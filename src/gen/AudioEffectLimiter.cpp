#include <AudioEffectLimiter.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectLimiter::___get_type_tag()
{
	return (void *) &AudioEffectLimiter::___get_type_tag;
}

void *AudioEffectLimiter::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectLimiter *AudioEffectLimiter::_new()
{
	return (AudioEffectLimiter *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectLimiter")());
}
void AudioEffectLimiter::set_ceiling_db(const double ceiling) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectLimiter", "set_ceiling_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, ceiling);
}

double AudioEffectLimiter::get_ceiling_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectLimiter", "get_ceiling_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectLimiter::set_threshold_db(const double threshold) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectLimiter", "set_threshold_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, threshold);
}

double AudioEffectLimiter::get_threshold_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectLimiter", "get_threshold_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectLimiter::set_soft_clip_db(const double soft_clip) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectLimiter", "set_soft_clip_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, soft_clip);
}

double AudioEffectLimiter::get_soft_clip_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectLimiter", "get_soft_clip_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void AudioEffectLimiter::set_soft_clip_ratio(const double soft_clip) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectLimiter", "set_soft_clip_ratio");
	}
	___godot_icall_void_float(mb, (const Object *) this, soft_clip);
}

double AudioEffectLimiter::get_soft_clip_ratio() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectLimiter", "get_soft_clip_ratio");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}