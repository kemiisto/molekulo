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

#ifndef MOLECULE_FILE_H
#define MOLECULE_FILE_H

#include "formats/text_file.h"

namespace ccio
{
    class molecule_file : public ccio::text_file
    {
    public:
        virtual ~molecule_file();

        virtual ccio::molecule& molecule() = 0;
        virtual const ccio::molecule& molecule() const = 0;

    protected:
        molecule_file(const std::string& absolute_file_path);
    };
}


#endif // MOLECULE_FILE_H
