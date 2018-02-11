#include <World.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Environment.hpp>
#include <PhysicsDirectSpaceState.hpp>


namespace godot {


void *World::___get_type_tag()
{
	return (void *) &World::___get_type_tag;
}

void *World::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

World *World::_new()
{
	return (World *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"World")());
}
RID World::get_space() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("World", "get_space");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID World::get_scenario() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("World", "get_scenario");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void World::set_environment(const Ref<Environment> env) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("World", "set_environment");
	}
	___godot_icall_void_Object(mb, (const Object *) this, env.ptr());
}

Ref<Environment> World::get_environment() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("World", "get_environment");
	}
	return Ref<Environment>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void World::set_fallback_environment(const Ref<Environment> env) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("World", "set_fallback_environment");
	}
	___godot_icall_void_Object(mb, (const Object *) this, env.ptr());
}

Ref<Environment> World::get_fallback_environment() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("World", "get_fallback_environment");
	}
	return Ref<Environment>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

PhysicsDirectSpaceState *World::get_direct_space_state() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("World", "get_direct_space_state");
	}
	return (PhysicsDirectSpaceState *) ___godot_icall_Object(mb, (const Object *) this);
}

}