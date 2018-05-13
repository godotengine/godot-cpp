#ifndef GODOT_CPP_AUDIOEFFECTSTEREOENHANCE_HPP
#define GODOT_CPP_AUDIOEFFECTSTEREOENHANCE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "AudioEffect.hpp"
namespace godot {


class AudioEffectStereoEnhance : public AudioEffect {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioEffectStereoEnhance"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AudioEffectStereoEnhance *_new();

	// methods
	void set_pan_pullout(const double amount);
	double get_pan_pullout() const;
	void set_time_pullout(const double amount);
	double get_time_pullout() const;
	void set_surround(const double amount);
	double get_surround() const;

};

}

#endif