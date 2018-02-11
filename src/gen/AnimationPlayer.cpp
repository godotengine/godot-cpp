#include <AnimationPlayer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <Animation.hpp>


namespace godot {


void *AnimationPlayer::___get_type_tag()
{
	return (void *) &AnimationPlayer::___get_type_tag;
}

void *AnimationPlayer::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

AnimationPlayer *AnimationPlayer::_new()
{
	return (AnimationPlayer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AnimationPlayer")());
}
void AnimationPlayer::_node_removed(const Object *arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "_node_removed");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0);
}

void AnimationPlayer::_animation_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "_animation_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Error AnimationPlayer::add_animation(const String name, const Ref<Animation> animation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "add_animation");
	}
	return (Error) ___godot_icall_int_String_Object(mb, (const Object *) this, name, animation.ptr());
}

void AnimationPlayer::remove_animation(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "remove_animation");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

void AnimationPlayer::rename_animation(const String name, const String newname) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "rename_animation");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, newname);
}

bool AnimationPlayer::has_animation(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "has_animation");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

Ref<Animation> AnimationPlayer::get_animation(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_animation");
	}
	return Ref<Animation>::__internal_constructor(___godot_icall_Object_String(mb, (const Object *) this, name));
}

PoolStringArray AnimationPlayer::get_animation_list() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_animation_list");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

void AnimationPlayer::animation_set_next(const String anim_from, const String anim_to) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "animation_set_next");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, anim_from, anim_to);
}

String AnimationPlayer::animation_get_next(const String anim_from) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "animation_get_next");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, anim_from);
}

void AnimationPlayer::set_blend_time(const String anim_from, const String anim_to, const double sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "set_blend_time");
	}
	___godot_icall_void_String_String_float(mb, (const Object *) this, anim_from, anim_to, sec);
}

double AnimationPlayer::get_blend_time(const String anim_from, const String anim_to) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_blend_time");
	}
	return ___godot_icall_float_String_String(mb, (const Object *) this, anim_from, anim_to);
}

void AnimationPlayer::set_default_blend_time(const double sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "set_default_blend_time");
	}
	___godot_icall_void_float(mb, (const Object *) this, sec);
}

double AnimationPlayer::get_default_blend_time() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_default_blend_time");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AnimationPlayer::play(const String name, const double custom_blend, const double custom_speed, const bool from_end) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "play");
	}
	___godot_icall_void_String_float_float_bool(mb, (const Object *) this, name, custom_blend, custom_speed, from_end);
}

void AnimationPlayer::play_backwards(const String name, const double custom_blend) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "play_backwards");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, name, custom_blend);
}

void AnimationPlayer::stop(const bool reset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "stop");
	}
	___godot_icall_void_bool(mb, (const Object *) this, reset);
}

bool AnimationPlayer::is_playing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "is_playing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AnimationPlayer::set_current_animation(const String anim) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "set_current_animation");
	}
	___godot_icall_void_String(mb, (const Object *) this, anim);
}

String AnimationPlayer::get_current_animation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_current_animation");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void AnimationPlayer::set_assigned_animation(const String anim) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "set_assigned_animation");
	}
	___godot_icall_void_String(mb, (const Object *) this, anim);
}

String AnimationPlayer::get_assigned_animation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_assigned_animation");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void AnimationPlayer::queue(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "queue");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

void AnimationPlayer::clear_queue() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "clear_queue");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void AnimationPlayer::set_active(const bool active) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "set_active");
	}
	___godot_icall_void_bool(mb, (const Object *) this, active);
}

bool AnimationPlayer::is_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "is_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AnimationPlayer::set_speed_scale(const double speed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "set_speed_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, speed);
}

double AnimationPlayer::get_speed_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_speed_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AnimationPlayer::set_autoplay(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "set_autoplay");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String AnimationPlayer::get_autoplay() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_autoplay");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void AnimationPlayer::set_root(const NodePath path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "set_root");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, path);
}

NodePath AnimationPlayer::get_root() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_root");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

String AnimationPlayer::find_animation(const Ref<Animation> animation) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "find_animation");
	}
	return ___godot_icall_String_Object(mb, (const Object *) this, animation.ptr());
}

void AnimationPlayer::clear_caches() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "clear_caches");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void AnimationPlayer::set_animation_process_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "set_animation_process_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

AnimationPlayer::AnimationProcessMode AnimationPlayer::get_animation_process_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_animation_process_mode");
	}
	return (AnimationPlayer::AnimationProcessMode) ___godot_icall_int(mb, (const Object *) this);
}

double AnimationPlayer::get_current_animation_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_current_animation_position");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double AnimationPlayer::get_current_animation_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "get_current_animation_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AnimationPlayer::seek(const double seconds, const bool update) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "seek");
	}
	___godot_icall_void_float_bool(mb, (const Object *) this, seconds, update);
}

void AnimationPlayer::advance(const double delta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimationPlayer", "advance");
	}
	___godot_icall_void_float(mb, (const Object *) this, delta);
}

}