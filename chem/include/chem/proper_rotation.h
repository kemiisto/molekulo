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

#ifndef PROPER_ROTATION_H
#define PROPER_ROTATION_H

#include "chem/symmetry_operation.h"

namespace ccio
{
    class proper_rotation final : public ccio::symmetry_operation
    {
    public:
        enum class axis { x, y, z };

        proper_rotation(ccio::proper_rotation::axis rotation_axis, int n, int m = 1);
        ~proper_rotation();

        void apply(ccio::molecule& molecule) const override;

    private:
        struct proper_rotation_private;
        std::unique_ptr<proper_rotation_private> p;
    };
}

#endif /* PROPER_ROTATION_H */
