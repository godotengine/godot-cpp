#ifndef GODOT_CPP_BUTTON_HPP
#define GODOT_CPP_BUTTON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Button.hpp>

#include <BaseButton.hpp>
namespace godot {

class Texture;

class Button : public BaseButton {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Button"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum TextAlign {
		ALIGN_LEFT = 0,
		ALIGN_CENTER = 1,
		ALIGN_RIGHT = 2,
	};

	// constants


	static Button *_new();

	// methods
	void set_text(const String text);
	String get_text() const;
	void set_button_icon(const Ref<Texture> texture);
	Ref<Texture> get_button_icon() const;
	void set_flat(const bool enabled);
	void set_clip_text(const bool enabled);
	bool get_clip_text() const;
	void set_text_align(const int64_t align);
	Button::TextAlign get_text_align() const;
	bool is_flat() const;

};

}

#endif