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
        _jointMtx = new array of GLfloat[16]

        mutex.lock()
        posA : unowned ode.Vector3 = bodyA.body.GetPosition()
        posB : unowned ode.Vector3 = bodyB.body.GetPosition()

        posAMag : ode.Real = (ode.Real) sqrt(posA.x*posA.x + 
                                             posA.y*posA.y +
                                             posA.z*posA.z)

        normA : ode.Vector3 = new ode.Vector3()
        normA.x = posA.x / posAMag
        normA.y = posA.y / posAMag
        normA.z = posA.z / posAMag

        direction : ode.Vector3 = new ode.Vector3()
        direction.x = posA.x + posB.x
        direction.y = posA.y + posB.y
        direction.z = posA.z + posB.z

        relDirection : ode.Vector3 = new ode.Vector3()
        bodyA.body.GetRelPointPos(direction.x, direction.y, direction.z, relDirection)
        relMag : ode.Real = (ode.Real) sqrt(relDirection.x*relDirection.x +
                                            relDirection.y*relDirection.y +
                                            relDirection.z*relDirection.z)

        relDirection.x /= relMag
        relDirection.y /= relMag
        relDirection.z /= relMag
        print "%f, %f, %f", relDirection.x, relDirection.y, relDirection.z

        angle : ode.Real = (ode.Real) acos(normA.x*relDirection.x +
                                           normA.y*relDirection.y +
                                           normA.z*relDirection.z)

        axisX : ode.Real = (ode.Real) (posA.y*relDirection.z - posA.z*relDirection.y)
        axisY : ode.Real = (ode.Real) (posA.z*relDirection.x - posA.x*relDirection.z)
        axisZ : ode.Real = (ode.Real) (posA.x*relDirection.y - posA.y*relDirection.x)

        length : ode.Real = (ode.Real) sqrt(
            axisX * axisX + axisY * axisY + axisZ * axisZ)

        normX : ode.Real = (ode.Real) axisX / length
        normY : ode.Real = (ode.Real) axisY / length
        normZ : ode.Real = (ode.Real) axisZ / length

        print "axisX: %f", axisX
        print "axisY: %f", axisY
        print "axisZ: %f", axisZ

        jointRotation : ode.Matrix3 = new ode.Matrix3()

        jointRotation.FromAxisAndAngle(normX, normY, normZ, angle)

        _jointMtx[0]  = (GLfloat) jointRotation.m0
        _jointMtx[1]  = (GLfloat) jointRotation.m4
        _jointMtx[2]  = (GLfloat) jointRotation.m8
        _jointMtx[3]  = (GLfloat) 0.0
        _jointMtx[4]  = (GLfloat) jointRotation.m1
        _jointMtx[5]  = (GLfloat) jointRotation.m5
        _jointMtx[6]  = (GLfloat) jointRotation.m9
        _jointMtx[7]  = (GLfloat) 0.0
        _jointMtx[8]  = (GLfloat) jointRotation.m2
        _jointMtx[9]  = (GLfloat) jointRotation.m6
        _jointMtx[10] = (GLfloat) jointRotation.ma
        _jointMtx[11] = (GLfloat) 0.0
        _jointMtx[12] = (GLfloat) 0.0
        _jointMtx[13] = (GLfloat) 0.0
        _jointMtx[14] = (GLfloat) 0.0
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
        rotationA : unowned ode.Matrix3 = bodyA.body.GetRotation()
        positionA : unowned ode.Vector3 = bodyA.body.GetPosition()

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
        _mtx[12] = (GLfloat) positionA.x
        _mtx[13] = (GLfloat) positionA.y
        _mtx[14] = (GLfloat) positionA.z
        _mtx[15] = (GLfloat) 1.0

        glMultMatrixf(_mtx)
        //glMultMatrixf(_jointMtx)
    
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
