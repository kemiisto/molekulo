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

#include "formats/dalton/dalton_symmetry_independent_centres_reader.h"
#include "chem/molecule.h"

#include "io/input_file_stream.h"
#include "io/logger.h"
#include "io/regexes.h"
#include "io/wrong_format_exception.h"

struct ccio::dalton_symmetry_independent_centres_reader::dalton_symmetry_independent_centres_reader_private
{
    ccio::molecule& molecule;

    dalton_symmetry_independent_centres_reader_private(ccio::molecule& molecule):
        molecule(molecule)
    {}
};

ccio::dalton_symmetry_independent_centres_reader::dalton_symmetry_independent_centres_reader(
        kemiisto::io::input_stream& stream,
        ccio::molecule& molecule) :
    reader(stream),
    p(new dalton_symmetry_independent_centres_reader_private(molecule))
{
}

ccio::dalton_symmetry_independent_centres_reader::~dalton_symmetry_independent_centres_reader()
{
}

void ccio::dalton_symmetry_independent_centres_reader::do_read()
{
    LOG(debug) << "Reading symmetry independent centres...";

    //        6 :      0.00000000     2.70060761     0.00000000  Isotope  1
    // Isotope is ignored!
    static const std::regex regex(
        kemiisto::io::re_int_g() + R"(\s+:\s+)" + 
        kemiisto::io::re_real_g() + kemiisto::io::re_spaces() + 
        kemiisto::io::re_real_g() + kemiisto::io::re_spaces() + 
        kemiisto::io::re_real_g() + kemiisto::io::re_spaces()
    );
    std::smatch match;

    while (std::regex_search(stream().read_line(), match, regex) && !stream().done()) {
        try {
            unsigned int atomic_number = boost::lexical_cast<unsigned int>(match[1]);
            double x = boost::lexical_cast<double>(match[2]) * bohrs_to_angstroms;
            double y = boost::lexical_cast<double>(match[3]) * bohrs_to_angstroms;
            double z = boost::lexical_cast<double>(match[4]) * bohrs_to_angstroms;
            p->molecule.create_atom(atomic_number, Eigen::Vector3d(x, y, z));
        } catch (const boost::bad_lexical_cast& e) {
            throw kemiisto::io::wrong_format_exception(
                "symmetry independent centres", stream().line_number(), e.what()
            );
        }
    }

    LOG(debug) << "Done.";
}
