#include <ButtonGroup.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <BaseButton.hpp>


namespace godot {


void *ButtonGroup::___get_type_tag()
{
	return (void *) &ButtonGroup::___get_type_tag;
}

void *ButtonGroup::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

ButtonGroup *ButtonGroup::_new()
{
	return (ButtonGroup *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ButtonGroup")());
}
BaseButton *ButtonGroup::get_pressed_button() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ButtonGroup", "get_pressed_button");
	}
	return (BaseButton *) ___godot_icall_Object(mb, (const Object *) this);
}

}