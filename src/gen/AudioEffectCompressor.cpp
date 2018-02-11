#include <AudioEffectCompressor.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectCompressor::___get_type_tag()
{
	return (void *) &AudioEffectCompressor::___get_type_tag;
}

void *AudioEffectCompressor::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectCompressor *AudioEffectCompressor::_new()
{
	return (AudioEffectCompressor *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectCompressor")());
}
void AudioEffectCompressor::set_threshold(const double threshold) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "set_threshold");
	}
	___godot_icall_void_float(mb, (const Object *) this, threshold);
}

double AudioEffectCompressor::get_threshold() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "get_threshold");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectCompressor::set_ratio(const double ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "set_ratio");
	}
	___godot_icall_void_float(mb, (const Object *) this, ratio);
}

double AudioEffectCompressor::get_ratio() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "get_ratio");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectCompressor::set_gain(const double gain) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "set_gain");
	}
	___godot_icall_void_float(mb, (const Object *) this, gain);
}

double AudioEffectCompressor::get_gain() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "get_gain");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectCompressor::set_attack_us(const double attack_us) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "set_attack_us");
	}
	___godot_icall_void_float(mb, (const Object *) this, attack_us);
}

double AudioEffectCompressor::get_attack_us() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "get_attack_us");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectCompressor::set_release_ms(const double release_ms) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "set_release_ms");
	}
	___godot_icall_void_float(mb, (const Object *) this, release_ms);
}

double AudioEffectCompressor::get_release_ms() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "get_release_ms");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectCompressor::set_mix(const double mix) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "set_mix");
	}
	___godot_icall_void_float(mb, (const Object *) this, mix);
}

double AudioEffectCompressor::get_mix() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "get_mix");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectCompressor::set_sidechain(const String sidechain) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "set_sidechain");
	}
	___godot_icall_void_String(mb, (const Object *) this, sidechain);
}

String AudioEffectCompressor::get_sidechain() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectCompressor", "get_sidechain");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}