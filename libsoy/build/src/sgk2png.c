/* sgk2png.c generated by valac 0.18.1, the Vala compiler
 * generated from sgk2png.gs, do not modify */

/*
 *  libsoy - soy.sgk2png
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
#include <gee.h>
#include <librsvg/rsvg.h>
#include <cairo.h>
#include <stdio.h>
#include <gobject/gvaluecollector.h>


#define SOY_TYPE_SG_K2_PNG_CONVERTER (soy_sg_k2_png_converter_get_type ())
#define SOY_SG_K2_PNG_CONVERTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_TYPE_SG_K2_PNG_CONVERTER, soySGK2PNGConverter))
#define SOY_SG_K2_PNG_CONVERTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_TYPE_SG_K2_PNG_CONVERTER, soySGK2PNGConverterClass))
#define SOY_IS_SG_K2_PNG_CONVERTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_TYPE_SG_K2_PNG_CONVERTER))
#define SOY_IS_SG_K2_PNG_CONVERTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_TYPE_SG_K2_PNG_CONVERTER))
#define SOY_SG_K2_PNG_CONVERTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_TYPE_SG_K2_PNG_CONVERTER, soySGK2PNGConverterClass))

typedef struct _soySGK2PNGConverter soySGK2PNGConverter;
typedef struct _soySGK2PNGConverterClass soySGK2PNGConverterClass;
typedef struct _soySGK2PNGConverterPrivate soySGK2PNGConverterPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _cairo_surface_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_surface_destroy (var), NULL)))
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _soyParamSpecSGK2PNGConverter soyParamSpecSGK2PNGConverter;

struct _soySGK2PNGConverter {
	GTypeInstance parent_instance;
	volatile int ref_count;
	soySGK2PNGConverterPrivate * priv;
};

struct _soySGK2PNGConverterClass {
	GTypeClass parent_class;
	void (*finalize) (soySGK2PNGConverter *self);
};

struct _soySGK2PNGConverterPrivate {
	GeeArrayList* _png_data;
};

struct _soyParamSpecSGK2PNGConverter {
	GParamSpec parent_instance;
};


static gpointer soy_sg_k2_png_converter_parent_class = NULL;

gpointer soy_sg_k2_png_converter_ref (gpointer instance);
void soy_sg_k2_png_converter_unref (gpointer instance);
GParamSpec* soy_param_spec_sg_k2_png_converter (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void soy_value_set_sg_k2_png_converter (GValue* value, gpointer v_object);
void soy_value_take_sg_k2_png_converter (GValue* value, gpointer v_object);
gpointer soy_value_get_sg_k2_png_converter (const GValue* value);
GType soy_sg_k2_png_converter_get_type (void) G_GNUC_CONST;
#define SOY_SG_K2_PNG_CONVERTER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_TYPE_SG_K2_PNG_CONVERTER, soySGK2PNGConverterPrivate))
enum  {
	SOY_SG_K2_PNG_CONVERTER_DUMMY_PROPERTY
};
soySGK2PNGConverter* soy_sg_k2_png_converter_new (void);
soySGK2PNGConverter* soy_sg_k2_png_converter_construct (GType object_type);
void soy_sg_k2_png_converter_set_png_data (soySGK2PNGConverter* self, GeeArrayList* value);
void soy_sg_k2_png_converter_sgk2png (soySGK2PNGConverter* self, guchar* sgk_data, int sgk_data_length1);
cairo_status_t soy_sg_k2_png_converter_writefunc (soySGK2PNGConverter* self, guchar* input, int input_length1);
static cairo_status_t _soy_sg_k2_png_converter_writefunc_cairo_write_func_t (gpointer self, guchar* data, int data_length1);
guchar* soy_sg_k2_png_converter_get_png (soySGK2PNGConverter* self, int* result_length1);
GeeArrayList* soy_sg_k2_png_converter_get_png_data (soySGK2PNGConverter* self);
static void soy_sg_k2_png_converter_finalize (soySGK2PNGConverter* obj);


soySGK2PNGConverter* soy_sg_k2_png_converter_construct (GType object_type) {
	soySGK2PNGConverter* self = NULL;
	GeeArrayList* _tmp0_;
	GeeArrayList* _tmp1_;
	self = (soySGK2PNGConverter*) g_type_create_instance (object_type);
	_tmp0_ = gee_array_list_new (G_TYPE_UCHAR, NULL, NULL, NULL);
	_tmp1_ = _tmp0_;
	soy_sg_k2_png_converter_set_png_data (self, _tmp1_);
	_g_object_unref0 (_tmp1_);
	return self;
	return self;
}


soySGK2PNGConverter* soy_sg_k2_png_converter_new (void) {
	return soy_sg_k2_png_converter_construct (SOY_TYPE_SG_K2_PNG_CONVERTER);
}


static cairo_status_t _soy_sg_k2_png_converter_writefunc_cairo_write_func_t (gpointer self, guchar* data, int data_length1) {
	cairo_status_t result;
	result = soy_sg_k2_png_converter_writefunc (self, data, data_length1);
	return result;
}


void soy_sg_k2_png_converter_sgk2png (soySGK2PNGConverter* self, guchar* sgk_data, int sgk_data_length1) {
	RsvgHandle* handle = NULL;
	cairo_surface_t* surface = NULL;
	cairo_t* context = NULL;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	{
		guchar* _tmp0_;
		gint _tmp0__length1;
		RsvgHandle* _tmp1_;
		RsvgHandle* _tmp2_;
		RsvgHandle* _tmp3_;
		gint _tmp4_ = 0;
		gint _tmp5_;
		RsvgHandle* _tmp6_;
		gint _tmp7_ = 0;
		gint _tmp8_;
		cairo_surface_t* _tmp9_;
		cairo_surface_t* _tmp10_;
		cairo_t* _tmp11_;
		RsvgHandle* _tmp12_;
		cairo_t* _tmp13_;
		cairo_surface_t* _tmp14_;
		_tmp0_ = sgk_data;
		_tmp0__length1 = sgk_data_length1;
		_tmp1_ = rsvg_handle_new_from_data (_tmp0_, _tmp0__length1, &_inner_error_);
		_tmp2_ = _tmp1_;
		if (_inner_error_ != NULL) {
			goto __catch9_g_error;
		}
		_g_object_unref0 (handle);
		handle = _tmp2_;
		_tmp3_ = handle;
		g_object_get (_tmp3_, "width", &_tmp4_, NULL);
		_tmp5_ = _tmp4_;
		_tmp6_ = handle;
		g_object_get (_tmp6_, "height", &_tmp7_, NULL);
		_tmp8_ = _tmp7_;
		_tmp9_ = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, _tmp5_, _tmp8_);
		_cairo_surface_destroy0 (surface);
		surface = _tmp9_;
		_tmp10_ = surface;
		_tmp11_ = cairo_create (_tmp10_);
		_cairo_destroy0 (context);
		context = _tmp11_;
		_tmp12_ = handle;
		_tmp13_ = context;
		rsvg_handle_render_cairo (_tmp12_, _tmp13_);
		_tmp14_ = surface;
		cairo_surface_write_to_png_stream (_tmp14_, _soy_sg_k2_png_converter_writefunc_cairo_write_func_t, self);
	}
	goto __finally9;
	__catch9_g_error:
	{
		GError* g = NULL;
		FILE* _tmp15_;
		GError* _tmp16_;
		const gchar* _tmp17_;
		g = _inner_error_;
		_inner_error_ = NULL;
		_tmp15_ = stdout;
		_tmp16_ = g;
		_tmp17_ = _tmp16_->message;
		fprintf (_tmp15_, "Error: %s\n", _tmp17_);
		_g_error_free0 (g);
		_cairo_destroy0 (context);
		_cairo_surface_destroy0 (surface);
		_g_object_unref0 (handle);
		return;
	}
	__finally9:
	if (_inner_error_ != NULL) {
		_cairo_destroy0 (context);
		_cairo_surface_destroy0 (surface);
		_g_object_unref0 (handle);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_cairo_destroy0 (context);
	_cairo_surface_destroy0 (surface);
	_g_object_unref0 (handle);
	return;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


guchar* soy_sg_k2_png_converter_get_png (soySGK2PNGConverter* self, int* result_length1) {
	guchar* result = NULL;
	GeeArrayList* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	guchar* _tmp3_ = NULL;
	guchar* data;
	gint data_length1;
	gint _data_size_;
	gint i;
	guchar* _tmp20_;
	gint _tmp20__length1;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_png_data;
	_tmp1_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = g_new0 (guchar, _tmp2_);
	data = _tmp3_;
	data_length1 = _tmp2_;
	_data_size_ = data_length1;
	i = 0;
	{
		GeeArrayList* _tmp4_;
		GeeArrayList* _tmp5_;
		GeeArrayList* _character_list;
		GeeArrayList* _tmp6_;
		gint _tmp7_;
		gint _tmp8_;
		gint _character_size;
		gint _character_index;
		_tmp4_ = self->priv->_png_data;
		_tmp5_ = _g_object_ref0 (_tmp4_);
		_character_list = _tmp5_;
		_tmp6_ = _character_list;
		_tmp7_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp6_);
		_tmp8_ = _tmp7_;
		_character_size = _tmp8_;
		_character_index = -1;
		while (TRUE) {
			gint _tmp9_;
			gint _tmp10_;
			gint _tmp11_;
			GeeArrayList* _tmp12_;
			gint _tmp13_;
			gpointer _tmp14_ = NULL;
			guchar character;
			guchar* _tmp15_;
			gint _tmp15__length1;
			gint _tmp16_;
			guchar _tmp17_;
			guchar _tmp18_;
			gint _tmp19_;
			_tmp9_ = _character_index;
			_character_index = _tmp9_ + 1;
			_tmp10_ = _character_index;
			_tmp11_ = _character_size;
			if (!(_tmp10_ < _tmp11_)) {
				break;
			}
			_tmp12_ = _character_list;
			_tmp13_ = _character_index;
			_tmp14_ = gee_abstract_list_get ((GeeAbstractList*) _tmp12_, _tmp13_);
			character = (guchar) ((guintptr) _tmp14_);
			_tmp15_ = data;
			_tmp15__length1 = data_length1;
			_tmp16_ = i;
			_tmp17_ = character;
			_tmp15_[_tmp16_] = _tmp17_;
			_tmp18_ = _tmp15_[_tmp16_];
			_tmp19_ = i;
			i = _tmp19_ + 1;
		}
		_g_object_unref0 (_character_list);
	}
	_tmp20_ = data;
	_tmp20__length1 = data_length1;
	if (result_length1) {
		*result_length1 = _tmp20__length1;
	}
	result = _tmp20_;
	return result;
}


cairo_status_t soy_sg_k2_png_converter_writefunc (soySGK2PNGConverter* self, guchar* input, int input_length1) {
	cairo_status_t result = 0;
	guchar* _tmp0_;
	gint _tmp0__length1;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = input;
	_tmp0__length1 = input_length1;
	{
		guchar* character_collection = NULL;
		gint character_collection_length1 = 0;
		gint _character_collection_size_ = 0;
		gint character_it = 0;
		character_collection = _tmp0_;
		character_collection_length1 = _tmp0__length1;
		for (character_it = 0; character_it < _tmp0__length1; character_it = character_it + 1) {
			guchar character = '\0';
			character = character_collection[character_it];
			{
				GeeArrayList* _tmp1_;
				guchar _tmp2_;
				_tmp1_ = self->priv->_png_data;
				_tmp2_ = character;
				gee_abstract_collection_add ((GeeAbstractCollection*) _tmp1_, (gpointer) ((guintptr) _tmp2_));
			}
		}
	}
	result = CAIRO_STATUS_SUCCESS;
	return result;
}


GeeArrayList* soy_sg_k2_png_converter_get_png_data (soySGK2PNGConverter* self) {
	GeeArrayList* result;
	GeeArrayList* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_png_data;
	result = _tmp0_;
	return result;
}


void soy_sg_k2_png_converter_set_png_data (soySGK2PNGConverter* self, GeeArrayList* value) {
	GeeArrayList* _tmp0_;
	GeeArrayList* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_png_data);
	self->priv->_png_data = _tmp1_;
}


static void soy_value_sg_k2_png_converter_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void soy_value_sg_k2_png_converter_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		soy_sg_k2_png_converter_unref (value->data[0].v_pointer);
	}
}


static void soy_value_sg_k2_png_converter_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = soy_sg_k2_png_converter_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer soy_value_sg_k2_png_converter_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* soy_value_sg_k2_png_converter_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		soySGK2PNGConverter* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = soy_sg_k2_png_converter_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* soy_value_sg_k2_png_converter_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	soySGK2PNGConverter** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = soy_sg_k2_png_converter_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* soy_param_spec_sg_k2_png_converter (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	soyParamSpecSGK2PNGConverter* spec;
	g_return_val_if_fail (g_type_is_a (object_type, SOY_TYPE_SG_K2_PNG_CONVERTER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer soy_value_get_sg_k2_png_converter (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SOY_TYPE_SG_K2_PNG_CONVERTER), NULL);
	return value->data[0].v_pointer;
}


void soy_value_set_sg_k2_png_converter (GValue* value, gpointer v_object) {
	soySGK2PNGConverter* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SOY_TYPE_SG_K2_PNG_CONVERTER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SOY_TYPE_SG_K2_PNG_CONVERTER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		soy_sg_k2_png_converter_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		soy_sg_k2_png_converter_unref (old);
	}
}


void soy_value_take_sg_k2_png_converter (GValue* value, gpointer v_object) {
	soySGK2PNGConverter* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SOY_TYPE_SG_K2_PNG_CONVERTER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SOY_TYPE_SG_K2_PNG_CONVERTER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		soy_sg_k2_png_converter_unref (old);
	}
}


static void soy_sg_k2_png_converter_class_init (soySGK2PNGConverterClass * klass) {
	soy_sg_k2_png_converter_parent_class = g_type_class_peek_parent (klass);
	SOY_SG_K2_PNG_CONVERTER_CLASS (klass)->finalize = soy_sg_k2_png_converter_finalize;
	g_type_class_add_private (klass, sizeof (soySGK2PNGConverterPrivate));
}


static void soy_sg_k2_png_converter_instance_init (soySGK2PNGConverter * self) {
	self->priv = SOY_SG_K2_PNG_CONVERTER_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void soy_sg_k2_png_converter_finalize (soySGK2PNGConverter* obj) {
	soySGK2PNGConverter * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_TYPE_SG_K2_PNG_CONVERTER, soySGK2PNGConverter);
	_g_object_unref0 (self->priv->_png_data);
}


GType soy_sg_k2_png_converter_get_type (void) {
	static volatile gsize soy_sg_k2_png_converter_type_id__volatile = 0;
	if (g_once_init_enter (&soy_sg_k2_png_converter_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { soy_value_sg_k2_png_converter_init, soy_value_sg_k2_png_converter_free_value, soy_value_sg_k2_png_converter_copy_value, soy_value_sg_k2_png_converter_peek_pointer, "p", soy_value_sg_k2_png_converter_collect_value, "p", soy_value_sg_k2_png_converter_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (soySGK2PNGConverterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_sg_k2_png_converter_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soySGK2PNGConverter), 0, (GInstanceInitFunc) soy_sg_k2_png_converter_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType soy_sg_k2_png_converter_type_id;
		soy_sg_k2_png_converter_type_id = g_type_register_fundamental (g_type_fundamental_next (), "soySGK2PNGConverter", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&soy_sg_k2_png_converter_type_id__volatile, soy_sg_k2_png_converter_type_id);
	}
	return soy_sg_k2_png_converter_type_id__volatile;
}


gpointer soy_sg_k2_png_converter_ref (gpointer instance) {
	soySGK2PNGConverter* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void soy_sg_k2_png_converter_unref (gpointer instance) {
	soySGK2PNGConverter* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		SOY_SG_K2_PNG_CONVERTER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



