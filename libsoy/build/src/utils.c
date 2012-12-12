/* utils.c generated by valac 0.18.1, the Vala compiler
 * generated from utils.gs, do not modify */

/*
 *  libsoy - soy utils
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
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define SOY_TYPE_EVENT_TYPE (soy_event_type_get_type ())

#define SOY_TYPE_SCROLL_DIRECTION (soy_scroll_direction_get_type ())

#define SOY_TYPE_COMPARISON (soy_comparison_get_type ())

#define SOY_TYPE_MATH_OPERATOR (soy_math_operator_get_type ())

#define SOY_TYPE_ITERATOR_WRAPPER (soy_iterator_wrapper_get_type ())
#define SOY_ITERATOR_WRAPPER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_TYPE_ITERATOR_WRAPPER, soyIteratorWrapper))
#define SOY_ITERATOR_WRAPPER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_TYPE_ITERATOR_WRAPPER, soyIteratorWrapperClass))
#define SOY_IS_ITERATOR_WRAPPER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_TYPE_ITERATOR_WRAPPER))
#define SOY_IS_ITERATOR_WRAPPER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_TYPE_ITERATOR_WRAPPER))
#define SOY_ITERATOR_WRAPPER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_TYPE_ITERATOR_WRAPPER, soyIteratorWrapperClass))

typedef struct _soyIteratorWrapper soyIteratorWrapper;
typedef struct _soyIteratorWrapperClass soyIteratorWrapperClass;
typedef struct _soyIteratorWrapperPrivate soyIteratorWrapperPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

typedef enum  {
	SOY_EVENT_TYPE_KeyPress,
	SOY_EVENT_TYPE_KeyDown,
	SOY_EVENT_TYPE_KeyRelease,
	SOY_EVENT_TYPE_Motion,
	SOY_EVENT_TYPE_ButtonPress,
	SOY_EVENT_TYPE_ButtonRelease,
	SOY_EVENT_TYPE_Scroll,
	SOY_EVENT_TYPE_WiimoteButtonPress
} soyEventType;

typedef enum  {
	SOY_SCROLL_DIRECTION_Up,
	SOY_SCROLL_DIRECTION_Down,
	SOY_SCROLL_DIRECTION_Left,
	SOY_SCROLL_DIRECTION_Right
} soyScrollDirection;

typedef enum  {
	SOY_COMPARISON_LT,
	SOY_COMPARISON_LE,
	SOY_COMPARISON_NE,
	SOY_COMPARISON_EQ,
	SOY_COMPARISON_GT,
	SOY_COMPARISON_GE
} soyComparison;

typedef enum  {
	SOY_MATH_OPERATOR_ADD,
	SOY_MATH_OPERATOR_SUB,
	SOY_MATH_OPERATOR_MUL,
	SOY_MATH_OPERATOR_DIV,
	SOY_MATH_OPERATOR_MOD,
	SOY_MATH_OPERATOR_OR,
	SOY_MATH_OPERATOR_AND
} soyMathOperator;

struct _soyIteratorWrapper {
	GObject parent_instance;
	soyIteratorWrapperPrivate * priv;
};

struct _soyIteratorWrapperClass {
	GObjectClass parent_class;
};

struct _soyIteratorWrapperPrivate {
	GType g_type;
	GBoxedCopyFunc g_dup_func;
	GDestroyNotify g_destroy_func;
	GeeIterator* _iter;
};


static gpointer soy_iterator_wrapper_parent_class = NULL;
static GeeIterableIface* soy_iterator_wrapper_gee_iterable_parent_iface = NULL;

GType soy_event_type_get_type (void) G_GNUC_CONST;
GType soy_scroll_direction_get_type (void) G_GNUC_CONST;
GType soy_comparison_get_type (void) G_GNUC_CONST;
GType soy_math_operator_get_type (void) G_GNUC_CONST;
gchar* soy_keyval_name (guint keyval);
GType soy_iterator_wrapper_get_type (void) G_GNUC_CONST;
#define SOY_ITERATOR_WRAPPER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_TYPE_ITERATOR_WRAPPER, soyIteratorWrapperPrivate))
enum  {
	SOY_ITERATOR_WRAPPER_DUMMY_PROPERTY,
	SOY_ITERATOR_WRAPPER_G_TYPE,
	SOY_ITERATOR_WRAPPER_G_DUP_FUNC,
	SOY_ITERATOR_WRAPPER_G_DESTROY_FUNC,
	SOY_ITERATOR_WRAPPER_ELEMENT_TYPE
};
soyIteratorWrapper* soy_iterator_wrapper_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GeeIterator* iter);
soyIteratorWrapper* soy_iterator_wrapper_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GeeIterator* iter);
static GeeIterator* soy_iterator_wrapper_real_iterator (GeeIterable* base);
static void soy_iterator_wrapper_finalize (GObject* obj);
static void _vala_soy_iterator_wrapper_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_soy_iterator_wrapper_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


GType soy_event_type_get_type (void) {
	static volatile gsize soy_event_type_type_id__volatile = 0;
	if (g_once_init_enter (&soy_event_type_type_id__volatile)) {
		static const GEnumValue values[] = {{SOY_EVENT_TYPE_KeyPress, "SOY_EVENT_TYPE_KeyPress", "keypress"}, {SOY_EVENT_TYPE_KeyDown, "SOY_EVENT_TYPE_KeyDown", "keydown"}, {SOY_EVENT_TYPE_KeyRelease, "SOY_EVENT_TYPE_KeyRelease", "keyrelease"}, {SOY_EVENT_TYPE_Motion, "SOY_EVENT_TYPE_Motion", "motion"}, {SOY_EVENT_TYPE_ButtonPress, "SOY_EVENT_TYPE_ButtonPress", "buttonpress"}, {SOY_EVENT_TYPE_ButtonRelease, "SOY_EVENT_TYPE_ButtonRelease", "buttonrelease"}, {SOY_EVENT_TYPE_Scroll, "SOY_EVENT_TYPE_Scroll", "scroll"}, {SOY_EVENT_TYPE_WiimoteButtonPress, "SOY_EVENT_TYPE_WiimoteButtonPress", "wiimotebuttonpress"}, {0, NULL, NULL}};
		GType soy_event_type_type_id;
		soy_event_type_type_id = g_enum_register_static ("soyEventType", values);
		g_once_init_leave (&soy_event_type_type_id__volatile, soy_event_type_type_id);
	}
	return soy_event_type_type_id__volatile;
}


GType soy_scroll_direction_get_type (void) {
	static volatile gsize soy_scroll_direction_type_id__volatile = 0;
	if (g_once_init_enter (&soy_scroll_direction_type_id__volatile)) {
		static const GEnumValue values[] = {{SOY_SCROLL_DIRECTION_Up, "SOY_SCROLL_DIRECTION_Up", "up"}, {SOY_SCROLL_DIRECTION_Down, "SOY_SCROLL_DIRECTION_Down", "down"}, {SOY_SCROLL_DIRECTION_Left, "SOY_SCROLL_DIRECTION_Left", "left"}, {SOY_SCROLL_DIRECTION_Right, "SOY_SCROLL_DIRECTION_Right", "right"}, {0, NULL, NULL}};
		GType soy_scroll_direction_type_id;
		soy_scroll_direction_type_id = g_enum_register_static ("soyScrollDirection", values);
		g_once_init_leave (&soy_scroll_direction_type_id__volatile, soy_scroll_direction_type_id);
	}
	return soy_scroll_direction_type_id__volatile;
}


GType soy_comparison_get_type (void) {
	static volatile gsize soy_comparison_type_id__volatile = 0;
	if (g_once_init_enter (&soy_comparison_type_id__volatile)) {
		static const GEnumValue values[] = {{SOY_COMPARISON_LT, "SOY_COMPARISON_LT", "lt"}, {SOY_COMPARISON_LE, "SOY_COMPARISON_LE", "le"}, {SOY_COMPARISON_NE, "SOY_COMPARISON_NE", "ne"}, {SOY_COMPARISON_EQ, "SOY_COMPARISON_EQ", "eq"}, {SOY_COMPARISON_GT, "SOY_COMPARISON_GT", "gt"}, {SOY_COMPARISON_GE, "SOY_COMPARISON_GE", "ge"}, {0, NULL, NULL}};
		GType soy_comparison_type_id;
		soy_comparison_type_id = g_enum_register_static ("soyComparison", values);
		g_once_init_leave (&soy_comparison_type_id__volatile, soy_comparison_type_id);
	}
	return soy_comparison_type_id__volatile;
}


GType soy_math_operator_get_type (void) {
	static volatile gsize soy_math_operator_type_id__volatile = 0;
	if (g_once_init_enter (&soy_math_operator_type_id__volatile)) {
		static const GEnumValue values[] = {{SOY_MATH_OPERATOR_ADD, "SOY_MATH_OPERATOR_ADD", "add"}, {SOY_MATH_OPERATOR_SUB, "SOY_MATH_OPERATOR_SUB", "sub"}, {SOY_MATH_OPERATOR_MUL, "SOY_MATH_OPERATOR_MUL", "mul"}, {SOY_MATH_OPERATOR_DIV, "SOY_MATH_OPERATOR_DIV", "div"}, {SOY_MATH_OPERATOR_MOD, "SOY_MATH_OPERATOR_MOD", "mod"}, {SOY_MATH_OPERATOR_OR, "SOY_MATH_OPERATOR_OR", "or"}, {SOY_MATH_OPERATOR_AND, "SOY_MATH_OPERATOR_AND", "and"}, {0, NULL, NULL}};
		GType soy_math_operator_type_id;
		soy_math_operator_type_id = g_enum_register_static ("soyMathOperator", values);
		g_once_init_leave (&soy_math_operator_type_id__volatile, soy_math_operator_type_id);
	}
	return soy_math_operator_type_id__volatile;
}


gchar* soy_keyval_name (guint keyval) {
	gchar* result = NULL;
	gchar* _tmp0_;
	_tmp0_ = g_strdup ("");
	result = _tmp0_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


soyIteratorWrapper* soy_iterator_wrapper_construct (GType object_type, GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GeeIterator* iter) {
	soyIteratorWrapper * self = NULL;
	GeeIterator* _tmp0_;
	GeeIterator* _tmp1_;
	g_return_val_if_fail (iter != NULL, NULL);
	self = (soyIteratorWrapper*) g_object_new (object_type, NULL);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	_tmp0_ = iter;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_iter);
	self->priv->_iter = _tmp1_;
	return self;
}


soyIteratorWrapper* soy_iterator_wrapper_new (GType g_type, GBoxedCopyFunc g_dup_func, GDestroyNotify g_destroy_func, GeeIterator* iter) {
	return soy_iterator_wrapper_construct (SOY_TYPE_ITERATOR_WRAPPER, g_type, g_dup_func, g_destroy_func, iter);
}


static GeeIterator* soy_iterator_wrapper_real_iterator (GeeIterable* base) {
	soyIteratorWrapper * self;
	GeeIterator* result = NULL;
	GeeIterator* _tmp0_;
	GeeIterator* _tmp1_;
	self = (soyIteratorWrapper*) base;
	_tmp0_ = self->priv->_iter;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	result = _tmp1_;
	return result;
}


static GType soy_iterator_wrapper_real_get_element_type (GeeIterable* base) {
	GType result;
	soyIteratorWrapper* self;
	self = (soyIteratorWrapper*) base;
	result = self->priv->g_type;
	return result;
}


static void soy_iterator_wrapper_class_init (soyIteratorWrapperClass * klass) {
	soy_iterator_wrapper_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (soyIteratorWrapperPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_soy_iterator_wrapper_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_soy_iterator_wrapper_set_property;
	G_OBJECT_CLASS (klass)->finalize = soy_iterator_wrapper_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_ITERATOR_WRAPPER_G_TYPE, g_param_spec_gtype ("g-type", "type", "type", G_TYPE_NONE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_ITERATOR_WRAPPER_G_DUP_FUNC, g_param_spec_pointer ("g-dup-func", "dup func", "dup func", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_ITERATOR_WRAPPER_G_DESTROY_FUNC, g_param_spec_pointer ("g-destroy-func", "destroy func", "destroy func", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_ITERATOR_WRAPPER_ELEMENT_TYPE, g_param_spec_gtype ("element-type", "element-type", "element-type", G_TYPE_NONE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void soy_iterator_wrapper_gee_iterable_interface_init (GeeIterableIface * iface) {
	soy_iterator_wrapper_gee_iterable_parent_iface = g_type_interface_peek_parent (iface);
	iface->iterator = (GeeIterator* (*)(GeeIterable*)) soy_iterator_wrapper_real_iterator;
	iface->get_element_type = soy_iterator_wrapper_real_get_element_type;
}


static void soy_iterator_wrapper_instance_init (soyIteratorWrapper * self) {
	self->priv = SOY_ITERATOR_WRAPPER_GET_PRIVATE (self);
}


static void soy_iterator_wrapper_finalize (GObject* obj) {
	soyIteratorWrapper * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_TYPE_ITERATOR_WRAPPER, soyIteratorWrapper);
	_g_object_unref0 (self->priv->_iter);
	G_OBJECT_CLASS (soy_iterator_wrapper_parent_class)->finalize (obj);
}


GType soy_iterator_wrapper_get_type (void) {
	static volatile gsize soy_iterator_wrapper_type_id__volatile = 0;
	if (g_once_init_enter (&soy_iterator_wrapper_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soyIteratorWrapperClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_iterator_wrapper_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soyIteratorWrapper), 0, (GInstanceInitFunc) soy_iterator_wrapper_instance_init, NULL };
		static const GInterfaceInfo gee_iterable_info = { (GInterfaceInitFunc) soy_iterator_wrapper_gee_iterable_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType soy_iterator_wrapper_type_id;
		soy_iterator_wrapper_type_id = g_type_register_static (G_TYPE_OBJECT, "soyIteratorWrapper", &g_define_type_info, 0);
		g_type_add_interface_static (soy_iterator_wrapper_type_id, GEE_TYPE_ITERABLE, &gee_iterable_info);
		g_once_init_leave (&soy_iterator_wrapper_type_id__volatile, soy_iterator_wrapper_type_id);
	}
	return soy_iterator_wrapper_type_id__volatile;
}


static void _vala_soy_iterator_wrapper_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	soyIteratorWrapper * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_TYPE_ITERATOR_WRAPPER, soyIteratorWrapper);
	switch (property_id) {
		case SOY_ITERATOR_WRAPPER_ELEMENT_TYPE:
		g_value_set_gtype (value, gee_iterable_get_element_type ((GeeIterable*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_soy_iterator_wrapper_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	soyIteratorWrapper * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_TYPE_ITERATOR_WRAPPER, soyIteratorWrapper);
	switch (property_id) {
		case SOY_ITERATOR_WRAPPER_G_TYPE:
		self->priv->g_type = g_value_get_gtype (value);
		break;
		case SOY_ITERATOR_WRAPPER_G_DUP_FUNC:
		self->priv->g_dup_func = g_value_get_pointer (value);
		break;
		case SOY_ITERATOR_WRAPPER_G_DESTROY_FUNC:
		self->priv->g_destroy_func = g_value_get_pointer (value);
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



