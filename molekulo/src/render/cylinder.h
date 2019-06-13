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

#ifndef CYLINDER_H
#define CYLINDER_H

#include <memory>

#include <Eigen/Core>

namespace molekulo
{
    /**
     * @class molekulo::Cylinder cylinder.h "render/cylinder.h"
     * @brief This class represents and draws a cylinder in an OpenGL scene.
     * @version 0.1
     */
    class Cylinder
    {
    public:
        /**
         * Initializes the cylinder with given number of faces.
         */
        Cylinder(int faces = 0);

        ~Cylinder();

        /**
         * Draws the cylinder at specified position, with specified radius.
         * @param end1 the position of the first end of the cylinder.
         * @param end2 the position of the second end of the cylinder.
         * @param radius the radius of the cylinder
         */
        void draw(const Eigen::Vector3f& end1, const Eigen::Vector3f& end2, float radius) const;

        /**
         * Draws the cylinder at specified position, with specified radius.
         * The order and shift arguments allow to render multiple cylinders at once.
         * @param end1 the position of the first end of the cylinder.
         * @param end2 the position of the second end of the cylinder.
         * @param radius the radius of the cylinder.
         * @param order the number of parallel cylinders to draw around the axis (end1 - end2).
         * @param shift the displacement of the axis of the drawn cylinders from the axis (end1 - end2).
         * @param planeNormalVector the unit normal vector of the plane in which we will try to fit the cylinders.
         * This is useful to draw float bonds in a molecule in such a way that they avoid looking like single bonds.
         * To achieve that, just pass the molecule's fitting plane's unit normal vector here.
         */
        void drawMulti(const Eigen::Vector3f& end1, const Eigen::Vector3f& end2,
                       float radius, int order, float shift,
                       const Eigen::Vector3f &planeNormalVector) const;

    private:
        struct CylinderPrivate;
        std::unique_ptr<CylinderPrivate> d;
    };
}

#endif // CYLINDER_H
