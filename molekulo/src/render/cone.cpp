/**********************************************************************
        Copyright (C) 2014,2015 Anton Simakov

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

#include "render/cone.h"

#include <cmath>
#include <Eigen/Geometry>

#include "render/gl.h"
#include "render/glu.h"

struct molekulo::Cone::ConePrivate
{
    GLUquadricObj* gluQuadric;
    GLuint displayList;

    void initialize(int detail);

    ConePrivate() : 
        gluQuadric(gluNewQuadric()),
        displayList(0)
    {
        gluQuadricDrawStyle(gluQuadric, GLU_FILL);
        gluQuadricNormals(gluQuadric, GLU_SMOOTH);
    }
};

void molekulo::Cone::ConePrivate::initialize(int faces)
{
    // compile display list
    if (!displayList) displayList = glGenLists(1);
    if (!displayList) return;

    if (faces < 3) {
        // Draw 2 trinagles
        glNewList(displayList, GL_COMPILE);
        glLineWidth(1.0);
        glBegin(GL_TRIANGLES);
        glVertex3f(-0.5f,  0.0f,  0.0f);
        glVertex3f( 0.0f,  0.0f,  1.0f);
        glVertex3f( 0.5f,  0.0f,  0.0f);
        glVertex3f( 0.0f, -0.5f,  0.0f);
        glVertex3f( 0.0f,  0.0f,  1.0f);
        glVertex3f( 0.0f,  0.5f,  0.0f);
        glEnd();
        glEndList();
    } else {
        glNewList(displayList, GL_COMPILE);
        // First draw the lateral surface.
        gluQuadricOrientation(gluQuadric, GLU_OUTSIDE);
        gluCylinder(gluQuadric, 1.0f, 0.0f, 1.0f, faces, 1);
        // Next draw the cone base.
        gluQuadricOrientation(gluQuadric, GLU_INSIDE);
        gluDisk(gluQuadric, 0.0, 1.0f, faces, 1);
        glEndList();
    }
}

molekulo::Cone::Cone(int faces):
    p(new ConePrivate)
{
    assert(faces >= 0);
    p->initialize(faces);
}

molekulo::Cone::~Cone()
{
    if (p->displayList)
        glDeleteLists(p->displayList, 1);
    if (p->gluQuadric)
        gluDeleteQuadric(p->gluQuadric);
}

void molekulo::Cone::draw(const Eigen::Vector3f& vertex1, const Eigen::Vector3f& vertex2, 
        float radius) const
{
    // construct the 4D transformation matrix
    Eigen::Matrix4f matrix;
    matrix.row(3) << 0, 0, 0, 1;
    matrix.block<3,1>(0,2) = vertex2 - vertex1; // the axis

    // construct an orthogonal basis whose first vector is the axis, and whose other vectors
    // have norm equal to 'radius'.
    Eigen::Vector3f axisNormalized = matrix.block<3,1>(0,2).normalized();
    matrix.block<3,1>(0,0) = axisNormalized.unitOrthogonal() * radius;
    matrix.block<3,1>(0,1) = axisNormalized.cross(matrix.block<3,1>(0,0));
    matrix.block<3,1>(0,3) = vertex1;

    glPushMatrix();
    glMultMatrixf(matrix.data());
    glCallList(p->displayList);
    glPopMatrix();
}