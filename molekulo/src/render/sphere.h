/**********************************************************************
  Copyright (C) 2014,2015 Anton Simakov
  Copyright (C) 2006,2007 Benoit Jacob

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

#ifndef SPHERE_H
#define SPHERE_H

#include <memory>

#include <Eigen/Core>

namespace molekulo
{
    /**
     * @class molekulo::Sphere sphere.h "render/sphere.h"
     * @brief This class represents and draws a sphere in an OpenGL scene.
     * @version 0.1
     *
     * The level of detail can be controlled:
     * at level  = 0, the sphere is an octahedron,
     * at level >= 1, the sphere is a "geosphere".
     * That is, if level >= 1 one starts with an icosahedron and sub-tesselates each face into smaller triangles.
     * level is interpreted as the number of sub-edges into which each edge of the icosahedron must be split.
     * This is a classical tesselation, known to give a very good quality/complexity ratio.
     */
    class Sphere
    {
    public:
        /**
         * @brief Initializes a sphere with given level of detail.
         * @param detail The wanted level of detail.
         */
        Sphere(int detail);

        ~Sphere();

        /**
         * @brief Draws a sphere at specified position and with specified radius
         * @param center Position of the sphere.
         * @param radius Radius of the sphere.
         */
        void draw(const Eigen::Vector3f& center, float radius) const;

    private:
        struct SpherePrivate;
        std::unique_ptr<SpherePrivate> d;
    };
}

#endif // SPHERE_H
