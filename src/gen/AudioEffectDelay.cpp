#include <AudioEffectDelay.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectDelay::___get_type_tag()
{
	return (void *) &AudioEffectDelay::___get_type_tag;
}

void *AudioEffectDelay::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectDelay *AudioEffectDelay::_new()
{
	return (AudioEffectDelay *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectDelay")());
}
void AudioEffectDelay::set_dry(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_dry");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectDelay::get_dry() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "get_dry");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDelay::set_tap1_active(const bool amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_tap1_active");
	}
	___godot_icall_void_bool(mb, (const Object *) this, amount);
}

bool AudioEffectDelay::is_tap1_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "is_tap1_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioEffectDelay::set_tap1_delay_ms(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_tap1_delay_ms");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectDelay::get_tap1_delay_ms() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "get_tap1_delay_ms");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDelay::set_tap1_level_db(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_tap1_level_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectDelay::get_tap1_level_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "get_tap1_level_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDelay::set_tap1_pan(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_tap1_pan");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectDelay::get_tap1_pan() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "get_tap1_pan");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDelay::set_tap2_active(const bool amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_tap2_active");
	}
	___godot_icall_void_bool(mb, (const Object *) this, amount);
}

bool AudioEffectDelay::is_tap2_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "is_tap2_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioEffectDelay::set_tap2_delay_ms(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_tap2_delay_ms");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectDelay::get_tap2_delay_ms() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "get_tap2_delay_ms");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDelay::set_tap2_level_db(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_tap2_level_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectDelay::get_tap2_level_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "get_tap2_level_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDelay::set_tap2_pan(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_tap2_pan");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectDelay::get_tap2_pan() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "get_tap2_pan");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDelay::set_feedback_active(const bool amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_feedback_active");
	}
	___godot_icall_void_bool(mb, (const Object *) this, amount);
}

bool AudioEffectDelay::is_feedback_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "is_feedback_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioEffectDelay::set_feedback_delay_ms(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_feedback_delay_ms");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectDelay::get_feedback_delay_ms() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "get_feedback_delay_ms");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDelay::set_feedback_level_db(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_feedback_level_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectDelay::get_feedback_level_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "get_feedback_level_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDelay::set_feedback_lowpass(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "set_feedback_lowpass");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectDelay::get_feedback_lowpass() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDelay", "get_feedback_lowpass");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}