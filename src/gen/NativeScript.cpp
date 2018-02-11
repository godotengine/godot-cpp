#include <NativeScript.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <GDNativeLibrary.hpp>
#include <Object.hpp>


namespace godot {


void *NativeScript::___get_type_tag()
{
	return (void *) &NativeScript::___get_type_tag;
}

void *NativeScript::___get_base_type_tag()
{
	return (void *) &Script::___get_type_tag;
}

NativeScript *NativeScript::_new()
{
	return (NativeScript *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"NativeScript")());
}
void NativeScript::set_class_name(const String class_name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NativeScript", "set_class_name");
	}
	___godot_icall_void_String(mb, (const Object *) this, class_name);
}

String NativeScript::get_class_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NativeScript", "get_class_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void NativeScript::set_library(const Ref<GDNativeLibrary> library) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NativeScript", "set_library");
	}
	___godot_icall_void_Object(mb, (const Object *) this, library.ptr());
}

Ref<GDNativeLibrary> NativeScript::get_library() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NativeScript", "get_library");
	}
	return Ref<GDNativeLibrary>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

String NativeScript::get_class_documentation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NativeScript", "get_class_documentation");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String NativeScript::get_method_documentation(const String method) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NativeScript", "get_method_documentation");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, method);
}

String NativeScript::get_signal_documentation(const String signal_name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NativeScript", "get_signal_documentation");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, signal_name);
}

String NativeScript::get_property_documentation(const String path) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NativeScript", "get_property_documentation");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, path);
}

Object *NativeScript::new_(const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NativeScript", "new");
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

}