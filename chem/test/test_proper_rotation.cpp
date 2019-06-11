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
#include <boost/test/unit_test.hpp>

#include <Eigen/Geometry>

#include "tolerance.h"
#include "chem/atom.h"
#include "chem/molecule.h"
#include "chem/proper_rotation.h"

BOOST_AUTO_TEST_SUITE(test_proper_rotation)

BOOST_AUTO_TEST_CASE(test_proper_rotation_c2_x)
{
    ccio::molecule molecule;
    molecule.create_atom(1, Eigen::Vector3d(1.0, 2.0, 3.0));

    ccio::proper_rotation rotation(ccio::proper_rotation::axis::x, 2);
    rotation.apply(molecule);

    BOOST_CHECK_EQUAL(molecule.number_of_atoms(), 2);

    Eigen::Vector3d true_result(1.0, -2.0, -3.0);
    const Eigen::Vector3d& result = molecule.atom(1).centre();

    BOOST_CHECK_CLOSE(result.x(), true_result.x(), tolerance);
    BOOST_CHECK_CLOSE(result.y(), true_result.y(), tolerance);
    BOOST_CHECK_CLOSE(result.z(), true_result.z(), tolerance);
}

BOOST_AUTO_TEST_CASE(test_proper_rotation_c2_y)
{
    ccio::molecule molecule;
    molecule.create_atom(1, Eigen::Vector3d(1.0, 2.0, 3.0));

    ccio::proper_rotation rotation(ccio::proper_rotation::axis::y, 2);
    rotation.apply(molecule);

    BOOST_CHECK_EQUAL(molecule.number_of_atoms(), 2);

    Eigen::Vector3d true_result(-1.0, 2.0, -3.0);
    const Eigen::Vector3d& result = molecule.atom(1).centre();

    BOOST_CHECK_CLOSE(result.x(), true_result.x(), tolerance);
    BOOST_CHECK_CLOSE(result.y(), true_result.y(), tolerance);
    BOOST_CHECK_CLOSE(result.z(), true_result.z(), tolerance);
}

BOOST_AUTO_TEST_CASE(test_proper_rotation_c2_z)
{
    ccio::molecule molecule;
    molecule.create_atom(1, Eigen::Vector3d(1.0, 2.0, 3.0));

    ccio::proper_rotation rotation(ccio::proper_rotation::axis::z, 2);
    rotation.apply(molecule);

    BOOST_CHECK_EQUAL(molecule.number_of_atoms(), 2);

    Eigen::Vector3d trueResult(-1.0, -2.0, 3.0);
    const Eigen::Vector3d& result = molecule.atom(1).centre();

    BOOST_CHECK_CLOSE(result.x(), trueResult.x(), tolerance);
    BOOST_CHECK_CLOSE(result.y(), trueResult.y(), tolerance);
    BOOST_CHECK_CLOSE(result.z(), trueResult.z(), tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
