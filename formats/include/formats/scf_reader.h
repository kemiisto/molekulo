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

#ifndef SCF_READER_H
#define SCF_READER_H

#include <boost/property_tree/ptree_fwd.hpp>
#include <memory>

#include "formats/constants.h"
#include "formats/section_reader.h"

namespace ccio
{
    class scf_reader : public ccio::section_reader
    {
    public:
        scf_reader(kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree,
                ccio::scf_type scf_type);
        virtual ~scf_reader();

    protected:
        ccio::scf_type scf_type() const;

    private:
        struct scf_reader_private;
        std::unique_ptr<scf_reader_private> p;

        void do_read_section() override final;
        bool next_cycle_found();
        bool scf_converged();

        virtual const std::map<ccio::scf_type, std::string>& cycle_start_string() const = 0;
        virtual const std::map<ccio::scf_type, std::string>& scf_converged_string() const = 0;
        virtual const std::map<ccio::scf_type, std::string>& scf_not_converged_string() const = 0;

        virtual void read_cycle(double& energy) = 0;
        virtual void read_final_energy(double& energy) = 0;
    };
}

#endif /* SCF_READER_H */
