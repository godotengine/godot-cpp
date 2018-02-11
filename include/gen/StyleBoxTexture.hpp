#ifndef GODOT_CPP_STYLEBOXTEXTURE_HPP
#define GODOT_CPP_STYLEBOXTEXTURE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <StyleBoxTexture.hpp>

#include <StyleBox.hpp>
namespace godot {

class Texture;

class StyleBoxTexture : public StyleBox {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "StyleBoxTexture"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum AxisStretchMode {
		AXIS_STRETCH_MODE_STRETCH = 0,
		AXIS_STRETCH_MODE_TILE_FIT = 2,
		AXIS_STRETCH_MODE_TILE = 1,
	};

	// constants


	static StyleBoxTexture *_new();

	// methods
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_normal_map(const Ref<Texture> normal_map);
	Ref<Texture> get_normal_map() const;
	void set_margin_size(const int64_t margin, const double size);
	double get_margin_size(const int64_t margin) const;
	void set_expand_margin_size(const int64_t margin, const double size);
	void set_expand_margin_all(const double size);
	void set_expand_margin_individual(const double size_left, const double size_top, const double size_right, const double size_bottom);
	double get_expand_margin_size(const int64_t margin) const;
	void set_region_rect(const Rect2 region);
	Rect2 get_region_rect() const;
	void set_draw_center(const bool enable);
	bool is_draw_center_enabled() const;
	void set_modulate(const Color color);
	Color get_modulate() const;
	void set_h_axis_stretch_mode(const int64_t mode);
	StyleBoxTexture::AxisStretchMode get_h_axis_stretch_mode() const;
	void set_v_axis_stretch_mode(const int64_t mode);
	StyleBoxTexture::AxisStretchMode get_v_axis_stretch_mode() const;

};

}

#endif