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

#ifndef KEMIISTO_IO_INPUT_STREAM_P_H
#define KEMIISTO_IO_INPUT_STREAM_P_H

#include <array>

namespace kemiisto
{
    namespace io
    {
        struct input_stream_private
        {
            static const std::size_t cached_lines_number = 3;

            input_stream_private() :
                line_number(0),
                cached_lines(),
                comment_marks() {}

            virtual ~input_stream_private() {}

            virtual std::istream& istream() = 0;

            const std::string& current_line() const { return cached_lines.at(cached_lines_number - 1); }
            const std::string& previous_line() const { return cached_lines.at(cached_lines_number - 2); }

            int line_number;
            std::array<std::string, cached_lines_number> cached_lines;
            std::vector<char> comment_marks;
        };
    }
}

#endif /* KEMIISTO_IO_INPUT_STREAM_P_H */
