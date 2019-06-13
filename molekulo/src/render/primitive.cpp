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

#include "render/primitive.h"

class molekulo::PrimitivePrivate
{
public:
    PrimitivePrivate() {}
};

molekulo::Primitive::Primitive(QObject* parent) : QObject(parent),
    d(new PrimitivePrivate), m_type(Primitive::OtherType), m_id(FALSE_ID), m_index(FALSE_ID)
{
}

molekulo::Primitive::~Primitive()
{
    delete d;
}
