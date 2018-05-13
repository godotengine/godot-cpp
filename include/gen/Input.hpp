#ifndef GODOT_CPP_INPUT_HPP
#define GODOT_CPP_INPUT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Input.hpp"

#include "Object.hpp"
namespace godot {

class Resource;
class InputEvent;

class Input : public Object {
	static Input *_singleton;

	Input();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline Input *get_singleton()
	{
		if (!Input::_singleton) {
			Input::_singleton = new Input;
		}
		return Input::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "Input"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum MouseMode {
		MOUSE_MODE_CONFINED = 3,
		MOUSE_MODE_VISIBLE = 0,
		MOUSE_MODE_HIDDEN = 1,
		MOUSE_MODE_CAPTURED = 2,
	};
	enum CursorShape {
		CURSOR_ARROW = 0,
		CURSOR_WAIT = 4,
		CURSOR_FORBIDDEN = 8,
		CURSOR_CROSS = 3,
		CURSOR_DRAG = 6,
		CURSOR_FDIAGSIZE = 12,
		CURSOR_HSIZE = 10,
		CURSOR_MOVE = 13,
		CURSOR_IBEAM = 1,
		CURSOR_HSPLIT = 15,
		CURSOR_BUSY = 5,
		CURSOR_HELP = 16,
		CURSOR_POINTING_HAND = 2,
		CURSOR_VSIZE = 9,
		CURSOR_CAN_DROP = 7,
		CURSOR_VSPLIT = 14,
		CURSOR_BDIAGSIZE = 11,
	};

	// constants

	// methods
	bool is_key_pressed(const int64_t scancode) const;
	bool is_mouse_button_pressed(const int64_t button) const;
	bool is_joy_button_pressed(const int64_t device, const int64_t button) const;
	bool is_action_pressed(const String action) const;
	bool is_action_just_pressed(const String action) const;
	bool is_action_just_released(const String action) const;
	double get_action_strength(const String action) const;
	void add_joy_mapping(const String mapping, const bool update_existing = false);
	void remove_joy_mapping(const String guid);
	void joy_connection_changed(const int64_t device, const bool connected, const String name, const String guid);
	bool is_joy_known(const int64_t device);
	double get_joy_axis(const int64_t device, const int64_t axis) const;
	String get_joy_name(const int64_t device);
	String get_joy_guid(const int64_t device) const;
	Array get_connected_joypads();
	Vector2 get_joy_vibration_strength(const int64_t device);
	double get_joy_vibration_duration(const int64_t device);
	String get_joy_button_string(const int64_t button_index);
	int64_t get_joy_button_index_from_string(const String button);
	String get_joy_axis_string(const int64_t axis_index);
	int64_t get_joy_axis_index_from_string(const String axis);
	void start_joy_vibration(const int64_t device, const double weak_magnitude, const double strong_magnitude, const double duration = 0);
	void stop_joy_vibration(const int64_t device);
	Vector3 get_gravity() const;
	Vector3 get_accelerometer() const;
	Vector3 get_magnetometer() const;
	Vector3 get_gyroscope() const;
	Vector2 get_last_mouse_speed() const;
	int64_t get_mouse_button_mask() const;
	void set_mouse_mode(const int64_t mode);
	Input::MouseMode get_mouse_mode() const;
	void warp_mouse_position(const Vector2 to);
	void action_press(const String action);
	void action_release(const String action);
	void set_default_cursor_shape(const int64_t shape = 0);
	void set_custom_mouse_cursor(const Ref<Resource> image, const int64_t shape = 0, const Vector2 hotspot = Vector2(0, 0));
	void parse_input_event(const Ref<InputEvent> event);

};

}

#endif