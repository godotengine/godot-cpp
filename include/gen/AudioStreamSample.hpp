#ifndef GODOT_CPP_AUDIOSTREAMSAMPLE_HPP
#define GODOT_CPP_AUDIOSTREAMSAMPLE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "AudioStreamSample.hpp"

#include "AudioStream.hpp"
namespace godot {


class AudioStreamSample : public AudioStream {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "AudioStreamSample"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum LoopMode {
		LOOP_PING_PONG = 2,
		LOOP_FORWARD = 1,
		LOOP_DISABLED = 0,
	};
	enum Format {
		FORMAT_8_BITS = 0,
		FORMAT_IMA_ADPCM = 2,
		FORMAT_16_BITS = 1,
	};

	// constants


	static AudioStreamSample *_new();

	// methods
	void set_format(const int64_t format);
	AudioStreamSample::Format get_format() const;
	void set_loop_mode(const int64_t loop_mode);
	AudioStreamSample::LoopMode get_loop_mode() const;
	void set_loop_begin(const int64_t loop_begin);
	int64_t get_loop_begin() const;
	void set_loop_end(const int64_t loop_end);
	int64_t get_loop_end() const;
	void set_mix_rate(const int64_t mix_rate);
	int64_t get_mix_rate() const;
	void set_stereo(const bool stereo);
	bool is_stereo() const;
	void _set_data(const PoolByteArray data);
	PoolByteArray _get_data() const;

};

}

#endif