/*
 *  libsoy - soy.atoms.Radius
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


class soy.atoms.Radius : Object
    event on_set (radius : Radius)

    construct (length : float = 0.0f)
        self._length = length


    def new set (length : float = 0.0f)
        self._length = length
        self.on_set(self)


    ////////////////////////////////////////////////////////////////////////
    // Properties

    _length : float
    prop length : float
        get
            return self._length
        set
            self._length = value
            self.on_set(self)
