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

#ifndef JOB_SP_READER_H
#define JOB_SP_READER_H

#include "formats/constants.h"
#include "formats/job_reader.h"
#include "formats/mp2_reader.h"
#include "formats/scf_reader.h"

namespace ccio
{
    class job_sp_reader : public job_reader
    {
    public:
        job_sp_reader(
                kemiisto::io::input_stream& stream,
                boost::property_tree::ptree& root,
                ccio::molecule& molecule);
        ~job_sp_reader();

    private:
        struct job_sp_reader_private;
        std::unique_ptr<job_sp_reader_private> p;

        void do_read_section() override final;

        virtual std::vector<ccio::method_type> method_types() const = 0;
//        virtual std::string method_names() const = 0;
        virtual std::vector<ccio::scf_type> scf_types() const = 0;

        virtual std::unique_ptr<ccio::scf_reader> get_scf_reader(
                boost::property_tree::ptree& tree, ccio::scf_type scf_type) = 0;
        virtual std::unique_ptr<ccio::mp2_reader> get_mp2_reader(
                boost::property_tree::ptree& tree) = 0;
    };
}

#endif /* JOB_SP_READER_H */
