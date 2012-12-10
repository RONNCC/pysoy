/*
 *  libsoy - soy.Mass
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
    GLib

class soy.Mass : Object
    /*
    soy.Mass

    This class gives bodies a physical presence for Mass
    */

    body : soy.bodies.Body
    mass_ : unowned ode.Mass

    construct(body : soy.bodies.Body)
        self.body = body
        m : unowned ode.Mass
        self.body.body.GetMass(out m)
        self.mass_ = m

    prop mass : float
        get
            return (float)self.mass_.mass
        set
            // no negative masses
            assert(value >= 0)

            self.mass_.mass = value
            if value != 0
                self.body.body.SetGravityMode(1)
                self.body.body.SetMass(ref self.mass_)
            else
                self.body.body.SetGravityMode(0)

    //
    // TODO: add properties center of gravity and inertia tensor too?

    // Given mass parameters for some object, adjust them so the total mass is now newmass.
    def adjust(newmass : float)
        // no negative masses
        assert(newmass >= 0)

        self.mass_.Adjust(newmass)
        if newmass != 0
            self.body.body.SetGravityMode(1)
            self.body.body.SetMass(ref self.mass_)
        else
            self.body.body.SetGravityMode(0)

    //
    // mass creation methods

    def box(density : float = 1, lx : float = 1, ly : float = 1, lz : float = 1)
        self.mass_.SetBox(density, lx, ly, lz)
        self.body.body.SetMass(ref self.mass_)

    def sphere(density : float = 1, radius : float = 1)
        self.mass_.SetSphere(density, radius)
        self.body.body.SetMass(ref self.mass_)

    def capsule(density : float = 1, direction : int = 1, radius : float = 1, length : float = 1)
        self.mass_.SetCapsule(density, direction, radius, length)
        self.body.body.SetMass(ref self.mass_)

    def cylinder(density : float = 1, direction : int = 1, radius : float = 1, length : float = 1)
        self.mass_.SetCylinder(density, direction, radius, length)
        self.body.body.SetMass(ref self.mass_)
