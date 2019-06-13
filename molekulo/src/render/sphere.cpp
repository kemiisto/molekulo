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

#include "render/sphere.h"

#include "render/gl.h"

struct molekulo::Sphere::SpherePrivate
{
    GLuint displayList;

    SpherePrivate() : displayList(0) {}

    void initialize(int detail);

    /**
     * Computes the index (position inside the index buffer) of a vertex given by its position (strip, column, row)
     * inside a certain flat model of the sub-tesselated icosahedron.
     */
    inline unsigned short indexOfVertex(int strip, int column, int row, int detail);

    /**
     * Computes the coordinates of a vertex given by its position (strip, column, row)
     * inside a certain flat model of the sub-tesselated icosahedron.
     */
    void computeVertex(Eigen::Vector3f* vertexBuffer, int strip, int column, int row, int detail);

};

void molekulo::Sphere::SpherePrivate::initialize(int detail)
{
    assert(detail >= 0);

    int vertexCount = 0, indexCount = 0;

    if (detail == 0) {
        displayList = glGenLists( 1 );
        if (!displayList) {
            return;
        }
        float octahedronVertices[6][3] = {
            { 1,  0,  0} ,
            { 0,  1,  0} ,
            { 0,  0,  1} ,
            { 0, -1,  0} ,
            { 0,  0, -1} ,
            {-1,  0,  0}
        };
#define USE_OCTAHEDRON_VERTEX(i) glNormal3fv(octahedronVertices[i]); \
    glVertex3fv(octahedronVertices[i]);
        glNewList(displayList, GL_COMPILE);
        glBegin(GL_TRIANGLE_FAN);
        USE_OCTAHEDRON_VERTEX(0);
        USE_OCTAHEDRON_VERTEX(1);
        USE_OCTAHEDRON_VERTEX(2);
        USE_OCTAHEDRON_VERTEX(3);
        USE_OCTAHEDRON_VERTEX(4);
        USE_OCTAHEDRON_VERTEX(1);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        USE_OCTAHEDRON_VERTEX(5);
        USE_OCTAHEDRON_VERTEX(1);
        USE_OCTAHEDRON_VERTEX(4);
        USE_OCTAHEDRON_VERTEX(3);
        USE_OCTAHEDRON_VERTEX(2);
        USE_OCTAHEDRON_VERTEX(1);
        glEnd();
        glEndList();
        return;
    }

    // compute number of vertices and indices
    vertexCount = (3 * detail + 1) * (5 * detail + 1);
    indexCount = (2 * (2 * detail + 1) + 2) * 5 * detail;

    Eigen::Vector3f* vertexBuffer = new Eigen::Vector3f[vertexCount];
    unsigned short* indexBuffer = new unsigned short[indexCount];

    // build vertex buffer
    for (int strip = 0; strip < 5; strip++) {
        for (int column = 1; column < detail; column++) {
            for (int row = column; row <= 2 * detail + column; row++) {
                computeVertex(vertexBuffer, strip, column, row, detail);
            }
        }
    }

    for (int strip = 1; strip < 5; strip++) {
        for (int row = 0; row <= 3 * detail; row++) {
            computeVertex(vertexBuffer, strip, 0, row, detail);
        }
    }

    for (int row = 0; row <= 2 * detail; row++) {
        computeVertex(vertexBuffer, 0, 0, row, detail);
    }

    for (int row = detail; row <= 3 * detail; row++) {
        computeVertex(vertexBuffer, 4, detail, row, detail);
    }

    // build index buffer
    unsigned int i = 0;
    for (int strip = 0; strip < 5; strip++ ) {
        for (int column = 0; column < detail; column++) {
            int row = column;
            indexBuffer[i++] = indexOfVertex(strip, column, row, detail);
            for (; row <= 2 * detail + column; row++) {
                indexBuffer[i++] = indexOfVertex(strip, column, row, detail);
                indexBuffer[i++] = indexOfVertex(strip, column + 1, row + 1, detail);
            }
            indexBuffer[i++] = indexOfVertex(strip, column + 1, 2 * detail + column + 1, detail);
        }
    }

    // compile display list
    displayList = glGenLists(1);
    if (!displayList) {
        delete[] vertexBuffer;
        delete[] indexBuffer;
        return;
    }
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glNewList(displayList, GL_COMPILE);
    glVertexPointer(3, GL_FLOAT, 0, vertexBuffer);
    glNormalPointer(GL_FLOAT, 0, vertexBuffer);
    glDrawElements(GL_TRIANGLE_STRIP, indexCount, GL_UNSIGNED_SHORT, indexBuffer);
    glEndList();
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);

    delete[] vertexBuffer;
    delete[] indexBuffer;
}

unsigned short molekulo::Sphere::SpherePrivate::indexOfVertex(int strip, int column, int row, int detail)
{
    return (row + (3 * detail + 1) * (column + detail * strip));
}

void molekulo::Sphere::SpherePrivate::computeVertex(Eigen::Vector3f* vertexBuffer, int strip, int column, int row, int detail)
{
    strip %= 5;
    int next_strip = (strip + 1) % 5;

    // the index of the vertex we want to store the result in
    unsigned short index = indexOfVertex(strip, column, row, detail);

    // reference to the vertex we want to store the result in
    Eigen::Vector3f& vertex = vertexBuffer[index];

    // the "golden ratio", useful to construct an icosahedron
    const float phi = (1 + sqrtf(5.0f)) / 2;

    // the 12 vertices of the icosahedron
    const Eigen::Vector3f northVertices[5] =
    {
        Eigen::Vector3f(   0,   -1,  phi),
        Eigen::Vector3f( phi,    0,    1),
        Eigen::Vector3f(   1,  phi,    0),
        Eigen::Vector3f(  -1,  phi,    0),
        Eigen::Vector3f(-phi,    0,    1)
    };
    const Eigen::Vector3f southVertices[5] =
    {
        Eigen::Vector3f(  -1, -phi,    0),
        Eigen::Vector3f(   1, -phi,    0),
        Eigen::Vector3f( phi,    0,   -1),
        Eigen::Vector3f(   0,    1, -phi),
        Eigen::Vector3f(-phi,    0,   -1)
    };

    const Eigen::Vector3f northPole(0,  1,  phi);
    const Eigen::Vector3f southPole(0, -1, -phi);


    // pointers to the 3 vertices of the face of the icosahedron in which we are
    const Eigen::Vector3f *v0, *v1, *v2;

    // coordinates of our position inside this face.
    // range from 0 to detail.
    int  c1, c2;

    // first, normalize the global coords row, column
    if (row >= 2 * detail && column == 0) {
        strip--;
        if (strip < 0) strip += 5;
        next_strip--;
        if (next_strip < 0) next_strip += 5;
        column = detail;
    }

    // next, determine in which face we are, and determine the coords
    // of our position inside this face
    if (row  <= detail) {
        v0 = &northVertices[strip];
        v1 = &northPole;
        v2 = &northVertices[next_strip];
        c1 = detail - row;
        c2 = column;
    } else if (row >= 2 * detail) {
        v0 = &southVertices[next_strip];
        v1 = &southPole;
        v2 = &southVertices[strip];
        c1 = row - 2 * detail;
        c2 = detail - column;
    } else if (row <= detail + column) {
        v0 = &northVertices[next_strip];
        v1 = &southVertices[next_strip];
        v2 = &northVertices[strip];
        c1 = row - detail;
        c2 = detail - column;
    } else {
        v0 = &southVertices[strip];
        v1 = &southVertices[next_strip];
        v2 = &northVertices[strip];
        c1 = column;
        c2 = 2 * detail - row;
    }

    // now, compute the actual coords of the vertex
    float u1 = static_cast<float>(c1) / detail;
    float u2 = static_cast<float>(c2) / detail;
    vertex = *v0 + u1 * ( *v1 - *v0 ) + u2 * ( *v2 - *v0 );

    // project the vertex onto the sphere
    vertex.normalize();
}

molekulo::Sphere::Sphere(int detail) : d(new SpherePrivate)
{
    d->initialize(detail);
}

molekulo::Sphere::~Sphere()
{
    if (d->displayList)
        glDeleteLists(d->displayList, 1);
}

void molekulo::Sphere::draw(const Eigen::Vector3f& center, float radius) const
{
    glPushMatrix();
    glTranslated(center.x(), center.y(), center.z());
    glScaled(radius, radius, radius);
    glCallList(d->displayList);
    glPopMatrix();
}

