#ifndef GODOT_CPP_AUDIOEFFECTCOMPRESSOR_HPP
#define GODOT_CPP_AUDIOEFFECTCOMPRESSOR_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <AudioEffect.hpp>
namespace godot {


class AudioEffectCompressor : public AudioEffect {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioEffectCompressor"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AudioEffectCompressor *_new();

	// methods
	void set_threshold(const double threshold);
	double get_threshold() const;
	void set_ratio(const double ratio);
	double get_ratio() const;
	void set_gain(const double gain);
	double get_gain() const;
	void set_attack_us(const double attack_us);
	double get_attack_us() const;
	void set_release_ms(const double release_ms);
	double get_release_ms() const;
	void set_mix(const double mix);
	double get_mix() const;
	void set_sidechain(const String sidechain);
	String get_sidechain() const;

};

}

#endif