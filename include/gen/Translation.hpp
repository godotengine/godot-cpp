#ifndef GODOT_CPP_TRANSLATION_HPP
#define GODOT_CPP_TRANSLATION_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {


class Translation : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Translation"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Translation *_new();

	// methods
	void set_locale(const String locale);
	String get_locale() const;
	void add_message(const String src_message, const String xlated_message);
	String get_message(const String src_message) const;
	void erase_message(const String src_message);
	PoolStringArray get_message_list() const;
	int64_t get_message_count() const;
	void _set_messages(const PoolStringArray arg0);
	PoolStringArray _get_messages() const;

};

}

#endif