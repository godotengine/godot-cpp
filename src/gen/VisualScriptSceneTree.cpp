#include <VisualScriptSceneTree.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptSceneTree::___get_type_tag()
{
	return (void *) &VisualScriptSceneTree::___get_type_tag;
}

void *VisualScriptSceneTree::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptSceneTree *VisualScriptSceneTree::_new()
{
	return (VisualScriptSceneTree *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptSceneTree")());
}
}