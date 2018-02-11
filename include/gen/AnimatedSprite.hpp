#ifndef GODOT_CPP_ANIMATEDSPRITE_HPP
#define GODOT_CPP_ANIMATEDSPRITE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Node2D.hpp>
namespace godot {

class SpriteFrames;

class AnimatedSprite : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AnimatedSprite"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AnimatedSprite *_new();

	// methods
	void set_sprite_frames(const Ref<SpriteFrames> sprite_frames);
	Ref<SpriteFrames> get_sprite_frames() const;
	void set_animation(const String animation);
	String get_animation() const;
	void _set_playing(const bool playing);
	bool _is_playing() const;
	void play(const String anim = "");
	void stop();
	bool is_playing() const;
	void set_centered(const bool centered);
	bool is_centered() const;
	void set_offset(const Vector2 offset);
	Vector2 get_offset() const;
	void set_flip_h(const bool flip_h);
	bool is_flipped_h() const;
	void set_flip_v(const bool flip_v);
	bool is_flipped_v() const;
	void set_frame(const int64_t frame);
	int64_t get_frame() const;
	void _res_changed();

};

}

#endif