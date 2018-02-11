#include <VisualScriptOperator.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptOperator::___get_type_tag()
{
	return (void *) &VisualScriptOperator::___get_type_tag;
}

void *VisualScriptOperator::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptOperator *VisualScriptOperator::_new()
{
	return (VisualScriptOperator *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptOperator")());
}
void VisualScriptOperator::set_operator(const int64_t op) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptOperator", "set_operator");
	}
	___godot_icall_void_int(mb, (const Object *) this, op);
}

Variant::Operator VisualScriptOperator::get_operator() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptOperator", "get_operator");
	}
	return (Variant::Operator) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptOperator::set_typed(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptOperator", "set_typed");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

Variant::Type VisualScriptOperator::get_typed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptOperator", "get_typed");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

}