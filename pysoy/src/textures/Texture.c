/*
    PySoy - soy.textures.Texture Type
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
#define SELF PySoy_textures_Texture_Object*


static char
tp_doc[] = "soy.textures.Texture Type\n"
"\n"
"    A PySoy texture is an OpenGL texture.\n"
"    A texture is a type that contains one or more images that all have\n"
"    the same image format.\n"
"    It can be used as a render target (for exapmle from soy.widgets.Canvas\n"
"    or CameraBody)\n"
"\n"
"    A texture is accessed like a list of soy.atoms.Color type\n"
"    Indexing a texture with Texture[x] will always return a\n"
"    soy.atoms.Color (or raise an exception because x is out of bounds)\n"
"\n";
// TODO


static PyObject*
tp_new (PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;
    const gchar* filename = NULL;
    gboolean png=0, svg=0;

    // Ensure no keywords were provided
    if (!_PyArg_NoKeywords("soy.textures.Texture", kwds))
        return NULL;

    // Parse arguments
    if (!PyArg_ParseTuple(args, "s", &filename)) {
        PyErr_Clear();
        if (!PyArg_ParseTuple(args, ""))
            return NULL;
    }

    if (filename) {
        png = g_str_has_suffix(filename, ".png");
        svg = (g_str_has_suffix(filename, ".svg") ||
               g_str_has_suffix(filename, ".sgk"));
        if (!(png || svg)) {
            PyErr_SetString(PyExc_ValueError, "Unrecognized mime-type");
            return NULL;
        }
    }

    // inherit base type
    self = (SELF) PyType_GenericNew(type, args, kwds);
    if (!self)
      return NULL;

    // new gobject for PNG file
    if (png)
        self->g = soy_textures_texture_new_from_png(filename);

    // new gobject for SVG/SGK file
    else if (svg)
        self->g = soy_textures_texture_new_from_svg(filename);

    // new gobject
    else
        self->g = soy_textures_texture_new();

    // return self
    return (PyObject*) self;
}


static PyObject*
tp_repr (SELF self) {
    gchar* str;
    PyObject* ret;

    // generate "<Texture>" string
    str = g_strdup_printf("<Texture>");

    // return string as unicode object
    ret = PyUnicode_FromString(str);
    g_free(str);
    return ret;
}


///////////////////////////////////////////////////////////////////////////////
// Number Methods

// TODO


///////////////////////////////////////////////////////////////////////////////
// Sequence Methods

static Py_ssize_t
sq_length(SELF self) {
    soyatomsSize* size;
    float width, height;

    size = soy_textures_texture_get_size(self->g);
    width = soy_atoms_size_get_width(size);
    height = soy_atoms_size_get_height(size);
    g_object_unref(size);

    return (Py_ssize_t) (width * height);
}


static PyObject*
sq_item(SELF self, Py_ssize_t index) {
    soyatomsColor* g = soy_textures_texture_get(self->g, index);
    PyObject* ret;

    // Raise exception if NULL was returned
    if (!g) {
        PyErr_SetString(PyExc_IndexError, "Texture index out of range");
        return NULL;
    }

    ret = PyType_GenericNew(&PySoy_atoms_Color_Type, NULL, NULL);

    // Raise exception if new Color object couldn't be created
    if (!ret) {
        PyErr_SetString(PyExc_RuntimeError, "Could not create return object");
        return NULL;
    }

    // Set backend storage and return
    ((PySoy_atoms_Color_Object*) ret)->g = g;
    return ret;
}


//Set a specific give soyatomsColor at a given index in the texture
static int
sq_ass_item(SELF self, Py_ssize_t index, PyObject* value) {
    soyatomsSize* size;

    // Ensure value is a Color
    if (!PySoy_atoms_Color_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "value must be soy.atoms.Color");
        return -1;
    }

    // Ensure index is in range
    size = soy_textures_texture_get_size(self->g);
    if (index < 0 || index >=
        soy_atoms_size_get_width(size)*soy_atoms_size_get_height(size)) {
        g_object_unref(size);
        PyErr_SetString(PyExc_IndexError, "Texture index out of range");
        return -1;
    }
    g_object_unref(size);

    // Set texel using backend set function
    soy_textures_texture_set(self->g, index,
                             (GObject*)((PySoy_atoms_Color_Object*) value)->g);
    return 0;
}


///////////////////////////////////////////////////////////////////////////////
// General Methods

// TODO


///////////////////////////////////////////////////////////////////////////////
// Properties

// TODO animate

static char
aspect_doc[] = "Aspect Ratio\n"
"\n"
"    The aspect ratio is the ratio of x (width) to y (height).\n"
"    (like 16:9, 4:3, etc.)\n"
"\n";
PYSOY_PROP_FLOAT_RO(textures, texture, aspect)
#define aspect_setter NULL


static char
channels_doc[] = "Number of Channels (L, LA, RGB, or RGBA)";
PYSOY_PROP_FLOAT(textures, texture, channels)


static char
size_doc[] = "Texture size";
PYSOY_PROP_OBJECT(textures, texture, size, atoms_Size)


static char
smooth_doc[] = "soy.textures.Texture.smooth\n"
"\n"
"    This property controls whether pixels that are smaller than texels are\n"
"    rendered as a smooth transition between them. If False, pixels rendered\n"
"    from this Texture will use the closest texel value instead.\n"
"\n"
"    This property defaults to True.\n"
"\n";
PYSOY_PROP_BOOL(textures, texture, smooth)


///////////////////////////////////////////////////////////////////////////////
// Type structs


/* TODO
static PyNumberMethods PySoy_textures_Texture_NumberMethods[] = {
     PySoy_textures_Texture_nb_add,                        // nb_add
     PySoy_textures_Texture_nb_subtract,                   // nb_subtract
     PySoy_textures_Texture_nb_multiply,                   // nb_multiply
     0,                                                    // nb_remainder
     0,                                                    // nb_divmod
     0,                                                    // nb_power
     0,                                                    // nb_negative
     0,                                                    // nb_positive
     0,                                                    // nb_absolute
     0,                                                    // nb_bool
     0,                                                    // nb_invert
     0,                                                    // nb_lshift
     0,                                                    // nb_rshift
     0,                                                    // nb_and
     0,                                                    // nb_xor
     0,                                                    // nb_or
     0,                                                    // nb_int
     0,                                                    // nb_reserved
     0,                                                    // nb_float
     0,                                                    // nb_inplace_add
     0,                                                    // nb_inplace_subtract
     0,                                                    // nb_inplace_multiply
     0,                                                    // nb_inplace_remainder
     0,                                                    // nb_inplace_power
     0,                                                    // nb_inplace_lshift
     0,                                                    // nb_inplace_rshift
     0,                                                    // nb_inplace_and
     0,                                                    // nb_inplace_xor
     0,                                                    // nb_inplace_or
     0,                                                    // nb_floor_divide
     PySoy_textures_Texture_nb_true_divide,                // nb_true_divide
     0,                                                    // nb_inplace_floor_divide
     0,                                                    // nb_inplace_true_divide
     0,                                                    // nb_index
};
*/

static PySequenceMethods tp_as_sequence = {
    (lenfunc) sq_length,                                   // sq_length
    0,                                                     // sq_concat
    0,                                                     // sq_repeat
    (ssizeargfunc) sq_item,                                // sq_item
    0,                                                     // was_sq_slice
    (ssizeobjargproc) sq_ass_item,                         // sq_ass_item
    0,                                                     // was_sq_ass_slice
    0,                                                     // sq_contains
    0,                                                     // sq_inplace_concat
    0,                                                     // sq_inplace_repeat
};


static PyMethodDef tp_methods[] = {
    // TODO
    {NULL},                                                // sentinel
};


static PyGetSetDef tp_getset[] = {
    PYSOY_PROPSTRUCT(aspect),
    PYSOY_PROPSTRUCT(channels),
    PYSOY_PROPSTRUCT(size),
    PYSOY_PROPSTRUCT(smooth),
    {NULL},                                                // sentinel
};


PyTypeObject PySoy_textures_Texture_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.textures.Texture",                                // tp_name
    sizeof(PySoy_textures_Texture_Object),                 // tp_basicsize
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
    (newfunc) tp_new,                                      // tp_new
    0,                                                     // tp_free
    0,                                                     // tp_is_gc
};

