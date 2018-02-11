#ifndef GODOT_CPP_SPRITEFRAMES_HPP
#define GODOT_CPP_SPRITEFRAMES_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {

class Texture;

class SpriteFrames : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "SpriteFrames"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static SpriteFrames *_new();

	// methods
	void add_animation(const String anim);
	bool has_animation(const String anim) const;
	void remove_animation(const String anim);
	void rename_animation(const String anim, const String newname);
	void set_animation_speed(const String anim, const double speed);
	double get_animation_speed(const String anim) const;
	void set_animation_loop(const String anim, const bool loop);
	bool get_animation_loop(const String anim) const;
	void add_frame(const String anim, const Ref<Texture> frame, const int64_t at_position = -1);
	int64_t get_frame_count(const String anim) const;
	Ref<Texture> get_frame(const String anim, const int64_t idx) const;
	void set_frame(const String anim, const int64_t idx, const Ref<Texture> txt);
	void remove_frame(const String anim, const int64_t idx);
	void clear(const String anim);
	void clear_all();
	void _set_frames(const Array arg0);
	Array _get_frames() const;
	void _set_animations(const Array arg0);
	Array _get_animations() const;

};

}

#endif