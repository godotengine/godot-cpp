#include <AudioEffectPhaser.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectPhaser::___get_type_tag()
{
	return (void *) &AudioEffectPhaser::___get_type_tag;
}

void *AudioEffectPhaser::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectPhaser *AudioEffectPhaser::_new()
{
	return (AudioEffectPhaser *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectPhaser")());
}
void AudioEffectPhaser::set_range_min_hz(const double hz) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPhaser", "set_range_min_hz");
	}
	___godot_icall_void_float(mb, (const Object *) this, hz);
}

double AudioEffectPhaser::get_range_min_hz() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPhaser", "get_range_min_hz");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectPhaser::set_range_max_hz(const double hz) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPhaser", "set_range_max_hz");
	}
	___godot_icall_void_float(mb, (const Object *) this, hz);
}

double AudioEffectPhaser::get_range_max_hz() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPhaser", "get_range_max_hz");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectPhaser::set_rate_hz(const double hz) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPhaser", "set_rate_hz");
	}
	___godot_icall_void_float(mb, (const Object *) this, hz);
}

double AudioEffectPhaser::get_rate_hz() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPhaser", "get_rate_hz");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectPhaser::set_feedback(const double fbk) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPhaser", "set_feedback");
	}
	___godot_icall_void_float(mb, (const Object *) this, fbk);
}

double AudioEffectPhaser::get_feedback() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPhaser", "get_feedback");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectPhaser::set_depth(const double depth) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPhaser", "set_depth");
	}
	___godot_icall_void_float(mb, (const Object *) this, depth);
}

double AudioEffectPhaser::get_depth() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPhaser", "get_depth");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}