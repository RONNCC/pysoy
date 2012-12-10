/*
 *  libsoy - soy.materials.Textured
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


class soy.materials.Textured : soy.materials.Colored
    /*
    *
    * GL_TEXTURE0 : for colormap
    * GL_TEXTURE1 : for glowmap
    * GL_TEXTURE2 : for bumpmap
    */

    // This simplifies rendering code
    _ids : static array of GLenum = {
        GL_TEXTURE0,
        GL_TEXTURE1,
        GL_TEXTURE2,
        GL_TEXTURE3
    }

    // This is used to render bumpmaps
    _normalisation_cubemap : static soy.textures.Cubemap

    // This ensures the texture property isn't changed while rendering it.
    _mutex : Mutex


    init
        _mutex = Mutex()
        needsTSLVs = false
        translucent = false


    construct (name : string? = null,
               bumpmap : soy.textures.Texture?,
               colormap : soy.textures.Texture?,
               glowmap : soy.textures.Texture?)
        super(name)
        _bumpmap = bumpmap
        _colormap = colormap
        _glowmap = glowmap


    ////////////////////////////////////////////////////////////////////////
    // Methods

    def override render (pass : int, tslvs : GLvoid*) : bool
        // Textured is only 1-pass (for now)
        if pass == 0
            // Lock mutex so the texture can't be changed until we're done
            _mutex.lock()

            // Enable colors
            self.enable_colors()

            // Enable colormap if available
            if _colormap is not null
                self.enable_colormap(0)
            if _glowmap is not null
                self.enable_glowmap(1)

            // Smooth or flat shading
            self.enable_shades()

            // Disable what we're not using and return
            glClientActiveTexture(GL_TEXTURE3)
            glDisableClientState(GL_TEXTURE_COORD_ARRAY)
            glClientActiveTexture(GL_TEXTURE2)
            glDisableClientState(GL_TEXTURE_COORD_ARRAY)
            if _glowmap is null            
                glClientActiveTexture(GL_TEXTURE1)
                glDisableClientState(GL_TEXTURE_COORD_ARRAY)
            if _colormap is null
                glClientActiveTexture(GL_TEXTURE0)
                glDisableClientState(GL_TEXTURE_COORD_ARRAY)

            return true

        // Cleanup on pass 1
        if _colormap is not null
            self.disable_colormap(0)

        if _glowmap is not null
            self.disable_glowmap(1)

        // Lock mutex so the texture can't be changed until we're done
        _mutex.unlock()
        return false


    def enable_bumpmap (id : int)
        // Enable Texture
        glActiveTexture(_ids[id])
        glClientActiveTexture(_ids[id])
        glEnableClientState(GL_TEXTURE_COORD_ARRAY)
        glTexCoordPointer(3, GL_FLOAT, (GLsizei) (sizeof(GLfloat) * 11),
                          (GLvoid*) (sizeof(GLfloat) * 6))
        // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE)
        _bumpmap.enable()


    def enable_colormap (id : int)
        // Enable Texture
        glActiveTexture(_ids[id])
        glClientActiveTexture(_ids[id])
        glEnableClientState(GL_TEXTURE_COORD_ARRAY)
        glTexCoordPointer(3, GL_FLOAT, (GLsizei) (sizeof(GLfloat) * 11),
                          (GLvoid*) (sizeof(GLfloat) * 6))
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, (GLint) GL_MODULATE)
        _colormap.enable()


    def enable_glowmap (id : int)
        // Enable Texture
        glActiveTexture(_ids[id])
        glClientActiveTexture(_ids[id])
        glEnableClientState(GL_TEXTURE_COORD_ARRAY)
        glEnable(GL_BLEND)
        glBlendFunc(GL_ONE, GL_ONE)
        glTexCoordPointer(3, GL_FLOAT, (GLsizei) (sizeof(GLfloat) * 11),
                          (GLvoid*) (sizeof(GLfloat) * 6))
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, (GLint) GL_ADD)
        _glowmap.enable()


    def disable_bumpmap (id : int)
        glActiveTexture(_ids[id])
        glClientActiveTexture(_ids[id])
        glDisableClientState(GL_TEXTURE_COORD_ARRAY)
        _bumpmap.disable()


    def disable_colormap (id : int)
        glActiveTexture(_ids[id])
        glClientActiveTexture(_ids[id])
        glDisableClientState(GL_TEXTURE_COORD_ARRAY)
        _colormap.disable()


    def disable_glowmap (id : int)
        glActiveTexture(_ids[id])
        glClientActiveTexture(_ids[id])
        glDisableClientState(GL_TEXTURE_COORD_ARRAY)
        _glowmap.disable()


    ////////////////////////////////////////////////////////////////////////
    // Properties

    //
    // bumpmap property
    _bumpmap : soy.textures.Texture?

    prop bumpmap : soy.textures.Texture?
        get
            return _bumpmap
        set
            _mutex.lock()
            _bumpmap = value
            _mutex.unlock()

    //
    // colormap property
    _colormap : soy.textures.Texture?

    prop colormap : soy.textures.Texture?
        get
            return _colormap
        set
            _mutex.lock()
            _colormap = value
            _mutex.unlock()

    //
    // glowmap property
    _glowmap : soy.textures.Texture?

    prop glowmap : soy.textures.Texture?
        get
            return _glowmap
        set
            _mutex.lock()
            _glowmap = value
            _mutex.unlock()

    ////////////////////////////////////////////////////////////////////////
    // Static

    init static
        _normalisation_cubemap = new soy.textures.Cubemap()
        // resize each face
        // populate with values

