#include <RayShape.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *RayShape::___get_type_tag()
{
	return (void *) &RayShape::___get_type_tag;
}

void *RayShape::___get_base_type_tag()
{
	return (void *) &Shape::___get_type_tag;
}

RayShape *RayShape::_new()
{
	return (RayShape *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RayShape")());
}
void RayShape::set_length(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayShape", "set_length");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double RayShape::get_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayShape", "get_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RayShape::set_slips_on_slope(const bool active) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayShape", "set_slips_on_slope");
	}
	___godot_icall_void_bool(mb, (const Object *) this, active);
}

bool RayShape::get_slips_on_slope() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayShape", "get_slips_on_slope");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}