/*
    PySoy - C Header
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

#ifndef __PYSOY_H__
#define __PYSOY_H__

#include <Python.h>
#include <soy-1/soy.h>
#include <soy-1/config.h>
#include <gio/gio.h>
#include <X11/extensions/XInput2.h>
#include <EGL/egl.h>


/////////////////////////////////////////////////////////////////////////////
// __credits__ doc string for for each module

#define PYSOY_CREDITS "" \
"Copyright (C) 2006,2007,2008,2009,2010,2011,2012 Copyleft Games Group\n" \
"\n" \
"    This program is free software; you can redistribute it and/or modify\n" \
"    it under the terms of the GNU Affero General Public License as published\n" \
"    by the Free Software Foundation, either version 3 of the License, or\n" \
"    (at your option) any later version.\n" \
"\n" \
"    This program is distributed in the hope that it will be useful,\n" \
"    but WITHOUT ANY WARRANTY; without even the implied warranty of\n" \
"    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n" \
"    GNU Affero General Public License for more details.\n" \
"\n" \
"    You should have received a copy of the GNU Affero General Public License\n" \
"    along with this program; if not, see http://www.gnu.org/licenses\n" \
"\n"


// __version__ doc string is provided by distutils

GQuark GPyObject;


/////////////////////////////////////////////////////////////////////////////
// Macros

#define PYSOY_TYPEADD(M, T) \
    Py_INCREF(&PySoy_ ## M ## _ ## T ## _Type);\
    PyModule_AddObject(module, #T, (PyObject*)&PySoy_ ## M ## _ ## T ## _Type)


#define PYSOY_TYPEADD_G(M, C, T) \
    PYSOY_TYPEADD(M, T);\
    g_type_set_qdata(soy_ ## M ## _ ## C ## _get_type (), GPyObject,\
                     &PySoy_ ## M ## _ ## T ## _Type)


#define PYSOY_TYPEINIT(m, t) \
    if (PyType_Ready(&PySoy_ ## m ## _ ## t ## _Type) < 0) return NULL


#define PYSOY_TYPEINIT_PROP(M, C, T, P, GETTER, SETTER, CHECKTYPE) do {\
    g_type_class_ref(soy_ ## M ## _ ## C ## _get_type());\
    gpointer g = soy_ ## M ## _ ## C ## _get_ ## P();\
    PyObject* py = PyType_GenericNew(g_type_get_qdata(G_OBJECT_TYPE(g),\
                                                      GPyObject), NULL, NULL);\
    ((PySoy__G_Object*) py)->g = g;\
    ((PySoy__GeeMap_Object*) py)->get = GETTER;\
    ((PySoy__GeeMap_Object*) py)->set = SETTER;\
    ((PySoy__GeeMap_Object*) py)->check_type = CHECKTYPE;\
    g_object_ref(g);\
    PyMapping_SetItemString(PySoy_ ## M ## _ ## T ## _Type.tp_dict, #P, py);\
    } while (0)

// PYSOY_PROP_BOOL
//   M (Module) is the module name (lowercase)
//   C (Class) is the libsoy Class (lowercase)
//   P (Property) is the libsoy property (lowercase)
//   ie; PYSOY_PROP_BOOL(atoms, color, alpha)
#define PYSOY_PROP_BOOL(M, C, P) \
static PyObject*\
P ## _getter (SELF self, void* closure) {\
    return PyBool_FromLong(soy_ ## M ## _ ## C ## _get_ ## P \
                           ((gpointer) self->g) );\
}\
static int \
P ## _setter (SELF self, PyObject* value, void* closure) {\
    int b;\
    if (value==NULL) {\
        PyErr_SetString(PyExc_AttributeError, \
                        "cannot delete " #P " property"); \
        return -1;\
    }\
    b = PyObject_IsTrue(value);\
    if (b == -1) {\
        return -1;\
    }\
    soy_ ## M ## _ ## C ## _set_ ## P ((gpointer) self->g, b);\
    return 0;\
}

// PYSOY_PROP_BOOL_RO - Read Only
//   M (Module) is the module name (lowercase)
//   C (Class) is the libsoy Class (lowercase)
//   P (Property) is the libsoy property (lowercase)
//   ie; PYSOY_PROP_BOOL_RO(atoms, color, alpha)
#define PYSOY_PROP_BOOL_RO(M, C, P) \
static PyObject*\
P ## _getter (SELF self, void* closure) {\
    return PyBool_FromLong(soy_ ## M ## _ ## C ## _get_ ## P \
                           ((gpointer) self->g) );\
}

// PYSOY_PROP_UCHAR
//   M (Module) is the module name (lowercase)
//   C (Class) is the libsoy Class (lowercase)
//   P (Property) is the libsoy property (lowercase)
//   ie; PYSOY_PROP_UCHAR(atoms, color, alpha)
#define PYSOY_PROP_UCHAR(M, C, P) \
static PyObject*\
P ## _getter (SELF self, void* closure) {\
    return PyLong_FromLong(soy_ ## M ## _ ## C ## _get_ ## P \
                           ((gpointer) self->g) );\
}\
static int \
P ## _setter (SELF self, PyObject* value, void* closure) {\
    if (value==NULL) {\
        PyErr_SetString(PyExc_AttributeError, \
                        "cannot delete " #P " property"); \
        return -1;\
    }\
    if (!PyLong_Check(value)) {\
        PyErr_SetString(PyExc_TypeError, \
                        "Value must be an integer"); \
        return -1;\
    }\
    soy_ ## M ## _ ## C ## _set_ ## P ((gpointer) self->g, \
                                       PyLong_AsLong(value));\
    return 0;\
}

// PYSOY_PROP_FLOAT
//   M (Module) is the module name (lowercase)
//   C (Class) is the libsoy Class (lowercase)
//   P (Property) is the libsoy property (lowercase)
//   ie; PYSOY_PROP_FLOAT(atoms, color, alpha)
#define PYSOY_PROP_FLOAT(M, C, P) \
static PyObject*\
P ## _getter (SELF self, void* closure) {\
    return PyFloat_FromDouble(soy_ ## M ## _ ## C ## _get_ ## P \
                              ((gpointer) self->g) );\
}\
static int \
P ## _setter (SELF self, PyObject* value, void* closure) {\
    if (value==NULL) {\
        PyErr_SetString(PyExc_AttributeError, \
                        "cannot delete " #P " property"); \
        return -1;\
    }\
    if (!PyNumber_Check(value)) {\
        PyErr_SetString(PyExc_TypeError, \
                        "Value must be a number"); \
        return -1;\
    }\
    soy_ ## M ## _ ## C ## _set_ ## P ((gpointer) self->g, \
                                       PyFloat_AsDouble(value));\
    return 0;\
}


// PYSOY_PROP_FLOAT_RO - Read Only
//   M (Module) is the module name (lowercase)
//   C (Class) is the libsoy Class (lowercase)
//   P (Property) is the libsoy property (lowercase)
//   ie; PYSOY_PROP_FLOAT(textures, texture, aspect)
#define PYSOY_PROP_FLOAT_RO(M, C, P) \
static PyObject*\
P ## _getter (SELF self, void* closure) {\
    return PyFloat_FromDouble(soy_ ## M ## _ ## C ## _get_ ## P \
                              ((gpointer) self->g) );\
}


// PYSOY_PROP_STRING
//   M (Module) is the module name (lowercase)
//   C (Class) is the libsoy Class (lowercase)
//   P (Property) is the libsoy property (lowercase)
//   ie; PYSOY_PROP_STRING(atoms, color, hex)
#define PYSOY_PROP_STRING(M, C, P) \
static PyObject*\
P ## _getter (SELF self, void* closure) {\
    return PyUnicode_FromString(soy_ ## M ## _ ## C ## _get_ ## P \
                              ((gpointer) self->g) );\
}\
static int \
P ## _setter (SELF self, PyObject* value, void* closure) {\
    PyObject* bytes; \
    if (value==NULL) { \
        PyErr_SetString(PyExc_AttributeError, \
                        "cannot delete " #P " property"); \
        return -1;\
    }\
    if (!PyUnicode_Check(value)) {\
        PyErr_SetString(PyExc_TypeError, \
                        "Value must be a string"); \
        return -1;\
    }\
	bytes = PyUnicode_AsUTF8String(value); \
    soy_ ## M ## _ ## C ## _set_ ## P ((gpointer) self->g, \
                                       PyBytes_AsString(bytes));\
    return 0;\
}


// PYSOY_PROP_OBJECT
//   M (Module) is the module name (lowercase)
//   C (Class) is the libsoy Class (lowercase)
//   P (Property) is the libsoy property (lowercase)
//   V (Value) is the PySoy type of property value (as module_Type)
//   ie; PYSOY_PROP(scenes, Scene, ambient, atoms_Color);
#define PYSOY_PROP_OBJECT(M, C, P, V) \
static PyObject*\
P ## _getter (SELF self, void* closure) {\
    gpointer g;\
    PySoy__G_Object* ret;\
    g = soy_ ## M ## _ ## C ## _get_ ## P ((gpointer) self->g);\
    if (!g) Py_RETURN_NONE;\
    ret = (PySoy__G_Object*) \
          PyType_GenericNew(g_type_get_qdata(G_OBJECT_TYPE(g), GPyObject), \
                            NULL, NULL);\
    if (!ret) return NULL;\
    ret->g = g;\
    g_object_ref(g);\
    return (PyObject*) ret;\
}\
static int \
P ## _setter (SELF self, PyObject* value, void* closure) {\
    if (value==NULL) {\
        PyErr_SetString(PyExc_AttributeError, \
                        "cannot delete " #P " property");\
        return -1;\
    }\
    if (PyObject_IsInstance(value, (PyObject*) &PySoy_ ## V ## _Type)!=1){\
        PyErr_SetString(PyExc_TypeError, \
                        "Incorrect type for " #P " property");\
        return -1;\
    }\
    soy_ ## M ## _ ## C ## _set_ ## P ((gpointer) self->g, \
                                       ((PySoy_ ## V ## _Object*) value)->g);\
    return 0;\
}


// PYSOY_PROP_OBJECT_OWNED
//   M (Module) is the module name (lowercase)
//   C (Class) is the libsoy Class (lowercase)
//   P (Property) is the libsoy property (lowercase)
//   V (Value) is the PySoy type of property value (as module_Type)
//   ie; PYSOY_PROP_OBJECT_OWNED(scenes, scene, ambient, atoms_Color);
#define PYSOY_PROP_OBJECT_OWNED(M, C, P, V) \
static PyObject*\
P ## _getter (SELF self, void* closure) {\
    gpointer g;\
    PySoy__G_Object* ret;\
    g = soy_ ## M ## _ ## C ## _get_ ## P ((gpointer) self->g);\
    if (!g) Py_RETURN_NONE;\
    ret = (PySoy__G_Object*) \
          PyType_GenericNew(g_type_get_qdata(G_OBJECT_TYPE(g), GPyObject), \
                            NULL, NULL);\
    if (!ret) return NULL;\
    ret->g = g;\
    return (PyObject*) ret;\
}\
static int \
P ## _setter (SELF self, PyObject* value, void* closure) {\
    if (value==NULL) {\
        PyErr_SetString(PyExc_AttributeError, \
                        "cannot delete " #P " property");\
        return -1;\
    }\
    if (PyObject_IsInstance(value, (PyObject*) &PySoy_ ## V ## _Type)!=1){\
        PyErr_SetString(PyExc_TypeError, \
                        "Incorrect type for " #P " property");\
        return -1;\
    }\
    soy_ ## M ## _ ## C ## _set_ ## P ((gpointer) self->g, \
                                       ((PySoy_ ## V ## _Object*) value)->g);\
    return 0;\
}


// PYSOY_PROP_OBJECT_DELETABLE
//   M (Module) is the module name (lowercase)
//   C (Class) is the libsoy Class (lowercase)
//   P (Property) is the libsoy property (lowercase)
//   V (Value) is the PySoy type of property value (as module_Type)
#define PYSOY_PROP_OBJECT_DELETABLE(M, C, P, V) \
static PyObject*\
P ## _getter (SELF self, void* closure) {\
    gpointer g;\
    PySoy__G_Object* ret;\
    g = soy_ ## M ## _ ## C ## _get_ ## P ((gpointer) self->g);\
    if (!g) Py_RETURN_NONE;\
    ret = (PySoy__G_Object*) \
          PyType_GenericNew(g_type_get_qdata(G_OBJECT_TYPE(g), GPyObject), \
                            NULL, NULL);\
    if (!ret) return NULL;\
    ret->g = g;\
    g_object_ref(g);\
    return (PyObject*) ret;\
}\
static int \
P ## _setter (SELF self, PyObject* value, void* closure) {\
    if (value==NULL || value==Py_None) {\
        soy_ ## M ## _ ## C ## _set_ ## P ((gpointer) self->g, NULL);\
        return 0;\
    }\
    if (PyObject_IsInstance(value, (PyObject*) &PySoy_ ## V ## _Type)!=1){\
        PyErr_SetString(PyExc_TypeError, \
                        "Incorrect type for " #P " property");\
        return -1;\
    }\
    soy_ ## M ## _ ## C ## _set_ ## P ((gpointer) self->g, \
                                       ((PySoy_ ## V ## _Object*) value)->g);\
    return 0;\
}


// PYSOY_PROP_OBJECT_MEMBER
//   M (Module) is the module name (lowercase)
//   C (Class) is the libsoy Class (lowercase)
//   T (Type) is the PySoy Type (Titled)
//   P (Property) is the libsoy property (lowercase)
//   V (Value) is the PySoy type of property value (as module_Type)
//  This works the same as PYSOY_PROP_OBJECT but with libsoy object members
#define PYSOY_PROP_OBJECT_MEMBER(M, C, T, P, V) \
static PyObject*\
PySoy_ ## M ## _ ## T ## _ ## P ## _getter (PySoy_ ## M ## _ ## T ## _Object*\
                                            self,\
                                            void* closure) {\
    gpointer g;\
    PySoy__G_Object* ret;\
    g = self->g->P;\
    ret = (PySoy__G_Object*) \
          PyType_GenericNew(g_type_get_qdata(G_OBJECT_TYPE(g), GPyObject), \
                            NULL, NULL);\
    if (!ret) return NULL;\
    ret->g = g;\
    g_object_ref(g);\
    return (PyObject*) ret;\
}\
static int \
PySoy_ ## M ## _ ## T ## _ ## P ## _setter (PySoy_ ## M ## _ ## T ## _Object* \
                                            self, \
                                            PyObject* value, void* closure) {\
    if (value==NULL) {\
        PyErr_SetString(PyExc_AttributeError, \
                        "cannot delete " #P " property");\
        return -1;\
    }\
    if (PyObject_IsInstance(value, (PyObject*) &PySoy_ ## V ## _Type)!=1){\
        PyErr_SetString(PyExc_TypeError, \
                        "Incorrect type for " #P " property");\
        return -1;\
    }\
    if (self->g->P)\
        g_object_unref(self->g->P);\
    if (value==NULL)\
        self->g->P = NULL;\
    else {\
        self->g->P = ((PySoy_ ## V ## _Object*) value)->g;\
        g_object_ref(self->g->P);\
    }\
    return 0;\
}


// PYSOY_PROP_OBJECT_LIST
//  M (Module) is the module name (lowercase)
//  C (Class) is the libsoy class (lowercase)
//  P (Property) is the property name (lowercase)
//  ie; PYSOY_PROP_LIST(models, target, Target, morphs)
#define PYSOY_PROP_OBJECT_LIST(M, C, P) \
static PyObject*\
P ## _getter (SELF self, void* closure) {\
    gint size;\
    gpointer g;\
    PyObject* ret;\
    PySoy__G_Object* obj;\
    GeeArrayList* lst;\
    gint i;\
    lst = soy_ ## M ## _ ## C ## _get_ ## P(self->g);\
    size = gee_collection_get_size((GeeCollection*) lst);\
    ret = PyList_New(size);\
    for(i=0;i<size;i++){\
        g = gee_list_get((GeeList*)lst,i);\
        obj = (PySoy__G_Object*) \
          PyType_GenericNew(g_type_get_qdata(G_OBJECT_TYPE(g), GPyObject), \
                            NULL, NULL);\
        if (!obj) return NULL;\
        obj->g = g;\
        g_object_ref(g);\
        Py_INCREF(obj);\
        PyList_SetItem(ret,i,(PyObject*)obj);\
    }\
    Py_INCREF(ret);\
    return ret;\
}\
static int \
P ## _setter (SELF self, PyObject* value, void* closure) {\
    return 0;\
}


// PYSOY_PROPSTRUCT
//   P (Property) is the property name
#define PYSOY_PROPSTRUCT(P) \
    {#P,\
     (getter) P ## _getter,\
     (setter) P ## _setter,\
     P ## _doc,\
     NULL}


/////////////////////////////////////////////////////////////////////////////
// soy

// soy._G
PyTypeObject PySoy__G_Type;
typedef struct {
    PyObject_HEAD
    gpointer g;
} PySoy__G_Object;
#define PySoy__G_Check(op) \
    PyObject_TypeCheck(op, &PySoy__G_Type)

// soy._GeeIterable
PyTypeObject PySoy__GeeIterable_Type;
typedef struct {
    PyObject_HEAD
    GeeIterable* g;
} PySoy__GeeIterable_Object;
#define PySoy__GeeIterable_Check(op) \
    PyObject_TypeCheck(op, &PySoy__GeeIterable_Type)

// soy._GeeMap
PyTypeObject PySoy__GeeMap_Type;
typedef struct {
    PyObject_HEAD
    GeeMap* g;
    gpointer (*get)(gpointer, const gchar*);
    void (*set)(gpointer, const gchar*, gpointer);
    int (*check_type)(gpointer);
} PySoy__GeeMap_Object;
#define PySoy__GeeMap_Check(op) \
    PyObject_TypeCheck(op, &PySoy__GeeMap_Type)

// soy._Importer
PyTypeObject PySoy__Importer_Type;
typedef struct {
    PyObject_HEAD
    gchar* path;
} PySoy__Importer_Object;
#define PySoy__Importer_Check(op) \
    PyObject_TypeCheck(op, &PySoy__Importer_Type)

/////////////////////////////////////////////////////////////////////////////
// soy.atoms

PyMODINIT_FUNC PyInit_soy_atoms(void);

// soy.atoms.Area
PyTypeObject PySoy_atoms_Area_Type;
typedef struct {
    PyObject_HEAD
    soyatomsArea* g;
} PySoy_atoms_Area_Object;
#define PySoy_atoms_Area_Check(op) \
    PyObject_TypeCheck(op, &PySoy_atoms_Area_Type)

// soy.atoms.Axis
PyTypeObject PySoy_atoms_Axis_Type;
typedef struct {
    PyObject_HEAD
    soyatomsAxis* g;
} PySoy_atoms_Axis_Object;
#define PySoy_atoms_Axis_Check(op) \
    PyObject_TypeCheck(op, &PySoy_atoms_Axis_Type)

// soy.atoms.Color
PyTypeObject PySoy_atoms_Color_Type;
typedef struct {
    PyObject_HEAD
    soyatomsColor* g;
} PySoy_atoms_Color_Object;
#define PySoy_atoms_Color_Check(op) \
    PyObject_TypeCheck(op, &PySoy_atoms_Color_Type)

// soy.atoms.Position
PyTypeObject PySoy_atoms_Position_Type;
typedef struct {
    PyObject_HEAD
    soyatomsPosition* g;                                    // backend object
} PySoy_atoms_Position_Object;
#define PySoy_atoms_Position_Check(op) \
    PyObject_TypeCheck(op, &PySoy_atoms_Position_Type)

// soy.atoms.Rotation
PyTypeObject PySoy_atoms_Rotation_Type;
typedef struct {
    PyObject_HEAD
    soyatomsRotation* g;                                 // backend object
} PySoy_atoms_Rotation_Object;
#define PySoy_atoms_Rotation_Check(op) \
    PyObject_TypeCheck(op, &PySoy_atoms_Rotation_Type)

// soy.atoms.Size
PyTypeObject PySoy_atoms_Size_Type;
typedef struct {
    PyObject_HEAD
    soyatomsSize* g;                                    // backend object
} PySoy_atoms_Size_Object;
#define PySoy_atoms_Size_Check(op) \
    PyObject_TypeCheck(op, &PySoy_atoms_Size_Type)

// soy.atoms.Vector
PyTypeObject PySoy_atoms_Vector_Type;
typedef struct {
    PyObject_HEAD
    soyatomsVector* g;                                            // backend object
} PySoy_atoms_Vector_Object;
#define PySoy_atoms_Vector_Check(op) \
    PyObject_TypeCheck(op, &PySoy_atoms_Vector_Type)

// soy.atoms.Vertex
PyTypeObject PySoy_atoms_Vertex_Type;
typedef struct {
    PyObject_HEAD
    soyatomsVertex* g;                                            // backend object
} PySoy_atoms_Vertex_Object;
#define PySoy_atoms_Vertex_Check(op) \
    PyObject_TypeCheck(op, &PySoy_atoms_Vertex_Type)

// soy.atoms.Face
PyTypeObject PySoy_atoms_Face_Type;
typedef struct {
    PyObject_HEAD
    soyatomsFace* g;                                            // backend object
} PySoy_atoms_Face_Object;
#define PySoy_atoms_Face_Check(op) \
    PyObject_TypeCheck(op, &PySoy_atoms_Face_Type)

// soy.atoms.Morph
PyTypeObject PySoy_atoms_Morph_Type;
typedef struct {
    PyObject_HEAD
    soyatomsMorph* g;                                            // backend object
} PySoy_atoms_Morph_Object;
#define PySoy_atoms_Morph_Check(op) \
    PyObject_TypeCheck(op, &PySoy_atoms_Morph_Type)

/////////////////////////////////////////////////////////////////////////////
// soy.bodies

PyMODINIT_FUNC PyInit_soy_bodies(void);

// soy.bodies.Billboard
PyTypeObject PySoy_bodies_Billboard_Type;
typedef struct {
    PyObject_HEAD
    soybodiesBillboard* g;
} PySoy_bodies_Billboard_Object;
#define PySoy_bodies_Billboard_Check(op) \
    PyObject_TypeCheck(op, &PySoy_bodies_Billboard_Type)

// soy.bodies.Body
PyTypeObject PySoy_bodies_Body_Type;
typedef struct {
    PyObject_HEAD
    soybodiesBody* g;
} PySoy_bodies_Body_Object;
#define PySoy_bodies_Body_Check(op) \
    PyObject_TypeCheck(op, &PySoy_bodies_Body_Type)

// soy.bodies.Box
PyTypeObject PySoy_bodies_Box_Type;
typedef struct {
    PyObject_HEAD
    soybodiesBox* g;
} PySoy_bodies_Box_Object;
#define PySoy_bodies_Box_Check(op) \
    PyObject_TypeCheck(op, &PySoy_bodies_Box_Type)

// soy.bodies.Sphere
PyTypeObject PySoy_bodies_Sphere_Type;
typedef struct {
    PyObject_HEAD
    soybodiesSphere* g;
} PySoy_bodies_Sphere_Object;
#define PySoy_bodies_Sphere_Check(op) \
    PyObject_TypeCheck(op, &PySoy_bodies_Sphere_Type)

// soy.bodies.Camera
PyTypeObject PySoy_bodies_Camera_Type;
typedef struct {
    PyObject_HEAD
    soybodiesCamera* g;
} PySoy_bodies_Camera_Object;
#define PySoy_bodies_Camera_Check(op) \
    PyObject_TypeCheck(op, &PySoy_bodies_Camera_Type)

// soy.bodies.Light
PyTypeObject PySoy_bodies_Light_Type;
typedef struct {
    PyObject_HEAD
    soybodiesLight* g;
} PySoy_bodies_Light_Object;
#define PySoy_bodies_Light_Check(op) \
    PyObject_TypeCheck(op, &PySoy_bodies_Light_Type)

// soy.bodies.Mesh
PyTypeObject PySoy_bodies_Mesh_Type;
typedef struct {
	PyObject_HEAD
	soybodiesMesh* g;
} PySoy_bodies_Mesh_Object;
#define PySoy_bodies_Mesh_Check(op) \
	PyObject_TypeCheck(op, &PySoy_bodies_Mesh_Type)


/////////////////////////////////////////////////////////////////////////////
// soy.controllers

PyMODINIT_FUNC PyInit_soy_controllers(void);

// soy.controllers.Controller
PyTypeObject PySoy_controllers_Controller_Type;
typedef struct {
    PyObject_HEAD
    soycontrollersController* g;
} PySoy_controllers_Controller_Object;
#define PySoy_controllers_Controller_Check(op) \
    PyObject_TypeCheck(op, &PySoy_controllers_Controller_Type)

// soy.controllers.Pointer
PyTypeObject PySoy_controllers_Pointer_Type;
typedef struct {
    PyObject_HEAD
    soycontrollersPointer* g;
} PySoy_controllers_Pointer_Object;
#define PySoy_controllers_Pointer_Check(op) \
    PyObject_TypeCheck(op, &PySoy_controllers_Pointer_Type)

// soy.controllers.Keyboard
PyTypeObject PySoy_controllers_Keyboard_Type;
typedef struct {
    PyObject_HEAD
    soycontrollersKeyboard* g;
} PySoy_controllers_Keyboard_Object;
#define PySoy_controllers_Keyboard_Check(op) \
    PyObject_TypeCheck(op, &PySoy_controllers_Keyboard_Type)

// soy.controllers.VirtualController
PyTypeObject PySoy_controllers_VirtualController_Type;
typedef struct {
    PyObject_HEAD
    soycontrollersVirtualController* g;
} PySoy_controllers_VirtualController_Object;
#define PySoy_controllers_VirtualController_Check(op) \
    PyObject_TypeCheck(op, &PySoy_controllers_VirtualController_Type)


// soy.controllers.Pathfollower
PyTypeObject PySoy_controllers_Pathfollower_Type;
typedef struct {
    PyObject_HEAD
    soycontrollersPathfollower* g;
} PySoy_controllers_Pathfollower_Object;
#define PySoy_controllers_Pathfollower_Check(op) \
    PyObject_TypeCheck(op, &PySoy_controllers_Pathfollower_Type)

// soy.controllers.BaseNavigator
PyTypeObject PySoy_controllers_BaseNavigator_Type;
typedef struct {
    PyObject_HEAD
    soycontrollersBaseNavigator* g;
} PySoy_controllers_BaseNavigator_Object;
#define PySoy_controllers_BaseNavigator_Check(op) \
    PyObject_TypeCheck(op, &PySoy_controllers_BaseNavigator_Type)

// soy.controllers.GridNavigator
PyTypeObject PySoy_controllers_GridNavigator_Type;
typedef struct {
    PyObject_HEAD
    soycontrollersGridNavigator* g;
} PySoy_controllers_GridNavigator_Object;
#define PySoy_controllers_GridNavigator_Check(op) \
    PyObject_TypeCheck(op, &PySoy_controllers_GridNavigator_Type)

// soy.controllers.SpaceNavigator
PyTypeObject PySoy_controllers_SpaceNavigator_Type;
typedef struct {
    PyObject_HEAD
    soycontrollersSpaceNavigator* g;
} PySoy_controllers_SpaceNavigator_Object;
#define PySoy_controllers_SpaceNavigator_Check(op) \
    PyObject_TypeCheck(op, &PySoy_controllers_SpaceNavigator_Type)

// soy.controllers.Wiimote
PyTypeObject PySoy_controllers_Wiimote_Type;
typedef struct {
    PyObject_HEAD
    soycontrollersWiimote* g;
} PySoy_controllers_Wiimote_Object;
#define PySoy_controllers_Wiimote_Check(op) \
    PyObject_TypeCheck(op, &PySoy_controllers_Wiimote_Type)

/////////////////////////////////////////////////////////////////////////////
// soy.fields

PyMODINIT_FUNC PyInit_soy_fields(void);

// soy.fields.Accelerate
PyTypeObject PySoy_fields_Accelerate_Type;
typedef struct {
    PyObject_HEAD
    soyfieldsAccelerate* g;
} PySoy_fields_Accelerate_Object;
#define PySoy_fields_Accelerate_Check(op) \
    PyObject_TypeCheck(op, &PySoy_fields_Accelerate_Type)

// soy.fields.Buoyancy
PyTypeObject PySoy_fields_Buoyancy_Type;
typedef struct {
    PyObject_HEAD
    soyfieldsBuoyancy* g;
} PySoy_fields_Buoyancy_Object;
#define PySoy_fields_Buoyancy_Check(op) \
    PyObject_TypeCheck(op, &PySoy_fields_Buoyancy_Type)

// soy.fields.Field
PyTypeObject PySoy_fields_Field_Type;
typedef struct {
    PyObject_HEAD
    soyfieldsField* g;
} PySoy_fields_Field_Object;
#define PySoy_fields_Field_Check(op) \
    PyObject_TypeCheck(op, &PySoy_fields_Field_Type)

// soy.fields.Monopole
PyTypeObject PySoy_fields_Monopole_Type;
typedef struct {
    PyObject_HEAD
    soyfieldsMonopole* g;
} PySoy_fields_Monopole_Object;
#define PySoy_fields_Monopole_Check(op) \
    PyObject_TypeCheck(op, &PySoy_fields_Field_Type)

// soy.fields.Shockwave
PyTypeObject PySoy_fields_Shockwave_Type;
typedef struct {
    PyObject_HEAD
    soyfieldsShockwave* g;
} PySoy_fields_Shockwave_Object;
#define PySoy_fields_Shockwave_Check(op) \
    PyObject_TypeCheck(op, &PySoy_fields_Field_Type)

// soy.fields.Wind
PyTypeObject PySoy_fields_Wind_Type;
typedef struct {
    PyObject_HEAD
    soyfieldsWind* g;
} PySoy_fields_Wind_Object;
#define PySoy_fields_Wind_Check(op) \
    PyObject_TypeCheck(op, &PySoy_fields_Field_Type)

/////////////////////////////////////////////////////////////////////////////
// soy.joints

PyMODINIT_FUNC PyInit_soy_joints(void);

// soy.joints.Ball
PyTypeObject PySoy_joints_Ball_Type;
typedef struct {
    PyObject_HEAD
    soyjointsBall* g;
} PySoy_joints_Ball_Object;
#define PySoy_joints_Ball_Check(op) \
    PyObject_TypeCheck(op, &PySoy_joints_Ball_Type)

// soy.joints.Fixed
PyTypeObject PySoy_joints_Fixed_Type;
typedef struct {
    PyObject_HEAD
    soyjointsFixed* g;
} PySoy_joints_Fixed_Object;
#define PySoy_joints_Fixed_Check(op) \
    PyObject_TypeCheck(op, &PySoy_joints_Fixed_Type)

// soy.joints.Hinge
PyTypeObject PySoy_joints_Hinge_Type;
typedef struct {
    PyObject_HEAD
    soyjointsHinge* g;
} PySoy_joints_Hinge_Object;
#define PySoy_joints_Hinge_Check(op) \
    PyObject_TypeCheck(op, &PySoy_joints_Hinge_Type)

// soy.joints.Hinge2
PyTypeObject PySoy_joints_Hinge2_Type;
typedef struct {
    PyObject_HEAD
    soyjointsHinge2* g;
} PySoy_joints_Hinge2_Object;
#define PySoy_joints_Hinge2_Check(op) \
    PyObject_TypeCheck(op, &PySoy_joints_Hinge2_Type)

// soy.joints.Joint
PyTypeObject PySoy_joints_Joint_Type;
typedef struct {
    PyObject_HEAD
    soyjointsJoint* g;
} PySoy_joints_Joint_Object;
#define PySoy_joints_Joint_Check(op) \
    PyObject_TypeCheck(op, &PySoy_joints_Joint_Type)

// soy.joints.Piston
PyTypeObject PySoy_joints_Piston_Type;
typedef struct {
    PyObject_HEAD
    soyjointsPiston* g;
} PySoy_joints_Piston_Object;
#define PySoy_joints_Piston_Check(op) \
    PyObject_TypeCheck(op, &PySoy_joints_Piston_Type)

// soy.joints.Plane2D
/*PyTypeObject PySoy_joints_Plane2D_Type;
typedef struct {
    PyObject_HEAD
    soyjointsPlane2D* g;
} PySoy_joints_Plane2D_Object;
#define PySoy_joints_Plane2D_Check(op) \
    PyObject_TypeCheck(op, &PySoy_joints_Plane2D_Type)
libsoy is borked for this joint*/

// soy.joints.Slider
PyTypeObject PySoy_joints_Slider_Type;
typedef struct {
    PyObject_HEAD
    soyjointsSlider* g;
} PySoy_joints_Slider_Object;
#define PySoy_joints_Slider_Check(op) \
    PyObject_TypeCheck(op, &PySoy_joints_Slider_Type)

// soy.joints.Universal
PyTypeObject PySoy_joints_Universal_Type;
typedef struct {
    PyObject_HEAD
    soyjointsUniversal* g;
} PySoy_joints_Universal_Object;
#define PySoy_joints_Universal_Check(op) \
    PyObject_TypeCheck(op, &PySoy_joints_Universal_Type)

/////////////////////////////////////////////////////////////////////////////
// soy.materials

PyMODINIT_FUNC PyInit_soy_materials(void);

// soy.materials.Material
PyTypeObject  PySoy_materials_Material_Type;
typedef struct {
    PyObject_HEAD
    soymaterialsMaterial* g;
} PySoy_materials_Material_Object;
#define PySoy_materials_Material_Check(op) \
    PyObject_TypeCheck(op, &PySoy_materials_Material_Type)

// soy.materials.Colored
PyTypeObject  PySoy_materials_Colored_Type;
typedef struct {
    PyObject_HEAD
    soymaterialsColored* g;
} PySoy_materials_Colored_Object;
#define PySoy_materials_Colored_Check(op) \
    PyObject_TypeCheck(op, &PySoy_materials_Colored_Type)

// soy.materials.Textured
PyTypeObject  PySoy_materials_Textured_Type;
typedef struct {
    PyObject_HEAD
    soymaterialsTextured* g;
} PySoy_materials_Textured_Object;
#define PySoy_materials_Textured_Check(op) \
    PyObject_TypeCheck(op, &PySoy_materials_Textured_Type)

/////////////////////////////////////////////////////////////////////////////
// soy.scenes

PyMODINIT_FUNC PyInit_soy_scenes(void);

// soy.scenes.Scene
PyTypeObject  PySoy_scenes_Scene_Type;
typedef struct {
    PyObject_HEAD
    soyscenesScene* g;
} PySoy_scenes_Scene_Object;
#define PySoy_scenes_Scene_Check(op) \
    PyObject_TypeCheck(op, &PySoy_scenes_Scene_Type)

// soy.scenes.Room
PyTypeObject  PySoy_scenes_Room_Type;
typedef struct {
    PyObject_HEAD
    soyscenesRoom* g;
} PySoy_scenes_Room_Object;
#define PySoy_scenes_Room_Check(op) \
    PyObject_TypeCheck(op, &PySoy_scenes_Room_Type)


/////////////////////////////////////////////////////////////////////////////
// soy.textures

PyMODINIT_FUNC PyInit_soy_textures(void);

// soy.textures.Texture
PyTypeObject  PySoy_textures_Texture_Type;
typedef struct {
    PyObject_HEAD
    soytexturesTexture* g;
} PySoy_textures_Texture_Object;
#define PySoy_textures_Texture_Check(op) \
    PyObject_TypeCheck(op, &PySoy_textures_Texture_Type)


/////////////////////////////////////////////////////////////////////////////
// soy.widgets

PyMODINIT_FUNC PyInit_soy_widgets(void);

// soy.widgets.Widget
PyTypeObject  PySoy_widgets_Widget_Type;
typedef struct {
    PyObject_HEAD
    soywidgetsWidget* g;
} PySoy_widgets_Widget_Object;
#define PySoy_widgets_Widget_Check(op) \
    PyObject_TypeCheck(op, &PySoy_widgets_Widget_Type)

// soy.widgets.Canvas
PyTypeObject  PySoy_widgets_Canvas_Type;
typedef struct {
    PyObject_HEAD
    soywidgetsCanvas* g;
} PySoy_widgets_Canvas_Object;
#define PySoy_widgets_Canvas_Check(op) \
    PyObject_TypeCheck(op, &PySoy_widgets_Canvas_Type)

// soy.widgets.Container
PyTypeObject  PySoy_widgets_Container_Type;
typedef struct {
    PyObject_HEAD
    soywidgetsContainer* g;
} PySoy_widgets_Container_Object;
#define PySoy_widgets_Container_Check(op) \
    PyObject_TypeCheck(op, &PySoy_widgets_Container_Type)

// soy.widgets.HBox
PyTypeObject  PySoy_widgets_HBox_Type;
typedef struct {
    PyObject_HEAD
    soywidgetsHBox* g;
} PySoy_widgets_HBox_Object;
#define PySoy_widgets_HBox_Check(op) \
    PyObject_TypeCheck(op, &PySoy_widgets_HBox_Type)

// soy.widgets.VBox
PyTypeObject  PySoy_widgets_VBox_Type;
typedef struct {
    PyObject_HEAD
    soywidgetsVBox* g;
} PySoy_widgets_VBox_Object;
#define PySoy_widgets_VBox_Check(op) \
    PyObject_TypeCheck(op, &PySoy_widgets_VBox_Type)

// soy.widgets.Projector
PyTypeObject  PySoy_widgets_Projector_Type;
typedef struct {
    PyObject_HEAD
    soywidgetsProjector* g;
} PySoy_widgets_Projector_Object;
#define PySoy_widgets_Projector_Check(op) \
    PyObject_TypeCheck(op, &PySoy_widgets_Projector_Type)

// soy.widgets.Window
PyTypeObject  PySoy_widgets_Window_Type;
typedef struct {
    PyObject_HEAD
    soywidgetsWindow* g;
} PySoy_widgets_Window_Object;
#define PySoy_widgets_Window_Check(op) \
    PyObject_TypeCheck(op, &PySoy_widgets_Window_Type)

/////////////////////////////////////////////////////////////////////////////
// soy.Client

// soy.Client._ControllerMap
PyTypeObject PySoy_Client__ControllerMap_Type;
typedef struct {
    PyObject_HEAD
    GHashTable* map;
} PySoy_Client__ControllerMap_Object;
#define PySoy_Client__Controller_Check(op) \
    PyObject_TypeCheck(op, &PySoy_Client__Controller_Type)

// soy.Client
PyTypeObject PySoy_Client_Type;
typedef struct {
    PyObject_HEAD
    char* address;
    PyObject* window;
    soyatomsSize* window_size;
    Window window_id;
    EGLSurface window_surface;
    PySoy_Client__ControllerMap_Object* controllers;
	soycontrollersPointer* pointer;
	soycontrollersKeyboard* keyboard;
} PySoy_Client_Object;
#define PySoy_Client_Check(op) \
    PyObject_TypeCheck(op, &PySoy_Client_Type)

#endif // __PYSOY_H__

