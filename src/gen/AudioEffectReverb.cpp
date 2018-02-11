#include <AudioEffectReverb.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectReverb::___get_type_tag()
{
	return (void *) &AudioEffectReverb::___get_type_tag;
}

void *AudioEffectReverb::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectReverb *AudioEffectReverb::_new()
{
	return (AudioEffectReverb *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectReverb")());
}
void AudioEffectReverb::set_predelay_msec(const double msec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "set_predelay_msec");
	}
	___godot_icall_void_float(mb, (const Object *) this, msec);
}

double AudioEffectReverb::get_predelay_msec() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "get_predelay_msec");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectReverb::set_predelay_feedback(const double feedback) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "set_predelay_feedback");
	}
	___godot_icall_void_float(mb, (const Object *) this, feedback);
}

double AudioEffectReverb::get_predelay_feedback() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "get_predelay_feedback");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectReverb::set_room_size(const double size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "set_room_size");
	}
	___godot_icall_void_float(mb, (const Object *) this, size);
}

double AudioEffectReverb::get_room_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "get_room_size");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectReverb::set_damping(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "set_damping");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectReverb::get_damping() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "get_damping");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectReverb::set_spread(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "set_spread");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectReverb::get_spread() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "get_spread");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectReverb::set_dry(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "set_dry");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectReverb::get_dry() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "get_dry");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectReverb::set_wet(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "set_wet");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectReverb::get_wet() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "get_wet");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectReverb::set_hpf(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "set_hpf");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectReverb::get_hpf() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectReverb", "get_hpf");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}