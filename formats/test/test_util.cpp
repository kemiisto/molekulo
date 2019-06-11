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

#include "test_util.h"

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/test/unit_test.hpp>

#include "chem/atom.h"
#include "chem/molecule.h"
#include "formats/dalton/dalton_scf_reader.h"
#include "formats/gaussian/gaussian_scf_reader.h"
#include "formats/dalton/dalton_cartesian_coordinates_reader.h"
#include "formats/gaussian/gaussian_cartesian_orientation_reader.h"
#include "io/input_string_stream.h"
#include "tolerance.h"

boost::filesystem::path ccio::samples_dir()
{
    boost::filesystem::path samples(boost::filesystem::current_path());
//    std::cout << "cwd: " << samples << std::endl;
// #ifdef __APPLE__
//     // Get out of the app bundle.
//     for (int i = 0; i < 3; ++i) {
//         samples = samples.parent_path();
//     }
// #endif
    for (int i = 0; i < 3; ++i) {
        samples = samples.parent_path();
    }
    samples /= "samples";
//    std::cout << "samples: " << samples << std::endl;
    return samples;
}

void ccio::test_dir(const boost::filesystem::path& dir,
        const boost::filesystem::path& extension, uintmax_t max_file_size)
{
    boost::filesystem::directory_iterator end;
    for (boost::filesystem::directory_iterator it(dir); it != end; ++it) {
        if (it->path().extension() == extension && file_size(it->path()) < max_file_size) {
            std::unique_ptr<ccio::text_file> chemFile = ccio::text_file::newInstance(it->path().string());
            chemFile->read();
        }
    }
}

void ccio::check_scf(ccio::text_file::type file_type, ccio::scf_type scf_type,
        const std::string& string, bool converged, const std::vector<double>& true_energies)
{
    kemiisto::io::input_string_stream stream(string);
    stream.read_line();

    boost::property_tree::ptree tree;

    std::unique_ptr<ccio::scf_reader> reader;
    switch (file_type) {
    case ccio::text_file::type::dalton_out_file:
        reader.reset(new ccio::dalton_scf_reader(stream, tree, scf_type));
        break;
    case ccio::text_file::type::gaussian_out_file:
        reader.reset(new ccio::gaussian_scf_reader(stream, tree, scf_type));
        break;
    default:
        throw std::invalid_argument("Wrong file type.");
    }
    reader->read();

    // First we check the parent done attribute which indicates did SCF converge or not.
    BOOST_CHECK_EQUAL(tree.get<bool>("<xmlattr>.done"), converged);

    // Then we check the parent value attribute which contains
    // either the final SCF energy in case if SCF converged
    // or ccio::did_not_converge_message otherwise.
    if (converged) {
        BOOST_CHECK_CLOSE(tree.get<double>("<xmlattr>.value"), true_energies.back(), tolerance);
    } else {
        BOOST_CHECK_EQUAL(tree.get<std::string>("<xmlattr>.value"), ccio::did_not_converge_message);
    }

    // And finally we check SCF energy at each and every cycle.
    // SCF cycles are stored in childs of the tree with keys "Item",
    // but there is one more child with key "<xmlattr>" which stores XML attributes of the parent.
    // Thus, when iterating over childs we have to check that the key is equal to "Item".
    int i = 1;
    for (const auto& item : tree) {
        if (item.first == "Item") {
            int name = item.second.get<int>("<xmlattr>.name");
            double value = item.second.get<double>("<xmlattr>.value");
            BOOST_CHECK_EQUAL(name, i);
            BOOST_CHECK_CLOSE(value, true_energies[name - 1], tolerance);
            i++;
        }
    }
}

void ccio::check_coordinates(ccio::text_file::type file_type, const std::string& string,
        bool bohrs, const std::vector<Eigen::Vector3d>& true_coordinates)
{
    kemiisto::io::input_string_stream stream(string);
    stream.read_line();

    ccio::molecule molecule;
    boost::property_tree::ptree tree;

    std::unique_ptr<ccio::reader> reader;
    switch (file_type) {
    case ccio::text_file::type::dalton_out_file:
        reader.reset(new ccio::dalton_cartesian_coordinates_reader(stream, molecule));
        break;
    case ccio::text_file::type::gaussian_out_file:
        reader.reset(new ccio::gaussian_cartesian_orientation_reader(stream, tree, molecule));
        break;
    default:
        throw std::invalid_argument("Wrong file type.");
    }
    reader->read();

    double conv = 1.0;
    if (bohrs) conv = bohrs_to_angstroms;
    BOOST_CHECK_EQUAL(molecule.number_of_atoms(), true_coordinates.size());
    for (std::size_t i = 0; i < molecule.number_of_atoms(); ++i) {
        const Eigen::Vector3d& v = molecule.atom(i).centre();
        for (int j = 0; j < 3; ++j) {
            BOOST_CHECK_CLOSE(v(j), true_coordinates.at(i)(j) * conv, tolerance);
        }
    }
}
