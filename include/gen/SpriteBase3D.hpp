#ifndef GODOT_CPP_SPRITEBASE3D_HPP
#define GODOT_CPP_SPRITEBASE3D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Vector3.hpp>
#include <SpriteBase3D.hpp>

#include <GeometryInstance.hpp>
namespace godot {


class SpriteBase3D : public GeometryInstance {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "SpriteBase3D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum DrawFlags {
		FLAG_TRANSPARENT = 0,
		FLAG_SHADED = 1,
		FLAG_MAX = 3,
		FLAG_DOUBLE_SIDED = 2,
	};
	enum AlphaCutMode {
		ALPHA_CUT_OPAQUE_PREPASS = 2,
		ALPHA_CUT_DISABLED = 0,
		ALPHA_CUT_DISCARD = 1,
	};

	// constants

	// methods
	void set_centered(const bool centered);
	bool is_centered() const;
	void set_offset(const Vector2 offset);
	Vector2 get_offset() const;
	void set_flip_h(const bool flip_h);
	bool is_flipped_h() const;
	void set_flip_v(const bool flip_v);
	bool is_flipped_v() const;
	void set_modulate(const Color modulate);
	Color get_modulate() const;
	void set_opacity(const double opacity);
	double get_opacity() const;
	void set_pixel_size(const double pixel_size);
	double get_pixel_size() const;
	void set_axis(const int64_t axis);
	Vector3::Axis get_axis() const;
	void set_draw_flag(const int64_t flag, const bool enabled);
	bool get_draw_flag(const int64_t flag) const;
	void set_alpha_cut_mode(const int64_t mode);
	SpriteBase3D::AlphaCutMode get_alpha_cut_mode() const;
	Rect2 get_item_rect() const;
	void _queue_update();
	void _im_update();

};

}

#endif