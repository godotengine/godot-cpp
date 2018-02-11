#ifndef GODOT_CPP_STREAMPEERBUFFER_HPP
#define GODOT_CPP_STREAMPEERBUFFER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <StreamPeer.hpp>
namespace godot {

class StreamPeerBuffer;

class StreamPeerBuffer : public StreamPeer {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "StreamPeerBuffer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static StreamPeerBuffer *_new();

	// methods
	void seek(const int64_t position);
	int64_t get_size() const;
	int64_t get_position() const;
	void resize(const int64_t size);
	void set_data_array(const PoolByteArray data);
	PoolByteArray get_data_array() const;
	void clear();
	Ref<StreamPeerBuffer> duplicate() const;

};

}

#endif