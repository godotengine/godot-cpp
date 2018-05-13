#ifndef GODOT_CPP_CLASSDB_HPP
#define GODOT_CPP_CLASSDB_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Object.hpp"
namespace godot {

class Object;

class ClassDB : public Object {
	static ClassDB *_singleton;

	ClassDB();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline ClassDB *get_singleton()
	{
		if (!ClassDB::_singleton) {
			ClassDB::_singleton = new ClassDB;
		}
		return ClassDB::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "ClassDB"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	PoolStringArray get_class_list() const;
	PoolStringArray get_inheriters_from_class(const String _class) const;
	String get_parent_class(const String _class) const;
	bool class_exists(const String _class) const;
	bool is_parent_class(const String _class, const String inherits) const;
	bool can_instance(const String _class) const;
	Variant instance(const String _class) const;
	bool class_has_signal(const String _class, const String signal) const;
	Dictionary class_get_signal(const String _class, const String signal) const;
	Array class_get_signal_list(const String _class, const bool no_inheritance = false) const;
	Array class_get_property_list(const String _class, const bool no_inheritance = false) const;
	Variant class_get_property(const Object *object, const String property) const;
	Error class_set_property(const Object *object, const String property, const Variant value) const;
	bool class_has_method(const String _class, const String method, const bool no_inheritance = false) const;
	Array class_get_method_list(const String _class, const bool no_inheritance = false) const;
	PoolStringArray class_get_integer_constant_list(const String _class, const bool no_inheritance = false) const;
	bool class_has_integer_constant(const String _class, const String name) const;
	int64_t class_get_integer_constant(const String _class, const String name) const;
	String class_get_category(const String _class) const;
	bool is_class_enabled(const String _class) const;

};

}

#endif