#include <VisualScriptFunctionState.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *VisualScriptFunctionState::___get_type_tag()
{
	return (void *) &VisualScriptFunctionState::___get_type_tag;
}

void *VisualScriptFunctionState::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

VisualScriptFunctionState *VisualScriptFunctionState::_new()
{
	return (VisualScriptFunctionState *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptFunctionState")());
}
void VisualScriptFunctionState::connect_to_signal(const Object *obj, const String signals, const Array args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionState", "connect_to_signal");
	}
	___godot_icall_void_Object_String_Array(mb, (const Object *) this, obj, signals, args);
}

Variant VisualScriptFunctionState::resume(const Array args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionState", "resume");
	}
	return ___godot_icall_Variant_Array(mb, (const Object *) this, args);
}

bool VisualScriptFunctionState::is_valid() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionState", "is_valid");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Variant VisualScriptFunctionState::_signal_callback(const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptFunctionState", "_signal_callback");
	}


	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 0));


	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 0] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 0), nullptr);


	return __result;
}

}