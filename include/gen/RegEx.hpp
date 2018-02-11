#ifndef GODOT_CPP_REGEX_HPP
#define GODOT_CPP_REGEX_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class RegExMatch;

class RegEx : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "RegEx"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static RegEx *_new();

	// methods
	void clear();
	Error compile(const String pattern);
	Ref<RegExMatch> search(const String subject, const int64_t offset = 0, const int64_t end = -1) const;
	Array search_all(const String subject, const int64_t offset = 0, const int64_t end = -1) const;
	String sub(const String subject, const String replacement, const bool all = false, const int64_t offset = 0, const int64_t end = -1) const;
	bool is_valid() const;
	String get_pattern() const;
	int64_t get_group_count() const;
	Array get_names() const;

};

}

#endif