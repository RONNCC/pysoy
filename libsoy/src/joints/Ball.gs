/*
 *  libsoy - soy.joints.Ball
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

class soy.joints.Ball: soy.joints.Joint
    construct(scene : soy.scenes.Scene, bodyA : soy.bodies.Body,
              bodyB : soy.bodies.Body?, anchor : soy.atoms.Position,
              material : soy.materials.Material?)
        super(scene, bodyA, bodyB, anchor, null, null, material)


    def override create ( )
        joint = new ode.joints.Ball(scene.world, null)


    def override setup (anchor : soy.atoms.Position?, axis1 : soy.atoms.Axis?,
                        axis2 : soy.atoms.Axis?)
        ((ode.joints.Ball) joint).SetAnchor((ode.Real) anchor.x,
                                            (ode.Real) anchor.y,
                                            (ode.Real) anchor.z)


    //
    // anchor Property
    _anchor_obj : weak soy.atoms.Position?

    def _anchor_set(anchor : soy.atoms.Position)
        self.scene.stepLock.writer_lock()
        ((ode.joints.Ball) joint).SetAnchor((ode.Real) anchor.x,
                                            (ode.Real) anchor.y,
                                            (ode.Real) anchor.z)
        self.scene.stepLock.writer_unlock()

    def _anchor_weak(anchor : Object)
        self._anchor_obj = null

    prop anchor : soy.atoms.Position
        owned get
            v : ode.Vector3 = new ode.Vector3()
            ((ode.joints.Ball) self.joint).GetAnchor(v)
            value : soy.atoms.Position? = self._anchor_obj
            if (value is null or (float) v.x != value.x or
                (float) v.y != value.y or (float)v.z != value.z)
                if value is not null
                    _anchor_obj.on_set.disconnect(self._anchor_set)
                    _anchor_obj.weak_unref(self._anchor_weak)
                value = new soy.atoms.Position((float) v.x,
                                               (float) v.y,
                                               (float) v.z)
                value.on_set.connect(self._anchor_set)
                value.weak_ref(self._anchor_weak)
                self._anchor_obj = value
            return value

        set
            self._anchor_set(value)
            if _anchor_obj != null
                _anchor_obj.on_set.disconnect(self._anchor_set)
                _anchor_obj.weak_unref(self._anchor_weak)
            _anchor_obj = value
            value.on_set.connect(self._anchor_set)
            value.weak_ref(self._anchor_weak)
        // TODO we need to somehow update the _anchor_obj whenever the joint
        // its attached to moves.  This would make the most sense in Scene.

