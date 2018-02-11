#include <PanelContainer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PanelContainer::___get_type_tag()
{
	return (void *) &PanelContainer::___get_type_tag;
}

void *PanelContainer::___get_base_type_tag()
{
	return (void *) &Container::___get_type_tag;
}

PanelContainer *PanelContainer::_new()
{
	return (PanelContainer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PanelContainer")());
}
}