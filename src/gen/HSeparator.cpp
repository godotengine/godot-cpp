#include <HSeparator.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *HSeparator::___get_type_tag()
{
	return (void *) &HSeparator::___get_type_tag;
}

void *HSeparator::___get_base_type_tag()
{
	return (void *) &Separator::___get_type_tag;
}

HSeparator *HSeparator::_new()
{
	return (HSeparator *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"HSeparator")());
}
}