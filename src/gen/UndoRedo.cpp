#include <UndoRedo.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *UndoRedo::___get_type_tag()
{
	return (void *) &UndoRedo::___get_type_tag;
}

void *UndoRedo::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

UndoRedo *UndoRedo::_new()
{
	return (UndoRedo *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"UndoRedo")());
}
void UndoRedo::create_action(const String name, const int64_t merge_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "create_action");
	}
	___godot_icall_void_String_int(mb, (const Object *) this, name, merge_mode);
}

void UndoRedo::commit_action() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "commit_action");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Variant UndoRedo::add_do_method(const Object *object, const String method, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "add_do_method");
	}
	Variant __given_args[2];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[1]);

	__given_args[0] = object;
	__given_args[1] = method;

	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 2));

	__args[0] = (godot_variant *) &__given_args[0];
	__args[1] = (godot_variant *) &__given_args[1];

	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 2] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 2), nullptr);

	godot::api->godot_variant_destroy((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_destroy((godot_variant *) &__given_args[1]);

	return __result;
}

Variant UndoRedo::add_undo_method(const Object *object, const String method, const Array& __var_args) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "add_undo_method");
	}
	Variant __given_args[2];
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_new_nil((godot_variant *) &__given_args[1]);

	__given_args[0] = object;
	__given_args[1] = method;

	godot_variant **__args = (godot_variant **) alloca(sizeof(godot_variant *) * (__var_args.size() + 2));

	__args[0] = (godot_variant *) &__given_args[0];
	__args[1] = (godot_variant *) &__given_args[1];

	for (int i = 0; i < __var_args.size(); i++) {
		__args[i + 2] = (godot_variant *) &((Array &) __var_args)[i];
	}

	Variant __result;
	*(godot_variant *) &__result = godot::api->godot_method_bind_call(mb, ((const Object *) this)->_owner, (const godot_variant **) __args, (__var_args.size() + 2), nullptr);

	godot::api->godot_variant_destroy((godot_variant *) &__given_args[0]);
	godot::api->godot_variant_destroy((godot_variant *) &__given_args[1]);

	return __result;
}

void UndoRedo::add_do_property(const Object *object, const String property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "add_do_property");
	}
	___godot_icall_void_Object_String_Variant(mb, (const Object *) this, object, property, value);
}

void UndoRedo::add_undo_property(const Object *object, const String property, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "add_undo_property");
	}
	___godot_icall_void_Object_String_Variant(mb, (const Object *) this, object, property, value);
}

void UndoRedo::add_do_reference(const Object *object) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "add_do_reference");
	}
	___godot_icall_void_Object(mb, (const Object *) this, object);
}

void UndoRedo::add_undo_reference(const Object *object) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "add_undo_reference");
	}
	___godot_icall_void_Object(mb, (const Object *) this, object);
}

void UndoRedo::clear_history() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "clear_history");
	}
	___godot_icall_void(mb, (const Object *) this);
}

String UndoRedo::get_current_action_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "get_current_action_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t UndoRedo::get_version() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "get_version");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void UndoRedo::redo() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "redo");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void UndoRedo::undo() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("UndoRedo", "undo");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}