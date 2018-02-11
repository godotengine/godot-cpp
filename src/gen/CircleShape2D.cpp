#include <CircleShape2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *CircleShape2D::___get_type_tag()
{
	return (void *) &CircleShape2D::___get_type_tag;
}

void *CircleShape2D::___get_base_type_tag()
{
	return (void *) &Shape2D::___get_type_tag;
}

CircleShape2D *CircleShape2D::_new()
{
	return (CircleShape2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CircleShape2D")());
}
void CircleShape2D::set_radius(const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CircleShape2D", "set_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, radius);
}

double CircleShape2D::get_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CircleShape2D", "get_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}