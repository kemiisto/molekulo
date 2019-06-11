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

#include "io/input_stream.h"

#include <fstream>
#include <istream>

#include <boost/algorithm/string/trim.hpp>

#include "io/logger.h"
#include "input_stream_p.h"

bool kemiisto::io::is_all_spaces(const std::string& string)
{
    return string.find_first_not_of(' ') == std::string::npos;
}

std::string condition(std::vector<std::string>::const_iterator first, 
    std::vector<std::string>::const_iterator last);

kemiisto::io::input_stream::input_stream(kemiisto::io::input_stream_private* isp) :
    p(isp)
{
}

kemiisto::io::input_stream::~input_stream()
{
}

void kemiisto::io::input_stream::set_comment_marks(const std::vector<char>& marks)
{
    p->comment_marks = marks;
}

void kemiisto::io::input_stream::clear_comment_marks()
{
    p->comment_marks.clear();
}

const std::string& kemiisto::io::input_stream::read_line(bool skip_comment_lines, bool trim)
{
    bool time_to_stop = false;

    while (!done() && !time_to_stop) {
        for (std::size_t i = 0; i < p->cached_lines_number - 1; ++i) {
            p->cached_lines[i] = p->cached_lines[i + 1];
        }
        std::getline(p->istream(), p->cached_lines.back());
        p->line_number++;

        // If comment lines are not ignored then it is time to stop,
        // otherwise we have to stop only if the current line is not a comment one,
        // i.e. it does not start with one of the comment marks or is empty.
        if (skip_comment_lines && !p->current_line().empty()) {
            auto it = p->comment_marks.cbegin();
            while (it != p->comment_marks.cend() && p->current_line().at(0) != *it) {
                ++it;
            }
            if (it == p->comment_marks.cend()) {
                time_to_stop = true;
            } 
            
        } else {
            time_to_stop = true;
        }
    }

    if (trim) boost::algorithm::trim(p->cached_lines.back());
    return p->cached_lines.back();
}

int kemiisto::io::input_stream::line_number() const
{
    return p->line_number;
}

const std::string& kemiisto::io::input_stream::current_line() const
{
    return p->current_line();
}

const std::string& kemiisto::io::input_stream::previous_line() const
{
    return p->previous_line();
}

bool kemiisto::io::input_stream::done() const
{
    return p->istream().eof();
}

bool kemiisto::io::input_stream::found(const std::string& string)
{
    std::vector<std::string> v = { string };
    return found_any_of(v);
}

bool kemiisto::io::input_stream::found_any_of(const std::vector<std::string>& strings)
{
    LOG(debug) << "Searching for " << condition(strings.cbegin(), strings.cend()) << "...";
    std::string line = current_line();
    while (!done()) {
        for (const auto& s : strings) {
            if (line.find(s) != std::string::npos) {
                LOG(debug) << "\"" + s + "\"" << " found at line " << line_number() << ".";
                return true;
            }
        }
        line = read_line();
    }
    LOG(debug) << "nothing found, reached the end of the stream.";
    return false;
}

std::vector<std::string>::const_iterator kemiisto::io::input_stream::find(
        std::vector<std::string>::const_iterator first,
        std::vector<std::string>::const_iterator last)
{
    LOG(debug) << "Searching for " << condition(first, last) << "...";

    std::string line = current_line();
    while (!done()) {
        // LOG(debug) << line;
        auto it = first;
        while (it != last && line.find(*it) == std::string::npos) {
            ++it;
        }
        if (it != last) {
            LOG(debug) << "\"" + *it + "\"" << " found at line " << line_number() << ".";
            return it;
        }
        line = read_line();
    }
    LOG(debug) << "nothing found, reached the end of the stream.";
    return last;
}

std::string condition(std::vector<std::string>::const_iterator first,
        std::vector<std::string>::const_iterator last)
{
    std::string s;
    // append first element
    if (first != last) {
        s += "\"" + *first + "\"";
        ++first;
    }
    // append the remaining elements
    for (; first != last; ++first) {
        s += " or \"" + *first + "\"";
    }

    return s;
}
