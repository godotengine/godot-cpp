#ifndef GODOT_CPP_AUDIOEFFECTCHORUS_HPP
#define GODOT_CPP_AUDIOEFFECTCHORUS_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "AudioEffect.hpp"
namespace godot {


class AudioEffectChorus : public AudioEffect {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioEffectChorus"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AudioEffectChorus *_new();

	// methods
	void set_voice_count(const int64_t voices);
	int64_t get_voice_count() const;
	void set_voice_delay_ms(const int64_t voice_idx, const double delay_ms);
	double get_voice_delay_ms(const int64_t voice_idx) const;
	void set_voice_rate_hz(const int64_t voice_idx, const double rate_hz);
	double get_voice_rate_hz(const int64_t voice_idx) const;
	void set_voice_depth_ms(const int64_t voice_idx, const double depth_ms);
	double get_voice_depth_ms(const int64_t voice_idx) const;
	void set_voice_level_db(const int64_t voice_idx, const double level_db);
	double get_voice_level_db(const int64_t voice_idx) const;
	void set_voice_cutoff_hz(const int64_t voice_idx, const double cutoff_hz);
	double get_voice_cutoff_hz(const int64_t voice_idx) const;
	void set_voice_pan(const int64_t voice_idx, const double pan);
	double get_voice_pan(const int64_t voice_idx) const;
	void set_wet(const double amount);
	double get_wet() const;
	void set_dry(const double amount);
	double get_dry() const;

};

}

#endif