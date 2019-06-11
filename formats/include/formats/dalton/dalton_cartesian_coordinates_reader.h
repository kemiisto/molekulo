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

#ifndef DALTON_CARTESIAN_COORDINATES_READER_H
#define DALTON_CARTESIAN_COORDINATES_READER_H

#include "formats/reader.h"

namespace ccio
{
    class molecule;

    /**
     *  Class that reads Cartesian coordinates in the beginning of the DALTON output.
     *  Note, however, that Cartesian coordinates are printed only for small molecules.
     *  See DALTON/abacus/herrdn.F, lines starting at ~4600.
     *  For instance, DALTON 2013.4 prints Cartesian coordinates only if IPREAD > IPTEST, where
     *    IPREAD is the overall print level;
     *    IPTEST = MIN(NUCDEP/13,2).
     *  As a result, at the default print level (IPREAD=1) Cartesian coordinates are printed out 
     *  only for molecules containing less than 13 atoms. 
     *  As such they are not useful and the class is currently not used.
     */
    class dalton_cartesian_coordinates_reader final : public ccio::reader
    {
    public:
        dalton_cartesian_coordinates_reader(kemiisto::io::input_stream& stream, ccio::molecule& molecule);
        ~dalton_cartesian_coordinates_reader();

    private:
        struct dalton_cartesian_coordinates_reader_private;
        std::unique_ptr<dalton_cartesian_coordinates_reader_private> p;

        void do_read() override;
    };
}

#endif /* DALTON_CARTESIAN_COORDINATES_READER_H */
