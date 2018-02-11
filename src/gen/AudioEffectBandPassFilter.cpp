#include <AudioEffectBandPassFilter.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectBandPassFilter::___get_type_tag()
{
	return (void *) &AudioEffectBandPassFilter::___get_type_tag;
}

void *AudioEffectBandPassFilter::___get_base_type_tag()
{
	return (void *) &AudioEffectFilter::___get_type_tag;
}

AudioEffectBandPassFilter *AudioEffectBandPassFilter::_new()
{
	return (AudioEffectBandPassFilter *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectBandPassFilter")());
}
}