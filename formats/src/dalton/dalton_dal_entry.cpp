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

#include "formats/dalton/dalton_dal_entry.h"

#include <boost/algorithm/string.hpp>

#include "io/logger.h"
#include "io/not_found_exception.h"
#include "io/not_implemented_exception.h"

std::string tree_name(const boost::property_tree::ptree& tree);

bool find_parametre(const boost::property_tree::ptree& tree, const std::string& name);
std::vector<std::string> get_parametres(const boost::property_tree::ptree& tree);

struct ccio::dalton_dal_entry::dalton_dal_entry_private
{
    boost::property_tree::ptree tree;

    dalton_dal_entry_private() :
        tree()
    {}
};

const std::map<std::string, ccio::dalton_dal_entry::job_type> ccio::dalton_dal_entry::string_to_job_type = {
    { ".INTEGRALS"          , ccio::dalton_dal_entry::job_type::integrals},
    { ".OPTIMIZE"           , ccio::dalton_dal_entry::job_type::optimize},
    { ".RUN ALL"            , ccio::dalton_dal_entry::job_type::run_all},
    { ".RUN PROPERTIES"     , ccio::dalton_dal_entry::job_type::run_properties},
    { ".RUN RESPONSE"       , ccio::dalton_dal_entry::job_type::run_response},
    { ".RUN WAVE FUNCTIONS" , ccio::dalton_dal_entry::job_type::run_wave_functions},
    { ".WALK"               , ccio::dalton_dal_entry::job_type::walk}
};

// .SCF is synonym for .HF but it is not mentioned in Dalton Program Manual.
const std::map<std::string, ccio::method_type> ccio::dalton_dal_entry::string_to_method_type = {
    { ".HF"     , ccio::method_type::scf},
    { ".SCF"    , ccio::method_type::scf},
    { ".MP2"    , ccio::method_type::mp2},
    { ".CI"     , ccio::method_type::ci},
    { ".GASCI"  , ccio::method_type::gasci},
    { ".CC"     , ccio::method_type::cc},
    { ".MCSCF"  , ccio::method_type::mcscf},
    { ".NEVPT2" , ccio::method_type::nevpt2},
    { ".DFT"    , ccio::method_type::scf}
};

const std::map<ccio::dalton_dal_entry::job_type, std::string> ccio::dalton_dal_entry::job_type_to_string = {
    { ccio::dalton_dal_entry::job_type::integrals,          ".INTEGRALS"          },
    { ccio::dalton_dal_entry::job_type::optimize,           ".OPTIMIZE"           },
    { ccio::dalton_dal_entry::job_type::run_all,            ".RUN ALL"            },
    { ccio::dalton_dal_entry::job_type::run_properties,     ".RUN PROPERTIES"     },
    { ccio::dalton_dal_entry::job_type::run_response,       ".RUN RESPONSE"       },
    { ccio::dalton_dal_entry::job_type::run_wave_functions, ".RUN WAVE FUNCTIONS" },
    { ccio::dalton_dal_entry::job_type::walk,               ".WALK"               }
};

const std::map<ccio::dalton_dal_entry::job_type, std::string> ccio::dalton_dal_entry::job_type_to_description = {
    { ccio::dalton_dal_entry::job_type::integrals, "Generating 1- and 2-electron integrals."},
    { ccio::dalton_dal_entry::job_type::optimize, "Geometry optimization."},
    { ccio::dalton_dal_entry::job_type::run_all, "Single point energy + properties (Abacus & Response)"},
    { ccio::dalton_dal_entry::job_type::run_properties, "Single point energy + properties (Abacus)."},
    { ccio::dalton_dal_entry::job_type::run_response, "Single point energy + properties (Response)."},
    { ccio::dalton_dal_entry::job_type::run_wave_functions, "Single point energy."},
    { ccio::dalton_dal_entry::job_type::walk, "Geometry walk."}
};

ccio::dalton_dal_entry::dalton_dal_entry() :
    p(new dalton_dal_entry_private())
{
}

ccio::dalton_dal_entry::~dalton_dal_entry()
{
}

void ccio::dalton_dal_entry::add_module(
    const boost::property_tree::ptree& module)
{
    p->tree.add_child("Dal.Module", module);
}

bool ccio::dalton_dal_entry::has_parametre(const std::string& path, const std::string& name) const
{
    // Parameter name should start with a dot symbol.
    if (!boost::starts_with(name, ".")) {
        throw std::invalid_argument("Wrong parametre name " + name);
    }

    std::vector<std::string> strs;
    boost::split(strs, path, boost::is_any_of("/"));

    // Path should contain not more than 2 parts: module name and possibly submodule name.
    if (strs.size() < 1 || strs.size() > 2) {
        throw std::invalid_argument("Wrong parametre path " + path);
    }

    // Get path's parameters and search through all of them comparing just the first six characteres.
    std::vector<std::string> ps = parametres(path);
    return (std::find_if(ps.begin(), ps.end(), [&name](const auto& p){
        return name.substr(0, 6) == p.substr(0, 6);
    }) != ps.end());
}

std::vector<std::string> ccio::dalton_dal_entry::parametres(const std::string& path) const
{
    std::vector<std::string> v;

    std::vector<std::string> strs;
    boost::split(strs, path, boost::is_any_of("/"));

    // Path should contain not more than 2 parts: module name and (possibly) submodule name.
    if (strs.size() < 1 || strs.size() > 2) {
        throw std::invalid_argument("Wrong parametre path " + path);
    }

    // Search module with name strs[0].
    auto modules = p->tree.get_child("Dal");
    boost::property_tree::ptree::const_iterator module = modules.begin();
    while (module != modules.end()) {
        if (tree_name(module->second).substr(0, 6) == strs.at(0).substr(0, 6))
            break;
        ++module;
    }

    if (module != modules.end()) {
        if (strs.size() == 1) {
            v = get_parametres(module->second);
        } else {
            auto children = module->second;
            boost::property_tree::ptree::const_iterator child = children.begin();
            while (child != children.end()) {
                if (child->first == "Submodule" && tree_name(child->second).substr(0, 6) == strs.at(1).substr(0, 6))
                    break;
                ++child;
            }
            if (child != children.end()) {
                v = get_parametres(child->second);
            }
        }
    }

    return v;
}

ccio::dalton_dal_entry::job_type ccio::dalton_dal_entry::get_job_type() const
{
    auto it = string_to_job_type.cbegin();
    while (it != string_to_job_type.cend() && !has_parametre("**DALTON INPUT", it->first)) {
        it++;
    }

    if (it != string_to_job_type.cend()) {
        return it->second;
    } else {
        throw std::runtime_error("Job type could not be determined.");
    }
}

std::vector<ccio::method_type> ccio::dalton_dal_entry::method_types() const
{
    std::vector<ccio::method_type> types;

    for (const auto& kv : string_to_method_type) {
        if (has_parametre("**WAVE FUNCTIONS", kv.first)) {
            if (kv.first == ".CC" && types.empty()) {
                types.push_back(ccio::method_type::scf);
            }
            types.push_back(kv.second);
        }
    }

    if (types.size() > 0) {
        return types;
    } else {
        throw std::runtime_error("Wave function types could not be determined.");
    }
}

std::vector<std::string> ccio::dalton_dal_entry::method_names() const
{
    throw kemiisto::io::not_implemented_exception("ccio::dalton_dal_entry::method_names()");
}

std::vector<ccio::scf_type> ccio::dalton_dal_entry::scf_types() const
{
    // Default is to switch to QCSCF if DIIS doesn't converge.
    std::vector<ccio::scf_type> v = {
            ccio::scf_type::diis,
            ccio::scf_type::qc
    };

    if (has_parametre("**WAVE FUNCTIONS/*SCF INPUT", ".NODIIS")) {
        v.erase(v.begin());
    }
    if (has_parametre("**WAVE FUNCTIONS/*SCF INPUT", ".NOQCSCF")) {
        v.erase(v.begin() + 1);
    }

    return v;
}

const boost::property_tree::ptree& ccio::dalton_dal_entry::tree() const
{
    return p->tree;
}

std::string tree_name(const boost::property_tree::ptree& tree)
{
    return tree.get<std::string>("<xmlattr>.name");
}

bool find_parametre(const boost::property_tree::ptree& tree, const std::string& name)
{
    for (const auto& child : tree) {
        if (child.first == "Parametre"
                && tree_name(child.second).substr(0, 6) == name.substr(0, 6)) {
            return true;
        }
    }

    return false;
}

std::vector<std::string> get_parametres(const boost::property_tree::ptree& tree)
{
    std::vector<std::string> v;
    for (const auto& child : tree) {
        if (child.first == "Parametre") {
            v.push_back(tree_name(child.second));
        }
    }
    return v;
}
