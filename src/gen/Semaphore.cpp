#include <Semaphore.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Semaphore::___get_type_tag()
{
	return (void *) &Semaphore::___get_type_tag;
}

void *Semaphore::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Semaphore *Semaphore::_new()
{
	return (Semaphore *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"_Semaphore")());
}
Error Semaphore::wait() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Semaphore", "wait");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

Error Semaphore::post() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Semaphore", "post");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

}