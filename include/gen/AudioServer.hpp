#ifndef GODOT_CPP_AUDIOSERVER_HPP
#define GODOT_CPP_AUDIOSERVER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <AudioServer.hpp>

#include <Object.hpp>
namespace godot {

class AudioEffect;
class AudioBusLayout;

class AudioServer : public Object {
	static AudioServer *_singleton;

	AudioServer();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline AudioServer *get_singleton()
	{
		if (!AudioServer::_singleton) {
			AudioServer::_singleton = new AudioServer;
		}
		return AudioServer::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "AudioServer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum SpeakerMode {
		SPEAKER_SURROUND_51 = 2,
		SPEAKER_SURROUND_71 = 3,
		SPEAKER_MODE_STEREO = 0,
	};

	// constants

	// methods
	void set_bus_count(const int64_t amount);
	int64_t get_bus_count() const;
	void remove_bus(const int64_t index);
	void add_bus(const int64_t at_position = -1);
	void move_bus(const int64_t index, const int64_t to_index);
	void set_bus_name(const int64_t bus_idx, const String name);
	String get_bus_name(const int64_t bus_idx) const;
	int64_t get_bus_index(const String bus_name) const;
	void set_bus_volume_db(const int64_t bus_idx, const double volume_db);
	double get_bus_volume_db(const int64_t bus_idx) const;
	void set_bus_send(const int64_t bus_idx, const String send);
	String get_bus_send(const int64_t bus_idx) const;
	void set_bus_solo(const int64_t bus_idx, const bool enable);
	bool is_bus_solo(const int64_t bus_idx) const;
	void set_bus_mute(const int64_t bus_idx, const bool enable);
	bool is_bus_mute(const int64_t bus_idx) const;
	void set_bus_bypass_effects(const int64_t bus_idx, const bool enable);
	bool is_bus_bypassing_effects(const int64_t bus_idx) const;
	void add_bus_effect(const int64_t bus_idx, const Ref<AudioEffect> effect, const int64_t at_position = -1);
	void remove_bus_effect(const int64_t bus_idx, const int64_t effect_idx);
	int64_t get_bus_effect_count(const int64_t bus_idx);
	Ref<AudioEffect> get_bus_effect(const int64_t bus_idx, const int64_t effect_idx);
	void swap_bus_effects(const int64_t bus_idx, const int64_t effect_idx, const int64_t by_effect_idx);
	void set_bus_effect_enabled(const int64_t bus_idx, const int64_t effect_idx, const bool enabled);
	bool is_bus_effect_enabled(const int64_t bus_idx, const int64_t effect_idx) const;
	double get_bus_peak_volume_left_db(const int64_t bus_idx, const int64_t channel) const;
	double get_bus_peak_volume_right_db(const int64_t bus_idx, const int64_t channel) const;
	void lock();
	void unlock();
	AudioServer::SpeakerMode get_speaker_mode() const;
	double get_mix_rate() const;
	void set_bus_layout(const Ref<AudioBusLayout> bus_layout);
	Ref<AudioBusLayout> generate_bus_layout() const;

};

}

#endif