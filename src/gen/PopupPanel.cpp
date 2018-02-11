#include <PopupPanel.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PopupPanel::___get_type_tag()
{
	return (void *) &PopupPanel::___get_type_tag;
}

void *PopupPanel::___get_base_type_tag()
{
	return (void *) &Popup::___get_type_tag;
}

PopupPanel *PopupPanel::_new()
{
	return (PopupPanel *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PopupPanel")());
}
}