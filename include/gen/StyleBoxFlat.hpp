#ifndef GODOT_CPP_STYLEBOXFLAT_HPP
#define GODOT_CPP_STYLEBOXFLAT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "StyleBox.hpp"
namespace godot {


class StyleBoxFlat : public StyleBox {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "StyleBoxFlat"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static StyleBoxFlat *_new();

	// methods
	void set_bg_color(const Color color);
	Color get_bg_color() const;
	void set_border_color(const Color color);
	Color get_border_color() const;
	void set_border_width_all(const int64_t width);
	int64_t get_border_width_min() const;
	void set_border_width(const int64_t margin, const int64_t width);
	int64_t get_border_width(const int64_t margin) const;
	void set_border_blend(const bool blend);
	bool get_border_blend() const;
	void set_corner_radius_individual(const int64_t radius_top_left, const int64_t radius_top_right, const int64_t radius_bottom_right, const int64_t radius_bottom_left);
	void set_corner_radius_all(const int64_t radius);
	void set_corner_radius(const int64_t corner, const int64_t radius);
	int64_t get_corner_radius(const int64_t corner) const;
	void set_expand_margin(const int64_t margin, const double size);
	void set_expand_margin_all(const double size);
	void set_expand_margin_individual(const double size_left, const double size_top, const double size_right, const double size_bottom);
	double get_expand_margin(const int64_t margin) const;
	void set_draw_center(const bool draw_center);
	bool is_draw_center_enabled() const;
	void set_shadow_color(const Color color);
	Color get_shadow_color() const;
	void set_shadow_size(const int64_t size);
	int64_t get_shadow_size() const;
	void set_anti_aliased(const bool anti_aliased);
	bool is_anti_aliased() const;
	void set_aa_size(const int64_t size);
	int64_t get_aa_size() const;
	void set_corner_detail(const int64_t detail);
	int64_t get_corner_detail() const;

};

}

#endif