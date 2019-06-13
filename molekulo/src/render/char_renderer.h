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

#ifndef CHAR_RENDERER_H
#define CHAR_RENDERER_H

#include <QChar>
#include <QFont>

#include "render/gl.h"

namespace molekulo
{
    /**
     * This is a helper class for TextRenderer.
     *
     * The CharRenderer class represents a character stored as OpenGL rendering
     * data : a texture object and a display list mapping it on a quad and then
     * translating to the right of it.
     *
     * See the charTable member of TextRenderer for an example of use of
     * this class.
     */
    class CharRenderer
    {
    protected:
        GLuint m_glyphTexture;
        GLuint m_outlineTexture;

        GLuint m_quadDisplayList;

        GLenum m_textureTarget;

        int m_realwidth, m_realheight;

    public:
        CharRenderer();
        ~CharRenderer();

        bool initialize( QChar c, const QFont &font, GLenum textureTarget );

        void draw(const float *color) const;

        inline int height() const {
            return m_realheight;
        }

        inline int width() const {
            return m_realwidth;
        }

        inline void drawOutline() const
        {
            glBindTexture(m_textureTarget, m_outlineTexture);
            glCallList( m_quadDisplayList );
        }

        inline void drawGlyph() const
        {
            glBindTexture(m_textureTarget, m_glyphTexture);
            glCallList( m_quadDisplayList );
        }
    };
}


#endif // CHAR_RENDERER_H
