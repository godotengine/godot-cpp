#include <VisualScriptNode.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <VisualScript.hpp>


namespace godot {


void *VisualScriptNode::___get_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

void *VisualScriptNode::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Ref<VisualScript> VisualScriptNode::get_visual_script() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptNode", "get_visual_script");
	}
	return Ref<VisualScript>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void VisualScriptNode::set_default_input_value(const int64_t port_idx, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptNode", "set_default_input_value");
	}
	___godot_icall_void_int_Variant(mb, (const Object *) this, port_idx, value);
}

Variant VisualScriptNode::get_default_input_value(const int64_t port_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptNode", "get_default_input_value");
	}
	return ___godot_icall_Variant_int(mb, (const Object *) this, port_idx);
}

void VisualScriptNode::ports_changed_notify() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptNode", "ports_changed_notify");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void VisualScriptNode::_set_default_input_values(const Array values) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptNode", "_set_default_input_values");
	}
	___godot_icall_void_Array(mb, (const Object *) this, values);
}

Array VisualScriptNode::_get_default_input_values() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptNode", "_get_default_input_values");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}