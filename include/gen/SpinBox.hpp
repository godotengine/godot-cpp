#ifndef GODOT_CPP_SPINBOX_HPP
#define GODOT_CPP_SPINBOX_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Range.hpp>
namespace godot {

class InputEvent;
class LineEdit;

class SpinBox : public Range {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "SpinBox"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static SpinBox *_new();

	// methods
	void _gui_input(const Ref<InputEvent> arg0);
	void _text_entered(const String arg0);
	void set_suffix(const String suffix);
	String get_suffix() const;
	void set_prefix(const String prefix);
	String get_prefix() const;
	void set_editable(const bool editable);
	bool is_editable() const;
	void _line_edit_focus_exit();
	LineEdit *get_line_edit();
	void _line_edit_input(const Ref<InputEvent> arg0);
	void _range_click_timeout();

};

}

#endif