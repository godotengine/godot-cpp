#include <VisualScriptIndexGet.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptIndexGet::___get_type_tag()
{
	return (void *) &VisualScriptIndexGet::___get_type_tag;
}

void *VisualScriptIndexGet::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptIndexGet *VisualScriptIndexGet::_new()
{
	return (VisualScriptIndexGet *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptIndexGet")());
}
}