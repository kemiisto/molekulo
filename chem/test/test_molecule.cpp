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

#define BOOST_TEST_DYN_LINK
// #define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "tolerance.h"
#include "chem/molecule.h"
#include "chem/atom.h"
#include "chem/bond.h"
#include "chem/element.h"

BOOST_AUTO_TEST_SUITE(test_molecule)

BOOST_AUTO_TEST_CASE(test_molecule_create_atom)
{
    ccio::molecule molecule;
    molecule.create_atom(1, Eigen::Vector3d::Zero());
    BOOST_CHECK_EQUAL(molecule.number_of_atoms(), 1);

    const ccio::atom& atom = molecule.atom(0);
    BOOST_CHECK_EQUAL(atom.centre(), Eigen::Vector3d::Zero());
    BOOST_CHECK_CLOSE(atom.element().van_der_waals_radius(), 1.20, tolerance);
}

BOOST_AUTO_TEST_CASE(test_molecule_create_bond)
{
    ccio::molecule molecule;
    molecule.create_atom(8, Eigen::Vector3d(0.0,  0.0,       0.114039));
    molecule.create_atom(1, Eigen::Vector3d(0.0,  0.780843, -0.456155));
    molecule.create_atom(1, Eigen::Vector3d(0.0, -0.780843, -0.456155));
    molecule.create_bond(0, 1);
    molecule.create_bond(0, 2);
    BOOST_CHECK_EQUAL(molecule.number_of_bonds(), 2);

    const ccio::bond& bond1 = molecule.bond(0);
    BOOST_CHECK_EQUAL(bond1.bond_order(), 1);
    BOOST_CHECK_EQUAL(bond1.begin_atom().element().atomic_number(), 8);
    BOOST_CHECK_EQUAL(bond1.end_atom().element().atomic_number(), 1);
    BOOST_CHECK_CLOSE(bond1.length(), 0.96687, tolerance);

    const ccio::bond& bond2 = molecule.bond(1);
    BOOST_CHECK_EQUAL(bond2.bond_order(), 1);
    BOOST_CHECK_EQUAL(bond2.begin_atom().element().atomic_number(), 8);
    BOOST_CHECK_EQUAL(bond2.end_atom().element().atomic_number(), 1);
    BOOST_CHECK_CLOSE(bond2.length(), 0.96687, tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
