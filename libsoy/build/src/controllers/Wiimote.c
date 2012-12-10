/* Wiimote.c generated by valac 0.18.1, the Vala compiler
 * generated from Wiimote.gs, do not modify */

/*
 *  libsoy - soy.controllers.Wiimote
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


#define SOY_CONTROLLERS_TYPE_CONTROLLER (soy_controllers_controller_get_type ())
#define SOY_CONTROLLERS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_CONTROLLERS_TYPE_CONTROLLER, soycontrollersController))
#define SOY_CONTROLLERS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_CONTROLLERS_TYPE_CONTROLLER, soycontrollersControllerClass))
#define SOY_CONTROLLERS_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_CONTROLLERS_TYPE_CONTROLLER))
#define SOY_CONTROLLERS_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_CONTROLLERS_TYPE_CONTROLLER))
#define SOY_CONTROLLERS_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_CONTROLLERS_TYPE_CONTROLLER, soycontrollersControllerClass))

typedef struct _soycontrollersController soycontrollersController;
typedef struct _soycontrollersControllerClass soycontrollersControllerClass;
typedef struct _soycontrollersControllerPrivate soycontrollersControllerPrivate;

#define SOY_CONTROLLERS_TYPE_WIIMOTE (soy_controllers_wiimote_get_type ())
#define SOY_CONTROLLERS_WIIMOTE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_CONTROLLERS_TYPE_WIIMOTE, soycontrollersWiimote))
#define SOY_CONTROLLERS_WIIMOTE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_CONTROLLERS_TYPE_WIIMOTE, soycontrollersWiimoteClass))
#define SOY_CONTROLLERS_IS_WIIMOTE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_CONTROLLERS_TYPE_WIIMOTE))
#define SOY_CONTROLLERS_IS_WIIMOTE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_CONTROLLERS_TYPE_WIIMOTE))
#define SOY_CONTROLLERS_WIIMOTE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_CONTROLLERS_TYPE_WIIMOTE, soycontrollersWiimoteClass))

typedef struct _soycontrollersWiimote soycontrollersWiimote;
typedef struct _soycontrollersWiimoteClass soycontrollersWiimoteClass;
typedef struct _soycontrollersWiimotePrivate soycontrollersWiimotePrivate;

#define SOY_EVENTS_TYPE_WIIBUTTON (soy_events_wiibutton_get_type ())

#define SOY_TYPE_EVENT_TYPE (soy_event_type_get_type ())
typedef struct _soyeventsWiibutton soyeventsWiibutton;

struct _soycontrollersController {
	GObject parent_instance;
	soycontrollersControllerPrivate * priv;
};

struct _soycontrollersControllerClass {
	GObjectClass parent_class;
	gchar* (*tp_repr) (soycontrollersController* self);
};

struct _soycontrollersWiimote {
	soycontrollersController parent_instance;
	soycontrollersWiimotePrivate * priv;
};

struct _soycontrollersWiimoteClass {
	soycontrollersControllerClass parent_class;
};

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

struct _soyeventsWiibutton {
	soyEventType type;
	guint16 wiibutton;
};


static gpointer soy_controllers_wiimote_parent_class = NULL;

GType soy_controllers_controller_get_type (void) G_GNUC_CONST;
GType soy_controllers_wiimote_get_type (void) G_GNUC_CONST;
enum  {
	SOY_CONTROLLERS_WIIMOTE_DUMMY_PROPERTY
};
soycontrollersWiimote* soy_controllers_wiimote_new (void);
soycontrollersWiimote* soy_controllers_wiimote_construct (GType object_type);
soycontrollersController* soy_controllers_controller_new (void);
soycontrollersController* soy_controllers_controller_construct (GType object_type);
guint8 soy_controllers_wiimote_toggle_bit (soycontrollersWiimote* self, guint8 bf, guint8 b);
GType soy_events_wiibutton_get_type (void) G_GNUC_CONST;
GType soy_event_type_get_type (void) G_GNUC_CONST;
soyeventsWiibutton* soy_events_wiibutton_dup (const soyeventsWiibutton* self);
void soy_events_wiibutton_free (soyeventsWiibutton* self);
static void g_cclosure_user_marshal_VOID__BOXED (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);


soycontrollersWiimote* soy_controllers_wiimote_construct (GType object_type) {
	soycontrollersWiimote * self = NULL;
	self = (soycontrollersWiimote*) soy_controllers_controller_construct (object_type);
	return self;
}


soycontrollersWiimote* soy_controllers_wiimote_new (void) {
	return soy_controllers_wiimote_construct (SOY_CONTROLLERS_TYPE_WIIMOTE);
}


guint8 soy_controllers_wiimote_toggle_bit (soycontrollersWiimote* self, guint8 bf, guint8 b) {
	guint8 result = 0U;
	guint8 _tmp0_;
	guint8 _tmp1_;
	guint8 _tmp6_;
	g_return_val_if_fail (self != NULL, 0U);
	_tmp0_ = bf;
	_tmp1_ = b;
	if (((gint) (_tmp0_ & _tmp1_)) != 0) {
		guint8 _tmp2_;
		guint8 _tmp3_;
		_tmp2_ = bf;
		_tmp3_ = b;
		bf = _tmp2_ & (~_tmp3_);
	} else {
		guint8 _tmp4_;
		guint8 _tmp5_;
		_tmp4_ = bf;
		_tmp5_ = b;
		bf = _tmp4_ | _tmp5_;
	}
	_tmp6_ = bf;
	result = _tmp6_;
	return result;
}


static void g_cclosure_user_marshal_VOID__BOXED (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__BOXED) (gpointer data1, gpointer arg_1, gpointer data2);
	register GMarshalFunc_VOID__BOXED callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 2);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__BOXED) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_boxed (param_values + 1), data2);
}


static void soy_controllers_wiimote_class_init (soycontrollersWiimoteClass * klass) {
	soy_controllers_wiimote_parent_class = g_type_class_peek_parent (klass);
	g_signal_new ("wiimote_button_press", SOY_CONTROLLERS_TYPE_WIIMOTE, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__BOXED, G_TYPE_NONE, 1, SOY_EVENTS_TYPE_WIIBUTTON);
}


static void soy_controllers_wiimote_instance_init (soycontrollersWiimote * self) {
}


GType soy_controllers_wiimote_get_type (void) {
	static volatile gsize soy_controllers_wiimote_type_id__volatile = 0;
	if (g_once_init_enter (&soy_controllers_wiimote_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soycontrollersWiimoteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_controllers_wiimote_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soycontrollersWiimote), 0, (GInstanceInitFunc) soy_controllers_wiimote_instance_init, NULL };
		GType soy_controllers_wiimote_type_id;
		soy_controllers_wiimote_type_id = g_type_register_static (SOY_CONTROLLERS_TYPE_CONTROLLER, "soycontrollersWiimote", &g_define_type_info, 0);
		g_once_init_leave (&soy_controllers_wiimote_type_id__volatile, soy_controllers_wiimote_type_id);
	}
	return soy_controllers_wiimote_type_id__volatile;
}


