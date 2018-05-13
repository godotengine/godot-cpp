#ifndef GODOT_CPP_JSON_HPP
#define GODOT_CPP_JSON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Object.hpp"
namespace godot {

class JSONParseResult;

class JSON : public Object {
	static JSON *_singleton;

	JSON();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline JSON *get_singleton()
	{
		if (!JSON::_singleton) {
			JSON::_singleton = new JSON;
		}
		return JSON::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "JSON"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	String print(const Variant value, const String indent = "", const bool sort_keys = false);
	Ref<JSONParseResult> parse(const String json);

};

}

#endif