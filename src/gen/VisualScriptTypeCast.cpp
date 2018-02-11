#include <VisualScriptTypeCast.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptTypeCast::___get_type_tag()
{
	return (void *) &VisualScriptTypeCast::___get_type_tag;
}

void *VisualScriptTypeCast::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptTypeCast *VisualScriptTypeCast::_new()
{
	return (VisualScriptTypeCast *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptTypeCast")());
}
void VisualScriptTypeCast::set_base_type(const String type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptTypeCast", "set_base_type");
	}
	___godot_icall_void_String(mb, (const Object *) this, type);
}

String VisualScriptTypeCast::get_base_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptTypeCast", "get_base_type");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptTypeCast::set_base_script(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptTypeCast", "set_base_script");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

String VisualScriptTypeCast::get_base_script() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptTypeCast", "get_base_script");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}