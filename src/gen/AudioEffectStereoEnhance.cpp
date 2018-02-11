#include <AudioEffectStereoEnhance.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectStereoEnhance::___get_type_tag()
{
	return (void *) &AudioEffectStereoEnhance::___get_type_tag;
}

void *AudioEffectStereoEnhance::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectStereoEnhance *AudioEffectStereoEnhance::_new()
{
	return (AudioEffectStereoEnhance *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectStereoEnhance")());
}
void AudioEffectStereoEnhance::set_pan_pullout(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectStereoEnhance", "set_pan_pullout");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectStereoEnhance::get_pan_pullout() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectStereoEnhance", "get_pan_pullout");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectStereoEnhance::set_time_pullout(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectStereoEnhance", "set_time_pullout");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectStereoEnhance::get_time_pullout() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectStereoEnhance", "get_time_pullout");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectStereoEnhance::set_surround(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectStereoEnhance", "set_surround");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectStereoEnhance::get_surround() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectStereoEnhance", "get_surround");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}