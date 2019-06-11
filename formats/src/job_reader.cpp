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

#include "formats/job_reader.h"

#include <boost/property_tree/ptree.hpp>
#include "chem/molecule.h"

struct ccio::job_reader::job_reader_private
{
    ccio::molecule& molecule;

    job_reader_private(ccio::molecule& molecule) : molecule(molecule) {}
};

ccio::job_reader::job_reader(kemiisto::io::input_stream& stream, boost::property_tree::ptree& root,
        const std::string& name, ccio::molecule& molecule) :
    section_reader(stream, root, name),
    p(new job_reader_private(molecule))
{
    tree().put("<xmlattr>.type", "Energy");
    tree().put("<xmlattr>.done", false);
}

ccio::job_reader::~job_reader()
{
}

ccio::molecule& ccio::job_reader::molecule()
{
    return p->molecule;
}

const ccio::molecule& ccio::job_reader::molecule() const
{
    return p->molecule;
}

bool ccio::job_reader::is_job_done() const
{
    for (const auto& item : tree()) {
        if (item.first == "Item" && !item.second.get<bool>("<xmlattr>.done")) {
            return false;
        }
    }
    return true;
}
