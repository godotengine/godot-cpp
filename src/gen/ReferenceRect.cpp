#include <ReferenceRect.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ReferenceRect::___get_type_tag()
{
	return (void *) &ReferenceRect::___get_type_tag;
}

void *ReferenceRect::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

ReferenceRect *ReferenceRect::_new()
{
	return (ReferenceRect *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ReferenceRect")());
}
}