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
#include <array>

#include "tolerance.h"
#include "test_util.h"

void check_dalton_coordinates(const std::string& string, bool bohrs,
        const std::vector<Eigen::Vector3d>& true_coordinates);

BOOST_AUTO_TEST_SUITE(test_dalton_cartesian_coordinates_reader)

BOOST_AUTO_TEST_CASE(test_dalton_cartesian_coordinates_reader_hf)
{
    std::string s = R"(
  Total number of coordinates:    6
  F       :     1  x   0.0000000000    2  y   0.0000000000    3  z   1.7632000000
  H       :     4  x   0.0000000000    5  y   0.0000000000    6  z   0.0000000000
    )";

    static const std::vector<Eigen::Vector3d> true_coordinates = {
        Eigen::Vector3d(0.0000000000,  0.0000000000,  1.7632000000),
        Eigen::Vector3d(0.0000000000,  0.0000000000,  0.0000000000)
    };
    check_dalton_coordinates(s, true, true_coordinates);
}

BOOST_AUTO_TEST_CASE(test_dalton_cartesian_coordinates_reader_h2o)
{
    std::string s = R"(
  Total number of coordinates:    9
  O1         :     1  x   0.0000000000    2  y   0.0000000000    3  z  -0.1171646009
  H2     / 1 :     4  x   0.0000000000    5  y   1.4815452820    6  z   0.9297436723
  H2     / 2 :     7  x   0.0000000000    8  y  -1.4815452820    9  z   0.9297436723
    )";

    static const std::vector<Eigen::Vector3d> true_coordinates = {
        Eigen::Vector3d(0.0000000000,  0.0000000000, -0.1171646009),
        Eigen::Vector3d(0.0000000000,  1.4815452820,  0.9297436723),
        Eigen::Vector3d(0.0000000000, -1.4815452820,  0.9297436723)
    };
    check_dalton_coordinates(s, true, true_coordinates);
}

BOOST_AUTO_TEST_SUITE_END()

void check_dalton_coordinates(const std::string& string, bool bohrs,
        const std::vector<Eigen::Vector3d>& true_coordinates)
{
    ccio::check_coordinates(ccio::text_file::type::dalton_out_file, string, bohrs, true_coordinates);
}
