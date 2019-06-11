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

#ifndef DALTON_MOL_ENTRY_H
#define DALTON_MOL_ENTRY_H

#include <map>
#include <vector>

#include "chem/molecule.h"

namespace ccio
{
    class dalton_mol_entry final
    {
    public:
        enum class basis_type
        {
            atombasis,
            basis,
            intgrl
        };

        enum class unit_of_length
        {
            bohr,
            angstrom
        };

        enum class gaussians_type
        {
            spherical,
            cartesian,
            own
        };

        static const std::map<std::string, ccio::dalton_mol_entry::basis_type> string_to_basis_type;
        static const std::map<ccio::dalton_mol_entry::basis_type, std::string> basis_type_to_string;
        static const std::map<ccio::dalton_mol_entry::unit_of_length, std::string> unit_of_length_to_string;
        static const std::map<ccio::dalton_mol_entry::gaussians_type, std::string> gaussians_type_to_string;

        dalton_mol_entry();
        ~dalton_mol_entry();

        dalton_mol_entry(const ccio::dalton_mol_entry&) = delete;
        ccio::dalton_mol_entry& operator=(const ccio::dalton_mol_entry&) = delete;

        basis_type get_basis_type() const;
        void set_basis_type(basis_type basis_type);

        const std::string& get_comment() const;
        void set_comment(const std::string& comment);

        unsigned int get_atom_types() const;
        void set_atom_types(unsigned int atom_types);

        std::size_t get_number_of_generators() const;
        const std::vector<std::string>& generators() const;
        void add_generator(const std::string& generator);

        double get_integrals_threshold() const;
        void set_integrals_threshold(double integrals_threshold);

        bool get_nosymmetry() const;
        void set_nosymmetry(bool nosymmetry);

        bool is_addition_of_symmetry_requested() const;

        unit_of_length get_unit_of_length() const;
        void set_unit_of_length(ccio::dalton_mol_entry::unit_of_length unit_of_length);

        gaussians_type get_gaussians_type() const;
        void set_gaussians_type(ccio::dalton_mol_entry::gaussians_type gaussians_type);

        void set_basis_for_atom_type(unsigned int atomic_number, const std::string& basis_set);

        ccio::molecule& get_molecule();
        const ccio::molecule& get_molecule() const;

    private:
        struct dalton_mol_entry_private;
        std::unique_ptr<dalton_mol_entry_private> p;
    };

    std::ostream& operator<<(std::ostream& ostream,
        ccio::dalton_mol_entry::basis_type basis_type);
    std::ostream& operator<<(std::ostream& ostream,
        ccio::dalton_mol_entry::unit_of_length unit_of_length);
    std::ostream& operator<<(std::ostream& ostream,
        ccio::dalton_mol_entry::gaussians_type gaussians_type);
}

#endif // DALTON_MOL_ENTRY_H
