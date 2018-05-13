#ifndef GODOT_CPP_WINDOWDIALOG_HPP
#define GODOT_CPP_WINDOWDIALOG_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Popup.hpp"
namespace godot {

class InputEvent;
class TextureButton;

class WindowDialog : public Popup {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "WindowDialog"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static WindowDialog *_new();

	// methods
	void _gui_input(const Ref<InputEvent> arg0);
	void set_title(const String title);
	String get_title() const;
	void set_resizable(const bool resizable);
	bool get_resizable() const;
	void _closed();
	TextureButton *get_close_button();

};

}

#endif