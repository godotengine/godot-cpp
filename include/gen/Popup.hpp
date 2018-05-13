#ifndef GODOT_CPP_POPUP_HPP
#define GODOT_CPP_POPUP_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Control.hpp"
namespace godot {


class Popup : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Popup"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants
	const static int NOTIFICATION_POST_POPUP = 80;
	const static int NOTIFICATION_POPUP_HIDE = 81;


	static Popup *_new();

	// methods
	void popup_centered(const Vector2 size = Vector2(0, 0));
	void popup_centered_ratio(const double ratio = 0.75);
	void popup_centered_minsize(const Vector2 minsize = Vector2(0, 0));
	void popup(const Rect2 bounds = Rect2(0, 0, 0, 0));
	void set_exclusive(const bool enable);
	bool is_exclusive() const;

};

}

#endif