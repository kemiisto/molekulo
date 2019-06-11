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

#include <unordered_map>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "formats/dalton/dalton_dal_entry.h"
#include "formats/dalton/dalton_dal_entry_module_reader.h"
#include "formats/dalton/dalton_dal_entry_reader.h"
#include "io/input_file_stream.h"
#include "io/logger.h"
#include "io/wrong_format_exception.h"

// DALTON/choles/cc_cholesky.F      **CHOLES
// DALTON/sirius/sirgp.F            **MOLORB, **NATORB
// DALTON/abacus/dalgnr.F           all others
static const std::unordered_map<std::string, std::string> keyword_to_module_name = {
    {  "**GENER"  ,  "**DALTON INPUT"    },
    {  "*GENERA"  ,  "**DALTON INPUT"    },
    {  "**DALTO"  ,  "**DALTON INPUT"    },
    {  "*DALTON"  ,  "**DALTON INPUT"    },
    {  "**HERMI"  ,  "**INTEGRALS"       },
    {  "*HERMIT"  ,  "**INTEGRALS"       },
    {  "**INTEG"  ,  "**INTEGRALS"       },
    {  "**WAVE "  ,  "**WAVE FUNCTIONS"  },
    {  "**WAVEF"  ,  "**WAVE FUNCTIONS"  },
    {  "**SIRIUS" ,  "**WAVE FUNCTIONS"  },
    {  "**START"  ,  "**START"           },
    {  "**EACH "  ,  "**EACH STEP"       },
    {  "**PROPE"  ,  "**PROPERTIES"      },
    {  "**RESPO"  ,  "**RESPONSE"        },
    {  "**CHOLE"  ,  "**CHOLES"          },
    {  "**NMDDR"  ,  "**NMDDRV"          },
    {  "**MOLORB" ,  "**MOLORB"          },
    {  "**NATORB" ,  "**NATORB"          } // isn't it the same as **MOLORB?
};

struct ccio::dalton_dal_entry_reader::dalton_dal_entry_reader_private
{
    ccio::dalton_dal_entry& dal_entry;

    dalton_dal_entry_reader_private(ccio::dalton_dal_entry& dal_entry) :
        dal_entry(dal_entry)
    {}
};

ccio::dalton_dal_entry_reader::dalton_dal_entry_reader(
        kemiisto::io::input_stream& stream, ccio::dalton_dal_entry& dal_entry) :
        reader(stream), p(new dalton_dal_entry_reader_private(dal_entry))
{
}

ccio::dalton_dal_entry_reader::~dalton_dal_entry_reader()
{
}

/*
 * Particular attention should be drawn to the following two things.
 *
 * First, the Manual can create the false impression that modules start with double asterisk (**).
 * But it is wrong, since according to the source code, DALTON allows some freedom here:
 * some modules are recognized even when their names contain only single asterisk (*).
 * So, all in all, a module starts with either ** or * while a submodule always starts with *, which
 * makes parsing more complicated.
 * Imagine reading a (sub)module and finding a line that starts with single asterisk (*).
 * Is it a start of a new module or a new submodule of a current module?
 * We would not be able to answer the question unless we know at least the names of all modules.
 *
 * Secondly, some modules have alternative names which is again not mentioned in the Manual.
 * This can also cause troubles, but at a later time, for instance, when querying if a module
 * has a parametre or a submodule in it.
 *
 * To avoid the troubles we carefully read
 */

void ccio::dalton_dal_entry_reader::do_read()
{
    // Before reading we set the comment marks.
    stream().set_comment_marks(std::vector<char> {'!', '#'});

    std::string line = stream().read_line();
    
    // We first skip "empty" lines (lines that contain spaces only).
    while (!stream().done() && kemiisto::io::is_all_spaces(line)) {
        line = stream().read_line();
    }

    while (!stream().done() && line.find("*END OF") == std::string::npos) {
        boost::trim(line);
        if (boost::starts_with(line, "*")) {
            LOG(debug) << line;
            LOG(debug) << "it starts with *, so it should be a module";
            auto it = keyword_to_module_name.cbegin();
            while (it != keyword_to_module_name.cend() && line.find(it->first)) {
                ++it;
            }
            if (it != keyword_to_module_name.cend()) {
                LOG(debug) << "and it indeed is a valid module";
                boost::property_tree::ptree module;
                module.put("<xmlattr>.name", it->second);
                ccio::dalton_dal_entry_module_reader reader(stream(), module);
                reader.read();
                p->dal_entry.add_module(module);
            } else {
                LOG(error) << "but it is not a valid module";
                throw kemiisto::io::wrong_format_exception("DALTON DALTON.INP file", stream().line_number());
            }
        } else {
            LOG(error) << "it starts with something else, which is wrong";
            throw kemiisto::io::wrong_format_exception("DALTON DALTON.INP file", stream().line_number());
        }
        line = stream().current_line();
    }

    // boost::property_tree::xml_writer_settings<std::string> settings(' ', 4);
    // boost::property_tree::write_xml(std::cout, p->dal_entry.tree(), settings);

    // Clear the comment marks.
    stream().clear_comment_marks();
}
