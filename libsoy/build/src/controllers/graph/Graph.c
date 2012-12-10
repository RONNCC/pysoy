/* Graph.c generated by valac 0.18.1, the Vala compiler
 * generated from Graph.gs, do not modify */

/*
 *  libsoy - soy.controllers.graph.Grid
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
#include <float.h>
#include <math.h>
#include <gobject/gvaluecollector.h>


#define SOY_CONTROLLERS_GRAPH_TYPE_INODE (soy_controllers_graph_inode_get_type ())
#define SOY_CONTROLLERS_GRAPH_INODE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_CONTROLLERS_GRAPH_TYPE_INODE, soycontrollersgraphINode))
#define SOY_CONTROLLERS_GRAPH_IS_INODE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_CONTROLLERS_GRAPH_TYPE_INODE))
#define SOY_CONTROLLERS_GRAPH_INODE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SOY_CONTROLLERS_GRAPH_TYPE_INODE, soycontrollersgraphINodeIface))

typedef struct _soycontrollersgraphINode soycontrollersgraphINode;
typedef struct _soycontrollersgraphINodeIface soycontrollersgraphINodeIface;

#define SOY_CONTROLLERS_GRAPH_TYPE_EDGE (soy_controllers_graph_edge_get_type ())
#define SOY_CONTROLLERS_GRAPH_EDGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_CONTROLLERS_GRAPH_TYPE_EDGE, soycontrollersgraphEdge))
#define SOY_CONTROLLERS_GRAPH_EDGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_CONTROLLERS_GRAPH_TYPE_EDGE, soycontrollersgraphEdgeClass))
#define SOY_CONTROLLERS_GRAPH_IS_EDGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_CONTROLLERS_GRAPH_TYPE_EDGE))
#define SOY_CONTROLLERS_GRAPH_IS_EDGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_CONTROLLERS_GRAPH_TYPE_EDGE))
#define SOY_CONTROLLERS_GRAPH_EDGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_CONTROLLERS_GRAPH_TYPE_EDGE, soycontrollersgraphEdgeClass))

typedef struct _soycontrollersgraphEdge soycontrollersgraphEdge;
typedef struct _soycontrollersgraphEdgeClass soycontrollersgraphEdgeClass;

#define SOY_ATOMS_TYPE_POSITION (soy_atoms_position_get_type ())
#define SOY_ATOMS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPosition))
#define SOY_ATOMS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))
#define SOY_ATOMS_IS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_IS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_POSITION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))

typedef struct _soyatomsPosition soyatomsPosition;
typedef struct _soyatomsPositionClass soyatomsPositionClass;
typedef struct _soycontrollersgraphEdgePrivate soycontrollersgraphEdgePrivate;
typedef struct _soycontrollersgraphParamSpecEdge soycontrollersgraphParamSpecEdge;

#define SOY_CONTROLLERS_GRAPH_TYPE_IGRAPH (soy_controllers_graph_igraph_get_type ())
#define SOY_CONTROLLERS_GRAPH_IGRAPH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_CONTROLLERS_GRAPH_TYPE_IGRAPH, soycontrollersgraphIGraph))
#define SOY_CONTROLLERS_GRAPH_IS_IGRAPH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_CONTROLLERS_GRAPH_TYPE_IGRAPH))
#define SOY_CONTROLLERS_GRAPH_IGRAPH_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SOY_CONTROLLERS_GRAPH_TYPE_IGRAPH, soycontrollersgraphIGraphIface))

typedef struct _soycontrollersgraphIGraph soycontrollersgraphIGraph;
typedef struct _soycontrollersgraphIGraphIface soycontrollersgraphIGraphIface;

struct _soycontrollersgraphINodeIface {
	GTypeInterface parent_iface;
	GeeList* (*get_edges) (soycontrollersgraphINode* self);
	soyatomsPosition* (*get_position) (soycontrollersgraphINode* self);
};

struct _soycontrollersgraphEdge {
	GTypeInstance parent_instance;
	volatile int ref_count;
	soycontrollersgraphEdgePrivate * priv;
	gfloat distance;
	gfloat total_cost;
	soycontrollersgraphINode* begin;
	soycontrollersgraphINode* end;
};

struct _soycontrollersgraphEdgeClass {
	GTypeClass parent_class;
	void (*finalize) (soycontrollersgraphEdge *self);
};

struct _soycontrollersgraphParamSpecEdge {
	GParamSpec parent_instance;
};

struct _soycontrollersgraphIGraphIface {
	GTypeInterface parent_iface;
	soycontrollersgraphINode* (*get_node) (soycontrollersgraphIGraph* self, soyatomsPosition* pos);
	soycontrollersgraphINode* (*add_terminal_node) (soycontrollersgraphIGraph* self, soyatomsPosition* pos);
	gboolean* (*check_collisions) (soycontrollersgraphIGraph* self, soyatomsPosition* start, soyatomsPosition** ends, int ends_length1, int* result_length1);
};


static gpointer soy_controllers_graph_edge_parent_class = NULL;

gpointer soy_controllers_graph_edge_ref (gpointer instance);
void soy_controllers_graph_edge_unref (gpointer instance);
GParamSpec* soy_controllers_graph_param_spec_edge (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void soy_controllers_graph_value_set_edge (GValue* value, gpointer v_object);
void soy_controllers_graph_value_take_edge (GValue* value, gpointer v_object);
gpointer soy_controllers_graph_value_get_edge (const GValue* value);
GType soy_controllers_graph_edge_get_type (void) G_GNUC_CONST;
GType soy_atoms_position_get_type (void) G_GNUC_CONST;
GType soy_controllers_graph_inode_get_type (void) G_GNUC_CONST;
GeeList* soy_controllers_graph_inode_get_edges (soycontrollersgraphINode* self);
soyatomsPosition* soy_controllers_graph_inode_get_position (soycontrollersgraphINode* self);
enum  {
	SOY_CONTROLLERS_GRAPH_EDGE_DUMMY_PROPERTY
};
soycontrollersgraphEdge* soy_controllers_graph_edge_new (gfloat dist, soycontrollersgraphINode* begin, soycontrollersgraphINode* end);
soycontrollersgraphEdge* soy_controllers_graph_edge_construct (GType object_type, gfloat dist, soycontrollersgraphINode* begin, soycontrollersgraphINode* end);
static void soy_controllers_graph_edge_finalize (soycontrollersgraphEdge* obj);
GType soy_controllers_graph_igraph_get_type (void) G_GNUC_CONST;
soycontrollersgraphINode* soy_controllers_graph_igraph_get_node (soycontrollersgraphIGraph* self, soyatomsPosition* pos);
soycontrollersgraphINode* soy_controllers_graph_igraph_add_terminal_node (soycontrollersgraphIGraph* self, soyatomsPosition* pos);
gboolean* soy_controllers_graph_igraph_check_collisions (soycontrollersgraphIGraph* self, soyatomsPosition* start, soyatomsPosition** ends, int ends_length1, int* result_length1);


GeeList* soy_controllers_graph_inode_get_edges (soycontrollersgraphINode* self) {
	g_return_val_if_fail (self != NULL, NULL);
	return SOY_CONTROLLERS_GRAPH_INODE_GET_INTERFACE (self)->get_edges (self);
}


soyatomsPosition* soy_controllers_graph_inode_get_position (soycontrollersgraphINode* self) {
	g_return_val_if_fail (self != NULL, NULL);
	return SOY_CONTROLLERS_GRAPH_INODE_GET_INTERFACE (self)->get_position (self);
}


static void soy_controllers_graph_inode_base_init (soycontrollersgraphINodeIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
		g_object_interface_install_property (iface, g_param_spec_object ("position", "position", "position", SOY_ATOMS_TYPE_POSITION, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	}
}


GType soy_controllers_graph_inode_get_type (void) {
	static volatile gsize soy_controllers_graph_inode_type_id__volatile = 0;
	if (g_once_init_enter (&soy_controllers_graph_inode_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soycontrollersgraphINodeIface), (GBaseInitFunc) soy_controllers_graph_inode_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType soy_controllers_graph_inode_type_id;
		soy_controllers_graph_inode_type_id = g_type_register_static (G_TYPE_INTERFACE, "soycontrollersgraphINode", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (soy_controllers_graph_inode_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&soy_controllers_graph_inode_type_id__volatile, soy_controllers_graph_inode_type_id);
	}
	return soy_controllers_graph_inode_type_id__volatile;
}


soycontrollersgraphEdge* soy_controllers_graph_edge_construct (GType object_type, gfloat dist, soycontrollersgraphINode* begin, soycontrollersgraphINode* end) {
	soycontrollersgraphEdge* self = NULL;
	gfloat _tmp0_;
	soycontrollersgraphINode* _tmp1_;
	soycontrollersgraphINode* _tmp2_;
	g_return_val_if_fail (begin != NULL, NULL);
	g_return_val_if_fail (end != NULL, NULL);
	self = (soycontrollersgraphEdge*) g_type_create_instance (object_type);
	_tmp0_ = dist;
	self->distance = _tmp0_;
	_tmp1_ = begin;
	self->begin = _tmp1_;
	_tmp2_ = end;
	self->end = _tmp2_;
	return self;
}


soycontrollersgraphEdge* soy_controllers_graph_edge_new (gfloat dist, soycontrollersgraphINode* begin, soycontrollersgraphINode* end) {
	return soy_controllers_graph_edge_construct (SOY_CONTROLLERS_GRAPH_TYPE_EDGE, dist, begin, end);
}


static void soy_controllers_graph_value_edge_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void soy_controllers_graph_value_edge_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		soy_controllers_graph_edge_unref (value->data[0].v_pointer);
	}
}


static void soy_controllers_graph_value_edge_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = soy_controllers_graph_edge_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer soy_controllers_graph_value_edge_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* soy_controllers_graph_value_edge_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		soycontrollersgraphEdge* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = soy_controllers_graph_edge_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* soy_controllers_graph_value_edge_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	soycontrollersgraphEdge** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = soy_controllers_graph_edge_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* soy_controllers_graph_param_spec_edge (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	soycontrollersgraphParamSpecEdge* spec;
	g_return_val_if_fail (g_type_is_a (object_type, SOY_CONTROLLERS_GRAPH_TYPE_EDGE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer soy_controllers_graph_value_get_edge (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SOY_CONTROLLERS_GRAPH_TYPE_EDGE), NULL);
	return value->data[0].v_pointer;
}


void soy_controllers_graph_value_set_edge (GValue* value, gpointer v_object) {
	soycontrollersgraphEdge* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SOY_CONTROLLERS_GRAPH_TYPE_EDGE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SOY_CONTROLLERS_GRAPH_TYPE_EDGE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		soy_controllers_graph_edge_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		soy_controllers_graph_edge_unref (old);
	}
}


void soy_controllers_graph_value_take_edge (GValue* value, gpointer v_object) {
	soycontrollersgraphEdge* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SOY_CONTROLLERS_GRAPH_TYPE_EDGE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SOY_CONTROLLERS_GRAPH_TYPE_EDGE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		soy_controllers_graph_edge_unref (old);
	}
}


static void soy_controllers_graph_edge_class_init (soycontrollersgraphEdgeClass * klass) {
	soy_controllers_graph_edge_parent_class = g_type_class_peek_parent (klass);
	SOY_CONTROLLERS_GRAPH_EDGE_CLASS (klass)->finalize = soy_controllers_graph_edge_finalize;
}


static void soy_controllers_graph_edge_instance_init (soycontrollersgraphEdge * self) {
	self->total_cost = (gfloat) 0;
	self->ref_count = 1;
}


static void soy_controllers_graph_edge_finalize (soycontrollersgraphEdge* obj) {
	soycontrollersgraphEdge * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_CONTROLLERS_GRAPH_TYPE_EDGE, soycontrollersgraphEdge);
}


GType soy_controllers_graph_edge_get_type (void) {
	static volatile gsize soy_controllers_graph_edge_type_id__volatile = 0;
	if (g_once_init_enter (&soy_controllers_graph_edge_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { soy_controllers_graph_value_edge_init, soy_controllers_graph_value_edge_free_value, soy_controllers_graph_value_edge_copy_value, soy_controllers_graph_value_edge_peek_pointer, "p", soy_controllers_graph_value_edge_collect_value, "p", soy_controllers_graph_value_edge_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (soycontrollersgraphEdgeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_controllers_graph_edge_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soycontrollersgraphEdge), 0, (GInstanceInitFunc) soy_controllers_graph_edge_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType soy_controllers_graph_edge_type_id;
		soy_controllers_graph_edge_type_id = g_type_register_fundamental (g_type_fundamental_next (), "soycontrollersgraphEdge", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&soy_controllers_graph_edge_type_id__volatile, soy_controllers_graph_edge_type_id);
	}
	return soy_controllers_graph_edge_type_id__volatile;
}


gpointer soy_controllers_graph_edge_ref (gpointer instance) {
	soycontrollersgraphEdge* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void soy_controllers_graph_edge_unref (gpointer instance) {
	soycontrollersgraphEdge* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		SOY_CONTROLLERS_GRAPH_EDGE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


soycontrollersgraphINode* soy_controllers_graph_igraph_get_node (soycontrollersgraphIGraph* self, soyatomsPosition* pos) {
	g_return_val_if_fail (self != NULL, NULL);
	return SOY_CONTROLLERS_GRAPH_IGRAPH_GET_INTERFACE (self)->get_node (self, pos);
}


soycontrollersgraphINode* soy_controllers_graph_igraph_add_terminal_node (soycontrollersgraphIGraph* self, soyatomsPosition* pos) {
	g_return_val_if_fail (self != NULL, NULL);
	return SOY_CONTROLLERS_GRAPH_IGRAPH_GET_INTERFACE (self)->add_terminal_node (self, pos);
}


gboolean* soy_controllers_graph_igraph_check_collisions (soycontrollersgraphIGraph* self, soyatomsPosition* start, soyatomsPosition** ends, int ends_length1, int* result_length1) {
	g_return_val_if_fail (self != NULL, NULL);
	return SOY_CONTROLLERS_GRAPH_IGRAPH_GET_INTERFACE (self)->check_collisions (self, start, ends, ends_length1, result_length1);
}


static void soy_controllers_graph_igraph_base_init (soycontrollersgraphIGraphIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


GType soy_controllers_graph_igraph_get_type (void) {
	static volatile gsize soy_controllers_graph_igraph_type_id__volatile = 0;
	if (g_once_init_enter (&soy_controllers_graph_igraph_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soycontrollersgraphIGraphIface), (GBaseInitFunc) soy_controllers_graph_igraph_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType soy_controllers_graph_igraph_type_id;
		soy_controllers_graph_igraph_type_id = g_type_register_static (G_TYPE_INTERFACE, "soycontrollersgraphIGraph", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (soy_controllers_graph_igraph_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&soy_controllers_graph_igraph_type_id__volatile, soy_controllers_graph_igraph_type_id);
	}
	return soy_controllers_graph_igraph_type_id__volatile;
}



