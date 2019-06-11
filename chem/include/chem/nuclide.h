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

#ifndef NUCLIDE_H
#define NUCLIDE_H

#include <memory>

#include "inuclide.h"

namespace ccio
{
    class nuclide : public ccio::inuclide
    {
    public:
        nuclide(unsigned int atomic_number, unsigned int mass_number, 
            double exact_mass, double natural_abundance);
        nuclide(const ccio::nuclide& nuclide);
        nuclide& operator=(const ccio::nuclide& nuclide);
        ~nuclide();

        unsigned int mass_number() const override;
        double exact_mass() const override;
        double natural_abundance() const override;

    private:
        struct nuclide_private;
        std::unique_ptr<nuclide_private> p;
    };
}

#endif /* NUCLIDE_H */
