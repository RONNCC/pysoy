/*
 *  libsoy - soy.joints.Fixed
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
    ode
    GL
    soy.atoms
    GLib.Math


class soy.joints.Fixed: soy.joints.Joint
    _ebo : GLuint // element buffer object
    _vbo : GLuint // vertex buffer object
    _updated : bool // are the buffers need updated?

    construct(scene : soy.scenes.Scene, bodyA : soy.bodies.Body,
              bodyB : soy.bodies.Body?, material : soy.materials.Material?)
        super(scene, bodyA, bodyB, null, null, null, material)
        _ebo = 0
        _updated = true


    ////////////////////////////////////////////////////////////////////////
    // Methods

    def override create ( )
        joint = new ode.joints.Fixed(scene.world, null)


    def override setup (anchor : soy.atoms.Position?, axis1 : soy.atoms.Axis?,
                        axis2 : soy.atoms.Axis?)
        ((ode.joints.Fixed) joint).Set()


    def override render ( )
        i : int = 0

        // save current matrix
        glMatrixMode(GL_MODELVIEW)
        glPushMatrix()

        // lock so cant be changed during a render
        mutex.lock()

        // set modelview matrix
        self.mult_model_matrix()

        // update ebo/vbo if its needed
        if _updated
            _update_joint()

        // rebind buffers when not updating
        else
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo)
            glBindBuffer(GL_ARRAY_BUFFER, _vbo)

        glVertexPointer(3, GL_FLOAT, (GLsizei) (sizeof(GLfloat) * 11), null)
        glNormalPointer(   GL_FLOAT, (GLsizei) (sizeof(GLfloat) * 11),
                        (GLvoid*) (sizeof(GLfloat) * 3))

        while self.material.render(i, null)
            glDrawElements(GL_TRIANGLES, 96, GL_UNSIGNED_BYTE, (GLvoid*) 0)
            i += 1

        // unlock mutex for writing, rendering done
        mutex.unlock()

        // restore matrix
        glMatrixMode(GL_MODELVIEW)
        glPopMatrix()

    def _update_joint()
        ///////////////////////////////////////////////////////////////////////
        //    .........
        //   /|      /|
        //  ......... |
        //  | |     | |
        //  | ......|.|.
        //  |/      | /
        //  .........
        //
        //
        // on the first pass
        if _ebo == 0
            glGenBuffers(1, out _ebo)
            glGenBuffers(1, out _vbo)

        posA : soy.atoms.Position = bodyA.position
        posB : soy.atoms.Position = bodyB.position

        // constants to help drawing
        r : GLfloat = 0.0625f   // radius

        // distance in (x, y) plane is xl
        xl : GLfloat = sqrtf((posB.x - posA.x) * (posB.x - posA.x) +
                             (posB.y - posA.y) * (posB.y - posA.y))

        // distance in (y, z) plane is height
        height : GLfloat = 0.250f - r

        // distance in (x, z) plane is depth
        depth : GLfloat = 0.250f - r

        // index array of vertex array
        elements : array of GLubyte = {
            0, 2, 1,    1, 2, 3,    3, 2, 4,    4, 2, 0,      // front
            5, 7, 6,    6, 7, 8,    8, 7, 9,    9, 7, 5,      // top
            10,12,11,   11,12,13,   13,12,14,   14,12,10,     // bottom
            15,17,16,   16,17,18,   18,17,19,   19,17,15,     // back
            20,22,21,   21,22,23,   23,22,24,   24,22,20,
            25,27,26,   26,27,28,   28,27,29,   29,27,25,
            30,32,31,   31,32,33,   33,32,34,   34,32,30,
            35,37,36,   36,37,38,   38,37,39,   39,37,35
        }

        // interleaved (vertex, normals, texcoords, tangents) array
        // (px py pz nx ny nz tx ty ux uy uz) for each vertex
        vertices : array of GLfloat = {
            // front
              xl,  height,  depth,
               0,       0,      1,
               1,       1,
               0,       1,      0,

               0,  height,  depth,
               0,       0,      1,
               0,       1,
               0,       1,      0,

            xl/2,       0,  depth,
               0,       0,      1,
            0.5f,    0.5f,
               0,       1,      0,

               0, -height,  depth,
               0,       0,      1,
               0,       0,
               0,       1,      0,

              xl, -height,  depth,
               0,       0,      1,
               1,       0,
               0,       1,      0,

            // top
              xl,  height,  depth,
               0,       1,      0,
               1,       0,
               0,       0,     -1,

              xl,  height, -depth,
               0,       1,      0,
               1,       1,
               0,       0,     -1,

            xl/2,  height,      0,
               0,       1,      0,
            0.5f,    0.5f,
               0,       0,     -1,

               0,  height, -depth,
               0,       1,      0,
               0,       1,
               0,       0,     -1,

               0,  height,  depth,
               0,       1,      0,
               0,       0,
               0,       0,     -1,

            // bottom
               0, -height, -depth,
               0,      -1,      0,
               0,       1,
               0,       0,      1,

              xl, -height, -depth,
               0,      -1,      0,
               1,       1,
               0,       0,      1,

            xl/2, -height,      0,
               0,      -1,      0,
            0.5f,    0.5f,
               0,       0,      1,

              xl, -height,  depth,
               0,      -1,      0,
               1,       0,
               0,       0,      1,

               0, -height,  depth,
               0,      -1,      0,
               0,       0,
               0,       0,      1,

            // back
              xl, -height, -depth,
               0,       0,     -1,
               1,       0,
               0,      -1,      0,

               0, -height, -depth,
               0,       0,     -1,
               0,       0,
               0,      -1,      0,

            xl/2,       0, -depth,
               0,       0,     -1,
            0.5f,    0.5f,
               0,      -1,      0,

               0,  height, -depth,
               0,       0,     -1,
               0,       1,
               0,      -1,      0,

              xl,  height, -depth,
               0,       0,     -1,
               1,       1,
               0,      -1,      0,

               0,  height,  depth,
               0,       0,      1,
               0,       0,
               0,       1,      0,

               0,  height + r * sinf( 11.25f),  depth + r * cosf( 11.25f),
               0,               sinf( 11.25f),              cosf( 11.25f),
               0,                           0,
               0,               sinf(-78.75f),              cosf(-78.75f),

               0,  height + r * sinf( 22.50f),  depth + r * cosf( 22.50f),
               0,               sinf( 22.50f),              cosf( 22.50f),
               0,                           0,
               0,               sinf(-67.50f),              cosf(-67.50f),

               0,  height + r * sinf( 33.75f),  depth + r * cosf( 33.75f),
               0,               sinf( 33.75f),              cosf( 33.75f),
               0,                           0,
               0,               sinf(-56.25f),              cosf(-56.25f),

               0,  height + r * sinf( 45.00f),  depth + r * cosf( 45.00f),
               0,               sinf( 45.00f),              cosf( 45.00f),
               0,                           0,
               0,               sinf(-45.00f),              cosf(-45.00f),

               0,                     -height,                      depth,
               0,                           0,                          1,
               0,                           0,
               0,                           1,                          0,

               0, -height + r * sinf( 11.25f),  depth + r * cosf( 11.25f),
               0,               sinf( 11.25f),              cosf( 11.25f),
               0,                           0,
               0,               sinf(-78.75f),              cosf(-78.75f),

               0, -height + r * sinf( 22.50f),  depth + r * cosf( 22.50f),
               0,               sinf( 22.50f),              cosf( 22.50f),
               0,                           0,
               0,               sinf(-67.50f),              cosf(-67.50f),

               0, -height + r * sinf( 33.75f),  depth + r * cosf( 33.75f),
               0,               sinf( 33.75f),              cosf( 33.75f),
               0,                           0,
               0,               sinf(-56.25f),              cosf(-56.25f),

               0, -height + r * sinf( 45.00f),  depth + r * cosf( 45.00f),
               0,               sinf( 45.00f),              cosf( 45.00f),
               0,                       0.75f,
               0,               sinf(-45.00f),              cosf(-45.00f),

              xl,                      height,                      depth,
               0,                           0,                          1,
               0,                           0,
               0,                           1,                          0,

              xl,  height + r * sinf( 11.25f),  depth + r * cosf( 11.25f),
               0,               sinf( 11.25f),              cosf( 11.25f),
               0,                           0,
               0,               sinf(-78.75f),              cosf(-78.75f),

              xl,  height + r * sinf( 22.50f),  depth + r * cosf( 22.50f),
               0,               sinf( 22.50f),              cosf( 22.50f),
               0,                           0,
               0,               sinf(-67.50f),              cosf(-67.50f),

              xl,  height + r * sinf( 33.75f),  depth + r * cosf( 33.75f),
               0,               sinf( 33.75f),              cosf( 33.75f),
               0,                           0,
               0,               sinf(-56.25f),              cosf(-56.25f),

              xl,  height + r * sinf( 45.00f),  depth + r * cosf( 45.00f),
               0,               sinf( 45.00f),              cosf( 45.00f),
               0,                       0.25f,
               0,               sinf(-45.00f),              cosf(-45.00f),

              xl,                     -height,                      depth,
               0,                           0,                          1,
               0,                           0,
               0,                           1,                          0,

              xl, -height + r * sinf( 11.25f),  depth + r * cosf( 11.25f),
               0,               sinf( 11.25f),              cosf( 11.25f),
               0,                           0,
               0,               sinf(-78.75f),              cosf(-78.75f),

              xl, -height + r * sinf( 22.50f),  depth + r * cosf( 22.50f),
               0,               sinf( 22.50f),              cosf( 22.50f),
               0,                           0,
               0,               sinf(-67.50f),              cosf(-67.50f),

              xl, -height + r * sinf( 33.75f),  depth + r * cosf( 33.75f),
               0,               sinf( 33.75f),              cosf( 33.75f),
               0,                           0,
               0,               sinf(-56.25f),              cosf(-56.25f),

              xl, -height + r * sinf( 45.00f),  depth + r * cosf( 45.00f),
               0,               sinf( 45.00f),              cosf( 45.00f),
               0,                       0.50f,
               0,               sinf(-45.00f),              cosf(-45.00f)
        }

        // bind elements
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo)
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 96, elements, GL_STATIC_DRAW)

        // bind vertices
        glBindBuffer(GL_ARRAY_BUFFER, _vbo)
        glBufferData(GL_ARRAY_BUFFER, (GLsizei) (440 * sizeof(GLfloat)),
                     vertices, GL_STATIC_DRAW)

        _updated = false

