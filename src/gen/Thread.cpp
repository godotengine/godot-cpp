#include <Thread.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *Thread::___get_type_tag()
{
	return (void *) &Thread::___get_type_tag;
}

void *Thread::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Thread *Thread::_new()
{
	return (Thread *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"_Thread")());
}
Error Thread::start(const Object *instance, const String method, const Variant userdata, const int64_t priority) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Thread", "start");
	}
	return (Error) ___godot_icall_int_Object_String_Variant_int(mb, (const Object *) this, instance, method, userdata, priority);
}

String Thread::get_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Thread", "get_id");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool Thread::is_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Thread", "is_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Variant Thread::wait_to_finish() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Thread", "wait_to_finish");
	}
	return ___godot_icall_Variant(mb, (const Object *) this);
}

}