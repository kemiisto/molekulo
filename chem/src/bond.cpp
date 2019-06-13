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

#include "chem/bond.h"

#include "chem/atom.h"
#include "chem/molecule.h"

struct ccio::bond::bond_private
{
    const ccio::molecule& molecule;
    std::size_t begin_atom_index;
    std::size_t end_atom_index;
    int bond_order;
    bool is_selected;

    bond_private(const ccio::molecule& molecule,
            std::size_t begin_atom_index, std::size_t end_atom_index, int bond_order) :
        molecule(molecule),
        begin_atom_index(begin_atom_index),
        end_atom_index(end_atom_index),
        bond_order(bond_order),
        is_selected(false)
    {}
};

ccio::bond::bond(const ccio::molecule& molecule,
        std::size_t begin_atom_index, std::size_t end_atom_index, int bond_order) :
    p(std::make_unique<bond_private>(molecule, begin_atom_index, end_atom_index, bond_order))
{
}

ccio::bond::~bond()
{
}

const ccio::atom& ccio::bond::begin_atom() const
{
    return p->molecule.atom(p->begin_atom_index);
}

const ccio::atom& ccio::bond::end_atom() const
{
    return p->molecule.atom(p->end_atom_index);
}

std::size_t ccio::bond::begin_atom_index() const
{
    return p->begin_atom_index;
}

std::size_t ccio::bond::end_atom_index() const
{
    return p->end_atom_index;
}

int ccio::bond::bond_order() const
{
    return p->bond_order;
}

void ccio::bond::cycle_bond_order()
{
    if (p->bond_order == 3) {
        p->bond_order = 1;
    } else {
        p->bond_order++;
    }
}

Eigen::Vector3d ccio::bond::centre() const
{
    return (end_atom().centre() + begin_atom().centre()) / 2;
}

double ccio::bond::length() const
{
    return (end_atom().centre() - begin_atom().centre()).norm();
}

bool ccio::bond::is_selected() const
{
    return p->is_selected;
}

void ccio::bond::toggle_selection()
{
    p->is_selected = !p->is_selected;
}
