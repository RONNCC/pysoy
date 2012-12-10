/*
    PySoy - soy.materials.Colored Type
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
#define SELF PySoy_materials_Colored_Object*


static char
tp_doc[] = "soy.materials.Colored Type\n"
"\n";
// TODO


static SELF
tp_new (PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;
    const gchar* name = NULL;

    // Ensure no keywords were provided
    if (!_PyArg_NoKeywords("soy.materials.Colored", kwds))
        return NULL;

    // Parse arguments
    if (!PyArg_ParseTuple(args, "s", &name)) {
        PyErr_Clear();
        if (!PyArg_ParseTuple(args, ""))
            return NULL;
    }

    // inherit base type
    self = (SELF) PyType_GenericNew(type, args, kwds);
    if (!self)
        return NULL;

    // new gobject
    self->g = soy_materials_colored_new(name);

    // return self
    return self;
}


static PyObject*
tp_repr (SELF self) {
    return PyUnicode_FromFormat("<Colored>");
}


///////////////////////////////////////////////////////////////////////////////
// Properties

PYSOY_PROP_OBJECT_OWNED(materials, colored, ambient, atoms_Color)
static char
ambient_doc[] = "Ambient Color\n"
"\n"
"    This is the ambient color of the Material, lit by both a Scene's ambient\n"
"    color and the ambient component of any lights used.\n"
"\n"
"    Must be an instance of soy.atoms.Color, defaults to white.\n";


PYSOY_PROP_OBJECT_OWNED(materials, colored, diffuse, atoms_Color)
static char
diffuse_doc[] = "Diffuse Color\n"
"\n"
"    This is the diffuse color of the Material, lit by the diffuse component\n"
"    of soy.bodies.Light objects in the same Scene.\n"
"\n"
"    Must be an instance of soy.atoms.Color, defaults to white.\n";


PYSOY_PROP_OBJECT_OWNED(materials, colored, specular, atoms_Color)
static char
specular_doc[] = "Specular Color\n"
"\n"
"    This is the specular color of the Material, lit by the specular\n"
"    property of soy.bodies.Light objects in the same Scene.\n"
"\n"
"    Must be an instance of soy.atoms.Color, defaults to white.\n";

PYSOY_PROP_OBJECT_OWNED(materials, colored, emission, atoms_Color)
static char
emission_doc[] = "Emission Color\n"
"\n"
"    This is the emission color of the Material, which is added to the lit\n"
"    colors regardless of any light properties (as if glowing).\n"
"\n"
"    Must be an instance of soy.atoms.Color, defaults to black\n";


//TODO shades
static char
shades_doc[] = "Number of Shades\n"
"\n"
"    This property detirmines how many \"shades\" a face may have:\n"
"      0 == \"smooth\"\n"
"      1 == \"flat\"\n"
"\n"
"    In the future 2+ will may be permitted for cell shading effects.\n";
// PYSOY_PROP_INT(materials, colored, shades);


//TODO PYSOY_PROP_FLOAT(materials, Colored, shininess);
static char
shininess_doc[] = "Shininess Value\n"
"\n"
"    This property is how large the specular \"dot\" is between 0.0 and 1.0.\n";
PYSOY_PROP_FLOAT(materials, colored, shininess);



///////////////////////////////////////////////////////////////////////////////
// Type structs

static PyGetSetDef tp_getset[] = {
    PYSOY_PROPSTRUCT(ambient),
    PYSOY_PROPSTRUCT(diffuse),
    PYSOY_PROPSTRUCT(specular),
    PYSOY_PROPSTRUCT(emission),
    //PYSOY_PROPSTRUCT(shades),
    PYSOY_PROPSTRUCT(shininess),
    {NULL}                                                 // sentinel
};


PyTypeObject PySoy_materials_Colored_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.materials.Colored",                               // tp_name
    sizeof(PySoy_materials_Colored_Object),                // tp_basicsize
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
    &PySoy_materials_Material_Type,                        // tp_base
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

