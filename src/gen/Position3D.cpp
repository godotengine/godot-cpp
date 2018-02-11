#include <Position3D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Position3D::___get_type_tag()
{
	return (void *) &Position3D::___get_type_tag;
}

void *Position3D::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

Position3D *Position3D::_new()
{
	return (Position3D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Position3D")());
}
}