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

#ifndef ATOM_H
#define ATOM_H

#include <memory>
#include <Eigen/Core>

namespace ccio
{
    class element;
    class molecule;
    class nuclide;

    /**
     * \brief Atom class.
     *
     * Currently for simplicity instances of Atom class are almost immutable:
     * after an atom is created, only its centre can be changed.
     *
     */
    class atom final
    {
        friend class ccio::molecule;

    public:
        ~atom();

        // int index() const;

        const ccio::element& element() const;
        const ccio::nuclide& isotope() const;

        const Eigen::Vector3d& centre() const;
        void set_centre(const Eigen::Vector3d &centre);

        bool is_selected() const;
        void toggle_selection();

    private:
        struct atom_private;
        std::unique_ptr<atom_private> p;

        atom(const ccio::molecule& molecule,
            unsigned int atomic_number, unsigned int mass_number,
            const Eigen::Vector3d& centre);
    };
}

#endif /* ATOM_H */
