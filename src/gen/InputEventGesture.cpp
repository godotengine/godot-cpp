#include <InputEventGesture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *InputEventGesture::___get_type_tag()
{
	return (void *) &InputEventGesture::___get_type_tag;
}

void *InputEventGesture::___get_base_type_tag()
{
	return (void *) &InputEventWithModifiers::___get_type_tag;
}

void InputEventGesture::set_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventGesture", "set_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

Vector2 InputEventGesture::get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("InputEventGesture", "get_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

}