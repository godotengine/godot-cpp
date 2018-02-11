#ifndef GODOT_CPP_TEXTUREPROGRESS_HPP
#define GODOT_CPP_TEXTUREPROGRESS_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Range.hpp>
namespace godot {

class Texture;

class TextureProgress : public Range {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "TextureProgress"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum FillMode {
		FILL_RIGHT_TO_LEFT = 1,
		FILL_CLOCKWISE = 4,
		FILL_BOTTOM_TO_TOP = 3,
		FILL_LEFT_TO_RIGHT = 0,
		FILL_TOP_TO_BOTTOM = 2,
		FILL_COUNTER_CLOCKWISE = 5,
	};

	// constants


	static TextureProgress *_new();

	// methods
	void set_under_texture(const Ref<Texture> tex);
	Ref<Texture> get_under_texture() const;
	void set_progress_texture(const Ref<Texture> tex);
	Ref<Texture> get_progress_texture() const;
	void set_over_texture(const Ref<Texture> tex);
	Ref<Texture> get_over_texture() const;
	void set_fill_mode(const int64_t mode);
	int64_t get_fill_mode();
	void set_radial_initial_angle(const double mode);
	double get_radial_initial_angle();
	void set_radial_center_offset(const Vector2 mode);
	Vector2 get_radial_center_offset();
	void set_fill_degrees(const double mode);
	double get_fill_degrees();
	void set_stretch_margin(const int64_t margin, const int64_t value);
	int64_t get_stretch_margin(const int64_t margin) const;
	void set_nine_patch_stretch(const bool stretch);
	bool get_nine_patch_stretch() const;

};

}

#endif