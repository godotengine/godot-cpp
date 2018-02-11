#include <CheckBox.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *CheckBox::___get_type_tag()
{
	return (void *) &CheckBox::___get_type_tag;
}

void *CheckBox::___get_base_type_tag()
{
	return (void *) &Button::___get_type_tag;
}

CheckBox *CheckBox::_new()
{
	return (CheckBox *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CheckBox")());
}
}