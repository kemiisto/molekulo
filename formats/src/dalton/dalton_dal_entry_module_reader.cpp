/**********************************************************************

  Copyright (C) 2008-2015 Anton Simakov

  This file is part of Molekulo.
  For more information, see <http://code.google.com/p/molekulo/>

  Molekulo is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Molekulo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Molekulo. If not, see <http://www.gnu.org/licenses/>.

 **********************************************************************/

#include "formats/dalton/dalton_dal_entry_module_reader.h"

#include <string>
#include <unordered_map>
#include <boost/algorithm/string.hpp>

#include "formats/dalton/dalton_dal_entry_submodule_reader.h"
#include "io/input_file_stream.h"
#include "io/logger.h"

static const std::vector<std::string> modules = {
    "**GENER"  ,  "*GENERA"  ,  "**DALTO"   ,  "*DALTON"  ,
    "**HERMI"  ,  "*HERMIT"  ,  "**INTEG"   ,
    "**WAVE "  ,  "**WAVEF"  ,  "**SIRIUS"  ,
    "**START"  ,
    "**EACH "  ,
    "**PROPE"  ,
    "**RESPO"  ,
    "**CHOLE"  ,
    "**NMDDR"  ,
    "**MOLORB" ,
    "**NATORB"
};

struct ccio::dalton_dal_entry_module_reader::dalton_dal_entry_module_reader_private final
{
    boost::property_tree::ptree& module;

    dalton_dal_entry_module_reader_private(boost::property_tree::ptree& module) :
        module(module)
    {}

    ~dalton_dal_entry_module_reader_private()
    {}

    void read_parametre(const std::string& name, boost::property_tree::ptree& module,
            kemiisto::io::input_stream& stream)
    {
        boost::property_tree::ptree parametre;
        parametre.put("<xmlattr>.name", name);

        // parametre may have some value
        std::string value;
        std::string line = stream.read_line();
        while (!boost::starts_with(line, ".") && !boost::starts_with(line, "*")) {
            value = value + line;
            line = stream.read_line();
        }
        if (!value.empty()) {
            boost::algorithm::trim(value);
            LOG(debug) << "with value " << value;
            parametre.put("<xmlattr>.value", value);
        }
        module.add_child("Parametre", parametre);
    }

    void read_submodule(const std::string& name, kemiisto::io::input_stream& stream)
    {
        boost::property_tree::ptree submodule;
        submodule.put("<xmlattr>.name", name);

        LOG(debug) << "Reading " << name << " submodule...";
        std::string line = stream.read_line();
        while (!stream.done() && line.find("*") == std::string::npos) {
            boost::trim(line);
            LOG(debug) << line;
            if (boost::starts_with(line, ".")) {
                LOG(debug) << "it starts with the full stop, so it should be a parametre";
                read_parametre(line, submodule, stream);
            }
            line = stream.current_line();
        }

        module.add_child("Submodule", submodule);
    }
};

ccio::dalton_dal_entry_module_reader::dalton_dal_entry_module_reader(
        kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& module) :
        reader(stream),
        p(new dalton_dal_entry_module_reader_private(module))
{
}

ccio::dalton_dal_entry_module_reader::~dalton_dal_entry_module_reader()
{
}

void ccio::dalton_dal_entry_module_reader::do_read()
{
    std::string module_name = p->module.get<std::string>("<xmlattr>.name");
    LOG(debug) << "Reading " << module_name << " module...";

    std::string line = stream().read_line();
    while (!stream().done() && line.find("*END OF") == std::string::npos) {
        boost::trim(line);
        LOG(debug) << line;
        if (boost::starts_with(line, ".")) {
            LOG(debug) << "it starts with the full stop, so it should be a parametre";
            p->read_parametre(line, p->module, stream());
        } else if (boost::starts_with(line, "*") && line.find("*END OF") == std::string::npos) {
            LOG(debug) << "it starts with the asterisk, so it should be either a submodule or a module";
            auto it = modules.cbegin();
            while (it != modules.cend() && line.find((*it).substr(0, 6)) == std::string::npos) {
                ++it;
            }
            if (it != modules.cend()) {
                LOG(debug) << "and it is a module, so we quit";
                break;
            } else {
                LOG(debug) << "and it is a submodule";
                p->read_submodule(line, stream());
            }
        } else {
            LOG(error) << "but it is neither a valid submodule nor a valid module";
        }
        line = stream().current_line();
    }
}
