/*
    PySoy - soy.bodies.Box Type
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
#define SELF PySoy_bodies_Box_Object*


static char
tp_doc[] = "soy.bodies.Box Type\n"
"\n"
"Box is a box shaped body.\n"
"\n"
"Box has size property for box size\n"
"and material property for material.\n"
"Example:\n"
"\n"
"    scene = soy.scenes.Scene()\n"
"    box = soy.bodies.Box((5, 10, 15))\n"
    // TODO add material example
"\n";


static PyObject*
tp_new (PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;
    PyObject* py_position = NULL;
    PyObject* py_size = NULL;
    PySoy_materials_Material_Object* py_material = NULL;
    soyatomsPosition* position = NULL;
    soyatomsSize* size = NULL;
    soymaterialsMaterial* material = NULL;
    float x, y, z;

    static char* kw[] = {"position", "size", "material", NULL};

    // Parse arguments
    if (!PyArg_ParseTupleAndKeywords(
            args, kwds, "|OOO!", kw,
            &py_position,
            &py_size,
            &PySoy_materials_Material_Type, &py_material))
        return NULL;

    // Parse py_position if its neither NULL or a Position type
    if (py_position) {
        if (PySoy_atoms_Position_Check(py_position)) {
            position = (soyatomsPosition*) ((PySoy__G_Object*) py_position)->g;
            g_object_ref(position);
        }
        else {
            if (!PyArg_ParseTuple(py_position, "fff", &x, &y, &z)) {
                PyErr_SetString(PyExc_ValueError,
                                "Argument 1 must be either a soy.atoms.Position or a sequence of 3 floats");
                return NULL;
            }
            position = soy_atoms_position_new(x, y, z);
        }
    }

    // Parse py_size if its neither NULL or a Size type
    if (py_size) {
        if (PySoy_atoms_Size_Check(py_size)) {
            size = (soyatomsSize*) ((PySoy__G_Object*) py_size)->g;
            g_object_ref(size);
        }
        else {
            if (!PyArg_ParseTuple(py_size, "fff", &x, &y, &z)) {
                PyErr_SetString(PyExc_ValueError,
                                "Argument 2 must be either a soy.atoms.Size or a sequence of 3 floats");
                return NULL;
            }
            size = soy_atoms_size_new(x, y, z);
        }
    }

    // Grab material's gobject
    material = (py_material) ? py_material->g : NULL;

    // inherit base type
    self = (SELF) PyType_GenericNew(type, args, kwds);
    if (!self)
      return NULL;

    // new gobject
    self->g = soy_bodies_box_new(position, size, material);

    // unref position and size
    if (position) g_object_unref(position);
    if (size) g_object_unref(size);

    // return self
    return (PyObject*) self;
}


static PyObject*
tp_repr (SELF self) {
    PyObject* ret;

    ret = PyUnicode_FromFormat("<Box>"); // TODO position size etc

    // return string as unicode object
    return ret;
}


///////////////////////////////////////////////////////////////////////////////
// Properties

static char
material_doc[] = "Material to render Box with.";
PYSOY_PROP_OBJECT(bodies, box, material, materials_Material);


static char
size_doc[] = "Box Size";
PYSOY_PROP_OBJECT_OWNED(bodies, box, size, atoms_Size);


///////////////////////////////////////////////////////////////////////////////
// Type structs

static PyGetSetDef tp_getset[] = {
    PYSOY_PROPSTRUCT(material),
    PYSOY_PROPSTRUCT(size),
    {NULL}                                                  // sentinel
};


PyTypeObject PySoy_bodies_Box_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.bodies.Box",                                      // tp_name
    sizeof(PySoy_bodies_Box_Object),                       // tp_basicsize
    0,                                                     // tp_itemsize
    0,                                                     // tp_dealloc
    0,                                                     // tp_print
    (getattrfunc) 0,                                       // tp_getattr
    (setattrfunc) 0,                                       // tp_setattr
    0,                                                     // tp_compare
    (reprfunc) tp_repr,                                    // tp_repr
    0,                                                     // tp_as_number
    0,                                                     // tp_as_sequence
    0,                                                     // tp_as_mapping
    0,                                                     // tp_hash
    0,                                                     // tp_call
    0,                                                     // tp_str
    (getattrofunc) 0,                                      // tp_getattro
    (setattrofunc) 0,                                      // tp_setattro
    0,                                                     // tp_as_buffer
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,              // tp_flags
    tp_doc,                                                // tp_doc
    0,                                                     // tp_traverse
    0,                                                     // tp_clear
    0,                                                     // tp_richcompare
    0,                                                     // tp_weaklistoffset
    0,                                                     // tp_iter
    0,                                                     // tp_iternext
    0,                                                     // tp_methods
    0,                                                     // tp_members
    tp_getset,                                             // tp_getset
    &PySoy_bodies_Body_Type,                               // tp_base
    0,                                                     // tp_dict
    0,                                                     // tp_descr_get
    0,                                                     // tp_descr_set
    0,                                                     // tp_dictoffset
    0,                                                     // tp_init
    0,                                                     // tp_alloc
    (newfunc) tp_new,                                      // tp_new
    0,                                                     // tp_free
    0,                                                     // tp_is_gc
};

