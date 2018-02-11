#include <PlaneShape.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PlaneShape::___get_type_tag()
{
	return (void *) &PlaneShape::___get_type_tag;
}

void *PlaneShape::___get_base_type_tag()
{
	return (void *) &Shape::___get_type_tag;
}

PlaneShape *PlaneShape::_new()
{
	return (PlaneShape *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PlaneShape")());
}
void PlaneShape::set_plane(const Plane plane) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PlaneShape", "set_plane");
	}
	___godot_icall_void_Plane(mb, (const Object *) this, plane);
}

Plane PlaneShape::get_plane() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PlaneShape", "get_plane");
	}
	return ___godot_icall_Plane(mb, (const Object *) this);
}

}