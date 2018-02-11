#ifndef GODOT_CPP_SCRIPT_HPP
#define GODOT_CPP_SCRIPT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {

class Object;
class Script;

class Script : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Script"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	bool can_instance() const;
	bool instance_has(const Object *base_object) const;
	bool has_source_code() const;
	String get_source_code() const;
	void set_source_code(const String source);
	Error reload(const bool keep_state = false);
	Ref<Script> get_base_script() const;
	String get_instance_base_type() const;
	bool has_script_signal(const String signal_name) const;
	bool is_tool() const;

};

}

#endif