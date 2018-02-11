#include <ARVRInterfaceGDNative.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ARVRInterfaceGDNative::___get_type_tag()
{
	return (void *) &ARVRInterfaceGDNative::___get_type_tag;
}

void *ARVRInterfaceGDNative::___get_base_type_tag()
{
	return (void *) &ARVRInterface::___get_type_tag;
}

ARVRInterfaceGDNative *ARVRInterfaceGDNative::_new()
{
	return (ARVRInterfaceGDNative *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ARVRInterfaceGDNative")());
}
}