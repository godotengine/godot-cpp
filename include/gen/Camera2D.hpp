#ifndef GODOT_CPP_CAMERA2D_HPP
#define GODOT_CPP_CAMERA2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Camera2D.hpp"

#include "Node2D.hpp"
namespace godot {

class Object;
class Node;

class Camera2D : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Camera2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum AnchorMode {
		ANCHOR_MODE_FIXED_TOP_LEFT = 0,
		ANCHOR_MODE_DRAG_CENTER = 1,
	};

	// constants


	static Camera2D *_new();

	// methods
	void set_offset(const Vector2 offset);
	Vector2 get_offset() const;
	void set_anchor_mode(const int64_t anchor_mode);
	Camera2D::AnchorMode get_anchor_mode() const;
	void set_rotating(const bool rotating);
	bool is_rotating() const;
	void make_current();
	void clear_current();
	void _make_current(const Object *arg0);
	void _update_scroll();
	void _set_current(const bool current);
	bool is_current() const;
	void set_limit(const int64_t margin, const int64_t limit);
	int64_t get_limit(const int64_t margin) const;
	void set_limit_smoothing_enabled(const bool limit_smoothing_enabled);
	bool is_limit_smoothing_enabled() const;
	void set_v_drag_enabled(const bool enabled);
	bool is_v_drag_enabled() const;
	void set_h_drag_enabled(const bool enabled);
	bool is_h_drag_enabled() const;
	void set_v_offset(const double ofs);
	double get_v_offset() const;
	void set_h_offset(const double ofs);
	double get_h_offset() const;
	void set_drag_margin(const int64_t margin, const double drag_margin);
	double get_drag_margin(const int64_t margin) const;
	Vector2 get_camera_position() const;
	Vector2 get_camera_screen_center() const;
	void set_zoom(const Vector2 zoom);
	Vector2 get_zoom() const;
	void set_custom_viewport(const Object *viewport);
	Node *get_custom_viewport() const;
	void set_follow_smoothing(const double follow_smoothing);
	double get_follow_smoothing() const;
	void set_enable_follow_smoothing(const bool follow_smoothing);
	bool is_follow_smoothing_enabled() const;
	void force_update_scroll();
	void reset_smoothing();
	void align();
	void _set_old_smoothing(const double follow_smoothing);
	void set_screen_drawing_enabled(const bool screen_drawing_enabled);
	bool is_screen_drawing_enabled() const;
	void set_limit_drawing_enabled(const bool limit_drawing_enabled);
	bool is_limit_drawing_enabled() const;
	void set_margin_drawing_enabled(const bool margin_drawing_enabled);
	bool is_margin_drawing_enabled() const;

};

}

#endif