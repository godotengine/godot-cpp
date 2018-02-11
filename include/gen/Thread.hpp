#ifndef GODOT_CPP_THREAD_HPP
#define GODOT_CPP_THREAD_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class Object;

class Thread : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Thread"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Priority {
		PRIORITY_NORMAL = 1,
		PRIORITY_HIGH = 2,
		PRIORITY_LOW = 0,
	};

	// constants


	static Thread *_new();

	// methods
	Error start(const Object *instance, const String method, const Variant userdata = Variant(), const int64_t priority = 1);
	String get_id() const;
	bool is_active() const;
	Variant wait_to_finish();

};

}

#endif