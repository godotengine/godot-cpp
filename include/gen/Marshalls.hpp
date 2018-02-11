#ifndef GODOT_CPP_MARSHALLS_HPP
#define GODOT_CPP_MARSHALLS_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {


class Marshalls : public Reference {
	static Marshalls *_singleton;

	Marshalls();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline Marshalls *get_singleton()
	{
		if (!Marshalls::_singleton) {
			Marshalls::_singleton = new Marshalls;
		}
		return Marshalls::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "Marshalls"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	String variant_to_base64(const Variant variant);
	Variant base64_to_variant(const String base64_str);
	String raw_to_base64(const PoolByteArray array);
	PoolByteArray base64_to_raw(const String base64_str);
	String utf8_to_base64(const String utf8_str);
	String base64_to_utf8(const String base64_str);

};

}

#endif