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

#ifndef DALTON_SCF_READER_H
#define DALTON_SCF_READER_H

#include <boost/property_tree/ptree_fwd.hpp>

#include "formats/scf_reader.h"

namespace ccio
{
    class dalton_scf_reader final : public ccio::scf_reader
    {
    public:
        dalton_scf_reader(kemiisto::io::input_stream& stream,
                boost::property_tree::ptree& tree, ccio::scf_type scf_type);
        ~dalton_scf_reader();

    private:
        const std::string& start_string() const override;
        const std::vector<std::string>& end_strings() const override;
        
        const std::map<ccio::scf_type, std::string>& cycle_start_string() const override;
        const std::map<ccio::scf_type, std::string>& scf_converged_string() const override;
        const std::map<ccio::scf_type, std::string>& scf_not_converged_string() const override;

        void read_cycle(double& energy) override;
        void read_final_energy(double& energy) override;
    };
}

#endif /* DALTON_SCF_READER_H */
