/*
 *  libsoy - soy.atoms.Size
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


class soy.atoms.Size : Object
    event on_set (size : Size)

    construct (width : float = 0.0f, height : float = 0.0f,
               depth : float = 0.0f)
        self._width = width
        self._height = height
        self._depth = depth


    def new set (width : float = 0.0f, height : float = 0.0f,
                 depth : float = 0.0f)
        self._width = width
        self._height = height
        self._depth = depth
        self.on_set(self)


    ////////////////////////////////////////////////////////////////////////
    // Properties

    _width : float
    prop width : float
        get
            return self._width
        set
            self._width = value
            self.on_set(self)


    _height : float
    prop height : float
        get
            return self._height
        set
            self._height = value
            self.on_set(self)


    _depth : float
    prop depth : float
        get
            return self._depth
        set
            self._depth = value
            self.on_set(self)
