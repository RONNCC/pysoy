/*
    PySoy - soy.widgets.Container Type
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
#define SELF PySoy_widgets_Container_Object*


static char
tp_doc[] = "soy.widgets.Container Type\n"
"\n"
"    Container is a container widget.\n"
"\n";


static SELF
tp_new (PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;
    SELF parent;
    static char* kw[] = {"parent", NULL};

    // Parse arguments
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!|", kw,
                                     &PySoy_widgets_Container_Type, &parent))
        return NULL;

    // inherit base type
    self = (SELF) PyType_GenericNew(type, args, kwds);
    if (!self)
      return NULL;

    // new gobject
    self->g = soy_widgets_container_new(parent->g);

    return self;
}


static PyObject*
tp_repr (SELF self) {
    return PyUnicode_FromString("<Container>");
}


///////////////////////////////////////////////////////////////////////////////
// Sequence Methods

static Py_ssize_t
tp_sq_length(SELF self) {
    // Pass call to libgee and return the result
    return gee_collection_get_size((GeeCollection*) self->g->children);
}


static PySoy_widgets_Widget_Object*
tp_sq_item(SELF self, Py_ssize_t index) {
    int size;
    gpointer g;
    PySoy_widgets_Widget_Object* ret;

    // Get size and compute relative index
    size = gee_collection_get_size((GeeCollection*) self->g->children);
    if (index < 0)
        index = size + index;

    // Check index
    if ((index < 0) || (index >= size)) {
        PyErr_SetString(PyExc_IndexError, "Container index out of range");
        return NULL;
    }

    // Pass call to libgee
    g = gee_list_get((GeeList*) self->g->children, index);

    // TODO Check to see if the gobject already has a pyobject associated

    // Kids, do not try this at home.
    ret = (PySoy_widgets_Widget_Object*)
          PyType_GenericNew(g_type_get_qdata(G_OBJECT_TYPE(g), GPyObject),
                            NULL, NULL);
    if (!ret) return NULL;

    // Set gobject backend, incref it
    ret->g = g;
    g_object_ref(g);

    // TODO store weak pyobject reference in gobject

    return ret;
}


static int
tp_sq_contains(SELF self, Py_ssize_t i, PyObject* value) {
    // Container widgets may only contain other widgets
    if (PyObject_IsInstance(value, (PyObject*) &PySoy_widgets_Widget_Type) != 1)
        return FALSE;

    // Pass call to libgee and return the result
    return gee_collection_contains((GeeCollection*) self->g->children,
                                   ((PySoy_widgets_Widget_Object*) value)->g);
}


///////////////////////////////////////////////////////////////////////////////
// Type structs

static PySequenceMethods tp_as_sequence = {
    (lenfunc) tp_sq_length,                                // sq_length
    0,                                                     // sq_concat
    0,                                                     // sq_repeat
    (ssizeargfunc) tp_sq_item,                             // sq_item
    0,                                                     // sq_ass_item
    (ssizeobjargproc) tp_sq_contains,                      // sq_contains
    0,                                                     // sq_inplace_concat
    0,                                                     // sq_inplace_repeat
};


PyTypeObject PySoy_widgets_Container_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.widgets.Container",                               // tp_name
    sizeof(PySoy_widgets_Container_Object),                // tp_basicsize
    0,                                                     // tp_itemsize
    0,                                                     // tp_dealloc
    0,                                                     // tp_print
    (getattrfunc) 0,                                       // tp_getattr
    (setattrfunc) 0,                                       // tp_setattr
    0,                                                     // tp_compare
    (reprfunc) tp_repr,                                    // tp_repr
    0,                                                     // tp_as_number
    &tp_as_sequence,                                       // tp_as_sequence
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
    0,                                                     // tp_getset
    &PySoy_widgets_Widget_Type,                            // tp_base
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
