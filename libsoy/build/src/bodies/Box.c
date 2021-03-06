/* Box.c generated by valac 0.18.1, the Vala compiler
 * generated from Box.gs, do not modify */

/*
 *  libsoy - soy.bodies.Box
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
#include <float.h>
#include <math.h>
#include <soy-1/ode.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <GLES/gl.h>
#include <GLES/glext.h>


#define SOY_BODIES_TYPE_BODY (soy_bodies_body_get_type ())
#define SOY_BODIES_BODY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_BODIES_TYPE_BODY, soybodiesBody))
#define SOY_BODIES_BODY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_BODIES_TYPE_BODY, soybodiesBodyClass))
#define SOY_BODIES_IS_BODY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_BODIES_TYPE_BODY))
#define SOY_BODIES_IS_BODY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_BODIES_TYPE_BODY))
#define SOY_BODIES_BODY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_BODIES_TYPE_BODY, soybodiesBodyClass))

typedef struct _soybodiesBody soybodiesBody;
typedef struct _soybodiesBodyClass soybodiesBodyClass;
typedef struct _soybodiesBodyPrivate soybodiesBodyPrivate;

#define SOY_SCENES_TYPE_SCENE (soy_scenes_scene_get_type ())
#define SOY_SCENES_SCENE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_SCENES_TYPE_SCENE, soyscenesScene))
#define SOY_SCENES_SCENE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_SCENES_TYPE_SCENE, soyscenesSceneClass))
#define SOY_SCENES_IS_SCENE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_SCENES_TYPE_SCENE))
#define SOY_SCENES_IS_SCENE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_SCENES_TYPE_SCENE))
#define SOY_SCENES_SCENE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_SCENES_TYPE_SCENE, soyscenesSceneClass))

typedef struct _soyscenesScene soyscenesScene;
typedef struct _soyscenesSceneClass soyscenesSceneClass;

#define SOY_BODIES_TYPE_BOX (soy_bodies_box_get_type ())
#define SOY_BODIES_BOX(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_BODIES_TYPE_BOX, soybodiesBox))
#define SOY_BODIES_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_BODIES_TYPE_BOX, soybodiesBoxClass))
#define SOY_BODIES_IS_BOX(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_BODIES_TYPE_BOX))
#define SOY_BODIES_IS_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_BODIES_TYPE_BOX))
#define SOY_BODIES_BOX_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_BODIES_TYPE_BOX, soybodiesBoxClass))

typedef struct _soybodiesBox soybodiesBox;
typedef struct _soybodiesBoxClass soybodiesBoxClass;
typedef struct _soybodiesBoxPrivate soybodiesBoxPrivate;

#define SOY_MATERIALS_TYPE_MATERIAL (soy_materials_material_get_type ())
#define SOY_MATERIALS_MATERIAL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_MATERIALS_TYPE_MATERIAL, soymaterialsMaterial))
#define SOY_MATERIALS_MATERIAL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_MATERIALS_TYPE_MATERIAL, soymaterialsMaterialClass))
#define SOY_MATERIALS_IS_MATERIAL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_MATERIALS_TYPE_MATERIAL))
#define SOY_MATERIALS_IS_MATERIAL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_MATERIALS_TYPE_MATERIAL))
#define SOY_MATERIALS_MATERIAL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_MATERIALS_TYPE_MATERIAL, soymaterialsMaterialClass))

typedef struct _soymaterialsMaterial soymaterialsMaterial;
typedef struct _soymaterialsMaterialClass soymaterialsMaterialClass;

#define SOY_ATOMS_TYPE_SIZE (soy_atoms_size_get_type ())
#define SOY_ATOMS_SIZE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_ATOMS_TYPE_SIZE, soyatomsSize))
#define SOY_ATOMS_SIZE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_ATOMS_TYPE_SIZE, soyatomsSizeClass))
#define SOY_ATOMS_IS_SIZE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_ATOMS_TYPE_SIZE))
#define SOY_ATOMS_IS_SIZE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_ATOMS_TYPE_SIZE))
#define SOY_ATOMS_SIZE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_ATOMS_TYPE_SIZE, soyatomsSizeClass))

typedef struct _soyatomsSize soyatomsSize;
typedef struct _soyatomsSizeClass soyatomsSizeClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define SOY_ATOMS_TYPE_POSITION (soy_atoms_position_get_type ())
#define SOY_ATOMS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPosition))
#define SOY_ATOMS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))
#define SOY_ATOMS_IS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_IS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_POSITION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))

typedef struct _soyatomsPosition soyatomsPosition;
typedef struct _soyatomsPositionClass soyatomsPositionClass;
#define _dGeomDestroy0(var) ((var == NULL) ? NULL : (var = (dGeomDestroy (var), NULL)))
typedef struct _soyscenesScenePrivate soyscenesScenePrivate;

#define SOY_BODIES_TYPE_LIGHT (soy_bodies_light_get_type ())
#define SOY_BODIES_LIGHT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_BODIES_TYPE_LIGHT, soybodiesLight))
#define SOY_BODIES_LIGHT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_BODIES_TYPE_LIGHT, soybodiesLightClass))
#define SOY_BODIES_IS_LIGHT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_BODIES_TYPE_LIGHT))
#define SOY_BODIES_IS_LIGHT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_BODIES_TYPE_LIGHT))
#define SOY_BODIES_LIGHT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_BODIES_TYPE_LIGHT, soybodiesLightClass))

typedef struct _soybodiesLight soybodiesLight;
typedef struct _soybodiesLightClass soybodiesLightClass;

#define SOY_JOINTS_TYPE_JOINT (soy_joints_joint_get_type ())
#define SOY_JOINTS_JOINT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_JOINTS_TYPE_JOINT, soyjointsJoint))
#define SOY_JOINTS_JOINT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_JOINTS_TYPE_JOINT, soyjointsJointClass))
#define SOY_JOINTS_IS_JOINT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_JOINTS_TYPE_JOINT))
#define SOY_JOINTS_IS_JOINT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_JOINTS_TYPE_JOINT))
#define SOY_JOINTS_JOINT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_JOINTS_TYPE_JOINT, soyjointsJointClass))

typedef struct _soyjointsJoint soyjointsJoint;
typedef struct _soyjointsJointClass soyjointsJointClass;

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

struct _soybodiesBody {
	GObject parent_instance;
	soybodiesBodyPrivate * priv;
	struct dxBody* body;
	struct dxGeom* geom;
	gchar* key;
	GMutex mutex;
	soyscenesScene* scene;
	GeeHashMap* tags_;
};

struct _soybodiesBodyClass {
	GObjectClass parent_class;
	void (*create_geom) (soybodiesBody* self, GObject* geom_param, gfloat geom_scalar);
	void (*add_extra) (soybodiesBody* self);
	void (*remove_extra) (soybodiesBody* self);
	gfloat (*pointDepth) (soybodiesBody* self, gfloat x, gfloat y, gfloat z);
	gfloat (*volume) (soybodiesBody* self);
	gint (*finite) (soybodiesBody* self);
	void (*mult_model_matrix) (soybodiesBody* self);
	void (*render) (soybodiesBody* self);
	void (*calcFogCoords) (soybodiesBody* self, gfloat _depth);
};

struct _soybodiesBox {
	soybodiesBody parent_instance;
	soybodiesBoxPrivate * priv;
};

struct _soybodiesBoxClass {
	soybodiesBodyClass parent_class;
};

struct _soybodiesBoxPrivate {
	GLuint _ebo;
	GLuint _vbo;
	gboolean _updated;
	soymaterialsMaterial* _material;
	GLfloat _width;
	GLfloat _height;
	GLfloat _depth;
	soyatomsSize* _size_obj;
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


static gpointer soy_bodies_box_parent_class = NULL;
extern soymaterialsMaterial* soy_default_material;
extern gulong GeomBody;

GType soy_bodies_body_get_type (void) G_GNUC_CONST;
GType soy_scenes_scene_get_type (void) G_GNUC_CONST;
GType soy_bodies_box_get_type (void) G_GNUC_CONST;
GType soy_materials_material_get_type (void) G_GNUC_CONST;
GType soy_atoms_size_get_type (void) G_GNUC_CONST;
#define SOY_BODIES_BOX_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_BODIES_TYPE_BOX, soybodiesBoxPrivate))
enum  {
	SOY_BODIES_BOX_DUMMY_PROPERTY,
	SOY_BODIES_BOX_MATERIAL,
	SOY_BODIES_BOX_SIZE
};
GType soy_atoms_position_get_type (void) G_GNUC_CONST;
soybodiesBox* soy_bodies_box_new (soyatomsPosition* position, soyatomsSize* size, soymaterialsMaterial* material);
soybodiesBox* soy_bodies_box_construct (GType object_type, soyatomsPosition* position, soyatomsSize* size, soymaterialsMaterial* material);
soybodiesBody* soy_bodies_body_new (soyatomsPosition* position, GObject* geom_param, gfloat geom_scalar);
soybodiesBody* soy_bodies_body_construct (GType object_type, soyatomsPosition* position, GObject* geom_param, gfloat geom_scalar);
soymaterialsMaterial* soy_materials_material_new (void);
soymaterialsMaterial* soy_materials_material_construct (GType object_type);
static void soy_bodies_box_real_create_geom (soybodiesBody* base, GObject* geom_param, gfloat geom_scalar);
void soy_bodies_box_set_size (soybodiesBox* self, soyatomsSize* value);
static void _soy_bodies_box_size_set (soybodiesBox* self, soyatomsSize* size);
gfloat soy_atoms_size_get_width (soyatomsSize* self);
gfloat soy_atoms_size_get_height (soyatomsSize* self);
gfloat soy_atoms_size_get_depth (soyatomsSize* self);
GType soy_bodies_light_get_type (void) G_GNUC_CONST;
GType soy_joints_joint_get_type (void) G_GNUC_CONST;
GType soy_controllers_controller_get_type (void) G_GNUC_CONST;
GType soy_controllers_virtual_controller_get_type (void) G_GNUC_CONST;
GType soy_fields_field_get_type (void) G_GNUC_CONST;
static void _soy_bodies_box_size_weak (soybodiesBox* self, GObject* size);
static gfloat soy_bodies_box_real_pointDepth (soybodiesBody* base, gfloat x, gfloat y, gfloat z);
static gfloat soy_bodies_box_real_volume (soybodiesBody* base);
static void soy_bodies_box_real_render (soybodiesBody* base);
void soy_bodies_body_mult_model_matrix (soybodiesBody* self);
static void _soy_bodies_box_update_box (soybodiesBox* self);
gboolean soy_materials_material_render (soymaterialsMaterial* self, gint pass, GLvoid* tslvs);
soymaterialsMaterial* soy_bodies_box_get_material (soybodiesBox* self);
void soy_bodies_box_set_material (soybodiesBox* self, soymaterialsMaterial* value);
soyatomsSize* soy_bodies_box_get_size (soybodiesBox* self);
soyatomsSize* soy_atoms_size_new (gfloat width, gfloat height, gfloat depth);
soyatomsSize* soy_atoms_size_construct (GType object_type, gfloat width, gfloat height, gfloat depth);
static void __soy_bodies_box_size_set_soy_atoms_size_on_set (soyatomsSize* _sender, soyatomsSize* size, gpointer self);
static void __soy_bodies_box_size_weak_gweak_notify (gpointer self, GObject* object);
static void soy_bodies_box_finalize (GObject* obj);
static void _vala_soy_bodies_box_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_soy_bodies_box_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


soybodiesBox* soy_bodies_box_construct (GType object_type, soyatomsPosition* position, soyatomsSize* size, soymaterialsMaterial* material) {
	soybodiesBox * self = NULL;
	soyatomsPosition* _tmp0_;
	soyatomsSize* _tmp1_;
	soymaterialsMaterial* _tmp2_;
	_tmp0_ = position;
	_tmp1_ = size;
	self = (soybodiesBox*) soy_bodies_body_construct (object_type, _tmp0_, (GObject*) _tmp1_, 0.0f);
	self->priv->_ebo = (GLuint) 0;
	self->priv->_updated = TRUE;
	_tmp2_ = material;
	if (_tmp2_ == NULL) {
		soymaterialsMaterial* _tmp3_;
		soymaterialsMaterial* _tmp5_;
		soymaterialsMaterial* _tmp6_;
		_tmp3_ = soy_default_material;
		if (_tmp3_ == NULL) {
			soymaterialsMaterial* _tmp4_;
			_tmp4_ = soy_materials_material_new ();
			_g_object_unref0 (soy_default_material);
			soy_default_material = _tmp4_;
		}
		_tmp5_ = soy_default_material;
		_tmp6_ = _g_object_ref0 (_tmp5_);
		_g_object_unref0 (self->priv->_material);
		self->priv->_material = _tmp6_;
	} else {
		soymaterialsMaterial* _tmp7_;
		soymaterialsMaterial* _tmp8_;
		_tmp7_ = material;
		_tmp8_ = _g_object_ref0 (_tmp7_);
		_g_object_unref0 (self->priv->_material);
		self->priv->_material = _tmp8_;
	}
	return self;
}


soybodiesBox* soy_bodies_box_new (soyatomsPosition* position, soyatomsSize* size, soymaterialsMaterial* material) {
	return soy_bodies_box_construct (SOY_BODIES_TYPE_BOX, position, size, material);
}


static void soy_bodies_box_real_create_geom (soybodiesBody* base, GObject* geom_param, gfloat geom_scalar) {
	soybodiesBox * self;
	GLfloat _tmp0_;
	GLfloat _tmp1_;
	GLfloat _tmp2_;
	GLfloat _tmp3_;
	GLfloat _tmp4_;
	struct dxGeom* _tmp5_;
	GObject* _tmp6_;
	struct dxGeom* _tmp8_;
	gulong _tmp9_;
	struct dxGeom* _tmp10_;
	self = (soybodiesBox*) base;
	self->priv->_depth = (GLfloat) 1.0f;
	_tmp0_ = self->priv->_depth;
	self->priv->_height = _tmp0_;
	_tmp1_ = self->priv->_height;
	self->priv->_width = _tmp1_;
	_tmp2_ = self->priv->_width;
	_tmp3_ = self->priv->_height;
	_tmp4_ = self->priv->_depth;
	_tmp5_ = dCreateBox (NULL, (dReal) _tmp2_, (dReal) _tmp3_, (dReal) _tmp4_);
	_dGeomDestroy0 (((soybodiesBody*) self)->geom);
	((soybodiesBody*) self)->geom = _tmp5_;
	_tmp6_ = geom_param;
	if (_tmp6_ != NULL) {
		GObject* _tmp7_;
		_tmp7_ = geom_param;
		soy_bodies_box_set_size (self, G_TYPE_CHECK_INSTANCE_CAST (_tmp7_, SOY_ATOMS_TYPE_SIZE, soyatomsSize));
	}
	_tmp8_ = ((soybodiesBody*) self)->geom;
	_tmp9_ = GeomBody;
	dGeomSetCategoryBits (_tmp8_, _tmp9_);
	_tmp10_ = ((soybodiesBody*) self)->geom;
	dGeomSetData (_tmp10_, (void*) self);
}


static void _soy_bodies_box_size_set (soybodiesBox* self, soyatomsSize* size) {
	soyatomsSize* _tmp0_;
	gfloat _tmp1_;
	gfloat _tmp2_;
	soyatomsSize* _tmp3_;
	gfloat _tmp4_;
	gfloat _tmp5_;
	soyatomsSize* _tmp6_;
	gfloat _tmp7_;
	gfloat _tmp8_;
	soyscenesScene* _tmp9_;
	struct dxGeom* _tmp11_;
	GLfloat _tmp12_;
	GLfloat _tmp13_;
	GLfloat _tmp14_;
	soyscenesScene* _tmp15_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (size != NULL);
	g_mutex_lock (&((soybodiesBody*) self)->mutex);
	_tmp0_ = size;
	_tmp1_ = soy_atoms_size_get_width (_tmp0_);
	_tmp2_ = _tmp1_;
	self->priv->_width = (GLfloat) _tmp2_;
	_tmp3_ = size;
	_tmp4_ = soy_atoms_size_get_height (_tmp3_);
	_tmp5_ = _tmp4_;
	self->priv->_height = (GLfloat) _tmp5_;
	_tmp6_ = size;
	_tmp7_ = soy_atoms_size_get_depth (_tmp6_);
	_tmp8_ = _tmp7_;
	self->priv->_depth = (GLfloat) _tmp8_;
	self->priv->_updated = TRUE;
	g_mutex_unlock (&((soybodiesBody*) self)->mutex);
	_tmp9_ = ((soybodiesBody*) self)->scene;
	if (_tmp9_ != NULL) {
		soyscenesScene* _tmp10_;
		_tmp10_ = ((soybodiesBody*) self)->scene;
		g_rw_lock_writer_lock (&_tmp10_->stepLock);
	}
	_tmp11_ = ((soybodiesBody*) self)->geom;
	_tmp12_ = self->priv->_width;
	_tmp13_ = self->priv->_height;
	_tmp14_ = self->priv->_depth;
	dGeomBoxSetLengths ((struct dxGeom*) _tmp11_, (dReal) _tmp12_, (dReal) _tmp13_, (dReal) _tmp14_);
	_tmp15_ = ((soybodiesBody*) self)->scene;
	if (_tmp15_ != NULL) {
		soyscenesScene* _tmp16_;
		_tmp16_ = ((soybodiesBody*) self)->scene;
		g_rw_lock_writer_unlock (&_tmp16_->stepLock);
	}
}


static void _soy_bodies_box_size_weak (soybodiesBox* self, GObject* size) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (size != NULL);
	self->priv->_size_obj = NULL;
}


static gfloat soy_bodies_box_real_pointDepth (soybodiesBody* base, gfloat x, gfloat y, gfloat z) {
	soybodiesBox * self;
	gfloat result = 0.0F;
	struct dxGeom* _tmp0_;
	gfloat _tmp1_;
	gfloat _tmp2_;
	gfloat _tmp3_;
	dReal _tmp4_ = 0.0;
	self = (soybodiesBox*) base;
	_tmp0_ = ((soybodiesBody*) self)->geom;
	_tmp1_ = x;
	_tmp2_ = y;
	_tmp3_ = z;
	_tmp4_ = dGeomBoxPointDepth ((struct dxGeom*) _tmp0_, (dReal) _tmp1_, (dReal) _tmp2_, (dReal) _tmp3_);
	result = (gfloat) _tmp4_;
	return result;
}


static gfloat soy_bodies_box_real_volume (soybodiesBody* base) {
	soybodiesBox * self;
	gfloat result = 0.0F;
	GLfloat _tmp0_;
	GLfloat _tmp1_;
	GLfloat _tmp2_;
	self = (soybodiesBox*) base;
	_tmp0_ = self->priv->_width;
	_tmp1_ = self->priv->_height;
	_tmp2_ = self->priv->_depth;
	result = (gfloat) ((_tmp0_ * _tmp1_) * _tmp2_);
	return result;
}


static void soy_bodies_box_real_render (soybodiesBody* base) {
	soybodiesBox * self;
	gint i;
	gboolean _tmp0_;
	self = (soybodiesBox*) base;
	i = 0;
	glMatrixMode (GL_MODELVIEW);
	glPushMatrix ();
	g_mutex_lock (&((soybodiesBody*) self)->mutex);
	soy_bodies_body_mult_model_matrix ((soybodiesBody*) self);
	_tmp0_ = self->priv->_updated;
	if (_tmp0_) {
		_soy_bodies_box_update_box (self);
	} else {
		GLuint _tmp1_;
		GLuint _tmp2_;
		_tmp1_ = self->priv->_ebo;
		glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, _tmp1_);
		_tmp2_ = self->priv->_vbo;
		glBindBuffer (GL_ARRAY_BUFFER, _tmp2_);
	}
	glVertexPointer ((GLint) 3, GL_FLOAT, (GLsizei) (sizeof (GLfloat) * 11), NULL);
	glNormalPointer (GL_FLOAT, (GLsizei) (sizeof (GLfloat) * 11), (GLvoid*) (sizeof (GLfloat) * 3));
	while (TRUE) {
		soymaterialsMaterial* _tmp3_;
		gint _tmp4_;
		gboolean _tmp5_ = FALSE;
		gint _tmp6_;
		_tmp3_ = self->priv->_material;
		_tmp4_ = i;
		_tmp5_ = soy_materials_material_render (_tmp3_, _tmp4_, NULL);
		if (!_tmp5_) {
			break;
		}
		glDrawElements (GL_TRIANGLES, (GLsizei) 36, GL_UNSIGNED_BYTE, (GLvoid*) 0);
		_tmp6_ = i;
		i = _tmp6_ + 1;
	}
	g_mutex_unlock (&((soybodiesBody*) self)->mutex);
	glMatrixMode (GL_MODELVIEW);
	glPopMatrix ();
}


static void _soy_bodies_box_update_box (soybodiesBox* self) {
	GLuint _tmp0_;
	GLfloat _tmp3_;
	GLfloat width;
	GLfloat _tmp4_;
	GLfloat height;
	GLfloat _tmp5_;
	GLfloat depth;
	GLubyte* _tmp6_ = NULL;
	GLubyte* elements;
	gint elements_length1;
	gint _elements_size_;
	GLfloat* _tmp7_ = NULL;
	GLfloat* vertices;
	gint vertices_length1;
	gint _vertices_size_;
	GLuint _tmp8_;
	GLuint _tmp9_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_ebo;
	if (_tmp0_ == ((GLuint) 0)) {
		GLuint _tmp1_ = 0U;
		GLuint _tmp2_ = 0U;
		glGenBuffers ((GLsizei) 1, &_tmp1_);
		self->priv->_ebo = _tmp1_;
		glGenBuffers ((GLsizei) 1, &_tmp2_);
		self->priv->_vbo = _tmp2_;
	}
	_tmp3_ = self->priv->_width;
	width = _tmp3_ / 2;
	_tmp4_ = self->priv->_height;
	height = _tmp4_ / 2;
	_tmp5_ = self->priv->_depth;
	depth = _tmp5_ / 2;
	_tmp6_ = g_new0 (GLubyte, 36);
	_tmp6_[0] = (GLubyte) 0;
	_tmp6_[1] = (GLubyte) 1;
	_tmp6_[2] = (GLubyte) 2;
	_tmp6_[3] = (GLubyte) 2;
	_tmp6_[4] = (GLubyte) 3;
	_tmp6_[5] = (GLubyte) 0;
	_tmp6_[6] = (GLubyte) 4;
	_tmp6_[7] = (GLubyte) 5;
	_tmp6_[8] = (GLubyte) 6;
	_tmp6_[9] = (GLubyte) 6;
	_tmp6_[10] = (GLubyte) 7;
	_tmp6_[11] = (GLubyte) 4;
	_tmp6_[12] = (GLubyte) 8;
	_tmp6_[13] = (GLubyte) 9;
	_tmp6_[14] = (GLubyte) 10;
	_tmp6_[15] = (GLubyte) 10;
	_tmp6_[16] = (GLubyte) 11;
	_tmp6_[17] = (GLubyte) 8;
	_tmp6_[18] = (GLubyte) 12;
	_tmp6_[19] = (GLubyte) 13;
	_tmp6_[20] = (GLubyte) 14;
	_tmp6_[21] = (GLubyte) 14;
	_tmp6_[22] = (GLubyte) 15;
	_tmp6_[23] = (GLubyte) 12;
	_tmp6_[24] = (GLubyte) 16;
	_tmp6_[25] = (GLubyte) 17;
	_tmp6_[26] = (GLubyte) 18;
	_tmp6_[27] = (GLubyte) 18;
	_tmp6_[28] = (GLubyte) 19;
	_tmp6_[29] = (GLubyte) 16;
	_tmp6_[30] = (GLubyte) 20;
	_tmp6_[31] = (GLubyte) 21;
	_tmp6_[32] = (GLubyte) 22;
	_tmp6_[33] = (GLubyte) 22;
	_tmp6_[34] = (GLubyte) 23;
	_tmp6_[35] = (GLubyte) 20;
	elements = _tmp6_;
	elements_length1 = 36;
	_elements_size_ = elements_length1;
	_tmp7_ = g_new0 (GLfloat, 264);
	_tmp7_[0] = width;
	_tmp7_[1] = height;
	_tmp7_[2] = depth;
	_tmp7_[3] = (GLfloat) 0;
	_tmp7_[4] = (GLfloat) 0;
	_tmp7_[5] = (GLfloat) 1;
	_tmp7_[6] = (GLfloat) 1;
	_tmp7_[7] = (GLfloat) 1;
	_tmp7_[8] = (GLfloat) 0;
	_tmp7_[9] = (GLfloat) 0;
	_tmp7_[10] = (GLfloat) 0;
	_tmp7_[11] = -width;
	_tmp7_[12] = height;
	_tmp7_[13] = depth;
	_tmp7_[14] = (GLfloat) 0;
	_tmp7_[15] = (GLfloat) 0;
	_tmp7_[16] = (GLfloat) 1;
	_tmp7_[17] = (GLfloat) 0;
	_tmp7_[18] = (GLfloat) 1;
	_tmp7_[19] = (GLfloat) 0;
	_tmp7_[20] = (GLfloat) 0;
	_tmp7_[21] = (GLfloat) 0;
	_tmp7_[22] = -width;
	_tmp7_[23] = -height;
	_tmp7_[24] = depth;
	_tmp7_[25] = (GLfloat) 0;
	_tmp7_[26] = (GLfloat) 0;
	_tmp7_[27] = (GLfloat) 1;
	_tmp7_[28] = (GLfloat) 0;
	_tmp7_[29] = (GLfloat) 0;
	_tmp7_[30] = (GLfloat) 0;
	_tmp7_[31] = (GLfloat) 0;
	_tmp7_[32] = (GLfloat) 0;
	_tmp7_[33] = width;
	_tmp7_[34] = -height;
	_tmp7_[35] = depth;
	_tmp7_[36] = (GLfloat) 0;
	_tmp7_[37] = (GLfloat) 0;
	_tmp7_[38] = (GLfloat) 1;
	_tmp7_[39] = (GLfloat) 1;
	_tmp7_[40] = (GLfloat) 0;
	_tmp7_[41] = (GLfloat) 0;
	_tmp7_[42] = (GLfloat) 0;
	_tmp7_[43] = (GLfloat) 0;
	_tmp7_[44] = width;
	_tmp7_[45] = height;
	_tmp7_[46] = depth;
	_tmp7_[47] = (GLfloat) 1;
	_tmp7_[48] = (GLfloat) 0;
	_tmp7_[49] = (GLfloat) 0;
	_tmp7_[50] = (GLfloat) 0;
	_tmp7_[51] = (GLfloat) 1;
	_tmp7_[52] = (GLfloat) 0;
	_tmp7_[53] = (GLfloat) 0;
	_tmp7_[54] = (GLfloat) 0;
	_tmp7_[55] = width;
	_tmp7_[56] = -height;
	_tmp7_[57] = depth;
	_tmp7_[58] = (GLfloat) 1;
	_tmp7_[59] = (GLfloat) 0;
	_tmp7_[60] = (GLfloat) 0;
	_tmp7_[61] = (GLfloat) 0;
	_tmp7_[62] = (GLfloat) 0;
	_tmp7_[63] = (GLfloat) 0;
	_tmp7_[64] = (GLfloat) 0;
	_tmp7_[65] = (GLfloat) 0;
	_tmp7_[66] = width;
	_tmp7_[67] = -height;
	_tmp7_[68] = -depth;
	_tmp7_[69] = (GLfloat) 1;
	_tmp7_[70] = (GLfloat) 0;
	_tmp7_[71] = (GLfloat) 0;
	_tmp7_[72] = (GLfloat) 1;
	_tmp7_[73] = (GLfloat) 0;
	_tmp7_[74] = (GLfloat) 0;
	_tmp7_[75] = (GLfloat) 0;
	_tmp7_[76] = (GLfloat) 0;
	_tmp7_[77] = width;
	_tmp7_[78] = height;
	_tmp7_[79] = -depth;
	_tmp7_[80] = (GLfloat) 1;
	_tmp7_[81] = (GLfloat) 0;
	_tmp7_[82] = (GLfloat) 0;
	_tmp7_[83] = (GLfloat) 1;
	_tmp7_[84] = (GLfloat) 1;
	_tmp7_[85] = (GLfloat) 0;
	_tmp7_[86] = (GLfloat) 0;
	_tmp7_[87] = (GLfloat) 0;
	_tmp7_[88] = width;
	_tmp7_[89] = height;
	_tmp7_[90] = depth;
	_tmp7_[91] = (GLfloat) 0;
	_tmp7_[92] = (GLfloat) 1;
	_tmp7_[93] = (GLfloat) 0;
	_tmp7_[94] = (GLfloat) 1;
	_tmp7_[95] = (GLfloat) 0;
	_tmp7_[96] = (GLfloat) 0;
	_tmp7_[97] = (GLfloat) 0;
	_tmp7_[98] = (GLfloat) 0;
	_tmp7_[99] = width;
	_tmp7_[100] = height;
	_tmp7_[101] = -depth;
	_tmp7_[102] = (GLfloat) 0;
	_tmp7_[103] = (GLfloat) 1;
	_tmp7_[104] = (GLfloat) 0;
	_tmp7_[105] = (GLfloat) 1;
	_tmp7_[106] = (GLfloat) 1;
	_tmp7_[107] = (GLfloat) 0;
	_tmp7_[108] = (GLfloat) 0;
	_tmp7_[109] = (GLfloat) 0;
	_tmp7_[110] = -width;
	_tmp7_[111] = height;
	_tmp7_[112] = -depth;
	_tmp7_[113] = (GLfloat) 0;
	_tmp7_[114] = (GLfloat) 1;
	_tmp7_[115] = (GLfloat) 0;
	_tmp7_[116] = (GLfloat) 0;
	_tmp7_[117] = (GLfloat) 1;
	_tmp7_[118] = (GLfloat) 0;
	_tmp7_[119] = (GLfloat) 0;
	_tmp7_[120] = (GLfloat) 0;
	_tmp7_[121] = -width;
	_tmp7_[122] = height;
	_tmp7_[123] = depth;
	_tmp7_[124] = (GLfloat) 0;
	_tmp7_[125] = (GLfloat) 1;
	_tmp7_[126] = (GLfloat) 0;
	_tmp7_[127] = (GLfloat) 0;
	_tmp7_[128] = (GLfloat) 0;
	_tmp7_[129] = (GLfloat) 0;
	_tmp7_[130] = (GLfloat) 0;
	_tmp7_[131] = (GLfloat) 0;
	_tmp7_[132] = -width;
	_tmp7_[133] = height;
	_tmp7_[134] = depth;
	_tmp7_[135] = (GLfloat) (-1);
	_tmp7_[136] = (GLfloat) 0;
	_tmp7_[137] = (GLfloat) 0;
	_tmp7_[138] = (GLfloat) 1;
	_tmp7_[139] = (GLfloat) 1;
	_tmp7_[140] = (GLfloat) 0;
	_tmp7_[141] = (GLfloat) 0;
	_tmp7_[142] = (GLfloat) 0;
	_tmp7_[143] = -width;
	_tmp7_[144] = height;
	_tmp7_[145] = -depth;
	_tmp7_[146] = (GLfloat) (-1);
	_tmp7_[147] = (GLfloat) 0;
	_tmp7_[148] = (GLfloat) 0;
	_tmp7_[149] = (GLfloat) 0;
	_tmp7_[150] = (GLfloat) 1;
	_tmp7_[151] = (GLfloat) 0;
	_tmp7_[152] = (GLfloat) 0;
	_tmp7_[153] = (GLfloat) 0;
	_tmp7_[154] = -width;
	_tmp7_[155] = -height;
	_tmp7_[156] = -depth;
	_tmp7_[157] = (GLfloat) (-1);
	_tmp7_[158] = (GLfloat) 0;
	_tmp7_[159] = (GLfloat) 0;
	_tmp7_[160] = (GLfloat) 0;
	_tmp7_[161] = (GLfloat) 0;
	_tmp7_[162] = (GLfloat) 0;
	_tmp7_[163] = (GLfloat) 0;
	_tmp7_[164] = (GLfloat) 0;
	_tmp7_[165] = -width;
	_tmp7_[166] = -height;
	_tmp7_[167] = depth;
	_tmp7_[168] = (GLfloat) (-1);
	_tmp7_[169] = (GLfloat) 0;
	_tmp7_[170] = (GLfloat) 0;
	_tmp7_[171] = (GLfloat) 1;
	_tmp7_[172] = (GLfloat) 0;
	_tmp7_[173] = (GLfloat) 0;
	_tmp7_[174] = (GLfloat) 0;
	_tmp7_[175] = (GLfloat) 0;
	_tmp7_[176] = -width;
	_tmp7_[177] = -height;
	_tmp7_[178] = -depth;
	_tmp7_[179] = (GLfloat) 0;
	_tmp7_[180] = (GLfloat) (-1);
	_tmp7_[181] = (GLfloat) 0;
	_tmp7_[182] = (GLfloat) 0;
	_tmp7_[183] = (GLfloat) 0;
	_tmp7_[184] = (GLfloat) 0;
	_tmp7_[185] = (GLfloat) 0;
	_tmp7_[186] = (GLfloat) 0;
	_tmp7_[187] = width;
	_tmp7_[188] = -height;
	_tmp7_[189] = -depth;
	_tmp7_[190] = (GLfloat) 0;
	_tmp7_[191] = (GLfloat) (-1);
	_tmp7_[192] = (GLfloat) 0;
	_tmp7_[193] = (GLfloat) 1;
	_tmp7_[194] = (GLfloat) 0;
	_tmp7_[195] = (GLfloat) 0;
	_tmp7_[196] = (GLfloat) 0;
	_tmp7_[197] = (GLfloat) 0;
	_tmp7_[198] = width;
	_tmp7_[199] = -height;
	_tmp7_[200] = depth;
	_tmp7_[201] = (GLfloat) 0;
	_tmp7_[202] = (GLfloat) (-1);
	_tmp7_[203] = (GLfloat) 0;
	_tmp7_[204] = (GLfloat) 1;
	_tmp7_[205] = (GLfloat) 1;
	_tmp7_[206] = (GLfloat) 0;
	_tmp7_[207] = (GLfloat) 0;
	_tmp7_[208] = (GLfloat) 0;
	_tmp7_[209] = -width;
	_tmp7_[210] = -height;
	_tmp7_[211] = depth;
	_tmp7_[212] = (GLfloat) 0;
	_tmp7_[213] = (GLfloat) (-1);
	_tmp7_[214] = (GLfloat) 0;
	_tmp7_[215] = (GLfloat) 0;
	_tmp7_[216] = (GLfloat) 1;
	_tmp7_[217] = (GLfloat) 0;
	_tmp7_[218] = (GLfloat) 0;
	_tmp7_[219] = (GLfloat) 0;
	_tmp7_[220] = width;
	_tmp7_[221] = -height;
	_tmp7_[222] = -depth;
	_tmp7_[223] = (GLfloat) 0;
	_tmp7_[224] = (GLfloat) 0;
	_tmp7_[225] = (GLfloat) (-1);
	_tmp7_[226] = (GLfloat) 0;
	_tmp7_[227] = (GLfloat) 0;
	_tmp7_[228] = (GLfloat) 0;
	_tmp7_[229] = (GLfloat) 0;
	_tmp7_[230] = (GLfloat) 0;
	_tmp7_[231] = -width;
	_tmp7_[232] = -height;
	_tmp7_[233] = -depth;
	_tmp7_[234] = (GLfloat) 0;
	_tmp7_[235] = (GLfloat) 0;
	_tmp7_[236] = (GLfloat) (-1);
	_tmp7_[237] = (GLfloat) 1;
	_tmp7_[238] = (GLfloat) 0;
	_tmp7_[239] = (GLfloat) 0;
	_tmp7_[240] = (GLfloat) 0;
	_tmp7_[241] = (GLfloat) 0;
	_tmp7_[242] = -width;
	_tmp7_[243] = height;
	_tmp7_[244] = -depth;
	_tmp7_[245] = (GLfloat) 0;
	_tmp7_[246] = (GLfloat) 0;
	_tmp7_[247] = (GLfloat) (-1);
	_tmp7_[248] = (GLfloat) 1;
	_tmp7_[249] = (GLfloat) 1;
	_tmp7_[250] = (GLfloat) 0;
	_tmp7_[251] = (GLfloat) 0;
	_tmp7_[252] = (GLfloat) 0;
	_tmp7_[253] = width;
	_tmp7_[254] = height;
	_tmp7_[255] = -depth;
	_tmp7_[256] = (GLfloat) 0;
	_tmp7_[257] = (GLfloat) 0;
	_tmp7_[258] = (GLfloat) (-1);
	_tmp7_[259] = (GLfloat) 0;
	_tmp7_[260] = (GLfloat) 1;
	_tmp7_[261] = (GLfloat) 0;
	_tmp7_[262] = (GLfloat) 0;
	_tmp7_[263] = (GLfloat) 0;
	vertices = _tmp7_;
	vertices_length1 = 264;
	_vertices_size_ = vertices_length1;
	_tmp8_ = self->priv->_ebo;
	glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, _tmp8_);
	glBufferData (GL_ELEMENT_ARRAY_BUFFER, (GLsizei) 36, elements, GL_STATIC_DRAW);
	_tmp9_ = self->priv->_vbo;
	glBindBuffer (GL_ARRAY_BUFFER, _tmp9_);
	glBufferData (GL_ARRAY_BUFFER, (GLsizei) (264 * sizeof (GLfloat)), vertices, GL_STATIC_DRAW);
	self->priv->_updated = FALSE;
	vertices = (g_free (vertices), NULL);
	elements = (g_free (elements), NULL);
}


soymaterialsMaterial* soy_bodies_box_get_material (soybodiesBox* self) {
	soymaterialsMaterial* result;
	soymaterialsMaterial* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_material;
	result = _tmp0_;
	return result;
}


void soy_bodies_box_set_material (soybodiesBox* self, soymaterialsMaterial* value) {
	soymaterialsMaterial* _tmp0_;
	soymaterialsMaterial* _tmp1_;
	g_return_if_fail (self != NULL);
	g_mutex_lock (&((soybodiesBody*) self)->mutex);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_material);
	self->priv->_material = _tmp1_;
	g_mutex_unlock (&((soybodiesBody*) self)->mutex);
	g_object_notify ((GObject *) self, "material");
}


static void __soy_bodies_box_size_set_soy_atoms_size_on_set (soyatomsSize* _sender, soyatomsSize* size, gpointer self) {
	_soy_bodies_box_size_set (self, size);
}


static void __soy_bodies_box_size_weak_gweak_notify (gpointer self, GObject* object) {
	_soy_bodies_box_size_weak (self, object);
}


soyatomsSize* soy_bodies_box_get_size (soybodiesBox* self) {
	soyatomsSize* result;
	soyatomsSize* _tmp0_;
	soyatomsSize* _tmp1_;
	soyatomsSize* value;
	soyatomsSize* _tmp2_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_size_obj;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	value = _tmp1_;
	_tmp2_ = value;
	if (_tmp2_ == NULL) {
		GLfloat _tmp3_;
		GLfloat _tmp4_;
		GLfloat _tmp5_;
		soyatomsSize* _tmp6_;
		soyatomsSize* _tmp7_;
		soyatomsSize* _tmp8_;
		soyatomsSize* _tmp9_;
		_tmp3_ = self->priv->_width;
		_tmp4_ = self->priv->_height;
		_tmp5_ = self->priv->_depth;
		_tmp6_ = soy_atoms_size_new ((gfloat) _tmp3_, (gfloat) _tmp4_, (gfloat) _tmp5_);
		_g_object_unref0 (value);
		value = _tmp6_;
		_tmp7_ = value;
		g_signal_connect_object (_tmp7_, "on-set", (GCallback) __soy_bodies_box_size_set_soy_atoms_size_on_set, self, 0);
		_tmp8_ = value;
		g_object_weak_ref ((GObject*) _tmp8_, __soy_bodies_box_size_weak_gweak_notify, self);
		_tmp9_ = value;
		self->priv->_size_obj = _tmp9_;
	}
	result = value;
	return result;
}


void soy_bodies_box_set_size (soybodiesBox* self, soyatomsSize* value) {
	soyatomsSize* _tmp0_;
	soyatomsSize* _tmp1_;
	soyatomsSize* _tmp2_;
	soyatomsSize* _tmp3_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_soy_bodies_box_size_set (self, _tmp0_);
	_tmp1_ = value;
	self->priv->_size_obj = _tmp1_;
	_tmp2_ = value;
	g_signal_connect_object (_tmp2_, "on-set", (GCallback) __soy_bodies_box_size_set_soy_atoms_size_on_set, self, 0);
	_tmp3_ = value;
	g_object_weak_ref ((GObject*) _tmp3_, __soy_bodies_box_size_weak_gweak_notify, self);
	g_object_notify ((GObject *) self, "size");
}


static void soy_bodies_box_class_init (soybodiesBoxClass * klass) {
	soy_bodies_box_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (soybodiesBoxPrivate));
	SOY_BODIES_BODY_CLASS (klass)->create_geom = soy_bodies_box_real_create_geom;
	SOY_BODIES_BODY_CLASS (klass)->pointDepth = soy_bodies_box_real_pointDepth;
	SOY_BODIES_BODY_CLASS (klass)->volume = soy_bodies_box_real_volume;
	SOY_BODIES_BODY_CLASS (klass)->render = soy_bodies_box_real_render;
	G_OBJECT_CLASS (klass)->get_property = _vala_soy_bodies_box_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_soy_bodies_box_set_property;
	G_OBJECT_CLASS (klass)->finalize = soy_bodies_box_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_BODIES_BOX_MATERIAL, g_param_spec_object ("material", "material", "material", SOY_MATERIALS_TYPE_MATERIAL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_BODIES_BOX_SIZE, g_param_spec_object ("size", "size", "size", SOY_ATOMS_TYPE_SIZE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void soy_bodies_box_instance_init (soybodiesBox * self) {
	self->priv = SOY_BODIES_BOX_GET_PRIVATE (self);
}


static void soy_bodies_box_finalize (GObject* obj) {
	soybodiesBox * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_BODIES_TYPE_BOX, soybodiesBox);
	_g_object_unref0 (self->priv->_material);
	G_OBJECT_CLASS (soy_bodies_box_parent_class)->finalize (obj);
}


GType soy_bodies_box_get_type (void) {
	static volatile gsize soy_bodies_box_type_id__volatile = 0;
	if (g_once_init_enter (&soy_bodies_box_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soybodiesBoxClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_bodies_box_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soybodiesBox), 0, (GInstanceInitFunc) soy_bodies_box_instance_init, NULL };
		GType soy_bodies_box_type_id;
		soy_bodies_box_type_id = g_type_register_static (SOY_BODIES_TYPE_BODY, "soybodiesBox", &g_define_type_info, 0);
		g_once_init_leave (&soy_bodies_box_type_id__volatile, soy_bodies_box_type_id);
	}
	return soy_bodies_box_type_id__volatile;
}


static void _vala_soy_bodies_box_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	soybodiesBox * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_BODIES_TYPE_BOX, soybodiesBox);
	switch (property_id) {
		case SOY_BODIES_BOX_MATERIAL:
		g_value_set_object (value, soy_bodies_box_get_material (self));
		break;
		case SOY_BODIES_BOX_SIZE:
		g_value_take_object (value, soy_bodies_box_get_size (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_soy_bodies_box_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	soybodiesBox * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_BODIES_TYPE_BOX, soybodiesBox);
	switch (property_id) {
		case SOY_BODIES_BOX_MATERIAL:
		soy_bodies_box_set_material (self, g_value_get_object (value));
		break;
		case SOY_BODIES_BOX_SIZE:
		soy_bodies_box_set_size (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



