#include <HBoxContainer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *HBoxContainer::___get_type_tag()
{
	return (void *) &HBoxContainer::___get_type_tag;
}

void *HBoxContainer::___get_base_type_tag()
{
	return (void *) &BoxContainer::___get_type_tag;
}

HBoxContainer *HBoxContainer::_new()
{
	return (HBoxContainer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"HBoxContainer")());
}
}