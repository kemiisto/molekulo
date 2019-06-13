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

#ifndef GLPAINTER_H
#define GLPAINTER_H

#include <memory>

#include <Eigen/Core>
#include <QString>

#include "render/color.h"

namespace molekulo
{
    class Viewer;
    class PainterPrivate;

    class Painter
    {
        friend class Viewer;

    public:
        /**
         * Constructor.
         * @param quality defaults to -1, valid range from 0 to 4.
         */
        Painter(Viewer &viewer, int quality=-1);
        ~Painter();

        /**
         * Sets the global quality setting. This influences the detail level of the
         * geometric objects (spheres and cylinders). Values range from 0 to
         * PAINTER_GLOBAL_QUALITY_SETTINGS-1.
         */
        void setQuality(int quality);

        /**
         * @return the current global quality setting.
         */
        int quality() const;

        /**
         * Set the color to paint the OpenGL primitives with.
         * @param color the color to be used for painting.
         */
        void setColor(const molekulo::Color& color);

        /**
         * Set to true to turn dynamic object scaling on, false for off.
         */
        void setDynamicScaling(bool scaling);

        /**
         * Draws a sphere, leaving the Painter choose the appropriate detail level based on the
         * apparent radius (ratio of radius over distance) and the global quality setting.
         * @param center the position of the center of the sphere.
         * @param radius the radius of the sphere.
         */
        void drawSphere(const Eigen::Vector3f& center, float radius);

        /**
         * Draws a cylinder, leaving the Painter choose the appropriate detail level based on the
         * apparent radius (ratio of radius over distance) and the global quality setting.
         * @param end1 the position of the first end of the cylinder.
         * @param end2 the position of the second end of the cylinder.
         * @param radius the radius, i.e. half-width of the cylinder.
         */
        void drawCylinder(const Eigen::Vector3f& end1, const Eigen::Vector3f& end2, float radius);

        /**
         * Draws a multiple cylinder (see below), leaving the Painter choose the appropriate
         * detail level based on the apparent radius (ratio of radius over distance) and the
         * global quality setting.
         *
         * What is a "multiple cylinder"? Think bond of order two or more between two atoms.
         * This function is here to allow drawing multiple bonds in a single call.
         *
         * This function takes care of rendering multiple bonds in such a way that the individual
         * bonds avoid hiding each other, at least in the defaut viewpoint of a molecule.
         * To achieves that, it asks the GLWidget for the the normal vector of the
         * molecule's best-fitting plane.
         *
         * @param end1 the position of the first end of the bond.
         * @param end2 the position of the second end of the bond.
         * @param radius the radius, i.e. half-width of each cylinder.
         * @param order the multiplicity order of the bond, e.g. 2 for a double bond.
         *              When this parameter equals 1, this function is equivalent to
         *              drawCylinder().
         * @param shift how far away from the central axis the cylinders are shifted.
         *              In other words this influences the total width of multiple bonds.
         */
        void drawMultiCylinder(const Eigen::Vector3f& end1, const Eigen::Vector3f& end2,
            float radius, int order, float shift, const Eigen::Vector3f& planeNormalVector);

        void drawCone(const Eigen::Vector3f& vertex1, const Eigen::Vector3f& vertex2, float radius);
        void drawArrow(const Eigen::Vector3f& origin, const Eigen::Vector3f& terminus, float radius);

        void drawText(const Eigen::Vector3f& pos, const QString& string);

    private:
        std::unique_ptr<PainterPrivate> d;

        /**
         * Push the GL name and type, called internally before GL objects are
         * painted on the GLWidget.
         */
        void pushName();

        /**
         * Pop the GL name and type, called internally after GL objects are
         * painted on the GLWidget.
         */
        void popName();

        /**
         * Reset the GL name and type, called internally in popName() and also
         * whenever frustum culling determines that a GL object must not be
         * painted.
         */
        void resetName();
    };
}

#endif // GLPAINTER_H
