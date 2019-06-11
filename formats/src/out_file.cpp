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

#include "formats/out_file.h"

#include <boost/property_tree/ptree.hpp>

struct ccio::out_file::out_file_private
{
    boost::property_tree::ptree tree;
    ccio::molecule molecule;

    out_file_private() :
        tree(),
        molecule()
    {}
};

ccio::out_file::out_file(const std::string& absolute_file_path) :
    ccio::molecule_file(absolute_file_path),
    p(new out_file_private())
{
}

ccio::out_file::~out_file()
{
}

ccio::molecule& ccio::out_file::molecule()
{
    return p->molecule;
}

const ccio::molecule& ccio::out_file::molecule() const
{
    return p->molecule;
}

boost::property_tree::ptree& ccio::out_file::tree()
{
    return p->tree;
}

const boost::property_tree::ptree& ccio::out_file::tree() const
{
    return p->tree;
}

void ccio::out_file::set_program_name(const std::string& program_name)
{
	p->tree.put("Out.<xmlattr>.program", program_name);
}

void ccio::out_file::set_program_version(const std::string& program_version)
{
	p->tree.put("Out.<xmlattr>.version", program_version);
}

std::string ccio::out_file::program() const
{
    return p->tree.get<std::string>("Out.<xmlattr>.program");
}

std::string ccio::out_file::version() const
{
    return p->tree.get<std::string>("Out.<xmlattr>.version");
}
