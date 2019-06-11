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

#include "data/gaussian/scf/qc/water_hf.h"
#include "data/gaussian/scf/qc/water_b3lyp.h"
#include "data/gaussian/scf/qc/coronene_hf.h"
#include "data/gaussian/scf/qc/water_hf_not_converged.h"
#include "data/gaussian/scf/qc/test018.h"
#include "data/gaussian/scf/qc/test045.h"
#include "data/gaussian/scf/qc/test110.h"
#include "data/gaussian/scf/qc/test117.h"
#include "data/gaussian/scf/qc/test118.h"
#include "data/gaussian/scf/qc/test130.h"
#include "data/gaussian/scf/qc/test131.h"

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

void check_gaussian_qc_scf(const std::string& string, bool converged, 
        const std::vector<double>& true_energies)
{
    ccio::check_scf(ccio::text_file::type::gaussian_out_file, ccio::scf_type::qc,
            string, converged, true_energies);
}

BOOST_AUTO_TEST_SUITE(test_gaussian_scf_reader_qc)

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_water_hf)
{
    const std::vector<double> true_energies = {
        -75.5170109481120,
        -75.5839156860635,
        -75.5857075413510,
        -75.5857957676848,
        -75.5858099773009,
        -75.5858099773044
    };

    check_gaussian_qc_scf(gaussian_scf_qc_water_hf, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_water_b3lyp)
{
    const std::vector<double> true_energies = {
        -75.9104461620061,
        -75.9710420695432,
        -75.9714944525492,
        -75.9715018646291,
        -75.9715018646321
    };

    check_gaussian_qc_scf(gaussian_scf_qc_water_b3lyp, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_coronene_hf)
{
    const std::vector<double> true_energies = {
        -904.629017249843,
        -904.811848578900,
        -904.814454471148,
        -904.814983472712,
        -904.815128153528,
        -904.815192244407,
        -904.815192244721
    };

    check_gaussian_qc_scf(gaussian_scf_qc_coronene_hf, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_water_hf_not_converged)
{
    const std::vector<double> true_energies = {
        -75.5170109481120,
        -75.5839156860635,
        -75.5857075413510
    };

    check_gaussian_qc_scf(gaussian_scf_qc_water_hf_not_converged, false, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_test018)
{
    const std::vector<double> true_energies = {
        -15.5929559780688,
        -15.5965514472216,
        -15.5968916421114,
        -15.5969642648891,
        -15.5969642678297
    };

    check_gaussian_qc_scf(gaussian_scf_qc_test018, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_test045)
{
    const std::vector<double> true_energies = {
        -76.2930425354007,
        -76.3601320506475,
        -76.3607804632052,
        -76.3608011327571,
        -76.3608011333586
    };

    check_gaussian_qc_scf(gaussian_scf_qc_test045, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_test110)
{
    const std::vector<double> true_energies = {
        -75.4720039043009
    };

    check_gaussian_qc_scf(gaussian_scf_qc_test110, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_test117)
{
    const std::vector<double> true_energies = {
        -75.9337104479242,
        -76.0080410955941,
        -76.0097601626042,
        -76.0098497981911,
        -76.0098687121347,
        -76.0098687121436
    };

    check_gaussian_qc_scf(gaussian_scf_qc_test117, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_test118)
{
    const std::vector<double> true_energies = {
        -38.8883792043103,
        -38.9181183630418,
        -38.9205150926903,
        -38.9209340072834,
        -38.9210330578734,
        -38.9210675603767,
        -38.9210675604022
    };

    check_gaussian_qc_scf(gaussian_scf_qc_test118, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_test130)
{
    const std::vector<double> true_energies = {
        -55.7810163353527,
        -55.8710015038621,
        -55.8721620992791,
        -55.8721981132516,
        -55.8722034727483,
        -55.8722034727486
    };

    check_gaussian_qc_scf(gaussian_scf_qc_test130, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_gaussian_scf_reader_qc_test131)
{
    const std::vector<double> true_energies = {
        -38.6838836361115,
        -38.7060325981253,
        -38.7081911416456,
        -38.7085881635871,
        -38.7087185532786,
        -38.7087185540121
    };

    check_gaussian_qc_scf(gaussian_scf_qc_test131, true, true_energies);
}

BOOST_AUTO_TEST_SUITE_END()
