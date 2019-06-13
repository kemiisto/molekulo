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

#include "render/color.h"

#include <cmath>

#include "render/gl.h"

struct molekulo::Color::ColorPrivate
{
    float r;
    float g;
    float b;
    float a;

    ColorPrivate(float r, float g, float b, float a) :
        r(r), g(g), b(b), a(a) {}
};

molekulo::Color::Color() :
    d(new ColorPrivate(0.0f, 0.0f, 0.0f, 1.0f))
{
}

molekulo::Color::~Color()
{
}

molekulo::Color::Color(float r, float g, float b, float a) :
    d(new ColorPrivate(r, g, b, a))
{
}

molekulo::Color::Color(const molekulo::Color& color) :
    d(new ColorPrivate(color.d->r, color.d->g, color.d->b, color.d->a))
{
}

molekulo::Color& molekulo::Color::operator=(const molekulo::Color& color)
{
    d->r = color.d->r;
    d->g = color.d->g;
    d->b = color.d->b;
    d->a = color.d->a;
    return *this;
}

float molekulo::Color::r() const
{
    return d->r;
}

float molekulo::Color::g() const
{
    return d->g;
}

float molekulo::Color::b() const
{
    return d->b;
}

float molekulo::Color::a() const
{
    return d->a;
}

const molekulo::Color& molekulo::Color::blue()
{
    static molekulo::Color color(0.0f, 0.0f, 1.0f, 1.0f);
    return color;
}

const molekulo::Color& molekulo::Color::green()
{
    static molekulo::Color color(0.0f, 1.0f, 0.0f, 1.0f);
    return color;
}

const molekulo::Color& molekulo::Color::red()
{
    static molekulo::Color color(1.0f, 0.0f, 0.0f, 1.0f);
    return color;
}

const molekulo::Color& molekulo::Color::white()
{
    static molekulo::Color color(1.0f, 1.0f, 1.0f, 1.0f);
    return color;
}

const molekulo::Color& molekulo::Color::yellow()
{
    static molekulo::Color color(1.0f, 1.0f, 0.0f, 1.0f);
    return color;
}

const molekulo::Color& molekulo::Color::selection()
{
    static molekulo::Color color(0.0f, 1.0f, 1.0f, 1.0f);
    return color;
}

void molekulo::Color::applyAsMaterials()
{
    float ambientColor[] = {d->r / 3, d->g / 3, d->b / 3, d->a};
    float diffuseColor[] = {d->r, d->g, d->b, d->a};

    float s = (0.5f + fabs(d->r - d->g) + fabs(d->b - d->g) + fabs(d->b - d->r)) / 4.0f;
    float t = 1.0f - s;
    float specularColor[] = { s + t * d->r, s + t * d->g, s + t * d->b, d->a };

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
}
