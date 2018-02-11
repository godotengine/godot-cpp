#include <InterpolatedCamera.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *InterpolatedCamera::___get_type_tag()
{
	return (void *) &InterpolatedCamera::___get_type_tag;
}

void *InterpolatedCamera::___get_base_type_tag()
{
	return (void *) &Camera::___get_type_tag;
}

InterpolatedCamera *InterpolatedCamera::_new()
{
	return (InterpolatedCamera *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"InterpolatedCamera")());
}
void InterpolatedCamera::set_target_path(const NodePath target_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InterpolatedCamera", "set_target_path");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, target_path);
}

NodePath InterpolatedCamera::get_target_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InterpolatedCamera", "get_target_path");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void InterpolatedCamera::set_target(const Object *target) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InterpolatedCamera", "set_target");
	}
	___godot_icall_void_Object(mb, (const Object *) this, target);
}

void InterpolatedCamera::set_speed(const double speed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InterpolatedCamera", "set_speed");
	}
	___godot_icall_void_float(mb, (const Object *) this, speed);
}

double InterpolatedCamera::get_speed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InterpolatedCamera", "get_speed");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void InterpolatedCamera::set_interpolation_enabled(const bool target_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InterpolatedCamera", "set_interpolation_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, target_path);
}

bool InterpolatedCamera::is_interpolation_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InterpolatedCamera", "is_interpolation_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}