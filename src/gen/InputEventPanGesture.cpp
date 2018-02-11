#include <InputEventPanGesture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *InputEventPanGesture::___get_type_tag()
{
	return (void *) &InputEventPanGesture::___get_type_tag;
}

void *InputEventPanGesture::___get_base_type_tag()
{
	return (void *) &InputEventGesture::___get_type_tag;
}

InputEventPanGesture *InputEventPanGesture::_new()
{
	return (InputEventPanGesture *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"InputEventPanGesture")());
}
void InputEventPanGesture::set_delta(const Vector2 delta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventPanGesture", "set_delta");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, delta);
}

Vector2 InputEventPanGesture::get_delta() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventPanGesture", "get_delta");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

}