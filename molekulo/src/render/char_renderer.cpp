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

#include "render/char_renderer.h"

#include <cmath>
#include <QFontMetrics>
#include <QImage>
#include <QPainter>

#define OUTLINE_WIDTH     3
const int OUTLINE_BRUSH[2*OUTLINE_WIDTH+1][2*OUTLINE_WIDTH+1]
= { { 10, 30,  45,  50,  45,  30,  10 },
    { 30, 65,  85,  100,  85, 65,  30 },
    { 45, 85,  200, 256, 200, 85,  45 },
    { 50, 100, 256, 256, 256, 100, 50},
    { 45, 85,  200, 256, 200, 85,  45 },
    { 30, 65,  85,  100,  85, 65,  30 },
    { 10, 30,  45,  50,  45,  30,  10 }
};

molekulo::CharRenderer::CharRenderer()
{
    m_glyphTexture = 0;
    m_outlineTexture = 0;
    m_quadDisplayList = 0;
}

molekulo::CharRenderer::~CharRenderer()
{
    if( m_glyphTexture ) glDeleteTextures( 1, &m_glyphTexture );
    if( m_outlineTexture ) glDeleteTextures( 1, &m_outlineTexture );
    if( m_quadDisplayList ) glDeleteLists( m_quadDisplayList, 1 );
}

static void normalizeTexSize(GLenum textureTarget, int& texwidth, int& texheight)
{
    // if the texture target is GL_TEXTURE_2D, that means that
    // the texture_rectangle OpenGL extension is unsupported and we must
    // use only square, power-of-two textures.
    if (textureTarget == GL_TEXTURE_2D) {
        int x = qMax( texwidth, texheight );
        // find next power of two
        int n;
        for(n = 1; n < x; n = n << 1) {}
        // the texture must be square, and its size must be a power of two.
        texwidth = texheight = n;
    }
}

bool molekulo::CharRenderer::initialize( QChar c, const QFont &font, GLenum textureTarget )
{
    if( m_quadDisplayList ) return true;
    m_textureTarget = textureTarget;
    // *** STEP 1 : render the character to a QImage ***

    // compute the size of the image to create
    const QFontMetrics fontMetrics ( font );
    m_realwidth = fontMetrics.width(c);
    m_realheight = fontMetrics.height();
    if(m_realwidth == 0 || m_realheight == 0) return false;
    int texwidth  =  m_realwidth + 2 * OUTLINE_WIDTH;
    int texheight = m_realheight + 2 * OUTLINE_WIDTH;
    normalizeTexSize(textureTarget, texwidth, texheight);

    // create a new image
    QImage image( texwidth, texheight, QImage::Format_RGB32 );
    QPainter painter;
    // start painting the image
    painter.begin( &image );
    painter.setFont( font );
    painter.setRenderHint( QPainter::TextAntialiasing );
    painter.setBackground( Qt::black );
    painter.eraseRect( image.rect() );
    // use an artificial blue color. This image is only used internally anyway.
    painter.setPen( Qt::blue );
    // actually paint the character. The position seems right at least with Helvetica
    // at various sizes, I didn't try other fonts. If in the future a user complains about
    // the text being clamped to the top/bottom, change this line.
    painter.drawText ( 1, m_realheight
                       + 2 * OUTLINE_WIDTH
                       - painter.fontMetrics().descent(),
                       c );
    // end painting the image
    painter.end();

    // *** STEP 2 : extract the raw bitmap from the image ***

    // --> explanation: the image we just rendered is RGB, but actually all the
    //     data is in the B channel because we painted in blue. Now we extract
    //     this blue channel into a separate bitmap that'll be faster to manipulate
    //     in what follows.

    int *rawbitmap = new int[ texwidth * texheight ];
    if( ! rawbitmap ) return false;
    int n = 0;
    // loop over the pixels of the image, in reverse y direction
    for( int j = texheight - 1; j >= 0; j-- )
        for( int i = 0; i < texwidth; i++, n++ )
        {
            double x = qBlue( image.pixel( i, j ) ) / 255.0;
            double y = pow(x, 0.75); /* this applies a gamma correction.
                the effect of this is to concentrate the intensities in
                the large values. This results in a slightly bolder-looking
                font, which is more suitable for outlining. More importantly,
                this makes more intense the otherwise dim shades. As the
                intensity of the outline is proportional to the intensity of
                the rawbitmap, dim shades give a dim outline which is
                bad for readability, so we don't want a whole part of a glyph
                to use a dim shade. Now the problem is that on my setup,
                e.g. the small "n" had one of its legs spread across two columns
                of pixels, each with a dim shade.*/
            rawbitmap[n] = static_cast<int>(255.0 * y);
        }

    // *** STEP 3 : compute the neighborhood map from the raw bitmap ***

    // --> explanation: we apply a convolution filter to the raw bitmap
    //     to produce a new map each pixel is associated a float telling how
    //     much it is surrounded by other pixels.

    int *neighborhood = new int[ texwidth * texheight ];
    if( ! neighborhood ) return false;
    for( int i = 0; i < texheight * texwidth; i++)
        neighborhood[i] = 0;

    for( int i = 0; i < texheight; i++ ) {
        for( int j = 0; j < texwidth; j++ ) {
            n = j + i * texwidth;
            for( int di = -OUTLINE_WIDTH; di <= OUTLINE_WIDTH; di++ ) {
                for( int dj = -OUTLINE_WIDTH; dj <= OUTLINE_WIDTH; dj++ ) {
                    int fi = i + di;
                    int fj = j + dj;
                    if( fi >= 0 && fi < texheight && fj >= 0 && fj < texwidth ) {
                        int fn = fj + fi * texwidth;
                        neighborhood[fn]
                            = qMax(
                                  neighborhood[fn],
                                  rawbitmap[n]
                                  * OUTLINE_BRUSH[OUTLINE_WIDTH + di]
                                  [OUTLINE_WIDTH + dj]);
                    }
                }
            }
        }
    }

    // *** STEP 4 : compute the final bitmap ***
    // --> explanation: we build the bitmap that will be passed to OpenGL for texturing.
    //     this texture has 2 channels: the luminance and the alpha channels.
    //     the rawbitmap readily gives the luminance channel, while the computation of the
    //     alpha channel is a bit more involved and uses the neighborhood map.

    GLubyte *glyphbitmap = new GLubyte[ texwidth * texheight ];
    if( ! glyphbitmap ) return false;
    GLubyte *outlinebitmap = new GLubyte[ texwidth * texheight ];
    if( ! outlinebitmap ) return false;

    for( int n = 0; n < texwidth * texheight; n++ )
    {
        glyphbitmap[n] = static_cast<GLubyte>(rawbitmap[n]);
        int alpha = (neighborhood[n] >> 8) + rawbitmap[n];
        if( alpha > 255 ) {
            alpha = 255;
        }
        outlinebitmap[n] = static_cast<GLubyte>(alpha);
    }

    delete [] rawbitmap;
    delete [] neighborhood;

    // *** STEP 5 : pass the final bitmap to OpenGL for texturing ***

    glGenTextures( 1, &m_glyphTexture );
    if( ! m_glyphTexture ) return false;
    glGenTextures( 1, &m_outlineTexture );
    if( ! m_outlineTexture ) return false;

    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

    glBindTexture( textureTarget, m_glyphTexture );
    glTexImage2D(
        textureTarget,
        0,
        GL_ALPHA,
        texwidth,
        texheight,
        0,
        GL_ALPHA,
        GL_UNSIGNED_BYTE,
        glyphbitmap );

    glTexParameteri( textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( textureTarget, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

    glBindTexture( textureTarget, m_outlineTexture );
    glTexImage2D(
        textureTarget,
        0,
        GL_ALPHA,
        texwidth,
        texheight,
        0,
        GL_ALPHA,
        GL_UNSIGNED_BYTE,
        outlinebitmap );

    glTexParameteri( textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( textureTarget, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

    // the texture data is now kept alive by OpenGL. It's time to free the bitmaps.
    delete [] glyphbitmap;
    delete [] outlinebitmap;

    // *** STEP 6 : compile the display list ***

    m_quadDisplayList = glGenLists(1);
    if( ! m_quadDisplayList ) return false;

    int texcoord_width = (textureTarget == GL_TEXTURE_2D) ? 1 : texwidth;
    int texcoord_height = (textureTarget == GL_TEXTURE_2D) ? 1 : texheight;

    glNewList( m_quadDisplayList, GL_COMPILE );
    glBegin( GL_QUADS );
    glTexCoord2i( 0, 0);
    glVertex2f( 0 , -texheight );
    glTexCoord2i( texcoord_width, 0);
    glVertex2f( texwidth , -texheight );
    glTexCoord2i( texcoord_width, texcoord_height);
    glVertex2f( texwidth, 0 );
    glTexCoord2i( 0, texcoord_height);
    glVertex2f( 0 , 0 );
    glEnd();
    glTranslatef( m_realwidth, 0, 0 );
    glEndList();

    return true;
}
