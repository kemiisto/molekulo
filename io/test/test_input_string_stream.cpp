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
#include <boost/test/unit_test.hpp>

#include "io/input_string_stream.h"

BOOST_AUTO_TEST_CASE(test_input_string_stream_read_line)
{
    std::string s = R"(
line0
line1
line2
line3
line4)";

    kemiisto::io::input_string_stream stream(s);
    stream.read_line();

    for (int i = 0; i < 5; ++i) {
        BOOST_CHECK_EQUAL(stream.read_line(), "line" + std::to_string(i));
    }
}

BOOST_AUTO_TEST_CASE(test_input_string_stream_found_any_of)
{
    std::string s = R"(
line0
line1
line2
line3
line4)";
    
    kemiisto::io::input_string_stream stream(s);
    stream.read_line();

    std::vector<std::string> strings = { "line4", "line2" };
    BOOST_CHECK(stream.found_any_of(strings));
}

BOOST_AUTO_TEST_CASE(test_input_string_stream_find)
{
    std::string s = R"(
line0
line1
line2
line3
line4)";

    kemiisto::io::input_string_stream stream(s);
    stream.read_line();

    std::vector<std::string> strings = { "line4", "line2" };
    BOOST_CHECK_EQUAL( *stream.find(strings.cbegin(), strings.cend()), *(strings.cbegin() + 1) );
}
