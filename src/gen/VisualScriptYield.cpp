#include <VisualScriptYield.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptYield::___get_type_tag()
{
	return (void *) &VisualScriptYield::___get_type_tag;
}

void *VisualScriptYield::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptYield *VisualScriptYield::_new()
{
	return (VisualScriptYield *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptYield")());
}
void VisualScriptYield::set_yield_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYield", "set_yield_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

VisualScriptYield::YieldMode VisualScriptYield::get_yield_mode() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYield", "get_yield_mode");
	}
	return (VisualScriptYield::YieldMode) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptYield::set_wait_time(const double sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYield", "set_wait_time");
	}
	___godot_icall_void_float(mb, (const Object *) this, sec);
}

double VisualScriptYield::get_wait_time() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptYield", "get_wait_time");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}