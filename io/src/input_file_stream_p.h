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

#ifndef KEMIISTO_IO_INPUT_FILE_STREAM_P_H
#define KEMIISTO_IO_INPUT_FILE_STREAM_P_H

#include <fstream>

#include "input_stream_p.h"

namespace kemiisto
{
    namespace io
    {
        struct input_file_stream_private final : public input_stream_private
        {
            std::ifstream ifstream;

            input_file_stream_private(const std::string& absolute_file_name) :
                input_stream_private(),
                ifstream(absolute_file_name) {}

            ~input_file_stream_private() {}

            std::istream& istream() override
            {
                return ifstream;
            }
        };
    }
}

#endif /* KEMIISTO_IO_INPUT_FILE_STREAM_P_H */
