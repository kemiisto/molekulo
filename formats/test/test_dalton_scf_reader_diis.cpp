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

#include "formats/constants.h"
#include "formats/dalton/dalton_scf_reader.h"
#include "io/input_string_stream.h"

#include "data/dalton/scf/diis/water_hf.h"
#include "data/dalton/scf/diis/water_b3lyp.h"
#include "data/dalton/scf/diis/coronene_hf.h"
#include "data/dalton/scf/diis/water_hf_not_converged.h"

#include "data/dalton/scf/diis/aba_prop_file_ref.h"
#include "data/dalton/scf/diis/cc2_r12_aux2_bh_a2_ref.h"
#include "data/dalton/scf/diis/cc2_r12_aux_benzene_sym_fop_ref.h"
#include "data/dalton/scf/diis/cc2_r12_aux_ch4_a2_ref.h"
#include "data/dalton/scf/diis/cc2_r12_aux_h2o_a2_ref.h"
#include "data/dalton/scf/diis/cc2_r12_aux_n2_gamma2_ref.h"

/*
 * Testing DIIS-SCF reader for the following different cases:
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

void check_dalton_diis_scf(const std::string& string, bool converged, 
        const std::vector<double>& true_energies)
{
    ccio::check_scf(ccio::text_file::type::dalton_out_file, ccio::scf_type::diis,
            string, converged, true_energies);
}

BOOST_AUTO_TEST_SUITE(test_dalton_scf_reader_diis)

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_diis_water_hf)
{
    const std::vector<double> true_energies = {
        -75.3971666773,
        -75.5791995958,
        -75.5855993905,
        -75.5858057410,
        -75.5858084159,
        -75.5858089159,
        -75.5858089931,
        -75.5858089943
    };

    check_dalton_diis_scf(dalton_scf_diis_water_hf, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_diis_water_b3lyp)
{
    const std::vector<double> true_energies = {
        -75.7529362048,
        -75.9332556012,
        -75.9335440727,
        -75.9342935879,
        -75.9343064566,
        -75.9343065207,
        -75.9343065208
    };

    check_dalton_diis_scf(dalton_scf_diis_water_b3lyp, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_diis_coronene_hf)
{
    const std::vector<double> true_energies = {
        -908.625983351,
        -910.695722366,
        -910.794325234,
        -910.809113632,
        -910.811488785,
        -910.811617180,
        -910.811630228,
        -910.811634756,
        -910.811635066,
        -910.811635068,
        -910.811635068
    };

    check_dalton_diis_scf(dalton_scf_diis_coronene_hf, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_diis_water_hf_not_converged)
{
    const std::vector<double> true_energies = {
        -75.3971666773,
        -75.5791995958,
        -75.5855993905,
        -75.5858057410,
        -75.5858084159
    };

    check_dalton_diis_scf(dalton_scf_diis_water_hf_not_converged, false, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_diis_aba_prop_file_ref)
{
    const std::vector<double> true_energies = {
        -112.128425712,
        -112.279310189,
        -112.353421199,
        -112.353675938,
        -112.353695014,
        -112.353697423,
        -112.353697509,
        -112.353697510,
        -112.353697510,
        -112.353697510,
        -112.353697510,
        -112.353697510,
        -112.353697510,
        -112.353697510,
        -112.353697510,
        -112.353697510,
        -112.353697510,
        -112.353697510
    };

    check_dalton_diis_scf(dalton_scf_diis_aba_prop_file_ref, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_diis_cc2_r12_aux2_bh_a2_ref)
{
    const std::vector<double> true_energies = {
        -23.7919251551,
        -24.8475362942,
        -24.8632919723,
        -24.8661450214,
        -24.8662245512,
        -24.8662249440,
        -24.8662249627,
        -24.8662249632,
        -24.8662249632,
        -24.8662249632,
        -24.8662249632,
        -24.8662249632,
        -24.8662249632
    };

    check_dalton_diis_scf(dalton_scf_diis_cc2_r12_aux2_bh_a2_ref, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_diis_cc2_r12_aux_benzene_sym_fop_ref)
{
    const std::vector<double> true_energies = {
        -185.117892192,
        -209.192906663,
        -209.967112774,
        -209.972747927,
        -209.972811153,
        -209.972811214,
        -209.972811214,
        -209.972811214,
        -209.972811214,
        -209.972811214,
        -209.972811214
    };

    check_dalton_diis_scf(dalton_scf_diis_cc2_r12_aux_benzene_sym_fop_ref, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_diis_cc2_r12_aux_ch4_a2_ref)
{
    const std::vector<double> true_energies = {
        -26.9208461930,
        -34.5740130443,
        -38.7812864835,
        -40.0920859293,
        -40.1914986672,
        -40.1917302506,
        -40.1917714465,
        -40.1917720845,
        -40.1917720926,
        -40.1917720926,
        -40.1917720926,
        -40.1917720926,
        -40.1917720926,
        -40.1917720926,
        -40.1917720926
    };

    check_dalton_diis_scf(dalton_scf_diis_cc2_r12_aux_ch4_a2_ref, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_diis_cc2_r12_aux_h2o_a2_ref)
{
    const std::vector<double> true_energies = {
        -61.9064868849,
        -67.5183719652,
        -73.7989315582,
        -75.6877048599,
        -76.0063796622,
        -76.0082538736,
        -76.0085436998,
        -76.0085548901,
        -76.0085552884,
        -76.0085552985,
        -76.0085552989,
        -76.0085552989,
        -76.0085552989,
        -76.0085552989,
        -76.0085552989,
        -76.0085552989
    };

    check_dalton_diis_scf(dalton_scf_diis_cc2_r12_aux_h2o_a2_ref, true, true_energies);
}

BOOST_AUTO_TEST_CASE(test_dalton_scf_reader_diis_cc2_r12_aux_n2_gamma2_ref)
{
    const std::vector<double> true_energies = {
        -99.9001864071,
        -106.570438337,
        -108.865160281,
        -108.950942395,
        -108.954044008,
        -108.954130007,
        -108.954130754,
        -108.954130767,
        -108.954130767,
        -108.954130767,
        -108.954130767,
        -108.954130767,
        -108.954130767,
        -108.954130767
    };

    check_dalton_diis_scf(dalton_scf_diis_cc2_r12_aux_n2_gamma2_ref, true, true_energies);
}

BOOST_AUTO_TEST_SUITE_END()
