#include <VisualScriptSwitch.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptSwitch::___get_type_tag()
{
	return (void *) &VisualScriptSwitch::___get_type_tag;
}

void *VisualScriptSwitch::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptSwitch *VisualScriptSwitch::_new()
{
	return (VisualScriptSwitch *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptSwitch")());
}
}