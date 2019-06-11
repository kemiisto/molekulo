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

#include "io/input_file_stream.h"

#include "input_file_stream_p.h"

kemiisto::io::input_file_stream::input_file_stream(const std::string& absoluteFileName) :
    input_stream(new kemiisto::io::input_file_stream_private(absoluteFileName))
{
}

kemiisto::io::input_file_stream::~input_file_stream()
{
}

bool kemiisto::io::input_file_stream::is_open() const
{
    return dynamic_cast<std::ifstream&>(p->istream()).is_open();
}

void kemiisto::io::input_file_stream::close()
{
    dynamic_cast<std::ifstream&>(p->istream()).close();
}
