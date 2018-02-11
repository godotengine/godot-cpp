#include <VideoPlayer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <VideoStream.hpp>
#include <Texture.hpp>


namespace godot {


void *VideoPlayer::___get_type_tag()
{
	return (void *) &VideoPlayer::___get_type_tag;
}

void *VideoPlayer::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

VideoPlayer *VideoPlayer::_new()
{
	return (VideoPlayer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VideoPlayer")());
}
void VideoPlayer::set_stream(const Ref<VideoStream> stream) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "set_stream");
	}
	___godot_icall_void_Object(mb, (const Object *) this, stream.ptr());
}

Ref<VideoStream> VideoPlayer::get_stream() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "get_stream");
	}
	return Ref<VideoStream>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void VideoPlayer::play() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "play");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void VideoPlayer::stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool VideoPlayer::is_playing() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "is_playing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void VideoPlayer::set_paused(const bool paused) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "set_paused");
	}
	___godot_icall_void_bool(mb, (const Object *) this, paused);
}

bool VideoPlayer::is_paused() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "is_paused");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void VideoPlayer::set_volume(const double volume) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "set_volume");
	}
	___godot_icall_void_float(mb, (const Object *) this, volume);
}

double VideoPlayer::get_volume() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "get_volume");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void VideoPlayer::set_volume_db(const double db) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "set_volume_db");
	}
	___godot_icall_void_float(mb, (const Object *) this, db);
}

double VideoPlayer::get_volume_db() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "get_volume_db");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void VideoPlayer::set_audio_track(const int64_t track) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "set_audio_track");
	}
	___godot_icall_void_int(mb, (const Object *) this, track);
}

int64_t VideoPlayer::get_audio_track() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "get_audio_track");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String VideoPlayer::get_stream_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "get_stream_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VideoPlayer::set_stream_position(const double position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "set_stream_position");
	}
	___godot_icall_void_float(mb, (const Object *) this, position);
}

double VideoPlayer::get_stream_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "get_stream_position");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void VideoPlayer::set_autoplay(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "set_autoplay");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool VideoPlayer::has_autoplay() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "has_autoplay");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void VideoPlayer::set_expand(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "set_expand");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool VideoPlayer::has_expand() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "has_expand");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void VideoPlayer::set_buffering_msec(const int64_t msec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "set_buffering_msec");
	}
	___godot_icall_void_int(mb, (const Object *) this, msec);
}

int64_t VideoPlayer::get_buffering_msec() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "get_buffering_msec");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void VideoPlayer::set_bus(const String bus) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "set_bus");
	}
	___godot_icall_void_String(mb, (const Object *) this, bus);
}

String VideoPlayer::get_bus() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "get_bus");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

Ref<Texture> VideoPlayer::get_video_texture() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoPlayer", "get_video_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}