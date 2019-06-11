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
#include <boost/filesystem.hpp>

#include "test_util.h"

static const uintmax_t maxSize = 10000;

BOOST_AUTO_TEST_SUITE(test_dalton_mol_file)

// DALTON-2013.4-Source/DALTON/test/
BOOST_AUTO_TEST_CASE(test_dalton_mol_file_dalton_test)
{
    ccio::test_dir(ccio::samples_dir()/"dalton"/"mol"/"dalton_test", ".mol");
}

// DALTON-2013.4-Source/LSDALTON/molecule_inputs/G2-G3_benchmark_set/
BOOST_AUTO_TEST_CASE(test_dalton_mol_file_lsdalton_g2_g3)
{
    ccio::test_dir(ccio::samples_dir()/"dalton"/"mol"/"lsdalton_g2_g3", ".mol", maxSize);
}

// DALTON-2013.4-Source/LSDALTON/Molecules
BOOST_AUTO_TEST_CASE(test_dalton_mol_file_lsdalton_molecules)
{
    ccio::test_dir(ccio::samples_dir()/"dalton"/"mol"/"lsdalton_molecules", ".mol", maxSize);
}

// DALTON-2013.4-Source/LSDALTON/molecule_inputs/Medium-size_benchmark_set/
BOOST_AUTO_TEST_CASE(test_dalton_mol_file_lsdalton_medium_size)
{
    ccio::test_dir(ccio::samples_dir()/"dalton"/"mol"/"lsdalton_medium_size", ".mol", maxSize);
}

// abel.uio.no
// /cluster/home/simensr/alkenex
BOOST_AUTO_TEST_CASE(test_dalton_mol_file_simensr_alkenex)
{
    ccio::test_dir(ccio::samples_dir()/"dalton"/"mol"/"simensr_alkenex", ".mol", maxSize);
}

// abel.uio.no
// /cluster/home/simensr/2008dec27/manyRuns/linmem_molecules/gluala/
BOOST_AUTO_TEST_CASE(test_dalton_mol_file_simensr_gluala)
{
    ccio::test_dir(ccio::samples_dir()/"dalton"/"mol"/"simensr_gluala", ".mol", maxSize);
}

// abel.uio.no
// /cluster/home/simensr/2008dec27/manyRuns/linmem_molecules/h2o/
BOOST_AUTO_TEST_CASE(test_dalton_mol_file_simensr_h2o)
{
    ccio::test_dir(ccio::samples_dir()/"dalton"/"mol"/"simensr_h2o", ".mol", maxSize);
}

// abel.uio.no
// /cluster/home/simensr/Dalton2013_release/LSDALTON/molecule_inputs/OchsenfeldsBenchmarkSetMP2/
BOOST_AUTO_TEST_CASE(test_dalton_mol_file_simensr_ochsenfelds)
{
    ccio::test_dir(ccio::samples_dir()/"dalton"/"mol"/"simensr_ochsenfelds", ".mol", maxSize);
}

// abel.uio.no
// patrime/DALTON/DataSimu/MOLECULEs_original/311molecules_test_set_TBP/DaltonINPUTS/
BOOST_AUTO_TEST_CASE(test_dalton_mol_file_simensr_profile)
{
    ccio::test_dir(ccio::samples_dir()/"dalton"/"mol"/"simensr_profile", ".mol", maxSize);
}

// www.rcsb.org
// Converted by QDalton.
BOOST_AUTO_TEST_CASE(test_dalton_mol_file_rcsb_pdb)
{
    ccio::test_dir(ccio::samples_dir()/"dalton"/"mol"/"rcsb_pdb", ".mol", maxSize);
}

BOOST_AUTO_TEST_SUITE_END()
