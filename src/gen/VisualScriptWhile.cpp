#include <VisualScriptWhile.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptWhile::___get_type_tag()
{
	return (void *) &VisualScriptWhile::___get_type_tag;
}

void *VisualScriptWhile::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptWhile *VisualScriptWhile::_new()
{
	return (VisualScriptWhile *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptWhile")());
}
}