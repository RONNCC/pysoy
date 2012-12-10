/*
 *  libsoy - soy.joints.Slider
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

class soy.joints.Slider: soy.joints.Joint
    construct(scene : soy.scenes.Scene, bodyA : soy.bodies.Body,
              bodyB : soy.bodies.Body?, axis: soy.atoms.Axis,
              material : soy.materials.Material?)
        super(scene, bodyA, bodyB, null, axis, null, material)


    def override create ( )
        joint = new ode.joints.Slider(scene.world, null)


    def override setup (anchor : soy.atoms.Position?, axis1 : soy.atoms.Axis?,
                        axis2 : soy.atoms.Axis?)
        ((ode.joints.Slider) joint).SetAxis((ode.Real) axis1.x,
                                            (ode.Real) axis1.y,
                                            (ode.Real) axis1.z)


    def addForce(force : ode.Real)
        ((ode.joints.Slider) self.joint).AddForce(force)

    //
    // axis Property
    _axis_obj : weak soy.atoms.Axis?

    def _axis_set(value : soy.atoms.Axis)
        axis : soy.atoms.Axis = new soy.atoms.Axis.normalize(value)
        self.scene.stepLock.writer_lock()
        ((ode.joints.Slider) joint).SetAxis((ode.Real) axis.x,
                                            (ode.Real) axis.y,
                                            (ode.Real) axis.z)
        self.scene.stepLock.writer_unlock()

    def _axis_weak(axis : Object)
        self._axis_obj = null

    prop axis : soy.atoms.Axis
        owned get
            v : ode.Vector3 = new ode.Vector3()
            ((ode.joints.Slider) self.joint).GetAxis(v)
            value : soy.atoms.Axis? = self._axis_obj
            if (value is null or (float) v.x != value.x or
                (float) v.y != value.y or (float) v.z != value.z)
                if value is not null
                    _axis_obj.on_set.disconnect(self._axis_set)
                    _axis_obj.weak_unref(self._axis_weak)
                value = new soy.atoms.Axis((float) v.x,
                                           (float) v.y,
                                           (float) v.z)
                value.on_set.connect(self._axis_set)
                value.weak_ref(self._axis_weak)
                self._axis_obj = value
            return value

        set
            self._axis_set(value)
            if _axis_obj != null
                _axis_obj.on_set.disconnect(self._axis_set)
                _axis_obj.weak_unref(self._axis_weak)
            _axis_obj = value
            value.on_set.connect(self._axis_set)
            value.weak_ref(self._axis_weak)

    //
    // length Property
    prop readonly length : float
        get
            return (float) ((ode.joints.Slider) self.joint).GetPosition()


/* TODO: These won't work until the parameters are in the vapi file
    prop stops : array of float
        owned get
            loangle : ode.Real = self.joint.GetParam(ode.dParamLoStop)
            hiangle : ode.Real = self.joint.GetParam(ode.dParamHiStop)

    prop bounces : float
        owned get
            return (float) self.joint.GetParam(ode.dParamBounce)
        set
            if (value < 0.0) or (value > 1.0)
                print "0.0 to 1.0 only"
                return
            self.joint.SetParam(ode.dParamBounce,(float)value)
*/

