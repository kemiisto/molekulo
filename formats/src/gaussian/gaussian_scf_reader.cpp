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

#include "formats/gaussian/gaussian_scf_reader.h"

#include "formats/constants.h"

#include "io/input_stream.h"
#include "io/logger.h"
#include "io/regexes.h"
#include "io/not_found_exception.h"
#include "io/wrong_format_exception.h"

ccio::gaussian_scf_reader::gaussian_scf_reader(
        kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& tree,
        ccio::scf_type scf_type) :
    scf_reader(stream, tree, scf_type)
{
}

ccio::gaussian_scf_reader::~gaussian_scf_reader()
{
}

/* DIIS:
 *  (Enter c:\g09w\l502.exe)
 *  Leave Link  502
 *  Error termination via Lnk1e in c:\g09w\l502.exe
 * QC:
 *  (Enter c:\g09w\l508.exe)
 *  Leave Link  508
 *  Error termination via Lnk1e in c:\g09w\l508.exe
 * DM:
 *  (Enter c:\g09w\l503.exe)
 *  Leave Link  503
 *  Error termination via Lnk1e in c:\g09w\l503.exe
 */

const std::string& ccio::gaussian_scf_reader::start_string() const
{
    static const std::map<ccio::scf_type, std::string> m = {
            { ccio::scf_type::diis , "l502.exe" },
            { ccio::scf_type::qc   , "l508.exe" },
            { ccio::scf_type::dm   , "l503.exe" }
    };
    return m.at(scf_type());
}

const std::vector<std::string>& ccio::gaussian_scf_reader::end_strings() const
{
    static const std::vector<std::string> v = {
        "Leave Link",
        "Error termination"
    };
    return v;
}

const std::map<ccio::scf_type, std::string>& ccio::gaussian_scf_reader::cycle_start_string() const
{
    static const std::map<ccio::scf_type, std::string> m = {
            { ccio::scf_type::diis , "Cycle"     },
            { ccio::scf_type::qc   , "Iteration" },
            { ccio::scf_type::dm   , "Inv2"      }
    };
    return m;
}

const std::map<ccio::scf_type, std::string>& ccio::gaussian_scf_reader::scf_converged_string() const
{
    static const std::map<ccio::scf_type, std::string> m = {
            { ccio::scf_type::diis , "SCF Done" },
            { ccio::scf_type::qc   , "SCF Done" },
            { ccio::scf_type::dm   , "SCF Done" }
    };
    return m;
}

const std::map<ccio::scf_type, std::string>& ccio::gaussian_scf_reader::scf_not_converged_string() const
{
    // Note that SCF Done is still printed out for DIIS- and QC-SCF, but not for DM-SCF,
    // so the keywords here must appear BEFORE SCF Done in the output.
    // Otherwise a non-convergent SCF will be erroneously recognized as a convergent one. 
    static const std::map<ccio::scf_type, std::string> m = {
            { ccio::scf_type::diis , "Convergence criterion not met" },
            { ccio::scf_type::qc   , "Convergence failure"           },
            { ccio::scf_type::dm   , "ITERATION ABORTED"             }
    };
    return m;
}

void ccio::gaussian_scf_reader::read_cycle(double& energy)
{
    /*
     * DIIS: E= -75.5701757793356
     * QC: EE= -75.5170109481120
     * DM: E= -75.5774172736844
     */

    static const std::map<ccio::scf_type, std::string> energy_string_start = {
        { ccio::scf_type::diis , "E= "   },
        { ccio::scf_type::qc   , "EE= "  },
        { ccio::scf_type::dm   , "E= "   }
    };

    static const std::regex gaussian_diis_dm_energy_regex(
        "E=" + kemiisto::io::re_spaces() + kemiisto::io::re_real_g()
    );

    static const std::regex gaussian_qc_energy_regex(
        "EE=" + kemiisto::io::re_spaces() + kemiisto::io::re_real_g()
    );

    static const std::map<ccio::scf_type, std::regex> energy_regex = {
        { ccio::scf_type::diis , gaussian_diis_dm_energy_regex },
        { ccio::scf_type::qc   , gaussian_qc_energy_regex      },
        { ccio::scf_type::dm   , gaussian_diis_dm_energy_regex }
    };

    if (stream().found(energy_string_start.at(scf_type()))) {
        const std::regex regex(energy_regex.at(scf_type()));
        std::smatch smatch;
        std::string line;
        if (scf_type() == ccio::scf_type::dm) {
            line = stream().previous_line();
        } else {
            line = stream().current_line();
        }
        if (std::regex_search(line, smatch, regex)) {
            energy = std::stod(smatch[1]);
            LOG(debug) << energy;
        } else {
            // Treating the special case of SCF=NoDIIS.
            // It is a bit odd that NoDIIS SCF results are read by the same procedure as DIIS ones,
            // but they are quite simillar except for former containing some non-variational
            // energies along the road.
            if (scf_type() == ccio::scf_type::diis && line.find("Non-Variational")) {
                energy = 0.0;
                LOG(debug) << "Non-variational energy.";
            } else {
                LOG(error) << "Couldn't read SCF energy.";
                throw kemiisto::io::wrong_format_exception("SCF energy", stream().line_number());
            }

        }
    } else {
        throw kemiisto::io::not_found_exception("SCF energy");
    }
    // For QC-SCF cycle energy is located on the last line read, thus,
    // the program will run an infinite loop reading the same energy again and again
    // if we don't read one more line here.
    // This is safe for all other types of SCF.
    stream().read_line();
}

void ccio::gaussian_scf_reader::read_final_energy(double& energy)
{
    //  SCF Done:  E(RHF) =  -75.5858099773     A.U. after   10 cycles
    //  SCF Done:  E(RRHF) =  -77.6009880572     a.u. after   11 cycles
    //  SCF Done:  E(RPBE-PBE) =  -76.3608011334     a.u. after    5 cycles
    static const std::regex regex(
        R"(SCF Done:\s+E\(.+\)\s+=\s+)" + kemiisto::io::re_real_g(), std::regex::icase
    );
    std::smatch smatch;
    if (std::regex_search(stream().current_line(), smatch, regex)) {
        energy = std::stod(smatch[1]);
    } else {
        throw kemiisto::io::wrong_format_exception("Final SCF energy", stream().line_number());
    }

}
