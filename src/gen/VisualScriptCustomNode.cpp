#include <VisualScriptCustomNode.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptCustomNode::___get_type_tag()
{
	return (void *) &VisualScriptCustomNode::___get_type_tag;
}

void *VisualScriptCustomNode::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptCustomNode *VisualScriptCustomNode::_new()
{
	return (VisualScriptCustomNode *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptCustomNode")());
}
int64_t VisualScriptCustomNode::_get_output_sequence_port_count() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_output_sequence_port_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool VisualScriptCustomNode::_has_input_sequence_port() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_has_input_sequence_port");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

String VisualScriptCustomNode::_get_output_sequence_port_text(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_output_sequence_port_text");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

int64_t VisualScriptCustomNode::_get_input_value_port_count() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_input_value_port_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t VisualScriptCustomNode::_get_output_value_port_count() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_output_value_port_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t VisualScriptCustomNode::_get_input_value_port_type(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_input_value_port_type");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

String VisualScriptCustomNode::_get_input_value_port_name(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_input_value_port_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

int64_t VisualScriptCustomNode::_get_output_value_port_type(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_output_value_port_type");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

String VisualScriptCustomNode::_get_output_value_port_name(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_output_value_port_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

String VisualScriptCustomNode::_get_caption() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_caption");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String VisualScriptCustomNode::_get_text() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String VisualScriptCustomNode::_get_category() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_category");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t VisualScriptCustomNode::_get_working_memory_size() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_get_working_memory_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Variant VisualScriptCustomNode::_step(const Array inputs, const Array outputs, const int64_t start_mode, const Array working_mem) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_step");
	}
	return ___godot_icall_Variant_Array_Array_int_Array(mb, (const Object *) this, inputs, outputs, start_mode, working_mem);
}

void VisualScriptCustomNode::_script_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptCustomNode", "_script_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}