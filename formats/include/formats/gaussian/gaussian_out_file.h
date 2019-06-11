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

#ifndef GAUSSIAN_OUT_FILE_H
#define GAUSSIAN_OUT_FILE_H

#include "formats/out_file.h"

namespace ccio
{
    class gaussian_out_file : public ccio::out_file
    {
    public:
        gaussian_out_file(const std::string& absoluteFilePath);

        void do_read() override;
        void load_job(int index);

    private:
        gaussian_out_file(const ccio::gaussian_out_file&);
        gaussian_out_file& operator=(const ccio::gaussian_out_file&);

        void find_gaussian_version();
        void find_jobs();

        void read_job(ccio::gaussian_out_file* outFile, const std::string& routeSection,
            boost::property_tree::ptree& job_tree);
    };
}
#endif // GAUSSIAN_OUT_FILE_H
