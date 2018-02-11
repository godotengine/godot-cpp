#include <AudioEffectEQ10.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectEQ10::___get_type_tag()
{
	return (void *) &AudioEffectEQ10::___get_type_tag;
}

void *AudioEffectEQ10::___get_base_type_tag()
{
	return (void *) &AudioEffectEQ::___get_type_tag;
}

AudioEffectEQ10 *AudioEffectEQ10::_new()
{
	return (AudioEffectEQ10 *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectEQ10")());
}
}