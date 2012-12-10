/*
    PySoy - soy.widgets.Window Type
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
#define SELF PySoy_widgets_Window_Object*


static char
tp_doc[] = "soy.widgets.Window Type\n"
"\n"
"    Window objects are automatically created for all soy.Client instances.\n"
"    These may represent a floating window which may be made fullscreen, an\n"
"    embedded frame within another application such as a web browser, or a\n"
"    framebuffer on a phone or dedicated gaming console.  Depending on the\n"
"    Client these windows may be resizable, may include a title, may support\n"
"    borderless and/or fullscreen modes, may support changing display\n"
"    resolution, or may only support fullscreen mode with the resolution\n"
"    offered by the Client's physical hardware.\n"
"\n"
"    Windows created by PySoy directly may be added to container widgets for\n"
"    a floating \"subwindow\" within a container widget, but are otherwise\n"
"    not rendered in any form.  To create a local X11 window, create a new\n"
"    soy.Client instance which will provide a window automatically.\n";


///////////////////////////////////////////////////////////////////////////////
// Function Prototypes

static int
background_setter (SELF self, PyObject* value, void* closure);


static int
title_setter (SELF self, PyObject* value, void* closure);

static int
fps_setter (SELF self, PyObject* value, void* closure);

static int
resizable_setter (SELF self, PyObject* value, void* closure);

///////////////////////////////////////////////////////////////////////////////
// Type Functions

static SELF
tp_new (PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;

    // inherit base type
    self = (SELF) PyType_GenericNew(type, args, kwds);
    if (!self)
      return NULL;

    // new gobject
    // TODO remove these NULL args once libsoy's API has been updated to match
    self->g = soy_widgets_window_new(NULL);

    return self;
}


static int
tp_init (SELF self, PyObject* args, PyObject* kwds) {
    PyObject* parent = NULL;
    PyObject* title = NULL;
    PyObject* background = NULL;
	PyObject* resizable = NULL;

    static char* kw[] = {"parent", "title", "background", "resizable", NULL};

    // Parse arguments
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|OOO", kw,
                                     &parent, &title, &background, &resizable))
        return -1;

    // Set title property if provided
    if (title && title_setter(self, title, NULL) == -1)
        return -1;

    // Set background property if provided
    if (background && background_setter(self, background, NULL) == -1)
        return -1;

    return 0;
}


static PyObject*
tp_repr (SELF self) {
    // TODO this should report additional debug information such as the host
    // the window is displayed on, whether its decorated and can be resized,
    // current size, position, number of widgets, fps, etc.
    return PyUnicode_FromFormat("<Window>");
}


///////////////////////////////////////////////////////////////////////////////
// Properties

PYSOY_PROP_OBJECT_OWNED(widgets, window, background, atoms_Color)
static char
background_doc[] = {"Window background color"};

// TODO icon property


PYSOY_PROP_OBJECT_OWNED(widgets, window, position, atoms_Position)
static char
position_doc[] = {"Window position on display"};

PYSOY_PROP_OBJECT(widgets, widget, size, atoms_Size)
static char
size_doc[] = {"Window size"};


/*static PyObject*
PySoy_widgets_Window_size_getter (PySoy_widgets_Window_Object* self,
                                  void* closure) {
    PySoy_atoms_Size_Object* ret;

    // create python color object
    ret = (PySoy_atoms_Size_Object*) PyType_GenericNew(&PySoy_atoms_Size_Type,
                                                         NULL, NULL);
    if (!ret)
        return NULL;

    // attach value, backend object and set function
    soy_widgets_widget_get_size((soywidgetsWidget*) self->g, &ret->value);
    ret->g = (GObject*) self->g;
    ret->set_func = (void(*)(GObject*,soyatomsSize*)) soy_widgets_widget_set_size;

    // incref backend
    g_object_ref(self->g);

    // return value
    return (PyObject*) ret;
}

static int
PySoy_widgets_Window_size_setter (PySoy_widgets_Window_Object* self,
                                  PyObject* value, void* closure) {
    // Property cannot be deleted
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError, "cannot delete this property");
        return -1;
    }

    // ensure value is a Size object
    if (!PySoy_atoms_Size_Check(value)) {
        // TODO try to turn supplied value into a color
        PyErr_SetString(PyExc_TypeError, "size property must be a Size object");
        return -1;
    }

    // set the size
    soy_widgets_widget_set_size((soywidgetsWidget*) self->g,
                                &((PySoy_atoms_Size_Object*) value)->value);
    return 0;
}*/

static char
resizable_doc[] = {"Indicates whether window can be resized or not"};

static PyObject*
resizable_getter(SELF self, void* closure) {
	return PyBool_FromLong(soy_widgets_window_get_resizable(self->g));
}

static int
resizable_setter(SELF self, PyObject* value, void* closure) {
    if(!PyBool_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "resizable must be a boolean value.");
        return -1;
    } 

    // Note: Find out how to cast value (type PyObject*) to GValue, to reduce to one single, pretty line
    // soy_widgets_window_set_resizable(self->g, TRUE/FALSE);
    if(value == Py_True) {
        soy_widgets_window_set_resizable(self->g, TRUE);
    } else {
        soy_widgets_window_set_resizable(self->g, FALSE);
    }
    return 0;
}

static char
fps_doc[] = {"Window frames per second"};

static PyObject*
fps_getter(SELF self, void* closure) {
	return PyLong_FromLong((long)soy_widgets_window_get_fps(self->g)); // returns the framerate as a PyObject integer
}

static int
fps_setter(SELF self, PyObject* value, void* closure) {
    PyErr_SetString(PyExc_AttributeError, "cannot edit this property");
    return -1;
}

static char
title_doc[] = {"Window title"};

static PyObject*
title_getter (SELF self, void* closure) {
    const gchar* title = soy_widgets_window_get_title(self->g);

    // return empty string if title is undefined
    if (title == NULL) title = "";

    return PyUnicode_FromString(title);
}

static int
title_setter (SELF self, PyObject* value, void* closure) {
    PyObject* bytes;

    // Property cannot be deleted
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError, "cannot delete this property");
        return -1;
    }

    // ensure its a unicode object
    if (!PyUnicode_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "title attribute must be a string");
        return -1;
    }

    // encode Unicode string as UTF-8 bytes object
    bytes = PyUnicode_AsUTF8String(value);

    // set title
    soy_widgets_window_set_title(self->g, PyBytes_AsString(bytes));

    // clean up bytes object
    Py_DECREF(bytes);

    return 0;
}


///////////////////////////////////////////////////////////////////////////////
// Type structs

static PyMethodDef tp_methods[] = {
    {NULL},                                                 // sentinel
};


static PyGetSetDef tp_getset[] = {
    PYSOY_PROPSTRUCT(background),
    PYSOY_PROPSTRUCT(position),
    PYSOY_PROPSTRUCT(size),
    PYSOY_PROPSTRUCT(title),
	PYSOY_PROPSTRUCT(fps),
	PYSOY_PROPSTRUCT(resizable),
    {NULL},                                                 // sentinel
};


PyTypeObject PySoy_widgets_Window_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.widgets.Window",                                  // tp_name
    sizeof(PySoy_widgets_Window_Object),                   // tp_basicsize
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
    tp_methods,                                            // tp_methods
    0,                                                     // tp_members
    tp_getset,                                             // tp_getset
    &PySoy_widgets_Container_Type,                         // tp_base
    0,                                                     // tp_dict
    0,                                                     // tp_descr_get
    0,                                                     // tp_descr_set
    0,                                                     // tp_dictoffset
    (initproc) tp_init,                                    // tp_init
    0,                                                     // tp_alloc
    (newfunc) tp_new,                                      // tp_new
    0,                                                     // tp_free
    0,                                                     // tp_is_gc
};
