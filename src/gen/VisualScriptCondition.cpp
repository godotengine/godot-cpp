#include <VisualScriptCondition.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptCondition::___get_type_tag()
{
	return (void *) &VisualScriptCondition::___get_type_tag;
}

void *VisualScriptCondition::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptCondition *VisualScriptCondition::_new()
{
	return (VisualScriptCondition *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptCondition")());
}
}