/*
  PySoy - soy.atoms.Color Type
  Copyright (C) 2006,2007,2008,2009,2010,2011,2012 Copyleft Games Group

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published
  by the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.

  You should have received a copy of the GNU Affero General Public License
  along with this program; if not, see http://www.gnu.org/licenses
*/

#include "pysoy2.h"
#define SELF PySoy_atoms_Color_Object*


static char
tp_doc[] =
    "soy.atoms.Color Type\n"
    "\n"
    "    This datatype stores a single RGBA color and handles color math.\n"
    "\n"
    "    Initialization takes either a tuple of 3 or 4 for RGB(A) floats or a\n"
    "    string with either the hex value (\"#FFFFFFFF\") or a named color.\n"
    "    Hex value can be given as a 32 (\"#RRGGBBAA\"), 24 (\"#RRGGBB\"), 16 (\"#RGBA\") or 12 (\"#RGB\") bit value.\n"
    "\n"
    "    Most standard math functions (+ - * /) are supported and are applied\n"
    "    with the component values.  For example, adding red (1.0 0.0 0.0) to\n"
    "    purple (0.5 0.0 0.5) results in bright reddish purple (1.5 0.0 0.5).\n"
    "\n"
    "    Two colors are equal if their components are exactly the same.\n"
    "    If you compare a color to something else, it will simply return False\n"
    "    when you tested on equality, or True when you used not equal.\n"
    "    Only equality and non-equality are supported, no less/greater.\n"
    "\n"
    "    >>> c = soy.atoms.Color('darksalmon')\n"
    "    >>> c\n"
    "    <Color (233, 150, 122, 255)>\n"
    "    >>> c.red\n"
    "    233\n"
    "    >>> c.blue\n"
    "    122\n"
    "    >>> c.green\n"
    "    150\n"
    "    >>> c.hex\n"
    "    '#e9967aff'\n"
    "\n"
    "    >>> soy.atoms.Color('#ccaaffee')\n"
    "    <Color (204, 170, 255, 238)>\n"
    "    >>> soy.atoms.Color('#ccaaff')\n"
    "    <Color (204, 170, 255, 255)>\n"
    "    >>> soy.atoms.Color('#cafe')\n"
    "    <Color (204, 170, 255, 238)>\n"
    "    >>> soy.atoms.Color('#caf')\n"
    "    <Color (204, 170, 255, 255)>\n"
    "\n";


static PyObject*
tp_new (PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;
    const gchar* name = NULL;
    unsigned char r, g, b, a = 255;

    // Ensure no keywords were given
    if (!_PyArg_NoKeywords("soy.atoms.Color", kwds));

    // Try name string argument first,
    // then 3-tuple uchars,
    // then 4-tuple uchars.
    if (!PyArg_ParseTuple(args, "s", &name)) {
        PyErr_Clear();
        if (!PyArg_ParseTuple(args, "(bbb)", &r, &g, &b)) {
            PyErr_Clear();
            if (!PyArg_ParseTuple(args, "(bbbb)", &r, &g, &b, &a)) {
                return NULL;
            }
        }
    }

    // inherit base type
    self = (SELF) PyType_GenericNew(type, args, kwds);
    if (!self)
        return NULL;

    // new gobject by name
    if (name)
        self->g = soy_atoms_color_new_named(name);

    // new gobject by uchars
    else
        self->g = soy_atoms_color_new(r, g, b, a);

    // return self
    return (PyObject*) self;
}


static PyObject*
tp_repr (PyObject* this) {
    SELF self = (SELF) this;
    gchar* str;
    PyObject* ret;

    // generate "<Color (r, g, b, a)>" string
    str = g_strdup_printf("<Color %s>", soy_atoms_color_string(self->g));

    // return string as unicode object
    ret = PyUnicode_FromString(str);
    g_free(str);
    return ret;
}


static PyObject*
tp_str (PyObject* this) {
    SELF self = (SELF) this;
    PyObject* ret;

    ret = PyUnicode_FromString(soy_atoms_color_string(self->g));

    // return string
    return ret;
}


static PyObject*
tp_richcompare (PyObject *left, PyObject *right, int op) {
    GObject* c1 = NULL;
    GObject* c2 = NULL;

    if (!PySoy__G_Check(left) || !PySoy__G_Check(right))
        return Py_False;

    c1 = ((PySoy__G_Object*) left)->g;
    c2 = ((PySoy__G_Object*) right)->g;

    if (op == Py_EQ) {
        if (soy_atoms_color_cmp_eq(c1, c2))
            return Py_True;
    }
    else if (op == Py_NE) {
        if (soy_atoms_color_cmp_ne(c1, c2))
            return Py_True;
    }
    else {
        PyErr_SetString(PyExc_NotImplementedError,
                        "only == and != are supported for soy.atoms.Color");
        return NULL;
    }
    return Py_False;
}


///////////////////////////////////////////////////////////////////////////////
// Number Methods

static PyObject*
nb_add (PyObject* o1, PyObject* o2) {
    soyatomsColor* c1 = NULL;
    soyatomsColor* c2 = NULL;
    SELF result;

    if (PySoy_atoms_Color_Check(o1) && PySoy_atoms_Color_Check(o2)) {
        c1 = ((SELF) o1)->g;
        c2 = ((SELF) o2)->g;
    }
    else {
        PyErr_SetString(PyExc_TypeError,
                        "arguments are not of type soy.atoms.Color");
        return NULL;
    }

    // create result object
    result = (SELF) PyType_GenericNew(&PySoy_atoms_Color_Type,
                                      NULL, NULL);
    if (!result)
        return NULL;

    // new gobject
    result->g = soy_atoms_color_new_add(c1, c2);

    // return result
    return (PyObject*) result;
}


static PyObject*
nb_subtract (PyObject* o1, PyObject* o2) {
    soyatomsColor* c1 = NULL;
    soyatomsColor* c2 = NULL;
    SELF result;

    if (PySoy_atoms_Color_Check(o1) && PySoy_atoms_Color_Check(o2)) {
        c1 = ((SELF) o1)->g;
        c2 = ((SELF) o2)->g;
    }
    else {
        PyErr_SetString(PyExc_TypeError,
                        "arguments are not of type soy.atoms.Color");
        return NULL;
    }

    // create result object
    result = (SELF) PyType_GenericNew(&PySoy_atoms_Color_Type,
                                      NULL, NULL);
    if (!result)
        return NULL;

    // new gobject
    result->g = soy_atoms_color_new_subtract(c1, c2);

    // return result
    return (PyObject*) result;
}


static PyObject*
nb_multiply (PyObject* o1, PyObject* o2) {
    soyatomsColor* c1 = NULL;
    soyatomsColor* c2 = NULL;
    SELF result;

    if (PySoy_atoms_Color_Check(o1) && PySoy_atoms_Color_Check(o2)) {
        c1 = ((SELF) o1)->g;
        c2 = ((SELF) o2)->g;
    }
    else {
        PyErr_SetString(PyExc_TypeError,
                        "arguments are not of type soy.atoms.Color");
        return NULL;
    }

    // create result object
    result = (SELF) PyType_GenericNew(&PySoy_atoms_Color_Type,
                                      NULL, NULL);
    if (!result)
        return NULL;

    // new gobject
    result->g = soy_atoms_color_new_multiply(c1, c2);

    // return result
    return (PyObject*) result;
}


static PyObject*
nb_true_divide (PyObject* o1, PyObject* o2) {
    soyatomsColor* c1 = NULL;
    soyatomsColor* c2 = NULL;
    SELF result;

    if (PySoy_atoms_Color_Check(o1) && PySoy_atoms_Color_Check(o2)) {
        c1 = ((SELF) o1)->g;
        c2 = ((SELF) o2)->g;
    }
    else {
        PyErr_SetString(PyExc_TypeError,
                        "arguments are not of type soy.atoms.Color");
        return NULL;
    }

    // create result object
    result = (SELF) PyType_GenericNew(&PySoy_atoms_Color_Type,
                                      NULL, NULL);
    if (!result)
        return NULL;

    // new gobject
    result->g = soy_atoms_color_new_divide(c1, c2);

    // return result
    return (PyObject*) result;
}


///////////////////////////////////////////////////////////////////////////////
// Properties

static char
red_doc[] = "Red color component";
PYSOY_PROP_UCHAR(atoms, color, red);


static char
green_doc[] = "Green color component";
PYSOY_PROP_UCHAR(atoms, color, green);


static char
blue_doc[] = "Blue color component";
PYSOY_PROP_UCHAR(atoms, color, blue);


static char
luma_doc[] = "Color brightness (RGB average)";
PYSOY_PROP_UCHAR(atoms, color, luma);


static char
alpha_doc[] = "Alpha color component";
PYSOY_PROP_UCHAR(atoms, color, alpha);


static char
hex_doc[] = "Color hex value";
PYSOY_PROP_STRING(atoms, color, hex);


///////////////////////////////////////////////////////////////////////////////
// Type structs

static PyMethodDef tp_methods[] = {
    {NULL},                                                 // sentinel
};


static PyNumberMethods tp_as_number = {
    nb_add,                                     // nb_add
    nb_subtract,                                // nb_subtract
    nb_multiply,                                // nb_multiply
    0,                                          // nb_remainder
    0,                                          // nb_divmod
    0,                                          // nb_power
    0,                                          // nb_negative
    0,                                          // nb_positive
    0,                                          // nb_absolute
    0,                                          // nb_bool
    0,                                          // nb_invert
    0,                                          // nb_lshift
    0,                                          // nb_rshift
    0,                                          // nb_and
    0,                                          // nb_xor
    0,                                          // nb_or
    0,                                          // nb_int
    0,                                          // nb_reserved
    0,                                          // nb_float
    0,                                          // nb_inplace_add
    0,                                          // nb_inplace_subtract
    0,                                          // nb_inplace_multiply
    0,                                          // nb_inplace_remainder
    0,                                          // nb_inplace_power
    0,                                          // nb_inplace_lshift
    0,                                          // nb_inplace_rshift
    0,                                          // nb_inplace_and
    0,                                          // nb_inplace_xor
    0,                                          // nb_inplace_or
    0,                                          // nb_floor_divide
    nb_true_divide,                             // nb_true_divide
    0,                                          // nb_inplace_floor_divide
    0,                                          // nb_inplace_true_divide
    0,                                          // nb_index
};


static PyGetSetDef tp_getset[] = {
    PYSOY_PROPSTRUCT(red),
    PYSOY_PROPSTRUCT(green),
    PYSOY_PROPSTRUCT(blue),
    PYSOY_PROPSTRUCT(luma),
    PYSOY_PROPSTRUCT(alpha),
    PYSOY_PROPSTRUCT(hex),
    {NULL},                                                // sentinel
};


PyTypeObject PySoy_atoms_Color_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.atoms.Color",                                     // tp_name
    sizeof(PySoy_atoms_Color_Object),                      // tp_basicsize
    0,                                                     // tp_itemsize
    0,                                                     // tp_dealloc
    0,                                                     // tp_print
    (getattrfunc) 0,                                       // tp_getattr
    (setattrfunc) 0,                                       // tp_setattr
    0,                                                     // tp_compare
    (reprfunc) tp_repr,                                    // tp_repr
    &tp_as_number,                                         // tp_as_number
    0,                                                     // tp_as_sequence
    0,                                                     // tp_as_mapping
    0,                                                     // tp_hash
    0,                                                     // tp_call
    (reprfunc) tp_str,                                     // tp_str
    (getattrofunc) 0,                                      // tp_getattro
    (setattrofunc) 0,                                      // tp_setattro
    0,                                                     // tp_as_buffer
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,              // tp_flags
    tp_doc,                                                // tp_doc
    0,                                                     // tp_traverse
    0,                                                     // tp_clear
    tp_richcompare,                                        // tp_richcompare
    0,                                                     // tp_weaklistoffset
    0,                                                     // tp_iter
    0,                                                     // tp_iternext
    tp_methods,                                            // tp_methods
    0,                                                     // tp_members
    tp_getset,                                             // tp_getset
    &PySoy__G_Type,                                        // tp_base
    0,                                                     // tp_dict
    0,                                                     // tp_descr_get
    0,                                                     // tp_descr_set
    0,                                                     // tp_dictoffset
    0,                                                     // tp_init
    0,                                                     // tp_alloc
    tp_new,                                                // tp_new
    0,                                                     // tp_free
    0,                                                     // tp_is_gc
};

