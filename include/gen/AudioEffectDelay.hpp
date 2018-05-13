#ifndef GODOT_CPP_AUDIOEFFECTDELAY_HPP
#define GODOT_CPP_AUDIOEFFECTDELAY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "AudioEffect.hpp"
namespace godot {


class AudioEffectDelay : public AudioEffect {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioEffectDelay"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AudioEffectDelay *_new();

	// methods
	void set_dry(const double amount);
	double get_dry();
	void set_tap1_active(const bool amount);
	bool is_tap1_active() const;
	void set_tap1_delay_ms(const double amount);
	double get_tap1_delay_ms() const;
	void set_tap1_level_db(const double amount);
	double get_tap1_level_db() const;
	void set_tap1_pan(const double amount);
	double get_tap1_pan() const;
	void set_tap2_active(const bool amount);
	bool is_tap2_active() const;
	void set_tap2_delay_ms(const double amount);
	double get_tap2_delay_ms() const;
	void set_tap2_level_db(const double amount);
	double get_tap2_level_db() const;
	void set_tap2_pan(const double amount);
	double get_tap2_pan() const;
	void set_feedback_active(const bool amount);
	bool is_feedback_active() const;
	void set_feedback_delay_ms(const double amount);
	double get_feedback_delay_ms() const;
	void set_feedback_level_db(const double amount);
	double get_feedback_level_db() const;
	void set_feedback_lowpass(const double amount);
	double get_feedback_lowpass() const;

};

}

#endif