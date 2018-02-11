#include <VisualScriptGlobalConstant.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptGlobalConstant::___get_type_tag()
{
	return (void *) &VisualScriptGlobalConstant::___get_type_tag;
}

void *VisualScriptGlobalConstant::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptGlobalConstant *VisualScriptGlobalConstant::_new()
{
	return (VisualScriptGlobalConstant *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptGlobalConstant")());
}
void VisualScriptGlobalConstant::set_global_constant(const int64_t index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptGlobalConstant", "set_global_constant");
	}
	___godot_icall_void_int(mb, (const Object *) this, index);
}

int64_t VisualScriptGlobalConstant::get_global_constant() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptGlobalConstant", "get_global_constant");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}