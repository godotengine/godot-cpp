#include <VisualScriptClassConstant.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptClassConstant::___get_type_tag()
{
	return (void *) &VisualScriptClassConstant::___get_type_tag;
}

void *VisualScriptClassConstant::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptClassConstant *VisualScriptClassConstant::_new()
{
	return (VisualScriptClassConstant *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptClassConstant")());
}
void VisualScriptClassConstant::set_class_constant(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptClassConstant", "set_class_constant");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String VisualScriptClassConstant::get_class_constant() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptClassConstant", "get_class_constant");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptClassConstant::set_base_type(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptClassConstant", "set_base_type");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String VisualScriptClassConstant::get_base_type() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptClassConstant", "get_base_type");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}