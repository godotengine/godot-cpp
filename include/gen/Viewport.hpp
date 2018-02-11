#ifndef GODOT_CPP_VIEWPORT_HPP
#define GODOT_CPP_VIEWPORT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Viewport.hpp>

#include <Node.hpp>
namespace godot {

class World2D;
class World;
class InputEvent;
class ViewportTexture;
class Camera;

class Viewport : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Viewport"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum ClearMode {
		CLEAR_MODE_ALWAYS = 0,
		CLEAR_MODE_NEVER = 1,
		CLEAR_MODE_ONLY_NEXT_FRAME = 2,
	};
	enum RenderInfo {
		RENDER_INFO_OBJECTS_IN_FRAME = 0,
		RENDER_INFO_MATERIAL_CHANGES_IN_FRAME = 2,
		RENDER_INFO_SHADER_CHANGES_IN_FRAME = 3,
		RENDER_INFO_MAX = 6,
		RENDER_INFO_VERTICES_IN_FRAME = 1,
		RENDER_INFO_DRAW_CALLS_IN_FRAME = 5,
		RENDER_INFO_SURFACE_CHANGES_IN_FRAME = 4,
	};
	enum Usage {
		USAGE_3D_NO_EFFECTS = 3,
		USAGE_2D = 0,
		USAGE_2D_NO_SAMPLING = 1,
		USAGE_3D = 2,
	};
	enum DebugDraw {
		DEBUG_DRAW_OVERDRAW = 2,
		DEBUG_DRAW_UNSHADED = 1,
		DEBUG_DRAW_DISABLED = 0,
		DEBUG_DRAW_WIREFRAME = 3,
	};
	enum ShadowAtlasQuadrantSubdiv {
		SHADOW_ATLAS_QUADRANT_SUBDIV_4 = 2,
		SHADOW_ATLAS_QUADRANT_SUBDIV_256 = 5,
		SHADOW_ATLAS_QUADRANT_SUBDIV_1 = 1,
		SHADOW_ATLAS_QUADRANT_SUBDIV_16 = 3,
		SHADOW_ATLAS_QUADRANT_SUBDIV_64 = 4,
		SHADOW_ATLAS_QUADRANT_SUBDIV_MAX = 7,
		SHADOW_ATLAS_QUADRANT_SUBDIV_DISABLED = 0,
		SHADOW_ATLAS_QUADRANT_SUBDIV_1024 = 6,
	};
	enum UpdateMode {
		UPDATE_ALWAYS = 3,
		UPDATE_DISABLED = 0,
		UPDATE_WHEN_VISIBLE = 2,
		UPDATE_ONCE = 1,
	};
	enum MSAA {
		MSAA_DISABLED = 0,
		MSAA_2X = 1,
		MSAA_8X = 3,
		MSAA_16X = 4,
		MSAA_4X = 2,
	};

	// constants


	static Viewport *_new();

	// methods
	void set_use_arvr(const bool use);
	bool use_arvr();
	void set_size(const Vector2 size);
	Vector2 get_size() const;
	void set_world_2d(const Ref<World2D> world_2d);
	Ref<World2D> get_world_2d() const;
	Ref<World2D> find_world_2d() const;
	void set_world(const Ref<World> world);
	Ref<World> get_world() const;
	Ref<World> find_world() const;
	void set_canvas_transform(const Transform2D xform);
	Transform2D get_canvas_transform() const;
	void set_global_canvas_transform(const Transform2D xform);
	Transform2D get_global_canvas_transform() const;
	Transform2D get_final_transform() const;
	Rect2 get_visible_rect() const;
	void set_transparent_background(const bool enable);
	bool has_transparent_background() const;
	void _vp_input(const Ref<InputEvent> arg0);
	void _vp_input_text(const String text);
	void _vp_unhandled_input(const Ref<InputEvent> arg0);
	void set_size_override(const bool enable, const Vector2 size = Vector2(-1, -1), const Vector2 margin = Vector2(0, 0));
	Vector2 get_size_override() const;
	bool is_size_override_enabled() const;
	void set_size_override_stretch(const bool enabled);
	bool is_size_override_stretch_enabled() const;
	void set_vflip(const bool enable);
	bool get_vflip() const;
	void set_clear_mode(const int64_t mode);
	Viewport::ClearMode get_clear_mode() const;
	void set_update_mode(const int64_t mode);
	Viewport::UpdateMode get_update_mode() const;
	void set_msaa(const int64_t msaa);
	Viewport::MSAA get_msaa() const;
	void set_hdr(const bool enable);
	bool get_hdr() const;
	void set_usage(const int64_t usage);
	Viewport::Usage get_usage() const;
	void set_debug_draw(const int64_t debug_draw);
	Viewport::DebugDraw get_debug_draw() const;
	int64_t get_render_info(const int64_t info);
	Ref<ViewportTexture> get_texture() const;
	void set_physics_object_picking(const bool enable);
	bool get_physics_object_picking();
	RID get_viewport_rid() const;
	void input(const Ref<InputEvent> local_event);
	void unhandled_input(const Ref<InputEvent> local_event);
	void update_worlds();
	void set_use_own_world(const bool enable);
	bool is_using_own_world() const;
	Camera *get_camera() const;
	void set_as_audio_listener(const bool enable);
	bool is_audio_listener() const;
	void set_as_audio_listener_2d(const bool enable);
	bool is_audio_listener_2d() const;
	void set_attach_to_screen_rect(const Rect2 rect);
	Vector2 get_mouse_position() const;
	void warp_mouse(const Vector2 to_position);
	bool gui_has_modal_stack() const;
	Variant gui_get_drag_data() const;
	void set_disable_input(const bool disable);
	bool is_input_disabled() const;
	void set_disable_3d(const bool disable);
	bool is_3d_disabled() const;
	void _gui_show_tooltip();
	void _gui_remove_focus();
	void set_shadow_atlas_size(const int64_t size);
	int64_t get_shadow_atlas_size() const;
	void set_snap_controls_to_pixels(const bool enabled);
	bool is_snap_controls_to_pixels_enabled() const;
	void set_shadow_atlas_quadrant_subdiv(const int64_t quadrant, const int64_t subdiv);
	Viewport::ShadowAtlasQuadrantSubdiv get_shadow_atlas_quadrant_subdiv(const int64_t quadrant) const;

};

}

#endif