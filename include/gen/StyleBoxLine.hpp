#ifndef GODOT_CPP_STYLEBOXLINE_HPP
#define GODOT_CPP_STYLEBOXLINE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "StyleBox.hpp"
namespace godot {


class StyleBoxLine : public StyleBox {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "StyleBoxLine"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static StyleBoxLine *_new();

	// methods
	void set_color(const Color color);
	Color get_color() const;
	void set_thickness(const int64_t thickness);
	int64_t get_thickness() const;
	void set_grow(const double grow);
	double get_grow() const;
	void set_vertical(const bool vertical);
	bool is_vertical() const;

};

}

#endif