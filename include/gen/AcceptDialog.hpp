#ifndef GODOT_CPP_ACCEPTDIALOG_HPP
#define GODOT_CPP_ACCEPTDIALOG_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <WindowDialog.hpp>
namespace godot {

class Button;
class Label;
class Object;

class AcceptDialog : public WindowDialog {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AcceptDialog"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AcceptDialog *_new();

	// methods
	void _ok();
	Button *get_ok();
	Label *get_label();
	void set_hide_on_ok(const bool enabled);
	bool get_hide_on_ok() const;
	Button *add_button(const String text, const bool right = false, const String action = "");
	Button *add_cancel(const String name);
	void _builtin_text_entered(const String arg0);
	void register_text_enter(const Object *line_edit);
	void _custom_action(const String arg0);
	void set_text(const String text);
	String get_text() const;

};

}

#endif