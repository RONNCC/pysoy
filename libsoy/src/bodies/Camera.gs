/*
 *  libsoy - soy.bodies.Camera
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
    soy
    soy.atoms

class soy.bodies.Camera : soy.bodies.Body
    _znear : GLfloat
    _zfar  : GLfloat


    /*
    construct (scene : soy.scenes.Scene)
        super(scene)
        _lens = 45.0f
        _znear = 1.0f
        _zfar  = 100.0f
        body.SetGravityMode(0)
    */

    init
        _lens = 45.0f
        _znear = 1.0f
        _zfar  = 100.0f


    construct (position : soy.atoms.Position?)
        super(position, null, 0.0f)


    //prop wireframe

    //prop lens
    _lens  : GLfloat
    prop lens : float
        get
            return self._lens
        set
            // TODO test value to ensure it won't crash something
            self._lens = value


    //prop direction

    //prop right

    //prop up

    def project (aspect : GLfloat)
        if(scene is null)
            return

        mtx : array of GLfloat[16] = new array of GLfloat[16]
        rot : weak ode.Matrix3 = self.body.GetRotation()
        pos : weak ode.Vector3 = self.body.GetPosition()
        glMatrixMode (GL_MODELVIEW)
        glLoadIdentity ()

        mtx[0]  = (GLfloat) rot.m0
        mtx[1]  = (GLfloat) rot.m1
        mtx[2]  = (GLfloat) rot.m2
        mtx[3]  = 0.0f
        mtx[4]  = (GLfloat) rot.m4
        mtx[5]  = (GLfloat) rot.m5
        mtx[6]  = (GLfloat) rot.m6
        mtx[7]  = 0.0f
        mtx[8]  = (GLfloat) rot.m8
        mtx[9]  = (GLfloat) rot.m9
        mtx[10] = (GLfloat) rot.ma
        mtx[11] = 0.0f
        mtx[12] = 0.0f
        mtx[13] = 0.0f
        mtx[14] = 0.0f
        mtx[15] = 1.0f

        glLoadMatrixf (mtx)
        glTranslatef (-(GLfloat) pos.x, -(GLfloat) pos.y, -(GLfloat) pos.z)

        self.scene.render(self._lens, aspect, self._znear, self._zfar)

