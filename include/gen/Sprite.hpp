#ifndef GODOT_CPP_SPRITE_HPP
#define GODOT_CPP_SPRITE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node2D.hpp"
namespace godot {

class Texture;

class Sprite : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Sprite"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Sprite *_new();

	// methods
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_normal_map(const Ref<Texture> normal_map);
	Ref<Texture> get_normal_map() const;
	void set_centered(const bool centered);
	bool is_centered() const;
	void set_offset(const Vector2 offset);
	Vector2 get_offset() const;
	void set_flip_h(const bool flip_h);
	bool is_flipped_h() const;
	void set_flip_v(const bool flip_v);
	bool is_flipped_v() const;
	void set_region(const bool enabled);
	bool is_region() const;
	void set_region_rect(const Rect2 rect);
	Rect2 get_region_rect() const;
	void set_region_filter_clip(const bool enabled);
	bool is_region_filter_clip_enabled() const;
	void set_frame(const int64_t frame);
	int64_t get_frame() const;
	void set_vframes(const int64_t vframes);
	int64_t get_vframes() const;
	void set_hframes(const int64_t hframes);
	int64_t get_hframes() const;
	Rect2 get_rect() const;

};

}

#endif