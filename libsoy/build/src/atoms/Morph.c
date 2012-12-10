/* Morph.c generated by valac 0.18.1, the Vala compiler
 * generated from Morph.gs, do not modify */

/*
 *  libsoy - soy.atoms.Face
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
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <float.h>
#include <math.h>


#define SOY_ATOMS_TYPE_MORPH (soy_atoms_morph_get_type ())
#define SOY_ATOMS_MORPH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_ATOMS_TYPE_MORPH, soyatomsMorph))
#define SOY_ATOMS_MORPH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_ATOMS_TYPE_MORPH, soyatomsMorphClass))
#define SOY_ATOMS_IS_MORPH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_ATOMS_TYPE_MORPH))
#define SOY_ATOMS_IS_MORPH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_ATOMS_TYPE_MORPH))
#define SOY_ATOMS_MORPH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_ATOMS_TYPE_MORPH, soyatomsMorphClass))

typedef struct _soyatomsMorph soyatomsMorph;
typedef struct _soyatomsMorphClass soyatomsMorphClass;
typedef struct _soyatomsMorphPrivate soyatomsMorphPrivate;

#define SOY_BODIES_TYPE_BODY (soy_bodies_body_get_type ())
#define SOY_BODIES_BODY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_BODIES_TYPE_BODY, soybodiesBody))
#define SOY_BODIES_BODY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_BODIES_TYPE_BODY, soybodiesBodyClass))
#define SOY_BODIES_IS_BODY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_BODIES_TYPE_BODY))
#define SOY_BODIES_IS_BODY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_BODIES_TYPE_BODY))
#define SOY_BODIES_BODY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_BODIES_TYPE_BODY, soybodiesBodyClass))

typedef struct _soybodiesBody soybodiesBody;
typedef struct _soybodiesBodyClass soybodiesBodyClass;

#define SOY_BODIES_TYPE_MESH (soy_bodies_mesh_get_type ())
#define SOY_BODIES_MESH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_BODIES_TYPE_MESH, soybodiesMesh))
#define SOY_BODIES_MESH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_BODIES_TYPE_MESH, soybodiesMeshClass))
#define SOY_BODIES_IS_MESH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_BODIES_TYPE_MESH))
#define SOY_BODIES_IS_MESH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_BODIES_TYPE_MESH))
#define SOY_BODIES_MESH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_BODIES_TYPE_MESH, soybodiesMeshClass))

typedef struct _soybodiesMesh soybodiesMesh;
typedef struct _soybodiesMeshClass soybodiesMeshClass;

struct _soyatomsMorph {
	GObject parent_instance;
	soyatomsMorphPrivate * priv;
};

struct _soyatomsMorphClass {
	GObjectClass parent_class;
};

struct _soyatomsMorphPrivate {
	GLfloat* _mtrx_orig;
	GLsizei _length;
	gfloat _delta;
	GLfloat* _mtrx;
};


static gpointer soy_atoms_morph_parent_class = NULL;

GType soy_atoms_morph_get_type (void) G_GNUC_CONST;
#define SOY_ATOMS_MORPH_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_ATOMS_TYPE_MORPH, soyatomsMorphPrivate))
enum  {
	SOY_ATOMS_MORPH_DUMMY_PROPERTY,
	SOY_ATOMS_MORPH_DELTA,
	SOY_ATOMS_MORPH_MATRIX
};
GType soy_bodies_body_get_type (void) G_GNUC_CONST;
GType soy_bodies_mesh_get_type (void) G_GNUC_CONST;
soyatomsMorph* soy_atoms_morph_new (soybodiesMesh* a, soybodiesMesh* b);
soyatomsMorph* soy_atoms_morph_construct (GType object_type, soybodiesMesh* a, soybodiesMesh* b);
static void _soy_atoms_morph_gen_buffer (soyatomsMorph* self, soybodiesMesh* a, soybodiesMesh* b);
static void _soy_atoms_morph_gen_mtrx (soyatomsMorph* self, soybodiesMesh* a, soybodiesMesh* b);
soyatomsMorph* soy_atoms_morph_new_with_delta (soybodiesMesh* a, soybodiesMesh* b, gfloat delta);
soyatomsMorph* soy_atoms_morph_construct_with_delta (GType object_type, soybodiesMesh* a, soybodiesMesh* b, gfloat delta);
gint soy_bodies_mesh_get_length (soybodiesMesh* self);
GLfloat* soy_bodies_mesh_get_raw_verts (soybodiesMesh* self);
static void _soy_atoms_morph_update_mtrx (soyatomsMorph* self);
gfloat soy_atoms_morph_get_delta (soyatomsMorph* self);
void soy_atoms_morph_set_delta (soyatomsMorph* self, gfloat value);
GLfloat* soy_atoms_morph_get_matrix (soyatomsMorph* self);
static void soy_atoms_morph_finalize (GObject* obj);
static void _vala_soy_atoms_morph_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_soy_atoms_morph_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


soyatomsMorph* soy_atoms_morph_construct (GType object_type, soybodiesMesh* a, soybodiesMesh* b) {
	soyatomsMorph * self = NULL;
	soybodiesMesh* _tmp0_;
	soybodiesMesh* _tmp1_;
	soybodiesMesh* _tmp2_;
	soybodiesMesh* _tmp3_;
	g_return_val_if_fail (a != NULL, NULL);
	g_return_val_if_fail (b != NULL, NULL);
	self = (soyatomsMorph*) g_object_new (object_type, NULL);
	self->priv->_delta = 0.0f;
	_tmp0_ = a;
	_tmp1_ = b;
	_soy_atoms_morph_gen_buffer (self, _tmp0_, _tmp1_);
	_tmp2_ = a;
	_tmp3_ = b;
	_soy_atoms_morph_gen_mtrx (self, _tmp2_, _tmp3_);
	return self;
}


soyatomsMorph* soy_atoms_morph_new (soybodiesMesh* a, soybodiesMesh* b) {
	return soy_atoms_morph_construct (SOY_ATOMS_TYPE_MORPH, a, b);
}


soyatomsMorph* soy_atoms_morph_construct_with_delta (GType object_type, soybodiesMesh* a, soybodiesMesh* b, gfloat delta) {
	soyatomsMorph * self = NULL;
	gfloat _tmp0_;
	soybodiesMesh* _tmp1_;
	soybodiesMesh* _tmp2_;
	soybodiesMesh* _tmp3_;
	soybodiesMesh* _tmp4_;
	g_return_val_if_fail (a != NULL, NULL);
	g_return_val_if_fail (b != NULL, NULL);
	self = (soyatomsMorph*) g_object_new (object_type, NULL);
	_tmp0_ = delta;
	self->priv->_delta = _tmp0_;
	_tmp1_ = a;
	_tmp2_ = b;
	_soy_atoms_morph_gen_buffer (self, _tmp1_, _tmp2_);
	_tmp3_ = a;
	_tmp4_ = b;
	_soy_atoms_morph_gen_mtrx (self, _tmp3_, _tmp4_);
	return self;
}


soyatomsMorph* soy_atoms_morph_new_with_delta (soybodiesMesh* a, soybodiesMesh* b, gfloat delta) {
	return soy_atoms_morph_construct_with_delta (SOY_ATOMS_TYPE_MORPH, a, b, delta);
}


static void _soy_atoms_morph_gen_buffer (soyatomsMorph* self, soybodiesMesh* a, soybodiesMesh* b) {
	gulong buffer_size = 0UL;
	soybodiesMesh* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	soybodiesMesh* _tmp3_;
	gint _tmp4_;
	gint _tmp5_;
	soybodiesMesh* _tmp6_;
	gint _tmp7_;
	gint _tmp8_;
	gulong _tmp9_;
	soybodiesMesh* _tmp26_;
	gint _tmp27_;
	gint _tmp28_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (a != NULL);
	g_return_if_fail (b != NULL);
	_tmp0_ = a;
	_tmp1_ = soy_bodies_mesh_get_length (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = b;
	_tmp4_ = soy_bodies_mesh_get_length (_tmp3_);
	_tmp5_ = _tmp4_;
	if (_tmp2_ != _tmp5_) {
		return;
	}
	_tmp6_ = a;
	_tmp7_ = soy_bodies_mesh_get_length (_tmp6_);
	_tmp8_ = _tmp7_;
	buffer_size = (_tmp8_ * 36) * sizeof (GLfloat);
	_tmp9_ = buffer_size;
	if (_tmp9_ == ((gulong) 0)) {
		GLfloat* _tmp10_;
		GLfloat* _tmp12_;
		_tmp10_ = self->priv->_mtrx;
		if (_tmp10_ != NULL) {
			GLfloat* _tmp11_;
			_tmp11_ = self->priv->_mtrx;
			g_free (_tmp11_);
			self->priv->_mtrx = NULL;
		}
		_tmp12_ = self->priv->_mtrx_orig;
		if (_tmp12_ != NULL) {
			GLfloat* _tmp13_;
			_tmp13_ = self->priv->_mtrx_orig;
			g_free (_tmp13_);
			self->priv->_mtrx_orig = NULL;
		}
	} else {
		GLfloat* _tmp14_;
		GLfloat* _tmp20_;
		_tmp14_ = self->priv->_mtrx;
		if (_tmp14_ != NULL) {
			GLfloat* _tmp15_;
			gulong _tmp16_;
			void* _tmp17_ = NULL;
			_tmp15_ = self->priv->_mtrx;
			_tmp16_ = buffer_size;
			_tmp17_ = g_realloc (_tmp15_, (gsize) _tmp16_);
			self->priv->_mtrx = (GLfloat*) _tmp17_;
		} else {
			gulong _tmp18_;
			void* _tmp19_ = NULL;
			_tmp18_ = buffer_size;
			_tmp19_ = g_malloc0 ((gsize) _tmp18_);
			self->priv->_mtrx = (GLfloat*) _tmp19_;
		}
		_tmp20_ = self->priv->_mtrx_orig;
		if (_tmp20_ != NULL) {
			GLfloat* _tmp21_;
			gulong _tmp22_;
			void* _tmp23_ = NULL;
			_tmp21_ = self->priv->_mtrx_orig;
			_tmp22_ = buffer_size;
			_tmp23_ = g_realloc (_tmp21_, (gsize) _tmp22_);
			self->priv->_mtrx_orig = (GLfloat*) _tmp23_;
		} else {
			gulong _tmp24_;
			void* _tmp25_ = NULL;
			_tmp24_ = buffer_size;
			_tmp25_ = g_malloc0 ((gsize) _tmp24_);
			self->priv->_mtrx_orig = (GLfloat*) _tmp25_;
		}
	}
	_tmp26_ = a;
	_tmp27_ = soy_bodies_mesh_get_length (_tmp26_);
	_tmp28_ = _tmp27_;
	self->priv->_length = ((GLsizei) _tmp28_) * 36;
}


static void _soy_atoms_morph_gen_mtrx (soyatomsMorph* self, soybodiesMesh* a, soybodiesMesh* b) {
	soybodiesMesh* _tmp0_;
	GLfloat* _tmp1_ = NULL;
	GLfloat* verts_a;
	soybodiesMesh* _tmp2_;
	GLfloat* _tmp3_ = NULL;
	GLfloat* verts_b;
	GLfloat diff = 0.0F;
	g_return_if_fail (self != NULL);
	g_return_if_fail (a != NULL);
	g_return_if_fail (b != NULL);
	_tmp0_ = a;
	_tmp1_ = soy_bodies_mesh_get_raw_verts (_tmp0_);
	verts_a = _tmp1_;
	_tmp2_ = b;
	_tmp3_ = soy_bodies_mesh_get_raw_verts (_tmp2_);
	verts_b = _tmp3_;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp4_;
			_tmp4_ = TRUE;
			while (TRUE) {
				gboolean _tmp5_;
				GLsizei _tmp7_;
				GLfloat* _tmp8_;
				gint _tmp9_;
				GLfloat _tmp10_;
				GLfloat* _tmp11_;
				gint _tmp12_;
				GLfloat _tmp13_;
				GLfloat* _tmp14_;
				gint _tmp15_;
				GLfloat _tmp16_;
				GLfloat _tmp17_;
				GLfloat* _tmp18_;
				gint _tmp19_;
				GLfloat _tmp20_;
				gfloat _tmp21_;
				GLfloat _tmp22_;
				_tmp5_ = _tmp4_;
				if (!_tmp5_) {
					gint _tmp6_;
					_tmp6_ = i;
					i = _tmp6_ + 1;
				}
				_tmp4_ = FALSE;
				_tmp7_ = self->priv->_length;
				if (!(i <= ((gint) _tmp7_))) {
					break;
				}
				_tmp8_ = verts_b;
				_tmp9_ = i;
				_tmp10_ = _tmp8_[_tmp9_];
				_tmp11_ = verts_a;
				_tmp12_ = i;
				_tmp13_ = _tmp11_[_tmp12_];
				diff = (GLfloat) (_tmp10_ - _tmp13_);
				_tmp14_ = self->priv->_mtrx_orig;
				_tmp15_ = i;
				_tmp16_ = diff;
				_tmp14_[_tmp15_] = _tmp16_;
				_tmp17_ = _tmp14_[_tmp15_];
				_tmp18_ = self->priv->_mtrx;
				_tmp19_ = i;
				_tmp20_ = diff;
				_tmp21_ = self->priv->_delta;
				_tmp18_[_tmp19_] = (GLfloat) (_tmp20_ * _tmp21_);
				_tmp22_ = _tmp18_[_tmp19_];
			}
		}
	}
}


static void _soy_atoms_morph_update_mtrx (soyatomsMorph* self) {
	g_return_if_fail (self != NULL);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				gboolean _tmp1_;
				GLsizei _tmp3_;
				GLfloat* _tmp4_;
				gint _tmp5_;
				GLfloat* _tmp6_;
				gint _tmp7_;
				GLfloat _tmp8_;
				gfloat _tmp9_;
				GLfloat _tmp10_;
				_tmp1_ = _tmp0_;
				if (!_tmp1_) {
					gint _tmp2_;
					_tmp2_ = i;
					i = _tmp2_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp3_ = self->priv->_length;
				if (!(i <= ((gint) _tmp3_))) {
					break;
				}
				_tmp4_ = self->priv->_mtrx;
				_tmp5_ = i;
				_tmp6_ = self->priv->_mtrx_orig;
				_tmp7_ = i;
				_tmp8_ = _tmp6_[_tmp7_];
				_tmp9_ = self->priv->_delta;
				_tmp4_[_tmp5_] = (GLfloat) (_tmp8_ * _tmp9_);
				_tmp10_ = _tmp4_[_tmp5_];
			}
		}
	}
}


gfloat soy_atoms_morph_get_delta (soyatomsMorph* self) {
	gfloat result;
	gfloat _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0F);
	_tmp0_ = self->priv->_delta;
	result = _tmp0_;
	return result;
}


void soy_atoms_morph_set_delta (soyatomsMorph* self, gfloat value) {
	gboolean _tmp0_ = FALSE;
	gfloat _tmp1_;
	gboolean _tmp3_;
	g_return_if_fail (self != NULL);
	_tmp1_ = value;
	if (((gdouble) _tmp1_) <= 1.0) {
		gfloat _tmp2_;
		_tmp2_ = value;
		_tmp0_ = ((gdouble) _tmp2_) >= 0.0;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		gfloat _tmp4_;
		_tmp4_ = value;
		self->priv->_delta = _tmp4_;
		_soy_atoms_morph_update_mtrx (self);
		g_signal_emit_by_name (self, "on-set", self);
	}
	g_object_notify ((GObject *) self, "delta");
}


GLfloat* soy_atoms_morph_get_matrix (soyatomsMorph* self) {
	GLfloat* result;
	GLfloat* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_mtrx;
	result = _tmp0_;
	return result;
}


static void soy_atoms_morph_class_init (soyatomsMorphClass * klass) {
	soy_atoms_morph_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (soyatomsMorphPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_soy_atoms_morph_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_soy_atoms_morph_set_property;
	G_OBJECT_CLASS (klass)->finalize = soy_atoms_morph_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_ATOMS_MORPH_DELTA, g_param_spec_float ("delta", "delta", "delta", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_ATOMS_MORPH_MATRIX, g_param_spec_pointer ("matrix", "matrix", "matrix", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_signal_new ("on_set", SOY_ATOMS_TYPE_MORPH, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, SOY_ATOMS_TYPE_MORPH);
}


static void soy_atoms_morph_instance_init (soyatomsMorph * self) {
	self->priv = SOY_ATOMS_MORPH_GET_PRIVATE (self);
}


static void soy_atoms_morph_finalize (GObject* obj) {
	soyatomsMorph * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_ATOMS_TYPE_MORPH, soyatomsMorph);
	G_OBJECT_CLASS (soy_atoms_morph_parent_class)->finalize (obj);
}


GType soy_atoms_morph_get_type (void) {
	static volatile gsize soy_atoms_morph_type_id__volatile = 0;
	if (g_once_init_enter (&soy_atoms_morph_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soyatomsMorphClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_atoms_morph_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soyatomsMorph), 0, (GInstanceInitFunc) soy_atoms_morph_instance_init, NULL };
		GType soy_atoms_morph_type_id;
		soy_atoms_morph_type_id = g_type_register_static (G_TYPE_OBJECT, "soyatomsMorph", &g_define_type_info, 0);
		g_once_init_leave (&soy_atoms_morph_type_id__volatile, soy_atoms_morph_type_id);
	}
	return soy_atoms_morph_type_id__volatile;
}


static void _vala_soy_atoms_morph_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	soyatomsMorph * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_ATOMS_TYPE_MORPH, soyatomsMorph);
	switch (property_id) {
		case SOY_ATOMS_MORPH_DELTA:
		g_value_set_float (value, soy_atoms_morph_get_delta (self));
		break;
		case SOY_ATOMS_MORPH_MATRIX:
		g_value_set_pointer (value, soy_atoms_morph_get_matrix (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_soy_atoms_morph_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	soyatomsMorph * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_ATOMS_TYPE_MORPH, soyatomsMorph);
	switch (property_id) {
		case SOY_ATOMS_MORPH_DELTA:
		soy_atoms_morph_set_delta (self, g_value_get_float (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


