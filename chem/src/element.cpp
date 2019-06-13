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

#include "chem/element.h"

#include <algorithm>
#include <string>
#include <vector>

#include "chem/nuclide.h"

struct ccio::element::element_private
{
    unsigned int atomic_number;
    std::string chemical_symbol;
    std::string name;
    double atomic_weight;
    double van_der_waals_radius;
    double covalent_radius;
    std::vector<ccio::nuclide> isotopes;
    std::vector<unsigned char> rgb;

    element_private(unsigned int atomic_number, const std::string& chemical_symbol, 
            const std::string& name) :
        atomic_number(atomic_number),
        chemical_symbol(chemical_symbol),
        name(name),
        atomic_weight(0.0),
        van_der_waals_radius(0.0),
        covalent_radius(0.0),
        isotopes(),
        rgb{0, 0, 0}
    {
    }
};

ccio::element::element(unsigned int atomic_number, const std::string& chemical_symbol,
        const std::string& name) :
    p(std::make_unique<element_private>(atomic_number, chemical_symbol, name))
{
}

ccio::element::element(const ccio::element& element) :
    p(new element_private(*element.p))
{
}

ccio::element& ccio::element::operator=(const ccio::element& element)
{
    p.reset(new ccio::element::element_private(*element.p));
    return *this;
}

ccio::element::~element()
{
}

unsigned int ccio::element::atomic_number() const
{
    return p->atomic_number;
}

const std::string& ccio::element::symbol() const
{
    return p->chemical_symbol;
}

const std::string& ccio::element::name() const
{
    return p->name;
}

double ccio::element::atomic_weight() const
{
    return p->atomic_weight;
}

void ccio::element::set_atomic_weight(double atomic_weight)
{
    p->atomic_weight = atomic_weight;
}

double ccio::element::van_der_waals_radius() const
{
    return p->van_der_waals_radius;
}

double ccio::element::covalent_radius() const
{
    return p->covalent_radius;
}

const std::vector<unsigned char>& ccio::element::rgb() const
{
    return p->rgb;
}

void ccio::element::set_van_der_waals_radius(double van_der_waals_radius)
{
    p->van_der_waals_radius = van_der_waals_radius;
}

void ccio::element::set_covalent_radius(double covalent_radius)
{
    p->covalent_radius = covalent_radius;
}

void ccio::element::set_rgb(unsigned char r, unsigned char g, unsigned char b)
{
    p->rgb[0] = r;
    p->rgb[1] = g;
    p->rgb[2] = b;
}

std::size_t ccio::element::number_of_isotopes() const
{
    return p->isotopes.size();
}

void ccio::element::add_isotope(unsigned int mass_number, double exact_mass, double natural_abundance)
{
    // create isotope
    ccio::nuclide isotope(atomic_number(), mass_number, exact_mass, natural_abundance);
    // find proper position for it in the vector (in descending order by abundance)
    auto it = std::lower_bound(p->isotopes.cbegin(), p->isotopes.cend(), isotope,
            [](const ccio::nuclide& a, const ccio::nuclide& b) -> bool {
                return a.natural_abundance() >= b.natural_abundance();
            }
    );
    // insert it into the right place
    p->isotopes.insert(it, isotope);
}

const ccio::nuclide & ccio::element::isotope(std::size_t index) const
{
    if (index >= number_of_isotopes()) {
        throw std::logic_error("Isotope index " + std::to_string(index) + " is out of range.");
    } else {
        return p->isotopes[index];
    }
}

const ccio::nuclide & ccio::element::isotope_with_mass_number(unsigned int mass_number) const
{
    auto it = std::find_if(p->isotopes.cbegin(), p->isotopes.cend(), [=] (const ccio::nuclide & n) {
        return n.mass_number() == mass_number;
    });
    if (it != p->isotopes.cend()) {
        return *it;
    } else {
        throw std::logic_error("Isotope with mass number " + std::to_string(
            mass_number) + " could not be found.");
    }
}
