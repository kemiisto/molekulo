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

#include <iostream>
#include <boost/property_tree/xml_parser.hpp>

#include "tolerance.h"
#include "test_util.h"

#include "formats/constants.h"
#include "formats/dalton/dalton_scf_reader.h"
#include "io/input_string_stream.h"

#include "data/dalton/scf/qc/water_hf.h"
#include "data/dalton/scf/qc/water_b3lyp.h"
#include "data/dalton/scf/qc/coronene_hf.h"
#include "data/dalton/scf/qc/water_hf_not_converged.h"

#include "data/dalton/scf/qc/cc3_CARBON_asym_pol_ref.h"
#include "data/dalton/scf/qc/cc3_HF_631G_2hyp_ref.h"
#include "data/dalton/scf/qc/cc3_HF_ccpVDZ_asym_pol_ref.h"

/*
 * Testing QC-SCF cycles reader for the following different cases:
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

void check_dalton_qc_scf(const std::string& string, bool converged, 
        const std::vector<double>& true_energies)
{
    ccio::check_scf(ccio::text_file::type::dalton_out_file, ccio::scf_type::qc,
            string, converged, true_energies);
}

BOOST_AUTO_TEST_SUITE(test_dalton_scf_reader_qc)

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_qc_water_hf)
{
    const std::vector<double> true_energies = {
        -75.397166677311489,
        -75.585044187858003,
        -75.585805579057805,
        -75.585808994255316
    };

    check_dalton_qc_scf(dalton_scf_qc_water_hf, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_qc_water_b3lyp)
{
    const std::vector<double> true_energies = {
        -75.752936204751379,
        -75.932387614445304,
        -75.934289276740600,
        -75.934305914838816,
        -75.934306510739106,
        -75.934306520550905,
        -75.934306520828116,
        -75.934306520839826
    };

    check_dalton_qc_scf(dalton_scf_qc_water_b3lyp, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_qc_coronene_hf)
{
    const std::vector<double> true_energies = {
        -908.625983351397508,
        -910.748577216300646,
        -910.810858210713150,
        -910.811633873045821,
        -910.811635068154601,
    };

    check_dalton_qc_scf(dalton_scf_qc_coronene_hf, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_qc_water_hf_not_converged)
{
    const std::vector<double> true_energies = {
        -75.397166677311489,
        -75.585044187858003,
        -75.585805579057805
    };

    check_dalton_qc_scf(dalton_scf_qc_water_hf_not_converged, false, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_qc_cc3_CARBON_asym_pol_ref)
{
    const std::vector<double> true_energies = {
        -11.202588104231971,
        -12.666589373848407,
        -12.706304076850222,
        -12.706411938684106,
        -12.706411939049516,
        -12.706411939049520
    };

    check_dalton_qc_scf(dalton_scf_qc_cc3_CARBON_asym_pol_ref, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_qc_cc3_HF_631G_2hyp_ref)
{
    const std::vector<double> true_energies = {
        -93.678666097950668,
        -98.655321581277249,
        -99.877932110727230,
        -99.982833972759494,
        -99.983407832178813,
        -99.983408935326651,
        -99.983408935327233,
        -99.983408935327219
    };

    check_dalton_qc_scf(dalton_scf_qc_cc3_HF_631G_2hyp_ref, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_qc_cc3_HF_ccpVDZ_asym_pol_ref)
{
    const std::vector<double> true_energies = {
         -93.628855123816152,
         -98.569258505426532,
         -99.867871161456378,
        -100.019193968062879,
        -100.019411138017404,
        -100.019411261974994,
        -100.019411261974540
    };

    check_dalton_qc_scf(dalton_scf_qc_cc3_HF_ccpVDZ_asym_pol_ref, true, true_energies);
}

BOOST_AUTO_TEST_SUITE_END()
