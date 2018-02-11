#include <RayShape2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *RayShape2D::___get_type_tag()
{
	return (void *) &RayShape2D::___get_type_tag;
}

void *RayShape2D::___get_base_type_tag()
{
	return (void *) &Shape2D::___get_type_tag;
}

RayShape2D *RayShape2D::_new()
{
	return (RayShape2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RayShape2D")());
}
void RayShape2D::set_length(const double length) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayShape2D", "set_length");
	}
	___godot_icall_void_float(mb, (const Object *) this, length);
}

double RayShape2D::get_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayShape2D", "get_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void RayShape2D::set_slips_on_slope(const bool active) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayShape2D", "set_slips_on_slope");
	}
	___godot_icall_void_bool(mb, (const Object *) this, active);
}

bool RayShape2D::get_slips_on_slope() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RayShape2D", "get_slips_on_slope");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}