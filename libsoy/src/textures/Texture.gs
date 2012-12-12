/*
 *  libsoy - soy.textures.Texture
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


class soy.textures.Texture : Object //soy._internals.Loadable

    _textureID : GLuint
    texels    : uchar*
    _texel_objs: dict of int, weak soy.atoms.Color?
    _isAnimated: int
    _scaleX    : GLfloat
    _scaleY    : GLfloat
    _updated   : bool
    _formats: static array of GLenum = {0, GL_LUMINANCE, GL_LUMINANCE_ALPHA,
                                        GL_RGB, GL_RGBA}
    _mutex : Mutex


    init
        _texel_objs = new dict of int, unowned soy.atoms.Color?
        _animate = new array of GLfloat[3]
        _mutex = Mutex()
        _scaleX = 0.0f
        _smooth = true


    construct ()
        _chans = 3


    construct from_png (filename : string)
        surface : Cairo.ImageSurface
        surface = new Cairo.ImageSurface.from_png(filename)
        self._copySurface(surface)


    construct from_svg (filename : string)
        context : Cairo.Context
        handle : Rsvg.Handle
        surface : Cairo.ImageSurface

        try
            handle = new Rsvg.Handle.from_file(filename)
            surface = new Cairo.ImageSurface(Cairo.Format.ARGB32, handle.width,
                                         handle.height)
            context = new Cairo.Context(surface)
            handle.render_cairo(context)
        except g : GLib.Error
            stdout.printf("Error: %s\n", g.message) // TODO better error management
            return

        self._copySurface(surface)


    ////////////////////////////////////////////////////////////////////////
    // Properties

    _animate : array of GLfloat
    prop animate : array of GLfloat
        get
            return _animate


    _aspect    : float
    prop aspect : float
        get
            return _aspect


    //
    // Channels Property
    _chans : int
    prop channels : int
        get
            return _chans
        set
            if value < 1 or value > 4
                return
            resize(value, self._width, self._height)

    //
    // Size Property
    _width     : GLsizei
    _height    : GLsizei
    _size_obj : weak soy.atoms.Size?

    def _size_set(size : soy.atoms.Size)
        resize(self._chans,
               (GLsizei) Math.lround(size.width),
               (GLsizei) Math.lround(size.height))

    def _size_weak(size : Object)
        self._size_obj = null

    prop size : soy.atoms.Size
        owned get
            value : soy.atoms.Size? = self._size_obj
            if value is null
                value = new soy.atoms.Size((float) self._width,
                                           (float) self._height)
                value.on_set.connect(self._size_set)
                value.weak_ref(self._size_weak)
                self._size_obj = value
            return value
        set
            self._size_set(value)
            if _size_obj != null
                _size_obj.on_set.disconnect(self._size_set)
                _size_obj.weak_unref(self._size_weak)
            _size_obj = value
            value.on_set.connect(self._size_set)
            value.weak_ref(self._size_weak)

    //
    // Smooth Property
    _smooth : bool
    prop smooth : bool
        get
            return self._smooth
        set
            self._smooth = value
            self._updated = true


    ////////////////////////////////////////////////////////////////////////
    // Methods

    def new get (index : int) : Color?
        ret : soy.atoms.Color? = null

        // Return null if requested index is out of bounds
        if index < 0 or index >= (self._width * self._height)
            return null

        // Return existing Color object if there is one
        if self._texel_objs.has_key(index)
            ret = _texel_objs[index]

        // Otherwise create a new object based on number of channels
        else if self._chans == 1
            var l = texels[index]
            ret = new soy.atoms.Color(l, l, l, 255)
        else if self._chans == 2
            var l = texels[index*2]
            var a = texels[index*2+1]
            ret = new soy.atoms.Color(l, l, l, a)
        else if self._chans == 3
            var r = texels[index*3]
            var g = texels[index*3+1]
            var b = texels[index*3+2]
            ret = new soy.atoms.Color(r, g, b, 255)
        else // if self._chans == 4
            var r = texels[index*4]
            var g = texels[index*4+1]
            var b = texels[index*4+2]
            var a = texels[index*4+3]
            ret = new soy.atoms.Color(r, g, b, a)

        // Set event callbacks
        ret.on_set.connect(self._texel_set)
        ret.weak_ref(self._texel_weak)

        // Store weak reference and return owned Color object
        self._texel_objs[index] = ret
        return (owned) ret


    def new set (index : int, value : Object)
        color : soy.atoms.Color

        if not (value isa soy.atoms.Color)
            return

        color = (soy.atoms.Color) value

        // Disconnect old texel Color object
        if self._texel_objs.has_key(index)
            var old = self._texel_objs[index]
            old.on_set.disconnect(self._texel_set)
            old.weak_unref(self._texel_weak)

        // Store weak reference
        self._texel_objs[index] = color

        // Set callbacks
        color.on_set.connect(self._texel_set)
        color.weak_ref(self._texel_weak)

        // Update local storage
        //
        // This code is a bit repetitive, but its hard to consolidate it
        // without slowing it down considerably.  Remember that users will use
        // this API for generating textures in their own code, so even small
        // hits to speed here will be multiplied by the size of their Texture

        // Luma
        if self._chans == 1
            texels[index] = color.luma
        // Luma+Alpha
        else if self._chans == 2
            texels[index*2] = color.luma
            texels[index*2+1] = color.alpha
        // RGB
        else if self._chans == 3
            texels[index*3] = color.red
            texels[index*3+1] = color.green
            texels[index*3+2] = color.blue
        // RGB+Alpha
        else // self._chans == 4
            texels[index*4] = color.red
            texels[index*4+1] = color.green
            texels[index*4+2] = color.blue
            texels[index*4+3] = color.alpha

        // Flag for updating
        self._mutex.lock()
        self._updated = true
        self._mutex.unlock()


    def _copySurface (surface : Cairo.ImageSurface)
        chans : int
        width : int
        height : int
        stride : int
        data : uchar*

        // Ensture all pending drawing operations are finished
        surface.flush()

        // Determine number of channels
        if surface.get_format() == Cairo.Format.RGB24
            chans = 3
        else // Cairo.Format.ARGB32
            chans = 4

        // Get surface width, height, and stride
        width = surface.get_width()
        height = surface.get_height()
        stride = surface.get_stride()

        // Get pointer to data
        data = (void*) surface.get_data()

        // Allocate texels
        self.resize(chans, squareup(width), squareup(height))

        // Switch on datatype
        if _chans == 3
            // Copy to texels, row by row
            for var y = 0 to (height-1)
                for var x = 0 to (width-1)
                    var src = (y * stride) + (x * 4)
                    var dst = ((y * _width) + x) * _chans
                    texels[dst  ] = *(data+src+2)
                    texels[dst+1] = *(data+src+1)
                    texels[dst+2] = *(data+src  )

        else // RGBA
            // TODO this function is really just a test
            surface2rgba(texels, _chans*_width, data, stride, 0, 0)

        // Calculate aspect ratio
        _aspect = (float) width / (float) height

        // Calc ratio between texture and actual size
        // This is used for texcoord translation so the image acts like the
        // full texture, when actually it's just scaled all the texcoords
        _scaleX = (float) width / (float) _width
        _scaleY = (float) height / (float) _height

        // Disable scaling for 1:1 ratio
        if _scaleX == 1.0f and _scaleY == 1.0f
            _scaleX = 0.0f


    def _texel_set(color : soy.atoms.Color)
        //
        // Iterate over texels with a Color object, update each match using
        // correct byte/channel mapping
        //

        // Luma
        if self._chans == 1
            for index in self._texel_objs.keys
                if self._texel_objs[index] is color
                    texels[index] = color.luma

        // Luma+Alpha
        else if self._chans == 2
            for index in self._texel_objs.keys
                if self._texel_objs[index] is color
                    texels[index*2] = color.luma
                    texels[index*2+1] = color.alpha
        // RGB
        else if self._chans == 3
            for index in self._texel_objs.keys
                if self._texel_objs[index] is color
                    texels[index*3] = color.red
                    texels[index*3+1] = color.green
                    texels[index*3+2] = color.blue
        // RGB+Alpha
        else // self._chans == 4
            for index in self._texel_objs.keys
                if self._texel_objs[index] is color
                    texels[index*4] = color.red
                    texels[index*4+1] = color.green
                    texels[index*4+2] = color.blue
                    texels[index*4+3] = color.alpha

        // Flag for updating
        self._mutex.lock()
        self._updated = true
        self._mutex.unlock()


    def _texel_weak(color : Object)
        // We can't remove keys from _texel_objs while we iterate over it, so
        // we instead build a list of keys that need to be garbage collected
        var garbage = new list of int
        for index in self._texel_objs.keys
            if self._texel_objs[index] is color
                garbage.add(index)
        // Now we can remove them
        for index in garbage
            self._texel_objs.unset(index)


    def resize(c : int, x : int, y : int)
        //
        // This function is called to allocate or free self.texels
        // It will also set ._chans ._width and ._height
        //
        size : int // long int?

        // Lock against rendering
        self._mutex.lock()

        size = c * x * y

        // If this is a request to free texels
        if size is 0
            if self._width is not 0
                free(self.texels)
                self.texels = null

        else
            // Have we already alloc'ed?
            if self._width is not 0
                if _chans is not c or _width is not x or _height is not y
                    temptexels : uchar* = malloc(size)
                    origin : uchar* = temptexels
                    // Reallocate for new size
                    // Hold onto the origin for us, incase we lose it

                    oldSize : int = self._chans * self._width * self._height
                    // Record old texels size

                    for index : int = 0 to (oldSize - 1)
                        temptexels[index] = self.texels[index]
                    // Shift existing values into new storage layout

                    free(self.texels)
                    self.texels = origin
            else
                // Allocate a new texel buffer
                self.texels = malloc0(size)

        // We're all done, set the object's new channels and size
        self._chans = c
        self._width = (GLsizei) x
        self._height = (GLsizei) y
        self._updated = true
        self._mutex.unlock()


    def inline update(target : GLenum)
        glTexImage2D(target, 0, (GLint) _formats[_chans], _width, _height, 0,
                     _formats[_chans], GL_UNSIGNED_BYTE,
                     (GL.GLvoid*) self.texels)


    def virtual enable ()
        _i : int
        _anim : array of float = new array of float[3]

        // Don't bother with empty texture
        if texels == null
            // But delete it if it was previously created
            if _textureID is not 0
                glDeleteTextures(1, {_textureID})
            return

        // Lock to prevent resizing while we render
        _mutex.lock()

        // Enable our texture
        glEnable(GL_TEXTURE_2D)

        // If we haven't generated this texture yet, do so now
        if _textureID is 0
            // Generate a new _textureID
            glGenTextures(1, out _textureID)

            // Bind the new texture and set its basic parameters
            glBindTexture(GL_TEXTURE_2D, _textureID)
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (GLint)GL_LINEAR)
            if self._smooth
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                                (GLint)GL_LINEAR)
            else
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                                (GLint)GL_NEAREST)

            // flag the texture for updating here so it'll be processed below
            self._updated = true

        else
            // Bind the existing textureID
            glBindTexture(GL_TEXTURE_2D, _textureID)

        // If the texture needs updating
        if self._updated
            self.update(GL_TEXTURE_2D)

            /*
            else // _target is GL_TEXTURE_CUBE_MAP
                _size = _bytes * _chans * _width * _height
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0,(GLint)_chans,
                             _width, _height, 0, (GLenum) _formats[_chans],
                             (GLenum)_types[_bytes], texels)
                glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0,(GLint)_chans,
                             _width, _height, 0, (GLenum) _formats[_chans],
                             (GLenum)_types[_bytes], ((GL.GLvoid*) texels)+_size)
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0,(GLint)_chans,
                             _width, _height, 0, (GLenum) _formats[_chans],
                             (GLenum)_types[_bytes], ((GL.GLvoid*) texels)+(_size*2))
                glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0,(GLint)_chans,
                             _width, _height, 0, (GLenum) _formats[_chans],
                             (GLenum)_types[_bytes], ((GL.GLvoid*) texels)+(_size*3))
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0,(GLint)_chans,
                             _width, _height, 0, (GLenum) _formats[_chans],
                             (GLenum)_types[_bytes], ((GL.GLvoid*) texels)+(_size*4))
                glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0,(GLint)_chans,
                             _width, _height, 0, (GLenum) _formats[_chans],
                             (GLenum)_types[_bytes], ((GL.GLvoid*) texels)+(_size*5))
            */
            // Update complete, clear the flag
            self._updated = false

        // Translate the texture matrix to animation state if needed
        if _isAnimated is 1
            var tv = GLib.TimeVal()
            var _it = ((float) tv.tv_sec) + ((float) tv.tv_usec) / 1000000.0f
            for _i = 0 to 3
                _anim[_i] = _it * _animate[_i]
                _anim[_i] = _anim[_i] - _anim[_i]
            glMatrixMode(GL_TEXTURE)
            glTranslatef((float)_anim[0], (float) _anim[1], (float) _anim[2])

        // Scale the texture matrix if needed
        if _scaleX is not 0
            glMatrixMode(GL_TEXTURE)
            glScalef(_scaleX, _scaleY, 1)


    def virtual disable ()
        if texels == null
            return
        glDisable(GL_TEXTURE_2D)

        // undo animation and/or scale
        if _isAnimated is not 0 or _scaleX is not 0
            glMatrixMode(GL_TEXTURE)
            glLoadIdentity()
        _mutex.unlock()


    def load (_vdata : void*, _size : int)
        //
        // This function is called by a soy.transports.Transport for each .soy
        // packet that's loaded.  We store the next packet number in self._state
        // which is set to -1 if there's an error or we're finished.
        //
        // _i = iterator
        //
        //_i : int
        _data :array of uchar  //= new array of uchar[]
        _data = (array of uchar) _vdata

        // Process this packet.
        // TODO


    ////////////////////////////////////////////////////////////////////////
    // Static Methods

    def static squareup(_v : int) : int
        //
        // This handy hack courtesy Sean Anderson, see:
        // http://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
        //
        _v = _v - 1
        _v = _v | _v >> 1
        _v = _v | _v >> 2
        _v = _v | _v >> 4
        _v = _v | _v >> 8
        _v = _v | _v >> 16
        return _v + 1


    def static extern surface2rgba (dst : uchar*,
                                    dst_stride : int,
                                    src : uchar*,
                                    src_stride : int,
                                    n : int, m : int)

