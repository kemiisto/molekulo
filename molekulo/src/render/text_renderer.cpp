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

#include "text_renderer.h"

#include "render/char_renderer.h"
#include "render/viewer.h"

#include <QPainter>
#include <QHash>
#include <QDebug>

#ifndef GL_TEXTURE_RECTANGLE_ARB
# define GL_TEXTURE_RECTANGLE_ARB 0x84F5
#endif

class molekulo::TextRenderer::TextRendererPrivate
{
public:

    TextRendererPrivate() : initialized(false)
    {
        font.setStyleStrategy(QFont::NoAntialias);
    }
    ~TextRendererPrivate() {}

    /**
       * The font used for rendering the chars.
       */
    QFont font;

    /**
       * This hash gives the correspondence table between QChars
       * (the keys) and the corresponding CharRenderers (the values).
       * Every time a QChar is being met, either it is found in this
       * table, in which case it can be directly rendered, or it is
       * not found, in which case a new CharRenderer is created for
       * it and added to this table.
       */
    QHash<QChar, CharRenderer*> charTable;

    /**
       * The GLWidget in which to render. This is set
       * once and for all by setup().
       */
    molekulo::Viewer *glwidget;

    GLboolean textmode;

    bool initialized;

    GLenum textureTarget;

    static int isGLExtensionSupported(const char *extension);
    void do_draw(const QString &string);
};

molekulo::TextRenderer::TextRenderer() : d(new TextRendererPrivate)
{
    d->glwidget = 0;
    d->textmode = false;
}

molekulo::TextRenderer::~TextRenderer()
{
    QHash<QChar, CharRenderer *>::iterator i = d->charTable.begin();
    while( i != d->charTable.end() ) {
        delete i.value();
        i = d->charTable.erase(i);
    }
    delete d;
}

// void TextRenderer::setGLWidget( GLWidget *glwidget )
// {
//   d->glwidget = glwidget;
//   d->font = d->glwidget->font();
// }

// the code of isGLExtensionSupported() is taken from the webpage:
// http://www.opengl.org/resources/features/OGLextensions/
// it seems pretty clear from this context that this code is provided
// without any use restriction.
int molekulo::TextRenderer::TextRendererPrivate::isGLExtensionSupported(const char *extension)
{
    const GLubyte *extensions = NULL;
    const GLubyte *start;
    GLubyte *where, *terminator;
    /* Extension names should not have spaces. */
    where = (GLubyte *) strchr(extension, ' ');
    if (where || *extension == '\0')
        return 0;
    extensions = glGetString(GL_EXTENSIONS);
    /* It takes a bit of care to be fool-proof about parsing the
       OpenGL extensions string. Don't be fooled by sub-strings,
       etc. */
    start = extensions;
    for (;;) {
        where = (GLubyte *) strstr((const char *) start, extension);
        if (!where)
            break;
        terminator = where + strlen(extension);
        if (where == start || *(where - 1) == ' ')
            if (*terminator == ' ' || *terminator == '\0')
                return 1;
        start = terminator;
    }
    return 0;
}


void molekulo::TextRenderer::begin(molekulo::Viewer *widget)
{
    if(!d->initialized) {
        if(TextRendererPrivate::isGLExtensionSupported("GL_ARB_texture_rectangle")) {
            d->textureTarget = GL_TEXTURE_RECTANGLE_ARB;
            qDebug() << "OpenGL extension GL_ARB_texture_rectangle is present.";
        } else {
            d->textureTarget = GL_TEXTURE_2D;
            qDebug() << "OpenGL extension GL_ARB_texture_rectangle is absent.";
        }
        d->initialized = true;
    }

    // already called begin
    if(d->glwidget == widget)
    {
        return;
    }


    // make sure we called ::end
    assert(!d->glwidget);

    d->glwidget = widget;
    d->textmode = true;
    //   glPushAttrib(GL_ENABLE_BIT | GL_DEPTH_BUFFER_BIT);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_LIGHTING);
    glDisable(GL_FOG);
    glDisable(GL_CULL_FACE);
    glEnable(d->textureTarget);
    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, d->glwidget->width(), 0, d->glwidget->height(), 0, 1);
    // qDebug() << d->glwidget->left << d->glwidget->right << d->glwidget->bottom << d->glwidget->top;
    // glOrtho(d->glwidget->left, d->glwidget->right, d->glwidget->bottom, d->glwidget->top, 0, 1);
    glMatrixMode(GL_MODELVIEW);
}

void molekulo::TextRenderer::end()
{
    if (d->glwidget) {
        assert(d->textmode);
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopAttrib();
        glDepthMask(GL_TRUE);
        glEnable(GL_LIGHTING);
        d->textmode = false;
        d->glwidget = 0;
    }
}

void molekulo::TextRenderer::TextRendererPrivate::do_draw( const QString &string )
{
    int i;
    GLfloat color[4];
    glGetFloatv(GL_CURRENT_COLOR, color);

    // Pass 1: render and cache the glyphs that are not yet cached.
    for( i = 0; i < string.size(); i++ )
    {
        if( ! charTable.contains( string[i] ) )
        {
            CharRenderer *c = new CharRenderer;
            if(!c->initialize( string[i], font, textureTarget ) )
            {
                delete c;
                c = new CharRenderer;
                qDebug() << "Character " << string[i]
                         << "(unicode" << string[i].unicode()
                         << ") failed to render using the following font:";
                qDebug() << font.toString();
                if(!c->initialize( '*', font, textureTarget ))
                {
                    qDebug() << "Can't render even a simple character (*).";
                    qDebug() << "Are you using a bad font, or what?";
                    qDebug() << "The font being used is:";
                    qDebug() << font.toString();
                    assert(false);
                }
            }
            charTable.insert( string[i], c);
        }
    }

    // Pass 2: render the outline
    glColor4f((1-color[0])/2,(1-color[1])/2,(1-color[2])/2,1); // use opposite color, but make it darker
    glPushMatrix();
    for( i = 0; i < string.size(); ++i )
    {
        charTable.value( string[i] )->drawOutline();
    }
    glPopMatrix();

    // Pass 3: render the glyphs themselves
    glColor4fv(color);
    for( i = 0; i < string.size(); ++i )
    {
        charTable.value( string[i] )->drawGlyph();
    }
}

int molekulo::TextRenderer::draw( int x, int y, const QString &string )
{
    assert(d->textmode);
    if( string.isEmpty() ) return 0;
    glPushMatrix();
    glLoadIdentity();
    glTranslatef( x, d->glwidget->height() - y, 0 );
    d->do_draw(string);
    glPopMatrix();
    const QFontMetrics fontMetrics ( d->font );
    return fontMetrics.height();
}

int molekulo::TextRenderer::draw( const Eigen::Vector3f &pos, const QString &string )
{
    assert(d->textmode);
    if( string.isEmpty() ) return 0;

    const QFontMetrics fontMetrics ( d->font );
    int w = fontMetrics.width(string);
    int h = fontMetrics.height();

    Eigen::Vector3f wincoords = d->glwidget->project(pos);

    // project is in QT window coordinates
    wincoords.y() = d->glwidget->height() - wincoords.y();

//    wincoords.x() -= w/2;
//    wincoords.y() += h/2;
    wincoords.x() -= w/2;
    wincoords.y() += h;

    glPushMatrix();
    glLoadIdentity();
    glTranslatef( static_cast<int>(wincoords.x()),
                  static_cast<int>(wincoords.y()),
                  -wincoords.z() );
    d->do_draw(string);
    glPopMatrix();
    return h;
}

bool molekulo::TextRenderer::isActive()
{
    return d->glwidget;
}
