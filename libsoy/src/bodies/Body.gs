/*
 *  libsoy - soy.bodies.Body
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
    Gee
    GL
    ode
    soy.atoms


class soy.bodies.Body : Object
    body : ode.Body?
    geom : ode.geoms.Geom
    key : string
    mutex : Mutex

    init
        // This is to ensure the VBOs and materials don not change while a Body
        // is being rendered, but allow reading values while being rendered.
        mutex = Mutex()

        // This is intended for use with fields, though currently not used.
        tags_ = new dict of string,float?


    construct (position : soy.atoms.Position?, geom_param : Object?,
               geom_scalar : float)
        self.create_geom(geom_param, geom_scalar)
        if position is not null
            self.position = position


    def virtual create_geom (geom_param : Object?, geom_scalar : float)
        geom = new ode.geoms.Sphere(null, (Real) 1.0)
        geom.Disable() // Because "Ghost" mode doesn't seem to be working
        geom.SetCategoryBits(GeomGhost)
        geom.SetData((void*) self)


    /*
    final
        if self.scene.bodies.contains(self)
            self.scene.stepLock.writer_lock()
            self.scene.bodies.remove(self)
            self.scene.stepLock.writer_unlock()
    */

    //
    // public methods

    //
    // Add forces to bodies (absolute or relative coordinates).
    //
    // The ...RelForce and ...RelTorque functions take force vectors that are
    // relative to the body's own frame of reference.
    // The ...ForceAtPos and ...ForceAtRelPos functions take an extra position
    // vector (in global or body-relative coordinates respectively) that
    // specifies the point at which the force is applied.
    // All other functions apply the force at the center of mass.
    def addForce(fx : ode.Real, fy : ode.Real, fz : ode.Real)
        if scene is null
            return
        scene.stepLock.writer_lock()
        body.AddForce(fx, fy, fz)
        scene.stepLock.writer_unlock()

    def addTorque(fx : ode.Real, fy : ode.Real, fz : ode.Real)
        if scene is null
            return
        scene.stepLock.writer_lock()
        body.AddTorque(fx, fy, fz)
        scene.stepLock.writer_unlock()

    def addRelForce(fx : ode.Real, fy : ode.Real, fz : ode.Real)
        if scene is null
            return
        scene.stepLock.writer_lock()
        body.AddRelForce(fx, fy, fz)
        scene.stepLock.writer_unlock()

    def addRelTorque(fx : ode.Real, fy : ode.Real, fz : ode.Real)
        if scene is null
            return
        scene.stepLock.writer_lock()
        body.AddRelTorque(fx, fy, fz)
        scene.stepLock.writer_unlock()

    def addForceAtPos(fx : ode.Real, fy : ode.Real, fz : ode.Real, px : ode.Real, py : ode.Real, pz : ode.Real)
        if scene is null
            return
        scene.stepLock.writer_lock()
        body.AddForceAtPos(fx, fy, fz, px, py, pz)
        scene.stepLock.writer_unlock()

    def addForceAtRelPos(fx : ode.Real, fy : ode.Real, fz : ode.Real, px : ode.Real, py : ode.Real, pz : ode.Real)
        if scene is null
            return
        scene.stepLock.writer_lock()
        body.AddForceAtRelPos(fx, fy, fz, px, py, pz)
        scene.stepLock.writer_unlock()

    def addRelForceAtPos(fx : ode.Real, fy : ode.Real, fz : ode.Real, px : ode.Real, py : ode.Real, pz : ode.Real)
        if scene is null
            return
        scene.stepLock.writer_lock()
        body.AddRelForceAtPos(fx, fy, fz, px, py, pz)
        scene.stepLock.writer_unlock()

    def addRelForceRelAtPos(fx : ode.Real, fy : ode.Real, fz : ode.Real, px : ode.Real, py : ode.Real, pz : ode.Real)
        if scene is null
            return
        scene.stepLock.writer_lock()
        body.AddRelForceAtRelPos(fx, fy, fz, px, py, pz)
        scene.stepLock.writer_unlock()

    // Toggle body as immovable.
    def toggle_immovable()
          if scene is null
            return
          scene.stepLock.writer_lock()
          if self.geom.GetBody() != null
              self.geom.SetBody(null)
          else
              self.geom.SetBody(self.body)
          scene.stepLock.writer_unlock()

    // TODO we need a "protected" mode so this can be used by Light directly
    // Please do not expose this in PySoy
    def getPositionf() : array of float
        if scene is null
            return {0.0f, 0.0f, 0.0f, 1.0f}
        v : unowned ode.Vector3 = self.body.GetPosition()
        return {(float) v.x, (float) v.y, (float) v.z, 1.0f}


    ////////////////////////////////////////////////////////////////////////
    // Properties

    //
    // scene Property
    scene : soy.scenes.Scene? = null

    //
    // tags property
    tags_ : dict of string,float? // NOTE: this is protected
    prop tags : dict of string,float?
        owned get
            if scene is null
                return new dict of string,float?
            return self.tags_

    //
    // mass property (READ-ONLY)
    _mass : soy.Mass?
    prop mass : soy.Mass
        get
            if _mass == null
                _mass = new soy.Mass(self)
            return _mass

    //
    // position Property
    _position_obj : weak soy.atoms.Position?

    def _position_set(value : soy.atoms.Position)
        // When not in a scene, set the geom's position
        if scene is null
            geom.SetPosition((ode.Real) value.x,
                             (ode.Real) value.y,
                             (ode.Real) value.z)

        // Set the body's position
        else
            scene.stepLock.writer_lock()
            body.SetPosition((ode.Real) value.x,
                             (ode.Real) value.y,
                             (ode.Real) value.z)
            scene.stepLock.writer_unlock()

    def _position_weak(position : Object)
        self._position_obj = null

    prop position : soy.atoms.Position
        owned get
            v : unowned ode.Vector3
            value : soy.atoms.Position? = self._position_obj

            // When not in a scene, get the geom's position
            if scene is null
                v = geom.GetPosition()

            // Set the body's position
            else
                v = body.GetPosition()

            if value is null or (float)v.x != value.x or (float)v.y != value.y or (float)v.z != value.z
                if not(value is null)
                    _position_obj.on_set.disconnect(self._position_set)
                    _position_obj.weak_unref(self._position_weak)
                value = new soy.atoms.Position((float) v.x,
                                               (float) v.y,
                                               (float) v.z)
                value.on_set.connect(self._position_set)
                value.weak_ref(self._position_weak)
                self._position_obj = value
            return value
        set
            self._position_set(value)
            if _position_obj != null
                _position_obj.on_set.disconnect(self._position_set)
                _position_obj.weak_unref(self._position_weak)
            _position_obj = value
            value.on_set.connect(self._position_set)
            value.weak_ref(self._position_weak)
        // TODO we need to somehow update the _position_obj whenever the body
        // its attached to moves.  This would make the most sense in Scene.

    //
    // rotation Property
    _rotation_obj : weak soy.atoms.Rotation?

    def _rotation_set(rot : soy.atoms.Rotation)
        if scene is null
            return
        m : ode.Matrix3 = new ode.Matrix3()
        // ode likes them to be zxy angles.
        m.FromEulerAngles(rot.gamma, rot.alpha, rot.beta)
        self.scene.stepLock.writer_lock()
        self.body.SetRotation(m)
        self.scene.stepLock.writer_unlock()
        return


    def _rotation_weak(rotation : Object)
        self._rotation_obj = null


    prop rotation : soy.atoms.Rotation
        owned get
            if scene is null
                return new soy.atoms.Rotation()
            // You shouldn't be messing with the rotation manually much anyway
            // so recreating it every time should be okay
            if self._rotation_obj != null
                self._rotation_obj.on_set.disconnect(self._rotation_set)
                self._rotation_obj.weak_unref(self._rotation_weak)
            /* matrix representation
                *
                *   __ 1    2    3 __
                * 1 | <0>  <1>  <2> |
                * 2 | <4>  <5>  <6> |
                * 3 | <8>  <9>  <a> |
                *   --              --
                */
            scene.stepLock.reader_lock()
            v : unowned ode.Matrix3 = self.body.GetRotation()
            var value  = new soy.atoms.Rotation(Math.asinf (-1*((float) v.m2)),
                                                Math.atan2f((float) v.m1,
                                                            (float) v.m0),
                                                Math.atan2f((float) v.m6,
                                                            (float) v.ma))
            scene.stepLock.reader_unlock()
            value.on_set.connect(self._rotation_set)
            value.weak_ref(self._rotation_weak)
            self._rotation_obj = value
            return value
        set
            self._rotation_set(value)
            if self._rotation_obj!= null
                self._rotation_obj.on_set.disconnect(self._rotation_set)
                self._rotation_obj.weak_unref(self._rotation_weak)
            self._rotation_obj = value
            value.on_set.connect(self._rotation_set)
            value.weak_ref(self._rotation_weak)

    // Body's linear velocity
    //
    // This is how fast and in which direction a body is moving in a scene.
    // Defaults to (0,0,0)
    prop velocity : soy.atoms.Vector
        owned get
            if scene is null
                return new soy.atoms.Vector()
            var value = new soy.atoms.Vector()
            scene.stepLock.reader_lock()
            vel : weak ode.Vector3 = self.body.GetLinearVel()
            value.x = (float) vel.x
            value.y = (float) vel.y
            value.z = (float) vel.z
            scene.stepLock.reader_unlock()
            return value
        set
            scene.stepLock.writer_lock()
            self.body.SetLinearVel(value.x, value.y, value.z)
            scene.stepLock.writer_unlock()


    def add (k : string, v : soy.scenes.Scene)
        pos : weak ode.Vector3

        // First detach body from old scene
        if body is not null
            self.remove()

        // Store key and value
        key = k
        scene = v

        // Create new ode.Body
        body = new ode.Body(scene.world)
        body.SetData((void*) self)

        // Copy position and orientation from geom
        pos = geom.GetPosition()
        body.SetPosition(pos.x, pos.y, pos.z)
        body.SetRotation(geom.GetRotation())

        // Attach geom to scene and body
        scene.space.Add(geom)
        self.geom.SetBody(self.body)

        // Perform any extra class-specific steps
        self.add_extra()


    def remove ()
        scene.bodies.unset(key)
        scene = null
        body = null
        scene.space.Remove(geom)

        // Perform any extra class-specific steps
        self.remove_extra()


    def virtual add_extra ()
        return


    def virtual remove_extra ()
        return

    def virtual pointDepth (x : float, y : float, z : float) : float
        return 0.0f


    def virtual volume ( ) : float
        return 0.0f


    //def virtual radius ( ) : float
    //    return 0.0f


    def virtual finite ( ) : int
        return 0


    // Sets body's modelview matrix.
    def virtual mult_model_matrix ( )
        var _mtx = new array of GLfloat[16]
        rotation : unowned ode.Matrix3 = self.body.GetRotation()
        position : unowned ode.Vector3 = self.body.GetPosition()

        _mtx[0]  = (GLfloat) rotation.m0
        _mtx[1]  = (GLfloat) rotation.m4
        _mtx[2]  = (GLfloat) rotation.m8
        _mtx[3]  = (GLfloat) 0.0
        _mtx[4]  = (GLfloat) rotation.m1
        _mtx[5]  = (GLfloat) rotation.m5
        _mtx[6]  = (GLfloat) rotation.m9
        _mtx[7]  = (GLfloat) 0.0
        _mtx[8]  = (GLfloat) rotation.m2
        _mtx[9]  = (GLfloat) rotation.m6
        _mtx[10] = (GLfloat) rotation.ma
        _mtx[11] = (GLfloat) 0.0
        _mtx[12] = (GLfloat) position.x
        _mtx[13] = (GLfloat) position.y
        _mtx[14] = (GLfloat) position.z
        _mtx[15] = (GLfloat) 1.0
        glMultMatrixf(_mtx)


    def virtual render ( )
        return


    def virtual calcFogCoords (_depth : float)
        return

