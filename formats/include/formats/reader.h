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

#ifndef READER_H
#define READER_H

#include <memory>

#include "io/input_stream.h"

namespace ccio
{
    class reader
    {
    public:
        reader(kemiisto::io::input_stream& stream);
        virtual ~reader();

        kemiisto::io::input_stream& stream();
        void read();

        reader(const ccio::reader&) = delete;
        ccio::reader& operator=(const ccio::reader&) = delete;

    private:
        struct reader_private;
        std::unique_ptr<reader_private> p;

        virtual void do_read() = 0;
    };
}

#endif // READER_H
