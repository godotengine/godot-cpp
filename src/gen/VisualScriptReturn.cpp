#include <VisualScriptReturn.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptReturn::___get_type_tag()
{
	return (void *) &VisualScriptReturn::___get_type_tag;
}

void *VisualScriptReturn::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptReturn *VisualScriptReturn::_new()
{
	return (VisualScriptReturn *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptReturn")());
}
void VisualScriptReturn::set_return_type(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptReturn", "set_return_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

Variant::Type VisualScriptReturn::get_return_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptReturn", "get_return_type");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptReturn::set_enable_return_value(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptReturn", "set_enable_return_value");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool VisualScriptReturn::is_return_value_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptReturn", "is_return_value_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}