#include <VisualScriptInputAction.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptInputAction::___get_type_tag()
{
	return (void *) &VisualScriptInputAction::___get_type_tag;
}

void *VisualScriptInputAction::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptInputAction *VisualScriptInputAction::_new()
{
	return (VisualScriptInputAction *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptInputAction")());
}
void VisualScriptInputAction::set_action_name(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptInputAction", "set_action_name");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String VisualScriptInputAction::get_action_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptInputAction", "get_action_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptInputAction::set_action_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptInputAction", "set_action_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

VisualScriptInputAction::Mode VisualScriptInputAction::get_action_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptInputAction", "get_action_mode");
	}
	return (VisualScriptInputAction::Mode) ___godot_icall_int(mb, (const Object *) this);
}

}