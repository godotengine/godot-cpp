#ifndef GODOT_CPP_CANVASITEM_HPP
#define GODOT_CPP_CANVASITEM_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node.hpp"
namespace godot {

class Texture;
class StyleBox;
class Font;
class Mesh;
class World2D;
class Material;
class InputEvent;

class CanvasItem : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "CanvasItem"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum BlendMode {
		BLEND_MODE_PREMULT_ALPHA = 4,
		BLEND_MODE_SUB = 2,
		BLEND_MODE_DISABLED = 5,
		BLEND_MODE_MUL = 3,
		BLEND_MODE_MIX = 0,
		BLEND_MODE_ADD = 1,
	};

	// constants
	const static int NOTIFICATION_VISIBILITY_CHANGED = 31;
	const static int NOTIFICATION_TRANSFORM_CHANGED = 29;
	const static int NOTIFICATION_EXIT_CANVAS = 33;
	const static int NOTIFICATION_DRAW = 30;
	const static int NOTIFICATION_ENTER_CANVAS = 32;

	// methods
	void _draw();
	void _toplevel_raise_self();
	void _update_callback();
	void _edit_set_state(const Dictionary state);
	Dictionary _edit_get_state() const;
	void _edit_set_position(const Vector2 position);
	Vector2 _edit_get_position() const;
	void _edit_set_scale(const Vector2 scale);
	Vector2 _edit_get_scale() const;
	void _edit_set_rect(const Rect2 rect);
	Rect2 _edit_get_rect() const;
	bool _edit_use_rect() const;
	Rect2 _edit_get_item_and_children_rect() const;
	void _edit_set_rotation(const double degrees);
	double _edit_get_rotation() const;
	bool _edit_use_rotation() const;
	void _edit_set_pivot(const Vector2 pivot);
	Vector2 _edit_get_pivot() const;
	bool _edit_use_pivot() const;
	RID get_canvas_item() const;
	void set_visible(const bool visible);
	bool is_visible() const;
	bool is_visible_in_tree() const;
	void show();
	void hide();
	void update();
	void set_as_toplevel(const bool enable);
	bool is_set_as_toplevel() const;
	void set_light_mask(const int64_t light_mask);
	int64_t get_light_mask() const;
	void set_modulate(const Color modulate);
	Color get_modulate() const;
	void set_self_modulate(const Color self_modulate);
	Color get_self_modulate() const;
	void set_draw_behind_parent(const bool enable);
	bool is_draw_behind_parent_enabled() const;
	void _set_on_top(const bool on_top);
	bool _is_on_top() const;
	void draw_line(const Vector2 from, const Vector2 to, const Color color, const double width = 1, const bool antialiased = false);
	void draw_polyline(const PoolVector2Array points, const Color color, const double width = 1, const bool antialiased = false);
	void draw_polyline_colors(const PoolVector2Array points, const PoolColorArray colors, const double width = 1, const bool antialiased = false);
	void draw_multiline(const PoolVector2Array points, const Color color, const double width = 1, const bool antialiased = false);
	void draw_multiline_colors(const PoolVector2Array points, const PoolColorArray colors, const double width = 1, const bool antialiased = false);
	void draw_rect(const Rect2 rect, const Color color, const bool filled = true);
	void draw_circle(const Vector2 position, const double radius, const Color color);
	void draw_texture(const Ref<Texture> texture, const Vector2 position, const Color modulate = Color(1,1,1,1), const Ref<Texture> normal_map = nullptr);
	void draw_texture_rect(const Ref<Texture> texture, const Rect2 rect, const bool tile, const Color modulate = Color(1,1,1,1), const bool transpose = false, const Ref<Texture> normal_map = nullptr);
	void draw_texture_rect_region(const Ref<Texture> texture, const Rect2 rect, const Rect2 src_rect, const Color modulate = Color(1,1,1,1), const bool transpose = false, const Ref<Texture> normal_map = nullptr, const bool clip_uv = true);
	void draw_style_box(const Ref<StyleBox> style_box, const Rect2 rect);
	void draw_primitive(const PoolVector2Array points, const PoolColorArray colors, const PoolVector2Array uvs, const Ref<Texture> texture = nullptr, const double width = 1, const Ref<Texture> normal_map = nullptr);
	void draw_polygon(const PoolVector2Array points, const PoolColorArray colors, const PoolVector2Array uvs = PoolVector2Array(), const Ref<Texture> texture = nullptr, const Ref<Texture> normal_map = nullptr, const bool antialiased = false);
	void draw_colored_polygon(const PoolVector2Array points, const Color color, const PoolVector2Array uvs = PoolVector2Array(), const Ref<Texture> texture = nullptr, const Ref<Texture> normal_map = nullptr, const bool antialiased = false);
	void draw_string(const Ref<Font> font, const Vector2 position, const String text, const Color modulate = Color(1,1,1,1), const int64_t clip_w = -1);
	double draw_char(const Ref<Font> font, const Vector2 position, const String _char, const String next, const Color modulate = Color(1,1,1,1));
	void draw_mesh(const Ref<Mesh> mesh, const Ref<Texture> texture, const Ref<Texture> normal_map = nullptr);
	void draw_multimesh(const Ref<Mesh> mesh, const Ref<Texture> texture, const Ref<Texture> normal_map = nullptr);
	void draw_set_transform(const Vector2 position, const double rotation, const Vector2 scale);
	void draw_set_transform_matrix(const Transform2D xform);
	Transform2D get_transform() const;
	Transform2D get_global_transform() const;
	Transform2D get_global_transform_with_canvas() const;
	Transform2D get_viewport_transform() const;
	Rect2 get_viewport_rect() const;
	Transform2D get_canvas_transform() const;
	Vector2 get_local_mouse_position() const;
	Vector2 get_global_mouse_position() const;
	RID get_canvas() const;
	Ref<World2D> get_world_2d() const;
	void set_material(const Ref<Material> material);
	Ref<Material> get_material() const;
	void set_use_parent_material(const bool enable);
	bool get_use_parent_material() const;
	void set_notify_local_transform(const bool enable);
	bool is_local_transform_notification_enabled() const;
	void set_notify_transform(const bool enable);
	bool is_transform_notification_enabled() const;
	Vector2 make_canvas_position_local(const Vector2 screen_point) const;
	Ref<InputEvent> make_input_local(const Ref<InputEvent> event) const;

};

}

#endif