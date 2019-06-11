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

#ifndef SECTION_READER_H
#define SECTION_READER_H

#include <boost/property_tree/ptree_fwd.hpp>
#include <memory>

#include "formats/reader.h"
#include "io/input_stream.h"

namespace ccio
{
    class section_reader : public ccio::reader
    {
    public:
        section_reader(kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree,
            const std::string& name);
        virtual ~section_reader();
        
    protected:
        boost::property_tree::ptree& tree();
        const boost::property_tree::ptree& tree() const;

    private:
        struct section_reader_private;
        std::unique_ptr<section_reader_private> p;
        
        void do_read() override final;
        bool start_found();
        virtual void do_read_section() = 0;
        bool end_found();
        
        virtual const std::string& start_string() const = 0;
        virtual const std::vector<std::string>& end_strings() const = 0;
    };
}

#endif // SECTION_READER_H
