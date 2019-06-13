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

#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H

#include <Eigen/Core>
#include <QString>

namespace molekulo
{
    class CharRenderer;
    class Viewer;

    class TextRenderer
    {
    public:
        TextRenderer();
        ~TextRenderer();

        void begin(Viewer *widget);
        void end();

        int draw(const Eigen::Vector3f& pos, const QString& string);
        int draw(int x, int y, const QString& string);

        bool isActive();

    private:
        class TextRendererPrivate;
        TextRendererPrivate * const d;
    };
}

#endif // TEXT_RENDERER_H
