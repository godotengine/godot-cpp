#include <VBoxContainer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VBoxContainer::___get_type_tag()
{
	return (void *) &VBoxContainer::___get_type_tag;
}

void *VBoxContainer::___get_base_type_tag()
{
	return (void *) &BoxContainer::___get_type_tag;
}

VBoxContainer *VBoxContainer::_new()
{
	return (VBoxContainer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VBoxContainer")());
}
}