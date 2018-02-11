#include <AudioEffectPanner.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioEffectPanner::___get_type_tag()
{
	return (void *) &AudioEffectPanner::___get_type_tag;
}

void *AudioEffectPanner::___get_base_type_tag()
{
	return (void *) &AudioEffect::___get_type_tag;
}

AudioEffectPanner *AudioEffectPanner::_new()
{
	return (AudioEffectPanner *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioEffectPanner")());
}
void AudioEffectPanner::set_pan(const double cpanume) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPanner", "set_pan");
	}
	___godot_icall_void_float(mb, (const Object *) this, cpanume);
}

double AudioEffectPanner::get_pan() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioEffectPanner", "get_pan");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}