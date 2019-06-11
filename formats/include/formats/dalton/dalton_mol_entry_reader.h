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

#ifndef DALTON_MOL_ENTRY_READER_H
#define DALTON_MOL_ENTRY_READER_H

#include <vector>

#include "formats/reader.h"

namespace ccio
{
    class dalton_mol_entry;
    class molecule;

    class dalton_mol_entry_reader final : public ccio::reader
    {
    public:
        static void complete_molecule(ccio::molecule& molecule,
            const std::vector<std::string>& generators);

        dalton_mol_entry_reader(kemiisto::io::input_stream& stream, ccio::dalton_mol_entry& molEntry);
        ~dalton_mol_entry_reader();

    private:
        struct dalton_mol_entry_reader_private;
        std::unique_ptr<dalton_mol_entry_reader_private> p;

        void do_read() override;
    };
}

#endif // DALTON_MOL_ENTRY_READER_H
