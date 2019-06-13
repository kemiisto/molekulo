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

#ifndef COLOR_H
#define COLOR_H

#include <memory>

namespace molekulo
{
    /**
     * @class Color Color.h "Molekulo/Color.h"
     * @brief Represents 4-component (r, g, b, a) color.
     * @version 0.1
     */
    class Color
    {
    public:
        /**
         * Default constructor.
         * Create instance with r, g, b channels equals 0 and and alpha channel equals one.
         */
        Color();
        ~Color();

        Color(float r, float g, float b, float a);
        Color(const Color& color);

        Color& operator=(const Color& color);

        float r() const;
        float g() const;
        float b() const;
        float a() const;

        // Return one of the predefined colors
        static const Color& blue();
        static const Color& green();
        static const Color& red();
        static const Color& white();
        static const Color& yellow();
        static const Color& selection();

        /**
         * Applies nice OpenGL materials using this color as the
         * diffuse color while using different shades for the ambient and
         * specular colors. This is only useful if lighting is enabled.
         */
        void applyAsMaterials();


    private:
        struct ColorPrivate;
        std::unique_ptr<ColorPrivate> d;
    };
}

#endif // COLOR_H
