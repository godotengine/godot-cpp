#ifndef GODOT_CPP_AUDIOSTREAMRANDOMPITCH_HPP
#define GODOT_CPP_AUDIOSTREAMRANDOMPITCH_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <AudioStream.hpp>
namespace godot {

class AudioStream;

class AudioStreamRandomPitch : public AudioStream {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioStreamRandomPitch"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static AudioStreamRandomPitch *_new();

	// methods
	void set_audio_stream(const Ref<AudioStream> stream);
	Ref<AudioStream> get_audio_stream() const;
	void set_random_pitch(const double scale);
	double get_random_pitch() const;

};

}

#endif