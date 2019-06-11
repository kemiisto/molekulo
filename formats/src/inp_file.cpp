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

#include "formats/inp_file.h"

struct ccio::inp_file::inp_file_private
{
    ccio::molecule molecule;

    inp_file_private() :
        molecule()
    {}
};

ccio::inp_file::inp_file(const std::string& absolute_file_path) :
    molecule_file(absolute_file_path),
    p(new inp_file_private())
{
}

ccio::inp_file::~inp_file()
{
}

ccio::molecule& ccio::inp_file::molecule()
{
    return p->molecule;
}

const ccio::molecule& ccio::inp_file::molecule() const
{
    return p->molecule;
}
