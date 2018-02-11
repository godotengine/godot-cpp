#include <Curve3D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Curve3D::___get_type_tag()
{
	return (void *) &Curve3D::___get_type_tag;
}

void *Curve3D::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Curve3D *Curve3D::_new()
{
	return (Curve3D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Curve3D")());
}
int64_t Curve3D::get_point_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "get_point_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Curve3D::add_point(const Vector3 position, const Vector3 in, const Vector3 out, const int64_t at_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "add_point");
	}
	___godot_icall_void_Vector3_Vector3_Vector3_int(mb, (const Object *) this, position, in, out, at_position);
}

void Curve3D::set_point_position(const int64_t idx, const Vector3 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "set_point_position");
	}
	___godot_icall_void_int_Vector3(mb, (const Object *) this, idx, position);
}

Vector3 Curve3D::get_point_position(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "get_point_position");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, idx);
}

void Curve3D::set_point_tilt(const int64_t idx, const double tilt) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "set_point_tilt");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, idx, tilt);
}

double Curve3D::get_point_tilt(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "get_point_tilt");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, idx);
}

void Curve3D::set_point_in(const int64_t idx, const Vector3 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "set_point_in");
	}
	___godot_icall_void_int_Vector3(mb, (const Object *) this, idx, position);
}

Vector3 Curve3D::get_point_in(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "get_point_in");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, idx);
}

void Curve3D::set_point_out(const int64_t idx, const Vector3 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "set_point_out");
	}
	___godot_icall_void_int_Vector3(mb, (const Object *) this, idx, position);
}

Vector3 Curve3D::get_point_out(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "get_point_out");
	}
	return ___godot_icall_Vector3_int(mb, (const Object *) this, idx);
}

void Curve3D::remove_point(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "remove_point");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void Curve3D::clear_points() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "clear_points");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Vector3 Curve3D::interpolate(const int64_t idx, const double t) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "interpolate");
	}
	return ___godot_icall_Vector3_int_float(mb, (const Object *) this, idx, t);
}

Vector3 Curve3D::interpolatef(const double fofs) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "interpolatef");
	}
	return ___godot_icall_Vector3_float(mb, (const Object *) this, fofs);
}

void Curve3D::set_bake_interval(const double distance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "set_bake_interval");
	}
	___godot_icall_void_float(mb, (const Object *) this, distance);
}

double Curve3D::get_bake_interval() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "get_bake_interval");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Curve3D::get_baked_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "get_baked_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

Vector3 Curve3D::interpolate_baked(const double offset, const bool cubic) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "interpolate_baked");
	}
	return ___godot_icall_Vector3_float_bool(mb, (const Object *) this, offset, cubic);
}

PoolVector3Array Curve3D::get_baked_points() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "get_baked_points");
	}
	return ___godot_icall_PoolVector3Array(mb, (const Object *) this);
}

PoolRealArray Curve3D::get_baked_tilts() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "get_baked_tilts");
	}
	return ___godot_icall_PoolRealArray(mb, (const Object *) this);
}

PoolVector3Array Curve3D::tessellate(const int64_t max_stages, const double tolerance_degrees) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "tessellate");
	}
	return ___godot_icall_PoolVector3Array_int_float(mb, (const Object *) this, max_stages, tolerance_degrees);
}

Dictionary Curve3D::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "_get_data");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

void Curve3D::_set_data(const Dictionary arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve3D", "_set_data");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, arg0);
}

}