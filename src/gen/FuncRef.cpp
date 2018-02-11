#include <FuncRef.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *FuncRef::___get_type_tag()
{
	return (void *) &FuncRef::___get_type_tag;
}

void *FuncRef::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

FuncRef *FuncRef::_new()
{
	return (FuncRef *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"FuncRef")());
}
Variant FuncRef::call_func(const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FuncRef", "call_func");
	}


	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 0));


	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 0] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 0), nullptr);


	return __result;
}

void FuncRef::set_instance(const Object *instance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FuncRef", "set_instance");
	}
	___godot_icall_void_Object(mb, (const Object *) this, instance);
}

void FuncRef::set_function(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("FuncRef", "set_function");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

}