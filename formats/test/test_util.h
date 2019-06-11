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

#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#include <boost/filesystem/path.hpp>

#include "formats/text_file.h"
#include "formats/constants.h"

namespace ccio
{
    boost::filesystem::path samples_dir();
    void test_dir(const boost::filesystem::path& dir, 
            const boost::filesystem::path& extension, uintmax_t max_file_size = UINTMAX_MAX);
    void check_scf(ccio::text_file::type file_type, ccio::scf_type scf_type,
            const std::string& string, bool converged, const std::vector<double>& true_energies);
    void check_coordinates(ccio::text_file::type file_type, const std::string& string, 
            bool bohrs, const std::vector<Eigen::Vector3d>& true_coordinates);
}

#endif // TEST_UTIL_H

