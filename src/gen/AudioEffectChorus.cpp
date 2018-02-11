#include <AudioEffectChorus.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectChorus::___get_type_tag()
{
	return (void *) &AudioEffectChorus::___get_type_tag;
}

void *AudioEffectChorus::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectChorus *AudioEffectChorus::_new()
{
	return (AudioEffectChorus *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectChorus")());
}
void AudioEffectChorus::set_voice_count(const int64_t voices) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "set_voice_count");
	}
	___godot_icall_void_int(mb, (const Object *) this, voices);
}

int64_t AudioEffectChorus::get_voice_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "get_voice_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void AudioEffectChorus::set_voice_delay_ms(const int64_t voice_idx, const double delay_ms) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "set_voice_delay_ms");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, voice_idx, delay_ms);
}

double AudioEffectChorus::get_voice_delay_ms(const int64_t voice_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "get_voice_delay_ms");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, voice_idx);
}

void AudioEffectChorus::set_voice_rate_hz(const int64_t voice_idx, const double rate_hz) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "set_voice_rate_hz");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, voice_idx, rate_hz);
}

double AudioEffectChorus::get_voice_rate_hz(const int64_t voice_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "get_voice_rate_hz");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, voice_idx);
}

void AudioEffectChorus::set_voice_depth_ms(const int64_t voice_idx, const double depth_ms) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "set_voice_depth_ms");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, voice_idx, depth_ms);
}

double AudioEffectChorus::get_voice_depth_ms(const int64_t voice_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "get_voice_depth_ms");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, voice_idx);
}

void AudioEffectChorus::set_voice_level_db(const int64_t voice_idx, const double level_db) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "set_voice_level_db");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, voice_idx, level_db);
}

double AudioEffectChorus::get_voice_level_db(const int64_t voice_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "get_voice_level_db");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, voice_idx);
}

void AudioEffectChorus::set_voice_cutoff_hz(const int64_t voice_idx, const double cutoff_hz) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "set_voice_cutoff_hz");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, voice_idx, cutoff_hz);
}

double AudioEffectChorus::get_voice_cutoff_hz(const int64_t voice_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "get_voice_cutoff_hz");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, voice_idx);
}

void AudioEffectChorus::set_voice_pan(const int64_t voice_idx, const double pan) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "set_voice_pan");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, voice_idx, pan);
}

double AudioEffectChorus::get_voice_pan(const int64_t voice_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "get_voice_pan");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, voice_idx);
}

void AudioEffectChorus::set_wet(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "set_wet");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectChorus::get_wet() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "get_wet");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectChorus::set_dry(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "set_dry");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectChorus::get_dry() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectChorus", "get_dry");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}