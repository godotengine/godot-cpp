#ifndef GODOT_CPP_AUDIOEFFECTLIMITER_HPP
#define GODOT_CPP_AUDIOEFFECTLIMITER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "AudioEffect.hpp"
namespace godot {


class AudioEffectLimiter : public AudioEffect {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioEffectLimiter"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AudioEffectLimiter *_new();

	// methods
	void set_ceiling_db(const double ceiling);
	double get_ceiling_db() const;
	void set_threshold_db(const double threshold);
	double get_threshold_db() const;
	void set_soft_clip_db(const double soft_clip);
	double get_soft_clip_db() const;
	void set_soft_clip_ratio(const double soft_clip);
	double get_soft_clip_ratio() const;

};

}

#endif