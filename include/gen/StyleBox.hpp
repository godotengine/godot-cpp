#ifndef GODOT_CPP_STYLEBOX_HPP
#define GODOT_CPP_STYLEBOX_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {


class StyleBox : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "StyleBox"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	bool test_mask(const Vector2 point, const Rect2 rect) const;
	void set_default_margin(const int64_t margin, const double offset);
	double get_default_margin(const int64_t margin) const;
	double get_margin(const int64_t margin) const;
	Vector2 get_minimum_size() const;
	Vector2 get_center_size() const;
	Vector2 get_offset() const;
	void draw(const RID canvas_item, const Rect2 rect) const;

};

}

#endif