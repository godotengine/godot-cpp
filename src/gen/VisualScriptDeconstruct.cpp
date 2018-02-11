#include <VisualScriptDeconstruct.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptDeconstruct::___get_type_tag()
{
	return (void *) &VisualScriptDeconstruct::___get_type_tag;
}

void *VisualScriptDeconstruct::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptDeconstruct *VisualScriptDeconstruct::_new()
{
	return (VisualScriptDeconstruct *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptDeconstruct")());
}
void VisualScriptDeconstruct::set_deconstruct_type(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptDeconstruct", "set_deconstruct_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

Variant::Type VisualScriptDeconstruct::get_deconstruct_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptDeconstruct", "get_deconstruct_type");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptDeconstruct::_set_elem_cache(const Array _cache) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptDeconstruct", "_set_elem_cache");
	}
	___godot_icall_void_Array(mb, (const Object *) this, _cache);
}

Array VisualScriptDeconstruct::_get_elem_cache() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptDeconstruct", "_get_elem_cache");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}