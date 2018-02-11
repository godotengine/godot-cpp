#include <VisualScriptSelect.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptSelect::___get_type_tag()
{
	return (void *) &VisualScriptSelect::___get_type_tag;
}

void *VisualScriptSelect::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptSelect *VisualScriptSelect::_new()
{
	return (VisualScriptSelect *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptSelect")());
}
void VisualScriptSelect::set_typed(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptSelect", "set_typed");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

Variant::Type VisualScriptSelect::get_typed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptSelect", "get_typed");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

}