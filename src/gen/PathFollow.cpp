#include <PathFollow.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PathFollow::___get_type_tag()
{
	return (void *) &PathFollow::___get_type_tag;
}

void *PathFollow::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

PathFollow *PathFollow::_new()
{
	return (PathFollow *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PathFollow")());
}
void PathFollow::set_offset(const double offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "set_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, offset);
}

double PathFollow::get_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "get_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PathFollow::set_h_offset(const double h_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "set_h_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, h_offset);
}

double PathFollow::get_h_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "get_h_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PathFollow::set_v_offset(const double v_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "set_v_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, v_offset);
}

double PathFollow::get_v_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "get_v_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PathFollow::set_unit_offset(const double unit_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "set_unit_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, unit_offset);
}

double PathFollow::get_unit_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "get_unit_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PathFollow::set_rotation_mode(const int64_t rotation_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "set_rotation_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, rotation_mode);
}

PathFollow::RotationMode PathFollow::get_rotation_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "get_rotation_mode");
	}
	return (PathFollow::RotationMode) ___godot_icall_int(mb, (const Object *) this);
}

void PathFollow::set_cubic_interpolation(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "set_cubic_interpolation");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool PathFollow::get_cubic_interpolation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "get_cubic_interpolation");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void PathFollow::set_loop(const bool loop) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "set_loop");
	}
	___godot_icall_void_bool(mb, (const Object *) this, loop);
}

bool PathFollow::has_loop() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow", "has_loop");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}