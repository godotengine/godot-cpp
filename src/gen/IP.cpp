#include <IP.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *IP::___get_type_tag()
{
	return (void *) &IP::___get_type_tag;
}

void *IP::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

IP *IP::_singleton = NULL;


IP::IP() {
	_owner = godot::api->godot_global_get_singleton((char *) "IP");
}


String IP::resolve_hostname(const String host, const int64_t ip_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("IP", "resolve_hostname");
	}
	return ___godot_icall_String_String_int(mb, (const Object *) this, host, ip_type);
}

int64_t IP::resolve_hostname_queue_item(const String host, const int64_t ip_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("IP", "resolve_hostname_queue_item");
	}
	return ___godot_icall_int_String_int(mb, (const Object *) this, host, ip_type);
}

IP::ResolverStatus IP::get_resolve_item_status(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("IP", "get_resolve_item_status");
	}
	return (IP::ResolverStatus) ___godot_icall_int_int(mb, (const Object *) this, id);
}

String IP::get_resolve_item_address(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("IP", "get_resolve_item_address");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, id);
}

void IP::erase_resolve_item(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("IP", "erase_resolve_item");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

Array IP::get_local_addresses() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("IP", "get_local_addresses");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void IP::clear_cache(const String hostname) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("IP", "clear_cache");
	}
	___godot_icall_void_String(mb, (const Object *) this, hostname);
}

}