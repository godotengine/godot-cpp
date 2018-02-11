#include <MarginContainer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *MarginContainer::___get_type_tag()
{
	return (void *) &MarginContainer::___get_type_tag;
}

void *MarginContainer::___get_base_type_tag()
{
	return (void *) &Container::___get_type_tag;
}

MarginContainer *MarginContainer::_new()
{
	return (MarginContainer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"MarginContainer")());
}
}