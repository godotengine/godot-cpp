#include <GraphEdit.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <InputEvent.hpp>


namespace godot {


void *GraphEdit::___get_type_tag()
{
	return (void *) &GraphEdit::___get_type_tag;
}

void *GraphEdit::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

GraphEdit *GraphEdit::_new()
{
	return (GraphEdit *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"GraphEdit")());
}
Error GraphEdit::connect_node(const String from, const int64_t from_port, const String to, const int64_t to_port) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "connect_node");
	}
	return (Error) ___godot_icall_int_String_int_String_int(mb, (const Object *) this, from, from_port, to, to_port);
}

bool GraphEdit::is_node_connected(const String from, const int64_t from_port, const String to, const int64_t to_port) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "is_node_connected");
	}
	return ___godot_icall_bool_String_int_String_int(mb, (const Object *) this, from, from_port, to, to_port);
}

void GraphEdit::disconnect_node(const String from, const int64_t from_port, const String to, const int64_t to_port) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "disconnect_node");
	}
	___godot_icall_void_String_int_String_int(mb, (const Object *) this, from, from_port, to, to_port);
}

Array GraphEdit::get_connection_list() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "get_connection_list");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void GraphEdit::clear_connections() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "clear_connections");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Vector2 GraphEdit::get_scroll_ofs() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "get_scroll_ofs");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void GraphEdit::set_scroll_ofs(const Vector2 ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "set_scroll_ofs");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, ofs);
}

void GraphEdit::add_valid_right_disconnect_type(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "add_valid_right_disconnect_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

void GraphEdit::remove_valid_right_disconnect_type(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "remove_valid_right_disconnect_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

void GraphEdit::add_valid_left_disconnect_type(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "add_valid_left_disconnect_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

void GraphEdit::remove_valid_left_disconnect_type(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "remove_valid_left_disconnect_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

void GraphEdit::add_valid_connection_type(const int64_t from_type, const int64_t to_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "add_valid_connection_type");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, from_type, to_type);
}

void GraphEdit::remove_valid_connection_type(const int64_t from_type, const int64_t to_type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "remove_valid_connection_type");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, from_type, to_type);
}

bool GraphEdit::is_valid_connection_type(const int64_t from_type, const int64_t to_type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "is_valid_connection_type");
	}
	return ___godot_icall_bool_int_int(mb, (const Object *) this, from_type, to_type);
}

void GraphEdit::set_zoom(const double p_zoom) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "set_zoom");
	}
	___godot_icall_void_float(mb, (const Object *) this, p_zoom);
}

double GraphEdit::get_zoom() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "get_zoom");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void GraphEdit::set_snap(const int64_t pixels) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "set_snap");
	}
	___godot_icall_void_int(mb, (const Object *) this, pixels);
}

int64_t GraphEdit::get_snap() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "get_snap");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void GraphEdit::set_use_snap(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "set_use_snap");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool GraphEdit::is_using_snap() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "is_using_snap");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GraphEdit::set_right_disconnects(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "set_right_disconnects");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool GraphEdit::is_right_disconnects_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "is_right_disconnects_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void GraphEdit::_graph_node_moved(const Object *arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_graph_node_moved");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0);
}

void GraphEdit::_graph_node_raised(const Object *arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_graph_node_raised");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0);
}

void GraphEdit::_top_layer_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_top_layer_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void GraphEdit::_top_layer_draw() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_top_layer_draw");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void GraphEdit::_scroll_moved(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_scroll_moved");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void GraphEdit::_zoom_minus() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_zoom_minus");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void GraphEdit::_zoom_reset() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_zoom_reset");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void GraphEdit::_zoom_plus() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_zoom_plus");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void GraphEdit::_snap_toggled() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_snap_toggled");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void GraphEdit::_snap_value_changed(const double arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_snap_value_changed");
	}
	___godot_icall_void_float(mb, (const Object *) this, arg0);
}

void GraphEdit::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void GraphEdit::_update_scroll_offset() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_update_scroll_offset");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void GraphEdit::_connections_layer_draw() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "_connections_layer_draw");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void GraphEdit::set_selected(const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GraphEdit", "set_selected");
	}
	___godot_icall_void_Object(mb, (const Object *) this, node);
}

}