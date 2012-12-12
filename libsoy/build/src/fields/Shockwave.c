/* Shockwave.c generated by valac 0.18.1, the Vala compiler
 * generated from Shockwave.gs, do not modify */

/*
 *  libsoy - soy.fields.Shockwave
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

#define SOY_FIELDS_TYPE_FIELD (soy_fields_field_get_type ())
#define SOY_FIELDS_FIELD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_FIELDS_TYPE_FIELD, soyfieldsField))
#define SOY_FIELDS_FIELD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_FIELDS_TYPE_FIELD, soyfieldsFieldClass))
#define SOY_FIELDS_IS_FIELD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_FIELDS_TYPE_FIELD))
#define SOY_FIELDS_IS_FIELD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_FIELDS_TYPE_FIELD))
#define SOY_FIELDS_FIELD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_FIELDS_TYPE_FIELD, soyfieldsFieldClass))

typedef struct _soyfieldsField soyfieldsField;
typedef struct _soyfieldsFieldClass soyfieldsFieldClass;
typedef struct _soyfieldsFieldPrivate soyfieldsFieldPrivate;

#define SOY_FIELDS_TYPE_SHOCKWAVE (soy_fields_shockwave_get_type ())
#define SOY_FIELDS_SHOCKWAVE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_FIELDS_TYPE_SHOCKWAVE, soyfieldsShockwave))
#define SOY_FIELDS_SHOCKWAVE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_FIELDS_TYPE_SHOCKWAVE, soyfieldsShockwaveClass))
#define SOY_FIELDS_IS_SHOCKWAVE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_FIELDS_TYPE_SHOCKWAVE))
#define SOY_FIELDS_IS_SHOCKWAVE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_FIELDS_TYPE_SHOCKWAVE))
#define SOY_FIELDS_SHOCKWAVE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_FIELDS_TYPE_SHOCKWAVE, soyfieldsShockwaveClass))

typedef struct _soyfieldsShockwave soyfieldsShockwave;
typedef struct _soyfieldsShockwaveClass soyfieldsShockwaveClass;
typedef struct _soyfieldsShockwavePrivate soyfieldsShockwavePrivate;
#define _dSpaceDestroy0(var) ((var == NULL) ? NULL : (var = (dSpaceDestroy (var), NULL)))

#define SOY_ATOMS_TYPE_POSITION (soy_atoms_position_get_type ())
#define SOY_ATOMS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPosition))
#define SOY_ATOMS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))
#define SOY_ATOMS_IS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_IS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_POSITION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))

typedef struct _soyatomsPosition soyatomsPosition;
typedef struct _soyatomsPositionClass soyatomsPositionClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) ((var == NULL) ? NULL : (var = (g_free (var), NULL)))
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
#define _dGeomDestroy0(var) ((var == NULL) ? NULL : (var = (dGeomDestroy (var), NULL)))
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

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

struct _soyfieldsField {
	soybodiesBody parent_instance;
	soyfieldsFieldPrivate * priv;
};

struct _soyfieldsFieldClass {
	soybodiesBodyClass parent_class;
	gboolean (*exert) (soyfieldsField* self, soybodiesBody* other);
	void (*give) (soyfieldsField* self, gint data);
	void (*commit) (soyfieldsField* self);
};

struct _soyfieldsShockwave {
	soyfieldsField parent_instance;
	soyfieldsShockwavePrivate * priv;
};

struct _soyfieldsShockwaveClass {
	soyfieldsFieldClass parent_class;
};

struct _soyfieldsShockwavePrivate {
	struct dxSpace* _space;
	gfloat _t0;
	gfloat _inner;
	gfloat _outer;
	gfloat _swvel;
	gfloat _energy;
	gfloat _radius;
	gfloat _length;
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


static gpointer soy_fields_shockwave_parent_class = NULL;

GType soy_bodies_body_get_type (void) G_GNUC_CONST;
GType soy_scenes_scene_get_type (void) G_GNUC_CONST;
GType soy_fields_field_get_type (void) G_GNUC_CONST;
GType soy_fields_shockwave_get_type (void) G_GNUC_CONST;
#define SOY_FIELDS_SHOCKWAVE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_FIELDS_TYPE_SHOCKWAVE, soyfieldsShockwavePrivate))
enum  {
	SOY_FIELDS_SHOCKWAVE_DUMMY_PROPERTY,
	SOY_FIELDS_SHOCKWAVE_SWVEL,
	SOY_FIELDS_SHOCKWAVE_ENERGY,
	SOY_FIELDS_SHOCKWAVE_RADIUS,
	SOY_FIELDS_SHOCKWAVE_LENGTH
};
void soy_fields_shockwave_activate (soyfieldsShockwave* self);
static gboolean soy_fields_shockwave_real_exert (soyfieldsField* base, soybodiesBody* other);
gfloat soy_bodies_body_pointDepth (soybodiesBody* self, gfloat x, gfloat y, gfloat z);
GType soy_atoms_position_get_type (void) G_GNUC_CONST;
soyatomsPosition* soy_bodies_body_get_position (soybodiesBody* self);
gfloat soy_atoms_position_get_x (soyatomsPosition* self);
gfloat soy_atoms_position_get_y (soyatomsPosition* self);
gfloat soy_atoms_position_get_z (soyatomsPosition* self);
gfloat soy_fields_shockwave_get_length (soyfieldsShockwave* self);
gfloat soy_fields_shockwave_get_swvel (soyfieldsShockwave* self);
GeeHashMap* soy_bodies_body_get_tags (soybodiesBody* self);
void soy_bodies_body_addForceAtRelPos (soybodiesBody* self, dReal fx, dReal fy, dReal fz, dReal px, dReal py, dReal pz);
void soy_bodies_body_addForce (soybodiesBody* self, dReal fx, dReal fy, dReal fz);
static void soy_fields_shockwave_real_give (soyfieldsField* base, gint data);
guint64 soy_scenes_scene_get_time (soyscenesScene* self);
gfloat soy_fields_shockwave_get_radius (soyfieldsShockwave* self);
soyfieldsShockwave* soy_fields_shockwave_new (void);
soyfieldsShockwave* soy_fields_shockwave_construct (GType object_type);
soyfieldsField* soy_fields_field_new (void);
soyfieldsField* soy_fields_field_construct (GType object_type);
void soy_fields_shockwave_set_swvel (soyfieldsShockwave* self, gfloat value);
gfloat soy_fields_shockwave_get_energy (soyfieldsShockwave* self);
void soy_fields_shockwave_set_energy (soyfieldsShockwave* self, gfloat value);
void soy_fields_shockwave_set_radius (soyfieldsShockwave* self, gfloat value);
void soy_fields_shockwave_set_length (soyfieldsShockwave* self, gfloat value);
static GObject * soy_fields_shockwave_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
GType soy_bodies_light_get_type (void) G_GNUC_CONST;
GType soy_joints_joint_get_type (void) G_GNUC_CONST;
GType soy_controllers_controller_get_type (void) G_GNUC_CONST;
GType soy_controllers_virtual_controller_get_type (void) G_GNUC_CONST;
static void soy_fields_shockwave_finalize (GObject* obj);
static void _vala_soy_fields_shockwave_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_soy_fields_shockwave_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


void soy_fields_shockwave_activate (soyfieldsShockwave* self) {
	gfloat _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_t0;
	_vala_assert (_tmp0_ != ((gfloat) 0), "self._t0 != 0");
	self->priv->_t0 = (gfloat) 0;
	self->priv->_inner = (gfloat) 0;
	self->priv->_outer = (gfloat) 0;
}


static gboolean soy_fields_shockwave_real_exert (soyfieldsField* base, soybodiesBody* other) {
	soyfieldsShockwave * self;
	gboolean result = FALSE;
	gfloat depth = 0.0F;
	gfloat force = 0.0F;
	gfloat dx = 0.0F;
	gfloat dy = 0.0F;
	gfloat dz = 0.0F;
	gfloat d = 0.0F;
	soybodiesBody* _tmp0_;
	soyatomsPosition* _tmp1_;
	soyatomsPosition* _tmp2_;
	soyatomsPosition* _tmp3_;
	gfloat _tmp4_;
	gfloat _tmp5_;
	soybodiesBody* _tmp6_;
	soyatomsPosition* _tmp7_;
	soyatomsPosition* _tmp8_;
	soyatomsPosition* _tmp9_;
	gfloat _tmp10_;
	gfloat _tmp11_;
	soybodiesBody* _tmp12_;
	soyatomsPosition* _tmp13_;
	soyatomsPosition* _tmp14_;
	soyatomsPosition* _tmp15_;
	gfloat _tmp16_;
	gfloat _tmp17_;
	gfloat _tmp18_ = 0.0F;
	gboolean _tmp19_ = FALSE;
	gfloat _tmp20_;
	gboolean _tmp24_;
	self = (soyfieldsShockwave*) base;
	g_return_val_if_fail (other != NULL, FALSE);
	_tmp0_ = other;
	_tmp1_ = soy_bodies_body_get_position (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = _tmp2_;
	_tmp4_ = soy_atoms_position_get_x (_tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = other;
	_tmp7_ = soy_bodies_body_get_position (_tmp6_);
	_tmp8_ = _tmp7_;
	_tmp9_ = _tmp8_;
	_tmp10_ = soy_atoms_position_get_y (_tmp9_);
	_tmp11_ = _tmp10_;
	_tmp12_ = other;
	_tmp13_ = soy_bodies_body_get_position (_tmp12_);
	_tmp14_ = _tmp13_;
	_tmp15_ = _tmp14_;
	_tmp16_ = soy_atoms_position_get_z (_tmp15_);
	_tmp17_ = _tmp16_;
	_tmp18_ = soy_bodies_body_pointDepth ((soybodiesBody*) self, _tmp5_, _tmp11_, _tmp17_);
	depth = _tmp18_;
	_g_object_unref0 (_tmp15_);
	_g_object_unref0 (_tmp9_);
	_g_object_unref0 (_tmp3_);
	_tmp20_ = depth;
	if (_tmp20_ > ((gfloat) 0)) {
		gfloat _tmp21_;
		gfloat _tmp22_;
		gfloat _tmp23_;
		_tmp21_ = depth;
		_tmp22_ = soy_fields_shockwave_get_length (self);
		_tmp23_ = _tmp22_;
		_tmp19_ = _tmp21_ < _tmp23_;
	} else {
		_tmp19_ = FALSE;
	}
	_tmp24_ = _tmp19_;
	if (_tmp24_) {
		gfloat _tmp25_;
		gfloat _tmp26_;
		gfloat _tmp27_;
		gfloat _tmp28_;
		gfloat _tmp29_ = 0.0F;
		soybodiesBody* _tmp30_;
		soyatomsPosition* _tmp31_;
		soyatomsPosition* _tmp32_;
		soyatomsPosition* _tmp33_;
		gfloat _tmp34_;
		gfloat _tmp35_;
		soyatomsPosition* _tmp36_;
		soyatomsPosition* _tmp37_;
		soyatomsPosition* _tmp38_;
		gfloat _tmp39_;
		gfloat _tmp40_;
		soybodiesBody* _tmp41_;
		soyatomsPosition* _tmp42_;
		soyatomsPosition* _tmp43_;
		soyatomsPosition* _tmp44_;
		gfloat _tmp45_;
		gfloat _tmp46_;
		soyatomsPosition* _tmp47_;
		soyatomsPosition* _tmp48_;
		soyatomsPosition* _tmp49_;
		gfloat _tmp50_;
		gfloat _tmp51_;
		soybodiesBody* _tmp52_;
		soyatomsPosition* _tmp53_;
		soyatomsPosition* _tmp54_;
		soyatomsPosition* _tmp55_;
		gfloat _tmp56_;
		gfloat _tmp57_;
		soyatomsPosition* _tmp58_;
		soyatomsPosition* _tmp59_;
		soyatomsPosition* _tmp60_;
		gfloat _tmp61_;
		gfloat _tmp62_;
		gfloat _tmp63_;
		gfloat _tmp64_ = 0.0F;
		gfloat _tmp65_;
		gfloat _tmp66_ = 0.0F;
		gfloat _tmp67_;
		gfloat _tmp68_ = 0.0F;
		gfloat _tmp69_ = 0.0F;
		gfloat _tmp70_;
		gfloat _tmp71_;
		gfloat _tmp72_;
		gfloat _tmp73_;
		gfloat _tmp74_;
		gfloat _tmp75_;
		gfloat _tmp76_;
		gfloat _tmp77_;
		gfloat _tmp78_;
		gboolean _tmp79_ = FALSE;
		gboolean _tmp80_ = FALSE;
		soybodiesBody* _tmp81_;
		GeeHashMap* _tmp82_;
		GeeHashMap* _tmp83_;
		GeeHashMap* _tmp84_;
		gboolean _tmp85_ = FALSE;
		gboolean _tmp86_;
		gboolean _tmp92_;
		gboolean _tmp98_;
		_tmp25_ = self->priv->_outer;
		_tmp26_ = soy_fields_shockwave_get_swvel (self);
		_tmp27_ = _tmp26_;
		_tmp28_ = depth;
		_tmp29_ = powf ((((gfloat) _tmp25_) * _tmp27_) - _tmp28_, (gfloat) 2);
		force = 1 / (12.56637061f * _tmp29_);
		_tmp30_ = other;
		_tmp31_ = soy_bodies_body_get_position (_tmp30_);
		_tmp32_ = _tmp31_;
		_tmp33_ = _tmp32_;
		_tmp34_ = soy_atoms_position_get_x (_tmp33_);
		_tmp35_ = _tmp34_;
		_tmp36_ = soy_bodies_body_get_position ((soybodiesBody*) self);
		_tmp37_ = _tmp36_;
		_tmp38_ = _tmp37_;
		_tmp39_ = soy_atoms_position_get_x (_tmp38_);
		_tmp40_ = _tmp39_;
		dx = _tmp35_ - _tmp40_;
		_g_object_unref0 (_tmp38_);
		_g_object_unref0 (_tmp33_);
		_tmp41_ = other;
		_tmp42_ = soy_bodies_body_get_position (_tmp41_);
		_tmp43_ = _tmp42_;
		_tmp44_ = _tmp43_;
		_tmp45_ = soy_atoms_position_get_y (_tmp44_);
		_tmp46_ = _tmp45_;
		_tmp47_ = soy_bodies_body_get_position ((soybodiesBody*) self);
		_tmp48_ = _tmp47_;
		_tmp49_ = _tmp48_;
		_tmp50_ = soy_atoms_position_get_y (_tmp49_);
		_tmp51_ = _tmp50_;
		dy = _tmp46_ - _tmp51_;
		_g_object_unref0 (_tmp49_);
		_g_object_unref0 (_tmp44_);
		_tmp52_ = other;
		_tmp53_ = soy_bodies_body_get_position (_tmp52_);
		_tmp54_ = _tmp53_;
		_tmp55_ = _tmp54_;
		_tmp56_ = soy_atoms_position_get_z (_tmp55_);
		_tmp57_ = _tmp56_;
		_tmp58_ = soy_bodies_body_get_position ((soybodiesBody*) self);
		_tmp59_ = _tmp58_;
		_tmp60_ = _tmp59_;
		_tmp61_ = soy_atoms_position_get_z (_tmp60_);
		_tmp62_ = _tmp61_;
		dz = _tmp57_ - _tmp62_;
		_g_object_unref0 (_tmp60_);
		_g_object_unref0 (_tmp55_);
		_tmp63_ = dx;
		_tmp64_ = powf (_tmp63_, (gfloat) 2);
		_tmp65_ = dy;
		_tmp66_ = powf (_tmp65_, (gfloat) 2);
		_tmp67_ = dz;
		_tmp68_ = powf (_tmp67_, (gfloat) 2);
		_tmp69_ = sqrtf ((_tmp64_ + _tmp66_) + _tmp68_);
		d = _tmp69_;
		_tmp70_ = force;
		_tmp71_ = dx;
		_tmp72_ = d;
		dx = (_tmp70_ * _tmp71_) / _tmp72_;
		_tmp73_ = force;
		_tmp74_ = dy;
		_tmp75_ = d;
		dy = (_tmp73_ * _tmp74_) / _tmp75_;
		_tmp76_ = force;
		_tmp77_ = dz;
		_tmp78_ = d;
		dz = (_tmp76_ * _tmp77_) / _tmp78_;
		_tmp81_ = other;
		_tmp82_ = soy_bodies_body_get_tags (_tmp81_);
		_tmp83_ = _tmp82_;
		_tmp84_ = _tmp83_;
		_tmp85_ = gee_abstract_map_has_key ((GeeAbstractMap*) _tmp84_, "cpx");
		_tmp86_ = _tmp85_;
		_g_object_unref0 (_tmp84_);
		if (_tmp86_) {
			soybodiesBody* _tmp87_;
			GeeHashMap* _tmp88_;
			GeeHashMap* _tmp89_;
			GeeHashMap* _tmp90_;
			gboolean _tmp91_ = FALSE;
			_tmp87_ = other;
			_tmp88_ = soy_bodies_body_get_tags (_tmp87_);
			_tmp89_ = _tmp88_;
			_tmp90_ = _tmp89_;
			_tmp91_ = gee_abstract_map_has_key ((GeeAbstractMap*) _tmp90_, "cpy");
			_tmp80_ = _tmp91_;
			_g_object_unref0 (_tmp90_);
		} else {
			_tmp80_ = FALSE;
		}
		_tmp92_ = _tmp80_;
		if (_tmp92_) {
			soybodiesBody* _tmp93_;
			GeeHashMap* _tmp94_;
			GeeHashMap* _tmp95_;
			GeeHashMap* _tmp96_;
			gboolean _tmp97_ = FALSE;
			_tmp93_ = other;
			_tmp94_ = soy_bodies_body_get_tags (_tmp93_);
			_tmp95_ = _tmp94_;
			_tmp96_ = _tmp95_;
			_tmp97_ = gee_abstract_map_has_key ((GeeAbstractMap*) _tmp96_, "cpz");
			_tmp79_ = _tmp97_;
			_g_object_unref0 (_tmp96_);
		} else {
			_tmp79_ = FALSE;
		}
		_tmp98_ = _tmp79_;
		if (_tmp98_) {
			soybodiesBody* _tmp99_;
			gfloat _tmp100_;
			gfloat _tmp101_;
			gfloat _tmp102_;
			soybodiesBody* _tmp103_;
			GeeHashMap* _tmp104_;
			GeeHashMap* _tmp105_;
			GeeHashMap* _tmp106_;
			gpointer _tmp107_ = NULL;
			gfloat* _tmp108_;
			soybodiesBody* _tmp109_;
			GeeHashMap* _tmp110_;
			GeeHashMap* _tmp111_;
			GeeHashMap* _tmp112_;
			gpointer _tmp113_ = NULL;
			gfloat* _tmp114_;
			soybodiesBody* _tmp115_;
			GeeHashMap* _tmp116_;
			GeeHashMap* _tmp117_;
			GeeHashMap* _tmp118_;
			gpointer _tmp119_ = NULL;
			gfloat* _tmp120_;
			_tmp99_ = other;
			_tmp100_ = dx;
			_tmp101_ = dy;
			_tmp102_ = dz;
			_tmp103_ = other;
			_tmp104_ = soy_bodies_body_get_tags (_tmp103_);
			_tmp105_ = _tmp104_;
			_tmp106_ = _tmp105_;
			_tmp107_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp106_, "cpx");
			_tmp108_ = (gfloat*) _tmp107_;
			_tmp109_ = other;
			_tmp110_ = soy_bodies_body_get_tags (_tmp109_);
			_tmp111_ = _tmp110_;
			_tmp112_ = _tmp111_;
			_tmp113_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp112_, "cpy");
			_tmp114_ = (gfloat*) _tmp113_;
			_tmp115_ = other;
			_tmp116_ = soy_bodies_body_get_tags (_tmp115_);
			_tmp117_ = _tmp116_;
			_tmp118_ = _tmp117_;
			_tmp119_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp118_, "cpz");
			_tmp120_ = (gfloat*) _tmp119_;
			soy_bodies_body_addForceAtRelPos (_tmp99_, (dReal) _tmp100_, (dReal) _tmp101_, (dReal) _tmp102_, *_tmp108_, *_tmp114_, *_tmp120_);
			_g_free0 (_tmp120_);
			_g_object_unref0 (_tmp118_);
			_g_free0 (_tmp114_);
			_g_object_unref0 (_tmp112_);
			_g_free0 (_tmp108_);
			_g_object_unref0 (_tmp106_);
		} else {
			soybodiesBody* _tmp121_;
			gfloat _tmp122_;
			gfloat _tmp123_;
			gfloat _tmp124_;
			_tmp121_ = other;
			_tmp122_ = dx;
			_tmp123_ = dy;
			_tmp124_ = dz;
			soy_bodies_body_addForce (_tmp121_, (dReal) _tmp122_, (dReal) _tmp123_, (dReal) _tmp124_);
		}
	}
	result = TRUE;
	return result;
}


static void soy_fields_shockwave_real_give (soyfieldsField* base, gint data) {
	soyfieldsShockwave * self;
	gfloat _tmp0_;
	soyscenesScene* _tmp1_;
	guint64 _tmp2_;
	guint64 _tmp3_;
	gfloat _tmp4_;
	gfloat _tmp5_;
	gfloat _tmp6_;
	gfloat _tmp7_;
	gfloat _tmp8_;
	gfloat _tmp9_;
	self = (soyfieldsShockwave*) base;
	_tmp0_ = self->priv->_outer;
	self->priv->_inner = _tmp0_;
	_tmp1_ = ((soybodiesBody*) self)->scene;
	_tmp2_ = soy_scenes_scene_get_time (_tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = self->priv->_t0;
	self->priv->_outer = ((gfloat) _tmp3_) - _tmp4_;
	_tmp5_ = self->priv->_inner;
	_tmp6_ = soy_fields_shockwave_get_swvel (self);
	_tmp7_ = _tmp6_;
	_tmp8_ = soy_fields_shockwave_get_radius (self);
	_tmp9_ = _tmp8_;
	if ((_tmp5_ * _tmp7_) > _tmp9_) {
		struct dxGeom* _tmp10_;
		_tmp10_ = ((soybodiesBody*) self)->geom;
		dGeomSphereSetRadius ((struct dxGeom*) _tmp10_, (dReal) 0);
		self->priv->_t0 = (gfloat) 0;
	}
}


soyfieldsShockwave* soy_fields_shockwave_construct (GType object_type) {
	soyfieldsShockwave * self = NULL;
	self = (soyfieldsShockwave*) soy_fields_field_construct (object_type);
	return self;
}


soyfieldsShockwave* soy_fields_shockwave_new (void) {
	return soy_fields_shockwave_construct (SOY_FIELDS_TYPE_SHOCKWAVE);
}


gfloat soy_fields_shockwave_get_swvel (soyfieldsShockwave* self) {
	gfloat result;
	gfloat _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0F);
	_tmp0_ = self->priv->_swvel;
	result = _tmp0_;
	return result;
}


void soy_fields_shockwave_set_swvel (soyfieldsShockwave* self, gfloat value) {
	gfloat _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_swvel = _tmp0_;
	g_object_notify ((GObject *) self, "swvel");
}


gfloat soy_fields_shockwave_get_energy (soyfieldsShockwave* self) {
	gfloat result;
	gfloat _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0F);
	_tmp0_ = self->priv->_energy;
	result = _tmp0_;
	return result;
}


void soy_fields_shockwave_set_energy (soyfieldsShockwave* self, gfloat value) {
	gfloat _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_energy = _tmp0_;
	g_object_notify ((GObject *) self, "energy");
}


gfloat soy_fields_shockwave_get_radius (soyfieldsShockwave* self) {
	gfloat result;
	gfloat _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0F);
	_tmp0_ = self->priv->_radius;
	result = _tmp0_;
	return result;
}


void soy_fields_shockwave_set_radius (soyfieldsShockwave* self, gfloat value) {
	gfloat _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_radius = _tmp0_;
	g_object_notify ((GObject *) self, "radius");
}


gfloat soy_fields_shockwave_get_length (soyfieldsShockwave* self) {
	gfloat result;
	gfloat _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0F);
	_tmp0_ = self->priv->_length;
	result = _tmp0_;
	return result;
}


void soy_fields_shockwave_set_length (soyfieldsShockwave* self, gfloat value) {
	gfloat _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_length = _tmp0_;
	g_object_notify ((GObject *) self, "length");
}


static GObject * soy_fields_shockwave_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	soyfieldsShockwave * self;
	struct dxSpace* _tmp0_;
	soyscenesScene* _tmp1_;
	struct dxSpace* _tmp2_;
	struct dxGeom* _tmp3_;
	parent_class = G_OBJECT_CLASS (soy_fields_shockwave_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_FIELDS_TYPE_SHOCKWAVE, soyfieldsShockwave);
	_tmp0_ = dHashSpaceCreate (NULL);
	_dSpaceDestroy0 (self->priv->_space);
	self->priv->_space = _tmp0_;
	_tmp1_ = ((soybodiesBody*) self)->scene;
	_tmp2_ = _tmp1_->space;
	_tmp3_ = dCreateSphere (_tmp2_, (dReal) 0.0f);
	_dGeomDestroy0 (((soybodiesBody*) self)->geom);
	((soybodiesBody*) self)->geom = _tmp3_;
	return obj;
}


static void soy_fields_shockwave_class_init (soyfieldsShockwaveClass * klass) {
	soy_fields_shockwave_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (soyfieldsShockwavePrivate));
	SOY_FIELDS_FIELD_CLASS (klass)->exert = soy_fields_shockwave_real_exert;
	SOY_FIELDS_FIELD_CLASS (klass)->give = soy_fields_shockwave_real_give;
	G_OBJECT_CLASS (klass)->get_property = _vala_soy_fields_shockwave_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_soy_fields_shockwave_set_property;
	G_OBJECT_CLASS (klass)->constructor = soy_fields_shockwave_constructor;
	G_OBJECT_CLASS (klass)->finalize = soy_fields_shockwave_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_FIELDS_SHOCKWAVE_SWVEL, g_param_spec_float ("swvel", "swvel", "swvel", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_FIELDS_SHOCKWAVE_ENERGY, g_param_spec_float ("energy", "energy", "energy", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_FIELDS_SHOCKWAVE_RADIUS, g_param_spec_float ("radius", "radius", "radius", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_FIELDS_SHOCKWAVE_LENGTH, g_param_spec_float ("length", "length", "length", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void soy_fields_shockwave_instance_init (soyfieldsShockwave * self) {
	self->priv = SOY_FIELDS_SHOCKWAVE_GET_PRIVATE (self);
}


static void soy_fields_shockwave_finalize (GObject* obj) {
	soyfieldsShockwave * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_FIELDS_TYPE_SHOCKWAVE, soyfieldsShockwave);
	_dSpaceDestroy0 (self->priv->_space);
	G_OBJECT_CLASS (soy_fields_shockwave_parent_class)->finalize (obj);
}


GType soy_fields_shockwave_get_type (void) {
	static volatile gsize soy_fields_shockwave_type_id__volatile = 0;
	if (g_once_init_enter (&soy_fields_shockwave_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soyfieldsShockwaveClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_fields_shockwave_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soyfieldsShockwave), 0, (GInstanceInitFunc) soy_fields_shockwave_instance_init, NULL };
		GType soy_fields_shockwave_type_id;
		soy_fields_shockwave_type_id = g_type_register_static (SOY_FIELDS_TYPE_FIELD, "soyfieldsShockwave", &g_define_type_info, 0);
		g_once_init_leave (&soy_fields_shockwave_type_id__volatile, soy_fields_shockwave_type_id);
	}
	return soy_fields_shockwave_type_id__volatile;
}


static void _vala_soy_fields_shockwave_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	soyfieldsShockwave * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_FIELDS_TYPE_SHOCKWAVE, soyfieldsShockwave);
	switch (property_id) {
		case SOY_FIELDS_SHOCKWAVE_SWVEL:
		g_value_set_float (value, soy_fields_shockwave_get_swvel (self));
		break;
		case SOY_FIELDS_SHOCKWAVE_ENERGY:
		g_value_set_float (value, soy_fields_shockwave_get_energy (self));
		break;
		case SOY_FIELDS_SHOCKWAVE_RADIUS:
		g_value_set_float (value, soy_fields_shockwave_get_radius (self));
		break;
		case SOY_FIELDS_SHOCKWAVE_LENGTH:
		g_value_set_float (value, soy_fields_shockwave_get_length (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_soy_fields_shockwave_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	soyfieldsShockwave * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_FIELDS_TYPE_SHOCKWAVE, soyfieldsShockwave);
	switch (property_id) {
		case SOY_FIELDS_SHOCKWAVE_SWVEL:
		soy_fields_shockwave_set_swvel (self, g_value_get_float (value));
		break;
		case SOY_FIELDS_SHOCKWAVE_ENERGY:
		soy_fields_shockwave_set_energy (self, g_value_get_float (value));
		break;
		case SOY_FIELDS_SHOCKWAVE_RADIUS:
		soy_fields_shockwave_set_radius (self, g_value_get_float (value));
		break;
		case SOY_FIELDS_SHOCKWAVE_LENGTH:
		soy_fields_shockwave_set_length (self, g_value_get_float (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



