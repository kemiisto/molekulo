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

#include "formats/gaussian/gaussian_job_sp_reader.h"

#include <boost/algorithm/string.hpp>

#include "formats/gaussian/gaussian_mp2_reader.h"
#include "formats/gaussian/gaussian_out_file.h"
#include "formats/gaussian/gaussian_scf_reader.h"
#include "io/not_found_exception.h"
#include "io/not_implemented_exception.h"

struct ccio::gaussian_job_sp_reader::gaussian_job_sp_reader_private
{
    const std::string& route_section;

    gaussian_job_sp_reader_private(const std::string& route_section) :
            route_section(route_section)
    {}
};

ccio::gaussian_job_sp_reader::gaussian_job_sp_reader(
        kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& root,
        ccio::molecule& molecule,
        const std::string& route_section) :
        job_sp_reader(stream, root, molecule),
        p(new gaussian_job_sp_reader_private(route_section))
{
}

ccio::gaussian_job_sp_reader::~gaussian_job_sp_reader()
{
}

std::vector<ccio::method_type> ccio::gaussian_job_sp_reader::method_types() const
{
    // If no keywords are present in the route section, the calculation defaults to HF/STO-3G SP.

    std::vector<ccio::method_type> v;

    static const std::vector<std::string> scf_methods {
            // Semi-Empirical Methods
            "AM1"       , "PM3"      , "PM3MM"    , "PM6"       , "PDDG",
            // Hartree-Fock
            "HF"        ,
            // Standalone Functionals
            // Exchange Only (3)
            "HFS"       , "XAlpha"   , "HFB"      ,
            // Pure (13)
            "VSXC"      , "HCTH"     , "HCTH93"   , "HCTH147"   , "HCTH407"  ,
            "tHCTH"     , "M06L"     , "B97D"     , "B97D3"     , "SOGGA11"  ,
            "M11L"      , "N12"      , "MN12L"    ,
            // Hybrid (27)
            "B3LYP"     , "B3P86"    , "B3PW91"   , "B1B95"     , "mPW1PW91" ,
            "mPW1LYP"   , "mPW1PBE"  , "mPW3PBE"  , "B98"       , "B971"     ,
            "B972"      , "PBE1PBE"  , "B1LYP"    , "O3LYP"     , "BHandH"   ,
            "BHandHLYP" , "BMK"      , "M06"      , "M06HF"     , "M062X"    ,
            "tHCTHhyb"  , "APFD"     , "APF"      , "SOGGA11X"  , "PBEh1PBE" ,
            "TPSSh"     , "X3LYP"    ,
            // Range-Separated Hybrid (13)
            "HYBRID"    , "HSEH1PBE" , "OHSE2PBE" , "OHSE1PBE"  , "wB97XD"   ,
            "wB97"      , "wB97X"    , "LC-wPBE"  , "CAM-B3LYP" , "HISSbPBE" ,
            "M11"       , "N12SX"    , "MN12SX"
    };

    for (const auto& m : scf_methods) {
        if (std::search(p->route_section.begin(), p->route_section.end(), m.begin(), m.end(),
                        [](char ch1, char ch2){ return std::tolower(ch1) == std::tolower(ch2); }
        ) != p->route_section.end()) {
            v.push_back(ccio::method_type::scf);
        }
    }
    return v;
}

std::vector<ccio::scf_type> ccio::gaussian_job_sp_reader::scf_types() const
{
    // 1) DIIS is default, a combination of EDIIS [Kudin02] and CDIIS.
    // 2) NoDIIS prohibits use of DIIS extrapolation, the output though is quite similar.
    //    With some surptises such as "E=   (Non-Variational)" after "4-Point extrapolation".
    // 3) CDIIS has the same output structure as DIIS.
    // 4) QC
    // 5) XQC = DIIS + QC (if DIIS did not converge).
    //    MaxConventionalCycles set the limit on the number of DIIS cycles.
    // 6) YQC seems to be QC + DIIS + QC. Available in G09 D.01 only.
    // 7) DM is the direct minimization SCF program [Seeger76].
    std::vector<ccio::scf_type> v;
    
    std::string s = p->route_section;
    boost::to_lower(s);
    
    if (s.find("xqc") != std::string::npos) {
        v.push_back(ccio::scf_type::diis);
        v.push_back(ccio::scf_type::qc);
    } else if (s.find("yqc") != std::string::npos) {
        v.push_back(ccio::scf_type::qc);
        v.push_back(ccio::scf_type::diis);
        v.push_back(ccio::scf_type::qc);
    } else if (s.find("qc") != std::string::npos) {
        v.push_back(ccio::scf_type::qc);
    } else if (s.find("dm") != std::string::npos) {
        v.push_back(ccio::scf_type::dm);
    } else {
        v.push_back(ccio::scf_type::diis);
    }

    return v;
}

/*
 * L301 generates basis set information.
 */
const std::string& ccio::gaussian_job_sp_reader::start_string() const
{
    static const std::string s = "l301"; // SURE???
    return s;
}

const std::vector<std::string>& ccio::gaussian_job_sp_reader::end_strings() const
{
    static const std::vector<std::string> v = { "#" };
    return v;
}


std::unique_ptr<ccio::scf_reader> ccio::gaussian_job_sp_reader::get_scf_reader(
        boost::property_tree::ptree& tree, ccio::scf_type scf_type)
{
    return std::unique_ptr<ccio::scf_reader>{
            std::make_unique<ccio::gaussian_scf_reader>(stream(), tree, scf_type)
    };
}

std::unique_ptr<ccio::mp2_reader> ccio::gaussian_job_sp_reader::get_mp2_reader(
        boost::property_tree::ptree& tree)
{
    return std::unique_ptr<ccio::mp2_reader>{
            std::make_unique<ccio::gaussian_mp2_reader>(stream(), tree)
    };
}
