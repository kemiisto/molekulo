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

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "io/input_file_stream.h"

BOOST_AUTO_TEST_CASE(testLineNumber)
{
    kemiisto::io::input_file_stream stream("data/elements.txt");
    if (stream.is_open()) {
        std::string line = stream.read_line();
        BOOST_CHECK(stream.line_number() == 1);
        stream.close();
    } else {
        throw std::runtime_error("File data/elements.txt not found.");
    }
}
