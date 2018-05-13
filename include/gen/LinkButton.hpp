#ifndef GODOT_CPP_LINKBUTTON_HPP
#define GODOT_CPP_LINKBUTTON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "LinkButton.hpp"

#include "BaseButton.hpp"
namespace godot {


class LinkButton : public BaseButton {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "LinkButton"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum UnderlineMode {
		UNDERLINE_MODE_NEVER = 2,
		UNDERLINE_MODE_ALWAYS = 0,
		UNDERLINE_MODE_ON_HOVER = 1,
	};

	// constants


	static LinkButton *_new();

	// methods
	void set_text(const String text);
	String get_text() const;
	void set_underline_mode(const int64_t underline_mode);
	LinkButton::UnderlineMode get_underline_mode() const;

};

}

#endif