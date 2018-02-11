#ifndef GODOT_CPP_AUDIOSTREAMPLAYER_HPP
#define GODOT_CPP_AUDIOSTREAMPLAYER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <AudioStreamPlayer.hpp>

#include <Node.hpp>
namespace godot {

class AudioStream;

class AudioStreamPlayer : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioStreamPlayer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum MixTarget {
		MIX_TARGET_SURROUND = 1,
		MIX_TARGET_CENTER = 2,
		MIX_TARGET_STEREO = 0,
	};

	// constants


	static AudioStreamPlayer *_new();

	// methods
	void set_stream(const Ref<AudioStream> stream);
	Ref<AudioStream> get_stream() const;
	void set_volume_db(const double volume_db);
	double get_volume_db() const;
	void set_pitch_scale(const double pitch_scale);
	double get_pitch_scale() const;
	void play(const double from_position = 0);
	void seek(const double to_position);
	void stop();
	bool is_playing() const;
	double get_playback_position();
	void set_bus(const String bus);
	String get_bus() const;
	void set_autoplay(const bool enable);
	bool is_autoplay_enabled();
	void set_mix_target(const int64_t mix_target);
	AudioStreamPlayer::MixTarget get_mix_target() const;
	void _set_playing(const bool enable);
	bool _is_active() const;
	void _bus_layout_changed();

};

}

#endif