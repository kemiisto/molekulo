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

#include "render/cylinder.h"

#include <cmath>

#include <Eigen/Geometry>

#include "render/gl.h"

struct molekulo::Cylinder::CylinderPrivate
{
    GLuint displayList;

    CylinderPrivate() : displayList(0) {}

    void initialize(int faces);
};

void molekulo::Cylinder::CylinderPrivate::initialize(int faces)
{
    // compile display list
    if (!displayList) displayList = glGenLists(1);
    if (!displayList) return;

    if (faces < 3) {
        glNewList(displayList, GL_COMPILE);
        glLineWidth(1.0);
        glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 1);
        glEnd();
        glEndList();
    } else {
        // compute number of vertices
        int vertexCount = 2 * faces + 2;

        Eigen::Vector3f* vertexBuffer = new Eigen::Vector3f[vertexCount];
        Eigen::Vector3f* normalBuffer = new Eigen::Vector3f[vertexCount];

        float baseAngle = 2 * M_PI / faces;
        // build vertex and normal buffers
        for(int i = 0; i <= faces; i++) {
            float angle = baseAngle * i;
            Eigen::Vector3f v(cosf(angle), sinf(angle), 0.0f);
            normalBuffer[2 * i] = v;
            normalBuffer[2 * i + 1] = v;
            vertexBuffer[2 * i] = v;
            vertexBuffer[2 * i + 1] = v;
            vertexBuffer[2 * i].z() = 1.0f;
        }
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glNewList(displayList, GL_COMPILE);
        glVertexPointer(3, GL_FLOAT, 0, vertexBuffer);
        glNormalPointer(GL_FLOAT, 0, normalBuffer);
        glDrawArrays(GL_QUAD_STRIP, 0, vertexCount);
        glEndList();
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);

        delete[] vertexBuffer;
        delete[] normalBuffer;
    }
}

molekulo::Cylinder::Cylinder(int faces) : d(new CylinderPrivate)
{
    assert(faces >= 0);
    d->initialize(faces);
}

molekulo::Cylinder::~Cylinder()
{
    if (d->displayList) {
        glDeleteLists(d->displayList, 1);
    }
}

void molekulo::Cylinder::draw(const Eigen::Vector3f& end1, const Eigen::Vector3f& end2, float radius) const
{
    // construct the 4D transformation matrix
    Eigen::Matrix4f matrix;
    matrix.row(3) << 0.0f, 0.0f, 0.0f, 1.0f;
    matrix.block<3,1>(0,2) = end2 - end1; // the axis

    // construct an orthogonal basis whose first vector is the axis, and whose other vectors
    // have norm equal to 'radius'.
    Eigen::Vector3f axisNormalized = matrix.block<3,1>(0,2).normalized();
    matrix.block<3,1>(0,0) = axisNormalized.unitOrthogonal() * radius;
    matrix.block<3,1>(0,1) = axisNormalized.cross(matrix.block<3,1>(0,0));
    matrix.block<3,1>(0,3) = end1;

    //now we can do the actual drawing !
    glPushMatrix();
    glMultMatrixf(matrix.data());
    glCallList(d->displayList);
    glPopMatrix();
}

void molekulo::Cylinder::drawMulti(const Eigen::Vector3f& end1, const Eigen::Vector3f& end2,
                                   float radius, int order, float shift,
                                   const Eigen::Vector3f& planeNormalVector) const
{
    // construct the 4D transformation matrix
    Eigen::Matrix4f matrix;
    matrix.row(3) << 0.0f, 0.0f, 0.0f, 1.0f;
    matrix.block<3,1>(0,3) = end1;
    matrix.block<3,1>(0,2) = end2 - end1; // the "axis vector" of the line

    // Now we want to construct an orthonormal basis (ortho1) whose third vector is axis.normalized().
    // The first vector in this basis should be approximately lying in the z = 0 plane if possible.
    // This is to ensure float bonds don't look like single bonds from the default point of view.
    Eigen::Vector3f axisNormalized = matrix.block<3,1>(0,2).normalized();
    Eigen::Block<Eigen::Matrix4f, 3, 1> ortho1(matrix, 0.0f, 0.0f);
    ortho1 = axisNormalized.cross(planeNormalVector);
    float ortho1Norm = ortho1.norm();
    if (ortho1Norm > 0.001f) {
        ortho1 = ortho1.normalized() * radius;
    } else {
        ortho1 = axisNormalized.unitOrthogonal() * radius;
    }
    matrix.block<3,1>(0,1) = axisNormalized.cross(ortho1);

    // now the matrix is entirely filled, so we can do the actual drawing!
    glPushMatrix();
    glMultMatrixf(matrix.data());
    if (order == 1) {
        glCallList(d->displayList);
    } else {
        float angleOffset = 0.0;
        if (order >= 3) {
            if (order == 3) {
                angleOffset = 90.0;
            } else {
                angleOffset = 22.5;
            }
        }

        float displacementFactor = shift / radius;
        for(int i = 0; i < order; i++) {
            glPushMatrix();
            glRotatef(angleOffset + 360.0f * i / order, 0.0f, 0.0f, 1.0f);
            glTranslatef(displacementFactor, 0.0f, 0.0f);
            glCallList(d->displayList);
            glPopMatrix();
        }
    }
    glPopMatrix();
}
