#include <Mutex.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Mutex::___get_type_tag()
{
	return (void *) &Mutex::___get_type_tag;
}

void *Mutex::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Mutex *Mutex::_new()
{
	return (Mutex *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"_Mutex")());
}
void Mutex::lock() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Mutex", "lock");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Error Mutex::try_lock() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Mutex", "try_lock");
	}
	return (Error) ___godot_icall_int(mb, (const Object *) this);
}

void Mutex::unlock() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Mutex", "unlock");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}