#include <CanvasItem.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>
#include <StyleBox.hpp>
#include <Font.hpp>
#include <Mesh.hpp>
#include <World2D.hpp>
#include <Material.hpp>
#include <InputEvent.hpp>


namespace godot {


void *CanvasItem::___get_type_tag()
{
	return (void *) &CanvasItem::___get_type_tag;
}

void *CanvasItem::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

void CanvasItem::_draw() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_draw");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void CanvasItem::_toplevel_raise_self() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_toplevel_raise_self");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void CanvasItem::_update_callback() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_update_callback");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void CanvasItem::_edit_set_state(const Dictionary state) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_set_state");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, state);
}

Dictionary CanvasItem::_edit_get_state() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_get_state");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

void CanvasItem::_edit_set_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_set_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

Vector2 CanvasItem::_edit_get_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_get_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

bool CanvasItem::_edit_use_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_use_position");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CanvasItem::_edit_set_rect(const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_set_rect");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, rect);
}

Rect2 CanvasItem::_edit_get_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_get_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

bool CanvasItem::_edit_use_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_use_rect");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Rect2 CanvasItem::_edit_get_item_and_children_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_get_item_and_children_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void CanvasItem::_edit_set_rotation(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_set_rotation");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

double CanvasItem::_edit_get_rotation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_get_rotation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

bool CanvasItem::_edit_use_rotation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_use_rotation");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CanvasItem::_edit_set_pivot(const Vector2 pivot) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_set_pivot");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, pivot);
}

Vector2 CanvasItem::_edit_get_pivot() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_get_pivot");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

bool CanvasItem::_edit_use_pivot() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_edit_use_pivot");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

RID CanvasItem::get_canvas_item() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_canvas_item");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void CanvasItem::set_visible(const bool visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "set_visible");
	}
	___godot_icall_void_bool(mb, (const Object *) this, visible);
}

bool CanvasItem::is_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "is_visible");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool CanvasItem::is_visible_in_tree() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "is_visible_in_tree");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CanvasItem::show() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "show");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void CanvasItem::hide() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "hide");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void CanvasItem::update() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "update");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void CanvasItem::set_as_toplevel(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "set_as_toplevel");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool CanvasItem::is_set_as_toplevel() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "is_set_as_toplevel");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CanvasItem::set_light_mask(const int64_t light_mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "set_light_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, light_mask);
}

int64_t CanvasItem::get_light_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_light_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void CanvasItem::set_modulate(const Color modulate) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "set_modulate");
	}
	___godot_icall_void_Color(mb, (const Object *) this, modulate);
}

Color CanvasItem::get_modulate() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_modulate");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void CanvasItem::set_self_modulate(const Color self_modulate) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "set_self_modulate");
	}
	___godot_icall_void_Color(mb, (const Object *) this, self_modulate);
}

Color CanvasItem::get_self_modulate() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_self_modulate");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void CanvasItem::set_draw_behind_parent(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "set_draw_behind_parent");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool CanvasItem::is_draw_behind_parent_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "is_draw_behind_parent_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CanvasItem::_set_on_top(const bool on_top) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_set_on_top");
	}
	___godot_icall_void_bool(mb, (const Object *) this, on_top);
}

bool CanvasItem::_is_on_top() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "_is_on_top");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CanvasItem::draw_line(const Vector2 from, const Vector2 to, const Color color, const double width, const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_line");
	}
	___godot_icall_void_Vector2_Vector2_Color_float_bool(mb, (const Object *) this, from, to, color, width, antialiased);
}

void CanvasItem::draw_polyline(const PoolVector2Array points, const Color color, const double width, const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_polyline");
	}
	___godot_icall_void_PoolVector2Array_Color_float_bool(mb, (const Object *) this, points, color, width, antialiased);
}

void CanvasItem::draw_polyline_colors(const PoolVector2Array points, const PoolColorArray colors, const double width, const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_polyline_colors");
	}
	___godot_icall_void_PoolVector2Array_PoolColorArray_float_bool(mb, (const Object *) this, points, colors, width, antialiased);
}

void CanvasItem::draw_multiline(const PoolVector2Array points, const Color color, const double width, const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_multiline");
	}
	___godot_icall_void_PoolVector2Array_Color_float_bool(mb, (const Object *) this, points, color, width, antialiased);
}

void CanvasItem::draw_multiline_colors(const PoolVector2Array points, const PoolColorArray colors, const double width, const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_multiline_colors");
	}
	___godot_icall_void_PoolVector2Array_PoolColorArray_float_bool(mb, (const Object *) this, points, colors, width, antialiased);
}

void CanvasItem::draw_rect(const Rect2 rect, const Color color, const bool filled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_rect");
	}
	___godot_icall_void_Rect2_Color_bool(mb, (const Object *) this, rect, color, filled);
}

void CanvasItem::draw_circle(const Vector2 position, const double radius, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_circle");
	}
	___godot_icall_void_Vector2_float_Color(mb, (const Object *) this, position, radius, color);
}

void CanvasItem::draw_texture(const Ref<Texture> texture, const Vector2 position, const Color modulate, const Ref<Texture> normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_texture");
	}
	___godot_icall_void_Object_Vector2_Color_Object(mb, (const Object *) this, texture.ptr(), position, modulate, normal_map.ptr());
}

void CanvasItem::draw_texture_rect(const Ref<Texture> texture, const Rect2 rect, const bool tile, const Color modulate, const bool transpose, const Ref<Texture> normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_texture_rect");
	}
	___godot_icall_void_Object_Rect2_bool_Color_bool_Object(mb, (const Object *) this, texture.ptr(), rect, tile, modulate, transpose, normal_map.ptr());
}

void CanvasItem::draw_texture_rect_region(const Ref<Texture> texture, const Rect2 rect, const Rect2 src_rect, const Color modulate, const bool transpose, const Ref<Texture> normal_map, const bool clip_uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_texture_rect_region");
	}
	___godot_icall_void_Object_Rect2_Rect2_Color_bool_Object_bool(mb, (const Object *) this, texture.ptr(), rect, src_rect, modulate, transpose, normal_map.ptr(), clip_uv);
}

void CanvasItem::draw_style_box(const Ref<StyleBox> style_box, const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_style_box");
	}
	___godot_icall_void_Object_Rect2(mb, (const Object *) this, style_box.ptr(), rect);
}

void CanvasItem::draw_primitive(const PoolVector2Array points, const PoolColorArray colors, const PoolVector2Array uvs, const Ref<Texture> texture, const double width, const Ref<Texture> normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_primitive");
	}
	___godot_icall_void_PoolVector2Array_PoolColorArray_PoolVector2Array_Object_float_Object(mb, (const Object *) this, points, colors, uvs, texture.ptr(), width, normal_map.ptr());
}

void CanvasItem::draw_polygon(const PoolVector2Array points, const PoolColorArray colors, const PoolVector2Array uvs, const Ref<Texture> texture, const Ref<Texture> normal_map, const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_polygon");
	}
	___godot_icall_void_PoolVector2Array_PoolColorArray_PoolVector2Array_Object_Object_bool(mb, (const Object *) this, points, colors, uvs, texture.ptr(), normal_map.ptr(), antialiased);
}

void CanvasItem::draw_colored_polygon(const PoolVector2Array points, const Color color, const PoolVector2Array uvs, const Ref<Texture> texture, const Ref<Texture> normal_map, const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_colored_polygon");
	}
	___godot_icall_void_PoolVector2Array_Color_PoolVector2Array_Object_Object_bool(mb, (const Object *) this, points, color, uvs, texture.ptr(), normal_map.ptr(), antialiased);
}

void CanvasItem::draw_string(const Ref<Font> font, const Vector2 position, const String text, const Color modulate, const int64_t clip_w) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_string");
	}
	___godot_icall_void_Object_Vector2_String_Color_int(mb, (const Object *) this, font.ptr(), position, text, modulate, clip_w);
}

double CanvasItem::draw_char(const Ref<Font> font, const Vector2 position, const String _char, const String next, const Color modulate) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_char");
	}
	return ___godot_icall_float_Object_Vector2_String_String_Color(mb, (const Object *) this, font.ptr(), position, _char, next, modulate);
}

void CanvasItem::draw_mesh(const Ref<Mesh> mesh, const Ref<Texture> texture, const Ref<Texture> normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_mesh");
	}
	___godot_icall_void_Object_Object_Object(mb, (const Object *) this, mesh.ptr(), texture.ptr(), normal_map.ptr());
}

void CanvasItem::draw_multimesh(const Ref<Mesh> mesh, const Ref<Texture> texture, const Ref<Texture> normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_multimesh");
	}
	___godot_icall_void_Object_Object_Object(mb, (const Object *) this, mesh.ptr(), texture.ptr(), normal_map.ptr());
}

void CanvasItem::draw_set_transform(const Vector2 position, const double rotation, const Vector2 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_set_transform");
	}
	___godot_icall_void_Vector2_float_Vector2(mb, (const Object *) this, position, rotation, scale);
}

void CanvasItem::draw_set_transform_matrix(const Transform2D xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "draw_set_transform_matrix");
	}
	___godot_icall_void_Transform2D(mb, (const Object *) this, xform);
}

Transform2D CanvasItem::get_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

Transform2D CanvasItem::get_global_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_global_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

Transform2D CanvasItem::get_global_transform_with_canvas() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_global_transform_with_canvas");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

Transform2D CanvasItem::get_viewport_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_viewport_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

Rect2 CanvasItem::get_viewport_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_viewport_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

Transform2D CanvasItem::get_canvas_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_canvas_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

Vector2 CanvasItem::get_local_mouse_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_local_mouse_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 CanvasItem::get_global_mouse_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_global_mouse_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

RID CanvasItem::get_canvas() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_canvas");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

Ref<World2D> CanvasItem::get_world_2d() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_world_2d");
	}
	return Ref<World2D>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void CanvasItem::set_material(const Ref<Material> material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "set_material");
	}
	___godot_icall_void_Object(mb, (const Object *) this, material.ptr());
}

Ref<Material> CanvasItem::get_material() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_material");
	}
	return Ref<Material>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void CanvasItem::set_use_parent_material(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "set_use_parent_material");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool CanvasItem::get_use_parent_material() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "get_use_parent_material");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CanvasItem::set_notify_local_transform(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "set_notify_local_transform");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool CanvasItem::is_local_transform_notification_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "is_local_transform_notification_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CanvasItem::set_notify_transform(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "set_notify_transform");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool CanvasItem::is_transform_notification_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "is_transform_notification_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Vector2 CanvasItem::make_canvas_position_local(const Vector2 screen_point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "make_canvas_position_local");
	}
	return ___godot_icall_Vector2_Vector2(mb, (const Object *) this, screen_point);
}

Ref<InputEvent> CanvasItem::make_input_local(const Ref<InputEvent> event) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItem", "make_input_local");
	}
	return Ref<InputEvent>::__internal_constructor(___godot_icall_Object_Object(mb, (const Object *) this, event.ptr()));
}

}