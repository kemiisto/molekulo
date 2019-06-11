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

#ifndef DALTON_SYMMETRY_INDEPENDENT_CENTRES_READER_H
#define DALTON_SYMMETRY_INDEPENDENT_CENTRES_READER_H

#include "formats/reader.h"

namespace ccio
{
    class molecule;

    class dalton_symmetry_independent_centres_reader : public ccio::reader
    {
    public:
        dalton_symmetry_independent_centres_reader(kemiisto::io::input_stream& stream, ccio::molecule& molecule);
        ~dalton_symmetry_independent_centres_reader();

    private:
        struct dalton_symmetry_independent_centres_reader_private;
        std::unique_ptr<dalton_symmetry_independent_centres_reader_private> p;

        void do_read() override;
    };
}

#endif // DALTON_SYMMETRY_INDEPENDENT_CENTRES_READER_H
