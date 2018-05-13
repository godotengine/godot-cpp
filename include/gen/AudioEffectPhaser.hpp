#ifndef GODOT_CPP_AUDIOEFFECTPHASER_HPP
#define GODOT_CPP_AUDIOEFFECTPHASER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "AudioEffect.hpp"
namespace godot {


class AudioEffectPhaser : public AudioEffect {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioEffectPhaser"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AudioEffectPhaser *_new();

	// methods
	void set_range_min_hz(const double hz);
	double get_range_min_hz() const;
	void set_range_max_hz(const double hz);
	double get_range_max_hz() const;
	void set_rate_hz(const double hz);
	double get_rate_hz() const;
	void set_feedback(const double fbk);
	double get_feedback() const;
	void set_depth(const double depth);
	double get_depth() const;

};

}

#endif