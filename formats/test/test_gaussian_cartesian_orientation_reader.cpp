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
#include <boost/property_tree/ptree.hpp>

#include "test_util.h"
#include "data/gaussian/cartesian_orientation/water_input.h"
#include "data/gaussian/cartesian_orientation/water_standard.h"
#include "data/gaussian/cartesian_orientation/coronene_input.h"
#include "data/gaussian/cartesian_orientation/coronene_standard.h"

void check_gaussian_coordinates(const std::string& string,
        const std::vector<Eigen::Vector3d>& true_coordinates)
{
    ccio::check_coordinates(ccio::text_file::type::gaussian_out_file, string, false, true_coordinates);
}

BOOST_AUTO_TEST_SUITE(test_gaussian_cartesian_orientation_reader)

BOOST_AUTO_TEST_CASE(test_gaussian_cartesian_orientation_reader_water_input)
{
    static const std::vector<Eigen::Vector3d> true_coordinates = {
        Eigen::Vector3d(-0.102389,  0.767918,  0.000000),
        Eigen::Vector3d( 0.857611,  0.767918,  0.000000),
        Eigen::Vector3d(-0.422844,  1.672854,  0.000000)
    };
    check_gaussian_coordinates(gaussian_cartesian_orientation_water_input, true_coordinates);
}

BOOST_AUTO_TEST_CASE(test_gaussian_cartesian_orientation_reader_water_standard)
{
    static const std::vector<Eigen::Vector3d> true_coordinates = {
        Eigen::Vector3d(0.000000,  0.000000,  0.110812),
        Eigen::Vector3d(0.000000,  0.783976, -0.443248),
        Eigen::Vector3d(0.000000, -0.783976, -0.443248)
    };
    check_gaussian_coordinates(gaussian_cartesian_orientation_water_standard, true_coordinates);
}

BOOST_AUTO_TEST_CASE(test_gaussian_cartesian_orientation_reader_coronene_input)
{
    static const std::vector<Eigen::Vector3d> true_coordinates = {
        Eigen::Vector3d(-3.682303, -0.666845,  0.000583),
        Eigen::Vector3d(-2.464366, -1.407116,  0.000364),
        Eigen::Vector3d(-1.241056, -0.708640, -0.000098),
        Eigen::Vector3d(-1.234217,  0.720474, -0.000164),
        Eigen::Vector3d(-2.450777,  1.430638, -0.000053),
        Eigen::Vector3d(-3.675756,  0.702079,  0.000355),
        Eigen::Vector3d(-0.006838, -1.429114, -0.000278),
        Eigen::Vector3d( 0.006844,  1.429097, -0.000265),
        Eigen::Vector3d( 1.241072,  0.708630, -0.000099),
        Eigen::Vector3d( 1.234229, -0.720479, -0.000147),
        Eigen::Vector3d( 2.464361,  1.407125,  0.000180),
        Eigen::Vector3d( 2.445884,  2.832269,  0.000099),
        Eigen::Vector3d( 1.263632,  3.522403, -0.000224),
        Eigen::Vector3d( 0.013579,  2.837756, -0.000292),
        Eigen::Vector3d(-1.229863,  3.534335, -0.000368),
        Eigen::Vector3d(-2.418668,  2.855538, -0.000225),
        Eigen::Vector3d(-3.375739,  3.399307, -0.000197),
        Eigen::Vector3d(-1.211711,  4.634943, -0.000489),
        Eigen::Vector3d(-4.631762, -1.223801,  0.000939),
        Eigen::Vector3d(-4.619830,  1.268108,  0.000528),
        Eigen::Vector3d( 3.408120,  3.366848,  0.000250),
        Eigen::Vector3d( 1.255996,  4.623134, -0.000387),
        Eigen::Vector3d(-2.445908, -2.832257,  0.000415),
        Eigen::Vector3d(-1.263640, -3.522400, -0.000143),
        Eigen::Vector3d(-0.013579, -2.837759, -0.000466),
        Eigen::Vector3d(-3.408132, -3.366868,  0.000861),
        Eigen::Vector3d(-1.256019, -4.623134, -0.000200),
        Eigen::Vector3d( 1.229866, -3.534337, -0.000667),
        Eigen::Vector3d( 2.418672, -2.855541, -0.000272),
        Eigen::Vector3d( 2.450775, -1.430645,  0.000037),
        Eigen::Vector3d( 1.211713, -4.634938, -0.000974),
        Eigen::Vector3d( 3.375744, -3.399306, -0.000201),
        Eigen::Vector3d( 3.682301,  0.666858,  0.000754),
        Eigen::Vector3d( 4.631767,  1.223833,  0.001399),
        Eigen::Vector3d( 3.675758, -0.702075,  0.000577),
        Eigen::Vector3d( 4.619850, -1.268080,  0.000853)
    };
    check_gaussian_coordinates(gaussian_cartesian_orientation_coronene_input, true_coordinates);
}

BOOST_AUTO_TEST_CASE(test_gaussian_cartesian_orientation_reader_coronene_standard)
{
    static const std::vector<Eigen::Vector3d> true_coordinates = {
        Eigen::Vector3d(-0.674368,  3.680933,  0.000583),
        Eigen::Vector3d(-1.412149,  2.461486,  0.000364),
        Eigen::Vector3d(-0.711175,  1.239606, -0.000098),
        Eigen::Vector3d( 0.717950,  1.235686, -0.000164),
        Eigen::Vector3d( 1.425627,  2.453695, -0.000053),
        Eigen::Vector3d( 0.694567,  3.677183,  0.000355),
        Eigen::Vector3d(-1.429125,  0.003918, -0.000278),
        Eigen::Vector3d( 1.429108, -0.003924, -0.000265),
        Eigen::Vector3d( 0.711164, -1.239622, -0.000099),
        Eigen::Vector3d(-0.717956, -1.235698, -0.000147),
        Eigen::Vector3d( 1.412158, -2.461481,  0.000180),
        Eigen::Vector3d( 2.837260, -2.440091,  0.000099),
        Eigen::Vector3d( 3.524978, -1.256432, -0.000224),
        Eigen::Vector3d( 2.837778, -0.007780, -0.000292),
        Eigen::Vector3d( 3.531815,  1.237082, -0.000368),
        Eigen::Vector3d( 2.850590,  2.424498, -0.000225),
        Eigen::Vector3d( 3.392402,  3.382678, -0.000197),
        Eigen::Vector3d( 4.632458,  1.221179, -0.000489),
        Eigen::Vector3d(-1.233263,  4.629251,  0.000939),
        Eigen::Vector3d( 1.258665,  4.622412,  0.000528),
        Eigen::Vector3d( 3.373805, -3.401233,  0.000250),
        Eigen::Vector3d( 4.625691, -1.246547, -0.000387),
        Eigen::Vector3d(-2.837249,  2.440116,  0.000415),
        Eigen::Vector3d(-3.524975,  1.256440, -0.000143),
        Eigen::Vector3d(-2.837780,  0.007781, -0.000466),
        Eigen::Vector3d(-3.373825,  3.401245,  0.000861),
        Eigen::Vector3d(-4.625690,  1.246570, -0.000200),
        Eigen::Vector3d(-3.531816, -1.237085, -0.000667),
        Eigen::Vector3d(-2.850593, -2.424502, -0.000272),
        Eigen::Vector3d(-1.425635, -2.453693,  0.000037),
        Eigen::Vector3d(-4.632452, -1.221181, -0.000974),
        Eigen::Vector3d(-3.392401, -3.382683, -0.000201),
        Eigen::Vector3d( 0.674381, -3.680930,  0.000754),
        Eigen::Vector3d( 1.233295, -4.629257,  0.001399),
        Eigen::Vector3d(-0.694562, -3.677185,  0.000577),
        Eigen::Vector3d(-1.258638, -4.622432,  0.000853)
    };
    check_gaussian_coordinates(gaussian_cartesian_orientation_coronene_standard, true_coordinates);
}

BOOST_AUTO_TEST_SUITE_END()
