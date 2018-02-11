#include <VisualScriptLocalVar.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptLocalVar::___get_type_tag()
{
	return (void *) &VisualScriptLocalVar::___get_type_tag;
}

void *VisualScriptLocalVar::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptLocalVar *VisualScriptLocalVar::_new()
{
	return (VisualScriptLocalVar *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptLocalVar")());
}
void VisualScriptLocalVar::set_var_name(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptLocalVar", "set_var_name");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String VisualScriptLocalVar::get_var_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptLocalVar", "get_var_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptLocalVar::set_var_type(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptLocalVar", "set_var_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

Variant::Type VisualScriptLocalVar::get_var_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptLocalVar", "get_var_type");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

}