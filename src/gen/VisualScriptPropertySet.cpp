#include <VisualScriptPropertySet.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptPropertySet::___get_type_tag()
{
	return (void *) &VisualScriptPropertySet::___get_type_tag;
}

void *VisualScriptPropertySet::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptPropertySet *VisualScriptPropertySet::_new()
{
	return (VisualScriptPropertySet *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptPropertySet")());
}
void VisualScriptPropertySet::set_base_type(const String base_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "set_base_type");
	}
	___godot_icall_void_String(mb, (const Object *) this, base_type);
}

String VisualScriptPropertySet::get_base_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "get_base_type");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptPropertySet::set_base_script(const String base_script) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "set_base_script");
	}
	___godot_icall_void_String(mb, (const Object *) this, base_script);
}

String VisualScriptPropertySet::get_base_script() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "get_base_script");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptPropertySet::set_basic_type(const int64_t basic_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "set_basic_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, basic_type);
}

Variant::Type VisualScriptPropertySet::get_basic_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "get_basic_type");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptPropertySet::_set_type_cache(const Dictionary type_cache) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "_set_type_cache");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, type_cache);
}

Dictionary VisualScriptPropertySet::_get_type_cache() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "_get_type_cache");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

void VisualScriptPropertySet::set_property(const String property) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "set_property");
	}
	___godot_icall_void_String(mb, (const Object *) this, property);
}

String VisualScriptPropertySet::get_property() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "get_property");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptPropertySet::set_call_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "set_call_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

VisualScriptPropertySet::CallMode VisualScriptPropertySet::get_call_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "get_call_mode");
	}
	return (VisualScriptPropertySet::CallMode) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptPropertySet::set_base_path(const NodePath base_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "set_base_path");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, base_path);
}

NodePath VisualScriptPropertySet::get_base_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "get_base_path");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

void VisualScriptPropertySet::set_index(const String index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "set_index");
	}
	___godot_icall_void_String(mb, (const Object *) this, index);
}

String VisualScriptPropertySet::get_index() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "get_index");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptPropertySet::set_assign_op(const int64_t assign_op) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "set_assign_op");
	}
	___godot_icall_void_int(mb, (const Object *) this, assign_op);
}

VisualScriptPropertySet::AssignOp VisualScriptPropertySet::get_assign_op() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptPropertySet", "get_assign_op");
	}
	return (VisualScriptPropertySet::AssignOp) ___godot_icall_int(mb, (const Object *) this);
}

}