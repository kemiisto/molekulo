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

#ifndef KEMIISTO_IO_INPUT_STREAM_H
#define KEMIISTO_IO_INPUT_STREAM_H

#include <memory>
#include <regex>
#include <string>

namespace kemiisto
{
    namespace io
    {
        bool is_all_spaces(const std::string& string);

        struct input_stream_private;
        /**
         * @class InputStream input_stream.h
         * @brief A stream that keeps track of line numbers.
         * @version 0.1
         *
         * Alternative to this implementation would be one in which InputStream is an interface with
         * input_file_stream and input_string_stream being its implementations.
         * The disadvantage of this alternative approach is code duplication: definitions of all methods
         * declared in InputStream interface would be exactly the same in all its implementations.
         */
        class input_stream
        {
        public:
            virtual ~input_stream();

            void set_comment_marks(const std::vector<char>& marks);
            void clear_comment_marks();

            const std::string& read_line(bool skip_comment_lines = true, bool trim = false);

            int line_number() const;
            const std::string& current_line() const;
            const std::string& previous_line() const;

            bool done() const;

            // Reads stream line-by-line to its end and tries to find the string.
            // Returns true if the string was found and false otherwise.
            bool found(const std::string& string);

            // Reads stream line-by-line to its end and tries to find any of the strings.
            // Returns true if some string was found and false otherwise.
            bool found_any_of(const std::vector<std::string>& strings);

            // Reads stream line-by-line to its end and tries to find one of the strings from a vector.
            // Returns iterator of the found string
            // or last when reached the end of stream and found nothing.
            std::vector<std::string>::const_iterator find(
                std::vector<std::string>::const_iterator first,
                std::vector<std::string>::const_iterator last);

            bool search_string_until_another_string(const std::string& string1, const std::string& string2,
                                                const std::string& description1, const std::string& description2);

            input_stream(const input_stream& stream) = delete;
            input_stream& operator=(const input_stream& stream) = delete;

        protected:
            std::unique_ptr<kemiisto::io::input_stream_private> p;
            input_stream(kemiisto::io::input_stream_private* isp);
        };
    }
}

#endif // KEMIISTO_IO_INPUT_STREAM_H
