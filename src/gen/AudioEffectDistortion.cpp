#include <AudioEffectDistortion.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectDistortion::___get_type_tag()
{
	return (void *) &AudioEffectDistortion::___get_type_tag;
}

void *AudioEffectDistortion::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectDistortion *AudioEffectDistortion::_new()
{
	return (AudioEffectDistortion *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectDistortion")());
}
void AudioEffectDistortion::set_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDistortion", "set_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

AudioEffectDistortion::Mode AudioEffectDistortion::get_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDistortion", "get_mode");
	}
	return (AudioEffectDistortion::Mode) ___godot_icall_int(mb, (const Object *) this);
}

void AudioEffectDistortion::set_pre_gain(const double pre_gain) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDistortion", "set_pre_gain");
	}
	___godot_icall_void_float(mb, (const Object *) this, pre_gain);
}

double AudioEffectDistortion::get_pre_gain() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDistortion", "get_pre_gain");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDistortion::set_keep_hf_hz(const double keep_hf_hz) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDistortion", "set_keep_hf_hz");
	}
	___godot_icall_void_float(mb, (const Object *) this, keep_hf_hz);
}

double AudioEffectDistortion::get_keep_hf_hz() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDistortion", "get_keep_hf_hz");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDistortion::set_drive(const double drive) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDistortion", "set_drive");
	}
	___godot_icall_void_float(mb, (const Object *) this, drive);
}

double AudioEffectDistortion::get_drive() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDistortion", "get_drive");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectDistortion::set_post_gain(const double post_gain) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDistortion", "set_post_gain");
	}
	___godot_icall_void_float(mb, (const Object *) this, post_gain);
}

double AudioEffectDistortion::get_post_gain() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectDistortion", "get_post_gain");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}