#include <VisualScriptBasicTypeConstant.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptBasicTypeConstant::___get_type_tag()
{
	return (void *) &VisualScriptBasicTypeConstant::___get_type_tag;
}

void *VisualScriptBasicTypeConstant::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptBasicTypeConstant *VisualScriptBasicTypeConstant::_new()
{
	return (VisualScriptBasicTypeConstant *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptBasicTypeConstant")());
}
void VisualScriptBasicTypeConstant::set_basic_type(const int64_t name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptBasicTypeConstant", "set_basic_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, name);
}

Variant::Type VisualScriptBasicTypeConstant::get_basic_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptBasicTypeConstant", "get_basic_type");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptBasicTypeConstant::set_basic_type_constant(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptBasicTypeConstant", "set_basic_type_constant");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String VisualScriptBasicTypeConstant::get_basic_type_constant() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptBasicTypeConstant", "get_basic_type_constant");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}