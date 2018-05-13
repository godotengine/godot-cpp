#ifndef GODOT_CPP_FONT_HPP
#define GODOT_CPP_FONT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {


class Font : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Font"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void draw(const RID canvas_item, const Vector2 position, const String string, const Color modulate = Color(1,1,1,1), const int64_t clip_w = -1, const Color outline_modulate = Color(1,1,1,1)) const;
	double get_ascent() const;
	double get_descent() const;
	double get_height() const;
	bool is_distance_field_hint() const;
	Vector2 get_string_size(const String string) const;
	bool has_outline() const;
	double draw_char(const RID canvas_item, const Vector2 position, const int64_t _char, const int64_t next = -1, const Color modulate = Color(1,1,1,1), const bool outline = false) const;
	void update_changes();

};

}

#endif