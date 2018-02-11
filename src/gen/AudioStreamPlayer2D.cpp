#include <AudioStreamPlayer2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <AudioStream.hpp>


namespace godot {


void *AudioStreamPlayer2D::___get_type_tag()
{
	return (void *) &AudioStreamPlayer2D::___get_type_tag;
}

void *AudioStreamPlayer2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

AudioStreamPlayer2D *AudioStreamPlayer2D::_new()
{
	return (AudioStreamPlayer2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioStreamPlayer2D")());
}
void AudioStreamPlayer2D::set_stream(const Ref<AudioStream> stream) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "set_stream");
	}
	___godot_icall_void_Object(mb, (const Object *) this, stream.ptr());
}

Ref<AudioStream> AudioStreamPlayer2D::get_stream() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "get_stream");
	}
	return Ref<AudioStream>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void AudioStreamPlayer2D::set_volume_db(const double volume_db) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "set_volume_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, volume_db);
}

double AudioStreamPlayer2D::get_volume_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "get_volume_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer2D::set_pitch_scale(const double pitch_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "set_pitch_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, pitch_scale);
}

double AudioStreamPlayer2D::get_pitch_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "get_pitch_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer2D::play(const double from_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "play");
	}
	___godot_icall_void_float(mb, (const Object *) this, from_position);
}

void AudioStreamPlayer2D::seek(const double to_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "seek");
	}
	___godot_icall_void_float(mb, (const Object *) this, to_position);
}

void AudioStreamPlayer2D::stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool AudioStreamPlayer2D::is_playing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "is_playing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

double AudioStreamPlayer2D::get_playback_position() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "get_playback_position");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer2D::set_bus(const String bus) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "set_bus");
	}
	___godot_icall_void_String(mb, (const Object *) this, bus);
}

String AudioStreamPlayer2D::get_bus() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "get_bus");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void AudioStreamPlayer2D::set_autoplay(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "set_autoplay");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool AudioStreamPlayer2D::is_autoplay_enabled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "is_autoplay_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioStreamPlayer2D::_set_playing(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "_set_playing");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool AudioStreamPlayer2D::_is_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "_is_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioStreamPlayer2D::set_max_distance(const double pixels) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "set_max_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, pixels);
}

double AudioStreamPlayer2D::get_max_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "get_max_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer2D::set_attenuation(const double curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "set_attenuation");
	}
	___godot_icall_void_float(mb, (const Object *) this, curve);
}

double AudioStreamPlayer2D::get_attenuation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "get_attenuation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioStreamPlayer2D::set_area_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "set_area_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t AudioStreamPlayer2D::get_area_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "get_area_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamPlayer2D::_bus_layout_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamPlayer2D", "_bus_layout_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}