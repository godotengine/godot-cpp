#include <VSlider.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VSlider::___get_type_tag()
{
	return (void *) &VSlider::___get_type_tag;
}

void *VSlider::___get_base_type_tag()
{
	return (void *) &Slider::___get_type_tag;
}

VSlider *VSlider::_new()
{
	return (VSlider *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VSlider")());
}
}