#ifndef GODOT_CPP_AUDIOEFFECTDISTORTION_HPP
#define GODOT_CPP_AUDIOEFFECTDISTORTION_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "AudioEffectDistortion.hpp"

#include "AudioEffect.hpp"
namespace godot {


class AudioEffectDistortion : public AudioEffect {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioEffectDistortion"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Mode {
		MODE_OVERDRIVE = 3,
		MODE_LOFI = 2,
		MODE_ATAN = 1,
		MODE_WAVESHAPE = 4,
		MODE_CLIP = 0,
	};

	// constants


	static AudioEffectDistortion *_new();

	// methods
	void set_mode(const int64_t mode);
	AudioEffectDistortion::Mode get_mode() const;
	void set_pre_gain(const double pre_gain);
	double get_pre_gain() const;
	void set_keep_hf_hz(const double keep_hf_hz);
	double get_keep_hf_hz() const;
	void set_drive(const double drive);
	double get_drive() const;
	void set_post_gain(const double post_gain);
	double get_post_gain() const;

};

}

#endif