#include <ARVRCamera.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ARVRCamera::___get_type_tag()
{
	return (void *) &ARVRCamera::___get_type_tag;
}

void *ARVRCamera::___get_base_type_tag()
{
	return (void *) &Camera::___get_type_tag;
}

ARVRCamera *ARVRCamera::_new()
{
	return (ARVRCamera *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ARVRCamera")());
}
}