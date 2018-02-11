#include <Position2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Position2D::___get_type_tag()
{
	return (void *) &Position2D::___get_type_tag;
}

void *Position2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

Position2D *Position2D::_new()
{
	return (Position2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Position2D")());
}
}