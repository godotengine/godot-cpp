#include <JavaScript.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *JavaScript::___get_type_tag()
{
	return (void *) &JavaScript::___get_type_tag;
}

void *JavaScript::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

JavaScript *JavaScript::_singleton = NULL;


JavaScript::JavaScript() {
	_owner = godot::api->godot_global_get_singleton((char *) "JavaScript");
}


Variant JavaScript::eval(const String code, const bool use_global_execution_context) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("JavaScript", "eval");
	}
	return ___godot_icall_Variant_String_bool(mb, (const Object *) this, code, use_global_execution_context);
}

}