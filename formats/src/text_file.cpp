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

#include "formats/molecule_file.h"

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <fstream>

#include "formats/dalton/dalton_dal_file.h"
#include "formats/dalton/dalton_mol_file.h"
#include "formats/dalton/dalton_out_file.h"
#include "formats/gaussian/gaussian_out_file.h"
#include "io/logger.h"

const std::map<ccio::text_file::type, std::string> ccio::text_file::fileTypeToString = {
    { ccio::text_file::type::dalton_dal_file,   "DALTON DALTON.INP input file"   },
    { ccio::text_file::type::dalton_mol_file,   "DALTON MOLECULE.INP input file" },
    { ccio::text_file::type::dalton_out_file,   "DALTON output file"             },
    { ccio::text_file::type::gaussian_inp_file, "Gaussian input file"            },
    { ccio::text_file::type::gaussian_out_file, "Gaussian output file"           },
};

std::ostream& ccio::operator<<(std::ostream& ostream, ccio::text_file::type fileType)
{
    auto it = ccio::text_file::fileTypeToString.find(fileType);
    if (it != ccio::text_file::fileTypeToString.end()) {
        ostream << it->second;
    } else {
        throw std::logic_error("Unknown file type.");
    }
    return ostream;
}

std::vector<std::string> words(ccio::text_file::type type);
int number_of_occurrences(const std::vector<std::string>& words, const std::string& line);
ccio::text_file::type file_type(const std::string& absolute_file_path);

std::unique_ptr<ccio::text_file> ccio::text_file::new_instance(const std::string &absolute_file_path)
{
    LOG(info) << "Opening " << absolute_file_path << "...";

    std::unique_ptr<ccio::text_file> chem_file;

    switch (file_type(absolute_file_path)) {
    case ccio::text_file::type::dalton_dal_file:
        chem_file = std::unique_ptr<ccio::text_file>(new ccio::DaltonDalFile(absolute_file_path));
        break;
    case ccio::text_file::type::dalton_mol_file:
        chem_file = std::unique_ptr<ccio::text_file>(new ccio::DaltonMolFile(absolute_file_path));
        break;
    case ccio::text_file::type::dalton_out_file:
        chem_file = std::unique_ptr<ccio::text_file>(new ccio::DaltonOutFile(absolute_file_path));
        break;
    case ccio::text_file::type::gaussian_inp_file:
        throw std::runtime_error("Gaussian input files are not supported yet.");
        // break;
    case ccio::text_file::type::gaussian_out_file:
        chem_file = std::unique_ptr<ccio::text_file>(new ccio::gaussian_out_file(absolute_file_path));
        break;
    }

    return chem_file;
}

struct ccio::text_file::text_file_private
{
    std::string absolute_file_path;
    std::string text;

    text_file_private(const std::string& absolute_file_path) :
        absolute_file_path(absolute_file_path),
        text()
    {}
};

ccio::text_file::text_file(const std::string& absolute_file_path) :
    stream(absolute_file_path),
    p(new text_file_private(absolute_file_path))
{
}

ccio::text_file::~text_file()
{
}

void ccio::text_file::read()
{
    LOG(info) << "Reading " << absolute_file_path() << "...";;

//    kemiisto::io::input_file_stream in(absolute_file_path_);
    if (stream.is_open()) {
        do_read();
        stream.close();
        LOG(info) << "Read successfully.\n\n";
    } else {
        throw std::runtime_error("Can not open file.");
    }
}

const std::string& ccio::text_file::text() const
{
    return p->text;
}

std::string ccio::text_file::directory() const
{
    return boost::filesystem::path(p->absolute_file_path).parent_path().string();
}

std::string ccio::text_file::file_name() const
{
    return boost::filesystem::path(p->absolute_file_path).filename().string();
}

const std::string& ccio::text_file::absolute_file_path() const
{
    return p->absolute_file_path;
}

std::vector<std::string> words(ccio::text_file::type type)
{
    std::vector<std::string> list;

    switch (type) {
    case ccio::text_file::type::dalton_dal_file:
        list = { "*dalton", "*wave", "*end", ".run"};
        break;
    case ccio::text_file::type::dalton_mol_file:
        list = { "basis", "intgrl", "atomtypes", "atoms", "charge" };
        break;
    case ccio::text_file::type::dalton_out_file:
        list = { "dalton", "oslo", "norway", "arhus", "denmark" };
        break;
    case ccio::text_file::type::gaussian_inp_file:
        list = { "%", "#n", "#p", "#t" };
        break;
    case ccio::text_file::type::gaussian_out_file:
        list = { "gaussian(r)", "gaussian, inc." };
        break;
    }

    return list;
}

int number_of_occurrences(const std::vector<std::string>& words, const std::string& line)
{
    int n = 0;
    for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it) {
        std::string sub = *it;
        std::string::size_type start = 0;
        while ((start = line.find(sub, start)) != std::string::npos) {
            ++n;
            start += sub.length();
        }
    }
    return n;
}

ccio::text_file::type file_type(const std::string& absolute_file_path)
{
    LOG(info) << "Determining file type...";

    ccio::text_file::type type = ccio::text_file::type::dalton_dal_file;

    // To determine file type we read first 15 lines
    std::ifstream in(absolute_file_path);
    if (in.is_open()) {
        std::string lines;
        std::string line;
        for (int i = 0; i < 15; ++i) {
            std::getline(in, line);
            boost::algorithm::to_lower(line);
            lines.append(line);
        }
        in.close();

        std::map<ccio::text_file::type, int> occurrences;
        occurrences[ccio::text_file::type::dalton_dal_file] =
            number_of_occurrences(words(ccio::text_file::type::dalton_dal_file), lines);
        occurrences[ccio::text_file::type::dalton_mol_file] =
            number_of_occurrences(words(ccio::text_file::type::dalton_mol_file), lines);
        occurrences[ccio::text_file::type::dalton_out_file] =
            number_of_occurrences(words(ccio::text_file::type::dalton_out_file), lines);
        occurrences[ccio::text_file::type::gaussian_inp_file] =
            number_of_occurrences(words(ccio::text_file::type::gaussian_inp_file), lines);
        occurrences[ccio::text_file::type::gaussian_out_file] =
            number_of_occurrences(words(ccio::text_file::type::gaussian_out_file), lines);

        int max_occurrences = 0;
        int total_occurrences = 0;
        // find maximum
        for (auto it = occurrences.begin(); it != occurrences.end(); ++it) {
            ccio::text_file::type key = it->first;
            int value = it->second;
            LOG(debug) << key << ": " << value;
            total_occurrences += value;
            if (max_occurrences < value) {
                max_occurrences = value;
                type = key;
            }
        }

        if (total_occurrences > 0) {
            LOG(info) << type << " with confidency "
                    << 100 * max_occurrences / total_occurrences << "%.\n";
        } else {
            throw std::runtime_error("Unsupported file type.");
        }
    } else {
        throw std::runtime_error("Unable to open file.");
    }

    return type;
}
