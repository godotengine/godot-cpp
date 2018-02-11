#include <VisualScriptIterator.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptIterator::___get_type_tag()
{
	return (void *) &VisualScriptIterator::___get_type_tag;
}

void *VisualScriptIterator::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptIterator *VisualScriptIterator::_new()
{
	return (VisualScriptIterator *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptIterator")());
}
}