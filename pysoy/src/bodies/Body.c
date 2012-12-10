/*
    PySoy - soy.bodies.Body Type
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
#define SELF PySoy_bodies_Body_Object*


static char
tp_doc[] = "soy.bodies.Body Type\n"
"\n"
"    Bodies are generic objects in 3d space with a position, velocity, mass,\n"
"    and shape.  Joints can connect them to together or to the scene to\n"
"    restrict their movement.\n"
"\n"
"    Properties position, rotation and velocity are respectively for body's\n"
"    position, rotation and velocity.\n"
"\n"
"    Methods addForce and addTorque are for adding force and torque to the body.\n"
"\n"
"Example::\n"
"\n"
"    scene = soy.scenes.Scene()\n"
"    b = soy.bodies.Body(scene)\n"
"    b.position = soy.atoms.Position(5, 10, 15)\n"
"    b.rotation = soy.atoms.Rotation(0, 180, 90)\n"
"    b.velocity = soy.atoms.Vector(5, 0, 0)\n"
"    b.addTorque(0.00005,  0.000000,  0.00003)\n"
"    b.addForce(0.00001, 0, 0)\n"
"\n";


static PyObject*
tp_new (PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;
    soyatomsPosition* position = NULL;
    static char* kw[] = {NULL};


    // Parse arguments
    // TODO position
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "", kw,
                                     &PySoy_scenes_Scene_Type))
        return NULL;

    // inherit base type
    self = (SELF) PyType_GenericNew(type, args, kwds);
    if (!self)
      return NULL;

    // new gobject
    self->g = soy_bodies_body_new(position, NULL, 0.0);

    // return self
    return (PyObject*) self;
}


static PyObject*
tp_repr (SELF self) {
    PyObject* ret;

    ret = PyUnicode_FromFormat("<Body>"); // TODO position etc

    // return string as unicode object
    return ret;
}


///////////////////////////////////////////////////////////////////////////////
// Methods

static char
addForce_doc[] = "Add force (linear force) along given axis";

static PyObject*
addForce (SELF self, PyObject* args) {
    float x, y, z;

    if (!PyArg_ParseTuple(args, "fff", &x, &y, &z))
        return NULL;

    soy_bodies_body_addForce(self->g, x, y, z);

    Py_RETURN_NONE;
}


static char
addTorque_doc[] = "Add torque (rotational force) along given axis";

static PyObject*
addTorque (SELF self, PyObject* args) {
    float x, y, z;

    if (!PyArg_ParseTuple(args, "fff", &x, &y, &z))
        return NULL;

    soy_bodies_body_addTorque(self->g, x, y, z);

    Py_RETURN_NONE;
}


/* TODO refactor or delete this
  def floor(self,Body floor) :
    cdef ode.dGeomID _ray
    cdef ode.dContactGeom cg[10]
    cdef ode.dSpaceID _spaceID
    _spaceID = self._scene._spaceID
    _ray = ode.dCreateRay(_spaceID,1000)
    ode.dGeomRaySet(_ray,
                    self._position[0], self._position[1], self._position[2],
                    0, -1, 0)
    countacts = ode.dCollide(<ode.dGeomID> _ray, <ode.dGeomID> _spaceID,
                             10, cg, sizeof(cg[0]))
    print "done"
    for contact in range(countacts): # countacts contains amount of collisions
      print "Trying a contact"
      if ode.dGeomGetBody(cg[contact].g2) == floor._bodyID :
        print "Floor found"
        self.position = (self._position[0], cg[contact].pos[1],
                         self._position[2])
        break
*/


///////////////////////////////////////////////////////////////////////////////
// Properties

static char
position_doc[] = "Body's Position\n"
"\n"
"    This is the (x,y,z) of where your body is in the scene as an instance\n"
"    of soy.atoms.Position.\n"
"\n"
"    Defaults to (0.0, 0.0, 0.0).\n"
"\n";
PYSOY_PROP_OBJECT_OWNED(bodies, body, position, atoms_Position)


static char
rotation_doc[] = "Body's Rotational Velocity\n"
"\n"
"    This is how fast your body is rotating on it's own axis.\n"
"\n"
"    Defaults to (0.0, 0.0, 0.0).\n"
"\n";
PYSOY_PROP_OBJECT_OWNED(bodies, body, rotation, atoms_Rotation)


static char
velocity_doc[] = "Body's Linear Velocity\n"
"\n"
"    This is how fast and in which direction a body is moving in a scene.\n"
"\n"
"    Defaults to (0.0, 0.0, 0.0).\n"
"\n";
PYSOY_PROP_OBJECT_OWNED(bodies, body, velocity, atoms_Vector)


///////////////////////////////////////////////////////////////////////////////
// Type structs

static PyMethodDef tp_methods[] = {
    {"addForce",                                            // ml_name
     (PyCFunction) addForce,                                // ml_meth
     METH_VARARGS,                                          // ml_flags
     addForce_doc},                                         // ml_doc
    {"addTorque",                                           // ml_name
     (PyCFunction) addTorque,                               // ml_meth
     METH_VARARGS,                                          // ml_flags
     addTorque_doc},                                        // ml_doc
    {NULL},                                                 // sentinel
};


static PyGetSetDef tp_getset[] = {
    PYSOY_PROPSTRUCT(position),
    PYSOY_PROPSTRUCT(rotation),
    PYSOY_PROPSTRUCT(velocity),
    {NULL}                                                 // sentinel
};


PyTypeObject PySoy_bodies_Body_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.bodies.Body",                                     // tp_name
    sizeof(PySoy_bodies_Body_Object),                      // tp_basicsize
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

