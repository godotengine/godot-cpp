#include <WorldEnvironment.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Environment.hpp>


namespace godot {


void *WorldEnvironment::___get_type_tag()
{
	return (void *) &WorldEnvironment::___get_type_tag;
}

void *WorldEnvironment::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

WorldEnvironment *WorldEnvironment::_new()
{
	return (WorldEnvironment *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"WorldEnvironment")());
}
void WorldEnvironment::set_environment(const Ref<Environment> env) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WorldEnvironment", "set_environment");
	}
	___godot_icall_void_Object(mb, (const Object *) this, env.ptr());
}

Ref<Environment> WorldEnvironment::get_environment() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WorldEnvironment", "get_environment");
	}
	return Ref<Environment>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}