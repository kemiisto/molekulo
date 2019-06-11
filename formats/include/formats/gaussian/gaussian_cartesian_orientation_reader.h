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

#ifndef GAUSSIAN_CARTESIAN_ORIENTATION_READER_H
#define GAUSSIAN_CARTESIAN_ORIENTATION_READER_H

#include "formats/section_reader.h"

namespace ccio
{
    class molecule;

    class gaussian_cartesian_orientation_reader final : public ccio::section_reader
    {
    public:
        gaussian_cartesian_orientation_reader(kemiisto::io::input_stream& stream, 
                boost::property_tree::ptree& tree, ccio::molecule& molecule);
        ~gaussian_cartesian_orientation_reader();

    private:
        struct gaussian_cartesian_orientation_reader_private;
        std::unique_ptr<gaussian_cartesian_orientation_reader_private> p;

        void do_read_section() override;
        const std::string& start_string() const override;
        const std::vector<std::string>& end_strings() const override;
    };
}


#endif // GAUSSIAN_CARTESIAN_ORIENTATION_READER_H
