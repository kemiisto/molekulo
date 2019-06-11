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

#include "formats/dalton/dalton_out_file.h"

#include <iostream>
#include <boost/property_tree/xml_parser.hpp>

#include <boost/algorithm/string.hpp>

#include "formats/dalton/dalton_dal_entry.h"
#include "formats/dalton/dalton_dal_entry_reader.h"
#include "formats/dalton/dalton_job_sp_reader.h"
#include "formats/dalton/dalton_mol_entry.h"
#include "formats/dalton/dalton_mol_entry_reader.h"
#include "formats/dalton/dalton_symmetry_independent_centres_reader.h"
#include "io/logger.h"
#include "io/not_found_exception.h"
#include "io/not_implemented_exception.h"
#include "io/regexes.h"
#include "io/wrong_format_exception.h"

struct ccio::DaltonOutFile::DaltonOutFilePrivate
{
    ccio::dalton_mol_entry mol_entry;
    ccio::dalton_dal_entry dal_entry;
    int print_level;

    DaltonOutFilePrivate() :
        mol_entry(),
        dal_entry(),
        print_level(0)
    {}

    void determine_program_name_and_version(kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& root);
    void read_dal_file(kemiisto::io::input_stream& stream);
    void read_mol_file(kemiisto::io::input_stream& stream);
    void determine_overall_print_level(kemiisto::io::input_stream& stream);
};

ccio::DaltonOutFile::DaltonOutFile(const std::string& absoluteFilePath) :
    ccio::out_file(absoluteFilePath),
    p(std::unique_ptr<DaltonOutFilePrivate>(new DaltonOutFilePrivate()))
{
}

ccio::DaltonOutFile::~DaltonOutFile()
{
}

void ccio::DaltonOutFile::do_read()
{
    LOG(info) << " as DALTON output..." << "\n";

    p->determine_program_name_and_version(stream, tree());

    if (program() == "LSDALTON") {
        throw kemiisto::io::not_implemented_exception("LSDALTON support");
    }

    if (version() == "2013") {
        p->read_dal_file(stream);
        p->read_mol_file(stream);
        p->determine_overall_print_level(stream);
        // When symmetry detection requested the program:
        //   a) translates and rotates the molecule before the symmetry detection;
        //   b) then continues to work in the new coordinate system.
        // Thus, in such a case we read the coordinates obtained after the symmetry detection.
        // Otherwise, we just copy the input geometry from the *.mol file which is already read.
        if (p->mol_entry.is_addition_of_symmetry_requested()) {
            LOG(debug) << "The addition of symmetry was requested.";
            // Symmetry class found: D(2h)
            // read it and then
            if (stream.found("Symmetry Independent Centres")) {
                stream.read_line();
                dalton_symmetry_independent_centres_reader reader(stream, molecule());
                reader.read();
                std::vector<std::string> generators;
                // The following elements were found:   X  Y  Z
                // But what if is was detected to be just C1?
                std::string s = stream.read_line();
                s.erase(0, 35);
                boost::algorithm::trim(s);
                boost::algorithm::split(generators, s, boost::is_space(), boost::token_compress_on);
                ccio::dalton_mol_entry_reader::complete_molecule(molecule(), generators);
            } else {
                throw kemiisto::io::not_found_exception("symmetry independent centres");
            }
        } else {
            LOG(debug) << "The addition of symmetry was not requested.";
            // copy input orientation from *.mol file
            molecule() = p->mol_entry.get_molecule();
            // and complete the molecule if necessary
            if (p->mol_entry.get_number_of_generators() > 0) {
                ccio::dalton_mol_entry_reader::complete_molecule(molecule(), p->mol_entry.generators());
            }
        }

        molecule().rebond();
    } else {
        throw kemiisto::io::not_implemented_exception("DALTON " + version() + " support");
    }

    boost::property_tree::ptree job_tree;
    ccio::dalton_job_sp_reader reader(stream, job_tree, molecule(), version(),
                                      p->print_level, p->mol_entry, p->dal_entry);
    reader.read();
    tree().add_child("Out.Job", job_tree);

    boost::property_tree::xml_writer_settings<std::string> settings(' ', 4);
    boost::property_tree::write_xml(std::cout, tree(), settings);
}

void ccio::DaltonOutFile::DaltonOutFilePrivate::determine_program_name_and_version(
    kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree)
{
    // This is output from DALTON (Release 2.0 rev. 0, Mar. 2005)
    // This is output from DALTON (Release Dalton2013 patch 0)
    // This is output from DALTON 2013.4
    // This is output from LSDALTON (Release Dalton2013)
    if (stream.found("This is output from")) {
    	std::string line = stream.current_line();
    	// DALTON or LSDALTON
    	if (line.find("LSDALTON") != std::string::npos) {
    		tree.put("Out.<xmlattr>.program", "LSDALTON");
    	} else if (line.find("DALTON") != std::string::npos) {
    		tree.put("Out.<xmlattr>.program", "DALTON");
    	} else {
    		throw kemiisto::io::wrong_format_exception("DALTON/LSDALTON version", stream.line_number());
    	}
    	// Version
    	if (line.find("2013") != std::string::npos) {
    		tree.put("Out.<xmlattr>.version", "2013");
    	} else if (line.find("2.0") != std::string::npos) {
    		tree.put("Out.<xmlattr>.version", "2");
    	} else {
    		throw kemiisto::io::not_found_exception("DALTON/LSDALTON version");
    	}
    } else {
    	throw kemiisto::io::not_found_exception("DALTON/LSDALTON version string");
    }
}

void ccio::DaltonOutFile::DaltonOutFilePrivate::read_dal_file(kemiisto::io::input_stream& stream)
{
    if (stream.found("Content of the .dal input file")) {
        stream.read_line();
        stream.read_line();
        ccio::dalton_dal_entry_reader dal_entry_reader(stream, dal_entry);
        dal_entry_reader.read();
    } else {
        throw kemiisto::io::not_found_exception("content of the .dal file");
    }
}

void ccio::DaltonOutFile::DaltonOutFilePrivate::read_mol_file(kemiisto::io::input_stream& stream)
{
    if (stream.found("Content of the .mol file")) {
        stream.read_line();
        stream.read_line();
        ccio::dalton_mol_entry_reader mol_entry_reader(stream, mol_entry);
        mol_entry_reader.read();
    } else {
        throw kemiisto::io::not_found_exception("content of the .mol file");
    }
}

void ccio::DaltonOutFile::DaltonOutFilePrivate::determine_overall_print_level(
	kemiisto::io::input_stream& stream)
{
	// Overall default print level:    0
	// Default print level:        0
    if (stream.found("print level:")) {
        static const std::regex regex(R"(print level:\s+)" + kemiisto::io::re_int_g());
        std::smatch smatch;
        if (std::regex_search(stream.current_line(), smatch, regex)) {
            LOG(debug) << smatch[1];
            print_level = std::stoi(smatch[1]);
        } else {
            throw kemiisto::io::wrong_format_exception("overall print level", stream.line_number());
        }
    } else {
        throw kemiisto::io::not_found_exception("overall print level");
    }
}
