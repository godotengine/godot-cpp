#include <AudioEffectEQ21.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectEQ21::___get_type_tag()
{
	return (void *) &AudioEffectEQ21::___get_type_tag;
}

void *AudioEffectEQ21::___get_base_type_tag()
{
	return (void *) &AudioEffectEQ::___get_type_tag;
}

AudioEffectEQ21 *AudioEffectEQ21::_new()
{
	return (AudioEffectEQ21 *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectEQ21")());
}
}