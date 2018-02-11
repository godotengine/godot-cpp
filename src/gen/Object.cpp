#include <Object.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Reference.hpp>
#include <Object.hpp>


namespace godot {


void *Object::___get_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

void *Object::___get_base_type_tag()
{
	return (void *) nullptr;
}

Object *Object::_new()
{
	return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Object")());
}
void Object::free() {
	godot::api->godot_object_destroy(_owner);
}

void Object::_notification(const int64_t what) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "_notification");
	}
	___godot_icall_void_int(mb, (const Object *) this, what);
}

bool Object::_set(const String property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "_set");
	}
	return ___godot_icall_bool_String_Variant(mb, (const Object *) this, property, value);
}

void Object::_get(const String property) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "_get");
	}
	___godot_icall_void_String(mb, (const Object *) this, property);
}

Array Object::_get_property_list() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "_get_property_list");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void Object::_init() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "_init");
	}
	___godot_icall_void(mb, (const Object *) this);
}

String Object::get_class() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_class");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool Object::is_class(const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "is_class");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, type);
}

void Object::set(const String property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "set");
	}
	___godot_icall_void_String_Variant(mb, (const Object *) this, property, value);
}

Variant Object::get(const String property) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get");
	}
	return ___godot_icall_Variant_String(mb, (const Object *) this, property);
}

void Object::set_indexed(const NodePath property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "set_indexed");
	}
	___godot_icall_void_NodePath_Variant(mb, (const Object *) this, property, value);
}

Variant Object::get_indexed(const NodePath property) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_indexed");
	}
	return ___godot_icall_Variant_NodePath(mb, (const Object *) this, property);
}

Array Object::get_property_list() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_property_list");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Array Object::get_method_list() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_method_list");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void Object::notification(const int64_t what, const bool reversed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "notification");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, what, reversed);
}

int64_t Object::get_instance_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_instance_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Object::set_script(const Reference *script) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "set_script");
	}
	___godot_icall_void_Object(mb, (const Object *) this, script);
}

Reference *Object::get_script() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_script");
	}
	return (Reference *) ___godot_icall_Object(mb, (const Object *) this);
}

void Object::set_meta(const String name, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "set_meta");
	}
	___godot_icall_void_String_Variant(mb, (const Object *) this, name, value);
}

Variant Object::get_meta(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_meta");
	}
	return ___godot_icall_Variant_String(mb, (const Object *) this, name);
}

bool Object::has_meta(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "has_meta");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

PoolStringArray Object::get_meta_list() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_meta_list");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

void Object::add_user_signal(const String signal, const Array arguments) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "add_user_signal");
	}
	___godot_icall_void_String_Array(mb, (const Object *) this, signal, arguments);
}

bool Object::has_user_signal(const String signal) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "has_user_signal");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, signal);
}

Variant Object::emit_signal(const String signal, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "emit_signal");
	}
	Variant __given_args[1];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);

	__given_args[0] = signal;

	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 1));

	__args[0] = (godot_variant *) &__given_args[0];

	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 1] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 1), nullptr);

	godot::api->godot_variant_destroy((godot_variant *) &__given_args[0]);

	return __result;
}

Variant Object::call(const String method, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "call");
	}
	Variant __given_args[1];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);

	__given_args[0] = method;

	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 1));

	__args[0] = (godot_variant *) &__given_args[0];

	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 1] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 1), nullptr);

	godot::api->godot_variant_destroy((godot_variant *) &__given_args[0]);

	return __result;
}

Variant Object::call_deferred(const String method, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "call_deferred");
	}
	Variant __given_args[1];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);

	__given_args[0] = method;

	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 1));

	__args[0] = (godot_variant *) &__given_args[0];

	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 1] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 1), nullptr);

	godot::api->godot_variant_destroy((godot_variant *) &__given_args[0]);

	return __result;
}

Variant Object::callv(const String method, const Array arg_array) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "callv");
	}
	return ___godot_icall_Variant_String_Array(mb, (const Object *) this, method, arg_array);
}

bool Object::has_method(const String method) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "has_method");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, method);
}

Array Object::get_signal_list() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_signal_list");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Array Object::get_signal_connection_list(const String signal) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_signal_connection_list");
	}
	return ___godot_icall_Array_String(mb, (const Object *) this, signal);
}

Array Object::get_incoming_connections() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "get_incoming_connections");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

Error Object::connect(const String signal, const Object *target, const String method, const Array binds, const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "connect");
	}
	return (Error) ___godot_icall_int_String_Object_String_Array_int(mb, (const Object *) this, signal, target, method, binds, flags);
}

void Object::disconnect(const String signal, const Object *target, const String method) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "disconnect");
	}
	___godot_icall_void_String_Object_String(mb, (const Object *) this, signal, target, method);
}

bool Object::is_connected(const String signal, const Object *target, const String method) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "is_connected");
	}
	return ___godot_icall_bool_String_Object_String(mb, (const Object *) this, signal, target, method);
}

void Object::set_block_signals(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "set_block_signals");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Object::is_blocking_signals() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "is_blocking_signals");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Object::property_list_changed_notify() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "property_list_changed_notify");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Object::set_message_translation(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "set_message_translation");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Object::can_translate_messages() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "can_translate_messages");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

String Object::tr(const String message) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "tr");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, message);
}

bool Object::is_queued_for_deletion() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Object", "is_queued_for_deletion");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}