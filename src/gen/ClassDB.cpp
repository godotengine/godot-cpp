#include <ClassDB.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *ClassDB::___get_type_tag()
{
	return (void *) &ClassDB::___get_type_tag;
}

void *ClassDB::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

ClassDB *ClassDB::_singleton = NULL;


ClassDB::ClassDB() {
	_owner = godot::api->godot_global_get_singleton((char *) "ClassDB");
}


PoolStringArray ClassDB::get_class_list() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "get_class_list");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

PoolStringArray ClassDB::get_inheriters_from_class(const String _class) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "get_inheriters_from_class");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, _class);
}

String ClassDB::get_parent_class(const String _class) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "get_parent_class");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, _class);
}

bool ClassDB::class_exists(const String _class) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_exists");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, _class);
}

bool ClassDB::is_parent_class(const String _class, const String inherits) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "is_parent_class");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, _class, inherits);
}

bool ClassDB::can_instance(const String _class) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "can_instance");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, _class);
}

Variant ClassDB::instance(const String _class) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "instance");
	}
	return ___godot_icall_Variant_String(mb, (const Object *) this, _class);
}

bool ClassDB::class_has_signal(const String _class, const String signal) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_has_signal");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, _class, signal);
}

Dictionary ClassDB::class_get_signal(const String _class, const String signal) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_get_signal");
	}
	return ___godot_icall_Dictionary_String_String(mb, (const Object *) this, _class, signal);
}

Array ClassDB::class_get_signal_list(const String _class, const bool no_inheritance) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_get_signal_list");
	}
	return ___godot_icall_Array_String_bool(mb, (const Object *) this, _class, no_inheritance);
}

Array ClassDB::class_get_property_list(const String _class, const bool no_inheritance) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_get_property_list");
	}
	return ___godot_icall_Array_String_bool(mb, (const Object *) this, _class, no_inheritance);
}

Variant ClassDB::class_get_property(const Object *object, const String property) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_get_property");
	}
	return ___godot_icall_Variant_Object_String(mb, (const Object *) this, object, property);
}

Error ClassDB::class_set_property(const Object *object, const String property, const Variant value) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_set_property");
	}
	return (Error) ___godot_icall_int_Object_String_Variant(mb, (const Object *) this, object, property, value);
}

bool ClassDB::class_has_method(const String _class, const String method, const bool no_inheritance) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_has_method");
	}
	return ___godot_icall_bool_String_String_bool(mb, (const Object *) this, _class, method, no_inheritance);
}

Array ClassDB::class_get_method_list(const String _class, const bool no_inheritance) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_get_method_list");
	}
	return ___godot_icall_Array_String_bool(mb, (const Object *) this, _class, no_inheritance);
}

PoolStringArray ClassDB::class_get_integer_constant_list(const String _class, const bool no_inheritance) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_get_integer_constant_list");
	}
	return ___godot_icall_PoolStringArray_String_bool(mb, (const Object *) this, _class, no_inheritance);
}

bool ClassDB::class_has_integer_constant(const String _class, const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_has_integer_constant");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, _class, name);
}

int64_t ClassDB::class_get_integer_constant(const String _class, const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_get_integer_constant");
	}
	return ___godot_icall_int_String_String(mb, (const Object *) this, _class, name);
}

String ClassDB::class_get_category(const String _class) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "class_get_category");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, _class);
}

bool ClassDB::is_class_enabled(const String _class) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_ClassDB", "is_class_enabled");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, _class);
}

}