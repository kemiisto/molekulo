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

#include "render/painter.h"

#include <QDebug>

#include "render/cone.h"
#include "render/cylinder.h"
#include "render/primitive.h"
#include "render/sphere.h"
#include "render/text_renderer.h"
#include "render/viewer.h"

float distance(const qglviewer::Camera* camera, const Eigen::Vector3f& v2)
{
    qglviewer::Vec v1 = camera->position();
    return (Eigen::Vector3f(v1.x, v1.y, v1.z) - v2).norm();
}

const int PAINTER_GLOBAL_QUALITY_SETTINGS = 5;
const int DEFAULT_GLOBAL_QUALITY_SETTING  = PAINTER_GLOBAL_QUALITY_SETTINGS - 3;
const int PAINTER_DETAIL_LEVELS           = 10;
// Sphere detail level array. Each row is a detail level.
// The first column is the sphere detail level at the furthest
// point and the last column is the detail level at the closest
// point.
const int PAINTER_SPHERES_LEVELS_ARRAY[5][10] =
{
    {0, 0, 1, 1, 2, 2,  3,  3,  4,  4},
    {0, 1, 2, 3, 4, 4,  5,  5,  6,  6},
    {1, 2, 3, 4, 5, 6,  7,  8,  9,  9},
    {1, 2, 3, 4, 6, 7,  8,  9, 11, 12},
    {2, 3, 4, 5, 7, 9, 12, 15, 18, 22}
};
const float PAINTER_SPHERES_LIMIT_MIN_LEVEL = 0.005f;
const float PAINTER_SPHERES_LIMIT_MAX_LEVEL = 0.15f;

// Cylinder detail level array. Each row is a detail level.
// The first column is the cylinder detail level at the furthest
// point and the last column is the detail level at the closest
// point.
const int PAINTER_CYLINDERS_LEVELS_ARRAY[5][10] =
{
    {0, 3,  5,  5,  8,  8, 12, 12, 16, 16},
    {0, 4,  6,  9, 12, 12, 16, 16, 20, 20},
    {0, 4,  6, 10, 14, 18, 22, 26, 32, 40},
    {0, 4,  6, 12, 16, 20, 24, 28, 34, 42},
    {0, 5, 10, 15, 20, 25, 30, 35, 40, 45}
};
const float PAINTER_CYLINDERS_LIMIT_MIN_LEVEL = 0.001f;
const float PAINTER_CYLINDERS_LIMIT_MAX_LEVEL = 0.03f;

const int PAINTER_MAX_DETAIL_LEVEL = PAINTER_DETAIL_LEVELS - 1;

const float PAINTER_SPHERES_SQRT_LIMIT_MIN_LEVEL = sqrt(PAINTER_SPHERES_LIMIT_MIN_LEVEL);
const float PAINTER_SPHERES_SQRT_LIMIT_MAX_LEVEL = sqrt(PAINTER_SPHERES_LIMIT_MAX_LEVEL);
const float PAINTER_SPHERES_DETAIL_COEFF = static_cast<float>(PAINTER_MAX_DETAIL_LEVEL - 1)
        / (PAINTER_SPHERES_SQRT_LIMIT_MAX_LEVEL - PAINTER_SPHERES_SQRT_LIMIT_MIN_LEVEL);

const float PAINTER_CYLINDERS_SQRT_LIMIT_MIN_LEVEL = sqrt(PAINTER_CYLINDERS_LIMIT_MIN_LEVEL);
const float PAINTER_CYLINDERS_SQRT_LIMIT_MAX_LEVEL = sqrt(PAINTER_CYLINDERS_LIMIT_MAX_LEVEL);
const float   PAINTER_CYLINDERS_DETAIL_COEFF = static_cast<float>(PAINTER_MAX_DETAIL_LEVEL - 1)
        / (PAINTER_CYLINDERS_SQRT_LIMIT_MAX_LEVEL - PAINTER_CYLINDERS_SQRT_LIMIT_MIN_LEVEL);

class molekulo::PainterPrivate
{
public:
    molekulo::Viewer& viewer;

    int newQuality;
    int quality;
    int overflow;

    /** array of pointers to Spheres. You might ask, why not have
      * a plain array of Spheres. The idea is that more than one global detail level
      * may use a given sphere detail level. It is therefore interesting to be able
      * to share that sphere, instead of having redundant spheres in memory.
      */
    Sphere** spheres;
    /** array of pointers to Cylinders. You might ask, why not have
     * a plain array of Cylinders. The idea is that more than one global detail level
     * may use a given cylinder detail level. It is therefore interesting to be able
     * to share that cylinder, instead of having redundant cylinder in memory.
     */
    Cylinder** cylinders;

    Cone** cones;

    TextRenderer textRenderer;

    bool initialized;

    // The primitive type and id of the current object
    Primitive::Type type;
    int id;
    Color color;

    bool dynamicScaling;

    void deleteObjects();
    void createObjects();

    inline bool isValid();

    PainterPrivate(molekulo::Viewer& viewer) :
        viewer(viewer),
        newQuality(-1),
        quality(0),
        overflow(0),
        spheres(0),
        cylinders(0),
        cones(0),
        textRenderer(),
        initialized(false),
        type(Primitive::OtherType),
        id(-1),
        color(),
        dynamicScaling(true) {}

    ~PainterPrivate()
    {
        deleteObjects();
    }
};

inline bool molekulo::PainterPrivate::isValid()
{
    if (!initialized) {
        if (newQuality != -1) {
            quality = newQuality;
        }
        createObjects();
        initialized = true;
    } else if (newQuality != -1) {
        if (newQuality != quality)
        {
            qDebug() << "updateObjects()";
            deleteObjects();
            quality = newQuality;
            createObjects();
        }
        newQuality = -1;
    }
    return true;
}

void molekulo::PainterPrivate::deleteObjects()
{
    int level, lastLevel, n;
    // delete the spheres. One has to be wary that more than one sphere
    // pointer may have the same value. One wants to avoid deleting twice the same sphere.
    if (spheres) {
        lastLevel = -1;
        for (n = 0; n < PAINTER_DETAIL_LEVELS; ++n) {
            level = PAINTER_SPHERES_LEVELS_ARRAY[quality][n];
            if (level != lastLevel) {
                lastLevel = level;
                if (spheres[n]) {
                    delete spheres[n];
                    spheres[n] = 0;
                }
            }
        }
        delete[] spheres;
        spheres = 0;
    }

    // delete the cylinders. One has to be wary that more than one cylinder
    // pointer may have the same value. One wants to avoid deleting twice the same cylinder.
    if (cylinders) {
        lastLevel = -1;
        for (n = 0; n < PAINTER_DETAIL_LEVELS; ++n) {
            level = PAINTER_CYLINDERS_LEVELS_ARRAY[quality][n];
            if (level != lastLevel) {
                lastLevel = level;
                if (cylinders[n]) {
                    delete cylinders[n];
                    cylinders[n] = 0;
                }
            }
        }
        delete[] cylinders;
        cylinders = 0;
    }

    // delete the cones. One has to be wary that more than one cone
    // pointer may have the same value. One wants to avoid deleting twice the same cone.
    if (cones) {
        lastLevel = -1;
        for (n = 0; n < PAINTER_DETAIL_LEVELS; ++n) {
            level = PAINTER_CYLINDERS_LEVELS_ARRAY[quality][n];
            if (level != lastLevel) {
                lastLevel = level;
                if (cones[n]) {
                    delete cones[n];
                    cones[n] = 0;
                }
            }
        }
        delete[] cones;
        cones = 0;
    }
}

void molekulo::PainterPrivate::createObjects()
{
    // create the spheres. More than one sphere detail level may have the same value.
    // in that case we want to reuse the corresponding sphere by just copying the pointer,
    // instead of creating redundant spheres.
    if (spheres == 0) {
        spheres = new Sphere*[PAINTER_DETAIL_LEVELS];
        int level, lastLevel;
        lastLevel = PAINTER_SPHERES_LEVELS_ARRAY[quality][0];
        spheres[0] = new Sphere ( lastLevel );
        for (int n = 1; n < PAINTER_DETAIL_LEVELS; ++n) {
            level = PAINTER_SPHERES_LEVELS_ARRAY[quality][n];
            if (level == lastLevel) {
                spheres[n] = spheres[n-1];
            }
            else {
                lastLevel = level;
                spheres[n] = new Sphere ( level );
            }
        }
    }

    // create the cylinders. More than one cylinder detail level may have the same value.
    // in that case we want to reuse the corresponding cylinder by just copying the pointer,
    // instead of creating redundant cylinders.
    if (cylinders == 0) {
        cylinders = new Cylinder*[PAINTER_DETAIL_LEVELS];
        int level, lastLevel;
        lastLevel = PAINTER_SPHERES_LEVELS_ARRAY[quality][0];
        cylinders[0] = new Cylinder ( lastLevel );
        for (int n = 1; n < PAINTER_DETAIL_LEVELS; ++n) {
            level = PAINTER_CYLINDERS_LEVELS_ARRAY[quality][n];
            if (level == lastLevel) {
                cylinders[n] = cylinders[n-1];
            }
            else {
                lastLevel = level;
                cylinders[n] = new Cylinder ( level );
            }
        }
    }

    // create the cones. More than one cylinder detail level may have the same value.
    // in that case we want to reuse the corresponding cylinder by just copying the pointer,
    // instead of creating redundant cones.
    if (cones == 0) {
        cones = new Cone*[PAINTER_DETAIL_LEVELS];
        int level, lastLevel;
        lastLevel = PAINTER_SPHERES_LEVELS_ARRAY[quality][0];
        cones[0] = new Cone(lastLevel);
        for (int n = 1; n < PAINTER_DETAIL_LEVELS; ++n) {
            level = PAINTER_CYLINDERS_LEVELS_ARRAY[quality][n];
            if (level == lastLevel) {
                cones[n] = cones[n-1];
            }
            else {
                lastLevel = level;
                cones[n] = new Cone(level);
            }
        }
    }
}

molekulo::Painter::Painter(molekulo::Viewer& viewer, int quality) : d(new PainterPrivate(viewer))
{
    if (quality < 0 || quality >= PAINTER_MAX_DETAIL_LEVEL) {
        quality = DEFAULT_GLOBAL_QUALITY_SETTING;
    } else {
        d->quality = quality;
    }
}

molekulo::Painter::~Painter()
{
}

void molekulo::Painter::setQuality(int quality)
{
    assert(quality >= 0 && quality < PAINTER_GLOBAL_QUALITY_SETTINGS);
    d->newQuality = quality;
}

int molekulo::Painter::quality() const
{
    return d->quality;
}

void molekulo::Painter::setColor(const molekulo::Color& color)
{
    d->color = color;
}

void molekulo::Painter::setDynamicScaling(bool scaling)
{
    d->dynamicScaling = scaling;
}

void molekulo::Painter::drawSphere(const Eigen::Vector3f& center, float radius)
{
    if(!d->isValid()) {
        return;
    }

    // Default to the minimum detail level for this quality
    int detailLevel = PAINTER_MAX_DETAIL_LEVEL / 3;

    if (d->viewer.projection() != Viewer::ProjectionOrthographic && d->dynamicScaling) {
        //    double apparentRadius = radius / d->widget->camera()->distance(center);
        double apparentRadius = radius / distance(d->viewer.camera(), center);
        detailLevel = 1 + static_cast<int>(
            floor(PAINTER_SPHERES_DETAIL_COEFF * (sqrt(apparentRadius) - PAINTER_SPHERES_SQRT_LIMIT_MIN_LEVEL)));
        if (detailLevel < 0)
            detailLevel = 0;
        if (detailLevel > PAINTER_MAX_DETAIL_LEVEL)
            detailLevel = PAINTER_MAX_DETAIL_LEVEL;
    }

    d->color.applyAsMaterials();
    pushName();
    d->spheres[detailLevel]->draw(center, radius);
    popName();
}

void molekulo::Painter::drawCylinder(const Eigen::Vector3f& end1, const Eigen::Vector3f& end2, float radius)
{
    if (!d->isValid()) {
        return;
    }

    // Default to the minimum detail level for this quality
    int detailLevel = PAINTER_MAX_DETAIL_LEVEL / 3;

    if (d->viewer.projection() != Viewer::ProjectionOrthographic && d->dynamicScaling) {
        //    double apparentRadius = radius / d->widget->camera()->distance(end1);
        double apparentRadius = radius / distance(d->viewer.camera(), end1);
        detailLevel = 1 + static_cast<int>(
            floor(PAINTER_CYLINDERS_DETAIL_COEFF * (sqrt(apparentRadius) - PAINTER_CYLINDERS_SQRT_LIMIT_MIN_LEVEL)));
        if (detailLevel < 0)
            detailLevel = 0;
        if (detailLevel > PAINTER_MAX_DETAIL_LEVEL)
            detailLevel = PAINTER_MAX_DETAIL_LEVEL;
    }

    d->color.applyAsMaterials();
    pushName();
    d->cylinders[detailLevel]->draw ( end1, end2, radius );
    popName();
}

void molekulo::Painter::drawMultiCylinder(const Eigen::Vector3f& end1, const Eigen::Vector3f& end2,
        float radius, int order, float shift,
        const Eigen::Vector3f& planeNormalVector)
{
    if (!d->isValid()) {
        return;
    }

    // Default to the minimum detail level for this quality
    int detailLevel = PAINTER_MAX_DETAIL_LEVEL / 3;

    if (d->viewer.projection() != Viewer::ProjectionOrthographic && d->dynamicScaling) {
        //    double apparentRadius = radius / d->widget->camera()->distance(end1);
        double apparentRadius = radius / distance(d->viewer.camera(), end1);
        detailLevel = 1 + static_cast<int>(
            floor(PAINTER_CYLINDERS_DETAIL_COEFF * (sqrt(apparentRadius) - PAINTER_CYLINDERS_SQRT_LIMIT_MIN_LEVEL)));
        if (detailLevel < 0)
            detailLevel = 0;
        if (detailLevel > PAINTER_MAX_DETAIL_LEVEL)
            detailLevel = PAINTER_MAX_DETAIL_LEVEL;
    }

    d->color.applyAsMaterials();
    pushName();
    d->cylinders[detailLevel]->drawMulti(end1, end2, radius, order, shift, planeNormalVector);
    popName();
}

void molekulo::Painter::drawCone(const Eigen::Vector3f& vertex1, const Eigen::Vector3f& vertex2,
        float radius)
{
    if(!d->isValid()) {
        return;
    }

    // Default to the minimum detail level for this quality
    int detailLevel = PAINTER_MAX_DETAIL_LEVEL / 3;

    if (d->viewer.projection() != Viewer::ProjectionOrthographic && d->dynamicScaling) {
        //    double apparentRadius = radius / d->widget->camera()->distance(center);
        double apparentRadius = radius / distance(d->viewer.camera(), vertex1);
        detailLevel = 1 + static_cast<int>(
            floor(PAINTER_SPHERES_DETAIL_COEFF * (sqrt(apparentRadius) - PAINTER_SPHERES_SQRT_LIMIT_MIN_LEVEL)));
        if (detailLevel < 0)
            detailLevel = 0;
        if (detailLevel > PAINTER_MAX_DETAIL_LEVEL)
            detailLevel = PAINTER_MAX_DETAIL_LEVEL;
    }

    d->color.applyAsMaterials();
    pushName();
    d->cones[detailLevel]->draw(vertex1, vertex2, radius);
    popName();
}

void molekulo::Painter::drawArrow(const Eigen::Vector3f& origin, const Eigen::Vector3f& terminus,
        float radius)
{
    Eigen::Vector3f point = terminus - origin;
    point = point * (point.norm() - 0.3f) / point.norm();
    point = point + origin;

    drawCylinder(origin, point, radius);
    drawCone(point, terminus, radius * 2.0f);
}

void molekulo::Painter::drawText(const Eigen::Vector3f& pos, const QString& string)
{
    if(!d->isValid()) return;

    d->textRenderer.begin(&d->viewer);
    d->textRenderer.draw(pos, string);
    d->textRenderer.end();
}

void molekulo::Painter::pushName()
{
    // Push the type and id if they are set
    if (d->id != -1) {
        glPushName(d->type);
        glPushName(d->id);
    }
}

void molekulo::Painter::popName()
{
    // Pop the type and id if they are set, then reset them
    if (d->id != -1) {
        glPopName();
        glPopName();
        resetName();
    }
}

void molekulo::Painter::resetName()
{
    d->type = Primitive::OtherType;
    d->id = -1;
}

