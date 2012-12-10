/*
 *  libsoy - soy.scenes.Room
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
    GL
    Gee
    ode

class soy.scenes.Room : soy.scenes.Scene
    planes : array of geoms.Geom

    construct (size : float)
        // This is a scene which has 6 planes facing towards the center creating
        // a sort of room, which keeps objects within an area.
        planes = new array of geoms.Geom[6]
        planes[0] = new ode.geoms.Plane(super.space,  1.0f,  0.0f,  0.0f, -size)
        planes[1] = new ode.geoms.Plane(super.space,  0.0f,  1.0f,  0.0f, -size)
        planes[2] = new ode.geoms.Plane(super.space,  0.0f,  0.0f,  1.0f, -size)
        planes[3] = new ode.geoms.Plane(super.space, -1.0f,  0.0f,  0.0f, -size)
        planes[4] = new ode.geoms.Plane(super.space,  0.0f, -1.0f,  0.0f, -size)
        planes[5] = new ode.geoms.Plane(super.space,  0.0f,  0.0f, -1.0f, -size)
        for var i = 0 to 5
            planes[i].SetCategoryBits(1)

    def override render (fov : GLfloat, aspect : GLfloat, znear : GLfloat,
                         zfar : GLfloat)
        super.render(fov, aspect, znear, zfar)

