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

#ifndef DALTON_DALTON_DAL_FILE_MODULE_READER
#define DALTON_DALTON_DAL_FILE_MODULE_READER

#include <boost/property_tree/ptree_fwd.hpp>
#include <vector>

#include "formats/reader.h"

namespace ccio
{
    class dalton_dal_entry_module_reader final : public ccio::reader
    {
    public:
        dalton_dal_entry_module_reader(kemiisto::io::input_stream& stream, boost::property_tree::ptree& module);
        ~dalton_dal_entry_module_reader();

    protected:
        struct dalton_dal_entry_module_reader_private;
        std::unique_ptr<dalton_dal_entry_module_reader_private> p;

        void do_read() override;
    };
}

#endif /* DALTON_DALTON_DAL_FILE_MODULE_READER */
