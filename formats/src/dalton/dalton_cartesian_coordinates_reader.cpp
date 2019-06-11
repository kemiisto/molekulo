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

#include "formats/dalton/dalton_cartesian_coordinates_reader.h"

#include <Eigen/Core>

#include "chem/molecule.h"
#include "io/input_stream.h"
#include "io/logger.h"
#include "io/regexes.h"
#include "io/wrong_format_exception.h"

struct ccio::dalton_cartesian_coordinates_reader::dalton_cartesian_coordinates_reader_private
{
    ccio::molecule& molecule;

    dalton_cartesian_coordinates_reader_private(ccio::molecule& molecule) :
        molecule(molecule)
    {}
};

ccio::dalton_cartesian_coordinates_reader::dalton_cartesian_coordinates_reader(
        kemiisto::io::input_stream& stream,
        ccio::molecule& molecule) :
    reader(stream),
    p(new dalton_cartesian_coordinates_reader_private(molecule))
{
}

ccio::dalton_cartesian_coordinates_reader::~dalton_cartesian_coordinates_reader()
{
}

void ccio::dalton_cartesian_coordinates_reader::do_read()
{
    LOG(debug) << "Reading Cartesian coordinates...";

    if (stream().found("Total number of coordinates")) {
        //  O1	     :     1  x   0.0000000000    2  y   0.0000000000    3  z  -0.1171646009
        //  H2	 / 1 :     4  x   0.0000000000    5  y   1.4815452820    6  z   0.9297436723
        static const std::regex regex(
            kemiisto::io::re_alpha_g() + kemiisto::io::re_int() 
            + R"(?\s+(?:/\s+)" + kemiisto::io::re_int() + R"(\s+)?:)"
            + kemiisto::io::re_spaces() + kemiisto::io::re_int() 
            + R"(\s+x\s+)" + kemiisto::io::re_real_g()
            + kemiisto::io::re_spaces() + kemiisto::io::re_int() 
            + R"(\s+y\s+)" + kemiisto::io::re_real_g()
            + kemiisto::io::re_spaces() + kemiisto::io::re_int() 
            + R"(\s+z\s+)" + kemiisto::io::re_real_g()
        );
        std::smatch match;

        std::string line = stream().read_line();
        while (std::regex_search(line, match, regex) && !stream().done()) {
            LOG(debug) << match[1].str() << " " << match[2].str() << " " 
                << match[3].str() << " " << match[4].str();
            double x = boost::lexical_cast<double>(match[2]) * ccio::bohrs_to_angstroms;
            double y = boost::lexical_cast<double>(match[3]) * ccio::bohrs_to_angstroms;
            double z = boost::lexical_cast<double>(match[4]) * ccio::bohrs_to_angstroms;
            p->molecule.create_atom(match[1], Eigen::Vector3d(x, y, z));
            line = stream().read_line();
        }
    }

    LOG(debug) << "Done.";
}
