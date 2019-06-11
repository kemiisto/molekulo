/**********************************************************************
  Copyright (C) 2008-2014 Anton Simakov

  This file is part of Molekulo.
  For more information, see <http://code.google.com/p/qdalton/>

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

#include "formats/dalton/dalton_dal_entry.h"
#include "formats/dalton/dalton_dal_entry_reader.h"
#include "formats/dalton/dalton_dal_file.h"
#include "io/logger.h"

struct ccio::DaltonDalFile::DaltonDalFilePrivate
{
    ccio::dalton_dal_entry dalEntry;

    DaltonDalFilePrivate() :
        dalEntry()
    {}
};

ccio::DaltonDalFile::DaltonDalFile(const std::string& absoluteFilePath) :
    ccio::text_file(absoluteFilePath),
    p(new DaltonDalFilePrivate())
{
}

ccio::DaltonDalFile::~DaltonDalFile()
{
}

void ccio::DaltonDalFile::do_read()
{
    LOG(info) << " as DALTON dal file...\n";

    ccio::dalton_dal_entry_reader reader(stream, p->dalEntry);
    reader.read();

    LOG(debug) << "Done.";
}

const ccio::dalton_dal_entry& ccio::DaltonDalFile::dalEntry() const
{
    return p->dalEntry;
}
