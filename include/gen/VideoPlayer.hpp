#ifndef GODOT_CPP_VIDEOPLAYER_HPP
#define GODOT_CPP_VIDEOPLAYER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Control.hpp>
namespace godot {

class VideoStream;
class Texture;

class VideoPlayer : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VideoPlayer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static VideoPlayer *_new();

	// methods
	void set_stream(const Ref<VideoStream> stream);
	Ref<VideoStream> get_stream() const;
	void play();
	void stop();
	bool is_playing() const;
	void set_paused(const bool paused);
	bool is_paused() const;
	void set_volume(const double volume);
	double get_volume() const;
	void set_volume_db(const double db);
	double get_volume_db() const;
	void set_audio_track(const int64_t track);
	int64_t get_audio_track() const;
	String get_stream_name() const;
	void set_stream_position(const double position);
	double get_stream_position() const;
	void set_autoplay(const bool enabled);
	bool has_autoplay() const;
	void set_expand(const bool enable);
	bool has_expand() const;
	void set_buffering_msec(const int64_t msec);
	int64_t get_buffering_msec() const;
	void set_bus(const String bus);
	String get_bus() const;
	Ref<Texture> get_video_texture();

};

}

#endif