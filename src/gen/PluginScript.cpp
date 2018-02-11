#include <PluginScript.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PluginScript::___get_type_tag()
{
	return (void *) &PluginScript::___get_type_tag;
}

void *PluginScript::___get_base_type_tag()
{
	return (void *) &Script::___get_type_tag;
}

PluginScript *PluginScript::_new()
{
	return (PluginScript *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PluginScript")());
}
}