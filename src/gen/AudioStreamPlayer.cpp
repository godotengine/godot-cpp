#include <AudioStreamPlayer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <AudioStream.hpp>


namespace godot {


void *AudioStreamPlayer::___get_type_tag()
{
	return (void *) &AudioStreamPlayer::___get_type_tag;
}

void *AudioStreamPlayer::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

AudioStreamPlayer *AudioStreamPlayer::_new()
{
	return (AudioStreamPlayer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioStreamPlayer")());
}
void AudioStreamPlayer::set_stream(const Ref<AudioStream> stream) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "set_stream");
	}
	___godot_icall_void_Object(mb, (const Object *) this, stream.ptr());
}

Ref<AudioStream> AudioStreamPlayer::get_stream() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "get_stream");
	}
	return Ref<AudioStream>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void AudioStreamPlayer::set_volume_db(const double volume_db) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "set_volume_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, volume_db);
}

double AudioStreamPlayer::get_volume_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "get_volume_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer::set_pitch_scale(const double pitch_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "set_pitch_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, pitch_scale);
}

double AudioStreamPlayer::get_pitch_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "get_pitch_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer::play(const double from_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "play");
	}
	___godot_icall_void_float(mb, (const Object *) this, from_position);
}

void AudioStreamPlayer::seek(const double to_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "seek");
	}
	___godot_icall_void_float(mb, (const Object *) this, to_position);
}

void AudioStreamPlayer::stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool AudioStreamPlayer::is_playing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "is_playing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

double AudioStreamPlayer::get_playback_position() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "get_playback_position");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer::set_bus(const String bus) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "set_bus");
	}
	___godot_icall_void_String(mb, (const Object *) this, bus);
}

String AudioStreamPlayer::get_bus() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "get_bus");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void AudioStreamPlayer::set_autoplay(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "set_autoplay");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool AudioStreamPlayer::is_autoplay_enabled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "is_autoplay_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioStreamPlayer::set_mix_target(const int64_t mix_target) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "set_mix_target");
	}
	___godot_icall_void_int(mb, (const Object *) this, mix_target);
}

AudioStreamPlayer::MixTarget AudioStreamPlayer::get_mix_target() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "get_mix_target");
	}
	return (AudioStreamPlayer::MixTarget) ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamPlayer::_set_playing(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "_set_playing");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool AudioStreamPlayer::_is_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "_is_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioStreamPlayer::_bus_layout_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer", "_bus_layout_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}