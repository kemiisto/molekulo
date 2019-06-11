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

#ifndef OUT_FILE_H
#define OUT_FILE_H

#include <boost/property_tree/ptree_fwd.hpp>

#include "formats/molecule_file.h"

namespace ccio
{
    class out_file : public ccio::molecule_file
    {
    public:
        virtual ~out_file();

        ccio::molecule& molecule() override;
        const ccio::molecule& molecule() const override;

        boost::property_tree::ptree& tree();
        const boost::property_tree::ptree& tree() const;

        void set_program_name(const std::string& program_name);
        void set_program_version(const std::string& program_version);

        std::string program() const;
        std::string version() const;

    protected:
        out_file(const std::string& absolute_file_path);

    private:
        struct out_file_private;
        std::unique_ptr<out_file_private> p;
    };
}

#endif /* OUT_FILE_H */
