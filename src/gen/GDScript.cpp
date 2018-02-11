#include <GDScript.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *GDScript::___get_type_tag()
{
	return (void *) &GDScript::___get_type_tag;
}

void *GDScript::___get_base_type_tag()
{
	return (void *) &Script::___get_type_tag;
}

GDScript *GDScript::_new()
{
	return (GDScript *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"GDScript")());
}
Object *GDScript::new_(const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDScript", "new");
	}


	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 0));


	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 0] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 0), nullptr);

	Object *obj = Object::___get_from_variant(__result);
	if (obj->has_method("reference"))
		obj->callv("reference", Array());


	return (Object *) Object::___get_from_variant(__result);
}

PoolByteArray GDScript::get_as_byte_code() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDScript", "get_as_byte_code");
	}
	return ___godot_icall_PoolByteArray(mb, (const Object *) this);
}

}