/*
  PySoy - soy.atoms.Area Type
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

#define SELF PySoy_joints_Piston_Object*

static char
tp_doc[] = "soy.joints.Piston Type\n"
"\n"
"   A :class:`~soy.joints.Piston` provides one degree of angular freedom for\n"
"   two bodies or a scene and a body.\n"
"\n"
"   Example:\n"
"       >>> s = soy.scenes.Scene()\n"
"       >>> b = soy.bodies.Body(s)\n"
"       >>> b2 = soy.bodies.Body(s)\n"
"       >>> anchor = soy.atoms.Position((1, 2, 3))\n"
"       >>> axis1 = soy.atoms.Axis((1, 2, 3))\n"
"       >>> axis2 = soy.atoms.Axis((2, 3, 4))\n"
"       >>> j = soy.joints.Piston(b, b2, anchor, axis1, axis2)\n"
"       >>> j\n"
"       <Piston Joint>\n";

static PyObject*
tp_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;

    soyscenesScene* scene;
    PySoy_scenes_Scene_Object* pyscene;
    PySoy_bodies_Body_Object* bodyOne;
    PySoy_bodies_Body_Object* bodyTwo;
    PySoy_atoms_Position_Object* anchor;
    PySoy_atoms_Axis_Object* axis1;
    PySoy_atoms_Axis_Object* axis2;

    if (PyArg_ParseTuple(args, "O!O!O!O!O!",
                         &PySoy_bodies_Body_Type, &bodyOne,
                         &PySoy_bodies_Body_Type, &bodyTwo,
                         &PySoy_atoms_Position_Type, &anchor,
                         &PySoy_atoms_Axis_Type, &axis1,
                         &PySoy_atoms_Axis_Type, &axis2))
        scene = bodyTwo->g->scene;

    else
    {
        PyErr_Clear();
        if (PyArg_ParseTuple(args, "O!O!O!O!O!",
                             &PySoy_bodies_Body_Type, &bodyOne,
                             &PySoy_scenes_Scene_Type, &pyscene,
                             &PySoy_atoms_Position_Type, &anchor,
                             &PySoy_atoms_Axis_Type, &axis1,
                             &PySoy_atoms_Axis_Type, &axis2))
            scene = pyscene->g;
        else
            return NULL;
    }

    // Ensure bodies are in the same scene
    if (bodyOne->g->scene != scene) {
        PyErr_SetString(PyExc_ValueError, "Bodies must be in the same scene");
        return NULL;
    }

    self = (SELF) PyType_GenericNew(type, args, NULL);

    if(!self)
        return NULL;

    if(!bodyTwo)
        self->g = soy_joints_piston_new(scene, bodyOne->g, NULL,
                                        anchor->g, axis1->g, axis2->g, NULL);
    else
        self->g = soy_joints_piston_new(scene, bodyOne->g, bodyTwo->g,
                                        anchor->g, axis1->g, axis2->g, NULL);

    return (PyObject*) self;
}

static PyObject*
tp_repr(SELF self) {
    PyObject* ret;

    ret = PyUnicode_FromFormat("<Piston Joint>");

    return ret;
}

///////////////////////////////////////////////////////////////////////////////
// Properties

static char anchor_doc[] =
"where the joint is anchored, returns a :class:`~soy.atoms.Position`";
PYSOY_PROP_OBJECT_OWNED(joints, piston, anchor, atoms_Position);

static char angle_doc[] = "angle of the piston, cannot be set, returns a float";
PYSOY_PROP_FLOAT_RO(joints, piston, angle);
#define angle_setter NULL

static char length_doc[] = "length of the piston, cannot be set, returns a float";
PYSOY_PROP_FLOAT_RO(joints, piston, length);
#define length_setter NULL

static char axis1_doc[] =
"the first axis of rotation, returns a :class:`~soy.atoms.Axis`";
PYSOY_PROP_OBJECT_OWNED(joints, piston, axis1, atoms_Axis);

static char axis2_doc[] =
"the second axis of rotation, returns a :class:`~soy.atoms.Axis`";
PYSOY_PROP_OBJECT_OWNED(joints, piston, axis2, atoms_Axis);

///////////////////////////////////////////////////////////////////////////////
// Type structs

static PyGetSetDef tp_getset[] = {
    PYSOY_PROPSTRUCT(anchor),
    PYSOY_PROPSTRUCT(angle),
    PYSOY_PROPSTRUCT(axis1),
    PYSOY_PROPSTRUCT(axis2),
    {NULL},                         // sentinel
};

PyTypeObject PySoy_joints_Piston_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.joints.Piston",                                   // tp_name
    sizeof(PySoy_joints_Piston_Object),                    // tp_basicsize
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
    (reprfunc) tp_repr,                                    // tp_str
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

