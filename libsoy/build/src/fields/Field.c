/* Field.c generated by valac 0.18.1, the Vala compiler
 * generated from Field.gs, do not modify */

/*
 *  libsoy - soy.fields.Field
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
#include <ode.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>


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

#define SOY_ATOMS_TYPE_POSITION (soy_atoms_position_get_type ())
#define SOY_ATOMS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPosition))
#define SOY_ATOMS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))
#define SOY_ATOMS_IS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_IS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_POSITION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))

typedef struct _soyatomsPosition soyatomsPosition;
typedef struct _soyatomsPositionClass soyatomsPositionClass;

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


static gpointer soy_fields_field_parent_class = NULL;

GType soy_bodies_body_get_type (void) G_GNUC_CONST;
GType soy_scenes_scene_get_type (void) G_GNUC_CONST;
GType soy_fields_field_get_type (void) G_GNUC_CONST;
enum  {
	SOY_FIELDS_FIELD_DUMMY_PROPERTY
};
soyfieldsField* soy_fields_field_new (void);
soyfieldsField* soy_fields_field_construct (GType object_type);
GType soy_atoms_position_get_type (void) G_GNUC_CONST;
soybodiesBody* soy_bodies_body_new (soyatomsPosition* position, GObject* geom_param, gfloat geom_scalar);
soybodiesBody* soy_bodies_body_construct (GType object_type, soyatomsPosition* position, GObject* geom_param, gfloat geom_scalar);
gboolean soy_fields_field_apply (soyfieldsField* self);
gboolean soy_fields_field_exert (soyfieldsField* self, soybodiesBody* other);
static gboolean soy_fields_field_real_exert (soyfieldsField* self, soybodiesBody* other);
void soy_fields_field_give (soyfieldsField* self, gint data);
static void soy_fields_field_real_give (soyfieldsField* self, gint data);
void soy_fields_field_commit (soyfieldsField* self);
static void soy_fields_field_real_commit (soyfieldsField* self);


soyfieldsField* soy_fields_field_construct (GType object_type) {
	soyfieldsField * self = NULL;
	self = (soyfieldsField*) soy_bodies_body_construct (object_type, NULL, NULL, 0.0f);
	return self;
}


soyfieldsField* soy_fields_field_new (void) {
	return soy_fields_field_construct (SOY_FIELDS_TYPE_FIELD);
}


gboolean soy_fields_field_apply (soyfieldsField* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	result = TRUE;
	return result;
}


static gboolean soy_fields_field_real_exert (soyfieldsField* self, soybodiesBody* other) {
	gboolean result = FALSE;
	g_return_val_if_fail (other != NULL, FALSE);
	result = TRUE;
	return result;
}


gboolean soy_fields_field_exert (soyfieldsField* self, soybodiesBody* other) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SOY_FIELDS_FIELD_GET_CLASS (self)->exert (self, other);
}


static void soy_fields_field_real_give (soyfieldsField* self, gint data) {
	return;
}


void soy_fields_field_give (soyfieldsField* self, gint data) {
	g_return_if_fail (self != NULL);
	SOY_FIELDS_FIELD_GET_CLASS (self)->give (self, data);
}


static void soy_fields_field_real_commit (soyfieldsField* self) {
	return;
}


void soy_fields_field_commit (soyfieldsField* self) {
	g_return_if_fail (self != NULL);
	SOY_FIELDS_FIELD_GET_CLASS (self)->commit (self);
}


static void soy_fields_field_class_init (soyfieldsFieldClass * klass) {
	soy_fields_field_parent_class = g_type_class_peek_parent (klass);
	SOY_FIELDS_FIELD_CLASS (klass)->exert = soy_fields_field_real_exert;
	SOY_FIELDS_FIELD_CLASS (klass)->give = soy_fields_field_real_give;
	SOY_FIELDS_FIELD_CLASS (klass)->commit = soy_fields_field_real_commit;
}


static void soy_fields_field_instance_init (soyfieldsField * self) {
}


GType soy_fields_field_get_type (void) {
	static volatile gsize soy_fields_field_type_id__volatile = 0;
	if (g_once_init_enter (&soy_fields_field_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soyfieldsFieldClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_fields_field_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soyfieldsField), 0, (GInstanceInitFunc) soy_fields_field_instance_init, NULL };
		GType soy_fields_field_type_id;
		soy_fields_field_type_id = g_type_register_static (SOY_BODIES_TYPE_BODY, "soyfieldsField", &g_define_type_info, 0);
		g_once_init_leave (&soy_fields_field_type_id__volatile, soy_fields_field_type_id);
	}
	return soy_fields_field_type_id__volatile;
}



