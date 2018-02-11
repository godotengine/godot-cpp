#ifndef GODOT_CPP_AUDIOEFFECTEQ_HPP
#define GODOT_CPP_AUDIOEFFECTEQ_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <AudioEffect.hpp>
namespace godot {


class AudioEffectEQ : public AudioEffect {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioEffectEQ"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AudioEffectEQ *_new();

	// methods
	void set_band_gain_db(const int64_t band_idx, const double volume_db);
	double get_band_gain_db(const int64_t band_idx) const;
	int64_t get_band_count() const;

};

}

#endif