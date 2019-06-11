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

#ifndef DALTON_DAL_ENTRY_H
#define DALTON_DAL_ENTRY_H

#include <boost/property_tree/ptree_fwd.hpp>
#include <map>
#include <memory>
#include <vector>

#include "formats/constants.h"

namespace ccio
{
    class dalton_dal_entry final
    {
    public:
        enum class job_type
        {
            integrals,
            optimize,
            run_all,
            run_properties,
            run_response,
            run_wave_functions,
            walk,
        };

        static const std::map<std::string, ccio::dalton_dal_entry::job_type> string_to_job_type;
        static const std::map<std::string, ccio::method_type> string_to_method_type;
        static const std::map<ccio::dalton_dal_entry::job_type, std::string> job_type_to_string;
        static const std::map<ccio::dalton_dal_entry::job_type, std::string> job_type_to_description;

        dalton_dal_entry();
        ~dalton_dal_entry();

        void add_module(const boost::property_tree::ptree& module);

        /*
         * If path exist returns a vector containing all of its parameter names,
         * otherwise returns an empty vector.
         */
        std::vector<std::string> parametres(const std::string& path) const;
        /*
         * If path exist and has a parameter with the first 6 characteres in its name same as that of name returns true,
         * otherwise returns false.
         */
        bool has_parametre(const std::string& path, const std::string& name) const;


        ccio::dalton_dal_entry::job_type get_job_type() const;
        std::vector<ccio::method_type> method_types() const;
        std::vector<std::string> method_names() const;
        std::vector<ccio::scf_type> scf_types() const;

        const boost::property_tree::ptree& tree() const;

    private:
        struct dalton_dal_entry_private;
        std::unique_ptr<dalton_dal_entry_private> p;
    };
}

//std::ostream& operator<<(std::ostream& stream, const ccio::dalton_dal_entry::job_type& jobType);

#endif /* DALTON_DAL_ENTRY_H */
