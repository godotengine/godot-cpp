#ifndef GODOT_CPP_WORLD_HPP
#define GODOT_CPP_WORLD_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {

class Environment;
class PhysicsDirectSpaceState;

class World : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "World"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static World *_new();

	// methods
	RID get_space() const;
	RID get_scenario() const;
	void set_environment(const Ref<Environment> env);
	Ref<Environment> get_environment() const;
	void set_fallback_environment(const Ref<Environment> env);
	Ref<Environment> get_fallback_environment() const;
	PhysicsDirectSpaceState *get_direct_space_state();

};

}

#endif