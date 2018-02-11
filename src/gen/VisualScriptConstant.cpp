#include <VisualScriptConstant.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptConstant::___get_type_tag()
{
	return (void *) &VisualScriptConstant::___get_type_tag;
}

void *VisualScriptConstant::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptConstant *VisualScriptConstant::_new()
{
	return (VisualScriptConstant *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptConstant")());
}
void VisualScriptConstant::set_constant_type(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptConstant", "set_constant_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

Variant::Type VisualScriptConstant::get_constant_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptConstant", "get_constant_type");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptConstant::set_constant_value(const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptConstant", "set_constant_value");
	}
	___godot_icall_void_Variant(mb, (const Object *) this, value);
}

Variant VisualScriptConstant::get_constant_value() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptConstant", "get_constant_value");
	}
	return ___godot_icall_Variant(mb, (const Object *) this);
}

}