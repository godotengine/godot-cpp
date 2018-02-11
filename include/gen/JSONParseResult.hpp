#ifndef GODOT_CPP_JSONPARSERESULT_HPP
#define GODOT_CPP_JSONPARSERESULT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {


class JSONParseResult : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "JSONParseResult"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static JSONParseResult *_new();

	// methods
	Error get_error() const;
	String get_error_string() const;
	int64_t get_error_line() const;
	Variant get_result() const;
	void set_error(const int64_t error);
	void set_error_string(const String error_string);
	void set_error_line(const int64_t error_line);
	void set_result(const Variant result);

};

}

#endif