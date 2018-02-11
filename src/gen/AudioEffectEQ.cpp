#include <AudioEffectEQ.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectEQ::___get_type_tag()
{
	return (void *) &AudioEffectEQ::___get_type_tag;
}

void *AudioEffectEQ::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectEQ *AudioEffectEQ::_new()
{
	return (AudioEffectEQ *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectEQ")());
}
void AudioEffectEQ::set_band_gain_db(const int64_t band_idx, const double volume_db) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectEQ", "set_band_gain_db");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, band_idx, volume_db);
}

double AudioEffectEQ::get_band_gain_db(const int64_t band_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectEQ", "get_band_gain_db");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, band_idx);
}

int64_t AudioEffectEQ::get_band_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectEQ", "get_band_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}