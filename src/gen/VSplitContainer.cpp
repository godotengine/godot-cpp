#include <VSplitContainer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VSplitContainer::___get_type_tag()
{
	return (void *) &VSplitContainer::___get_type_tag;
}

void *VSplitContainer::___get_base_type_tag()
{
	return (void *) &SplitContainer::___get_type_tag;
}

VSplitContainer *VSplitContainer::_new()
{
	return (VSplitContainer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VSplitContainer")());
}
}