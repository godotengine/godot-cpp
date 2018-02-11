#include <Input.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Resource.hpp>
#include <InputEvent.hpp>


namespace godot {


void *Input::___get_type_tag()
{
	return (void *) &Input::___get_type_tag;
}

void *Input::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

Input *Input::_singleton = NULL;


Input::Input() {
	_owner = godot::api->godot_global_get_singleton((char *) "Input");
}


bool Input::is_key_pressed(const int64_t scancode) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "is_key_pressed");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, scancode);
}

bool Input::is_mouse_button_pressed(const int64_t button) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "is_mouse_button_pressed");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, button);
}

bool Input::is_joy_button_pressed(const int64_t device, const int64_t button) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "is_joy_button_pressed");
	}
	return ___godot_icall_bool_int_int(mb, (const Object *) this, device, button);
}

bool Input::is_action_pressed(const String action) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "is_action_pressed");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, action);
}

bool Input::is_action_just_pressed(const String action) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "is_action_just_pressed");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, action);
}

bool Input::is_action_just_released(const String action) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "is_action_just_released");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, action);
}

void Input::add_joy_mapping(const String mapping, const bool update_existing) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "add_joy_mapping");
	}
	___godot_icall_void_String_bool(mb, (const Object *) this, mapping, update_existing);
}

void Input::remove_joy_mapping(const String guid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "remove_joy_mapping");
	}
	___godot_icall_void_String(mb, (const Object *) this, guid);
}

void Input::joy_connection_changed(const int64_t device, const bool connected, const String name, const String guid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "joy_connection_changed");
	}
	___godot_icall_void_int_bool_String_String(mb, (const Object *) this, device, connected, name, guid);
}

bool Input::is_joy_known(const int64_t device) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "is_joy_known");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, device);
}

double Input::get_joy_axis(const int64_t device, const int64_t axis) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_joy_axis");
	}
	return ___godot_icall_float_int_int(mb, (const Object *) this, device, axis);
}

String Input::get_joy_name(const int64_t device) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_joy_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, device);
}

String Input::get_joy_guid(const int64_t device) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_joy_guid");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, device);
}

Array Input::get_connected_joypads() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_connected_joypads");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Vector2 Input::get_joy_vibration_strength(const int64_t device) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_joy_vibration_strength");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, device);
}

double Input::get_joy_vibration_duration(const int64_t device) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_joy_vibration_duration");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, device);
}

String Input::get_joy_button_string(const int64_t button_index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_joy_button_string");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, button_index);
}

int64_t Input::get_joy_button_index_from_string(const String button) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_joy_button_index_from_string");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, button);
}

String Input::get_joy_axis_string(const int64_t axis_index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_joy_axis_string");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, axis_index);
}

int64_t Input::get_joy_axis_index_from_string(const String axis) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_joy_axis_index_from_string");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, axis);
}

void Input::start_joy_vibration(const int64_t device, const double weak_magnitude, const double strong_magnitude, const double duration) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "start_joy_vibration");
	}
	___godot_icall_void_int_float_float_float(mb, (const Object *) this, device, weak_magnitude, strong_magnitude, duration);
}

void Input::stop_joy_vibration(const int64_t device) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "stop_joy_vibration");
	}
	___godot_icall_void_int(mb, (const Object *) this, device);
}

Vector3 Input::get_gravity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_gravity");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Vector3 Input::get_accelerometer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_accelerometer");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Vector3 Input::get_magnetometer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_magnetometer");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Vector3 Input::get_gyroscope() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_gyroscope");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Vector2 Input::get_last_mouse_speed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_last_mouse_speed");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

int64_t Input::get_mouse_button_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_mouse_button_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Input::set_mouse_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "set_mouse_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Input::MouseMode Input::get_mouse_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "get_mouse_mode");
	}
	return (Input::MouseMode) ___godot_icall_int(mb, (const Object *) this);
}

void Input::warp_mouse_position(const Vector2 to) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "warp_mouse_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, to);
}

void Input::action_press(const String action) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "action_press");
	}
	___godot_icall_void_String(mb, (const Object *) this, action);
}

void Input::action_release(const String action) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "action_release");
	}
	___godot_icall_void_String(mb, (const Object *) this, action);
}

void Input::set_custom_mouse_cursor(const Ref<Resource> image, const int64_t shape, const Vector2 hotspot) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "set_custom_mouse_cursor");
	}
	___godot_icall_void_Object_int_Vector2(mb, (const Object *) this, image.ptr(), shape, hotspot);
}

void Input::parse_input_event(const Ref<InputEvent> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Input", "parse_input_event");
	}
	___godot_icall_void_Object(mb, (const Object *) this, event.ptr());
}

}