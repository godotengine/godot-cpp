#include <GraphNode.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>
#include <Texture.hpp>


namespace godot {


void *GraphNode::___get_type_tag()
{
	return (void *) &GraphNode::___get_type_tag;
}

void *GraphNode::___get_base_type_tag()
{
	return (void *) &Container::___get_type_tag;
}

GraphNode *GraphNode::_new()
{
	return (GraphNode *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"GraphNode")());
}
void GraphNode::set_title(const String title) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "set_title");
	}
	___godot_icall_void_String(mb, (const Object *) this, title);
}

String GraphNode::get_title() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_title");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void GraphNode::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void GraphNode::set_slot(const int64_t idx, const bool enable_left, const int64_t type_left, const Color color_left, const bool enable_right, const int64_t type_right, const Color color_right, const Ref<Texture> custom_left, const Ref<Texture> custom_right) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "set_slot");
	}
	___godot_icall_void_int_bool_int_Color_bool_int_Color_Object_Object(mb, (const Object *) this, idx, enable_left, type_left, color_left, enable_right, type_right, color_right, custom_left.ptr(), custom_right.ptr());
}

void GraphNode::clear_slot(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "clear_slot");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void GraphNode::clear_all_slots() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "clear_all_slots");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool GraphNode::is_slot_enabled_left(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "is_slot_enabled_left");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

int64_t GraphNode::get_slot_type_left(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_slot_type_left");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

Color GraphNode::get_slot_color_left(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_slot_color_left");
	}
	return ___godot_icall_Color_int(mb, (const Object *) this, idx);
}

bool GraphNode::is_slot_enabled_right(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "is_slot_enabled_right");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

int64_t GraphNode::get_slot_type_right(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_slot_type_right");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

Color GraphNode::get_slot_color_right(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_slot_color_right");
	}
	return ___godot_icall_Color_int(mb, (const Object *) this, idx);
}

void GraphNode::set_offset(const Vector2 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "set_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, offset);
}

Vector2 GraphNode::get_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void GraphNode::set_comment(const bool comment) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "set_comment");
	}
	___godot_icall_void_bool(mb, (const Object *) this, comment);
}

bool GraphNode::is_comment() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "is_comment");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GraphNode::set_resizable(const bool resizable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "set_resizable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, resizable);
}

bool GraphNode::is_resizable() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "is_resizable");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GraphNode::set_selected(const bool selected) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "set_selected");
	}
	___godot_icall_void_bool(mb, (const Object *) this, selected);
}

bool GraphNode::is_selected() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "is_selected");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t GraphNode::get_connection_output_count() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_connection_output_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t GraphNode::get_connection_input_count() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_connection_input_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Vector2 GraphNode::get_connection_output_position(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_connection_output_position");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, idx);
}

int64_t GraphNode::get_connection_output_type(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_connection_output_type");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

Color GraphNode::get_connection_output_color(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_connection_output_color");
	}
	return ___godot_icall_Color_int(mb, (const Object *) this, idx);
}

Vector2 GraphNode::get_connection_input_position(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_connection_input_position");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, idx);
}

int64_t GraphNode::get_connection_input_type(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_connection_input_type");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

Color GraphNode::get_connection_input_color(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_connection_input_color");
	}
	return ___godot_icall_Color_int(mb, (const Object *) this, idx);
}

void GraphNode::set_show_close_button(const bool show) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "set_show_close_button");
	}
	___godot_icall_void_bool(mb, (const Object *) this, show);
}

bool GraphNode::is_close_button_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "is_close_button_visible");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GraphNode::set_overlay(const int64_t overlay) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "set_overlay");
	}
	___godot_icall_void_int(mb, (const Object *) this, overlay);
}

GraphNode::Overlay GraphNode::get_overlay() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphNode", "get_overlay");
	}
	return (GraphNode::Overlay) ___godot_icall_int(mb, (const Object *) this);
}

}