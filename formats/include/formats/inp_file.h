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

#ifndef INP_FILE_H
#define INP_FILE_H

#include "formats/molecule_file.h"

namespace ccio
{
    class inp_file : public ccio::molecule_file
    {
    public:
        virtual ~inp_file();

        ccio::molecule& molecule() override;
        const ccio::molecule& molecule() const override;

    protected:
        inp_file(const std::string& absolute_file_path);

    private:
        struct inp_file_private;
        std::unique_ptr<inp_file_private> p;
    };
}

#endif /* INP_FILE_H */
