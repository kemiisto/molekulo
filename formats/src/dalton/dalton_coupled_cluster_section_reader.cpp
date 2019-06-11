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

#include "formats/dalton/dalton_coupled_cluster_section_reader.h"

#include "io/input_stream.h"
#include "io/logger.h"
#include "io/not_found_exception.h"
#include "io/regexes.h"
#include "io/wrong_format_exception.h"

void read_cc_iterations(kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree);

void read_perturbative_triples(kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree);

struct ccio::dalton_coupled_cluster_section_reader::dalton_coupled_cluster_section_reader_private
{
    boost::property_tree::ptree& tree;

    dalton_coupled_cluster_section_reader_private(boost::property_tree::ptree& tree) : tree(tree)
    { }
};

ccio::dalton_coupled_cluster_section_reader::dalton_coupled_cluster_section_reader(kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& tree) :
        reader(stream),
        p(new dalton_coupled_cluster_section_reader_private(tree))
{
}

ccio::dalton_coupled_cluster_section_reader::~dalton_coupled_cluster_section_reader()
{
}

void ccio::dalton_coupled_cluster_section_reader::do_read()
{
    if (stream().found("(CC)")) {
        LOG(debug) << "Reading Coupled Cluster Section...";
        if (stream().found("Iter.")) {
            read_cc_iterations(stream(), p->tree);
            std::vector<std::string> v = {"Perturbative triples corrections", "SUMMARY OF COUPLED CLUSTER CALCULATION"};
            if (stream().find(v.begin(), v.end()) == v.begin()) {
                read_perturbative_triples(stream(), p->tree);
            }
            // reading section to its end
            stream().found("(CC)");
        } else {
            throw kemiisto::io::not_found_exception("CC iterations");
        }
    } else {
        throw kemiisto::io::not_found_exception("beginning of Coupled Cluster Section");
    }
}

void read_cc_iterations(kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree)
{
    LOG(debug) << "Reading CC iterations...";

    // First comes MP2 energy possibly followed by few CC energies.
    // Iter.  1: Coupled cluster MP2   energy :     -75.7080410459820570
    // Iter.  1: Coupled cluster CCSD  energy :     -75.7114047772544581
    // Iter.  2: Coupled cluster CCSD  energy :     -75.7150068138121242
    static const std::regex energy_regex(
            R"(Iter.\s+)" + kemiisto::io::re_int_g() + R"(:\s+Coupled cluster\s+(\w+)\s+energy\s+:\s+)" +
            kemiisto::io::re_real_g());
    std::smatch energy_smatch;

    if (std::regex_search(stream.current_line(), energy_smatch, energy_regex)) {
        LOG(debug) << energy_smatch[2].str() << " energy: " << energy_smatch[3].str();
        boost::property_tree::ptree mp2_tree;
        mp2_tree.put("<xmlattr>.name", energy_smatch[2]);
        mp2_tree.put("<xmlattr>.value", energy_smatch[3]);
        mp2_tree.put("<xmlattr>.done", "true");
        tree.add_child("Item", mp2_tree);
        stream.read_line();
    } else {
        throw kemiisto::io::wrong_format_exception("MP2 energy", stream.line_number());
    }

    if (std::regex_search(stream.current_line(), energy_smatch, energy_regex)) {
        boost::property_tree::ptree cc_tree;
        while (std::regex_search(stream.current_line(), energy_smatch, energy_regex)) {
            LOG(debug) << energy_smatch[2].str() << " energy: " << energy_smatch[3].str();
            boost::property_tree::ptree cc_iter_tree;
            cc_iter_tree.put("<xmlattr>.name", energy_smatch[1]);
            cc_tree.put("<xmlattr>.name", energy_smatch[2]);
            cc_iter_tree.put("<xmlattr>.value", energy_smatch[3]);
            cc_tree.add_child("Item", cc_iter_tree);
            cc_tree.put("<xmlattr>.value", energy_smatch[3]);
            stream.read_line();
        }
        // CCSD  energy converged to within   0.10D-07 is          -75.715297249359
        std::vector<std::string> v = {"energy converged", "not converged"};
        if (stream.find(v.begin(), v.end()) == v.begin()) {
            cc_tree.put("<xmlattr>.done", "true");
        } else {
            cc_tree.put("<xmlattr>.done", "false");
        }
        tree.add_child("Item", cc_tree);
    }

    LOG(debug) << "Reading CC iterations done.";
}

void read_perturbative_triples(kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree)
{
    LOG(debug) << "Reading perturbative triples corrections...";

    //    The E4 doubles and triples:            -0.0014066167
    //    The E5 singles and triples:             0.0000809740
    //
    //    Total energy CC(3):                   -75.7166221342
    //    Total energy CCSD(T):                 -75.7166228920
    static const std::regex energy_regex(R"(Total energy\s+([^:]+):\s+)" + kemiisto::io::re_real_g());
    std::smatch energy_smatch;

    if (stream.found("Total energy")) {
        if (std::regex_search(stream.current_line(), energy_smatch, energy_regex)) {
            LOG(debug) << energy_smatch[1].str() << " energy: " << energy_smatch[2].str();
            boost::property_tree::ptree cct_tree;
            cct_tree.put("<xmlattr>.name", energy_smatch[1]);
            cct_tree.put("<xmlattr>.value", energy_smatch[2]);
            cct_tree.put("<xmlattr>.done", "true");
            tree.add_child("Item", cct_tree);
            stream.read_line();
        } else {
            throw kemiisto::io::wrong_format_exception("Total energy with triples", stream.line_number());
        }
    } else {
        throw kemiisto::io::not_found_exception("Total energy with triples");
    }

    LOG(debug) << "Reading perturbative triples corrections done.";
}
