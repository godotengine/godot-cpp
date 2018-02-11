#include <Line2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Gradient.hpp>
#include <Texture.hpp>


namespace godot {


void *Line2D::___get_type_tag()
{
	return (void *) &Line2D::___get_type_tag;
}

void *Line2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

Line2D *Line2D::_new()
{
	return (Line2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Line2D")());
}
void Line2D::set_points(const PoolVector2Array points) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_points");
	}
	___godot_icall_void_PoolVector2Array(mb, (const Object *) this, points);
}

PoolVector2Array Line2D::get_points() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_points");
	}
	return ___godot_icall_PoolVector2Array(mb, (const Object *) this);
}

void Line2D::set_point_position(const int64_t i, const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_point_position");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, i, position);
}

Vector2 Line2D::get_point_position(const int64_t i) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_point_position");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, i);
}

int64_t Line2D::get_point_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_point_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Line2D::add_point(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "add_point");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

void Line2D::remove_point(const int64_t i) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "remove_point");
	}
	___godot_icall_void_int(mb, (const Object *) this, i);
}

void Line2D::set_width(const double width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_width");
	}
	___godot_icall_void_float(mb, (const Object *) this, width);
}

double Line2D::get_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_width");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Line2D::set_default_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_default_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color Line2D::get_default_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_default_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void Line2D::set_gradient(const Ref<Gradient> color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_gradient");
	}
	___godot_icall_void_Object(mb, (const Object *) this, color.ptr());
}

Ref<Gradient> Line2D::get_gradient() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_gradient");
	}
	return Ref<Gradient>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Line2D::set_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> Line2D::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Line2D::set_texture_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_texture_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Line2D::LineTextureMode Line2D::get_texture_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_texture_mode");
	}
	return (Line2D::LineTextureMode) ___godot_icall_int(mb, (const Object *) this);
}

void Line2D::set_joint_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_joint_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Line2D::LineJointMode Line2D::get_joint_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_joint_mode");
	}
	return (Line2D::LineJointMode) ___godot_icall_int(mb, (const Object *) this);
}

void Line2D::set_begin_cap_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_begin_cap_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Line2D::LineCapMode Line2D::get_begin_cap_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_begin_cap_mode");
	}
	return (Line2D::LineCapMode) ___godot_icall_int(mb, (const Object *) this);
}

void Line2D::set_end_cap_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_end_cap_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Line2D::LineCapMode Line2D::get_end_cap_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_end_cap_mode");
	}
	return (Line2D::LineCapMode) ___godot_icall_int(mb, (const Object *) this);
}

void Line2D::set_sharp_limit(const double limit) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_sharp_limit");
	}
	___godot_icall_void_float(mb, (const Object *) this, limit);
}

double Line2D::get_sharp_limit() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_sharp_limit");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Line2D::set_round_precision(const int64_t precision) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "set_round_precision");
	}
	___godot_icall_void_int(mb, (const Object *) this, precision);
}

int64_t Line2D::get_round_precision() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "get_round_precision");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Line2D::_gradient_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Line2D", "_gradient_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}