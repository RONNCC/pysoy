/*
 *  libsoy - soy.widgets.Container
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
    soy.atoms

class soy.widgets.Container : soy.widgets.Widget
    children : LinkedList of soy.widgets.Widget

    construct (parent : soy.widgets.Container?)
        super(parent)
        self.children = new LinkedList of soy.widgets.Widget


    def virtual resize_children (x: int, y : int, width : int, height : int)
        // Resize each child widget in order
        for widget in self.children
            widget.size = new soy.atoms.Size(self.width, self.height)


    def override render (x: int, y : int, width : int, height : int)
        // Render each child widget in order
        for widget in self.children
            widget.render(x, y, widget.width, widget.height)

    def override resize(x: int, y : int, width : int, height : int)
        self.resize_children (x, y, width, height)

