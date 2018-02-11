#ifndef GODOT_CPP_AUDIOEFFECTREVERB_HPP
#define GODOT_CPP_AUDIOEFFECTREVERB_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <AudioEffect.hpp>
namespace godot {


class AudioEffectReverb : public AudioEffect {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioEffectReverb"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AudioEffectReverb *_new();

	// methods
	void set_predelay_msec(const double msec);
	double get_predelay_msec() const;
	void set_predelay_feedback(const double feedback);
	double get_predelay_feedback() const;
	void set_room_size(const double size);
	double get_room_size() const;
	void set_damping(const double amount);
	double get_damping() const;
	void set_spread(const double amount);
	double get_spread() const;
	void set_dry(const double amount);
	double get_dry() const;
	void set_wet(const double amount);
	double get_wet() const;
	void set_hpf(const double amount);
	double get_hpf() const;

};

}

#endif