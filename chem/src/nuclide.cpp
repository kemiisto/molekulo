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

#include "chem/nuclide.h"

#include "chem/element.h"
#include "chem/periodic_table.h"

struct ccio::nuclide::nuclide_private
{
    // Do we need atomic_number?
    unsigned int atomic_number;
    unsigned int mass_number;
    double exact_mass;
    double natural_abundance;

    nuclide_private(unsigned int atomic_number, unsigned int mass_number, double exact_mass, double natural_abundance) :
        atomic_number(atomic_number),
        mass_number(mass_number),
        exact_mass(exact_mass),
        natural_abundance(natural_abundance)
    {}

    const ccio::element& element() const
    {
        return ccio::periodic_table().element(atomic_number);
    }
};

ccio::nuclide::nuclide(unsigned int atomic_number, unsigned int mass_number,
        double exact_mass, double natural_abundance) :
    p(new nuclide_private(atomic_number, mass_number, exact_mass, natural_abundance))
{
}

ccio::nuclide::nuclide(const nuclide & nuclide) :
    p(new nuclide_private(*nuclide.p))
{
}

ccio::nuclide& ccio::nuclide::operator=(const ccio::nuclide& nuclide)
{
    p.reset(new nuclide_private(*nuclide.p));
    return *this;
}

ccio::nuclide::~nuclide()
{
}

unsigned int ccio::nuclide::mass_number() const
{
    return p->mass_number;
}

double ccio::nuclide::exact_mass() const
{
    return p->exact_mass;
}

double ccio::nuclide::natural_abundance() const
{
    return p->natural_abundance;
}
