#ifndef GODOT_CPP_STREAMPEER_HPP
#define GODOT_CPP_STREAMPEER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Reference.hpp"
namespace godot {


class StreamPeer : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "StreamPeer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	Error put_data(const PoolByteArray data);
	Array put_partial_data(const PoolByteArray data);
	Array get_data(const int64_t bytes);
	Array get_partial_data(const int64_t bytes);
	int64_t get_available_bytes() const;
	void set_big_endian(const bool enable);
	bool is_big_endian_enabled() const;
	void put_8(const int64_t value);
	void put_u8(const int64_t value);
	void put_16(const int64_t value);
	void put_u16(const int64_t value);
	void put_32(const int64_t value);
	void put_u32(const int64_t value);
	void put_64(const int64_t value);
	void put_u64(const int64_t value);
	void put_float(const double value);
	void put_double(const double value);
	void put_utf8_string(const String value);
	void put_var(const Variant value);
	int64_t get_8();
	int64_t get_u8();
	int64_t get_16();
	int64_t get_u16();
	int64_t get_32();
	int64_t get_u32();
	int64_t get_64();
	int64_t get_u64();
	double get_float();
	double get_double();
	String get_string(const int64_t bytes);
	String get_utf8_string(const int64_t bytes);
	Variant get_var();

};

}

#endif