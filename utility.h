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

#ifndef UTILITY_H
#define UTILITY_H

#include <cmath>
#include <limits>
#include <string>

namespace kemiisto
{
    template <typename T>
    bool is_close_to_zero(T x)
    {
        return std::abs(x) < std::numeric_limits<T>::epsilon();
    }

    std::string to_string(double x, int width, int precision);
}

#endif // UTILITY_H
