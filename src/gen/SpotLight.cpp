#include <SpotLight.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *SpotLight::___get_type_tag()
{
	return (void *) &SpotLight::___get_type_tag;
}

void *SpotLight::___get_base_type_tag()
{
	return (void *) &Light::___get_type_tag;
}

SpotLight *SpotLight::_new()
{
	return (SpotLight *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"SpotLight")());
}
}