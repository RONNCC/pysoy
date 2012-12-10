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
        radius : GLfloat = (GLfloat) 0.025

        // distance in (x, y) plane is width
        width : GLfloat = sqrtf((posB.x - posA.x) * (posB.x - posA.x) +
                                (posB.y - posA.y) * (posB.y - posA.y)) / 2

        // distance in (y, z) plane is height
        height : GLfloat = (GLfloat) 0.150 - radius

        // distance in (x, z) plane is depth
        depth : GLfloat = (GLfloat) 0.150 - radius

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
             width, height, depth,   0, 0, 1,    1, 1,    0, 1, 0, // front
            -width, height, depth,   0, 0, 1,    0, 1,    0, 1, 0,
            0     , 0     , depth,   0, 0, 1,    (GLfloat) 0.5, (GLfloat) 0.5,    0, 1, 0
            -width,-height, depth,   0, 0, 1,    0, 0,    0, 1, 0,
             width,-height, depth,   0, 0, 1,    1, 0,    0, 1, 0,

             width, height, depth,   0, 1, 0,    1, 0,    0, 0,-1, // top
             width, height,-depth,   0, 1, 0,    1, 1,    0, 0,-1,
             0,     height, 0    ,   0, 1, 0,    (GLfloat) 0.5, (GLfloat) 0.5,    0, 0,-1,
            -width, height,-depth,   0, 1, 0,    0, 1,    0, 0,-1,
            -width, height, depth,   0, 1, 0,    0, 0,    0, 0,-1,

            -width,-height,-depth,   0,-1, 0,    0, 1,    0, 0, 1,// bottom
             width,-height,-depth,   0,-1, 0,    1, 1,    0, 0, 1,
             0    ,-height, 0    ,   0,-1, 0,    (GLfloat) 0.5, (GLfloat) 0.5,    0, 0, 1,
             width,-height, depth,   0,-1, 0,    1, 0,    0, 0, 1,
            -width,-height, depth,   0,-1, 0,    0, 0,    0, 0, 1,

             width,-height,-depth,   0, 0,-1,    1, 0,    0,-1, 0, // back
            -width,-height,-depth,   0, 0,-1,    0, 0,    0,-1, 0,
            0     , 0     ,-depth,   0, 0,-1,    (GLfloat) 0.5, (GLfloat) 0.5,    0,-1,0,
            -width, height,-depth,   0, 0,-1,    0, 1,    0,-1, 0,
             width, height,-depth,   0, 0,-1,    1, 1,    0,-1, 0,

             -width, height, depth,  0, 0, 1,    0, 0,    0, 1, 0,
             -width, (GLfloat) (height + radius * sin(11.25)), (GLfloat) (depth + radius*cos(11.25)), 0, (GLfloat) (sin(11.25)), (GLfloat) (cos(11.25)), 0, 0,    0, (GLfloat) sin(-78.75), (GLfloat) cos(-78.75),
             -width, (GLfloat) (height + radius * sin(22.5)),(GLfloat) (depth + radius*cos(22.5)), 0, (GLfloat) (sin(22.5)), (GLfloat) (cos(22.5)),      0, 0,    0, (GLfloat) sin(-67.5), (GLfloat) cos(-67.5),
             -width, (GLfloat) (height + radius * sin(33.75)), (GLfloat) (depth + radius*cos(33.75)), 0, (GLfloat) (sin(33.75)), (GLfloat) (cos(33.75)), 0, 0,    0, (GLfloat) sin(-56.25), (GLfloat) cos(-56.25),
             -width, (GLfloat) (height + radius * sin(45)), (GLfloat) (depth + radius*cos(45)), 0, (GLfloat) (sin(45)), (GLfloat) (cos(45)),             0, 0,    0, (GLfloat) sin(-45), (GLfloat) cos(-45),

             -width,-height, depth,  0, 0, 1,    0, 0,    0, 1, 0
             -width,(GLfloat) (-height + radius * sin(11.25)), (GLfloat) (depth + radius*cos(11.25)), 0, (GLfloat) (sin(11.25)), (GLfloat) (cos(11.25)),0, 0,    0, (GLfloat) sin(-78.75), (GLfloat) cos(-78.75),
             -width,(GLfloat) (-height + radius * sin(22.5)), (GLfloat) (depth + radius*cos(22.5)), 0, (GLfloat) (sin(22.5)), (GLfloat) (cos(22.5)),    0, 0,    0, (GLfloat) sin(-67.5), (GLfloat) cos(-67.5),
             -width,(GLfloat) (-height + radius * sin(33.75)), (GLfloat) (depth + radius*cos(33.75)), 0, (GLfloat) (sin(33.75)), (GLfloat) (cos(33.75)),0, 0,    0, (GLfloat) sin(-56.25), (GLfloat) cos(-56.25),
             -width,(GLfloat) (-height + radius * sin(45)), (GLfloat) (depth + radius*cos(45)), 0, (GLfloat) (sin(45)), (GLfloat) (cos(45)),            0, (GLfloat) 0.75,    0, (GLfloat) sin(-45), (GLfloat) cos(-45),

              width, height, depth,  0, 0, 1,    0, 0,    0, 1, 0,
              width, (GLfloat) (height + radius * sin(11.25)), (GLfloat) (depth + radius*cos(11.25)), 0, (GLfloat) (sin(11.25)), (GLfloat) (cos(11.25)),0, 0,    0, (GLfloat) sin(-78.75), (GLfloat) cos(-78.75),
              width, (GLfloat) (height + radius * sin(22.5)), (GLfloat) (depth + radius*cos(22.5)), 0, (GLfloat) (sin(22.5)), (GLfloat) (cos(22.5)),    0, 0,    0, (GLfloat) sin(-67.5), (GLfloat) cos(-67.5),
              width, (GLfloat) (height + radius * sin(33.75)), (GLfloat) (depth + radius*cos(33.75)), 0, (GLfloat) (sin(33.75)), (GLfloat) (cos(33.75)),0, 0,    0, (GLfloat) sin(-56.25), (GLfloat) cos(-56.25),
              width, (GLfloat) (height + radius * sin(45)), (GLfloat) (depth + radius*cos(45)), 0, (GLfloat) (sin(45)), (GLfloat) (cos(45)), 0, (GLfloat) 0.25,    0, (GLfloat) sin(-45), (GLfloat) cos(-45),

              width,-height, depth,  0, 0, 1,    0, 0,    0, 1, 0,
              width,(GLfloat) (-height + radius * sin(11.25)), (GLfloat) (depth + radius*cos(11.25)), 0, (GLfloat) (sin(11.25)), (GLfloat) (cos(11.25)),0, 0,    0, (GLfloat) sin(-78.75), (GLfloat) cos(-78.75),
              width,(GLfloat) (-height + radius * sin(22.5)), (GLfloat) (depth + radius*cos(22.5)), 0, (GLfloat) (sin(22.5)), (GLfloat) (cos(22.5)),    0, 0,    0, (GLfloat) sin(-67.5), (GLfloat) cos(-67.5),
              width,(GLfloat) (-height + radius * sin(33.75)), (GLfloat) (depth + radius*cos(33.75)), 0, (GLfloat) (sin(33.75)), (GLfloat) (cos(33.75)),0, 0,    0, (GLfloat) sin(-56.25), (GLfloat) cos(-56.25),
              width,(GLfloat) (-height + radius * sin(45)), (GLfloat) (depth + radius*cos(45)), 0, (GLfloat) (sin(45)), (GLfloat) (cos(45)),            0, (GLfloat) 0.5,    0, (GLfloat) sin(-45), (GLfloat) cos(-45)
        }

        // bind elements
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo)
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 96, elements, GL_STATIC_DRAW)

        // bind vertices
        glBindBuffer(GL_ARRAY_BUFFER, _vbo)
        glBufferData(GL_ARRAY_BUFFER, (GLsizei) (440 * sizeof(GLfloat)),
                     vertices, GL_STATIC_DRAW)

        _updated = false

