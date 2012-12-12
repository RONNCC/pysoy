/* Hinge.c generated by valac 0.18.1, the Vala compiler
 * generated from Hinge.gs, do not modify */

/*
 *  libsoy - soy.joints.Hinge
 *  Copyright (C) 2006,2007,2008,2009,2010,2011,2012 Copyleft Games Group
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program; if not, see http://www.gnu.org/licenses
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <soy-1/ode.h>
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define SOY_JOINTS_TYPE_JOINT (soy_joints_joint_get_type ())
#define SOY_JOINTS_JOINT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_JOINTS_TYPE_JOINT, soyjointsJoint))
#define SOY_JOINTS_JOINT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_JOINTS_TYPE_JOINT, soyjointsJointClass))
#define SOY_JOINTS_IS_JOINT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_JOINTS_TYPE_JOINT))
#define SOY_JOINTS_IS_JOINT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_JOINTS_TYPE_JOINT))
#define SOY_JOINTS_JOINT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_JOINTS_TYPE_JOINT, soyjointsJointClass))

typedef struct _soyjointsJoint soyjointsJoint;
typedef struct _soyjointsJointClass soyjointsJointClass;
typedef struct _soyjointsJointPrivate soyjointsJointPrivate;

#define SOY_ATOMS_TYPE_POSITION (soy_atoms_position_get_type ())
#define SOY_ATOMS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPosition))
#define SOY_ATOMS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))
#define SOY_ATOMS_IS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_IS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_POSITION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))

typedef struct _soyatomsPosition soyatomsPosition;
typedef struct _soyatomsPositionClass soyatomsPositionClass;

#define SOY_ATOMS_TYPE_AXIS (soy_atoms_axis_get_type ())
#define SOY_ATOMS_AXIS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_ATOMS_TYPE_AXIS, soyatomsAxis))
#define SOY_ATOMS_AXIS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_ATOMS_TYPE_AXIS, soyatomsAxisClass))
#define SOY_ATOMS_IS_AXIS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_ATOMS_TYPE_AXIS))
#define SOY_ATOMS_IS_AXIS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_ATOMS_TYPE_AXIS))
#define SOY_ATOMS_AXIS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_ATOMS_TYPE_AXIS, soyatomsAxisClass))

typedef struct _soyatomsAxis soyatomsAxis;
typedef struct _soyatomsAxisClass soyatomsAxisClass;

#define SOY_SCENES_TYPE_SCENE (soy_scenes_scene_get_type ())
#define SOY_SCENES_SCENE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_SCENES_TYPE_SCENE, soyscenesScene))
#define SOY_SCENES_SCENE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_SCENES_TYPE_SCENE, soyscenesSceneClass))
#define SOY_SCENES_IS_SCENE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_SCENES_TYPE_SCENE))
#define SOY_SCENES_IS_SCENE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_SCENES_TYPE_SCENE))
#define SOY_SCENES_SCENE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_SCENES_TYPE_SCENE, soyscenesSceneClass))

typedef struct _soyscenesScene soyscenesScene;
typedef struct _soyscenesSceneClass soyscenesSceneClass;

#define SOY_BODIES_TYPE_BODY (soy_bodies_body_get_type ())
#define SOY_BODIES_BODY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_BODIES_TYPE_BODY, soybodiesBody))
#define SOY_BODIES_BODY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_BODIES_TYPE_BODY, soybodiesBodyClass))
#define SOY_BODIES_IS_BODY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_BODIES_TYPE_BODY))
#define SOY_BODIES_IS_BODY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_BODIES_TYPE_BODY))
#define SOY_BODIES_BODY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_BODIES_TYPE_BODY, soybodiesBodyClass))

typedef struct _soybodiesBody soybodiesBody;
typedef struct _soybodiesBodyClass soybodiesBodyClass;

#define SOY_JOINTS_TYPE_HINGE (soy_joints_hinge_get_type ())
#define SOY_JOINTS_HINGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_JOINTS_TYPE_HINGE, soyjointsHinge))
#define SOY_JOINTS_HINGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_JOINTS_TYPE_HINGE, soyjointsHingeClass))
#define SOY_JOINTS_IS_HINGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_JOINTS_TYPE_HINGE))
#define SOY_JOINTS_IS_HINGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_JOINTS_TYPE_HINGE))
#define SOY_JOINTS_HINGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_JOINTS_TYPE_HINGE, soyjointsHingeClass))

typedef struct _soyjointsHinge soyjointsHinge;
typedef struct _soyjointsHingeClass soyjointsHingeClass;
typedef struct _soyjointsHingePrivate soyjointsHingePrivate;

#define SOY_MATERIALS_TYPE_MATERIAL (soy_materials_material_get_type ())
#define SOY_MATERIALS_MATERIAL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_MATERIALS_TYPE_MATERIAL, soymaterialsMaterial))
#define SOY_MATERIALS_MATERIAL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_MATERIALS_TYPE_MATERIAL, soymaterialsMaterialClass))
#define SOY_MATERIALS_IS_MATERIAL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_MATERIALS_TYPE_MATERIAL))
#define SOY_MATERIALS_IS_MATERIAL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_MATERIALS_TYPE_MATERIAL))
#define SOY_MATERIALS_MATERIAL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_MATERIALS_TYPE_MATERIAL, soymaterialsMaterialClass))

typedef struct _soymaterialsMaterial soymaterialsMaterial;
typedef struct _soymaterialsMaterialClass soymaterialsMaterialClass;
typedef struct _soyscenesScenePrivate soyscenesScenePrivate;

#define SOY_BODIES_TYPE_LIGHT (soy_bodies_light_get_type ())
#define SOY_BODIES_LIGHT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_BODIES_TYPE_LIGHT, soybodiesLight))
#define SOY_BODIES_LIGHT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_BODIES_TYPE_LIGHT, soybodiesLightClass))
#define SOY_BODIES_IS_LIGHT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_BODIES_TYPE_LIGHT))
#define SOY_BODIES_IS_LIGHT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_BODIES_TYPE_LIGHT))
#define SOY_BODIES_LIGHT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_BODIES_TYPE_LIGHT, soybodiesLightClass))

typedef struct _soybodiesLight soybodiesLight;
typedef struct _soybodiesLightClass soybodiesLightClass;

#define SOY_CONTROLLERS_TYPE_CONTROLLER (soy_controllers_controller_get_type ())
#define SOY_CONTROLLERS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_CONTROLLERS_TYPE_CONTROLLER, soycontrollersController))
#define SOY_CONTROLLERS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_CONTROLLERS_TYPE_CONTROLLER, soycontrollersControllerClass))
#define SOY_CONTROLLERS_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_CONTROLLERS_TYPE_CONTROLLER))
#define SOY_CONTROLLERS_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_CONTROLLERS_TYPE_CONTROLLER))
#define SOY_CONTROLLERS_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_CONTROLLERS_TYPE_CONTROLLER, soycontrollersControllerClass))

typedef struct _soycontrollersController soycontrollersController;
typedef struct _soycontrollersControllerClass soycontrollersControllerClass;

#define SOY_CONTROLLERS_TYPE_VIRTUAL_CONTROLLER (soy_controllers_virtual_controller_get_type ())
#define SOY_CONTROLLERS_VIRTUAL_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_CONTROLLERS_TYPE_VIRTUAL_CONTROLLER, soycontrollersVirtualController))
#define SOY_CONTROLLERS_VIRTUAL_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_CONTROLLERS_TYPE_VIRTUAL_CONTROLLER, soycontrollersVirtualControllerClass))
#define SOY_CONTROLLERS_IS_VIRTUAL_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_CONTROLLERS_TYPE_VIRTUAL_CONTROLLER))
#define SOY_CONTROLLERS_IS_VIRTUAL_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_CONTROLLERS_TYPE_VIRTUAL_CONTROLLER))
#define SOY_CONTROLLERS_VIRTUAL_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_CONTROLLERS_TYPE_VIRTUAL_CONTROLLER, soycontrollersVirtualControllerClass))

typedef struct _soycontrollersVirtualController soycontrollersVirtualController;
typedef struct _soycontrollersVirtualControllerClass soycontrollersVirtualControllerClass;

#define SOY_FIELDS_TYPE_FIELD (soy_fields_field_get_type ())
#define SOY_FIELDS_FIELD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_FIELDS_TYPE_FIELD, soyfieldsField))
#define SOY_FIELDS_FIELD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_FIELDS_TYPE_FIELD, soyfieldsFieldClass))
#define SOY_FIELDS_IS_FIELD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_FIELDS_TYPE_FIELD))
#define SOY_FIELDS_IS_FIELD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_FIELDS_TYPE_FIELD))
#define SOY_FIELDS_FIELD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_FIELDS_TYPE_FIELD, soyfieldsFieldClass))

typedef struct _soyfieldsField soyfieldsField;
typedef struct _soyfieldsFieldClass soyfieldsFieldClass;
#define _dJointDestroy0(var) ((var == NULL) ? NULL : (var = (dJointDestroy (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _dvector3_free0(var) ((var == NULL) ? NULL : (var = (dvector3_free (var), NULL)))

struct _soyjointsJoint {
	GObject parent_instance;
	soyjointsJointPrivate * priv;
	struct dxJoint* joint;
	soyscenesScene* scene;
	soybodiesBody* bodyA;
	soybodiesBody* bodyB;
	GMutex mutex;
};

struct _soyjointsJointClass {
	GObjectClass parent_class;
	void (*create) (soyjointsJoint* self);
	void (*setup) (soyjointsJoint* self, soyatomsPosition* anchor, soyatomsAxis* axis1, soyatomsAxis* axis2);
	void (*render) (soyjointsJoint* self);
	void (*mult_model_matrix) (soyjointsJoint* self);
};

struct _soyjointsHinge {
	soyjointsJoint parent_instance;
	soyjointsHingePrivate * priv;
};

struct _soyjointsHingeClass {
	soyjointsJointClass parent_class;
};

struct _soyjointsHingePrivate {
	soyatomsPosition* _anchor_obj;
	soyatomsAxis* _axis_obj;
};

struct _soyscenesScene {
	GObject parent_instance;
	soyscenesScenePrivate * priv;
	struct dxWorld* world;
	struct dxSpace* space;
	GRWLock stepLock;
	GeeHashSet* lights;
	GeeHashMap* bodies;
	GeeArrayList* joints;
	GeeHashSet* Controllers;
	GeeHashMap* fields;
};

struct _soyscenesSceneClass {
	GObjectClass parent_class;
	void (*do_in_step) (soyscenesScene* self);
	void (*render) (soyscenesScene* self, GLfloat fov, GLfloat aspect, GLfloat znear, GLfloat zfar);
};


static gpointer soy_joints_hinge_parent_class = NULL;

GType soy_joints_joint_get_type (void) G_GNUC_CONST;
GType soy_atoms_position_get_type (void) G_GNUC_CONST;
GType soy_atoms_axis_get_type (void) G_GNUC_CONST;
GType soy_scenes_scene_get_type (void) G_GNUC_CONST;
GType soy_bodies_body_get_type (void) G_GNUC_CONST;
GType soy_joints_hinge_get_type (void) G_GNUC_CONST;
#define SOY_JOINTS_HINGE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_JOINTS_TYPE_HINGE, soyjointsHingePrivate))
enum  {
	SOY_JOINTS_HINGE_DUMMY_PROPERTY,
	SOY_JOINTS_HINGE_ANCHOR,
	SOY_JOINTS_HINGE_AXIS
};
GType soy_materials_material_get_type (void) G_GNUC_CONST;
soyjointsHinge* soy_joints_hinge_new (soyscenesScene* scene, soybodiesBody* bodyA, soybodiesBody* bodyB, soyatomsPosition* anchor, soyatomsAxis* axis, soymaterialsMaterial* material);
soyjointsHinge* soy_joints_hinge_construct (GType object_type, soyscenesScene* scene, soybodiesBody* bodyA, soybodiesBody* bodyB, soyatomsPosition* anchor, soyatomsAxis* axis, soymaterialsMaterial* material);
soyjointsJoint* soy_joints_joint_new (soyscenesScene* scene, soybodiesBody* bodyA, soybodiesBody* bodyB, soyatomsPosition* anchor, soyatomsAxis* axis1, soyatomsAxis* axis2, soymaterialsMaterial* material);
soyjointsJoint* soy_joints_joint_construct (GType object_type, soyscenesScene* scene, soybodiesBody* bodyA, soybodiesBody* bodyB, soyatomsPosition* anchor, soyatomsAxis* axis1, soyatomsAxis* axis2, soymaterialsMaterial* material);
static void soy_joints_hinge_real_create (soyjointsJoint* base);
GType soy_bodies_light_get_type (void) G_GNUC_CONST;
GType soy_controllers_controller_get_type (void) G_GNUC_CONST;
GType soy_controllers_virtual_controller_get_type (void) G_GNUC_CONST;
GType soy_fields_field_get_type (void) G_GNUC_CONST;
static void soy_joints_hinge_real_setup (soyjointsJoint* base, soyatomsPosition* anchor, soyatomsAxis* axis1, soyatomsAxis* axis2);
gfloat soy_atoms_position_get_x (soyatomsPosition* self);
gfloat soy_atoms_position_get_y (soyatomsPosition* self);
gfloat soy_atoms_position_get_z (soyatomsPosition* self);
gfloat soy_atoms_axis_get_x (soyatomsAxis* self);
gfloat soy_atoms_axis_get_y (soyatomsAxis* self);
gfloat soy_atoms_axis_get_z (soyatomsAxis* self);
void soy_joints_hinge_addTorque (soyjointsHinge* self, dReal torque);
static void _soy_joints_hinge_anchor_set (soyjointsHinge* self, soyatomsPosition* anchor);
static void _soy_joints_hinge_anchor_weak (soyjointsHinge* self, GObject* anchor);
static void _soy_joints_hinge_axis_set (soyjointsHinge* self, soyatomsAxis* value);
soyatomsAxis* soy_atoms_axis_new_normalize (soyatomsAxis* axis);
soyatomsAxis* soy_atoms_axis_construct_normalize (GType object_type, soyatomsAxis* axis);
static void _soy_joints_hinge_axis_weak (soyjointsHinge* self, GObject* axis);
soyatomsPosition* soy_joints_hinge_get_anchor (soyjointsHinge* self);
static void __soy_joints_hinge_anchor_set_soy_atoms_position_on_set (soyatomsPosition* _sender, soyatomsPosition* position, gpointer self);
static void __soy_joints_hinge_anchor_weak_gweak_notify (gpointer self, GObject* object);
soyatomsPosition* soy_atoms_position_new (gfloat x, gfloat y, gfloat z);
soyatomsPosition* soy_atoms_position_construct (GType object_type, gfloat x, gfloat y, gfloat z);
void soy_joints_hinge_set_anchor (soyjointsHinge* self, soyatomsPosition* value);
soyatomsAxis* soy_joints_hinge_get_axis (soyjointsHinge* self);
static void __soy_joints_hinge_axis_set_soy_atoms_axis_on_set (soyatomsAxis* _sender, soyatomsAxis* vector, gpointer self);
static void __soy_joints_hinge_axis_weak_gweak_notify (gpointer self, GObject* object);
soyatomsAxis* soy_atoms_axis_new (gfloat x, gfloat y, gfloat z);
soyatomsAxis* soy_atoms_axis_construct (GType object_type, gfloat x, gfloat y, gfloat z);
void soy_joints_hinge_set_axis (soyjointsHinge* self, soyatomsAxis* value);
static void soy_joints_hinge_finalize (GObject* obj);
static void _vala_soy_joints_hinge_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_soy_joints_hinge_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


soyjointsHinge* soy_joints_hinge_construct (GType object_type, soyscenesScene* scene, soybodiesBody* bodyA, soybodiesBody* bodyB, soyatomsPosition* anchor, soyatomsAxis* axis, soymaterialsMaterial* material) {
	soyjointsHinge * self = NULL;
	soyscenesScene* _tmp0_;
	soybodiesBody* _tmp1_;
	soybodiesBody* _tmp2_;
	soyatomsPosition* _tmp3_;
	soyatomsAxis* _tmp4_;
	soymaterialsMaterial* _tmp5_;
	g_return_val_if_fail (scene != NULL, NULL);
	g_return_val_if_fail (bodyA != NULL, NULL);
	g_return_val_if_fail (anchor != NULL, NULL);
	g_return_val_if_fail (axis != NULL, NULL);
	_tmp0_ = scene;
	_tmp1_ = bodyA;
	_tmp2_ = bodyB;
	_tmp3_ = anchor;
	_tmp4_ = axis;
	_tmp5_ = material;
	self = (soyjointsHinge*) soy_joints_joint_construct (object_type, _tmp0_, _tmp1_, _tmp2_, _tmp3_, _tmp4_, NULL, _tmp5_);
	return self;
}


soyjointsHinge* soy_joints_hinge_new (soyscenesScene* scene, soybodiesBody* bodyA, soybodiesBody* bodyB, soyatomsPosition* anchor, soyatomsAxis* axis, soymaterialsMaterial* material) {
	return soy_joints_hinge_construct (SOY_JOINTS_TYPE_HINGE, scene, bodyA, bodyB, anchor, axis, material);
}


static void soy_joints_hinge_real_create (soyjointsJoint* base) {
	soyjointsHinge * self;
	soyscenesScene* _tmp0_;
	struct dxWorld* _tmp1_;
	struct dxJoint* _tmp2_;
	self = (soyjointsHinge*) base;
	_tmp0_ = ((soyjointsJoint*) self)->scene;
	_tmp1_ = _tmp0_->world;
	_tmp2_ = dJointCreateHinge (_tmp1_, NULL);
	_dJointDestroy0 (((soyjointsJoint*) self)->joint);
	((soyjointsJoint*) self)->joint = _tmp2_;
}


static void soy_joints_hinge_real_setup (soyjointsJoint* base, soyatomsPosition* anchor, soyatomsAxis* axis1, soyatomsAxis* axis2) {
	soyjointsHinge * self;
	struct dxJoint* _tmp0_;
	soyatomsPosition* _tmp1_;
	gfloat _tmp2_;
	gfloat _tmp3_;
	soyatomsPosition* _tmp4_;
	gfloat _tmp5_;
	gfloat _tmp6_;
	soyatomsPosition* _tmp7_;
	gfloat _tmp8_;
	gfloat _tmp9_;
	struct dxJoint* _tmp10_;
	soyatomsAxis* _tmp11_;
	gfloat _tmp12_;
	gfloat _tmp13_;
	soyatomsAxis* _tmp14_;
	gfloat _tmp15_;
	gfloat _tmp16_;
	soyatomsAxis* _tmp17_;
	gfloat _tmp18_;
	gfloat _tmp19_;
	self = (soyjointsHinge*) base;
	_tmp0_ = ((soyjointsJoint*) self)->joint;
	_tmp1_ = anchor;
	_tmp2_ = soy_atoms_position_get_x (_tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = anchor;
	_tmp5_ = soy_atoms_position_get_y (_tmp4_);
	_tmp6_ = _tmp5_;
	_tmp7_ = anchor;
	_tmp8_ = soy_atoms_position_get_z (_tmp7_);
	_tmp9_ = _tmp8_;
	dJointSetHingeAnchor ((struct dxJoint*) _tmp0_, (dReal) _tmp3_, (dReal) _tmp6_, (dReal) _tmp9_);
	_tmp10_ = ((soyjointsJoint*) self)->joint;
	_tmp11_ = axis1;
	_tmp12_ = soy_atoms_axis_get_x (_tmp11_);
	_tmp13_ = _tmp12_;
	_tmp14_ = axis1;
	_tmp15_ = soy_atoms_axis_get_y (_tmp14_);
	_tmp16_ = _tmp15_;
	_tmp17_ = axis1;
	_tmp18_ = soy_atoms_axis_get_z (_tmp17_);
	_tmp19_ = _tmp18_;
	dJointSetHingeAxis ((struct dxJoint*) _tmp10_, (dReal) _tmp13_, (dReal) _tmp16_, (dReal) _tmp19_);
}


void soy_joints_hinge_addTorque (soyjointsHinge* self, dReal torque) {
	struct dxJoint* _tmp0_;
	dReal _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = ((soyjointsJoint*) self)->joint;
	_tmp1_ = torque;
	dJointAddHingeTorque ((struct dxJoint*) _tmp0_, _tmp1_);
}


static void _soy_joints_hinge_anchor_set (soyjointsHinge* self, soyatomsPosition* anchor) {
	soyscenesScene* _tmp0_;
	struct dxJoint* _tmp1_;
	soyatomsPosition* _tmp2_;
	gfloat _tmp3_;
	gfloat _tmp4_;
	soyatomsPosition* _tmp5_;
	gfloat _tmp6_;
	gfloat _tmp7_;
	soyatomsPosition* _tmp8_;
	gfloat _tmp9_;
	gfloat _tmp10_;
	soyscenesScene* _tmp11_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (anchor != NULL);
	_tmp0_ = ((soyjointsJoint*) self)->scene;
	g_rw_lock_writer_lock (&_tmp0_->stepLock);
	_tmp1_ = ((soyjointsJoint*) self)->joint;
	_tmp2_ = anchor;
	_tmp3_ = soy_atoms_position_get_x (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = anchor;
	_tmp6_ = soy_atoms_position_get_y (_tmp5_);
	_tmp7_ = _tmp6_;
	_tmp8_ = anchor;
	_tmp9_ = soy_atoms_position_get_z (_tmp8_);
	_tmp10_ = _tmp9_;
	dJointSetHingeAnchor ((struct dxJoint*) _tmp1_, (dReal) _tmp4_, (dReal) _tmp7_, (dReal) _tmp10_);
	_tmp11_ = ((soyjointsJoint*) self)->scene;
	g_rw_lock_writer_unlock (&_tmp11_->stepLock);
}


static void _soy_joints_hinge_anchor_weak (soyjointsHinge* self, GObject* anchor) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (anchor != NULL);
	self->priv->_anchor_obj = NULL;
}


static void _soy_joints_hinge_axis_set (soyjointsHinge* self, soyatomsAxis* value) {
	soyatomsAxis* _tmp0_;
	soyatomsAxis* _tmp1_;
	soyatomsAxis* axis;
	soyscenesScene* _tmp2_;
	struct dxJoint* _tmp3_;
	gfloat _tmp4_;
	gfloat _tmp5_;
	gfloat _tmp6_;
	gfloat _tmp7_;
	gfloat _tmp8_;
	gfloat _tmp9_;
	soyscenesScene* _tmp10_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (value != NULL);
	_tmp0_ = value;
	_tmp1_ = soy_atoms_axis_new_normalize (_tmp0_);
	axis = _tmp1_;
	_tmp2_ = ((soyjointsJoint*) self)->scene;
	g_rw_lock_writer_lock (&_tmp2_->stepLock);
	_tmp3_ = ((soyjointsJoint*) self)->joint;
	_tmp4_ = soy_atoms_axis_get_x (axis);
	_tmp5_ = _tmp4_;
	_tmp6_ = soy_atoms_axis_get_y (axis);
	_tmp7_ = _tmp6_;
	_tmp8_ = soy_atoms_axis_get_z (axis);
	_tmp9_ = _tmp8_;
	dJointSetHingeAxis ((struct dxJoint*) _tmp3_, (dReal) _tmp5_, (dReal) _tmp7_, (dReal) _tmp9_);
	_tmp10_ = ((soyjointsJoint*) self)->scene;
	g_rw_lock_writer_unlock (&_tmp10_->stepLock);
	_g_object_unref0 (axis);
}


static void _soy_joints_hinge_axis_weak (soyjointsHinge* self, GObject* axis) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (axis != NULL);
	self->priv->_axis_obj = NULL;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void __soy_joints_hinge_anchor_set_soy_atoms_position_on_set (soyatomsPosition* _sender, soyatomsPosition* position, gpointer self) {
	_soy_joints_hinge_anchor_set (self, position);
}


static void __soy_joints_hinge_anchor_weak_gweak_notify (gpointer self, GObject* object) {
	_soy_joints_hinge_anchor_weak (self, object);
}


soyatomsPosition* soy_joints_hinge_get_anchor (soyjointsHinge* self) {
	soyatomsPosition* result;
	dxVector3* _tmp0_;
	dxVector3* v;
	struct dxJoint* _tmp1_;
	dxVector3* _tmp2_;
	soyatomsPosition* _tmp3_;
	soyatomsPosition* _tmp4_;
	soyatomsPosition* value;
	gboolean _tmp5_ = FALSE;
	gboolean _tmp6_ = FALSE;
	gboolean _tmp7_ = FALSE;
	soyatomsPosition* _tmp8_;
	gboolean _tmp14_;
	gboolean _tmp20_;
	gboolean _tmp26_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = dvector3_new ();
	v = _tmp0_;
	_tmp1_ = ((soyjointsJoint*) self)->joint;
	_tmp2_ = v;
	dJointGetHingeAnchor ((struct dxJoint*) _tmp1_, _tmp2_);
	_tmp3_ = self->priv->_anchor_obj;
	_tmp4_ = _g_object_ref0 (_tmp3_);
	value = _tmp4_;
	_tmp8_ = value;
	if (_tmp8_ == NULL) {
		_tmp7_ = TRUE;
	} else {
		dxVector3* _tmp9_;
		dReal _tmp10_;
		soyatomsPosition* _tmp11_;
		gfloat _tmp12_;
		gfloat _tmp13_;
		_tmp9_ = v;
		_tmp10_ = _tmp9_->x;
		_tmp11_ = value;
		_tmp12_ = soy_atoms_position_get_x (_tmp11_);
		_tmp13_ = _tmp12_;
		_tmp7_ = ((gfloat) _tmp10_) != _tmp13_;
	}
	_tmp14_ = _tmp7_;
	if (_tmp14_) {
		_tmp6_ = TRUE;
	} else {
		dxVector3* _tmp15_;
		dReal _tmp16_;
		soyatomsPosition* _tmp17_;
		gfloat _tmp18_;
		gfloat _tmp19_;
		_tmp15_ = v;
		_tmp16_ = _tmp15_->y;
		_tmp17_ = value;
		_tmp18_ = soy_atoms_position_get_y (_tmp17_);
		_tmp19_ = _tmp18_;
		_tmp6_ = ((gfloat) _tmp16_) != _tmp19_;
	}
	_tmp20_ = _tmp6_;
	if (_tmp20_) {
		_tmp5_ = TRUE;
	} else {
		dxVector3* _tmp21_;
		dReal _tmp22_;
		soyatomsPosition* _tmp23_;
		gfloat _tmp24_;
		gfloat _tmp25_;
		_tmp21_ = v;
		_tmp22_ = _tmp21_->z;
		_tmp23_ = value;
		_tmp24_ = soy_atoms_position_get_z (_tmp23_);
		_tmp25_ = _tmp24_;
		_tmp5_ = ((gfloat) _tmp22_) != _tmp25_;
	}
	_tmp26_ = _tmp5_;
	if (_tmp26_) {
		soyatomsPosition* _tmp27_;
		dxVector3* _tmp31_;
		dReal _tmp32_;
		dxVector3* _tmp33_;
		dReal _tmp34_;
		dxVector3* _tmp35_;
		dReal _tmp36_;
		soyatomsPosition* _tmp37_;
		soyatomsPosition* _tmp38_;
		soyatomsPosition* _tmp39_;
		soyatomsPosition* _tmp40_;
		_tmp27_ = value;
		if (_tmp27_ != NULL) {
			soyatomsPosition* _tmp28_;
			guint _tmp29_ = 0U;
			soyatomsPosition* _tmp30_;
			_tmp28_ = self->priv->_anchor_obj;
			g_signal_parse_name ("on-set", SOY_ATOMS_TYPE_POSITION, &_tmp29_, NULL, FALSE);
			g_signal_handlers_disconnect_matched (_tmp28_, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp29_, 0, NULL, (GCallback) __soy_joints_hinge_anchor_set_soy_atoms_position_on_set, self);
			_tmp30_ = self->priv->_anchor_obj;
			g_object_weak_unref ((GObject*) _tmp30_, __soy_joints_hinge_anchor_weak_gweak_notify, self);
		}
		_tmp31_ = v;
		_tmp32_ = _tmp31_->x;
		_tmp33_ = v;
		_tmp34_ = _tmp33_->y;
		_tmp35_ = v;
		_tmp36_ = _tmp35_->z;
		_tmp37_ = soy_atoms_position_new ((gfloat) _tmp32_, (gfloat) _tmp34_, (gfloat) _tmp36_);
		_g_object_unref0 (value);
		value = _tmp37_;
		_tmp38_ = value;
		g_signal_connect_object (_tmp38_, "on-set", (GCallback) __soy_joints_hinge_anchor_set_soy_atoms_position_on_set, self, 0);
		_tmp39_ = value;
		g_object_weak_ref ((GObject*) _tmp39_, __soy_joints_hinge_anchor_weak_gweak_notify, self);
		_tmp40_ = value;
		self->priv->_anchor_obj = _tmp40_;
	}
	result = value;
	_dvector3_free0 (v);
	return result;
}


void soy_joints_hinge_set_anchor (soyjointsHinge* self, soyatomsPosition* value) {
	soyatomsPosition* _tmp0_;
	soyatomsPosition* _tmp1_;
	soyatomsPosition* _tmp5_;
	soyatomsPosition* _tmp6_;
	soyatomsPosition* _tmp7_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_soy_joints_hinge_anchor_set (self, _tmp0_);
	_tmp1_ = self->priv->_anchor_obj;
	if (_tmp1_ != NULL) {
		soyatomsPosition* _tmp2_;
		guint _tmp3_ = 0U;
		soyatomsPosition* _tmp4_;
		_tmp2_ = self->priv->_anchor_obj;
		g_signal_parse_name ("on-set", SOY_ATOMS_TYPE_POSITION, &_tmp3_, NULL, FALSE);
		g_signal_handlers_disconnect_matched (_tmp2_, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp3_, 0, NULL, (GCallback) __soy_joints_hinge_anchor_set_soy_atoms_position_on_set, self);
		_tmp4_ = self->priv->_anchor_obj;
		g_object_weak_unref ((GObject*) _tmp4_, __soy_joints_hinge_anchor_weak_gweak_notify, self);
	}
	_tmp5_ = value;
	self->priv->_anchor_obj = _tmp5_;
	_tmp6_ = value;
	g_signal_connect_object (_tmp6_, "on-set", (GCallback) __soy_joints_hinge_anchor_set_soy_atoms_position_on_set, self, 0);
	_tmp7_ = value;
	g_object_weak_ref ((GObject*) _tmp7_, __soy_joints_hinge_anchor_weak_gweak_notify, self);
	g_object_notify ((GObject *) self, "anchor");
}


static void __soy_joints_hinge_axis_set_soy_atoms_axis_on_set (soyatomsAxis* _sender, soyatomsAxis* vector, gpointer self) {
	_soy_joints_hinge_axis_set (self, vector);
}


static void __soy_joints_hinge_axis_weak_gweak_notify (gpointer self, GObject* object) {
	_soy_joints_hinge_axis_weak (self, object);
}


soyatomsAxis* soy_joints_hinge_get_axis (soyjointsHinge* self) {
	soyatomsAxis* result;
	dxVector3* _tmp0_;
	dxVector3* v;
	struct dxJoint* _tmp1_;
	dxVector3* _tmp2_;
	soyatomsAxis* _tmp3_;
	soyatomsAxis* _tmp4_;
	soyatomsAxis* value;
	gboolean _tmp5_ = FALSE;
	gboolean _tmp6_ = FALSE;
	gboolean _tmp7_ = FALSE;
	soyatomsAxis* _tmp8_;
	gboolean _tmp14_;
	gboolean _tmp20_;
	gboolean _tmp26_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = dvector3_new ();
	v = _tmp0_;
	_tmp1_ = ((soyjointsJoint*) self)->joint;
	_tmp2_ = v;
	dJointGetHingeAxis ((struct dxJoint*) _tmp1_, _tmp2_);
	_tmp3_ = self->priv->_axis_obj;
	_tmp4_ = _g_object_ref0 (_tmp3_);
	value = _tmp4_;
	_tmp8_ = value;
	if (_tmp8_ == NULL) {
		_tmp7_ = TRUE;
	} else {
		dxVector3* _tmp9_;
		dReal _tmp10_;
		soyatomsAxis* _tmp11_;
		gfloat _tmp12_;
		gfloat _tmp13_;
		_tmp9_ = v;
		_tmp10_ = _tmp9_->x;
		_tmp11_ = value;
		_tmp12_ = soy_atoms_axis_get_x (_tmp11_);
		_tmp13_ = _tmp12_;
		_tmp7_ = ((gfloat) _tmp10_) != _tmp13_;
	}
	_tmp14_ = _tmp7_;
	if (_tmp14_) {
		_tmp6_ = TRUE;
	} else {
		dxVector3* _tmp15_;
		dReal _tmp16_;
		soyatomsAxis* _tmp17_;
		gfloat _tmp18_;
		gfloat _tmp19_;
		_tmp15_ = v;
		_tmp16_ = _tmp15_->y;
		_tmp17_ = value;
		_tmp18_ = soy_atoms_axis_get_y (_tmp17_);
		_tmp19_ = _tmp18_;
		_tmp6_ = ((gfloat) _tmp16_) != _tmp19_;
	}
	_tmp20_ = _tmp6_;
	if (_tmp20_) {
		_tmp5_ = TRUE;
	} else {
		dxVector3* _tmp21_;
		dReal _tmp22_;
		soyatomsAxis* _tmp23_;
		gfloat _tmp24_;
		gfloat _tmp25_;
		_tmp21_ = v;
		_tmp22_ = _tmp21_->z;
		_tmp23_ = value;
		_tmp24_ = soy_atoms_axis_get_z (_tmp23_);
		_tmp25_ = _tmp24_;
		_tmp5_ = ((gfloat) _tmp22_) != _tmp25_;
	}
	_tmp26_ = _tmp5_;
	if (_tmp26_) {
		soyatomsAxis* _tmp27_;
		dxVector3* _tmp31_;
		dReal _tmp32_;
		dxVector3* _tmp33_;
		dReal _tmp34_;
		dxVector3* _tmp35_;
		dReal _tmp36_;
		soyatomsAxis* _tmp37_;
		soyatomsAxis* _tmp38_;
		soyatomsAxis* _tmp39_;
		soyatomsAxis* _tmp40_;
		_tmp27_ = value;
		if (_tmp27_ != NULL) {
			soyatomsAxis* _tmp28_;
			guint _tmp29_ = 0U;
			soyatomsAxis* _tmp30_;
			_tmp28_ = self->priv->_axis_obj;
			g_signal_parse_name ("on-set", SOY_ATOMS_TYPE_AXIS, &_tmp29_, NULL, FALSE);
			g_signal_handlers_disconnect_matched (_tmp28_, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp29_, 0, NULL, (GCallback) __soy_joints_hinge_axis_set_soy_atoms_axis_on_set, self);
			_tmp30_ = self->priv->_axis_obj;
			g_object_weak_unref ((GObject*) _tmp30_, __soy_joints_hinge_axis_weak_gweak_notify, self);
		}
		_tmp31_ = v;
		_tmp32_ = _tmp31_->x;
		_tmp33_ = v;
		_tmp34_ = _tmp33_->y;
		_tmp35_ = v;
		_tmp36_ = _tmp35_->z;
		_tmp37_ = soy_atoms_axis_new ((gfloat) _tmp32_, (gfloat) _tmp34_, (gfloat) _tmp36_);
		_g_object_unref0 (value);
		value = _tmp37_;
		_tmp38_ = value;
		g_signal_connect_object (_tmp38_, "on-set", (GCallback) __soy_joints_hinge_axis_set_soy_atoms_axis_on_set, self, 0);
		_tmp39_ = value;
		g_object_weak_ref ((GObject*) _tmp39_, __soy_joints_hinge_axis_weak_gweak_notify, self);
		_tmp40_ = value;
		self->priv->_axis_obj = _tmp40_;
	}
	result = value;
	_dvector3_free0 (v);
	return result;
}


void soy_joints_hinge_set_axis (soyjointsHinge* self, soyatomsAxis* value) {
	soyatomsAxis* _tmp0_;
	soyatomsAxis* _tmp1_;
	soyatomsAxis* _tmp5_;
	soyatomsAxis* _tmp6_;
	soyatomsAxis* _tmp7_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_soy_joints_hinge_axis_set (self, _tmp0_);
	_tmp1_ = self->priv->_axis_obj;
	if (_tmp1_ != NULL) {
		soyatomsAxis* _tmp2_;
		guint _tmp3_ = 0U;
		soyatomsAxis* _tmp4_;
		_tmp2_ = self->priv->_axis_obj;
		g_signal_parse_name ("on-set", SOY_ATOMS_TYPE_AXIS, &_tmp3_, NULL, FALSE);
		g_signal_handlers_disconnect_matched (_tmp2_, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp3_, 0, NULL, (GCallback) __soy_joints_hinge_axis_set_soy_atoms_axis_on_set, self);
		_tmp4_ = self->priv->_axis_obj;
		g_object_weak_unref ((GObject*) _tmp4_, __soy_joints_hinge_axis_weak_gweak_notify, self);
	}
	_tmp5_ = value;
	self->priv->_axis_obj = _tmp5_;
	_tmp6_ = value;
	g_signal_connect_object (_tmp6_, "on-set", (GCallback) __soy_joints_hinge_axis_set_soy_atoms_axis_on_set, self, 0);
	_tmp7_ = value;
	g_object_weak_ref ((GObject*) _tmp7_, __soy_joints_hinge_axis_weak_gweak_notify, self);
	g_object_notify ((GObject *) self, "axis");
}


static void soy_joints_hinge_class_init (soyjointsHingeClass * klass) {
	soy_joints_hinge_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (soyjointsHingePrivate));
	SOY_JOINTS_JOINT_CLASS (klass)->create = soy_joints_hinge_real_create;
	SOY_JOINTS_JOINT_CLASS (klass)->setup = soy_joints_hinge_real_setup;
	G_OBJECT_CLASS (klass)->get_property = _vala_soy_joints_hinge_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_soy_joints_hinge_set_property;
	G_OBJECT_CLASS (klass)->finalize = soy_joints_hinge_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_JOINTS_HINGE_ANCHOR, g_param_spec_object ("anchor", "anchor", "anchor", SOY_ATOMS_TYPE_POSITION, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_JOINTS_HINGE_AXIS, g_param_spec_object ("axis", "axis", "axis", SOY_ATOMS_TYPE_AXIS, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void soy_joints_hinge_instance_init (soyjointsHinge * self) {
	self->priv = SOY_JOINTS_HINGE_GET_PRIVATE (self);
}


static void soy_joints_hinge_finalize (GObject* obj) {
	soyjointsHinge * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_JOINTS_TYPE_HINGE, soyjointsHinge);
	G_OBJECT_CLASS (soy_joints_hinge_parent_class)->finalize (obj);
}


GType soy_joints_hinge_get_type (void) {
	static volatile gsize soy_joints_hinge_type_id__volatile = 0;
	if (g_once_init_enter (&soy_joints_hinge_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soyjointsHingeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_joints_hinge_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soyjointsHinge), 0, (GInstanceInitFunc) soy_joints_hinge_instance_init, NULL };
		GType soy_joints_hinge_type_id;
		soy_joints_hinge_type_id = g_type_register_static (SOY_JOINTS_TYPE_JOINT, "soyjointsHinge", &g_define_type_info, 0);
		g_once_init_leave (&soy_joints_hinge_type_id__volatile, soy_joints_hinge_type_id);
	}
	return soy_joints_hinge_type_id__volatile;
}


static void _vala_soy_joints_hinge_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	soyjointsHinge * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_JOINTS_TYPE_HINGE, soyjointsHinge);
	switch (property_id) {
		case SOY_JOINTS_HINGE_ANCHOR:
		g_value_take_object (value, soy_joints_hinge_get_anchor (self));
		break;
		case SOY_JOINTS_HINGE_AXIS:
		g_value_take_object (value, soy_joints_hinge_get_axis (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_soy_joints_hinge_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	soyjointsHinge * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_JOINTS_TYPE_HINGE, soyjointsHinge);
	switch (property_id) {
		case SOY_JOINTS_HINGE_ANCHOR:
		soy_joints_hinge_set_anchor (self, g_value_get_object (value));
		break;
		case SOY_JOINTS_HINGE_AXIS:
		soy_joints_hinge_set_axis (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



