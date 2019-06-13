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

#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include <map>

#include "chem/molecule.h"
#include "io/input_file_stream.h"

namespace ccio
{
    class text_file
    {
    public:
        enum class type
        {
            dalton_dal_file,
            dalton_mol_file,
            dalton_out_file,
            gaussian_inp_file,
            gaussian_out_file
        };

        virtual ~text_file();

        kemiisto::io::input_file_stream stream;

        static const std::map<ccio::text_file::type, std::string> fileTypeToString;

        static std::unique_ptr<ccio::text_file> new_instance(const std::string &absolute_file_path);

        const std::string& absolute_file_path() const;

        void read();
        virtual void do_read() = 0;

        const std::string& text() const;
//        virtual std::string summary() const = 0;

        std::string directory() const;
        std::string file_name() const;

    protected:
        text_file(const std::string& absolute_file_path);

    private:
        struct text_file_private;
        std::unique_ptr<text_file_private> p;

        text_file(const ccio::text_file&);
        ccio::text_file& operator=(const ccio::text_file&);
    };

    std::ostream& operator<<(std::ostream& ostream, ccio::text_file::type fileType);
}

#endif // TEXT_FILE_H
