/*
 *  libsoy - soy.bodies.Box
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
    ode
    soy.atoms


class soy.bodies.Box : soy.bodies.Body
    _ebo : GLuint   // Element Buffer Object
    _vbo : GLuint   // Vertex Buffer Object
    _updated : bool // Buffers need updating


    construct (position : soy.atoms.Position?, size : soy.atoms.Size?,
               material : soy.materials.Material?)
        super(position, size, 0.0f)

        // Setup for first render pass
        _ebo = 0
        _updated = true

        // Set default material
        if material is null
            if default_material is null
                default_material = new soy.materials.Material()
            _material = default_material

        // Use the provided material
        else
            _material = material


    def override create_geom (geom_param : Object?, geom_scalar : float)
        // Set default size
        _width = _height = _depth = 1.0f

        geom = new ode.geoms.Box(null, (Real) _width, (Real) _height,
                                 (Real) _depth)

        // set size if provided
        if geom_param is not null
            self.size = (soy.atoms.Size) geom_param
        geom.SetCategoryBits(GeomBody)
        geom.SetData((void*) self)


    ////////////////////////////////////////////////////////////////////////
    // Properties

    //
    // Material property
    _material : soy.materials.Material
    prop material : soy.materials.Material
        get
            return _material
        set
            mutex.lock()
            _material = value
            mutex.unlock()

    //
    // Size Property
    _width  : GLfloat
    _height : GLfloat
    _depth  : GLfloat
    _size_obj : weak soy.atoms.Size?

    def _size_set(size : soy.atoms.Size)
        // Set size while locked to avoid potential rendering weirdness
        mutex.lock()
        _width = (GLfloat) size.width
        _height = (GLfloat) size.height
        _depth = (GLfloat) size.depth
        _updated = true
        mutex.unlock()

        if scene is not null
            scene.stepLock.writer_lock()
        ((geoms.Box) self.geom).SetLengths((Real) _width,
                                           (Real) _height,
                                           (Real) _depth)
        if scene is not null
            scene.stepLock.writer_unlock()

    def _size_weak(size : Object)
        _size_obj = null

    prop size : soy.atoms.Size
        owned get
            value : soy.atoms.Size? = self._size_obj
            if value is null
                value = new soy.atoms.Size((float) _width,
                                           (float) _height,
                                           (float) _depth)
                value.on_set.connect(self._size_set)
                value.weak_ref(self._size_weak)
                self._size_obj = value
            return value
        set
            self._size_set(value)
            _size_obj = value
            value.on_set.connect(self._size_set)
            value.weak_ref(self._size_weak)


    ////////////////////////////////////////////////////////////////////////
    // Methods

    def override pointDepth (x : float, y : float, z : float) : float
        return (float) ((geoms.Box) self.geom).PointDepth((Real) x, (Real) y,
                                                          (Real) z)


    // TODO modify for bisection
    def override volume ( ) : float
        return (self._width * self._height * self._depth)


    def override render ( )
        i : int = 0

        // save current matrix
        glMatrixMode(GL_MODELVIEW)
        glPushMatrix()

        // Lock so body can't be changed during render
        mutex.lock()

        // set modelview matrix
        self.mult_model_matrix()

        // Update ebo/vbo as needed
        if _updated
            _update_box()

        // Re-bind buffers when not updating
        else
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo)
            glBindBuffer(GL_ARRAY_BUFFER, _vbo)

        glVertexPointer(3, GL_FLOAT, (GLsizei) (sizeof(GLfloat) * 11), null)
        glNormalPointer(   GL_FLOAT, (GLsizei) (sizeof(GLfloat) * 11),
                        (GLvoid*) (sizeof(GLfloat) * 3))

        // Render
        while self._material.render(i, null)
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (GLvoid*) 0)
            i += 1

        // Rendering done, unlock
        mutex.unlock()

        // Restore matrix
        glMatrixMode(GL_MODELVIEW)
        glPopMatrix()


    def _update_box()
        ///////////////////////////////////////////////////////////////////////
        // Currently:
        //    v6----- v5
        //   /|      /|
        //  v1------v0|
        //  | |     | |
        //  | |v7---|-|v4
        //  |/      |/
        //  v2------v3
        //
        // Box Unfolding
        // TODO Current code needs to reflect this
        //
        //                    C--------A                 +y
        //                    | +z     |                 |
        //                    | |      |                 |____+x
        //                    | |___+x |                 /
        //                    |  top   |              +z/     E-------G
        //  A--------C--------E--------G--------A            /|      /|
        //  | +y     | +y     | +y     | +y     |           C-------A |
        //  | |      | |      | |      | |      |           | |     | |
        //  | |___-x | |___-z | |___+x | |___+z |           | F-----|-H
        //  |  front |  left  |  back  |  right |           |/      |/
        //  B--------D--------F--------H--------B           D-------B
        //         .          | -z     |
        //        /|\         | |      |
        //         |          | |___+x |
        //         |          | bottom |
        //      Tangent       D--------B
        //
        // Each side needs its own vertices for correct 2d texcoords.
        //
        // Cubemaps use vertex positions, while 2d textures use specified
        // (tx, ty) values for each face, but both use the same tangent values
        // for bumpmapping. As a result the box must be laid out as above
        // with 2d texcoords starting at (0,0) at lower left for each face.
        // Ie, for face CDEF, C=(0,1), D=(0,0), E=(1,1), F=(0,1)

        // on first pass
        if _ebo == 0
            glGenBuffers(1, out _ebo)
            glGenBuffers(1, out _vbo)

        // calculate half values since box is centered around 0, 0, 0
        width : GLfloat = _width/2
        height : GLfloat = _height/2
        depth : GLfloat = _depth/2

        // index array of vertex array
        elements : array of GLubyte = {
             0, 1, 2,   2, 3, 0,      // front
             4, 5, 6,   6, 7, 4,      // right
             8, 9,10,  10,11, 8,      // top
             12,13,14,  14,15,12,     // left
             16,17,18,  18,19,16,     // bottom
             20,21,22,  22,23,20 }    // back

        // interleaved (vertex, normal, texcoord) array
        vertices : array of GLfloat = {
            //    position           normal  texcoord  tangent
            //  px,     py,    pz,  nx,ny,nz,  tx,ty,  ux,uy,uz,
             width, height, depth,   0, 0, 1,   1, 1,   0, 0, 0, // v0 (front)
            -width, height, depth,   0, 0, 1,   0, 1,   0, 0, 0, // v1
            -width,-height, depth,   0, 0, 1,   0, 0,   0, 0, 0, // v2
             width,-height, depth,   0, 0, 1,   1, 0,   0, 0, 0, // v3

             width, height, depth,   1, 0, 0,   0, 1,   0, 0, 0, // v0 (right)
             width,-height, depth,   1, 0, 0,   0, 0,   0, 0, 0, // v3
             width,-height,-depth,   1, 0, 0,   1, 0,   0, 0, 0, // v4
             width, height,-depth,   1, 0, 0,   1, 1,   0, 0, 0, // v5

             width, height, depth,   0, 1, 0,   1, 0,   0, 0, 0, // v0 (top)
             width, height,-depth,   0, 1, 0,   1, 1,   0, 0, 0, // v5
            -width, height,-depth,   0, 1, 0,   0, 1,   0, 0, 0, // v6
            -width, height, depth,   0, 1, 0,   0, 0,   0, 0, 0, // v1

            -width, height, depth,  -1, 0, 0,   1, 1,   0, 0, 0, // v1 (left)
            -width, height,-depth,  -1, 0, 0,   0, 1,   0, 0, 0, // v6
            -width,-height,-depth,  -1, 0, 0,   0, 0,   0, 0, 0, // v7
            -width,-height, depth,  -1, 0, 0,   1, 0,   0, 0, 0, // v2

            -width,-height,-depth,   0,-1, 0,   0, 0,   0, 0, 0, // v7 (bottom)
             width,-height,-depth,   0,-1, 0,   1, 0,   0, 0, 0, // v4
             width,-height, depth,   0,-1, 0,   1, 1,   0, 0, 0, // v3
            -width,-height, depth,   0,-1, 0,   0, 1,   0, 0, 0, // v2

             width,-height,-depth,   0, 0,-1,   0, 0,   0, 0, 0, // v4 (back)
            -width,-height,-depth,   0, 0,-1,   1, 0,   0, 0, 0, // v7
            -width, height,-depth,   0, 0,-1,   1, 1,   0, 0, 0, // v6
             width, height,-depth,   0, 0,-1,   0, 1,   0, 0, 0} // v5

        // bind elements
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo)
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36, elements, GL_STATIC_DRAW)

        // bind vertices
        glBindBuffer(GL_ARRAY_BUFFER, _vbo)
        glBufferData(GL_ARRAY_BUFFER, (GLsizei) (264 * sizeof(GLfloat)),
                     vertices, GL_STATIC_DRAW)

        // Reset updated flag
        _updated = false

