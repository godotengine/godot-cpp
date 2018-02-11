#ifndef GODOT_CPP_TOUCHSCREENBUTTON_HPP
#define GODOT_CPP_TOUCHSCREENBUTTON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <TouchScreenButton.hpp>

#include <Node2D.hpp>
namespace godot {

class Texture;
class BitMap;
class Shape2D;
class InputEvent;

class TouchScreenButton : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "TouchScreenButton"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum VisibilityMode {
		VISIBILITY_ALWAYS = 0,
		VISIBILITY_TOUCHSCREEN_ONLY = 1,
	};

	// constants


	static TouchScreenButton *_new();

	// methods
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_texture_pressed(const Ref<Texture> texture_pressed);
	Ref<Texture> get_texture_pressed() const;
	void set_bitmask(const Ref<BitMap> bitmask);
	Ref<BitMap> get_bitmask() const;
	void set_shape(const Ref<Shape2D> shape);
	Ref<Shape2D> get_shape() const;
	void set_shape_centered(const bool _bool);
	bool is_shape_centered() const;
	void set_shape_visible(const bool _bool);
	bool is_shape_visible() const;
	void set_action(const String action);
	String get_action() const;
	void set_visibility_mode(const int64_t mode);
	TouchScreenButton::VisibilityMode get_visibility_mode() const;
	void set_passby_press(const bool enabled);
	bool is_passby_press_enabled() const;
	bool is_pressed() const;
	void _input(const Ref<InputEvent> arg0);

};

}

#endif