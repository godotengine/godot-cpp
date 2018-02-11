#include <Curve.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Curve::___get_type_tag()
{
	return (void *) &Curve::___get_type_tag;
}

void *Curve::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Curve *Curve::_new()
{
	return (Curve *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Curve")());
}
int64_t Curve::add_point(const Vector2 position, const double left_tangent, const double right_tangent, const int64_t left_mode, const int64_t right_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "add_point");
	}
	return ___godot_icall_int_Vector2_float_float_int_int(mb, (const Object *) this, position, left_tangent, right_tangent, left_mode, right_mode);
}

void Curve::remove_point(const int64_t index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "remove_point");
	}
	___godot_icall_void_int(mb, (const Object *) this, index);
}

void Curve::clear_points() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "clear_points");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Vector2 Curve::get_point_position(const int64_t index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "get_point_position");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, index);
}

void Curve::set_point_value(const int64_t index, const double y) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "set_point_value");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, index, y);
}

int64_t Curve::set_point_offset(const int64_t index, const double offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "set_point_offset");
	}
	return ___godot_icall_int_int_float(mb, (const Object *) this, index, offset);
}

double Curve::interpolate(const double offset) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "interpolate");
	}
	return ___godot_icall_float_float(mb, (const Object *) this, offset);
}

double Curve::interpolate_baked(const double offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "interpolate_baked");
	}
	return ___godot_icall_float_float(mb, (const Object *) this, offset);
}

double Curve::get_point_left_tangent(const int64_t index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "get_point_left_tangent");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, index);
}

double Curve::get_point_right_tangent(const int64_t index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "get_point_right_tangent");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, index);
}

Curve::TangentMode Curve::get_point_left_mode(const int64_t index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "get_point_left_mode");
	}
	return (Curve::TangentMode) ___godot_icall_int_int(mb, (const Object *) this, index);
}

Curve::TangentMode Curve::get_point_right_mode(const int64_t index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "get_point_right_mode");
	}
	return (Curve::TangentMode) ___godot_icall_int_int(mb, (const Object *) this, index);
}

void Curve::set_point_left_tangent(const int64_t index, const double tangent) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "set_point_left_tangent");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, index, tangent);
}

void Curve::set_point_right_tangent(const int64_t index, const double tangent) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "set_point_right_tangent");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, index, tangent);
}

void Curve::set_point_left_mode(const int64_t index, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "set_point_left_mode");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, index, mode);
}

void Curve::set_point_right_mode(const int64_t index, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "set_point_right_mode");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, index, mode);
}

double Curve::get_min_value() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "get_min_value");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Curve::set_min_value(const double min) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "set_min_value");
	}
	___godot_icall_void_float(mb, (const Object *) this, min);
}

double Curve::get_max_value() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "get_max_value");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Curve::set_max_value(const double max) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "set_max_value");
	}
	___godot_icall_void_float(mb, (const Object *) this, max);
}

void Curve::clean_dupes() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "clean_dupes");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Curve::bake() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "bake");
	}
	___godot_icall_void(mb, (const Object *) this);
}

int64_t Curve::get_bake_resolution() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "get_bake_resolution");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Curve::set_bake_resolution(const int64_t resolution) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "set_bake_resolution");
	}
	___godot_icall_void_int(mb, (const Object *) this, resolution);
}

Array Curve::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "_get_data");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void Curve::_set_data(const Array data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Curve", "_set_data");
	}
	___godot_icall_void_Array(mb, (const Object *) this, data);
}

}