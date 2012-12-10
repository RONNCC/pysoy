/*
    PySoy - soy.materials.Textured Type
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
#define SELF PySoy_materials_Textured_Object*


static char
tp_doc[] = "soy.materials.Textured Type\n"
"\n"
"    Textured materials support one or more basic texture types plus the\n"
"    standard Colored components (ambient, diffuse, specular, emission)\n"
"    which are multiplied by the texture color to provide shading.\n"
"\n"
"    Currently .bumpmap .colormap and .glowmap are supported.\n";


static SELF
tp_new (PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;
    const gchar* name = NULL;
    PySoy_textures_Texture_Object* py_bumpmap = NULL;
    PySoy_textures_Texture_Object* py_colormap = NULL;
    PySoy_textures_Texture_Object* py_glowmap = NULL;
    soytexturesTexture* bumpmap = NULL;
    soytexturesTexture* colormap = NULL;
    soytexturesTexture* glowmap = NULL;
    static char* kw[] = {"name", "bumpmap", "colormap", "glowmap", NULL};

    // Parse arguments
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|sO!O!O!", kw,
            &name,
            &PySoy_textures_Texture_Type, &py_bumpmap,
            &PySoy_textures_Texture_Type, &py_colormap,
            &PySoy_textures_Texture_Type, &py_glowmap))
        return NULL;

    // Grab optional texture gobjects
    bumpmap = (py_bumpmap) ? py_bumpmap->g : NULL;
    colormap = (py_colormap) ? py_colormap->g : NULL;
    glowmap = (py_glowmap) ? py_glowmap->g : NULL;

    // inherit base type
    self = (SELF) PyType_GenericNew(type, args, kwds);
    if (!self)
        return NULL;

    // new gobject
    self->g = soy_materials_textured_new(name, bumpmap, colormap, glowmap);

    // return self
    return self;
}


static PyObject*
tp_repr (SELF self) {
    return PyUnicode_FromFormat("<Textured>");
}


///////////////////////////////////////////////////////////////////////////////
// Properties

PYSOY_PROP_OBJECT_OWNED(materials, textured, bumpmap, textures_Texture)
static char
bumpmap_doc[] = "Bumpmap Texture\n"
"    When a :class:`~soy.textures.Texture` is assigned to this property it\n"
"    will render as a bumpmap. The RGB values of the texture alter the\n"
"    direction light is reflected off the surface of the material.\n"
"\n"
"    This allows artists to add fine-grained detail to 3d objects or the\n"
"    give otherwise smooth/flat surfaces an appearance that changes with\n"
"    the angle of light to the camera (shadows/highlights).\n"
"\n"
"    In OpenGL terms, this texture is a dot3 normal map in tangent-space\n"
"    which is mapped to object space by combining a normalisation cubemap.\n"
"\n"
"    Default is None (disabled).\n";


PYSOY_PROP_OBJECT_OWNED(materials, textured, colormap, textures_Texture)
static char
colormap_doc[] = "Colormap Texture\n"
"\n"
"    When a :class:`~soy.textures.Texture` is assigned to this property it\n"
"    will be rendered as the surface color of the material.\n"
"\n"
"    In OpenGL terms, this texture is set GL_MODULATE to the lit material\n"
"    color which provides it's shading. Textures with an alpha component\n"
"    will be translucent to the material's lit color, so to achieve actual\n"
"    translucency the ambient and diffuse must also be translucent.\n"
"\n"
"    Default is None (disabled).\n";


PYSOY_PROP_OBJECT_OWNED(materials, textured, glowmap, textures_Texture)
static char
glowmap_doc[] = "Glowmap Texture\n"
"\n"
"    When a :class:`~soy.textures.Texture` is assigned to this property it\n"
"    will be rendered as the surface glow of a material.\n"
"\n"
"    In OpenGL terms, this texture is set as GL_ADD.\n"
"\n"
"    Default is None (disabled).\n";


///////////////////////////////////////////////////////////////////////////////
// Type structs

static PyGetSetDef tp_getset[] = {
    PYSOY_PROPSTRUCT(bumpmap),
    PYSOY_PROPSTRUCT(colormap),
    PYSOY_PROPSTRUCT(glowmap),
    {NULL}                                                 // sentinel
};


PyTypeObject PySoy_materials_Textured_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.materials.Textured",                              // tp_name
    sizeof(PySoy_materials_Textured_Object),               // tp_basicsize
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
    &PySoy_materials_Colored_Type,                         // tp_base
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

