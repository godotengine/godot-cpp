#include <Marshalls.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Marshalls::___get_type_tag()
{
	return (void *) &Marshalls::___get_type_tag;
}

void *Marshalls::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

Marshalls *Marshalls::_singleton = NULL;


Marshalls::Marshalls() {
	_owner = godot::api->godot_global_get_singleton((char *) "Marshalls");
}


String Marshalls::variant_to_base64(const Variant variant) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Marshalls", "variant_to_base64");
	}
	return ___godot_icall_String_Variant(mb, (const Object *) this, variant);
}

Variant Marshalls::base64_to_variant(const String base64_str) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Marshalls", "base64_to_variant");
	}
	return ___godot_icall_Variant_String(mb, (const Object *) this, base64_str);
}

String Marshalls::raw_to_base64(const PoolByteArray array) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Marshalls", "raw_to_base64");
	}
	return ___godot_icall_String_PoolByteArray(mb, (const Object *) this, array);
}

PoolByteArray Marshalls::base64_to_raw(const String base64_str) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Marshalls", "base64_to_raw");
	}
	return ___godot_icall_PoolByteArray_String(mb, (const Object *) this, base64_str);
}

String Marshalls::utf8_to_base64(const String utf8_str) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Marshalls", "utf8_to_base64");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, utf8_str);
}

String Marshalls::base64_to_utf8(const String base64_str) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Marshalls", "base64_to_utf8");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, base64_str);
}

}