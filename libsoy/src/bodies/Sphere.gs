/*
 *  libsoy - soy.bodies.Sphere
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
    GLib.Math
    ode
    soy.atoms

class soy.bodies.Sphere : soy.bodies.Body

    construct (position : soy.atoms.Position?, radius : float,
               material : soy.materials.Material?)
        super(position, null, radius)

        // Set default material
        if material is null
            if default_material is null
                default_material = new soy.materials.Material()
            self.material = default_material

        // Use the provided material
        else
            self.material = material


    def override create_geom (geom_param : Object?, geom_scalar : float)
        _radius = geom_scalar
        _subdivisions = 120
        geom = new ode.geoms.Sphere(null, (Real) _radius)
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
    // Radius Property
    _radius  : GLfloat
    prop radius : float
        get
            return self._radius
        set
            if scene is not null
                scene.stepLock.writer_lock()
            self._radius = value
            ((geoms.Sphere) self.geom).SetRadius((Real) value)
            if scene is not null
                scene.stepLock.writer_unlock()

    //
    // subdivisions Property
    _subdivisions : uint
    prop subdivisions : uint
        get
            return self._subdivisions
        set
            self._subdivisions = value

    ////////////////////////////////////////////////////////////////////////
    // Methods

    /*def override pointDepth(x : float, y : float, z : float) : float
        return (float) ((geoms.Sphere) self.geom).PointDepth((Real) x, (Real) y,
                                                           (Real) z)
    */

    // TODO modify for bisection
    def override volume() : float
        return (float) (4 / 3 * Math.pow(self._radius, 3) * 3.1416)


    def override render ( )
        i : int = 0

        // save current matrix
        glMatrixMode(GL_MODELVIEW)
        glPushMatrix()

        // Lock against changes during render
        mutex.lock()

        // set model's matrix
        self.mult_model_matrix()

        while self._material.render(i, null)
            // TODO these need texcoords
            // TODO use a VBO, please!
            self._sphere(self._radius, (GLint) self.subdivisions,
                         (GLint) self.subdivisions)
            i += 1

        // Release lock
        mutex.unlock()

        // Restore matrix
        glMatrixMode(GL_MODELVIEW)
        glPopMatrix()


    // TODO: textures, use VBO instead vertex array and buffer it better
    def _sphere(radius : GLfloat, slices : GLint, stacks : GLint)
        ///////////////////////////////////////////////////////////////////////
        //
        // (example with CACHE_SIZE = 5)
        //
        //  Front View:
        //
        //             ,O,
        //           ,'/| ',
        //         ,' / |   ',
        //       ,'  / ,O--,  ',
        //     ,'   /,' | ','--,',
        //   ,'    /'   |   ',  '--,
        //  O-----O-----O-----O-----O
        //   '--,  ',   |   ,/    ,'
        //     ','--,', | ,'/   ,'
        //       ',  '--O' /  ,'
        //         ',   | / ,'
        //           ', |/,'
        //             'O'
        //
        //  Top View:
        //
        //          _,,-O-,,_
        //       ,-'    |    '-,
        //      O-------O-------O
        //     /    _,-'|     ,' \
        //    / _,-'    |  ,-'    \
        //   ;-'        |,'        \
        //  O-----------O-----------O
        //   \        ,'|       _,-;
        //    \    ,-'  |   _,-'  /
        //     \ ,'     |,-'     /
        //      O-------O-------O
        //       '-,_   |   _,-'
        //           ''-O-''
        //
        // In this case, there are 4 slices, and 4 stacks.

        CACHE_SIZE : GLuint = 240
        // sin,cos of slices
        var sinCache1a = new array of GLfloat[CACHE_SIZE]
        var cosCache1a = new array of GLfloat[CACHE_SIZE]
        // sin,cos of slices
        var sinCache2a = new array of GLfloat[CACHE_SIZE]
        var cosCache2a = new array of GLfloat[CACHE_SIZE]
        // unused caches
        var sinCache3a = new array of GLfloat[CACHE_SIZE]
        var cosCache3a = new array of GLfloat[CACHE_SIZE]
        // sin,cos of stacks multiplied by radius, used for vertices
        var sinCache1b = new array of GLfloat[CACHE_SIZE]
        var cosCache1b = new array of GLfloat[CACHE_SIZE]
        // sin,cos of stacks
        var sinCache2b = new array of GLfloat[CACHE_SIZE]
        var cosCache2b = new array of GLfloat[CACHE_SIZE]
        // unused caches
        var sinCache3b = new array of GLfloat[CACHE_SIZE]
        var cosCache3b = new array of GLfloat[CACHE_SIZE]
        // temporary values
        zLow, zHigh : GLfloat
        var sintemp1 = 0.0f
        var sintemp2 = 0.0f
        var sintemp3 = 0.0f
        var sintemp4 = 0.0f
        var costemp3 = 0.0f
        var costemp4 = 0.0f

        vertices : array of GLfloat[(CACHE_SIZE+1)*2, 3] = new array of GLfloat[(CACHE_SIZE+1)*2, 3]
        normals : array of GLfloat[(CACHE_SIZE+1)*2, 3] = new array of GLfloat[(CACHE_SIZE+1)*2, 3]
        /* print "slices: %d, stacks: %d, radius: %f", slices,stacks,radius */
        /* print "CACHE_SIZE: %d",(GLint)(CACHE_SIZE - 1) */

        // limit the number of slices and stacks to the cache size
        if slices >= CACHE_SIZE
            slices = (GLint)(CACHE_SIZE - 1)
        if stacks >= CACHE_SIZE
            stacks = (GLint)(CACHE_SIZE - 1)
        /* print "slices: %d, stacks: %d, radius: %f", slices,stacks,radius */

        // Make sure the sphere is valid (not degenerate, nonnegative radius)
        assert(slices>=2 && stacks>=1 && radius>=0.0)

        // Generate caches
        for var i=0 to (slices-1)
            var angle = 2.0f * PI * i / slices
            // sin,cos caches for slice angles (around z-axis)
            sinCache1a[i] = (GLfloat) sin(angle)
            cosCache1a[i] = (GLfloat) cos(angle)

            sinCache2a[i] = sinCache1a[i]
            cosCache2a[i] = cosCache1a[i]

        for var j=0 to (stacks-1)
            var angle = PI * j / stacks
            // sin,cos caches for stack angles (around x or y-axis)
            sinCache2b[j] = (GLfloat) sin(angle)
            cosCache2b[j] = (GLfloat) cos(angle)

            sinCache1b[j] = (GLfloat) (radius * sin(angle))
            cosCache1b[j] = (GLfloat) (radius * cos(angle))

        sinCache1b[0] = 0
        sinCache1b[stacks] = 0

        // unused generated caches
        for var i=0 to (slices-1)
            var angle = 2.0f * PI * (i - 0.5f) / slices
            sinCache3a[i] = (GLfloat) sin(angle)
            cosCache3a[i] = (GLfloat) cos(angle)

        for var j=0 to stacks
            var angle = PI * (j - 0.5f) / stacks
            sinCache3b[j] = (GLfloat) sin(angle)
            cosCache3b[j] = (GLfloat) cos(angle)

        // Make the caches start and end at the same value
        sinCache1a[slices] = sinCache1a[0]
        cosCache1a[slices] = cosCache1a[0]
        sinCache2a[slices] = sinCache2a[0]
        cosCache2a[slices] = cosCache2a[0]
        sinCache3a[slices] = sinCache3a[0]
        cosCache3a[slices] = cosCache3a[0]

        // Enable arrays
        glEnableClientState(GL_VERTEX_ARRAY)
        glVertexPointer(3, GL_FLOAT, 0, vertices)

        glDisableClientState(GL_TEXTURE_COORD_ARRAY)
        glEnableClientState(GL_NORMAL_ARRAY)
        glNormalPointer(GL_FLOAT, 0, normals)

        // indexes for middle stacks
        var start = 1
        var finish = stacks-1

        // Draw the front end cap
        //
        //  Top View:
        //
        //              Center ------,
        //              .            |
        //              .            | zHigh
        //              .            |
        //      O-------O-------O ---'
        //       '-,_   |   _,-'
        //           ''-O-''
        //
        //              |-------|
        //               sintemp2
        //
        sintemp2 = sinCache1b[1] // radius of the end cap
        zHigh = cosCache1b[1] // depth of the end cap
        sintemp3 = sinCache2b[1] // normalized radius
        costemp3 = cosCache2b[1] // normalized depth

        // front vertex
        normals[0,0] = sinCache2a[0] * sinCache2b[0] // 0.0f
        normals[0,1] = cosCache2a[0] * sinCache2b[0] // 0.0f
        normals[0,2] = cosCache2b[0] // 1.0f

        vertices[0,0] = 0.0f
        vertices[0,1] = 0.0f
        vertices[0,2] = radius

        // generate cap
        for var i=0 to slices
            normals[slices-i+1,0] = sinCache2a[i] * sintemp3
            normals[slices-i+1,1] = cosCache2a[i] * sintemp3
            normals[slices-i+1,2] = costemp3

            vertices[slices-i+1,0] = sintemp2 * sinCache1a[i]
            vertices[slices-i+1,1] = sintemp2 * cosCache1a[i]
            vertices[slices-i+1,2] = zHigh

        glDrawArrays(GL_TRIANGLE_FAN, 0, (slices+2))

        // Draw the back end cap
        //
        //  Top View:
        //
        //               sintemp2
        //              |-------|
        //
        //          _,,-O-,,_
        //       ,-'    |    '-,
        //      O-------O-------O ----,
        //              .             |
        //              .             | zHigh
        //              .             |
        //              Center -------'
        //
        sintemp2 = sinCache1b[stacks-1] // radius of the end cap
        zHigh = cosCache1b[stacks-1] // depth of the end cap
        sintemp3 = sinCache2b[stacks-1] // normalized radius
        costemp3 = cosCache2b[stacks-1] // normalized depth

        // back vertex
        normals[0,0] = sinCache2a[stacks] * sinCache2b[stacks] // 0.0f
        normals[0,1] = cosCache2a[stacks] * sinCache2b[stacks] // 0.0f
        normals[0,2] = cosCache2b[stacks] // 0.0f (uninitialized?)

        vertices[0,0] = 0.0f
        vertices[0,1] = 0.0f
        vertices[0,2] = -radius

        // generate cap
        for var i=0 to slices
            normals[i+1,0] = sinCache2a[i] * sintemp3
            normals[i+1,1] = cosCache2a[i] * sintemp3
            normals[i+1,2] = costemp3

            vertices[i+1,0] = sintemp2 * sinCache1a[i]
            vertices[i+1,1] = sintemp2 * cosCache1a[i]
            vertices[i+1,2] = zHigh

        glDrawArrays(GL_TRIANGLE_FAN, 0, (slices+2))

        // Draw the middle stacks
        //
        //  Top View (not CACHE_SIZE = 5):
        //
        //
        //              Center ----------, ------,
        //              .                |       |
        //              .                | zHigh |
        //              .                |       |
        //  O-----------O-----------O ---'       | zLow
        //   \        ,'|       _,-;             |
        //    \    ,-'  |   _,-'  /              |
        //     \ ,'     |,-'     /               |
        //      O-------O-------O ---------------'
        //
        //              |-------|
        //               sintemp1
        //
        //              |-----------|
        //                sintemp2
        //
        for var j=start to (finish-1)
            zLow = cosCache1b[j] // front depth of stack
            zHigh = cosCache1b[j+1] // back depth of stack
            sintemp1 = sinCache1b[j] // front radius of stack
            sintemp2 = sinCache1b[j+1] // back radius of stack

            sintemp3 = sinCache2b[j+1] // normalized back radius
            costemp3 = cosCache2b[j+1] // normalized back depth
            sintemp4 = sinCache2b[j] // normalized front radius
            costemp4 = cosCache2b[j] // normalized front depth

            // normals and vertices for one stack
            for var i=0 to slices
                // back ring of vertices
                normals[i*2,0] = sinCache2a[i]*sintemp3
                normals[i*2,1] = cosCache2a[i]*sintemp3
                normals[i*2,2] = costemp3

                vertices[i*2,0] = sintemp2*sinCache1a[i]
                vertices[i*2,1] = sintemp2*cosCache1a[i]
                vertices[i*2,2] = zHigh

                // front ring of vertices
                normals[i*2+1,0] = sinCache2a[i]*sintemp4
                normals[i*2+1,1] = cosCache2a[i]*sintemp4
                normals[i*2+1,2] = costemp4

                vertices[i*2+1,0] = sintemp1*sinCache1a[i]
                vertices[i*2+1,1] = sintemp1*cosCache1a[i]
                vertices[i*2+1,2] = zLow

            glDrawArrays(GL_TRIANGLE_STRIP, 0, (slices+1)*2)

        // Disable or re-enable arrays
        glDisableClientState(GL_VERTEX_ARRAY)
        glDisableClientState(GL_NORMAL_ARRAY)

