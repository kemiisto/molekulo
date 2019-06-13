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

#include <boost/filesystem/operations.hpp>

#include "test_util.h"
#include "formats/dalton/dalton_mol_file.h"
#include "formats/dalton/dalton_out_file.h"
#include "formats/gaussian/gaussian_out_file.h"

void testDetectionInDir(ccio::text_file::type type, const boost::filesystem::path& dir, const std::string& ext);

BOOST_AUTO_TEST_CASE(testDaltonMolDetection)
{
    testDetectionInDir(ccio::text_file::type::dalton_mol_file,
                       ccio::samples_dir()/"dalton"/"mol"/"lsdalton_g2_g3", ".mol");
    testDetectionInDir(ccio::text_file::type::dalton_mol_file,
                       ccio::samples_dir()/"dalton"/"mol"/"lsdalton_molecules", ".mol");
    testDetectionInDir(ccio::text_file::type::dalton_mol_file,
                       ccio::samples_dir()/"dalton"/"mol"/"lsdalton_medium_size", ".mol");
}

BOOST_AUTO_TEST_CASE(testGaussianOutDetection)
{
    testDetectionInDir(ccio::text_file::type::gaussian_out_file,
                       ccio::samples_dir()/"gaussian"/"h2o"/"sp", ".out");
    testDetectionInDir(ccio::text_file::type::gaussian_out_file,
                       ccio::samples_dir()/"gaussian"/"h2o"/"opt", ".out");
}

void testDetectionInDir(ccio::text_file::type type, const boost::filesystem::path& dir, const std::string& ext)
{
    boost::filesystem::directory_iterator end;
    for (boost::filesystem::directory_iterator it(dir); it != end; ++it) {
        if (it->path().extension() == ext) {
            std::unique_ptr<ccio::text_file> chemFile = ccio::text_file::new_instance(it->path().string());
            switch (type) {
            case ccio::text_file::type::dalton_dal_file:
                break;
            case ccio::text_file::type::dalton_mol_file: {
                ccio::DaltonMolFile* daltonMolFile = dynamic_cast<ccio::DaltonMolFile*>(chemFile.get());
                BOOST_CHECK_MESSAGE(daltonMolFile != nullptr, it->path());
                break;
            }
            case ccio::text_file::type::dalton_out_file: {
                ccio::DaltonOutFile* daltonOutFile = dynamic_cast<ccio::DaltonOutFile*>(chemFile.get());
                BOOST_CHECK_MESSAGE(daltonOutFile != nullptr, it->path());
                break;
            }
            case ccio::text_file::type::gaussian_inp_file:
                break;
            case ccio::text_file::type::gaussian_out_file: {
                ccio::gaussian_out_file* gaussianOutFile = dynamic_cast<ccio::gaussian_out_file*>(chemFile.get());
                BOOST_CHECK_MESSAGE(gaussianOutFile != nullptr, it->path());
                break;
            }
            }
        }
    }
}
