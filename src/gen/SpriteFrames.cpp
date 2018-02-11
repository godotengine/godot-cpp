#include <SpriteFrames.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *SpriteFrames::___get_type_tag()
{
	return (void *) &SpriteFrames::___get_type_tag;
}

void *SpriteFrames::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

SpriteFrames *SpriteFrames::_new()
{
	return (SpriteFrames *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"SpriteFrames")());
}
void SpriteFrames::add_animation(const String anim) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "add_animation");
	}
	___godot_icall_void_String(mb, (const Object *) this, anim);
}

bool SpriteFrames::has_animation(const String anim) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "has_animation");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, anim);
}

void SpriteFrames::remove_animation(const String anim) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "remove_animation");
	}
	___godot_icall_void_String(mb, (const Object *) this, anim);
}

void SpriteFrames::rename_animation(const String anim, const String newname) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "rename_animation");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, anim, newname);
}

void SpriteFrames::set_animation_speed(const String anim, const double speed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "set_animation_speed");
	}
	___godot_icall_void_String_float(mb, (const Object *) this, anim, speed);
}

double SpriteFrames::get_animation_speed(const String anim) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "get_animation_speed");
	}
	return ___godot_icall_float_String(mb, (const Object *) this, anim);
}

void SpriteFrames::set_animation_loop(const String anim, const bool loop) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "set_animation_loop");
	}
	___godot_icall_void_String_bool(mb, (const Object *) this, anim, loop);
}

bool SpriteFrames::get_animation_loop(const String anim) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "get_animation_loop");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, anim);
}

void SpriteFrames::add_frame(const String anim, const Ref<Texture> frame, const int64_t at_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "add_frame");
	}
	___godot_icall_void_String_Object_int(mb, (const Object *) this, anim, frame.ptr(), at_position);
}

int64_t SpriteFrames::get_frame_count(const String anim) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "get_frame_count");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, anim);
}

Ref<Texture> SpriteFrames::get_frame(const String anim, const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "get_frame");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_String_int(mb, (const Object *) this, anim, idx));
}

void SpriteFrames::set_frame(const String anim, const int64_t idx, const Ref<Texture> txt) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "set_frame");
	}
	___godot_icall_void_String_int_Object(mb, (const Object *) this, anim, idx, txt.ptr());
}

void SpriteFrames::remove_frame(const String anim, const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "remove_frame");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, anim, idx);
}

void SpriteFrames::clear(const String anim) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "clear");
	}
	___godot_icall_void_String(mb, (const Object *) this, anim);
}

void SpriteFrames::clear_all() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "clear_all");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void SpriteFrames::_set_frames(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "_set_frames");
	}
	___godot_icall_void_Array(mb, (const Object *) this, arg0);
}

Array SpriteFrames::_get_frames() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "_get_frames");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void SpriteFrames::_set_animations(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "_set_animations");
	}
	___godot_icall_void_Array(mb, (const Object *) this, arg0);
}

Array SpriteFrames::_get_animations() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SpriteFrames", "_get_animations");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}