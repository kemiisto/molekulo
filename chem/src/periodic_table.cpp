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

#include "chem/periodic_table.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <boost/lexical_cast.hpp>

#include "chem/element.h"
#include "chem/nuclide.h"
#include "io/input_file_stream.h"
#include "io/not_found_exception.h"
#include "io/regexes.h"
#include "io/wrong_format_exception.h"

const ccio::periodic_table& ccio::default_periodic_table()
{
    static const ccio::periodic_table table;
    return table;
}

struct ccio::periodic_table::periodic_table_private {
    std::vector<ccio::element> elements;

    periodic_table_private() :
        elements()
    {
    }
};

ccio::periodic_table::periodic_table() :
    p(std::make_unique<periodic_table_private>())
{
    p->elements.push_back(ccio::element(0, "X", "Dummy"));

    kemiisto::io::input_file_stream stream("data/elements.txt");

    if (stream.is_open()) {
        std::string line = stream.read_line();

        while (!stream.done() && line.find("Number  Symbol") == std::string::npos) {
            line = stream.read_line();
        }

        line = stream.read_line();
        if (!stream.done()) {
            while (!stream.done()) {
                static const std::regex regex(
                    kemiisto::io::re_int_g() + kemiisto::io::re_spaces()
                    + kemiisto::io::re_alpha_g() + kemiisto::io::re_spaces()
                    + kemiisto::io::re_alpha_g() + kemiisto::io::re_spaces()
                    + kemiisto::io::re_real_int_g() + kemiisto::io::re_spaces()
                    + kemiisto::io::re_real_g() + kemiisto::io::re_spaces()
                    + kemiisto::io::re_real_g() + kemiisto::io::re_spaces()
                    + kemiisto::io::re_int_g() + kemiisto::io::re_spaces()
                    + kemiisto::io::re_int_g() + kemiisto::io::re_spaces()
                    + kemiisto::io::re_int_g()
                );
                std::smatch smatch;
                line = stream.read_line();

                if (std::regex_search(line, smatch, regex)) {
                    ccio::element element(boost::lexical_cast<unsigned int>(smatch[1]), smatch[2], smatch[3]);
                    element.set_atomic_weight(std::stof(smatch[4]));
                    element.set_van_der_waals_radius(std::stof(smatch[5]));
                    element.set_covalent_radius(std::stof(smatch[6]));
                    // Do not use boost::lexical_cast<unsigned char> here,
                    // it'll throw boost::bad_lexical_cast.
                    // http://www.boost.org/doc/libs/1_60_0/doc/html/boost_lexical_cast/frequently_asked_questions.html
                    element.set_rgb(
                        boost::lexical_cast<int>(smatch[7]),
                        boost::lexical_cast<int>(smatch[8]),
                        boost::lexical_cast<int>(smatch[9])
                    );

                    line = stream.read_line();
                    static const std::regex isotope_regex(
                        kemiisto::io::re_int_g() + kemiisto::io::re_spaces()
                        + kemiisto::io::re_real_g() + kemiisto::io::re_spaces()
                        + kemiisto::io::re_real_g()
                    );
                    std::smatch isotope_smatch;
                    line = stream.read_line();
                    while (std::regex_search(line, isotope_smatch, isotope_regex)) {
                        element.add_isotope(
                            boost::lexical_cast<unsigned int>(isotope_smatch[1]),
                            boost::lexical_cast<float>(isotope_smatch[2]),
                            boost::lexical_cast<float>(isotope_smatch[3])
                        );
                        line = stream.read_line();
                    }

                    p->elements.push_back(element);
                } else {
                    throw kemiisto::io::wrong_format_exception("isotope", stream.line_number());
                }
            }
        } else {
            throw kemiisto::io::wrong_format_exception("element", stream.line_number());
        }

        stream.close();
    } else {
        throw std::runtime_error("File data/elements.txt not found.");
    }
}

ccio::periodic_table::~periodic_table()
{
}

std::size_t ccio::periodic_table::number_of_elements() const
{
    return p->elements.size();
}

const ccio::element& ccio::periodic_table::element(unsigned int atomic_number) const
{
    return p->elements[atomic_number];
}

const ccio::element& ccio::periodic_table::element(
    const std::string& symbol) const
{
    auto result = std::find_if(
        p->elements.cbegin(), p->elements.cend(),
        [&symbol](const ccio::element& e) -> bool { return e.symbol() == symbol; }
    );
    if (result != p->elements.cend()) {
        return *result;
    } else {
        throw std::logic_error("Element not found for symbol " + symbol);
    }
}
