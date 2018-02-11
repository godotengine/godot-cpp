#include <JSON.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <JSONParseResult.hpp>


namespace godot {


void *JSON::___get_type_tag()
{
	return (void *) &JSON::___get_type_tag;
}

void *JSON::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

JSON *JSON::_singleton = NULL;


JSON::JSON() {
	_owner = godot::api->godot_global_get_singleton((char *) "JSON");
}


String JSON::print(const Variant value, const String indent, const bool sort_keys) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_JSON", "print");
	}
	return ___godot_icall_String_Variant_String_bool(mb, (const Object *) this, value, indent, sort_keys);
}

Ref<JSONParseResult> JSON::parse(const String json) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_JSON", "parse");
	}
	return Ref<JSONParseResult>::__internal_constructor(___godot_icall_Object_String(mb, (const Object *) this, json));
}

}