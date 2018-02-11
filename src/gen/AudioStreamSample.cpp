#include <AudioStreamSample.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioStreamSample::___get_type_tag()
{
	return (void *) &AudioStreamSample::___get_type_tag;
}

void *AudioStreamSample::___get_base_type_tag()
{
	return (void *) &AudioStream::___get_type_tag;
}

AudioStreamSample *AudioStreamSample::_new()
{
	return (AudioStreamSample *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AudioStreamSample")());
}
void AudioStreamSample::set_format(const int64_t format) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "set_format");
	}
	___godot_icall_void_int(mb, (const Object *) this, format);
}

AudioStreamSample::Format AudioStreamSample::get_format() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "get_format");
	}
	return (AudioStreamSample::Format) ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamSample::set_loop_mode(const int64_t loop_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "set_loop_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, loop_mode);
}

AudioStreamSample::LoopMode AudioStreamSample::get_loop_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "get_loop_mode");
	}
	return (AudioStreamSample::LoopMode) ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamSample::set_loop_begin(const int64_t loop_begin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "set_loop_begin");
	}
	___godot_icall_void_int(mb, (const Object *) this, loop_begin);
}

int64_t AudioStreamSample::get_loop_begin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "get_loop_begin");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamSample::set_loop_end(const int64_t loop_end) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "set_loop_end");
	}
	___godot_icall_void_int(mb, (const Object *) this, loop_end);
}

int64_t AudioStreamSample::get_loop_end() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "get_loop_end");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamSample::set_mix_rate(const int64_t mix_rate) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "set_mix_rate");
	}
	___godot_icall_void_int(mb, (const Object *) this, mix_rate);
}

int64_t AudioStreamSample::get_mix_rate() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "get_mix_rate");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void AudioStreamSample::set_stereo(const bool stereo) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "set_stereo");
	}
	___godot_icall_void_bool(mb, (const Object *) this, stereo);
}

bool AudioStreamSample::is_stereo() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "is_stereo");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void AudioStreamSample::_set_data(const PoolByteArray data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "_set_data");
	}
	___godot_icall_void_PoolByteArray(mb, (const Object *) this, data);
}

PoolByteArray AudioStreamSample::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStreamSample", "_get_data");
	}
	return ___godot_icall_PoolByteArray(mb, (const Object *) this);
}

}