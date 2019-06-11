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

#include "formats/scf_reader.h"

#include "formats/constants.h"

#include "io/input_stream.h"
#include "io/logger.h"
#include "io/regexes.h"
#include "io/not_found_exception.h"
#include "io/wrong_format_exception.h"

struct ccio::scf_reader::scf_reader_private
{
    ccio::scf_type scf_type;
    double last_cycle_energy;

    scf_reader_private(ccio::scf_type scf_type) :
        scf_type(scf_type), last_cycle_energy(0.0) {}
};

ccio::scf_reader::scf_reader(
        kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& tree,
        ccio::scf_type scf_type) :
    section_reader(stream, tree, "SCF results"),
    p(new scf_reader_private(scf_type))
{
    tree.put("<xmlattr>.value", ccio::did_not_converge_message);
    tree.put("<xmlattr>.done", false);
}

ccio::scf_reader::~scf_reader()
{
}

ccio::scf_type ccio::scf_reader::scf_type() const
{
    return p->scf_type;
}

void ccio::scf_reader::do_read_section()
{
    LOG(debug) << "Reading SCF cycles...";

    // One SCF procedure might follow another one, e.g. QC-SCF can follow DIIS-SCF, or vice versa.
    // -1 due to <xmlattr> child.
    std::size_t cycle = tree().size() - 1;
    while (next_cycle_found()) {
        LOG(debug) << "Reading the cycle...";
        cycle++;
        // We keep track of last read SCF cycle energy because 
        // not every program outputs final SCF energy even when SCF converged,
        // in which case the last read SCF cycle energy serves as the final SCF energy (see below).
        read_cycle(p->last_cycle_energy);
        // Once we get the SCF cycle energy, we create a leaf in the SCF tree for it.
        boost::property_tree::ptree scf_cycle_tree;
        scf_cycle_tree.put("<xmlattr>.name", cycle);
        scf_cycle_tree.put("<xmlattr>.value", p->last_cycle_energy);
        tree().add_child("Item", scf_cycle_tree);
    }

    if (scf_converged()) {
        LOG(debug) << "SCF converged.";
        double final_energy = p->last_cycle_energy;
        read_final_energy(final_energy);
        // As mentioned above, not every program outputs final SCF energy even when SCF converged.
        // If this is the case, read_final_energy() returns the unchanged value of final_energy,
        // which is set to the last read SCF cycle energy prior to the call.
        // This way the last read SCF cycle energy would serve as the final SCF energy if there is
        // final SCF energy in the output.
        // Q: Why do we even need to read the final energy then,
        //    if the last read SCF cycle energy would do it?
        // A: One good reason is that some programs (e.g. ORCA) have an option 
        //    to run DFT SCF cycles with one grid, but once SCF converged,
        //    switch to a better grid and do final reevaluation of the SCF energy.
        //    In that case final SCF energy will of course differ from the last SCF cycle energy.
        tree().put("<xmlattr>.value", final_energy);
        tree().put("<xmlattr>.done", true);
    } else {
        LOG(debug) << "SCF did not converge.";
    }
}

bool ccio::scf_reader::next_cycle_found()
{
    LOG(debug) << "Searching the next SCF cycle...";

    const std::vector<std::string> v {
            cycle_start_string().at(scf_type()),
            scf_converged_string().at(scf_type()),
            scf_not_converged_string().at(scf_type())
    };

    if (stream().find(v.cbegin(), v.cend()) == v.cbegin()) {
        LOG(debug) << "Next SCF cycle found.";
        return true;
    } else {
        LOG(debug) << "Next SCF cycle not found.";
        return false;
    }
}

bool ccio::scf_reader::scf_converged()
{
    const std::string& s = scf_converged_string().at(scf_type());
    return (stream().current_line().find(s) != std::string::npos);
}
