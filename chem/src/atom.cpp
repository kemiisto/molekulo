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

#include "chem/atom.h"

#include "chem/element.h"
#include "chem/nuclide.h"
#include "chem/periodic_table.h"

struct ccio::atom::atom_private
{
    const ccio::molecule& molecule;
    unsigned int atomic_number;
    unsigned int mass_number;
    Eigen::Vector3d centre;
    bool is_selected;

    atom_private(const ccio::molecule& molecule,
            unsigned int atomic_number, unsigned int mass_number,
            const Eigen::Vector3d& centre) :
        molecule(molecule),
        atomic_number(atomic_number),
        mass_number(mass_number),
        centre(centre),
        is_selected(false)
    {
    }
};

ccio::atom::atom(const ccio::molecule& molecule,
        unsigned int atomic_number, unsigned int mass_number,
        const Eigen::Vector3d& centre) :
    p(std::make_unique<atom_private>(molecule, atomic_number, mass_number, centre))
{
}

ccio::atom::~atom()
{
}

const ccio::element& ccio::atom::element() const
{
    return ccio::default_periodic_table().element(p->atomic_number);
}

const ccio::nuclide& ccio::atom::isotope() const
{
    return element().isotope_with_mass_number(p->mass_number);
}

const Eigen::Vector3d& ccio::atom::centre() const
{
    return p->centre;
}

void ccio::atom::set_centre(const Eigen::Vector3d &centre)
{
    p->centre = centre;
}

bool ccio::atom::is_selected() const
{
    return p->is_selected;
}

void ccio::atom::toggle_selection()
{
    p->is_selected = !p->is_selected;
}
