#ifndef GODOT_CPP_NINEPATCHRECT_HPP
#define GODOT_CPP_NINEPATCHRECT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "NinePatchRect.hpp"

#include "Control.hpp"
namespace godot {

class Texture;

class NinePatchRect : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "NinePatchRect"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum AxisStretchMode {
		AXIS_STRETCH_MODE_STRETCH = 0,
		AXIS_STRETCH_MODE_TILE_FIT = 2,
		AXIS_STRETCH_MODE_TILE = 1,
	};

	// constants


	static NinePatchRect *_new();

	// methods
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_patch_margin(const int64_t margin, const int64_t value);
	int64_t get_patch_margin(const int64_t margin) const;
	void set_region_rect(const Rect2 rect);
	Rect2 get_region_rect() const;
	void set_draw_center(const bool draw_center);
	bool is_draw_center_enabled() const;
	void set_h_axis_stretch_mode(const int64_t mode);
	NinePatchRect::AxisStretchMode get_h_axis_stretch_mode() const;
	void set_v_axis_stretch_mode(const int64_t mode);
	NinePatchRect::AxisStretchMode get_v_axis_stretch_mode() const;

};

}

#endif