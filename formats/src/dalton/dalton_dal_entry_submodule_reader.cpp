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

#include "formats/dalton/dalton_dal_entry_submodule_reader.h"

#include <unordered_map>
#include <boost/algorithm/string.hpp>

#include "io/input_file_stream.h"
#include "io/logger.h"

struct ccio::DaltonDalEntrySubmoduleReader::DaltonDalEntrySubmoduleReaderPrivate
{
    boost::property_tree::ptree& module;

    DaltonDalEntrySubmoduleReaderPrivate(boost::property_tree::ptree& module) :
        module(module)
    {}
};

ccio::DaltonDalEntrySubmoduleReader::DaltonDalEntrySubmoduleReader(
        kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& module) :
        reader(stream),
        p(new DaltonDalEntrySubmoduleReaderPrivate(module))
{
}

ccio::DaltonDalEntrySubmoduleReader::~DaltonDalEntrySubmoduleReader()
{
}

void ccio::DaltonDalEntrySubmoduleReader::do_read()
{
    std::string line = stream().read_line();
    while (!stream().done() && line.find(".") != std::string::npos) {
        boost::trim(line);
        LOG(debug) << line;
        LOG(debug) << "it starts with the full stop, so it should be a parametre";
        // iterating through valid parametres for the module and
        // compare first 7 characters of the current line and each parametre
        // parametre may have some value
        std::string value;
        line = stream().read_line();
        while (!boost::starts_with(line, ".") && !boost::starts_with(line, "*")) {
            value = value + line;
            line = stream().read_line();
        }
        if (!value.empty()) {
            LOG(debug) << "with value " << value;
        }
        boost::property_tree::ptree parametre;
        parametre.put("<xmlattr>.name", line);
        parametre.put("<xmlattr>.value", value);
        p->module.add_child("Parametre", parametre);
    }
}
