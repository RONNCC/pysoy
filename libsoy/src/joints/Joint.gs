/*
 *  libsoy - soy.joints.Joint
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
    soy.atoms
    GL
    ode
    GLib.Math

class soy.joints.Joint : Object
    joint : ode.joints.Joint
    scene : weak soy.scenes.Scene
    bodyA : weak soy.bodies.Body
    bodyB : weak soy.bodies.Body?
    mutex : Mutex
    _jointMtx : array of GLfloat

    init
        // ensures that vbos and materials do not change while joint is rendered
        mutex = Mutex()

    construct(scene : soy.scenes.Scene, bodyA : soy.bodies.Body,
              bodyB : soy.bodies.Body?, anchor : soy.atoms.Position?,
              axis1 : soy.atoms.Axis?, axis2 : soy.atoms.Axis?,
              material : soy.materials.Material?)
        self.scene = scene
        self.bodyA = bodyA
        self.bodyB = bodyB
        mutex.lock()
        _jointMtx = new array of GLfloat[16]

        rotation : ode.Matrix3 = new ode.Matrix3()

        posA : unowned ode.Vector3 = bodyA.body.GetPosition()
        posB : unowned ode.Vector3 = bodyB.body.GetPosition()

        thetaXY : ode.Real = (ode.Real) atan2(posB.y - posA.y, posB.x - posA.x)
        thetaYZ : ode.Real = (ode.Real) atan2(posB.z - posA.z, posB.y - posA.y)
        thetaXZ : ode.Real = (ode.Real) atan2(posB.z - posA.z, posB.x - posA.x)

        // (y, z), (x, z),(x, y)
        rotation.FromEulerAngles(thetaYZ, thetaXZ, thetaXY)

        _jointMtx[0]  = (GLfloat) rotation.m0
        _jointMtx[1]  = (GLfloat) rotation.m4
        _jointMtx[2]  = (GLfloat) rotation.m8
        _jointMtx[3]  = (GLfloat) 0.0
        _jointMtx[4]  = (GLfloat) rotation.m1
        _jointMtx[5]  = (GLfloat) rotation.m5
        _jointMtx[6]  = (GLfloat) rotation.m9
        _jointMtx[7]  = (GLfloat) 0.0
        _jointMtx[8]  = (GLfloat) rotation.m2
        _jointMtx[9]  = (GLfloat) rotation.m6
        _jointMtx[10] = (GLfloat) rotation.ma
        _jointMtx[11] = (GLfloat) 0.0
        _jointMtx[12] = (GLfloat) (((posA.x + posB.x) / 2) - posA.x)
        _jointMtx[13] = (GLfloat) (((posA.y + posB.y) / 2) - posA.y)
        _jointMtx[14] = (GLfloat) (((posA.z + posB.z) / 2) - posA.z)
        _jointMtx[15] = (GLfloat) 1.0

        mutex.unlock()

        if material is null
            if default_material is null
                default_material = new soy.materials.Material()
            self.material = default_material

        else
            self.material = material

        // Lock scene until were done
        scene.stepLock.writer_lock()

        // Create joint
        self.create()

        // Store a ref to self it ODE joint
        joint.SetData((void*) self)

        // Attach joint to body/ies
        if bodyB == null
            joint.Attach(bodyA.body, null)
        else
            joint.Attach(bodyA.body, bodyB.body)

        // Setup joint
        self.setup(anchor, axis1, axis2)

        // add self to scenes for rendering
        scene.joints.add(self)

        // Unlock scene
        scene.stepLock.writer_unlock()

    def virtual create ( )
        self.joint = new ode.joints.Joint(scene.world, null)


    def virtual setup (anchor : soy.atoms.Position?, axis1 : soy.atoms.Axis?,
                       axis2 : soy.atoms.Axis?)
        return

    def virtual render ( )
        return

    def virtual mult_model_matrix( )
        var _mtx = new array of GLfloat[16]
        posA : unowned ode.Vector3 = bodyA.body.GetPosition()
        posB : unowned ode.Vector3 = bodyB.body.GetPosition()

        rotationA : unowned ode.Matrix3 = bodyA.body.GetRotation()

        _mtx[0]  = (GLfloat) rotationA.m0
        _mtx[1]  = (GLfloat) rotationA.m4
        _mtx[2]  = (GLfloat) rotationA.m8
        _mtx[3]  = (GLfloat) 0.0
        _mtx[4]  = (GLfloat) rotationA.m1
        _mtx[5]  = (GLfloat) rotationA.m5
        _mtx[6]  = (GLfloat) rotationA.m9
        _mtx[7]  = (GLfloat) 0.0
        _mtx[8]  = (GLfloat) rotationA.m2
        _mtx[9]  = (GLfloat) rotationA.m6
        _mtx[10] = (GLfloat) rotationA.ma
        _mtx[11] = (GLfloat) 0.0
        _mtx[12] = (GLfloat) posA.x
        _mtx[13] = (GLfloat) posA.y
        _mtx[14] = (GLfloat) posA.z
        _mtx[15] = (GLfloat) 1.0

        glMultMatrixf(_mtx)

        glMultMatrixf(_jointMtx)
    
    ////////////////////////////////////////////////////////////////////////
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
