#include <AudioBusLayout.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioBusLayout::___get_type_tag()
{
	return (void *) &AudioBusLayout::___get_type_tag;
}

void *AudioBusLayout::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

AudioBusLayout *AudioBusLayout::_new()
{
	return (AudioBusLayout *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioBusLayout")());
}
}