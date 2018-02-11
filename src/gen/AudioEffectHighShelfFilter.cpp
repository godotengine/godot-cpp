#include <AudioEffectHighShelfFilter.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectHighShelfFilter::___get_type_tag()
{
	return (void *) &AudioEffectHighShelfFilter::___get_type_tag;
}

void *AudioEffectHighShelfFilter::___get_base_type_tag()
{
	return (void *) &AudioEffectFilter::___get_type_tag;
}

AudioEffectHighShelfFilter *AudioEffectHighShelfFilter::_new()
{
	return (AudioEffectHighShelfFilter *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectHighShelfFilter")());
}
}