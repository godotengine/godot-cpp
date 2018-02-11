#ifndef GODOT_CPP_GRAPHNODE_HPP
#define GODOT_CPP_GRAPHNODE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <GraphNode.hpp>

#include <Container.hpp>
namespace godot {

class InputEvent;
class Texture;

class GraphNode : public Container {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GraphNode"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Overlay {
		OVERLAY_BREAKPOINT = 1,
		OVERLAY_POSITION = 2,
		OVERLAY_DISABLED = 0,
	};

	// constants


	static GraphNode *_new();

	// methods
	void set_title(const String title);
	String get_title() const;
	void _gui_input(const Ref<InputEvent> arg0);
	void set_slot(const int64_t idx, const bool enable_left, const int64_t type_left, const Color color_left, const bool enable_right, const int64_t type_right, const Color color_right, const Ref<Texture> custom_left = nullptr, const Ref<Texture> custom_right = nullptr);
	void clear_slot(const int64_t idx);
	void clear_all_slots();
	bool is_slot_enabled_left(const int64_t idx) const;
	int64_t get_slot_type_left(const int64_t idx) const;
	Color get_slot_color_left(const int64_t idx) const;
	bool is_slot_enabled_right(const int64_t idx) const;
	int64_t get_slot_type_right(const int64_t idx) const;
	Color get_slot_color_right(const int64_t idx) const;
	void set_offset(const Vector2 offset);
	Vector2 get_offset() const;
	void set_comment(const bool comment);
	bool is_comment() const;
	void set_resizable(const bool resizable);
	bool is_resizable() const;
	void set_selected(const bool selected);
	bool is_selected();
	int64_t get_connection_output_count();
	int64_t get_connection_input_count();
	Vector2 get_connection_output_position(const int64_t idx);
	int64_t get_connection_output_type(const int64_t idx);
	Color get_connection_output_color(const int64_t idx);
	Vector2 get_connection_input_position(const int64_t idx);
	int64_t get_connection_input_type(const int64_t idx);
	Color get_connection_input_color(const int64_t idx);
	void set_show_close_button(const bool show);
	bool is_close_button_visible() const;
	void set_overlay(const int64_t overlay);
	GraphNode::Overlay get_overlay() const;

};

}

#endif