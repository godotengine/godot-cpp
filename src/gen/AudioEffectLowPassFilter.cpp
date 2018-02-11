#include <AudioEffectLowPassFilter.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectLowPassFilter::___get_type_tag()
{
	return (void *) &AudioEffectLowPassFilter::___get_type_tag;
}

void *AudioEffectLowPassFilter::___get_base_type_tag()
{
	return (void *) &AudioEffectFilter::___get_type_tag;
}

AudioEffectLowPassFilter *AudioEffectLowPassFilter::_new()
{
	return (AudioEffectLowPassFilter *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectLowPassFilter")());
}
}