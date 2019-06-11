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

#ifndef BOND_H
#define BOND_H

#include <memory>

#include <Eigen/Core>

namespace ccio
{
    class atom;
    class molecule;
    
    class bond final
    {
        friend class molecule;

    public:
        ~bond();

        const ccio::atom& begin_atom() const;
        const ccio::atom& end_atom() const;

        std::size_t begin_atom_index() const;
        std::size_t end_atom_index() const;

        int bond_order() const;
        void cycle_bond_order();

        Eigen::Vector3d centre() const;
        double length() const;

        bool is_selected() const;
        void toggle_selection();

    private:
        struct bond_private;
        std::unique_ptr<bond_private> p;

        bond(const ccio::molecule& molecule, 
                std::size_t begin_atom_index, std::size_t end_atom_index, int bond_order);
    };
}

#endif /* BOND_H */
