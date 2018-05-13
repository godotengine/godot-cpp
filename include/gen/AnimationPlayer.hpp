#ifndef GODOT_CPP_ANIMATIONPLAYER_HPP
#define GODOT_CPP_ANIMATIONPLAYER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "AnimationPlayer.hpp"

#include "Node.hpp"
namespace godot {

class Object;
class Animation;

class AnimationPlayer : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AnimationPlayer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum AnimationProcessMode {
		ANIMATION_PROCESS_IDLE = 1,
		ANIMATION_PROCESS_PHYSICS = 0,
	};

	// constants


	static AnimationPlayer *_new();

	// methods
	void _node_removed(const Object *arg0);
	void _animation_changed();
	Error add_animation(const String name, const Ref<Animation> animation);
	void remove_animation(const String name);
	void rename_animation(const String name, const String newname);
	bool has_animation(const String name) const;
	Ref<Animation> get_animation(const String name) const;
	PoolStringArray get_animation_list() const;
	void animation_set_next(const String anim_from, const String anim_to);
	String animation_get_next(const String anim_from) const;
	void set_blend_time(const String anim_from, const String anim_to, const double sec);
	double get_blend_time(const String anim_from, const String anim_to) const;
	void set_default_blend_time(const double sec);
	double get_default_blend_time() const;
	void play(const String name = "", const double custom_blend = -1, const double custom_speed = 1, const bool from_end = false);
	void play_backwards(const String name = "", const double custom_blend = -1);
	void stop(const bool reset = true);
	bool is_playing() const;
	void set_current_animation(const String anim);
	String get_current_animation() const;
	void set_assigned_animation(const String anim);
	String get_assigned_animation() const;
	void queue(const String name);
	void clear_queue();
	void set_active(const bool active);
	bool is_active() const;
	void set_speed_scale(const double speed);
	double get_speed_scale() const;
	double get_playing_speed() const;
	void set_autoplay(const String name);
	String get_autoplay() const;
	void set_root(const NodePath path);
	NodePath get_root() const;
	String find_animation(const Ref<Animation> animation) const;
	void clear_caches();
	void set_animation_process_mode(const int64_t mode);
	AnimationPlayer::AnimationProcessMode get_animation_process_mode() const;
	double get_current_animation_position() const;
	double get_current_animation_length() const;
	void seek(const double seconds, const bool update = false);
	void advance(const double delta);

};

}

#endif