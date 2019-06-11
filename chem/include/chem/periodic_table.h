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

#ifndef PERIODIC_TABLE_H
#define PERIODIC_TABLE_H

#include <memory>

namespace ccio
{
    class element;

    class periodic_table final
    {
    public:
        periodic_table();
        ~periodic_table();

        std::size_t number_of_elements() const;
        const ccio::element& element(unsigned int atomic_number) const;
        const ccio::element& element(const std::string& symbol) const;

    private:
        struct periodic_table_private;
        std::unique_ptr<periodic_table_private> p;
    };

    const ccio::periodic_table& default_periodic_table();
}

#endif /* PERIODIC_TABLE_H */
