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

#include "formats/reader.h"

#include <boost/core/demangle.hpp>

#include "io/logger.h"
#include "io/input_stream.h"

#define BEGIN_READ_FUNC(X) \
    LOG(debug) << "Entering " << boost::core::demangle(typeid(*this).name()) << "::read()"; \
    LOG(debug) << "@line: " << X
#define END_READ_FUNC(X) \
    LOG(debug) << "Exiting " << boost::core::demangle(typeid(*this).name()) << "::read()"; \
    LOG(debug) << "@line: " << X << "\n"

struct ccio::reader::reader_private
{
    kemiisto::io::input_stream& stream;

    reader_private(kemiisto::io::input_stream& stream) :
            stream(stream) {}
};

ccio::reader::reader(kemiisto::io::input_stream& stream) :
        p(new reader_private(stream))
{
}

ccio::reader::~reader()
{
}

kemiisto::io::input_stream& ccio::reader::stream()
{
    return p->stream;
}

void ccio::reader::read()
{
    BEGIN_READ_FUNC(stream().line_number());
    do_read();
    END_READ_FUNC(stream().line_number());
}
