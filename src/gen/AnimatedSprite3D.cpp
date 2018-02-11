#include <AnimatedSprite3D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <SpriteFrames.hpp>


namespace godot {


void *AnimatedSprite3D::___get_type_tag()
{
	return (void *) &AnimatedSprite3D::___get_type_tag;
}

void *AnimatedSprite3D::___get_base_type_tag()
{
	return (void *) &SpriteBase3D::___get_type_tag;
}

AnimatedSprite3D *AnimatedSprite3D::_new()
{
	return (AnimatedSprite3D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AnimatedSprite3D")());
}
void AnimatedSprite3D::set_sprite_frames(const Ref<SpriteFrames> sprite_frames) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "set_sprite_frames");
	}
	___godot_icall_void_Object(mb, (const Object *) this, sprite_frames.ptr());
}

Ref<SpriteFrames> AnimatedSprite3D::get_sprite_frames() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "get_sprite_frames");
	}
	return Ref<SpriteFrames>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void AnimatedSprite3D::set_animation(const String animation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "set_animation");
	}
	___godot_icall_void_String(mb, (const Object *) this, animation);
}

String AnimatedSprite3D::get_animation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "get_animation");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void AnimatedSprite3D::_set_playing(const bool playing) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "_set_playing");
	}
	___godot_icall_void_bool(mb, (const Object *) this, playing);
}

bool AnimatedSprite3D::_is_playing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "_is_playing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AnimatedSprite3D::play(const String anim) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "play");
	}
	___godot_icall_void_String(mb, (const Object *) this, anim);
}

void AnimatedSprite3D::stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool AnimatedSprite3D::is_playing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "is_playing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AnimatedSprite3D::set_frame(const int64_t frame) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "set_frame");
	}
	___godot_icall_void_int(mb, (const Object *) this, frame);
}

int64_t AnimatedSprite3D::get_frame() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "get_frame");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void AnimatedSprite3D::_res_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AnimatedSprite3D", "_res_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}