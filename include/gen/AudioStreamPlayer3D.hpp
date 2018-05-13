#ifndef GODOT_CPP_AUDIOSTREAMPLAYER3D_HPP
#define GODOT_CPP_AUDIOSTREAMPLAYER3D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "AudioStreamPlayer3D.hpp"

#include "Spatial.hpp"
namespace godot {

class AudioStream;

class AudioStreamPlayer3D : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioStreamPlayer3D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum AttenuationModel {
		ATTENUATION_INVERSE_DISTANCE = 0,
		ATTENUATION_LOGARITHMIC = 2,
		ATTENUATION_INVERSE_SQUARE_DISTANCE = 1,
	};
	enum OutOfRangeMode {
		OUT_OF_RANGE_MIX = 0,
		OUT_OF_RANGE_PAUSE = 1,
	};
	enum DopplerTracking {
		DOPPLER_TRACKING_IDLE_STEP = 1,
		DOPPLER_TRACKING_PHYSICS_STEP = 2,
		DOPPLER_TRACKING_DISABLED = 0,
	};

	// constants


	static AudioStreamPlayer3D *_new();

	// methods
	void set_stream(const Ref<AudioStream> stream);
	Ref<AudioStream> get_stream() const;
	void set_unit_db(const double unit_db);
	double get_unit_db() const;
	void set_unit_size(const double unit_size);
	double get_unit_size() const;
	void set_max_db(const double max_db);
	double get_max_db() const;
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
	void _set_playing(const bool enable);
	bool _is_active() const;
	void set_max_distance(const double metres);
	double get_max_distance() const;
	void set_area_mask(const int64_t mask);
	int64_t get_area_mask() const;
	void set_emission_angle(const double degrees);
	double get_emission_angle() const;
	void set_emission_angle_enabled(const bool enabled);
	bool is_emission_angle_enabled() const;
	void set_emission_angle_filter_attenuation_db(const double db);
	double get_emission_angle_filter_attenuation_db() const;
	void set_attenuation_filter_cutoff_hz(const double degrees);
	double get_attenuation_filter_cutoff_hz() const;
	void set_attenuation_filter_db(const double db);
	double get_attenuation_filter_db() const;
	void set_attenuation_model(const int64_t model);
	AudioStreamPlayer3D::AttenuationModel get_attenuation_model() const;
	void set_out_of_range_mode(const int64_t mode);
	AudioStreamPlayer3D::OutOfRangeMode get_out_of_range_mode() const;
	void set_doppler_tracking(const int64_t mode);
	AudioStreamPlayer3D::DopplerTracking get_doppler_tracking() const;
	void _bus_layout_changed();

};

}

#endif