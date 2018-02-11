#include <VSeparator.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VSeparator::___get_type_tag()
{
	return (void *) &VSeparator::___get_type_tag;
}

void *VSeparator::___get_base_type_tag()
{
	return (void *) &Separator::___get_type_tag;
}

VSeparator *VSeparator::_new()
{
	return (VSeparator *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VSeparator")());
}
}