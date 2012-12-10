/* Branch.c generated by valac 0.18.1, the Vala compiler
 * generated from Branch.gs, do not modify */

/*
 *  libsoy - soy.widgets.Branch
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
#include <stdlib.h>
#include <string.h>
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <float.h>
#include <math.h>


#define SOY_WIDGETS_TYPE_WIDGET (soy_widgets_widget_get_type ())
#define SOY_WIDGETS_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_WIDGETS_TYPE_WIDGET, soywidgetsWidget))
#define SOY_WIDGETS_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_WIDGETS_TYPE_WIDGET, soywidgetsWidgetClass))
#define SOY_WIDGETS_IS_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_WIDGETS_TYPE_WIDGET))
#define SOY_WIDGETS_IS_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_WIDGETS_TYPE_WIDGET))
#define SOY_WIDGETS_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_WIDGETS_TYPE_WIDGET, soywidgetsWidgetClass))

typedef struct _soywidgetsWidget soywidgetsWidget;
typedef struct _soywidgetsWidgetClass soywidgetsWidgetClass;
typedef struct _soywidgetsWidgetPrivate soywidgetsWidgetPrivate;

#define SOY_WIDGETS_TYPE_CONTAINER (soy_widgets_container_get_type ())
#define SOY_WIDGETS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_WIDGETS_TYPE_CONTAINER, soywidgetsContainer))
#define SOY_WIDGETS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_WIDGETS_TYPE_CONTAINER, soywidgetsContainerClass))
#define SOY_WIDGETS_IS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_WIDGETS_TYPE_CONTAINER))
#define SOY_WIDGETS_IS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_WIDGETS_TYPE_CONTAINER))
#define SOY_WIDGETS_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_WIDGETS_TYPE_CONTAINER, soywidgetsContainerClass))

typedef struct _soywidgetsContainer soywidgetsContainer;
typedef struct _soywidgetsContainerClass soywidgetsContainerClass;
typedef struct _soywidgetsContainerPrivate soywidgetsContainerPrivate;

#define SOY_WIDGETS_TYPE_BRANCH (soy_widgets_branch_get_type ())
#define SOY_WIDGETS_BRANCH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_WIDGETS_TYPE_BRANCH, soywidgetsBranch))
#define SOY_WIDGETS_BRANCH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_WIDGETS_TYPE_BRANCH, soywidgetsBranchClass))
#define SOY_WIDGETS_IS_BRANCH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_WIDGETS_TYPE_BRANCH))
#define SOY_WIDGETS_IS_BRANCH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_WIDGETS_TYPE_BRANCH))
#define SOY_WIDGETS_BRANCH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_WIDGETS_TYPE_BRANCH, soywidgetsBranchClass))

typedef struct _soywidgetsBranch soywidgetsBranch;
typedef struct _soywidgetsBranchClass soywidgetsBranchClass;
typedef struct _soywidgetsBranchPrivate soywidgetsBranchPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _soywidgetsWidget {
	GObject parent_instance;
	soywidgetsWidgetPrivate * priv;
	gint width;
	gint height;
	gboolean resized;
};

struct _soywidgetsWidgetClass {
	GObjectClass parent_class;
	void (*render) (soywidgetsWidget* self, gint x, gint y, gint width, gint height);
	void (*resize) (soywidgetsWidget* self, gint x, gint y, gint width, gint height);
};

struct _soywidgetsContainer {
	soywidgetsWidget parent_instance;
	soywidgetsContainerPrivate * priv;
	GeeLinkedList* children;
};

struct _soywidgetsContainerClass {
	soywidgetsWidgetClass parent_class;
	void (*resize_children) (soywidgetsContainer* self, gint x, gint y, gint width, gint height);
};

struct _soywidgetsBranch {
	soywidgetsContainer parent_instance;
	soywidgetsBranchPrivate * priv;
	gchar* name;
	gboolean collapsed;
};

struct _soywidgetsBranchClass {
	soywidgetsContainerClass parent_class;
};

struct _soywidgetsBranchPrivate {
	GeeArrayList* _children;
	GLuint _vbuffer;
	GLuint _ibuffer;
	gint _branchHeight;
	gint _branchWidth;
	gint _branchPosX;
	gint _branchPosY;
	gint _indentLength;
	soywidgetsContainer* _parent;
	gboolean _shouldRender;
	gint _YDisp;
};


static gpointer soy_widgets_branch_parent_class = NULL;
static GLfloat* soy_widgets_branch__verts;
static gint soy_widgets_branch__verts_length1;
static GLfloat* soy_widgets_branch__verts = NULL;
static gint soy_widgets_branch__verts_length1 = 0;
static gint _soy_widgets_branch__verts_size_ = 0;
static GLushort* soy_widgets_branch__faces;
static gint soy_widgets_branch__faces_length1;
static GLushort* soy_widgets_branch__faces = NULL;
static gint soy_widgets_branch__faces_length1 = 0;
static gint _soy_widgets_branch__faces_size_ = 0;

GType soy_widgets_widget_get_type (void) G_GNUC_CONST;
GType soy_widgets_container_get_type (void) G_GNUC_CONST;
GType soy_widgets_branch_get_type (void) G_GNUC_CONST;
#define SOY_WIDGETS_BRANCH_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_WIDGETS_TYPE_BRANCH, soywidgetsBranchPrivate))
enum  {
	SOY_WIDGETS_BRANCH_DUMMY_PROPERTY
};
soywidgetsBranch* soy_widgets_branch_new (soywidgetsContainer* parent, const gchar* name);
soywidgetsBranch* soy_widgets_branch_construct (GType object_type, soywidgetsContainer* parent, const gchar* name);
soywidgetsContainer* soy_widgets_container_new (soywidgetsContainer* parent);
soywidgetsContainer* soy_widgets_container_construct (GType object_type, soywidgetsContainer* parent);
gfloat soy_widgets_branch_convertY (soywidgetsBranch* self, gfloat y);
void soy_widgets_branch_remove_branch (soywidgetsBranch* self, soywidgetsBranch* oldBranch);
void soy_widgets_branch_display (soywidgetsBranch* self);
static gint _soy_widgets_branch_calc_disp (soywidgetsBranch* self, gint rootY, gint y);
void soy_widgets_widget_render (soywidgetsWidget* self, gint x, gint y, gint width, gint height);
static void soy_widgets_branch_real_render (soywidgetsWidget* base, gint x, gint y, gint width, gint height);
static void soy_widgets_branch_finalize (GObject* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


soywidgetsBranch* soy_widgets_branch_construct (GType object_type, soywidgetsContainer* parent, const gchar* name) {
	soywidgetsBranch * self = NULL;
	soywidgetsContainer* _tmp0_;
	soywidgetsContainer* _tmp1_;
	soywidgetsContainer* _tmp2_;
	soywidgetsContainer* _tmp3_;
	const gchar* _tmp6_;
	gchar* _tmp7_;
	GeeArrayList* _tmp8_;
	gfloat _tmp9_ = 0.0F;
	_tmp0_ = parent;
	self = (soywidgetsBranch*) soy_widgets_container_construct (object_type, _tmp0_);
	_tmp1_ = parent;
	_tmp2_ = _g_object_ref0 (_tmp1_);
	_g_object_unref0 (self->priv->_parent);
	self->priv->_parent = _tmp2_;
	_tmp3_ = parent;
	if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp3_, SOY_WIDGETS_TYPE_BRANCH)) {
		soywidgetsContainer* _tmp4_;
		GeeArrayList* _tmp5_;
		_tmp4_ = parent;
		_tmp5_ = G_TYPE_CHECK_INSTANCE_CAST (_tmp4_, SOY_WIDGETS_TYPE_BRANCH, soywidgetsBranch)->priv->_children;
		gee_abstract_collection_add ((GeeAbstractCollection*) _tmp5_, self);
	}
	_tmp6_ = name;
	_tmp7_ = g_strdup (_tmp6_);
	_g_free0 (self->name);
	self->name = _tmp7_;
	_tmp8_ = gee_array_list_new (SOY_WIDGETS_TYPE_BRANCH, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL);
	_g_object_unref0 (self->priv->_children);
	self->priv->_children = _tmp8_;
	self->collapsed = FALSE;
	self->priv->_branchPosX = 0;
	_tmp9_ = soy_widgets_branch_convertY (self, 0.0f);
	self->priv->_branchPosY = (gint) _tmp9_;
	self->priv->_shouldRender = TRUE;
	return self;
}


soywidgetsBranch* soy_widgets_branch_new (soywidgetsContainer* parent, const gchar* name) {
	return soy_widgets_branch_construct (SOY_WIDGETS_TYPE_BRANCH, parent, name);
}


void soy_widgets_branch_remove_branch (soywidgetsBranch* self, soywidgetsBranch* oldBranch) {
	GeeArrayList* _tmp0_;
	soywidgetsBranch* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (oldBranch != NULL);
	_tmp0_ = self->priv->_children;
	_tmp1_ = oldBranch;
	gee_abstract_collection_remove ((GeeAbstractCollection*) _tmp0_, _tmp1_);
}


void soy_widgets_branch_display (soywidgetsBranch* self) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->collapsed;
	if (_tmp0_) {
		const gchar* _tmp1_;
		_tmp1_ = self->name;
		g_print ("+ %s\n", _tmp1_);
		return;
	} else {
		const gchar* _tmp2_;
		_tmp2_ = self->name;
		g_print ("- %s\n", _tmp2_);
		{
			GeeArrayList* _tmp3_;
			GeeArrayList* _tmp4_;
			GeeArrayList* _child_list;
			GeeArrayList* _tmp5_;
			gint _tmp6_;
			gint _tmp7_;
			gint _child_size;
			gint _child_index;
			_tmp3_ = self->priv->_children;
			_tmp4_ = _g_object_ref0 (_tmp3_);
			_child_list = _tmp4_;
			_tmp5_ = _child_list;
			_tmp6_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp5_);
			_tmp7_ = _tmp6_;
			_child_size = _tmp7_;
			_child_index = -1;
			while (TRUE) {
				gint _tmp8_;
				gint _tmp9_;
				gint _tmp10_;
				GeeArrayList* _tmp11_;
				gint _tmp12_;
				gpointer _tmp13_ = NULL;
				soywidgetsBranch* child;
				soywidgetsBranch* _tmp14_;
				_tmp8_ = _child_index;
				_child_index = _tmp8_ + 1;
				_tmp9_ = _child_index;
				_tmp10_ = _child_size;
				if (!(_tmp9_ < _tmp10_)) {
					break;
				}
				_tmp11_ = _child_list;
				_tmp12_ = _child_index;
				_tmp13_ = gee_abstract_list_get ((GeeAbstractList*) _tmp11_, _tmp12_);
				child = (soywidgetsBranch*) _tmp13_;
				_tmp14_ = child;
				soy_widgets_branch_display (_tmp14_);
				_g_object_unref0 (child);
			}
			_g_object_unref0 (_child_list);
		}
	}
}


gfloat soy_widgets_branch_convertY (soywidgetsBranch* self, gfloat y) {
	gfloat result = 0.0F;
	soywidgetsContainer* _tmp0_;
	gint _tmp1_;
	gfloat _tmp2_;
	gint _tmp3_;
	g_return_val_if_fail (self != NULL, 0.0F);
	_tmp0_ = self->priv->_parent;
	_tmp1_ = ((soywidgetsWidget*) _tmp0_)->height;
	_tmp2_ = y;
	_tmp3_ = self->priv->_branchHeight;
	result = (_tmp1_ - _tmp2_) - _tmp3_;
	return result;
}


static gint _soy_widgets_branch_calc_disp (soywidgetsBranch* self, gint rootY, gint y) {
	gint result = 0;
	gint _tmp0_;
	gint _tmp28_;
	gint _tmp29_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = y;
	self->priv->_YDisp = _tmp0_;
	{
		GeeArrayList* _tmp1_;
		GeeArrayList* _tmp2_;
		GeeArrayList* _child_list;
		GeeArrayList* _tmp3_;
		gint _tmp4_;
		gint _tmp5_;
		gint _child_size;
		gint _child_index;
		_tmp1_ = self->priv->_children;
		_tmp2_ = _g_object_ref0 (_tmp1_);
		_child_list = _tmp2_;
		_tmp3_ = _child_list;
		_tmp4_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp3_);
		_tmp5_ = _tmp4_;
		_child_size = _tmp5_;
		_child_index = -1;
		while (TRUE) {
			gint _tmp6_;
			gint _tmp7_;
			gint _tmp8_;
			GeeArrayList* _tmp9_;
			gint _tmp10_;
			gpointer _tmp11_ = NULL;
			soywidgetsBranch* child;
			soywidgetsBranch* _tmp12_;
			gint _tmp13_;
			gint _tmp14_;
			soywidgetsBranch* _tmp15_;
			gboolean _tmp16_;
			_tmp6_ = _child_index;
			_child_index = _tmp6_ + 1;
			_tmp7_ = _child_index;
			_tmp8_ = _child_size;
			if (!(_tmp7_ < _tmp8_)) {
				break;
			}
			_tmp9_ = _child_list;
			_tmp10_ = _child_index;
			_tmp11_ = gee_abstract_list_get ((GeeAbstractList*) _tmp9_, _tmp10_);
			child = (soywidgetsBranch*) _tmp11_;
			_tmp12_ = child;
			_tmp13_ = self->priv->_branchPosX;
			_tmp14_ = self->priv->_indentLength;
			_tmp12_->priv->_branchPosX = _tmp13_ + _tmp14_;
			_tmp15_ = child;
			_tmp16_ = _tmp15_->priv->_shouldRender;
			if (_tmp16_) {
				gint _tmp17_;
				gint _tmp18_;
				soywidgetsBranch* _tmp19_;
				gint _tmp20_;
				gint _tmp21_;
				gint _tmp22_;
				soywidgetsBranch* _tmp23_;
				gint _tmp24_;
				gint _tmp25_;
				gint _tmp26_ = 0;
				soywidgetsBranch* _tmp27_;
				_tmp17_ = self->priv->_YDisp;
				_tmp18_ = self->priv->_branchHeight;
				self->priv->_YDisp = _tmp17_ + (_tmp18_ + 5);
				_tmp19_ = child;
				_tmp20_ = rootY;
				_tmp21_ = self->priv->_YDisp;
				_tmp19_->priv->_branchPosY = _tmp20_ - _tmp21_;
				_tmp22_ = self->priv->_YDisp;
				_tmp23_ = child;
				_tmp24_ = rootY;
				_tmp25_ = self->priv->_YDisp;
				_tmp26_ = _soy_widgets_branch_calc_disp (_tmp23_, _tmp24_, _tmp25_);
				self->priv->_YDisp = _tmp22_ + _tmp26_;
				_tmp27_ = child;
				soy_widgets_widget_render ((soywidgetsWidget*) _tmp27_, 0, 0, 0, 0);
			}
			_g_object_unref0 (child);
		}
		_g_object_unref0 (_child_list);
	}
	_tmp28_ = self->priv->_YDisp;
	_tmp29_ = y;
	result = _tmp28_ - _tmp29_;
	return result;
}


static void soy_widgets_branch_real_render (soywidgetsWidget* base, gint x, gint y, gint width, gint height) {
	soywidgetsBranch * self;
	gboolean _tmp0_;
	gboolean _tmp25_;
	soywidgetsContainer* _tmp26_;
	soywidgetsContainer* _tmp27_;
	soywidgetsContainer* p;
	soywidgetsContainer* _tmp28_;
	GLfloat* _tmp30_ = NULL;
	GLushort* _tmp31_ = NULL;
	gboolean _tmp32_ = FALSE;
	GLuint _tmp33_;
	gboolean _tmp35_;
	gint _tmp44_;
	gint _tmp45_;
	gint _tmp46_;
	gint _tmp47_;
	self = (soywidgetsBranch*) base;
	_tmp0_ = self->collapsed;
	if (_tmp0_) {
		{
			GeeArrayList* _tmp1_;
			GeeArrayList* _tmp2_;
			GeeArrayList* _child_list;
			GeeArrayList* _tmp3_;
			gint _tmp4_;
			gint _tmp5_;
			gint _child_size;
			gint _child_index;
			_tmp1_ = self->priv->_children;
			_tmp2_ = _g_object_ref0 (_tmp1_);
			_child_list = _tmp2_;
			_tmp3_ = _child_list;
			_tmp4_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp3_);
			_tmp5_ = _tmp4_;
			_child_size = _tmp5_;
			_child_index = -1;
			while (TRUE) {
				gint _tmp6_;
				gint _tmp7_;
				gint _tmp8_;
				GeeArrayList* _tmp9_;
				gint _tmp10_;
				gpointer _tmp11_ = NULL;
				soywidgetsBranch* child;
				soywidgetsBranch* _tmp12_;
				_tmp6_ = _child_index;
				_child_index = _tmp6_ + 1;
				_tmp7_ = _child_index;
				_tmp8_ = _child_size;
				if (!(_tmp7_ < _tmp8_)) {
					break;
				}
				_tmp9_ = _child_list;
				_tmp10_ = _child_index;
				_tmp11_ = gee_abstract_list_get ((GeeAbstractList*) _tmp9_, _tmp10_);
				child = (soywidgetsBranch*) _tmp11_;
				_tmp12_ = child;
				_tmp12_->priv->_shouldRender = FALSE;
				_g_object_unref0 (child);
			}
			_g_object_unref0 (_child_list);
		}
	} else {
		{
			GeeArrayList* _tmp13_;
			GeeArrayList* _tmp14_;
			GeeArrayList* _child_list;
			GeeArrayList* _tmp15_;
			gint _tmp16_;
			gint _tmp17_;
			gint _child_size;
			gint _child_index;
			_tmp13_ = self->priv->_children;
			_tmp14_ = _g_object_ref0 (_tmp13_);
			_child_list = _tmp14_;
			_tmp15_ = _child_list;
			_tmp16_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp15_);
			_tmp17_ = _tmp16_;
			_child_size = _tmp17_;
			_child_index = -1;
			while (TRUE) {
				gint _tmp18_;
				gint _tmp19_;
				gint _tmp20_;
				GeeArrayList* _tmp21_;
				gint _tmp22_;
				gpointer _tmp23_ = NULL;
				soywidgetsBranch* child;
				soywidgetsBranch* _tmp24_;
				_tmp18_ = _child_index;
				_child_index = _tmp18_ + 1;
				_tmp19_ = _child_index;
				_tmp20_ = _child_size;
				if (!(_tmp19_ < _tmp20_)) {
					break;
				}
				_tmp21_ = _child_list;
				_tmp22_ = _child_index;
				_tmp23_ = gee_abstract_list_get ((GeeAbstractList*) _tmp21_, _tmp22_);
				child = (soywidgetsBranch*) _tmp23_;
				_tmp24_ = child;
				_tmp24_->priv->_shouldRender = TRUE;
				_g_object_unref0 (child);
			}
			_g_object_unref0 (_child_list);
		}
	}
	_tmp25_ = self->priv->_shouldRender;
	if (!_tmp25_) {
		return;
	}
	_tmp26_ = self->priv->_parent;
	_tmp27_ = _g_object_ref0 (_tmp26_);
	p = _tmp27_;
	_tmp28_ = p;
	if (!G_TYPE_CHECK_INSTANCE_TYPE (_tmp28_, SOY_WIDGETS_TYPE_BRANCH)) {
		gint _tmp29_;
		_tmp29_ = self->priv->_branchPosY;
		_soy_widgets_branch_calc_disp (self, _tmp29_, 0);
	}
	_tmp30_ = g_new0 (GLfloat, 20);
	_tmp30_[0] = (GLfloat) 0.0f;
	_tmp30_[1] = (GLfloat) 0.0f;
	_tmp30_[2] = (GLfloat) 0.0f;
	_tmp30_[3] = (GLfloat) 0.0f;
	_tmp30_[4] = (GLfloat) 0.0f;
	_tmp30_[5] = (GLfloat) 1.0f;
	_tmp30_[6] = (GLfloat) 0.0f;
	_tmp30_[7] = (GLfloat) 0.0f;
	_tmp30_[8] = (GLfloat) 1.0f;
	_tmp30_[9] = (GLfloat) 0.0f;
	_tmp30_[10] = (GLfloat) 1.0f;
	_tmp30_[11] = (GLfloat) 1.0f;
	_tmp30_[12] = (GLfloat) 0.0f;
	_tmp30_[13] = (GLfloat) 1.0f;
	_tmp30_[14] = (GLfloat) 1.0f;
	_tmp30_[15] = (GLfloat) 0.0f;
	_tmp30_[16] = (GLfloat) 1.0f;
	_tmp30_[17] = (GLfloat) 0.0f;
	_tmp30_[18] = (GLfloat) 0.0f;
	_tmp30_[19] = (GLfloat) 1.0f;
	soy_widgets_branch__verts = (g_free (soy_widgets_branch__verts), NULL);
	soy_widgets_branch__verts = _tmp30_;
	soy_widgets_branch__verts_length1 = 20;
	_soy_widgets_branch__verts_size_ = soy_widgets_branch__verts_length1;
	_tmp31_ = g_new0 (GLushort, 6);
	_tmp31_[0] = (GLushort) 0;
	_tmp31_[1] = (GLushort) 1;
	_tmp31_[2] = (GLushort) 2;
	_tmp31_[3] = (GLushort) 2;
	_tmp31_[4] = (GLushort) 3;
	_tmp31_[5] = (GLushort) 0;
	soy_widgets_branch__faces = (g_free (soy_widgets_branch__faces), NULL);
	soy_widgets_branch__faces = _tmp31_;
	soy_widgets_branch__faces_length1 = 6;
	_soy_widgets_branch__faces_size_ = soy_widgets_branch__faces_length1;
	_tmp33_ = self->priv->_vbuffer;
	if (_tmp33_ == ((GLuint) 0)) {
		_tmp32_ = TRUE;
	} else {
		GLuint _tmp34_;
		_tmp34_ = self->priv->_ibuffer;
		_tmp32_ = _tmp34_ == ((GLuint) 0);
	}
	_tmp35_ = _tmp32_;
	if (_tmp35_) {
		GLuint _tmp36_ = 0U;
		GLuint _tmp37_;
		GLfloat* _tmp38_;
		gint _tmp38__length1;
		GLuint _tmp39_ = 0U;
		GLuint _tmp40_;
		GLushort* _tmp41_;
		gint _tmp41__length1;
		glGenBuffers ((GLsizei) 1, &_tmp36_);
		self->priv->_vbuffer = _tmp36_;
		_tmp37_ = self->priv->_vbuffer;
		glBindBuffer (GL_ARRAY_BUFFER, _tmp37_);
		_tmp38_ = soy_widgets_branch__verts;
		_tmp38__length1 = soy_widgets_branch__verts_length1;
		glBufferData (GL_ARRAY_BUFFER, (GLsizei) (sizeof (GLfloat) * 20), _tmp38_, GL_STATIC_DRAW);
		glGenBuffers ((GLsizei) 1, &_tmp39_);
		self->priv->_ibuffer = _tmp39_;
		_tmp40_ = self->priv->_ibuffer;
		glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, _tmp40_);
		_tmp41_ = soy_widgets_branch__faces;
		_tmp41__length1 = soy_widgets_branch__faces_length1;
		glBufferData (GL_ELEMENT_ARRAY_BUFFER, (GLsizei) (sizeof (GLushort) * 6), _tmp41_, GL_STATIC_DRAW);
	} else {
		GLuint _tmp42_;
		GLuint _tmp43_;
		_tmp42_ = self->priv->_vbuffer;
		glBindBuffer (GL_ARRAY_BUFFER, _tmp42_);
		_tmp43_ = self->priv->_ibuffer;
		glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, _tmp43_);
	}
	_tmp44_ = self->priv->_branchPosX;
	_tmp45_ = self->priv->_branchPosY;
	_tmp46_ = self->priv->_branchWidth;
	_tmp47_ = self->priv->_branchHeight;
	glViewport ((GLint) _tmp44_, (GLint) _tmp45_, (GLsizei) ((GLint) _tmp46_), (GLsizei) ((GLint) _tmp47_));
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glDisableClientState (GL_NORMAL_ARRAY);
	glVertexPointer ((GLint) 3, GL_FLOAT, (GLsizei) 20, (void*) 0);
	glDrawElements (GL_TRIANGLES, (GLsizei) 6, GL_UNSIGNED_SHORT, (void*) 0);
	_g_object_unref0 (p);
}


static void soy_widgets_branch_class_init (soywidgetsBranchClass * klass) {
	soy_widgets_branch_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (soywidgetsBranchPrivate));
	SOY_WIDGETS_WIDGET_CLASS (klass)->render = soy_widgets_branch_real_render;
	G_OBJECT_CLASS (klass)->finalize = soy_widgets_branch_finalize;
}


static void soy_widgets_branch_instance_init (soywidgetsBranch * self) {
	self->priv = SOY_WIDGETS_BRANCH_GET_PRIVATE (self);
	self->priv->_branchHeight = 20;
	self->priv->_branchWidth = 200;
	self->priv->_indentLength = 20;
}


static void soy_widgets_branch_finalize (GObject* obj) {
	soywidgetsBranch * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_WIDGETS_TYPE_BRANCH, soywidgetsBranch);
	_g_object_unref0 (self->priv->_children);
	_g_free0 (self->name);
	_g_object_unref0 (self->priv->_parent);
	G_OBJECT_CLASS (soy_widgets_branch_parent_class)->finalize (obj);
}


GType soy_widgets_branch_get_type (void) {
	static volatile gsize soy_widgets_branch_type_id__volatile = 0;
	if (g_once_init_enter (&soy_widgets_branch_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soywidgetsBranchClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_widgets_branch_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soywidgetsBranch), 0, (GInstanceInitFunc) soy_widgets_branch_instance_init, NULL };
		GType soy_widgets_branch_type_id;
		soy_widgets_branch_type_id = g_type_register_static (SOY_WIDGETS_TYPE_CONTAINER, "soywidgetsBranch", &g_define_type_info, 0);
		g_once_init_leave (&soy_widgets_branch_type_id__volatile, soy_widgets_branch_type_id);
	}
	return soy_widgets_branch_type_id__volatile;
}


