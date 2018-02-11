#include <AudioEffectFilter.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectFilter::___get_type_tag()
{
	return (void *) &AudioEffectFilter::___get_type_tag;
}

void *AudioEffectFilter::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectFilter *AudioEffectFilter::_new()
{
	return (AudioEffectFilter *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectFilter")());
}
void AudioEffectFilter::set_cutoff(const double freq) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectFilter", "set_cutoff");
	}
	___godot_icall_void_float(mb, (const Object *) this, freq);
}

double AudioEffectFilter::get_cutoff() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectFilter", "get_cutoff");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectFilter::set_resonance(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectFilter", "set_resonance");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectFilter::get_resonance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectFilter", "get_resonance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectFilter::set_gain(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectFilter", "set_gain");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double AudioEffectFilter::get_gain() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectFilter", "get_gain");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectFilter::set_db(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectFilter", "set_db");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

AudioEffectFilter::FilterDB AudioEffectFilter::get_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectFilter", "get_db");
	}
	return (AudioEffectFilter::FilterDB) ___godot_icall_int(mb, (const Object *) this);
}

}