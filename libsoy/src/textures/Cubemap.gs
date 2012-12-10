/*
 *  libsoy - soy.textures.Cubemap
 *  Copyright (C) 2006,2007,2008,2009,2010,2011,2012 Copyleft Games Group
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program; if not, see http://www.gnu.org/licenses
 *
 */

[indent=4]
uses
    GL
    soy.atoms


class soy.textures.Cubemap : soy.textures.Texture

    _texture   : GLuint
    _updated   : bool
    _mutex : Mutex


    construct ()
        _mutex = Mutex()


    ////////////////////////////////////////////////////////////////////////
    // Properties

    _up : soy.textures.Texture?
    prop up : soy.textures.Texture?
        get
            return _up
        set
            _up = value

    _down : soy.textures.Texture?
    prop down : soy.textures.Texture?
        get
            return _down
        set
            _down = value

    _left : soy.textures.Texture?
    prop left : soy.textures.Texture?
        get
            return _left
        set
            _left = value

    _right : soy.textures.Texture?
    prop right : soy.textures.Texture?
        get
            return _right
        set
            _right = value

    _front : soy.textures.Texture?
    prop front : soy.textures.Texture?
        get
            return _front
        set
            _front = value

    _back : soy.textures.Texture?
    prop back : soy.textures.Texture?
        get
            return _back
        set
            _back = value


    ////////////////////////////////////////////////////////////////////////
    // Methods

    def override enable ()
        _mutex.lock()

        glEnable(GL_TEXTURE_CUBE_MAP_OES)

        if _texture is 0
            // Generate a new _texture
            glGenTextures(1, out _texture)

            // Bind the new texture and set its basic parameters
            glBindTexture(GL_TEXTURE_CUBE_MAP_OES, _texture)
            glTexParameteri(GL_TEXTURE_CUBE_MAP_OES, GL_TEXTURE_MAG_FILTER, (GLint)GL_LINEAR)
            glTexParameteri(GL_TEXTURE_CUBE_MAP_OES, GL_TEXTURE_MIN_FILTER, (GLint)GL_LINEAR)

            // flag the texture for updating here so it'll be processed below
            self._updated = true

        else
            // Bind the existing texture
            glBindTexture(GL_TEXTURE_CUBE_MAP_OES, _texture)


        if self._updated
            // connect each of the 6 faces
            if right is not null
                right.update(GL_TEXTURE_CUBE_MAP_POSITIVE_X_OES)

            if left is not null
                left.update(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_OES)

            if up is not null
                up.update(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_OES)

            if down is not null
                down.update(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_OES)

            if front is not null
                front.update(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_OES)

            if back is not null
                back.update(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_OES)


    def override disable ()
        glDisable(GL_TEXTURE_CUBE_MAP_OES)
        _mutex.unlock()

