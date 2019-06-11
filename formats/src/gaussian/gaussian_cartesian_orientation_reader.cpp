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

#include "formats/gaussian/gaussian_cartesian_orientation_reader.h"

#include <boost/property_tree/xml_parser.hpp>

#include "io/input_string_stream.h"
#include "io/wrong_format_exception.h"
#include "io/logger.h"
#include "io/regexes.h"
#include "chem/molecule.h"
#include "utility.h"

/**
 * Input/Standard orientation is printed in Gaussian output in the following format.
 *  ---------------------------------------------------------------------
 *  Center     Atomic      Atomic             Coordinates (Angstroms)
 *  Number     Number       Type             X           Y           Z
 *  ---------------------------------------------------------------------
 *       1          8           0       -0.102389    0.767918    0.000000
 *       2          1           0        0.857611    0.767918    0.000000
 *       3          1           0       -0.422844    1.672854    0.000000
 *  ---------------------------------------------------------------------
 */

struct ccio::gaussian_cartesian_orientation_reader::gaussian_cartesian_orientation_reader_private
{
    ccio::molecule& molecule;

    gaussian_cartesian_orientation_reader_private(ccio::molecule& molecule) :
        molecule(molecule) {}
};

ccio::gaussian_cartesian_orientation_reader::gaussian_cartesian_orientation_reader(
        kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree,
        ccio::molecule& molecule) :
    section_reader(stream, tree, "Input/Standard orientation"),
    p(new gaussian_cartesian_orientation_reader_private(molecule))
{
    if (!molecule.is_empty()) {
        throw std::invalid_argument("Molecule should be empty.");
    }
}

ccio::gaussian_cartesian_orientation_reader::~gaussian_cartesian_orientation_reader()
{
}

void ccio::gaussian_cartesian_orientation_reader::do_read_section()
{
    boost::property_tree::ptree molecule_tree;
    // molecule_tree.put("<xmlattr>.name", "Molecule");

    std::string line;
    // we skip 4 lines (the table title)
    for (int i = 0; i < 4; i++) {
        line = stream().read_line();
    }

    // and then read coordinates
    LOG(info) << "Reading coordinates...";
    // Pattern is the following:
    //  1) integer number, Center Number
    //  2) separator \s+
    //  3) integer number, Atomic Number
    //  4) separator \s+
    //  5) integer number, Atomic Type
    //  6) separator \s+
    //  7) floating point number, Coordinates, X
    //  8) separator \s+
    //  9) floating point number, Coordinates, Y
    // 10) separator \s+
    // 11) floating point number, Coordinates, Z
    static const std::regex regex(
        kemiisto::io::re_int_g() + kemiisto::io::re_spaces()
        + kemiisto::io::re_int_g() + kemiisto::io::re_spaces()
        + kemiisto::io::re_int_g() + kemiisto::io::re_spaces()
        + kemiisto::io::re_real_g() + kemiisto::io::re_spaces()
        + kemiisto::io::re_real_g() + kemiisto::io::re_spaces()
        + kemiisto::io::re_real_g()
    );
    std::smatch match;

    line = stream().read_line();

    while (!stream().done() && std::regex_search(line, match, regex)) {
        double x, y, z;
        unsigned int atomic_number;

        try {
            atomic_number = boost::lexical_cast<unsigned int>(match[2]);
        } catch (const boost::bad_lexical_cast& e) {
            throw kemiisto::io::wrong_format_exception(
                "atomic number", stream().line_number(), e.what()
            );
        }

        try {
            x = boost::lexical_cast<double>(match[4]);
        } catch (const boost::bad_lexical_cast& e) {
            throw kemiisto::io::wrong_format_exception(
                "x coordinate", stream().line_number(), e.what()
            );
        }

        try {
            y = boost::lexical_cast<double>(match[5]);
        } catch (const boost::bad_lexical_cast& e) {
            throw kemiisto::io::wrong_format_exception(
                "y coordinate", stream().line_number(), e.what()
            );
        }

        try {
            z = boost::lexical_cast<double>(match[6]);
        } catch (const boost::bad_lexical_cast& e) {
            throw kemiisto::io::wrong_format_exception(
                "z coordinate", stream().line_number(), e.what()
            );
        }

        boost::property_tree::ptree atom_tree;
        // atom_tree.put("<xmlattr>.name", "Atom");
        atom_tree.put("<xmlattr>.atomic_number", atomic_number);
        atom_tree.put("<xmlattr>.x", kemiisto::to_string(x, 20, 15));
        atom_tree.put("<xmlattr>.y", kemiisto::to_string(y, 20, 15));
        atom_tree.put("<xmlattr>.z", kemiisto::to_string(z, 20, 15));
        molecule_tree.add_child("Atom", atom_tree);

        p->molecule.create_atom(atomic_number, Eigen::Vector3d(x, y, z));

        line = stream().read_line();
    }

    LOG(info) << "Done.";
    tree().add_child("Molecule", molecule_tree);
    p->molecule.rebond();
}

const std::string& ccio::gaussian_cartesian_orientation_reader::start_string() const
{
    static const std::string s = "orientation:";
    return s;
}

const std::vector<std::string>& ccio::gaussian_cartesian_orientation_reader::end_strings() const
{
    static const std::vector<std::string> v = { "--" };
    return v;
}
