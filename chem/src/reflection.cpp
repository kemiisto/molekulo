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

#include "chem/reflection.h"

#include "chem/atom.h"
#include "chem/element.h"
#include "chem/molecule.h"

#include "utility.h"

struct ccio::reflection::reflection_private
{
    ccio::reflection::plane reflection_plane;

    reflection_private(ccio::reflection::plane reflection_plane) :
        reflection_plane(reflection_plane)
    {}
};

ccio::reflection::reflection(plane reflection_plane) :
    symmetry_operation(),
    p(new reflection_private(reflection_plane))
{
}

ccio::reflection::~reflection()
{
}

void ccio::reflection::apply(ccio::molecule& molecule) const
{
    // Save original number of atom, so that we won't get an infinite loop.
    std::size_t n = molecule.number_of_atoms();

    for (std::size_t i = 0; i < n; ++i) {
        ccio::atom& atom = molecule.atom(i);
        Eigen::Vector3d v(atom.centre());
        switch (p->reflection_plane) {
        case plane::yz:
            if (!kemiisto::is_close_to_zero(atom.centre().x())) {
                v.x() = -v.x();
                molecule.create_atom(atom.element().atomic_number(), v);
            }
            break;
        case plane::xz:
            if (!kemiisto::is_close_to_zero(atom.centre().y())) {
                v.y() = -v.y();
                molecule.create_atom(atom.element().atomic_number(), v);
            }
            break;
        case plane::xy:
            if (!kemiisto::is_close_to_zero(atom.centre().z())) {
                v.z() = -v.z();
                molecule.create_atom(atom.element().atomic_number(), v);
            }
            break;
        }
    }
}
