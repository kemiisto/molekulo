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

#ifndef ELEMENT_H
#define ELEMENT_H

#include <memory>

#include "ielement.h"

namespace ccio
{
    class nuclide;

    class element final : public ielement
    {
        friend class periodic_table;
        
    public:
        element(unsigned int atomic_number, const std::string& chemical_symbol, const std::string& name);
        element(const element& element);
        element& operator=(const element& element);
        ~element();

        unsigned int atomic_number() const override;
        const std::string& symbol() const override;
        const std::string& name() const override;
        double atomic_weight() const override;
        double van_der_waals_radius() const override;
        double covalent_radius() const override;
        const std::vector<unsigned char>& rgb() const override;

        std::size_t number_of_isotopes() const;
        const ccio::nuclide& isotope(std::size_t index) const;
        const ccio::nuclide& isotope_with_mass_number(unsigned int mass_number) const;

    private:
        struct element_private;
        std::unique_ptr<element_private> p;

        void set_atomic_weight(double atomic_weight);
        void set_van_der_waals_radius(double van_der_waals_radius);
        void set_covalent_radius(double covalent_radius);
        void set_rgb(unsigned char r, unsigned char g, unsigned char b);
        void add_isotope(unsigned int mass_number, double exact_mass, double natural_abundance);
    };
}

#endif /* ELEMENT_H */
