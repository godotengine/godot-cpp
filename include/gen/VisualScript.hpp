#ifndef GODOT_CPP_VISUALSCRIPT_HPP
#define GODOT_CPP_VISUALSCRIPT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Variant.hpp>

#include <Script.hpp>
namespace godot {

class VisualScriptNode;

class VisualScript : public Script {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualScript"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static VisualScript *_new();

	// methods
	void _node_ports_changed(const int64_t arg0);
	void add_function(const String name);
	bool has_function(const String name) const;
	void remove_function(const String name);
	void rename_function(const String name, const String new_name);
	void set_function_scroll(const String name, const Vector2 ofs);
	Vector2 get_function_scroll(const String name) const;
	void add_node(const String func, const int64_t id, const Ref<VisualScriptNode> node, const Vector2 position = Vector2(0, 0));
	void remove_node(const String func, const int64_t id);
	int64_t get_function_node_id(const String name) const;
	Ref<VisualScriptNode> get_node(const String func, const int64_t id) const;
	bool has_node(const String func, const int64_t id) const;
	void set_node_position(const String func, const int64_t id, const Vector2 position);
	Vector2 get_node_position(const String func, const int64_t id) const;
	void sequence_connect(const String func, const int64_t from_node, const int64_t from_output, const int64_t to_node);
	void sequence_disconnect(const String func, const int64_t from_node, const int64_t from_output, const int64_t to_node);
	bool has_sequence_connection(const String func, const int64_t from_node, const int64_t from_output, const int64_t to_node) const;
	void data_connect(const String func, const int64_t from_node, const int64_t from_port, const int64_t to_node, const int64_t to_port);
	void data_disconnect(const String func, const int64_t from_node, const int64_t from_port, const int64_t to_node, const int64_t to_port);
	bool has_data_connection(const String func, const int64_t from_node, const int64_t from_port, const int64_t to_node, const int64_t to_port) const;
	void add_variable(const String name, const Variant default_value = Variant(), const bool _export = false);
	bool has_variable(const String name) const;
	void remove_variable(const String name);
	void set_variable_default_value(const String name, const Variant value);
	Variant get_variable_default_value(const String name) const;
	void set_variable_info(const String name, const Dictionary value);
	Dictionary get_variable_info(const String name) const;
	void set_variable_export(const String name, const bool enable);
	bool get_variable_export(const String name) const;
	void rename_variable(const String name, const String new_name);
	void add_custom_signal(const String name);
	bool has_custom_signal(const String name) const;
	void custom_signal_add_argument(const String name, const int64_t type, const String argname, const int64_t index = -1);
	void custom_signal_set_argument_type(const String name, const int64_t argidx, const int64_t type);
	Variant::Type custom_signal_get_argument_type(const String name, const int64_t argidx) const;
	void custom_signal_set_argument_name(const String name, const int64_t argidx, const String argname);
	String custom_signal_get_argument_name(const String name, const int64_t argidx) const;
	void custom_signal_remove_argument(const String name, const int64_t argidx);
	int64_t custom_signal_get_argument_count(const String name) const;
	void custom_signal_swap_argument(const String name, const int64_t argidx, const int64_t withidx);
	void remove_custom_signal(const String name);
	void rename_custom_signal(const String name, const String new_name);
	void set_instance_base_type(const String type);
	void _set_data(const Dictionary data);
	Dictionary _get_data() const;

};

}

#endif