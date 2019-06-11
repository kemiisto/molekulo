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

#ifndef IELEMENT_H
#define IELEMENT_H

#include <string>
#include <vector>

namespace ccio
{
    class ielement
    {
    public:
        virtual ~ielement() {}

        virtual unsigned int atomic_number() const = 0;
        virtual const std::string& symbol() const = 0;
        virtual const std::string& name() const = 0;
        virtual double atomic_weight() const = 0;
        virtual double van_der_waals_radius() const = 0;
        virtual double covalent_radius() const = 0;
        virtual const std::vector<unsigned char>& rgb() const = 0;
    };
}

#endif /* IELEMENT_H */
