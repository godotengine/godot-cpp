#include <AudioServer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <AudioEffect.hpp>
#include <AudioBusLayout.hpp>


namespace godot {


void *AudioServer::___get_type_tag()
{
	return (void *) &AudioServer::___get_type_tag;
}

void *AudioServer::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

AudioServer *AudioServer::_singleton = NULL;


AudioServer::AudioServer() {
	_owner = godot::api->godot_global_get_singleton((char *) "AudioServer");
}


void AudioServer::set_bus_count(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "set_bus_count");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

int64_t AudioServer::get_bus_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_bus_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void AudioServer::remove_bus(const int64_t index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "remove_bus");
	}
	___godot_icall_void_int(mb, (const Object *) this, index);
}

void AudioServer::add_bus(const int64_t at_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "add_bus");
	}
	___godot_icall_void_int(mb, (const Object *) this, at_position);
}

void AudioServer::move_bus(const int64_t index, const int64_t to_index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "move_bus");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, index, to_index);
}

void AudioServer::set_bus_name(const int64_t bus_idx, const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "set_bus_name");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, bus_idx, name);
}

String AudioServer::get_bus_name(const int64_t bus_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_bus_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, bus_idx);
}

int64_t AudioServer::get_bus_index(const String bus_name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_bus_index");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, bus_name);
}

void AudioServer::set_bus_volume_db(const int64_t bus_idx, const double volume_db) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "set_bus_volume_db");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, bus_idx, volume_db);
}

double AudioServer::get_bus_volume_db(const int64_t bus_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_bus_volume_db");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, bus_idx);
}

void AudioServer::set_bus_send(const int64_t bus_idx, const String send) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "set_bus_send");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, bus_idx, send);
}

String AudioServer::get_bus_send(const int64_t bus_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_bus_send");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, bus_idx);
}

void AudioServer::set_bus_solo(const int64_t bus_idx, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "set_bus_solo");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bus_idx, enable);
}

bool AudioServer::is_bus_solo(const int64_t bus_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "is_bus_solo");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bus_idx);
}

void AudioServer::set_bus_mute(const int64_t bus_idx, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "set_bus_mute");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bus_idx, enable);
}

bool AudioServer::is_bus_mute(const int64_t bus_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "is_bus_mute");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bus_idx);
}

void AudioServer::set_bus_bypass_effects(const int64_t bus_idx, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "set_bus_bypass_effects");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bus_idx, enable);
}

bool AudioServer::is_bus_bypassing_effects(const int64_t bus_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "is_bus_bypassing_effects");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bus_idx);
}

void AudioServer::add_bus_effect(const int64_t bus_idx, const Ref<AudioEffect> effect, const int64_t at_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "add_bus_effect");
	}
	___godot_icall_void_int_Object_int(mb, (const Object *) this, bus_idx, effect.ptr(), at_position);
}

void AudioServer::remove_bus_effect(const int64_t bus_idx, const int64_t effect_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "remove_bus_effect");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, bus_idx, effect_idx);
}

int64_t AudioServer::get_bus_effect_count(const int64_t bus_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_bus_effect_count");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, bus_idx);
}

Ref<AudioEffect> AudioServer::get_bus_effect(const int64_t bus_idx, const int64_t effect_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_bus_effect");
	}
	return Ref<AudioEffect>::__internal_constructor(___godot_icall_Object_int_int(mb, (const Object *) this, bus_idx, effect_idx));
}

void AudioServer::swap_bus_effects(const int64_t bus_idx, const int64_t effect_idx, const int64_t by_effect_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "swap_bus_effects");
	}
	___godot_icall_void_int_int_int(mb, (const Object *) this, bus_idx, effect_idx, by_effect_idx);
}

void AudioServer::set_bus_effect_enabled(const int64_t bus_idx, const int64_t effect_idx, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "set_bus_effect_enabled");
	}
	___godot_icall_void_int_int_bool(mb, (const Object *) this, bus_idx, effect_idx, enabled);
}

bool AudioServer::is_bus_effect_enabled(const int64_t bus_idx, const int64_t effect_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "is_bus_effect_enabled");
	}
	return ___godot_icall_bool_int_int(mb, (const Object *) this, bus_idx, effect_idx);
}

double AudioServer::get_bus_peak_volume_left_db(const int64_t bus_idx, const int64_t channel) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_bus_peak_volume_left_db");
	}
	return ___godot_icall_float_int_int(mb, (const Object *) this, bus_idx, channel);
}

double AudioServer::get_bus_peak_volume_right_db(const int64_t bus_idx, const int64_t channel) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_bus_peak_volume_right_db");
	}
	return ___godot_icall_float_int_int(mb, (const Object *) this, bus_idx, channel);
}

void AudioServer::lock() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "lock");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void AudioServer::unlock() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "unlock");
	}
	___godot_icall_void(mb, (const Object *) this);
}

AudioServer::SpeakerMode AudioServer::get_speaker_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_speaker_mode");
	}
	return (AudioServer::SpeakerMode) ___godot_icall_int(mb, (const Object *) this);
}

double AudioServer::get_mix_rate() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "get_mix_rate");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioServer::set_bus_layout(const Ref<AudioBusLayout> bus_layout) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "set_bus_layout");
	}
	___godot_icall_void_Object(mb, (const Object *) this, bus_layout.ptr());
}

Ref<AudioBusLayout> AudioServer::generate_bus_layout() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioServer", "generate_bus_layout");
	}
	return Ref<AudioBusLayout>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}