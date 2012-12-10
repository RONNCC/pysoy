/*
 *  libsoy - soy.atoms.Color
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
    GLib.Math
    GL


class soy.atoms.Color : Object
    event on_set (color : Color)

    // TODO: accept other types of values such as hex and different sized lists
    construct (red : uchar, green : uchar, blue : uchar, alpha : uchar = 255)
        self._red   = red
        self._green = green
        self._blue  = blue
        self._alpha = alpha


    construct new4f (rgba : array of float)
        // For glColor4f
        self._red   = (uchar) (rgba[0] * 255)
        self._green = (uchar) (rgba[1] * 255)
        self._blue  = (uchar) (rgba[2] * 255)
        self._alpha = (uchar) (rgba[3] * 255)


    construct new4ub (rgba : array of uchar)
        self._red = rgba[0]
        self._green = rgba[1]
        self._blue = rgba[2]
        self._alpha = rgba[3]


    construct load (packet : string)
        self._alpha = 255


    construct named (color : string)
        rgba : uint

        if _map.has_key(color)
            rgba = _map[color]
            self._red = (uchar) ((rgba >> 24) & 255)
            self._green = (uchar) ((rgba >> 16) & 255)
            self._blue = (uchar) ((rgba >> 8) & 255)
            self._alpha = (uchar) (rgba & 255)
        else
            self.hex = color


    construct divide (a : soy.atoms.Color, b : soy.atoms.Color)
        _r, _g, _b : uint

        if b._red == 0
            _r = 255
        else
            _r = (uint)roundf((a._red/256.0f) / (b._red/256.0f) * 256)

        if b._green == 0
            _g = 255
        else
           _g = (uint)roundf((a._green/256.0f) / (b._green/256.0f) * 256)

        if b._blue == 0
            _b = 255
        else
            _b = (uint)roundf((a._blue/256.0f) / (b.blue/256.0f) * 256)

        if _r <= 255
           self._red = (uchar)_r
        else
            self._red = 255
        if _g <= 255
            self._green = (uchar)_g
        else
            self._green = 255
        if _b <= 255
            self._blue = (uchar)_b
        else
            self._blue = 255
        self._alpha = 255


    construct multiply (a : soy.atoms.Color, b : soy.atoms.Color)
        _r, _g, _b : uint
        _r = (uint)roundf((a._red/256.0f) * (b._red/256.0f) * 256)
        _g = (uint)roundf((a._green/256.0f) * (b._green/256.0f) * 256)
        _b = (uint)roundf((a._blue/256.0f) * (b.blue/256.0f) * 256)

        if _r <= 255
           self._red = (uchar)_r
        else
            self._red = 255
        if _g <= 255
            self._green = (uchar)_g
        else
            self._green = 255
        if _b <= 255
            self._blue = (uchar)_b
        else
            self._blue = 255
        self._alpha = 255


    construct add (a : soy.atoms.Color, b : soy.atoms.Color)
        _r, _g, _b : uint
        _r = a._red   + b._red
        _g = a._green + b._green
        _b = a._blue  + b._blue

        if _r <= 255
           self._red = (uchar)_r
        else
            self._red = 255
        if _g <= 255
            self._green = (uchar)_g
        else
            self._green = 255
        if _b <= 255
            self._blue = (uchar)_b
        else
            self._blue = 255
        self._alpha = 255


    construct subtract (a : soy.atoms.Color, b : soy.atoms.Color)
        _r, _g, _b : int
        _r = a._red   - b._red
        _g = a._green - b._green
        _b = a._blue  - b._blue

        if _r >= 0
           self._red = (uchar)_r
        else
            self._red = 0
        if _g >= 0
            self._green = (uchar)_g
        else
            self._green = 0
        if _b >= 0
            self._blue = (uchar)_b
        else
            self._blue = 0
        self._alpha = 255


    ////////////////////////////////////////////////////////////////////////
    // Properties

    _red   : uchar
    prop red : uchar
        get
            return _red
        set
            self._red = value
            self.on_set(self)


    _green   : uchar
    prop green : uchar
        get
            return _green
        set
            self._green = value
            self.on_set(self)


    _blue   : uchar
    prop blue : uchar
        get
            return _blue
        set
            self._blue = value
            self.on_set(self)


    prop luma : uchar
        get
            return (uchar) (((int) _red + (int) _green + (int) _blue) / 3)
        set
            curr : uchar = (uchar)(((int)_red + (int)_green + (int)_blue) / 3)
            diff : uchar = value - curr
            // FIXME
            self._red += diff
            self._green += diff
            self._blue += diff

            self.on_set(self)


    _alpha   : uchar
    prop alpha : uchar
        get
            return _alpha
        set
            self._alpha = value
            self.on_set(self)


    prop hex : string
        owned get
            return "#%02x%02x%02x%02x".printf(self._red, self._green, self._blue, self._alpha)
        set
            if value.length >= 4 && value.length <= 9 && value[0] == '#'
                if value.length == 9
                    // 32-bit hex value
                    (value[1:3]).scanf("%x", out self._red)
                    (value[3:5]).scanf("%x", out self._green)
                    (value[5:7]).scanf("%x", out self._blue)
                    (value[7:9]).scanf("%x", out self._alpha)
                else if value.length >= 7
                    // 24-bit hex value
                    (value[1:3]).scanf("%x", out self._red)
                    (value[3:5]).scanf("%x", out self._green)
                    (value[5:7]).scanf("%x", out self._blue)
                    self._alpha = 255
                else if value.length >= 5
                    // 16-bit hex value
                    (value[1:2]).scanf("%x", out self._red)
                    (value[2:3]).scanf("%x", out self._green)
                    (value[3:4]).scanf("%x", out self._blue)
                    (value[4:5]).scanf("%x", out self._alpha)
                    self._red *= 17
                    self._green *= 17
                    self._blue *= 17
                    self._alpha *= 17
                else if value.length >= 4
                    // 12-bit hex value
                    (value[1:2]).scanf("%x", out self._red)
                    (value[2:3]).scanf("%x", out self._green)
                    (value[3:4]).scanf("%x", out self._blue)
                    self._red *= 17
                    self._green *= 17
                    self._blue *= 17
                    self._alpha = 255
            else
                // default to black
                self._red = 0
                self._green = 0
                self._blue = 0
                self._alpha = 255




    def string () : string
        return "(%i, %i, %i, %i)".printf((int) self._red, (int) self._green,
                                         (int) self._blue, (int) self._alpha)


    def get4f () : array of float
        // For glColor4f
        return {((float) self._red) / 255.0f,
                ((float) self._green) / 255.0f,
                ((float) self._blue) / 255.0f,
                ((float) self._alpha) / 255.0f}


    def get4ub () : array of uchar
        // For glColor4ub calls
        return {self._red, self._green, self._blue, self._alpha}


    def static cmp_eq (left : Object, right : Object) : bool
        if not (left isa soy.atoms.Color) or not (right isa soy.atoms.Color)
            return false

        _r, _g, _b, _a : bool

        var lefta = ((soy.atoms.Color)left).get4ub()
        var righta = ((soy.atoms.Color)right).get4ub()

        _r = lefta[0] == righta[0]
        _g = lefta[1] == righta[1]
        _b = lefta[2] == righta[2]
        _a = lefta[3] == righta[3]

        return (_r & _g & _b & _a)


    def static cmp_ne (left : Object, right : Object) : bool
        return not cmp_eq(left, right)

    def static cmp (left : Object, right : Object, comparison : Comparison) : bool
        if not (left isa soy.atoms.Color) or not (right isa soy.atoms.Color)
            return false

        if (comparison == Comparison.EQ)
            return cmp_eq(left, right)
        else if (comparison == Comparison.NE)
            return cmp_ne(left, right)
        else  // compute luminosities
        
            var lefta = (soy.atoms.Color) left
            var righta = (soy.atoms.Color) right
            
            lum_left : float
            lum_right : float
            
            lum_left  = sqrtf(0.299f * lefta._red * lefta._red + 0.587f * lefta._green * lefta._green + 0.114f * lefta._blue * lefta._blue)
            lum_right = sqrtf(0.299f * righta._red * righta._red + 0.587f * righta._green * righta._green + 0.114f * righta._blue * righta._blue)
				                 
            if (comparison == Comparison.GT)
                return lum_left > lum_right
            else if (comparison == Comparison.GE)
                return lum_left >= lum_right
            else if (comparison == Comparison.LT)
                return lum_left < lum_right
            else
                return lum_left <= lum_right

    ////////////////////////////////////////////////////////////////////////
    // Static properties

    class Colormap : dict of string, uint
        _map_objs: dict of string, unowned soy.atoms.Color?

        init
            _map_objs = new dict of string, unowned soy.atoms.Color?

        def _map_weak (color : Object)
            // We can't remove keys from _map_objs while we iterate over it, so
            // we instead build a list of keys that need to be garbage collected
            var garbage = new list of string
            for index in self._map_objs.keys
                if self._map_objs[index] is color
                    garbage.add(index)
            // Now we can remove them
            for index in garbage
                self._map_objs.unset(index)

        def _map_set (c : Color)
            value : uint
            value = (c.red << 24) + (c.green << 16) + (c.blue << 8) + c.alpha

            for key in self._map_objs.keys
                if self._map_objs[key] is c
                    self[key] = value

        def get_color (key : string) : soy.atoms.Color?
            if not (key in _map.keys)
                return null

            ret : soy.atoms.Color? = null

            if _map_objs.has_key(key)
                ret = _map_objs[key]
            else
                ret = new soy.atoms.Color.named(key)

            // Set event callbacks
            ret.on_set.connect(_map_set)
            ret.weak_ref(_map_weak)

            // Store weak reference and return owned Color object
            _map_objs[key] = ret
            return (owned) ret

        def set_color (key : string, v : soy.atoms.Color)
            value : uint
            value = (v.red << 24) + (v.green << 16) + (v.blue << 8) + v.alpha
            self[key] = value
            self._map_objs[key] = v

            // Set event callbacks
            v.on_set.connect(_map_set)
            v.weak_ref(_map_weak)

        def get_color_uint (key : string) : uint
            if not (key in _map.keys)
                return -1

            col : soy.atoms.Color? = null
            ret : uint

            if _map_objs.has_key(key)
                col = _map_objs[key]
            else
                col = new soy.atoms.Color.named(key)

            // Set event callbacks
            col.on_set.connect(_map_set)
            col.weak_ref(_map_weak)

            // Store weak reference and return owned Color object
            _map_objs[key] = col

            ret = (col.red << 24) + (col.green << 16) + (col.blue << 8) + col.alpha
            return ret

        def set_color_uint (key : string, v : uint)
            self[key] = v
            red : uchar = (uchar) v >> 24
            green : uchar = (uchar) v >> 16
            blue : uchar = (uchar) v >> 8
            alpha : uchar = (uchar) v
            self._map_objs[key] = new soy.atoms.Color(red, green, blue, alpha)

            // Set event callbacks
            self._map_objs[key].on_set.connect(_map_set)
            self._map_objs[key].weak_ref(_map_weak)

        def static check_type (v : Object) : bool
            if v isa soy.atoms.Color
                return true
            return false


    _map : static Colormap
    init static
        // From http://www.w3.org/TR/SVG/types.html#ColorKeywords
        // Packed as (red<<24 | green<<16 | blue<<8 | alpha)
        _map = new Colormap
        _map["aliceblue"] = 4042850303u
        _map["antiquewhite"] = 4209760255u
        _map["aqua"] = 16777215u
        _map["aquamarine"] = 2147472639u
        _map["azure"] = 4043309055u
        _map["beige"] = 4126530815u
        _map["bisque"] = 4293182719u
        _map["black"] = 255u
        _map["blanchedalmond"] = 4293643775u
        _map["blue"] = 65535u
        _map["blueviolet"] = 2318131967u
        _map["brown"] = 2771004159u
        _map["burlywood"] = 3736635391u
        _map["cadetblue"] = 1604231423u
        _map["chartreuse"] = 2147418367u
        _map["chocolate"] = 3530104575u
        _map["clear"] = 0u
        _map["coral"] = 4286533887u
        _map["cornflowerblue"] = 1687547391u
        _map["cornsilk"] = 4294499583u
        _map["crimson"] = 3692313855u
        _map["cyan"] = 16777215u
        _map["darkblue"] = 35839u
        _map["darkcyan"] = 9145343u
        _map["darkgoldenrod"] = 3095792639u
        _map["darkgray"] = 2846468607u
        _map["darkgreen"] = 6553855u
        _map["darkgrey"] = 2846468607u
        _map["darkkhaki"] = 3182914559u
        _map["darkmagenta"] = 2332068863u
        _map["darkolivegreen"] = 1433087999u
        _map["darkorange"] = 4287365375u
        _map["darkorchid"] = 2570243327u
        _map["darkred"] = 2332033279u
        _map["darksalmon"] = 3918953215u
        _map["darkseagreen"] = 2411499519u
        _map["darkslateblue"] = 1211993087u
        _map["darkslategray"] = 793726975u
        _map["darkslategrey"] = 793726975u
        _map["darkturquoise"] = 13554175u
        _map["darkviolet"] = 2483082239u
        _map["deeppink"] = 4279538687u
        _map["deepskyblue"] = 12582911u
        _map["dimgray"] = 1768516095u
        _map["dimgrey"] = 1768516095u
        _map["dodgerblue"] = 512819199u
        _map["firebrick"] = 2988581631u
        _map["floralwhite"] = 4294635775u
        _map["forestgreen"] = 579543807u
        _map["fuchsia"] = 4278255615u
        _map["gainsboro"] = 3705462015u
        _map["ghostwhite"] = 4177068031u
        _map["gold"] = 4292280575u
        _map["goldenrod"] = 3668254975u
        _map["gray"] = 2155905279u
        _map["green"] = 8388863u
        _map["greenyellow"] = 2919182335u
        _map["grey"] = 2155905279u
        _map["honeydew"] = 4043305215u
        _map["hotpink"] = 4285117695u
        _map["indianred"] = 3445382399u
        _map["indigo"] = 1258324735u
        _map["ivory"] = 4294963455u
        _map["khaki"] = 4041641215u
        _map["lavender"] = 3873897215u
        _map["lavenderblush"] = 4293981695u
        _map["lawngreen"] = 2096890111u
        _map["lemonchiffon"] = 4294626815u
        _map["lightblue"] = 2916673279u
        _map["lightcoral"] = 4034953471u
        _map["lightcyan"] = 3774873599u
        _map["lightgoldenrodyellow"] = 4210742015u
        _map["lightgray"] = 3553874943u
        _map["lightgreen"] = 2431553791u
        _map["lightgrey"] = 3553874943u
        _map["lightpink"] = 4290167295u
        _map["lightsalmon"] = 4288707327u
        _map["lightseagreen"] = 548580095u
        _map["lightskyblue"] = 2278488831u
        _map["lightslategray"] = 2005441023u
        _map["lightslategrey"] = 2005441023u
        _map["lightsteelblue"] = 2965692159u
        _map["lightyellow"] = 4294959359u
        _map["lime"] = 16711935u
        _map["limegreen"] = 852308735u
        _map["linen"] = 4210091775u
        _map["magenta"] = 4278255615u
        _map["maroon"] = 2147483903u
        _map["mediumaquamarine"] = 1724754687u
        _map["mediumblue"] = 52735u
        _map["mediumorchid"] = 3126187007u
        _map["mediumpurple"] = 2473647103u
        _map["mediumseagreen"] = 1018393087u
        _map["mediumslateblue"] = 2070474495u
        _map["mediumspringgreen"] = 16423679u
        _map["mediumturquoise"] = 1221709055u
        _map["mediumvioletred"] = 3340076543u
        _map["midnightblue"] = 421097727u
        _map["mintcream"] = 4127193855u
        _map["mistyrose"] = 4293190143u
        _map["moccasin"] = 4293178879u
        _map["navajowhite"] = 4292783615u
        _map["navy"] = 33023u
        _map["oldlace"] = 4260751103u
        _map["olive"] = 2155872511u
        _map["olivedrab"] = 1804477439u
        _map["orange"] = 4289003775u
        _map["orangered"] = 4282712319u
        _map["orchid"] = 3664828159u
        _map["palegoldenrod"] = 4008225535u
        _map["palegreen"] = 2566625535u
        _map["paleturquoise"] = 2951671551u
        _map["palevioletred"] = 3681588223u
        _map["papayawhip"] = 4293907967u
        _map["peachpuff"] = 4292524543u
        _map["peru"] = 3448061951u
        _map["pink"] = 4290825215u
        _map["plum"] = 3718307327u
        _map["powderblue"] = 2967529215u
        _map["purple"] = 2147516671u
        _map["red"] = 4278190335u
        _map["rosybrown"] = 3163525119u
        _map["royalblue"] = 1097458175u
        _map["saddlebrown"] = 2336560127u
        _map["salmon"] = 4202722047u
        _map["sandybrown"] = 4104413439u
        _map["seagreen"] = 780883967u
        _map["seashell"] = 4294307583u
        _map["sienna"] = 2689740287u
        _map["silver"] = 3233857791u
        _map["skyblue"] = 2278484991u
        _map["slateblue"] = 1784335871u
        _map["slategray"] = 1887473919u
        _map["slategrey"] = 1887473919u
        _map["snow"] = 4294638335u
        _map["springgreen"] = 16744447u
        _map["steelblue"] = 1182971135u
        _map["tan"] = 3535047935u
        _map["teal"] = 8421631u
        _map["thistle"] = 3636451583u
        _map["tomato"] = 4284696575u
        _map["turquoise"] = 1088475391u
        _map["violet"] = 4001558271u
        _map["wheat"] = 4125012991u
        _map["white"] = 4294967295u
        _map["whitesmoke"] = 4126537215u
        _map["yellow"] = 4294902015u
        _map["yellowgreen"] = 2597139199u

    prop static readonly names : Colormap
        get
            return _map

