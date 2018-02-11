#include <AudioStreamOGGVorbis.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioStreamOGGVorbis::___get_type_tag()
{
	return (void *) &AudioStreamOGGVorbis::___get_type_tag;
}

void *AudioStreamOGGVorbis::___get_base_type_tag()
{
	return (void *) &AudioStream::___get_type_tag;
}

AudioStreamOGGVorbis *AudioStreamOGGVorbis::_new()
{
	return (AudioStreamOGGVorbis *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioStreamOGGVorbis")());
}
void AudioStreamOGGVorbis::_set_data(const PoolByteArray data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamOGGVorbis", "_set_data");
	}
	___godot_icall_void_PoolByteArray(mb, (const Object *) this, data);
}

PoolByteArray AudioStreamOGGVorbis::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamOGGVorbis", "_get_data");
	}
	return ___godot_icall_PoolByteArray(mb, (const Object *) this);
}

void AudioStreamOGGVorbis::set_loop(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamOGGVorbis", "set_loop");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool AudioStreamOGGVorbis::has_loop() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamOGGVorbis", "has_loop");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioStreamOGGVorbis::set_loop_offset(const double seconds) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamOGGVorbis", "set_loop_offset");
	}
	___godot_icall_void_float(mb, (const Object *) this, seconds);
}

double AudioStreamOGGVorbis::get_loop_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamOGGVorbis", "get_loop_offset");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}