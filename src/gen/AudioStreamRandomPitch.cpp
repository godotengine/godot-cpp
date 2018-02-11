#include <AudioStreamRandomPitch.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <AudioStream.hpp>


namespace godot {


void *AudioStreamRandomPitch::___get_type_tag()
{
	return (void *) &AudioStreamRandomPitch::___get_type_tag;
}

void *AudioStreamRandomPitch::___get_base_type_tag()
{
	return (void *) &AudioStream::___get_type_tag;
}

AudioStreamRandomPitch *AudioStreamRandomPitch::_new()
{
	return (AudioStreamRandomPitch *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioStreamRandomPitch")());
}
void AudioStreamRandomPitch::set_audio_stream(const Ref<AudioStream> stream) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamRandomPitch", "set_audio_stream");
	}
	___godot_icall_void_Object(mb, (const Object *) this, stream.ptr());
}

Ref<AudioStream> AudioStreamRandomPitch::get_audio_stream() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamRandomPitch", "get_audio_stream");
	}
	return Ref<AudioStream>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void AudioStreamRandomPitch::set_random_pitch(const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamRandomPitch", "set_random_pitch");
	}
	___godot_icall_void_float(mb, (const Object *) this, scale);
}

double AudioStreamRandomPitch::get_random_pitch() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamRandomPitch", "get_random_pitch");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}