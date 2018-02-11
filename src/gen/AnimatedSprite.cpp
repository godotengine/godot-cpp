#include <AnimatedSprite.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <SpriteFrames.hpp>


namespace godot {


void *AnimatedSprite::___get_type_tag()
{
	return (void *) &AnimatedSprite::___get_type_tag;
}

void *AnimatedSprite::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

AnimatedSprite *AnimatedSprite::_new()
{
	return (AnimatedSprite *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AnimatedSprite")());
}
void AnimatedSprite::set_sprite_frames(const Ref<SpriteFrames> sprite_frames) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "set_sprite_frames");
	}
	___godot_icall_void_Object(mb, (const Object *) this, sprite_frames.ptr());
}

Ref<SpriteFrames> AnimatedSprite::get_sprite_frames() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "get_sprite_frames");
	}
	return Ref<SpriteFrames>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void AnimatedSprite::set_animation(const String animation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "set_animation");
	}
	___godot_icall_void_String(mb, (const Object *) this, animation);
}

String AnimatedSprite::get_animation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "get_animation");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void AnimatedSprite::_set_playing(const bool playing) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "_set_playing");
	}
	___godot_icall_void_bool(mb, (const Object *) this, playing);
}

bool AnimatedSprite::_is_playing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "_is_playing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AnimatedSprite::play(const String anim) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "play");
	}
	___godot_icall_void_String(mb, (const Object *) this, anim);
}

void AnimatedSprite::stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool AnimatedSprite::is_playing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "is_playing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AnimatedSprite::set_centered(const bool centered) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "set_centered");
	}
	___godot_icall_void_bool(mb, (const Object *) this, centered);
}

bool AnimatedSprite::is_centered() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "is_centered");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AnimatedSprite::set_offset(const Vector2 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "set_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, offset);
}

Vector2 AnimatedSprite::get_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "get_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void AnimatedSprite::set_flip_h(const bool flip_h) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "set_flip_h");
	}
	___godot_icall_void_bool(mb, (const Object *) this, flip_h);
}

bool AnimatedSprite::is_flipped_h() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "is_flipped_h");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AnimatedSprite::set_flip_v(const bool flip_v) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "set_flip_v");
	}
	___godot_icall_void_bool(mb, (const Object *) this, flip_v);
}

bool AnimatedSprite::is_flipped_v() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "is_flipped_v");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AnimatedSprite::set_frame(const int64_t frame) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "set_frame");
	}
	___godot_icall_void_int(mb, (const Object *) this, frame);
}

int64_t AnimatedSprite::get_frame() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "get_frame");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void AnimatedSprite::_res_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite", "_res_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}