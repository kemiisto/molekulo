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

#ifndef MOLECULE_H
#define MOLECULE_H

#include <memory>

#include <Eigen/Core>

namespace ccio
{
    const double bohrs_to_angstroms = 0.52917720859;

    class atom;
    class bond;

    class molecule final
    {
    public:
        molecule();
        molecule(const ccio::molecule& molecule);

        ~molecule();

        ccio::molecule& operator=(const ccio::molecule& molecule);

        std::size_t number_of_atoms() const;
        std::size_t number_of_bonds() const;

        const ccio::atom& atom(std::size_t index) const;
        const ccio::bond& bond(std::size_t index) const;

        ccio::atom& atom(std::size_t index);
        ccio::bond& bond(std::size_t index);

        void create_atom(unsigned int atomic_number, unsigned int mass_number, const Eigen::Vector3d& centre);
        void create_atom(unsigned int atomic_number, const Eigen::Vector3d& centre);
        void create_atom(const std::string& symbol, const Eigen::Vector3d& centre);

        void create_bond(std::size_t begin_atom_index, std::size_t end_atom_index, int bond_order = 1);

        // void remove_atom(unsigned int index);
        // void remove_bond(unsigned int index);

        int charge() const;
        void set_charge(int charge);

        double interatomic_distance(std::size_t i, std::size_t j);
        void rebond();

        double radius() const;

        bool is_empty() const;
        void clear();

        const Eigen::Vector3d& plane_normal_vector() const;
        void set_plane_normal_vector(const Eigen::Vector3d& vector);

    private:
        struct molecule_private;
        std::unique_ptr<molecule_private> p;
    };
}

#endif /* MOLECULE_H */
