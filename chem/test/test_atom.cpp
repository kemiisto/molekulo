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
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "chem/atom.h"
#include "chem/element.h"
#include "chem/molecule.h"
#include "tolerance.h"

BOOST_AUTO_TEST_SUITE(test_atom)

BOOST_AUTO_TEST_CASE(test_atom_1)
{
    ccio::molecule molecule;
    molecule.create_atom(1, Eigen::Vector3d::Zero());
    const ccio::atom& atom = molecule.atom(0);
    BOOST_CHECK_EQUAL(atom.centre(), Eigen::Vector3d::Zero());
    BOOST_CHECK_EQUAL(atom.element().atomic_number(), 1);
}

BOOST_AUTO_TEST_SUITE_END()
