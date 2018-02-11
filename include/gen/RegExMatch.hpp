#ifndef GODOT_CPP_REGEXMATCH_HPP
#define GODOT_CPP_REGEXMATCH_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {


class RegExMatch : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "RegExMatch"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static RegExMatch *_new();

	// methods
	String get_subject() const;
	int64_t get_group_count() const;
	Dictionary get_names() const;
	Array get_strings() const;
	String get_string(const Variant name = 0) const;
	int64_t get_start(const Variant name = 0) const;
	int64_t get_end(const Variant name = 0) const;

};

}

#endif