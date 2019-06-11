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
#include <iostream>
#include <memory>

#include "chem/molecule.h"
#include "chem/reflection.h"
#include "formats/dalton/dalton_cartesian_coordinates_reader.h"
#include "formats/dalton/dalton_coupled_cluster_section_reader.h"
#include "formats/dalton/dalton_dal_entry.h"
#include "formats/dalton/dalton_job_sp_reader.h"
#include "formats/dalton/dalton_mol_entry.h"
#include "formats/dalton/dalton_mol_entry_reader.h"
#include "formats/dalton/dalton_mp2_reader.h"
#include "formats/dalton/dalton_scf_reader.h"
#include "formats/dalton/dalton_symmetry_independent_centres_reader.h"
#include "io/input_stream.h"
#include "io/logger.h"
#include "io/not_found_exception.h"
#include "io/regexes.h"
#include "io/wrong_format_exception.h"

struct ccio::dalton_job_sp_reader::dalton_job_sp_reader_private
{
    const ccio::dalton_mol_entry& mol_entry;
    const ccio::dalton_dal_entry& dal_entry;

    dalton_job_sp_reader_private(const ccio::dalton_mol_entry& mol_entry,
            const ccio::dalton_dal_entry& dal_entry) :
        mol_entry(mol_entry),
        dal_entry(dal_entry)
    {}
};

ccio::dalton_job_sp_reader::dalton_job_sp_reader(
        kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& root,
        ccio::molecule& molecule,
        const std::string& program_version, int print_level,
        const ccio::dalton_mol_entry& mol_entry,
        const ccio::dalton_dal_entry& dal_entry) :
    job_sp_reader(stream, root, molecule),
    p(new dalton_job_sp_reader_private(mol_entry, dal_entry))
{
    (void)program_version;
    (void)print_level;
}

ccio::dalton_job_sp_reader::~dalton_job_sp_reader()
{
}

std::vector<ccio::method_type> ccio::dalton_job_sp_reader::method_types() const
{
    return p->dal_entry.method_types();
}

std::vector<ccio::scf_type> ccio::dalton_job_sp_reader::scf_types() const
{
    return p->dal_entry.scf_types();
}

/*
 * Starts with "Starting in Wave Function Section (SIRIUS)",
 * but it is enough to search for just "(SIRIUS)".
 */
const std::string& ccio::dalton_job_sp_reader::start_string() const
{
    static const std::string s = "(SIRIUS)";
    return s;
}

/*
 * Ends with "End of Wave Function Section (SIRIUS)" regardles of convergence,
 * but again it is enough to search for just "(SIRIUS)".
 */
const std::vector<std::string>& ccio::dalton_job_sp_reader::end_strings() const
{
    static const std::vector<std::string> v = { "(SIRIUS)" }; 
    return v;
}

// const std::string& ccio::dalton_job_sp_reader::succeeded_string() const
// {
//     return start_string();
// }

// const std::string& ccio::dalton_job_sp_reader::failed_string() const
// {
//     return start_string();
// }

std::unique_ptr<ccio::scf_reader> ccio::dalton_job_sp_reader::get_scf_reader(
        boost::property_tree::ptree& tree, ccio::scf_type scf_type)
{
    return std::unique_ptr<ccio::scf_reader>{
            std::make_unique<ccio::dalton_scf_reader>(stream(), tree, scf_type)
    };
}

std::unique_ptr<ccio::mp2_reader> ccio::dalton_job_sp_reader::get_mp2_reader(
        boost::property_tree::ptree& tree)
{
    return std::unique_ptr<ccio::mp2_reader>{
            std::make_unique<ccio::dalton_mp2_reader>(stream(), tree)
    };
}
