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

#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "chem/molecule.h"
#include "chem/reflection.h"
#include "formats/dalton/dalton_cartesian_coordinates_reader.h"
#include "formats/dalton/dalton_coupled_cluster_section_reader.h"
#include "formats/dalton/dalton_dal_entry.h"
#include "formats/dalton/dalton_job_sp_reader.h"
#include "formats/dalton/dalton_mol_entry.h"
#include "formats/dalton/dalton_mol_entry_reader.h"
#include "formats/dalton/dalton_symmetry_independent_centres_reader.h"
#include "io/not_found_exception.h"
#include "io/regexes.h"
#include "io/wrong_format_exception.h"

bool scf_done(const boost::property_tree::ptree& tree);

struct ccio::job_sp_reader::job_sp_reader_private
{
    job_sp_reader_private()
    {}
};

ccio::job_sp_reader::job_sp_reader(
        kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& root,
        ccio::molecule& molecule) :
    job_reader(stream, root, "single point job", molecule),
    p(std::make_unique<job_sp_reader_private>())
{
    job_reader::tree().put("<xmlattr>.type", "Energy");
    job_reader::tree().put("<xmlattr>.done", false);
}

ccio::job_sp_reader::~job_sp_reader()
{
}

void ccio::job_sp_reader::do_read_section()
{
    boost::property_tree::ptree scf_tree;
    scf_tree.put("<xmlattr>.done", false);

    for (const auto& type : method_types()) {
        switch (type) {
            case ccio::method_type::scf:
                scf_tree.put("<xmlattr>.name", "SCF");
                for (const auto& type : scf_types()) {
                    if (scf_tree.get<bool>("<xmlattr>.done")) break;
                    auto scf_reader = get_scf_reader(scf_tree, type);
                    scf_reader->read();
                }
                tree().add_child("Item", scf_tree);
                break;
            case ccio::method_type::mp2: {
                if (scf_done(tree())) {
                    auto mp2_reader = get_mp2_reader(tree());
                    mp2_reader->read();
                }
            }
                break;
            case ccio::method_type::ci:
                break;
            case ccio::method_type::gasci:
                break;
            case ccio::method_type::cc:
                break;
            case ccio::method_type::mcscf:
                break;
            case ccio::method_type::nevpt2:
                break;
        }
    }

    if (is_job_done()) {
        tree().put("<xmlattr>.done", true);
    } else {
        tree().put("<xmlattr>.done", false);
    }
}

bool scf_done(const boost::property_tree::ptree& tree)
{
    // Currently used to decide do we need to read a post-HF results that follows HF ones.
    // At that time there should be only 2 children in a job tree: <xmlattr> and SCF Item.
    assert (tree.size() == 2);
    auto scf_tree = tree.get_child("Item");
    assert (scf_tree.get<std::string>("<xmlattr>.name") == "SCF");
    return scf_tree.get<bool>("<xmlattr>.done");
}
