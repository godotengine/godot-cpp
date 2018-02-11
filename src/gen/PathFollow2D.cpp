#include <PathFollow2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PathFollow2D::___get_type_tag()
{
	return (void *) &PathFollow2D::___get_type_tag;
}

void *PathFollow2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

PathFollow2D *PathFollow2D::_new()
{
	return (PathFollow2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PathFollow2D")());
}
void PathFollow2D::set_offset(const double offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "set_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, offset);
}

double PathFollow2D::get_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "get_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PathFollow2D::set_h_offset(const double h_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "set_h_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, h_offset);
}

double PathFollow2D::get_h_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "get_h_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PathFollow2D::set_v_offset(const double v_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "set_v_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, v_offset);
}

double PathFollow2D::get_v_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "get_v_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PathFollow2D::set_unit_offset(const double unit_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "set_unit_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, unit_offset);
}

double PathFollow2D::get_unit_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "get_unit_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void PathFollow2D::set_rotate(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "set_rotate");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool PathFollow2D::is_rotating() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "is_rotating");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void PathFollow2D::set_cubic_interpolation(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "set_cubic_interpolation");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool PathFollow2D::get_cubic_interpolation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "get_cubic_interpolation");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void PathFollow2D::set_loop(const bool loop) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "set_loop");
	}
	___godot_icall_void_bool(mb, (const Object *) this, loop);
}

bool PathFollow2D::has_loop() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "has_loop");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void PathFollow2D::set_lookahead(const double lookahead) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "set_lookahead");
	}
	___godot_icall_void_float(mb, (const Object *) this, lookahead);
}

double PathFollow2D::get_lookahead() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PathFollow2D", "get_lookahead");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}