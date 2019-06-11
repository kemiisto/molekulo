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

#include <array>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "tolerance.h"
#include "test_util.h"
#include "formats/gaussian/gaussian_scf_reader.h"
#include "formats/constants.h"
#include "io/input_string_stream.h"

#include "data/gaussian/scf/diis/water_hf.h"
#include "data/gaussian/scf/diis/water_hf_nodiis.h"
#include "data/gaussian/scf/diis/water_b3lyp.h"
#include "data/gaussian/scf/diis/coronene_hf.h"
#include "data/gaussian/scf/diis/water_hf_not_converged.h"
#include "data/gaussian/scf/diis/test000.h"
#include "data/gaussian/scf/diis/test001.h"
#include "data/gaussian/scf/diis/test002.h"
#include "data/gaussian/scf/diis/test004.h"
#include "data/gaussian/scf/diis/test005.h"
#include "data/gaussian/scf/diis/test007.h"
#include "data/gaussian/scf/diis/test008.h"
#include "data/gaussian/scf/diis/test009.h"
#include "data/gaussian/scf/diis/test010.h"

/*
 * Testing DIIS-SCF cycles reader for the following different cases:
 *   1) different wave functions 
 *     a) water_hf
 *     b) water_b3lyp
 *   2) molecules of different size
 *     a) water_hf
 *     b) coronene_hf
 *   3) SCF converged and did not converge
 *     a) water_hf
 *     b) water_hf_not_converged 
 */

void check_gaussian_diis_scf(const std::string& string, bool converged, 
        const std::vector<double>& true_energies)
{
    ccio::check_scf(ccio::text_file::type::gaussian_out_file, ccio::scf_type::diis,
            string, converged, true_energies);
}

BOOST_AUTO_TEST_SUITE(test_gaussian_scf_reader_diis)

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_water_hf)
{
    const std::vector<double> true_energies = {
        -75.5170109481120,
        -75.5701757793356,
        -75.5847903860537,
        -75.5857941194611,
        -75.5858097383584,
        -75.5858099662530,
        -75.5858099772537,
        -75.5858099773422,
        -75.5858099773433,
        -75.5858099773433
    };

    check_gaussian_diis_scf(gaussian_scf_diis_water_hf, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_water_hf_nodiis)
{
    const std::vector<double> true_energies = {
        -75.5170109481120,
        -75.5701757793356,
        -75.5818453955312,
        -75.5847998977749,
          0.0            , // (Non-Variational)
        -75.5858096651021,
        -75.5858099236921,
        -75.5858099670474,
          0.0            , // (Non-Variational)
        -75.5858099750818,
        -75.5858099767686,
        -75.5858099771966,
          0.0            , // (Non-Variational)
        -75.5858099773432,
        -75.5858099773434,
        -75.5858099773435
    };

    check_gaussian_diis_scf(gaussian_scf_diis_water_hf_nodiis, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_water_b3lyp)
{
    const std::vector<double> true_energies = {
        -75.9104639122239,
        -75.9366483877627,
        -75.9714625981312,
        -75.9715207604717,
        -75.9715018643415,
        -75.9715018643321,
        -75.9715018646264,
        -75.9715018646305
    };

    check_gaussian_diis_scf(gaussian_scf_diis_water_b3lyp, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_coronene_hf)
{
    const std::vector<double> true_energies = {
        -904.629006880920,
        -904.718616198498,
        -904.814405084983,
        -904.814991783521,
        -904.815147098348,
        -904.815172361011,
        -904.815176045933,
        -904.815192237424,
        -904.815192245049,
        -904.815192245232,
        -904.815192245423,
        -904.815192245431
    };

    check_gaussian_diis_scf(gaussian_scf_diis_coronene_hf, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_water_hf_not_converged)
{
    const std::vector<double> true_energies = {
        -75.5170109481120,
        -75.5701757793356,
        -75.5847903860537,
        -75.5857941194611,
        -75.5858097383584
    };

    check_gaussian_diis_scf(gaussian_scf_diis_water_hf_not_converged, false, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_test000)
{
    const std::vector<double> true_energies = {
        -74.9104425342548,
        -74.9603587989136,
        -74.9607058086476,
        -74.9607225781492,
        -74.9607232306620,
        -74.9607232756393,
        -74.9607232756403
    };

    check_gaussian_diis_scf(gaussian_scf_diis_test000, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_test001)
{
    const std::vector<double> true_energies = {
        -147.577024369843,
        -147.578440324672,
        -147.578509304061,
        -147.578511032137,
        -147.578511032139
    };

    check_gaussian_diis_scf(gaussian_scf_diis_test001, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_test002)
{
    const std::vector<double> true_energies = {
        -39.4433685360849,
        -39.4744989535336,
        -39.5017140920356,
        -39.5017778293688,
        -39.5017818414360,
        -39.5017819130889,
        -39.5017819143297,
        -39.5017819143907,
        -39.5017819143928,
        -39.5017819143928
    };

    check_gaussian_diis_scf(gaussian_scf_diis_test002, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_test004)
{
    const std::vector<double> true_energies = {
        -78.4539379445890,
        -78.5767128468840,
        -78.5954502783332,
        -78.5966285706626,
        -78.5968233694575,
        -78.5968641388540,
        -78.5968738397351,
        -78.5968746281882,
        -78.5968747015779,
        -78.5968747116883,
        -78.5968747129300,
        -78.5968747129798,
        -78.5968747129840,
        -78.5968747129844
    };

    check_gaussian_diis_scf(gaussian_scf_diis_test004, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_test005)
{
    const std::vector<double> true_energies = {
        -76.7159525365055,
        -76.8288683133668,
        -76.8407722569881,
        -76.8412101048244,
        -76.8412121344604,
        -76.8412121775719,
        -76.8412121779833,
        -76.8412121779879
    };

    check_gaussian_diis_scf(gaussian_scf_diis_test005, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_test007)
{
    const std::vector<double> true_energies = {
        -75.9337104522472,
        -75.9857362423962,
        -76.0082732231612,
        -76.0098450825981,
        -76.0098681926951,
        -76.0098686699877,
        -76.0098686937119,
        -76.0098686945344,
        -76.0098686945479
    };

    check_gaussian_diis_scf(gaussian_scf_diis_test007, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_test008)
{
    const std::vector<double> true_energies = {
        -75.9337104479936,
        -75.9857362615451,
        -76.0082732392250,
        -76.0098450987511,
        -76.0098682088200,
        -76.0098686861117,
        -76.0098687098359,
        -76.0098687106584,
        -76.0098687106719,
        -76.0098687106721
    };

    check_gaussian_diis_scf(gaussian_scf_diis_test008, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_test009)
{
    const std::vector<double> true_energies = {
        -74.9104425342548,
        -74.9603587989136,
        -74.9607058086476,
        -74.9607225781491,
        -74.9607232306619,
        -74.9607232756392,
        -74.9607232756403
    };

    check_gaussian_diis_scf(gaussian_scf_diis_test009, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_diis_test010)
{
    const std::vector<double> true_energies = {
        -74.9127604222906,
        -74.9630777284393,
        -74.9634538239620,
        -74.9634666597301,
        -74.9634671046978,
        -74.9634671322859,
        -74.9634671322869
    };

    check_gaussian_diis_scf(gaussian_scf_diis_test010, true, true_energies);
}

BOOST_AUTO_TEST_SUITE_END()
