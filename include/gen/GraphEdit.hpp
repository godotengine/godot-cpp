#ifndef GODOT_CPP_GRAPHEDIT_HPP
#define GODOT_CPP_GRAPHEDIT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Control.hpp>
namespace godot {

class Object;
class InputEvent;

class GraphEdit : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GraphEdit"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static GraphEdit *_new();

	// methods
	Error connect_node(const String from, const int64_t from_port, const String to, const int64_t to_port);
	bool is_node_connected(const String from, const int64_t from_port, const String to, const int64_t to_port);
	void disconnect_node(const String from, const int64_t from_port, const String to, const int64_t to_port);
	Array get_connection_list() const;
	void clear_connections();
	Vector2 get_scroll_ofs() const;
	void set_scroll_ofs(const Vector2 ofs);
	void add_valid_right_disconnect_type(const int64_t type);
	void remove_valid_right_disconnect_type(const int64_t type);
	void add_valid_left_disconnect_type(const int64_t type);
	void remove_valid_left_disconnect_type(const int64_t type);
	void add_valid_connection_type(const int64_t from_type, const int64_t to_type);
	void remove_valid_connection_type(const int64_t from_type, const int64_t to_type);
	bool is_valid_connection_type(const int64_t from_type, const int64_t to_type) const;
	void set_zoom(const double p_zoom);
	double get_zoom() const;
	void set_snap(const int64_t pixels);
	int64_t get_snap() const;
	void set_use_snap(const bool enable);
	bool is_using_snap() const;
	void set_right_disconnects(const bool enable);
	bool is_right_disconnects_enabled() const;
	void _graph_node_moved(const Object *arg0);
	void _graph_node_raised(const Object *arg0);
	void _top_layer_input(const Ref<InputEvent> arg0);
	void _top_layer_draw();
	void _scroll_moved(const double arg0);
	void _zoom_minus();
	void _zoom_reset();
	void _zoom_plus();
	void _snap_toggled();
	void _snap_value_changed(const double arg0);
	void _gui_input(const Ref<InputEvent> arg0);
	void _update_scroll_offset();
	void _connections_layer_draw();
	void set_selected(const Object *node);

};

}

#endif