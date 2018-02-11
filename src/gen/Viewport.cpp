#include <Viewport.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <World2D.hpp>
#include <World.hpp>
#include <InputEvent.hpp>
#include <ViewportTexture.hpp>
#include <Camera.hpp>


namespace godot {


void *Viewport::___get_type_tag()
{
	return (void *) &Viewport::___get_type_tag;
}

void *Viewport::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

Viewport *Viewport::_new()
{
	return (Viewport *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Viewport")());
}
void Viewport::set_use_arvr(const bool use) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_use_arvr");
	}
	___godot_icall_void_bool(mb, (const Object *) this, use);
}

bool Viewport::use_arvr() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "use_arvr");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::set_size(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_size");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

Vector2 Viewport::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Viewport::set_world_2d(const Ref<World2D> world_2d) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_world_2d");
	}
	___godot_icall_void_Object(mb, (const Object *) this, world_2d.ptr());
}

Ref<World2D> Viewport::get_world_2d() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_world_2d");
	}
	return Ref<World2D>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Ref<World2D> Viewport::find_world_2d() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "find_world_2d");
	}
	return Ref<World2D>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Viewport::set_world(const Ref<World> world) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_world");
	}
	___godot_icall_void_Object(mb, (const Object *) this, world.ptr());
}

Ref<World> Viewport::get_world() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_world");
	}
	return Ref<World>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

Ref<World> Viewport::find_world() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "find_world");
	}
	return Ref<World>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Viewport::set_canvas_transform(const Transform2D xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_canvas_transform");
	}
	___godot_icall_void_Transform2D(mb, (const Object *) this, xform);
}

Transform2D Viewport::get_canvas_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_canvas_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

void Viewport::set_global_canvas_transform(const Transform2D xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_global_canvas_transform");
	}
	___godot_icall_void_Transform2D(mb, (const Object *) this, xform);
}

Transform2D Viewport::get_global_canvas_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_global_canvas_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

Transform2D Viewport::get_final_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_final_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

Rect2 Viewport::get_visible_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_visible_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void Viewport::set_transparent_background(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_transparent_background");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Viewport::has_transparent_background() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "has_transparent_background");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::_vp_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "_vp_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void Viewport::_vp_input_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "_vp_input_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

void Viewport::_vp_unhandled_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "_vp_unhandled_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void Viewport::set_size_override(const bool enable, const Vector2 size, const Vector2 margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_size_override");
	}
	___godot_icall_void_bool_Vector2_Vector2(mb, (const Object *) this, enable, size, margin);
}

Vector2 Viewport::get_size_override() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_size_override");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

bool Viewport::is_size_override_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "is_size_override_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::set_size_override_stretch(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_size_override_stretch");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Viewport::is_size_override_stretch_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "is_size_override_stretch_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::set_vflip(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_vflip");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Viewport::get_vflip() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_vflip");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::set_clear_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_clear_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Viewport::ClearMode Viewport::get_clear_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_clear_mode");
	}
	return (Viewport::ClearMode) ___godot_icall_int(mb, (const Object *) this);
}

void Viewport::set_update_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_update_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Viewport::UpdateMode Viewport::get_update_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_update_mode");
	}
	return (Viewport::UpdateMode) ___godot_icall_int(mb, (const Object *) this);
}

void Viewport::set_msaa(const int64_t msaa) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_msaa");
	}
	___godot_icall_void_int(mb, (const Object *) this, msaa);
}

Viewport::MSAA Viewport::get_msaa() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_msaa");
	}
	return (Viewport::MSAA) ___godot_icall_int(mb, (const Object *) this);
}

void Viewport::set_hdr(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_hdr");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Viewport::get_hdr() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_hdr");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::set_usage(const int64_t usage) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_usage");
	}
	___godot_icall_void_int(mb, (const Object *) this, usage);
}

Viewport::Usage Viewport::get_usage() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_usage");
	}
	return (Viewport::Usage) ___godot_icall_int(mb, (const Object *) this);
}

void Viewport::set_debug_draw(const int64_t debug_draw) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_debug_draw");
	}
	___godot_icall_void_int(mb, (const Object *) this, debug_draw);
}

Viewport::DebugDraw Viewport::get_debug_draw() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_debug_draw");
	}
	return (Viewport::DebugDraw) ___godot_icall_int(mb, (const Object *) this);
}

int64_t Viewport::get_render_info(const int64_t info) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_render_info");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, info);
}

Ref<ViewportTexture> Viewport::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_texture");
	}
	return Ref<ViewportTexture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Viewport::set_physics_object_picking(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_physics_object_picking");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Viewport::get_physics_object_picking() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_physics_object_picking");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

RID Viewport::get_viewport_rid() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_viewport_rid");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void Viewport::input(const Ref<InputEvent> local_event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, local_event.ptr());
}

void Viewport::unhandled_input(const Ref<InputEvent> local_event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "unhandled_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, local_event.ptr());
}

void Viewport::update_worlds() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "update_worlds");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Viewport::set_use_own_world(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_use_own_world");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Viewport::is_using_own_world() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "is_using_own_world");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Camera *Viewport::get_camera() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_camera");
	}
	return (Camera *) ___godot_icall_Object(mb, (const Object *) this);
}

void Viewport::set_as_audio_listener(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_as_audio_listener");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Viewport::is_audio_listener() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "is_audio_listener");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::set_as_audio_listener_2d(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_as_audio_listener_2d");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Viewport::is_audio_listener_2d() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "is_audio_listener_2d");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::set_attach_to_screen_rect(const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_attach_to_screen_rect");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, rect);
}

Vector2 Viewport::get_mouse_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_mouse_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Viewport::warp_mouse(const Vector2 to_position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "warp_mouse");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, to_position);
}

bool Viewport::gui_has_modal_stack() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "gui_has_modal_stack");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Variant Viewport::gui_get_drag_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "gui_get_drag_data");
	}
	return ___godot_icall_Variant(mb, (const Object *) this);
}

void Viewport::set_disable_input(const bool disable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_disable_input");
	}
	___godot_icall_void_bool(mb, (const Object *) this, disable);
}

bool Viewport::is_input_disabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "is_input_disabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::set_disable_3d(const bool disable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_disable_3d");
	}
	___godot_icall_void_bool(mb, (const Object *) this, disable);
}

bool Viewport::is_3d_disabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "is_3d_disabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::_gui_show_tooltip() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "_gui_show_tooltip");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Viewport::_gui_remove_focus() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "_gui_remove_focus");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Viewport::set_shadow_atlas_size(const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_shadow_atlas_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, size);
}

int64_t Viewport::get_shadow_atlas_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_shadow_atlas_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Viewport::set_snap_controls_to_pixels(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_snap_controls_to_pixels");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Viewport::is_snap_controls_to_pixels_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "is_snap_controls_to_pixels_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Viewport::set_shadow_atlas_quadrant_subdiv(const int64_t quadrant, const int64_t subdiv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "set_shadow_atlas_quadrant_subdiv");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, quadrant, subdiv);
}

Viewport::ShadowAtlasQuadrantSubdiv Viewport::get_shadow_atlas_quadrant_subdiv(const int64_t quadrant) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Viewport", "get_shadow_atlas_quadrant_subdiv");
	}
	return (Viewport::ShadowAtlasQuadrantSubdiv) ___godot_icall_int_int(mb, (const Object *) this, quadrant);
}

}