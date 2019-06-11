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

#ifndef KEMIISTO_IO_INPUT_FILE_STREAM_H
#define KEMIISTO_IO_INPUT_FILE_STREAM_H

#include "io/input_stream.h"

namespace kemiisto
{
    namespace io
    {
        class input_file_stream final : public input_stream
        {
        public:
            input_file_stream(const std::string& absolute_file_name);
            ~input_file_stream();

            bool is_open() const;
            void close();
        };
    }
}

#endif /* KEMIISTO_IO_INPUT_FILE_STREAM_H */
