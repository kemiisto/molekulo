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

#include <iomanip>

#include <boost/algorithm/string.hpp>

#include "formats/dalton/dalton_mol_entry.h"
#include "formats/dalton/dalton_mol_entry_reader.h"
#include "formats/dalton/dalton_mol_file.h"
#include "formats/text_file.h"

#include "chem/reflection.h"
#include "chem/proper_rotation.h"

#include "io/logger.h"
#include "io/regexes.h"
#include "io/not_found_exception.h"
#include "io/not_implemented_exception.h"
#include "io/wrong_format_exception.h"

// Often the BN edit descriptor is used.
// If BN precedes a specification, a nonleading blank in numeric input is considered null, and is ignored.
void remove_spaces(std::string& string);

void ccio::dalton_mol_entry_reader::complete_molecule(
    ccio::molecule& molecule,
    const std::vector<std::string>& generators)
{
    LOG(debug) << "Completing molecule by generators...";

    for (auto generator : generators) {
        LOG(debug) << generator;
        ccio::symmetry_operation* operation;
        if (generator == "X") {
            operation = new ccio::reflection(ccio::reflection::plane::yz);
        } else if (generator == "Y") {
            operation = new ccio::reflection(ccio::reflection::plane::xz);
        } else if (generator == "Z") {
            operation = new ccio::reflection(ccio::reflection::plane::xy);
        } else if (generator == "XY") {
            operation = new ccio::proper_rotation(ccio::proper_rotation::axis::z, 2);
        } else if (generator == "YZ") {
            operation = new ccio::proper_rotation(ccio::proper_rotation::axis::x, 2);
        } else if (generator == "XZ") {
            operation = new ccio::proper_rotation(ccio::proper_rotation::axis::y, 2);
        } else {
            throw kemiisto::io::not_implemented_exception("support for " + generator + " generator");
        }

        if (operation) {
            operation->apply(molecule);
            delete operation;
        }
    }

    LOG(debug) << "Done.";
}

struct ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private
{
    ccio::dalton_mol_entry& mol_entry;

    dalton_mol_entry_reader_private(ccio::dalton_mol_entry& mol_entry) :
        mol_entry(mol_entry)
    {}

    void read_basis_type(kemiisto::io::input_stream& stream);
    void read_comment(kemiisto::io::input_stream& stream);

    void read_general_string(kemiisto::io::input_stream& stream);
    void determine_handling_of_symmetry(const std::string& line);
    void determine_unit_of_length(const std::string& line);
    void determine_type_of_gaussians(const std::string& line);
    void determine_charge(const std::string& line);
    void determine_integrals_threshold(const std::string& line);

    void read_general_string_in_old_format(kemiisto::io::input_stream& stream);

    void read_atoms(kemiisto::io::input_stream& stream);
    void read_atoms_in_old_format(kemiisto::io::input_stream& stream);

    void read_atoms_of_same_type(kemiisto::io::input_stream& stream, unsigned int atomic_number,
        unsigned int count, unsigned int max_angular, bool auxiliary_basis);
    void read_intgrl_basis(kemiisto::io::input_stream& stream, unsigned int max_angular);
};

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::read_basis_type(
        kemiisto::io::input_stream& stream)
{
    LOG(debug) << "Reading basis type...";

    std::string line = stream.read_line();
    boost::algorithm::trim(line);
    boost::algorithm::to_upper(line);

    auto it = ccio::dalton_mol_entry::string_to_basis_type.find(line);
    if (it != ccio::dalton_mol_entry::string_to_basis_type.end()) {
        mol_entry.set_basis_type(it->second);
        LOG(debug) << mol_entry.get_basis_type();
        if (mol_entry.get_basis_type() == ccio::dalton_mol_entry::basis_type::basis) {
            line = stream.read_line();
            LOG(debug) << "Basis type: " << line;
        }
    } else {
        throw kemiisto::io::wrong_format_exception("basis type", stream.line_number());
    }
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::read_comment(kemiisto::io::input_stream& stream)
{
    LOG(debug) << "Reading comment...";
    // Fist line.
    std::string line1 = boost::trim_right_copy(stream.read_line());
    LOG(debug) << line1;
    // Second line.
    std::string line2 = boost::trim_right_copy(stream.read_line());
    LOG(debug) << line2;
    mol_entry.set_comment(line1 + "\n" + line2);
}

/*
 * This line is keyword-driven. The general structure of the input is Keyword=.
 * The input is case sensitive, but Dalton will recognize the keywords whether specified
 * with only three characters (minimum) or the full name (or any intermediate option).
 * The order of the keywords is arbitrary.
 */
void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::read_general_string(kemiisto::io::input_stream& stream)
{
    LOG(debug) << "Reading general instructions...";
    std::string line = stream.read_line();

    LOG(debug) << "Determining number of atom types...";
    static const std::string pattern  = "(Ato|Atom|Atomt|Atomty|Atomtyp|Atomtype|Atomtypes)";
    std::regex regex(pattern + "=\\s*" + kemiisto::io::re_int_g(), std::regex_constants::icase);
    std::smatch match;

    LOG(debug) << "Searching for \"Atomtypes=\"...";
    if (std::regex_search(line, match, regex)) {
        LOG(debug) << "Found.";
        mol_entry.set_atom_types(boost::lexical_cast<unsigned int>(match[2]));
        determine_handling_of_symmetry(line);
        determine_unit_of_length(line);
        determine_type_of_gaussians(line);
        determine_charge(line);
        determine_integrals_threshold(line);
    } else {
        LOG(debug) << "Not found, assuming old input format.";
        read_general_string_in_old_format(stream);
    }
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::determine_handling_of_symmetry(const std::string& line)
{
    LOG(debug) << "Determining symmetry handling...";

    LOG(debug) << "Searching for \"Generators=\"...";
    static const std::string pattern =
        "(Gen|Gene|Gener|Genera|Generat|Generato|Generator|Generators)";
    static const std::regex regex(pattern + "=\\s*([0123])", std::regex_constants::icase);
    std::smatch match;

    if (std::regex_search(line, match, regex)) {
        std::size_t number_of_generators = boost::lexical_cast<std::size_t>(match[2]);
        LOG(debug) << "Found.";
        if (number_of_generators > 0) {
            LOG(debug) << "Reading " << number_of_generators << " generators...";
            // We take a substring starting from the end of the match,
            // i.e. starting right after the number of generators just read.
            // We trim it and then split by spaces.
            // Note that Generators might be followed by other keywords, so only number_of_generators
            // first elements of generators vector are actual generators.
            std::string generators_string = line.substr(
                static_cast<std::size_t>(match.position() + match.length())
            );
            boost::algorithm::trim(generators_string);
            std::vector<std::string> generators;
            boost::algorithm::split(generators, generators_string,
                boost::is_space(), boost::token_compress_on);
            for (std::size_t i = 0; i < number_of_generators; ++i)  {
                mol_entry.add_generator(generators[i]);
                LOG(debug) << "" << generators[i];
            }
            LOG(debug) << "Symmetry: given explicitly.";
        }
    } else {
        LOG(debug) << "Not found, thus searching for \"Nosymmetry\" next...";
        static const std::string nosymmetryPattern =
            "(Nos|Nosy|Nosym|Nosymm|Nosymme|Nosymmet|Nosymmetr|Nosymmetry)";
        static const std::regex nosymmetryRegex(nosymmetryPattern, std::regex_constants::icase);
        if (std::regex_search(line, match, nosymmetryRegex)) {
            LOG(debug) << "Found.";
            LOG(debug) << "Symmetry: not used.";
            mol_entry.set_nosymmetry(true);
        } else {
            LOG(debug) << "Not found.";
            LOG(debug) << "Symmetry: detected automatically.";
        }
    }
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::determine_unit_of_length(const std::string& line)
{
    LOG(debug) << "Determining unit of length...";

    LOG(debug) << "Searching for \"Angstrom\"...";
    static const std::string pattern = "(Ang|Angs|Angst|Angstr|Angstro|Angstrom)";
    static const std::regex regex(pattern, std::regex_constants::icase);
    std::smatch match;

    if (std::regex_search(line, match, regex)) {
        LOG(debug) << "Found.";
        mol_entry.set_unit_of_length(dalton_mol_entry::unit_of_length::angstrom);
    } else {
        LOG(debug) << "Not found.";
        mol_entry.set_unit_of_length(dalton_mol_entry::unit_of_length::bohr);
    }
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::determine_type_of_gaussians(const std::string& line)
{
    LOG(debug) << "Determining Gaussians type...";

    LOG(debug) << "Searching for \"Cartesian\"...";
    static const std::string pattern =
        "(Car|Cart|Carte|Cartes|Cartesi|Cartesia|Cartesian)";
    static const std::regex regex(pattern, std::regex_constants::icase);
    std::smatch match;

    if (std::regex_search(line, match, regex)) {
        LOG(debug) << "Found.";
        mol_entry.set_gaussians_type(dalton_mol_entry::gaussians_type::cartesian);
    } else {
        LOG(debug) << "Not found.";
        mol_entry.set_gaussians_type(dalton_mol_entry::gaussians_type::spherical);
    }
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::determine_charge(const std::string& line)
{
    LOG(debug) << "Determining molecule charge...";

    LOG(debug) << "Searching for \"Charge=\"...";
    static const std::string pattern = "(Cha|Char|Charg|Charge)";
    static const std::regex regex(pattern + "=\\s*" + kemiisto::io::re_int_g(), std::regex_constants::icase);
    std::smatch match;

    if (std::regex_search(line, match, regex)) {
        LOG(debug) << "Found.";
        mol_entry.get_molecule().set_charge(std::stoi(match[2]));
    } else {
        LOG(debug) << "Not found.";
        mol_entry.get_molecule().set_charge(0);
    }
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::determine_integrals_threshold(const std::string& line)
{
    LOG(debug) << "Determining integrals threshold...";

    LOG(debug) << "Searching for \"Integrals=\"...";
    static const std::string pattern  = "(Int|Inte|Integ|Integr|Integra|Integral|Integrals)";
    static const std::regex regex(pattern + "=\\s*" + kemiisto::io::re_real_g(), std::regex_constants::icase);
    std::smatch match;

    if (std::regex_search(line, match, regex)) {
        LOG(debug) << "Found.";
        std::string s = match[2];
        boost::ireplace_all(s, "d", "e");
        mol_entry.set_integrals_threshold(std::stod(s));
    } else {
        LOG(debug) << "Not found.";
        LOG(debug) << "Integrals threshold defaulted to 1.0e-15.";
    }
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::read_general_string_in_old_format(kemiisto::io::input_stream& stream)
{
    // '(BN,A1,I4,I3,A2,10A1,D10.2,6I5)'
    // BN       Blank control
    // A1       Character 1             CRT         'C', 'c', 'X'
    // I4       Integer 4               NONTYP
    // I3       Integer 3               KCHARG1
    // A2       Character 2             SYMTXT
    // 10A1     10 * Character 1        ((KASYM(I,J),I=1,3),J=1,3) + ID3
    // D10.2    Floating-point 10.2     THRS
    // 6I5      6 * Integer 5           ???
    //
    // CRT     - flag for spherical harmonics or "your own scheme"
    // NONTYP  - number of atomic types
    // KCHARG  - Molecular charge
    // SYMTXT  - Symmetry operations read as a text to test if
    //           symmetry is to be added automatically
    // KASYM   - 3x3 character array specifying the basic symmetry operations;
    //           specify axis that are reversed under the operation
    // ID3     - Units: Angstroms or Bohrs
    // THRS    - integral threshold

    LOG(debug) << "Reading general instructions in old format...";

    static const std::map<std::string, std::size_t> loc {
        { "crt"    ,  0 },
        { "nontyp" ,  1 },
        { "kcharg1",  5 },
        { "symtxt" ,  8 },
        { "kasym"  , 10 },
        { "id3"    , 19 },
        { "thrs"   , 20 }
    };

    static const std::map<std::string, std::size_t> len {
        { "crt"    ,  1 },
        { "nontyp" ,  4 },
        { "kcharg1",  3 },
        { "symtxt" ,  2 },
        { "kasym"  ,  9 },
        { "id3"    ,  1 },
        { "thrs"   , 10 }
    };

    std::string line = stream.current_line();

    // CRT
    LOG(debug) << "Determining Gaussians type...";
    char crt = line.at(loc.at("crt"));
    if (crt == 'C' || crt == 'c') {
        mol_entry.set_gaussians_type(dalton_mol_entry::gaussians_type::cartesian);
    } else if (crt == 'X') {
        mol_entry.set_gaussians_type(dalton_mol_entry::gaussians_type::own);
    } else {
        mol_entry.set_gaussians_type(dalton_mol_entry::gaussians_type::spherical);
    }

    // NONTYP
    LOG(debug) << "Determining number of atom types...";
    std::string nontyp = line.substr(loc.at("nontyp"), len.at("nontyp"));
    if (!kemiisto::io::is_all_spaces(nontyp)) {
        boost::algorithm::trim(nontyp);
        try {
            unsigned int atom_types = boost::lexical_cast<unsigned int>(nontyp);
            mol_entry.set_atom_types(atom_types);
        } catch (const boost::bad_lexical_cast& e) {
            throw kemiisto::io::wrong_format_exception("atom types", stream.line_number(), e.what());
        }
    } else {
        LOG(debug) << "Not found.";
        throw kemiisto::io::not_found_exception("atom types");
    }

    // KCHARG1
    LOG(debug) << "Determining molecule charge...";
    std::string kcharg1 = line.substr(loc.at("kcharg1"), len.at("kcharg1"));
    if (!kemiisto::io::is_all_spaces(kcharg1)) {
        try {
            int charge = std::stoi(kcharg1);
            mol_entry.get_molecule().set_charge(charge);
        } catch (const std::invalid_argument& e) {
            throw kemiisto::io::wrong_format_exception("charge", stream.line_number(), e.what());
        }
    } else {
        mol_entry.get_molecule().set_charge(0);
    }

    // SYMTXT + KASYM
    // If SYMTXT is empty or its first character is equal to 'C'or 'D',
    // then automatic symmetry detection is enabled.
    // Otherwise we have to read the number of generators and then
    // either read generators themselves if the number of generators > 0,
    // or set NoSymmetry to zero if the number of generators = 0.
    LOG(debug) << "Determining symmetry handling...";
    std::string symtxt = line.substr(loc.at("symtxt"), len.at("symtxt"));
    if (!kemiisto::io::is_all_spaces(symtxt)) {
        if (line.at(loc.at("symtxt")) == 'D' || line.at(loc.at("symtxt")) == 'C') {
            LOG(debug) << "Symmetry: detected automatically for Dinfh or Cinfv.";
        } else {
            try {
                int number_of_generators = std::stoi(symtxt);
                if (number_of_generators > 0) {
                    LOG(debug) << "Symmetry: given explicitly.";
                    LOG(debug) << "reading " << number_of_generators << " generators...";
                    std::string kasym = line.substr(10,9);
                    boost::algorithm::trim(kasym);
                    std::vector<std::string> generators;
                    boost::algorithm::split(generators, kasym, boost::is_space(),
                        boost::token_compress_on);
                    for (auto g : generators) {
                        mol_entry.add_generator(g);
                        LOG(debug) << "" << g;
                    }
                } else {
                    LOG(debug) << "Symmetry: not used.";
                    mol_entry.set_nosymmetry(true);
                }
            } catch (const std::invalid_argument& e) {
                throw kemiisto::io::wrong_format_exception("symmetry", stream.line_number(), e.what());
            }
        }
    } else {
        LOG(debug) << "Symmetry: detected automatically.";
    }

    // ID3
    LOG(debug) << "Determining unit of length...";
    if (line.at(loc.at("id3")) != ' ') {
        mol_entry.set_unit_of_length(ccio::dalton_mol_entry::unit_of_length::angstrom);
    } else {
        mol_entry.set_unit_of_length(ccio::dalton_mol_entry::unit_of_length::bohr);
    }

    // THRS
    LOG(debug) << "Determining integrals threshold...";
    std::string thrs = line.substr(loc.at("thrs"), len.at("thrs"));
    if (!kemiisto::io::is_all_spaces(thrs)) {
        try {
            boost::ireplace_all(thrs, "d", "e");
            mol_entry.set_integrals_threshold(std::stod(thrs));
        } catch (const std::invalid_argument& e) {
            throw kemiisto::io::wrong_format_exception("threshold", stream.line_number(), e.what());
        }
    } else {
        LOG(debug) << "Integrals threshold defaulted to: 1.0e-15.";
    }
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::read_atoms(
        kemiisto::io::input_stream& stream)
{
    // Strange detail: charge is real number. But is not it always integer?
    LOG(debug) << "Reading atoms...";

    std::string line = stream.read_line();
    if (line.find("ZMAT") != std::string::npos) {
        throw kemiisto::io::not_implemented_exception("support fot Z-matrix input");
    }

    static const std::string atomsPattern  = "(Ato|Atom|Atoms)";
    static const std::string basisPattern  = "(Bas|Basi|Basis)";
    static const std::string blocksPattern = "(Blo|Bloc|Block|Blocks)";
    static const std::string chargePattern = "(Cha|Char|Charg|Charge)";
    static const std::string polPattern    = "Pol";
    static const std::string setPattern    = "Set";

    for (unsigned int a = 0; a < mol_entry.get_atom_types(); ++a) {
        std::regex regex;
        std::smatch match;
        line = stream.current_line();

        unsigned int atomic_number = 0;
        unsigned int count = 0;
        unsigned int max_angular = 0;
        bool auxiliary_basis = false;

        LOG(debug) << "Searching for \"Atoms=\"...";
        regex.assign(atomsPattern + "=\\s*" + kemiisto::io::re_int_g(), std::regex_constants::icase);
        if (std::regex_search(line, match, regex)) {
            LOG(debug) << "Found " << match[2];
            try {
                count = boost::lexical_cast<unsigned int>(match[2]);
            } catch (const std::invalid_argument& e) {
                throw kemiisto::io::wrong_format_exception("Atoms=", stream.line_number(), e.what());
            }
        } else {
            LOG(debug) << "Not found, assuming old input format.";
            read_atoms_in_old_format(stream);
            break;
        }

        LOG(debug) << "Searching for \"Charge=\"...";
        regex.assign(chargePattern + "=\\s*" + kemiisto::io::re_real_int_g(), std::regex_constants::icase);
        if (std::regex_search(line, match, regex)) {
            LOG(debug) << "Found " << match[2];
            try {
                atomic_number = boost::numeric_cast<unsigned int>(boost::lexical_cast<float>(match[2]));
            } catch (const std::invalid_argument& e) {
                throw kemiisto::io::wrong_format_exception("Charge=", stream.line_number(), e.what());
            }
        } else {
            LOG(debug) << "Not found.";
            throw kemiisto::io::not_found_exception("Charge=");
        }

        if (mol_entry.get_basis_type() == ccio::dalton_mol_entry::basis_type::intgrl) {
            LOG(debug) << "Searching for Blocks=...";
            regex.assign(blocksPattern + "=\\s*" + kemiisto::io::re_real_int_g(), std::regex_constants::icase);
            if (std::regex_search(line, match, regex)) {
                LOG(debug) << "Found " << match[2];
                try {
                    max_angular = boost::lexical_cast<unsigned int>(match[2]);
                } catch (const std::invalid_argument& e) {
                    throw kemiisto::io::wrong_format_exception("Blocks=", stream.line_number(), e.what());
                }
            } else {
                LOG(debug) << "Not found.";
                throw kemiisto::io::not_found_exception("Blocks=");
            }
        }

        LOG(debug) << "Searching for \"Set=\"...";
        regex.assign(setPattern + "=\\s*" + kemiisto::io::re_int_g(), std::regex_constants::icase);
        if (std::regex_search(line, match, regex)) {
            LOG(debug) << "Found Set=" << match[2];
            if (match[2] == "2") {
                auxiliary_basis = true;
                LOG(debug) << "Auxiliary basis detected.";
            }
        } else {
            LOG(debug) << "Not found.";
        }

        read_atoms_of_same_type(stream, atomic_number, count, max_angular, auxiliary_basis);
        line = stream.read_line();
    }

    LOG(debug) << mol_entry.get_molecule().number_of_atoms() << " atoms in total.";;
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::read_atoms_in_old_format(
        kemiisto::io::input_stream& stream)
{
    // C***********************************************************************
    // C        Card 6: ATOMIC DATA
    // C         Q     - nuclear charge
    // C         NONT  - number of symmetry independent atoms
    // C         IQM   - maximum angular quantum number (s=1,p=2,d=3 etc.)
    // C         NHTYP - maximum angular quantum number for ALL orbitals
    // C         JCO   - number of AO-blocks for each l-value
    // C***********************************************************************
    // '(BN,I3,F7.0,I5)'        MBSI,Q,NONT(I)  for .R12AUX, see 27.5 Auxiliary basis sets
    // '(BN,F10.0,I5)'          Q,NONT(I)       otherwise
    // if INTGRL
    // '(BN,I3,F7.0,I5,24I5)'   MBSI,Q,NONT(I),IQM(I,1),(JCO(J,I,1), J=1, IQM(I,1)) for .R12AUX
    // '(BN,F10.0,I5,24I5)'     Q,NONT(I),IQM(I,1),(JCO(J,I,1), J=1, IQM(I,1))

    LOG(debug) << "Reading atoms in old format...";

    static const std::map<std::string, int> loc {
        { "mbsi"  ,  0 },
        { "q"     ,  3 },
        { "nont"  , 10 },
        { "iqm"   , 15 },
        { "jco"   , 20 }
    };

    static const std::map<std::string, int> len {
        { "mbsi"  ,  3 },
        { "q"     ,  7 },
        { "nont"  ,  5 },
        { "iqm"   ,  5 },
        { "jco"   , 24 }
    };

    std::string line = stream.current_line();
    for (unsigned int a = 0; a < mol_entry.get_atom_types(); ++a) {
        unsigned int atomic_number = 0;
        unsigned int count = 0;
        unsigned int max_angular = 0;
        unsigned int number_of_ao_blocks = 0;
        bool auxiliary_basis = false;

        if (line.find("MM") != std::string::npos) {
            LOG(warning) << "MM atoms are currently ignored!";
            LOG(debug) << "Reading atoms in old format done.";
            break;
        }

        // MBSI
        std::string mbsi = line.substr(
            static_cast<std::size_t>(loc.at("mbsi")), static_cast<std::size_t>(len.at("mbsi"))
        );
        remove_spaces(mbsi);
        if (mbsi == "2") {
            auxiliary_basis = true;
            LOG(warning) << "Auxiliary basis sets are ignored!";
        }

        // Q
        std::string q = line.substr(
            static_cast<std::size_t>(loc.at("q")), static_cast<std::size_t>(len.at("q"))
        );
        remove_spaces(q);
        if (!q.empty()) {
            try {
                atomic_number = boost::numeric_cast<unsigned int>(boost::lexical_cast<float>(q));
                LOG(debug) << "Atomic number: " << atomic_number;
                if (atomic_number == 0) {
                    auxiliary_basis = true;
                    LOG(warning) << "Auxiliary basis sets are ignored!";
                }
            } catch (const std::invalid_argument& e) {
                throw kemiisto::io::wrong_format_exception("atomic number", stream.line_number(), e.what());
            }
        } else {
            throw kemiisto::io::not_found_exception("atomic number");
        }

        // NONT
        std::string nont = line.substr(
            static_cast<std::size_t>(loc.at("nont")), static_cast<std::size_t>(len.at("nont"))
        );
        remove_spaces(nont);
        if (!nont.empty()) {
            try {
                count = boost::lexical_cast<unsigned int>(nont);
                LOG(debug) << "Number of atoms: " << count;
            } catch (const std::invalid_argument& e) {
                throw kemiisto::io::wrong_format_exception(
                    "number of atoms", stream.line_number(), e.what()
                );
            }
        } else {
            throw kemiisto::io::not_found_exception("number of atoms");
        }

        if (mol_entry.get_basis_type() == ccio::dalton_mol_entry::basis_type::intgrl) {
            // IQM
            std::string iqm = line.substr(
                static_cast<std::size_t>(loc.at("iqm")), static_cast<std::size_t>(len.at("iqm"))
            );
            remove_spaces(iqm);
            if (!iqm.empty()) {
                try {
                    max_angular = boost::lexical_cast<unsigned int>(iqm);
                    LOG(debug) << "Maximum angular quantum number: " << max_angular;
                } catch (const std::invalid_argument& e) {
                    throw kemiisto::io::wrong_format_exception(
                        "maximum angular quantum number", stream.line_number(), e.what()
                    );
                }
                // JCO
                for (unsigned int i = 0; i < max_angular; ++i) {
                    std::string jco = line.substr(
                        static_cast<std::size_t>(loc.at("jco")) + 5 * i, 5
                    );
                    remove_spaces(jco);
                    if (!jco.empty()) {
                        try {
                            unsigned int jqmi = boost::lexical_cast<unsigned int>(jco);
                            number_of_ao_blocks += jqmi;
                        } catch (const std::invalid_argument& e) {
                            throw kemiisto::io::wrong_format_exception(
                                "Number of AO-blocks", stream.line_number(), e.what()
                            );
                        }
                    }
                }
                LOG(debug) << "total number of AO-blocks: " << number_of_ao_blocks;
            } else {
                throw kemiisto::io::not_found_exception("maximum angular quantum number");
            }
        }

        read_atoms_of_same_type(stream, atomic_number, count, number_of_ao_blocks, auxiliary_basis);
        line = stream.read_line();
    }
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::read_atoms_of_same_type(
        kemiisto::io::input_stream& stream, unsigned int atomic_number,
        unsigned int count, unsigned int number_of_ao_blocks, bool auxiliary_basis)
{
    LOG(debug) << "Reading " << count << " atom(s) with atomic number " << std::setw(4) << atomic_number;

    std::regex regex("(\\w{1,4})\\s+"
        + kemiisto::io::re_real_int_g() + "\\s+"
        + kemiisto::io::re_real_int_g() + "\\s+"
        + kemiisto::io::re_real_int_g() + "(\\s+Isotope=" + kemiisto::io::re_int_g() + ")?");
    std::smatch match;

    for (unsigned int j = 0; j < count; ++j) {
        std::string line = stream.read_line();
        int isotope = 0;
        double x, y, z;
        if (std::regex_search(line, match, regex)) {
            try {
                x = std::stof(match[2]);
            } catch (const std::invalid_argument& e) {
                throw kemiisto::io::wrong_format_exception(
                    "x coordinate", stream.line_number(), e.what()
                );
            }

            try {
                y = std::stof(match[3]);
            } catch (const std::invalid_argument& e) {
                throw kemiisto::io::wrong_format_exception(
                    "y coordinate", stream.line_number(), e.what()
                );
            }

            try {
                z = std::stof(match[4]);
            } catch (const std::invalid_argument& e) {
                throw kemiisto::io::wrong_format_exception(
                    "z coordinate", stream.line_number(), e.what()
                );
            }

            if (mol_entry.get_unit_of_length() == dalton_mol_entry::unit_of_length::bohr) {
                x = x * bohrs_to_angstroms;
                y = y * bohrs_to_angstroms;
                z = z * bohrs_to_angstroms;
            }

            if (!match[5].str().empty()) {
                try {
                    isotope = std::stoi(match[6]);
                } catch (const std::invalid_argument& e) {
                    throw kemiisto::io::wrong_format_exception(
                        "isotope", stream.line_number(), e.what()
                    );
                }
            }

            std::stringstream s;
            s << std::setw(14) << std::fixed << std::setprecision(8) << x << "    " << y << "    " << z;
            // FIX! ISOTOPE!
            (void)isotope;
            if (!auxiliary_basis) {
                LOG(debug) << "" << s.str();
                mol_entry.get_molecule().create_atom(atomic_number, Eigen::Vector3d(x, y, z));
            } else {
                LOG(debug) << "Auxiliary basis set.";
            }
        }
    }

    if (mol_entry.get_basis_type() == ccio::dalton_mol_entry::basis_type::intgrl) {
        read_intgrl_basis(stream, number_of_ao_blocks);
    }
}

void ccio::dalton_mol_entry_reader::dalton_mol_entry_reader_private::read_intgrl_basis(
    kemiisto::io::input_stream& stream, unsigned int number_of_ao_blocks)
{
    LOG(debug) << "reading INTGRL basis...";

    static const std::regex regex(kemiisto::io::re_real_g());
    std::smatch smatch;

    // for now we just skip through INTGRL basis
    for (unsigned int l = 0; l < number_of_ao_blocks; ++l) {
        // FRMT, NPRIM, NCONT, NOINT (A1,I4,2I5)
        std::string line = stream.read_line();

        bool freeFormat = false;
        int numberOfColumns = 0;
        int numberOfPrimitiveGaussians = 0;
        int numberOfContractedGaussians = 0;


        std::string frmt = line.substr(0, 1);
        if (frmt == "F" || frmt == "f") {
            freeFormat = true;
        } else if (frmt == "H" || frmt == "h") {
            numberOfColumns = 4;
        } else {
            numberOfColumns = 8;
        }

        std::string nprim = line.substr(1, 4);
        std::string ncont = line.substr(5, 5);
        if (!kemiisto::io::is_all_spaces(nprim) && !kemiisto::io::is_all_spaces(ncont)) {
            try {
                numberOfPrimitiveGaussians = std::stoi(nprim);
                numberOfContractedGaussians = std::stoi(ncont);
                LOG(debug) << "number of primitive Gaussians in the block: " << nprim;
                LOG(debug) << "number of contracted Gaussians in the block: " << ncont;
                for (int pg = 0; pg < numberOfPrimitiveGaussians; ++pg) {
                    if (freeFormat) {
                        line = stream.read_line();
                    } else {
                        // we have to read numberOfContractedGaussians + 1 reals
                        // by numberOfColumns on each line
                        int numberOfLines = static_cast<int>(
                            ceil(static_cast<float>(numberOfContractedGaussians + 1) / numberOfColumns)
                        );
                        // numberOfContractedGaussians might be zero, but we need to read one line anyway
                        if (numberOfLines == 0) {
                            numberOfLines++;
                        }
                        for (int i = 0; i < numberOfLines; ++i) {
                            line = stream.read_line();
                        }
                    }
                }
            } catch (const std::invalid_argument& e) {
                throw kemiisto::io::wrong_format_exception(
                    "number of Gaussians in the block", stream.line_number(), e.what()
                );
            }
        } else {
            throw kemiisto::io::not_found_exception("number of Gaussians in the block");
        }
    }
}

ccio::dalton_mol_entry_reader::dalton_mol_entry_reader(
        kemiisto::io::input_stream& stream,
        ccio::dalton_mol_entry& mol_entry) :
    reader(stream),
    p(std::unique_ptr<dalton_mol_entry_reader_private>(new dalton_mol_entry_reader_private(mol_entry)))
{
}

ccio::dalton_mol_entry_reader::~dalton_mol_entry_reader()
{
}

void ccio::dalton_mol_entry_reader::do_read()
{
    // Before reading we set the comment marks.
    stream().set_comment_marks(std::vector<char> {'!', '#'});

    p->read_basis_type(stream());
    p->read_comment(stream());
    p->read_general_string(stream());
    p->read_atoms(stream());

    // Clear the comment marks.
    stream().clear_comment_marks();
}

void remove_spaces(std::string& string)
{
    string.erase(std::remove(string.begin(), string.end(), ' '), string.end());
}
