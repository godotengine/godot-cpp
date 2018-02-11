#include <Curve2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Curve2D::___get_type_tag()
{
	return (void *) &Curve2D::___get_type_tag;
}

void *Curve2D::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Curve2D *Curve2D::_new()
{
	return (Curve2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Curve2D")());
}
int64_t Curve2D::get_point_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "get_point_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Curve2D::add_point(const Vector2 position, const Vector2 in, const Vector2 out, const int64_t at_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "add_point");
	}
	___godot_icall_void_Vector2_Vector2_Vector2_int(mb, (const Object *) this, position, in, out, at_position);
}

void Curve2D::set_point_position(const int64_t idx, const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "set_point_position");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, idx, position);
}

Vector2 Curve2D::get_point_position(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "get_point_position");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, idx);
}

void Curve2D::set_point_in(const int64_t idx, const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "set_point_in");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, idx, position);
}

Vector2 Curve2D::get_point_in(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "get_point_in");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, idx);
}

void Curve2D::set_point_out(const int64_t idx, const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "set_point_out");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, idx, position);
}

Vector2 Curve2D::get_point_out(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "get_point_out");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, idx);
}

void Curve2D::remove_point(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "remove_point");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void Curve2D::clear_points() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "clear_points");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Vector2 Curve2D::interpolate(const int64_t idx, const double t) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "interpolate");
	}
	return ___godot_icall_Vector2_int_float(mb, (const Object *) this, idx, t);
}

Vector2 Curve2D::interpolatef(const double fofs) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "interpolatef");
	}
	return ___godot_icall_Vector2_float(mb, (const Object *) this, fofs);
}

void Curve2D::set_bake_interval(const double distance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "set_bake_interval");
	}
	___godot_icall_void_float(mb, (const Object *) this, distance);
}

double Curve2D::get_bake_interval() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "get_bake_interval");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Curve2D::get_baked_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "get_baked_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

Vector2 Curve2D::interpolate_baked(const double offset, const bool cubic) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "interpolate_baked");
	}
	return ___godot_icall_Vector2_float_bool(mb, (const Object *) this, offset, cubic);
}

PoolVector2Array Curve2D::get_baked_points() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "get_baked_points");
	}
	return ___godot_icall_PoolVector2Array(mb, (const Object *) this);
}

PoolVector2Array Curve2D::tessellate(const int64_t max_stages, const double tolerance_degrees) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "tessellate");
	}
	return ___godot_icall_PoolVector2Array_int_float(mb, (const Object *) this, max_stages, tolerance_degrees);
}

Dictionary Curve2D::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "_get_data");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

void Curve2D::_set_data(const Dictionary arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve2D", "_set_data");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, arg0);
}

}