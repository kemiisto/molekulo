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

#include "formats/dalton/dalton_scf_reader.h"

#include "formats/constants.h"
#include "io/input_stream.h"
#include "io/logger.h"
#include "io/regexes.h"
#include "io/not_found_exception.h"
#include "io/wrong_format_exception.h"

ccio::dalton_scf_reader::dalton_scf_reader(
        kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& tree,
        ccio::scf_type scf_type) :
    scf_reader(stream, tree, scf_type)
{
}

ccio::dalton_scf_reader::~dalton_scf_reader()
{
}

const std::string& ccio::dalton_scf_reader::start_string() const
{
    static const std::map<ccio::scf_type, std::string> m = {
            { ccio::scf_type::diis , "DIIS optimization" },
            { ccio::scf_type::qc   , "SIRIUS QC"   }
    };
    return m.at(scf_type());
}

const std::vector<std::string>& ccio::dalton_scf_reader::end_strings() const
{
    // If not converged DIIS-SCF might be followed by QC-SCF.
    static const std::vector<std::string> v = {
        "SIRIUS QC",
        "CPU and wall time for SCF"
    };
    return v;
}

const std::map<ccio::scf_type, std::string>& ccio::dalton_scf_reader::cycle_start_string() const
{
    static const std::map<ccio::scf_type, std::string> m = {
            { ccio::scf_type::diis , "--"              },
            { ccio::scf_type::qc   , "MACRO ITERATION" }
    };
    return m;
}

const std::map<ccio::scf_type, std::string>& ccio::dalton_scf_reader::scf_converged_string() const
{
    static const std::map<ccio::scf_type, std::string> m = {
            { ccio::scf_type::diis   , "DIIS converged"        },
            { ccio::scf_type::qc     , "Optimization control:" }
    };
    return m;
}

const std::map<ccio::scf_type, std::string>& ccio::dalton_scf_reader::scf_not_converged_string() const
{
    static const std::map<ccio::scf_type, std::string> m = {
            { ccio::scf_type::diis   , "DIIS aborted"                 },
            { ccio::scf_type::qc     , "Optimization control WARNING" }
    };
    return m;
}

void ccio::dalton_scf_reader::read_cycle(double& energy)
{
    // DIIS:
    // @  1  -75.3971666773       2.17D+00  -7.54D+01     3   1   1   0
    // QC:
    // Total QC-HF energy       :           -75.397166677311489  (MACRO    1)

    static const std::map<ccio::scf_type, std::string> energy_string_start = {
        { ccio::scf_type::diis   , "@"     },
        { ccio::scf_type::qc     , "Total" }
    };

    static const std::regex dalton_diis_energy_regex(
        kemiisto::io::re_int() + kemiisto::io::re_spaces() + kemiisto::io::re_real_g()
    );

    static const std::regex dalton_qc_energy_regex(
        kemiisto::io::re_real_g() + kemiisto::io::re_spaces()
            + R"(\(MACRO)" + kemiisto::io::re_spaces() + kemiisto::io::re_int() + R"(\))"
    );

    static const std::map<ccio::scf_type, std::regex> energy_regex = {
        { ccio::scf_type::diis , dalton_diis_energy_regex },
        { ccio::scf_type::qc   , dalton_qc_energy_regex   }
    };

    if (stream().found(energy_string_start.at(scf_type()))) {
        const std::regex regex(energy_regex.at(scf_type()));
        std::smatch smatch;
        if (std::regex_search(stream().current_line(), smatch, regex)) {
            energy = std::stod(smatch[1]);
            LOG(debug) << energy;
        } else {
            LOG(error) << "Couldn't read SCF energy.";
            throw kemiisto::io::wrong_format_exception("SCF energy", stream().line_number());
        }
    } else {
        throw kemiisto::io::not_found_exception("SCF energy");
    }
}

void ccio::dalton_scf_reader::read_final_energy(double& energy)
{
    // DIIS:
    // @     Converged SCF energy, gradient:    -75.585808994257    7.75D-07
    // QC:
    // 
    // No final SCF energy is printed for QC-SCF!
    // There will eventually be some "Final HF energy" in the output for both DIIS- and QC-SCF,
    // but way after the end of SCF results (e.g. after MP2 results), so it is irrelevant.
              
    if (scf_type() == ccio::scf_type::diis) {
        static const std::regex regex(R"(Converged SCF energy, gradient:\s+)" + kemiisto::io::re_real_g());
        std::smatch smatch;
        if (std::regex_search(stream().read_line(), smatch, regex)) {
            energy = std::stod(smatch[1]);
        } else {
            throw kemiisto::io::wrong_format_exception("Converged SCF energy", stream().line_number());
        }
    }
}
