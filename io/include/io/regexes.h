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

#ifndef KEMIISTO_IO_REGEXES_H
#define KEMIISTO_IO_REGEXES_H

#include <regex>
#include <string>

namespace kemiisto
{
    namespace io
    {
        // non-capturing groups
        const std::string& re_int();
        const std::string& re_real();
        const std::string& re_real_int();
        const std::string& re_alpha();
        const std::string& re_spaces();
        // capturing groups
        const std::string& re_int_g();
        const std::string& re_real_g();
        const std::string& re_real_int_g();
        const std::string& re_alpha_g();
    }
}

#endif /* KEMIISTO_IO_REGEXES_H */
