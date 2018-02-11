#include <GDScriptFunctionState.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *GDScriptFunctionState::___get_type_tag()
{
	return (void *) &GDScriptFunctionState::___get_type_tag;
}

void *GDScriptFunctionState::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Variant GDScriptFunctionState::resume(const Variant arg) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDScriptFunctionState", "resume");
	}
	return ___godot_icall_Variant_Variant(mb, (const Object *) this, arg);
}

bool GDScriptFunctionState::is_valid(const bool extended_check) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDScriptFunctionState", "is_valid");
	}
	return ___godot_icall_bool_bool(mb, (const Object *) this, extended_check);
}

Variant GDScriptFunctionState::_signal_callback(const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GDScriptFunctionState", "_signal_callback");
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