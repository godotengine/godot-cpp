#include <VisualScriptYieldSignal.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptYieldSignal::___get_type_tag()
{
	return (void *) &VisualScriptYieldSignal::___get_type_tag;
}

void *VisualScriptYieldSignal::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptYieldSignal *VisualScriptYieldSignal::_new()
{
	return (VisualScriptYieldSignal *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptYieldSignal")());
}
void VisualScriptYieldSignal::set_base_type(const String base_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYieldSignal", "set_base_type");
	}
	___godot_icall_void_String(mb, (const Object *) this, base_type);
}

String VisualScriptYieldSignal::get_base_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYieldSignal", "get_base_type");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptYieldSignal::set_signal(const String signal) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYieldSignal", "set_signal");
	}
	___godot_icall_void_String(mb, (const Object *) this, signal);
}

String VisualScriptYieldSignal::get_signal() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYieldSignal", "get_signal");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void VisualScriptYieldSignal::set_call_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYieldSignal", "set_call_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

VisualScriptYieldSignal::CallMode VisualScriptYieldSignal::get_call_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYieldSignal", "get_call_mode");
	}
	return (VisualScriptYieldSignal::CallMode) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptYieldSignal::set_base_path(const NodePath base_path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYieldSignal", "set_base_path");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, base_path);
}

NodePath VisualScriptYieldSignal::get_base_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYieldSignal", "get_base_path");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

}