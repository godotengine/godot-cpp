#include <RectangleShape2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *RectangleShape2D::___get_type_tag()
{
	return (void *) &RectangleShape2D::___get_type_tag;
}

void *RectangleShape2D::___get_base_type_tag()
{
	return (void *) &Shape2D::___get_type_tag;
}

RectangleShape2D *RectangleShape2D::_new()
{
	return (RectangleShape2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"RectangleShape2D")());
}
void RectangleShape2D::set_extents(const Vector2 extents) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RectangleShape2D", "set_extents");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, extents);
}

Vector2 RectangleShape2D::get_extents() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("RectangleShape2D", "get_extents");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

}