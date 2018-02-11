#ifndef GODOT_CPP_VISUALSERVER_HPP
#define GODOT_CPP_VISUALSERVER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Image.hpp>
#include <VisualServer.hpp>

#include <Object.hpp>
namespace godot {

class Image;
class Object;

class VisualServer : public Object {
	static VisualServer *_singleton;

	VisualServer();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline VisualServer *get_singleton()
	{
		if (!VisualServer::_singleton) {
			VisualServer::_singleton = new VisualServer;
		}
		return VisualServer::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "VisualServer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum ReflectionProbeUpdateMode {
		REFLECTION_PROBE_UPDATE_ONCE = 0,
		REFLECTION_PROBE_UPDATE_ALWAYS = 1,
	};
	enum LightDirectionalShadowDepthRangeMode {
		LIGHT_DIRECTIONAL_SHADOW_DEPTH_RANGE_OPTIMIZED = 1,
		LIGHT_DIRECTIONAL_SHADOW_DEPTH_RANGE_STABLE = 0,
	};
	enum BlendShapeMode {
		BLEND_SHAPE_MODE_NORMALIZED = 0,
		BLEND_SHAPE_MODE_RELATIVE = 1,
	};
	enum PrimitiveType {
		PRIMITIVE_TRIANGLES = 4,
		PRIMITIVE_LINES = 1,
		PRIMITIVE_LINE_LOOP = 3,
		PRIMITIVE_TRIANGLE_FAN = 6,
		PRIMITIVE_MAX = 7,
		PRIMITIVE_POINTS = 0,
		PRIMITIVE_TRIANGLE_STRIP = 5,
		PRIMITIVE_LINE_STRIP = 2,
	};
	enum EnvironmentSSAOQuality {
		ENV_SSAO_QUALITY_HIGH = 2,
		ENV_SSAO_QUALITY_MEDIUM = 1,
		ENV_SSAO_QUALITY_LOW = 0,
	};
	enum EnvironmentDOFBlurQuality {
		ENV_DOF_BLUR_QUALITY_LOW = 0,
		ENV_DOF_BLUR_QUALITY_MEDIUM = 1,
		ENV_DOF_BLUR_QUALITY_HIGH = 2,
	};
	enum RenderInfo {
		INFO_TEXTURE_MEM_USED = 8,
		INFO_VIDEO_MEM_USED = 7,
		INFO_VERTEX_MEM_USED = 9,
		INFO_MATERIAL_CHANGES_IN_FRAME = 2,
		INFO_SURFACE_CHANGES_IN_FRAME = 4,
		INFO_SHADER_CHANGES_IN_FRAME = 3,
		INFO_VERTICES_IN_FRAME = 1,
		INFO_OBJECTS_IN_FRAME = 0,
		INFO_USAGE_VIDEO_MEM_TOTAL = 6,
		INFO_DRAW_CALLS_IN_FRAME = 5,
	};
	enum NinePatchAxisMode {
		NINE_PATCH_TILE_FIT = 2,
		NINE_PATCH_TILE = 1,
		NINE_PATCH_STRETCH = 0,
	};
	enum ViewportRenderInfo {
		VIEWPORT_RENDER_INFO_SHADER_CHANGES_IN_FRAME = 3,
		VIEWPORT_RENDER_INFO_MAX = 6,
		VIEWPORT_RENDER_INFO_SURFACE_CHANGES_IN_FRAME = 4,
		VIEWPORT_RENDER_INFO_VERTICES_IN_FRAME = 1,
		VIEWPORT_RENDER_INFO_OBJECTS_IN_FRAME = 0,
		VIEWPORT_RENDER_INFO_MATERIAL_CHANGES_IN_FRAME = 2,
		VIEWPORT_RENDER_INFO_DRAW_CALLS_IN_FRAME = 5,
	};
	enum ViewportClearMode {
		VIEWPORT_CLEAR_ALWAYS = 0,
		VIEWPORT_CLEAR_ONLY_NEXT_FRAME = 2,
		VIEWPORT_CLEAR_NEVER = 1,
	};
	enum LightOmniShadowDetail {
		LIGHT_OMNI_SHADOW_DETAIL_VERTICAL = 0,
		LIGHT_OMNI_SHADOW_DETAIL_HORIZONTAL = 1,
	};
	enum ShaderMode {
		SHADER_SPATIAL = 0,
		SHADER_MAX = 3,
		SHADER_CANVAS_ITEM = 1,
		SHADER_PARTICLES = 2,
	};
	enum MultimeshTransformFormat {
		MULTIMESH_TRANSFORM_3D = 1,
		MULTIMESH_TRANSFORM_2D = 0,
	};
	enum ShadowCastingSetting {
		SHADOW_CASTING_SETTING_ON = 1,
		SHADOW_CASTING_SETTING_SHADOWS_ONLY = 3,
		SHADOW_CASTING_SETTING_DOUBLE_SIDED = 2,
		SHADOW_CASTING_SETTING_OFF = 0,
	};
	enum ViewportDebugDraw {
		VIEWPORT_DEBUG_DRAW_WIREFRAME = 3,
		VIEWPORT_DEBUG_DRAW_DISABLED = 0,
		VIEWPORT_DEBUG_DRAW_OVERDRAW = 2,
		VIEWPORT_DEBUG_DRAW_UNSHADED = 1,
	};
	enum ViewportUsage {
		VIEWPORT_USAGE_2D_NO_SAMPLING = 1,
		VIEWPORT_USAGE_3D_NO_EFFECTS = 3,
		VIEWPORT_USAGE_3D = 2,
		VIEWPORT_USAGE_2D = 0,
	};
	enum EnvironmentBG {
		ENV_BG_CLEAR_COLOR = 0,
		ENV_BG_SKY = 2,
		ENV_BG_MAX = 6,
		ENV_BG_CANVAS = 4,
		ENV_BG_COLOR = 1,
		ENV_BG_COLOR_SKY = 3,
		ENV_BG_KEEP = 5,
	};
	enum LightOmniShadowMode {
		LIGHT_OMNI_SHADOW_DUAL_PARABOLOID = 0,
		LIGHT_OMNI_SHADOW_CUBE = 1,
	};
	enum TextureFlags {
		TEXTURE_FLAG_FILTER = 4,
		TEXTURE_FLAG_REPEAT = 2,
		TEXTURE_FLAG_USED_FOR_STREAMING = 4096,
		TEXTURE_FLAG_CUBEMAP = 2048,
		TEXTURE_FLAG_ANISOTROPIC_FILTER = 8,
		TEXTURE_FLAG_MIRRORED_REPEAT = 32,
		TEXTURE_FLAG_MIPMAPS = 1,
		TEXTURE_FLAGS_DEFAULT = 7,
		TEXTURE_FLAG_CONVERT_TO_LINEAR = 16,
	};
	enum Features {
		FEATURE_SHADERS = 0,
		FEATURE_MULTITHREADED = 1,
	};
	enum InstanceType {
		INSTANCE_IMMEDIATE = 3,
		INSTANCE_MULTIMESH = 2,
		INSTANCE_REFLECTION_PROBE = 6,
		INSTANCE_NONE = 0,
		INSTANCE_MAX = 9,
		INSTANCE_MESH = 1,
		INSTANCE_LIGHTMAP_CAPTURE = 8,
		INSTANCE_GI_PROBE = 7,
		INSTANCE_GEOMETRY_MASK = 30,
		INSTANCE_LIGHT = 5,
		INSTANCE_PARTICLES = 4,
	};
	enum EnvironmentSSAOBlur {
		ENV_SSAO_BLUR_1x1 = 1,
		ENV_SSAO_BLUR_3x3 = 3,
		ENV_SSAO_BLUR_2x2 = 2,
		ENV_SSAO_BLUR_DISABLED = 0,
	};
	enum EnvironmentToneMapper {
		ENV_TONE_MAPPER_ACES = 3,
		ENV_TONE_MAPPER_FILMIC = 2,
		ENV_TONE_MAPPER_LINEAR = 0,
		ENV_TONE_MAPPER_REINHARDT = 1,
	};
	enum EnvironmentGlowBlendMode {
		GLOW_BLEND_MODE_SCREEN = 1,
		GLOW_BLEND_MODE_REPLACE = 3,
		GLOW_BLEND_MODE_ADDITIVE = 0,
		GLOW_BLEND_MODE_SOFTLIGHT = 2,
	};
	enum MultimeshColorFormat {
		MULTIMESH_COLOR_NONE = 0,
		MULTIMESH_COLOR_FLOAT = 2,
		MULTIMESH_COLOR_8BIT = 1,
	};
	enum CanvasLightShadowFilter {
		CANVAS_LIGHT_FILTER_PCF13 = 5,
		CANVAS_LIGHT_FILTER_PCF9 = 4,
		CANVAS_LIGHT_FILTER_NONE = 0,
		CANVAS_LIGHT_FILTER_PCF3 = 1,
		CANVAS_LIGHT_FILTER_PCF5 = 2,
		CANVAS_LIGHT_FILTER_PCF7 = 3,
	};
	enum ScenarioDebugMode {
		SCENARIO_DEBUG_OVERDRAW = 2,
		SCENARIO_DEBUG_SHADELESS = 3,
		SCENARIO_DEBUG_WIREFRAME = 1,
		SCENARIO_DEBUG_DISABLED = 0,
	};
	enum ViewportUpdateMode {
		VIEWPORT_UPDATE_ALWAYS = 3,
		VIEWPORT_UPDATE_DISABLED = 0,
		VIEWPORT_UPDATE_WHEN_VISIBLE = 2,
		VIEWPORT_UPDATE_ONCE = 1,
	};
	enum ArrayFormat {
		ARRAY_FORMAT_WEIGHTS = 128,
		ARRAY_COMPRESS_VERTEX = 512,
		ARRAY_FLAG_USE_2D_VERTICES = 262144,
		ARRAY_COMPRESS_TANGENT = 2048,
		ARRAY_COMPRESS_NORMAL = 1024,
		ARRAY_FORMAT_COLOR = 8,
		ARRAY_COMPRESS_DEFAULT = 97792,
		ARRAY_COMPRESS_INDEX = 131072,
		ARRAY_COMPRESS_COLOR = 4096,
		ARRAY_FORMAT_TEX_UV = 16,
		ARRAY_FORMAT_TEX_UV2 = 32,
		ARRAY_COMPRESS_TEX_UV = 8192,
		ARRAY_FORMAT_INDEX = 256,
		ARRAY_FORMAT_BONES = 64,
		ARRAY_FORMAT_VERTEX = 1,
		ARRAY_COMPRESS_BONES = 32768,
		ARRAY_FORMAT_TANGENT = 4,
		ARRAY_COMPRESS_WEIGHTS = 65536,
		ARRAY_FORMAT_NORMAL = 2,
		ARRAY_COMPRESS_TEX_UV2 = 16384,
		ARRAY_FLAG_USE_16_BIT_BONES = 524288,
	};
	enum ParticlesDrawOrder {
		PARTICLES_DRAW_ORDER_VIEW_DEPTH = 2,
		PARTICLES_DRAW_ORDER_LIFETIME = 1,
		PARTICLES_DRAW_ORDER_INDEX = 0,
	};
	enum CanvasLightMode {
		CANVAS_LIGHT_MODE_SUB = 1,
		CANVAS_LIGHT_MODE_ADD = 0,
		CANVAS_LIGHT_MODE_MASK = 3,
		CANVAS_LIGHT_MODE_MIX = 2,
	};
	enum LightDirectionalShadowMode {
		LIGHT_DIRECTIONAL_SHADOW_PARALLEL_2_SPLITS = 1,
		LIGHT_DIRECTIONAL_SHADOW_PARALLEL_4_SPLITS = 2,
		LIGHT_DIRECTIONAL_SHADOW_ORTHOGONAL = 0,
	};
	enum LightParam {
		LIGHT_PARAM_SHADOW_SPLIT_3_OFFSET = 11,
		LIGHT_PARAM_SPECULAR = 2,
		LIGHT_PARAM_MAX = 15,
		LIGHT_PARAM_SHADOW_NORMAL_BIAS = 12,
		LIGHT_PARAM_ATTENUATION = 4,
		LIGHT_PARAM_RANGE = 3,
		LIGHT_PARAM_SHADOW_BIAS_SPLIT_SCALE = 14,
		LIGHT_PARAM_SHADOW_MAX_DISTANCE = 8,
		LIGHT_PARAM_SHADOW_BIAS = 13,
		LIGHT_PARAM_SPOT_ATTENUATION = 6,
		LIGHT_PARAM_SHADOW_SPLIT_1_OFFSET = 9,
		LIGHT_PARAM_ENERGY = 0,
		LIGHT_PARAM_CONTACT_SHADOW_SIZE = 7,
		LIGHT_PARAM_SPOT_ANGLE = 5,
		LIGHT_PARAM_SHADOW_SPLIT_2_OFFSET = 10,
	};
	enum ArrayType {
		ARRAY_VERTEX = 0,
		ARRAY_TEX_UV2 = 5,
		ARRAY_MAX = 9,
		ARRAY_BONES = 6,
		ARRAY_NORMAL = 1,
		ARRAY_WEIGHTS = 7,
		ARRAY_COLOR = 3,
		ARRAY_INDEX = 8,
		ARRAY_TANGENT = 2,
		ARRAY_TEX_UV = 4,
	};
	enum CanvasOccluderPolygonCullMode {
		CANVAS_OCCLUDER_POLYGON_CULL_COUNTER_CLOCKWISE = 2,
		CANVAS_OCCLUDER_POLYGON_CULL_CLOCKWISE = 1,
		CANVAS_OCCLUDER_POLYGON_CULL_DISABLED = 0,
	};
	enum InstanceFlags {
		INSTANCE_FLAG_MAX = 1,
		INSTANCE_FLAG_USE_BAKED_LIGHT = 0,
	};
	enum ViewportMSAA {
		VIEWPORT_MSAA_DISABLED = 0,
		VIEWPORT_MSAA_2X = 1,
		VIEWPORT_MSAA_4X = 2,
		VIEWPORT_MSAA_16X = 4,
		VIEWPORT_MSAA_8X = 3,
	};
	enum LightType {
		LIGHT_DIRECTIONAL = 0,
		LIGHT_SPOT = 2,
		LIGHT_OMNI = 1,
	};
	enum CubeMapSide {
		CUBEMAP_LEFT = 0,
		CUBEMAP_RIGHT = 1,
		CUBEMAP_BACK = 5,
		CUBEMAP_FRONT = 4,
		CUBEMAP_TOP = 3,
		CUBEMAP_BOTTOM = 2,
	};

	// constants
	const static int MAX_CURSORS = 8;
	const static int MATERIAL_RENDER_PRIORITY_MAX = 127;
	const static int CANVAS_ITEM_Z_MIN = -4096;
	const static int CANVAS_ITEM_Z_MAX = 4096;
	const static int MATERIAL_RENDER_PRIORITY_MIN = -128;
	const static int NO_INDEX_ARRAY = -1;
	const static int MAX_GLOW_LEVELS = 7;
	const static int ARRAY_WEIGHTS_SIZE = 4;

	// methods
	void force_sync();
	void force_draw(const bool swap_buffers = true);
	void sync();
	void draw(const bool swap_buffers = true);
	RID texture_create();
	RID texture_create_from_image(const Ref<Image> image, const int64_t flags = 7);
	void texture_allocate(const RID texture, const int64_t width, const int64_t height, const int64_t format, const int64_t flags = 7);
	void texture_set_data(const RID texture, const Ref<Image> image, const int64_t cube_side = 0);
	Ref<Image> texture_get_data(const RID texture, const int64_t cube_side = 0) const;
	void texture_set_flags(const RID texture, const int64_t flags);
	int64_t texture_get_flags(const RID texture) const;
	Image::Format texture_get_format(const RID texture) const;
	int64_t texture_get_texid(const RID texture) const;
	int64_t texture_get_width(const RID texture) const;
	int64_t texture_get_height(const RID texture) const;
	void texture_set_size_override(const RID texture, const int64_t width, const int64_t height);
	void texture_set_path(const RID texture, const String path);
	String texture_get_path(const RID texture) const;
	void texture_set_shrink_all_x2_on_set_data(const bool shrink);
	Array texture_debug_usage();
	void textures_keep_original(const bool enable);
	RID sky_create();
	void sky_set_texture(const RID sky, const RID cube_map, const int64_t radiance_size);
	RID shader_create();
	void shader_set_code(const RID shader, const String code);
	String shader_get_code(const RID shader) const;
	Array shader_get_param_list(const RID shader) const;
	void shader_set_default_texture_param(const RID shader, const String name, const RID texture);
	RID shader_get_default_texture_param(const RID shader, const String name) const;
	RID material_create();
	void material_set_shader(const RID shader_material, const RID shader);
	RID material_get_shader(const RID shader_material) const;
	void material_set_param(const RID material, const String parameter, const Variant value);
	Variant material_get_param(const RID material, const String parameter) const;
	void material_set_render_priority(const RID material, const int64_t priority);
	void material_set_line_width(const RID material, const double width);
	void material_set_next_pass(const RID material, const RID next_material);
	RID mesh_create();
	void mesh_add_surface_from_arrays(const RID mesh, const int64_t primtive, const Array arrays, const Array blend_shapes = Array(), const int64_t compress_format = 97792);
	void mesh_set_blend_shape_count(const RID mesh, const int64_t amount);
	int64_t mesh_get_blend_shape_count(const RID mesh) const;
	void mesh_set_blend_shape_mode(const RID mesh, const int64_t mode);
	VisualServer::BlendShapeMode mesh_get_blend_shape_mode(const RID mesh) const;
	void mesh_surface_set_material(const RID mesh, const int64_t surface, const RID material);
	RID mesh_surface_get_material(const RID mesh, const int64_t surface) const;
	int64_t mesh_surface_get_array_len(const RID mesh, const int64_t surface) const;
	int64_t mesh_surface_get_array_index_len(const RID mesh, const int64_t surface) const;
	PoolByteArray mesh_surface_get_array(const RID mesh, const int64_t surface) const;
	PoolByteArray mesh_surface_get_index_array(const RID mesh, const int64_t surface) const;
	Array mesh_surface_get_arrays(const RID mesh, const int64_t surface) const;
	Array mesh_surface_get_blend_shape_arrays(const RID mesh, const int64_t surface) const;
	int64_t mesh_surface_get_format(const RID mesh, const int64_t surface) const;
	VisualServer::PrimitiveType mesh_surface_get_primitive_type(const RID mesh, const int64_t surface) const;
	AABB mesh_surface_get_aabb(const RID mesh, const int64_t surface) const;
	Array mesh_surface_get_skeleton_aabb(const RID mesh, const int64_t surface) const;
	void mesh_remove_surface(const RID mesh, const int64_t index);
	int64_t mesh_get_surface_count(const RID mesh) const;
	void mesh_set_custom_aabb(const RID mesh, const AABB aabb);
	AABB mesh_get_custom_aabb(const RID mesh) const;
	void mesh_clear(const RID mesh);
	void multimesh_allocate(const RID multimesh, const int64_t instances, const int64_t transform_format, const int64_t color_format);
	int64_t multimesh_get_instance_count(const RID multimesh) const;
	void multimesh_set_mesh(const RID multimesh, const RID mesh);
	void multimesh_instance_set_transform(const RID multimesh, const int64_t index, const Transform transform);
	void multimesh_instance_set_transform_2d(const RID multimesh, const int64_t index, const Transform2D transform);
	void multimesh_instance_set_color(const RID multimesh, const int64_t index, const Color color);
	RID multimesh_get_mesh(const RID multimesh) const;
	AABB multimesh_get_aabb(const RID multimesh) const;
	Transform multimesh_instance_get_transform(const RID multimesh, const int64_t index) const;
	Transform2D multimesh_instance_get_transform_2d(const RID multimesh, const int64_t index) const;
	Color multimesh_instance_get_color(const RID multimesh, const int64_t index) const;
	void multimesh_set_visible_instances(const RID multimesh, const int64_t visible);
	int64_t multimesh_get_visible_instances(const RID multimesh) const;
	RID immediate_create();
	void immediate_begin(const RID immediate, const int64_t primitive, const RID texture = RID());
	void immediate_vertex(const RID immediate, const Vector3 vertex);
	void immediate_vertex_2d(const RID immediate, const Vector2 vertex);
	void immediate_normal(const RID immediate, const Vector3 normal);
	void immediate_tangent(const RID immediate, const Plane tangent);
	void immediate_color(const RID immediate, const Color color);
	void immediate_uv(const RID immediate, const Vector2 tex_uv);
	void immediate_uv2(const RID immediate, const Vector2 tex_uv);
	void immediate_end(const RID immediate);
	void immediate_clear(const RID immediate);
	void immediate_set_material(const RID immediate, const RID material);
	RID immediate_get_material(const RID immediate) const;
	RID skeleton_create();
	void skeleton_allocate(const RID skeleton, const int64_t bones, const bool is_2d_skeleton = false);
	int64_t skeleton_get_bone_count(const RID skeleton) const;
	void skeleton_bone_set_transform(const RID skeleton, const int64_t bone, const Transform transform);
	Transform skeleton_bone_get_transform(const RID skeleton, const int64_t bone) const;
	void skeleton_bone_set_transform_2d(const RID skeleton, const int64_t bone, const Transform2D transform);
	Transform2D skeleton_bone_get_transform_2d(const RID skeleton, const int64_t bone) const;
	RID directional_light_create();
	RID omni_light_create();
	RID spot_light_create();
	void light_set_color(const RID light, const Color color);
	void light_set_param(const RID light, const int64_t param, const double value);
	void light_set_shadow(const RID light, const bool enabled);
	void light_set_shadow_color(const RID light, const Color color);
	void light_set_projector(const RID light, const RID texture);
	void light_set_negative(const RID light, const bool enable);
	void light_set_cull_mask(const RID light, const int64_t mask);
	void light_set_reverse_cull_face_mode(const RID light, const bool enabled);
	void light_omni_set_shadow_mode(const RID light, const int64_t mode);
	void light_omni_set_shadow_detail(const RID light, const int64_t detail);
	void light_directional_set_shadow_mode(const RID light, const int64_t mode);
	void light_directional_set_blend_splits(const RID light, const bool enable);
	void light_directional_set_shadow_depth_range_mode(const RID light, const int64_t range_mode);
	RID reflection_probe_create();
	void reflection_probe_set_update_mode(const RID probe, const int64_t mode);
	void reflection_probe_set_intensity(const RID probe, const double intensity);
	void reflection_probe_set_interior_ambient(const RID probe, const Color color);
	void reflection_probe_set_interior_ambient_energy(const RID probe, const double energy);
	void reflection_probe_set_interior_ambient_probe_contribution(const RID probe, const double contrib);
	void reflection_probe_set_max_distance(const RID probe, const double distance);
	void reflection_probe_set_extents(const RID probe, const Vector3 extents);
	void reflection_probe_set_origin_offset(const RID probe, const Vector3 offset);
	void reflection_probe_set_as_interior(const RID probe, const bool enable);
	void reflection_probe_set_enable_box_projection(const RID probe, const bool enable);
	void reflection_probe_set_enable_shadows(const RID probe, const bool enable);
	void reflection_probe_set_cull_mask(const RID probe, const int64_t layers);
	RID gi_probe_create();
	void gi_probe_set_bounds(const RID probe, const AABB bounds);
	AABB gi_probe_get_bounds(const RID probe) const;
	void gi_probe_set_cell_size(const RID probe, const double range);
	double gi_probe_get_cell_size(const RID probe) const;
	void gi_probe_set_to_cell_xform(const RID xform, const Transform arg1);
	Transform gi_probe_get_to_cell_xform(const RID arg0) const;
	void gi_probe_set_dynamic_data(const RID data, const PoolIntArray arg1);
	PoolIntArray gi_probe_get_dynamic_data(const RID arg0) const;
	void gi_probe_set_dynamic_range(const RID range, const int64_t arg1);
	int64_t gi_probe_get_dynamic_range(const RID arg0) const;
	void gi_probe_set_energy(const RID energy, const double arg1);
	double gi_probe_get_energy(const RID arg0) const;
	void gi_probe_set_bias(const RID bias, const double arg1);
	double gi_probe_get_bias(const RID arg0) const;
	void gi_probe_set_normal_bias(const RID bias, const double arg1);
	double gi_probe_get_normal_bias(const RID arg0) const;
	void gi_probe_set_propagation(const RID propagation, const double arg1);
	double gi_probe_get_propagation(const RID arg0) const;
	void gi_probe_set_interior(const RID enable, const bool arg1);
	bool gi_probe_is_interior(const RID arg0) const;
	void gi_probe_set_compress(const RID enable, const bool arg1);
	bool gi_probe_is_compressed(const RID arg0) const;
	RID lightmap_capture_create();
	void lightmap_capture_set_bounds(const RID capture, const AABB bounds);
	AABB lightmap_capture_get_bounds(const RID capture) const;
	void lightmap_capture_set_octree(const RID capture, const PoolByteArray octree);
	void lightmap_capture_set_octree_cell_transform(const RID capture, const Transform xform);
	Transform lightmap_capture_get_octree_cell_transform(const RID capture) const;
	void lightmap_capture_set_octree_cell_subdiv(const RID capture, const int64_t subdiv);
	int64_t lightmap_capture_get_octree_cell_subdiv(const RID capture) const;
	PoolByteArray lightmap_capture_get_octree(const RID capture) const;
	void lightmap_capture_set_energy(const RID capture, const double energy);
	double lightmap_capture_get_energy(const RID capture) const;
	RID particles_create();
	void particles_set_emitting(const RID particles, const bool emitting);
	bool particles_get_emitting(const RID particles);
	void particles_set_amount(const RID particles, const int64_t amount);
	void particles_set_lifetime(const RID particles, const double lifetime);
	void particles_set_one_shot(const RID particles, const bool one_shot);
	void particles_set_pre_process_time(const RID particles, const double time);
	void particles_set_explosiveness_ratio(const RID particles, const double ratio);
	void particles_set_randomness_ratio(const RID particles, const double ratio);
	void particles_set_custom_aabb(const RID particles, const AABB aabb);
	void particles_set_speed_scale(const RID particles, const double scale);
	void particles_set_use_local_coordinates(const RID particles, const bool enable);
	void particles_set_process_material(const RID particles, const RID material);
	void particles_set_fixed_fps(const RID particles, const int64_t fps);
	void particles_set_fractional_delta(const RID particles, const bool enable);
	void particles_restart(const RID particles);
	void particles_set_draw_order(const RID particles, const int64_t order);
	void particles_set_draw_passes(const RID particles, const int64_t count);
	void particles_set_draw_pass_mesh(const RID particles, const int64_t pass, const RID mesh);
	AABB particles_get_current_aabb(const RID particles);
	void particles_set_emission_transform(const RID particles, const Transform transform);
	RID camera_create();
	void camera_set_perspective(const RID camera, const double fovy_degrees, const double z_near, const double z_far);
	void camera_set_orthogonal(const RID camera, const double size, const double z_near, const double z_far);
	void camera_set_transform(const RID camera, const Transform transform);
	void camera_set_cull_mask(const RID camera, const int64_t layers);
	void camera_set_environment(const RID camera, const RID env);
	void camera_set_use_vertical_aspect(const RID camera, const bool enable);
	RID viewport_create();
	void viewport_set_use_arvr(const RID viewport, const bool use_arvr);
	void viewport_set_size(const RID viewport, const int64_t width, const int64_t height);
	void viewport_set_active(const RID viewport, const bool active);
	void viewport_set_parent_viewport(const RID viewport, const RID parent_viewport);
	void viewport_attach_to_screen(const RID viewport, const Rect2 rect = Rect2(0, 0, 0, 0), const int64_t screen = 0);
	void viewport_detach(const RID viewport);
	void viewport_set_update_mode(const RID viewport, const int64_t update_mode);
	void viewport_set_vflip(const RID viewport, const bool enabled);
	void viewport_set_clear_mode(const RID viewport, const int64_t clear_mode);
	RID viewport_get_texture(const RID viewport) const;
	void viewport_set_hide_scenario(const RID viewport, const bool hidden);
	void viewport_set_hide_canvas(const RID viewport, const bool hidden);
	void viewport_set_disable_environment(const RID viewport, const bool disabled);
	void viewport_set_disable_3d(const RID viewport, const bool disabled);
	void viewport_attach_camera(const RID viewport, const RID camera);
	void viewport_set_scenario(const RID viewport, const RID scenario);
	void viewport_attach_canvas(const RID viewport, const RID canvas);
	void viewport_remove_canvas(const RID viewport, const RID canvas);
	void viewport_set_canvas_transform(const RID viewport, const RID canvas, const Transform2D offset);
	void viewport_set_transparent_background(const RID viewport, const bool enabled);
	void viewport_set_global_canvas_transform(const RID viewport, const Transform2D transform);
	void viewport_set_canvas_layer(const RID viewport, const RID canvas, const int64_t layer);
	void viewport_set_shadow_atlas_size(const RID viewport, const int64_t size);
	void viewport_set_shadow_atlas_quadrant_subdivision(const RID viewport, const int64_t quadrant, const int64_t subdivision);
	void viewport_set_msaa(const RID viewport, const int64_t msaa);
	void viewport_set_hdr(const RID viewport, const bool enabled);
	void viewport_set_usage(const RID viewport, const int64_t usage);
	int64_t viewport_get_render_info(const RID viewport, const int64_t info);
	void viewport_set_debug_draw(const RID viewport, const int64_t draw);
	RID environment_create();
	void environment_set_background(const RID env, const int64_t bg);
	void environment_set_sky(const RID env, const RID sky);
	void environment_set_sky_custom_fov(const RID env, const double scale);
	void environment_set_bg_color(const RID env, const Color color);
	void environment_set_bg_energy(const RID env, const double energy);
	void environment_set_canvas_max_layer(const RID env, const int64_t max_layer);
	void environment_set_ambient_light(const RID env, const Color color, const double energy = 1, const double sky_contibution = 0);
	void environment_set_dof_blur_near(const RID env, const bool enable, const double distance, const double transition, const double far_amount, const int64_t quality);
	void environment_set_dof_blur_far(const RID env, const bool enable, const double distance, const double transition, const double far_amount, const int64_t quality);
	void environment_set_glow(const RID env, const bool enable, const int64_t level_flags, const double intensity, const double strength, const double bloom_threshold, const int64_t blend_mode, const double hdr_bleed_threshold, const double hdr_bleed_scale, const bool bicubic_upscale);
	void environment_set_tonemap(const RID env, const int64_t tone_mapper, const double exposure, const double white, const bool auto_exposure, const double min_luminance, const double max_luminance, const double auto_exp_speed, const double auto_exp_grey);
	void environment_set_adjustment(const RID env, const bool enable, const double brightness, const double contrast, const double saturation, const RID ramp);
	void environment_set_ssr(const RID env, const bool enable, const int64_t max_steps, const double fade_in, const double fade_out, const double depth_tolerance, const bool roughness);
	void environment_set_ssao(const RID env, const bool enable, const double radius, const double intensity, const double radius2, const double intensity2, const double bias, const double light_affect, const Color color, const int64_t quality, const int64_t blur, const double bilateral_sharpness);
	void environment_set_fog(const RID env, const bool enable, const Color color, const Color sun_color, const double sun_amount);
	void environment_set_fog_depth(const RID env, const bool enable, const double depth_begin, const double depth_curve, const bool transmit, const double transmit_curve);
	void environment_set_fog_height(const RID env, const bool enable, const double min_height, const double max_height, const double height_curve);
	RID scenario_create();
	void scenario_set_debug(const RID scenario, const int64_t debug_mode);
	void scenario_set_environment(const RID scenario, const RID environment);
	void scenario_set_reflection_atlas_size(const RID scenario, const int64_t p_size, const int64_t subdiv);
	void scenario_set_fallback_environment(const RID scenario, const RID environment);
	RID instance_create2(const RID base, const RID scenario);
	RID instance_create();
	void instance_set_base(const RID instance, const RID base);
	void instance_set_scenario(const RID instance, const RID scenario);
	void instance_set_layer_mask(const RID instance, const int64_t mask);
	void instance_set_transform(const RID instance, const Transform transform);
	void instance_attach_object_instance_id(const RID instance, const int64_t id);
	void instance_set_blend_shape_weight(const RID instance, const int64_t shape, const double weight);
	void instance_set_surface_material(const RID instance, const int64_t surface, const RID material);
	void instance_set_visible(const RID instance, const bool visible);
	void instance_set_use_lightmap(const RID instance, const RID lightmap_instance, const RID lightmap);
	void instance_set_custom_aabb(const RID instance, const AABB aabb);
	void instance_attach_skeleton(const RID instance, const RID skeleton);
	void instance_set_exterior(const RID instance, const bool enabled);
	void instance_set_extra_visibility_margin(const RID instance, const double margin);
	void instance_geometry_set_flag(const RID instance, const int64_t flag, const bool enabled);
	void instance_geometry_set_cast_shadows_setting(const RID instance, const int64_t shadow_casting_setting);
	void instance_geometry_set_material_override(const RID instance, const RID material);
	void instance_geometry_set_draw_range(const RID instance, const double min, const double max, const double min_margin, const double max_margin);
	void instance_geometry_set_as_instance_lod(const RID instance, const RID as_lod_of_instance);
	Array instances_cull_aabb(const AABB aabb, const RID scenario = RID()) const;
	Array instances_cull_ray(const Vector3 from, const Vector3 to, const RID scenario = RID()) const;
	Array instances_cull_convex(const Array convex, const RID scenario = RID()) const;
	RID canvas_create();
	void canvas_set_item_mirroring(const RID canvas, const RID item, const Vector2 mirroring);
	void canvas_set_modulate(const RID canvas, const Color color);
	RID canvas_item_create();
	void canvas_item_set_parent(const RID item, const RID parent);
	void canvas_item_set_visible(const RID item, const bool visible);
	void canvas_item_set_light_mask(const RID item, const int64_t mask);
	void canvas_item_set_transform(const RID item, const Transform2D transform);
	void canvas_item_set_clip(const RID item, const bool clip);
	void canvas_item_set_distance_field_mode(const RID item, const bool enabled);
	void canvas_item_set_custom_rect(const RID item, const bool use_custom_rect, const Rect2 rect = Rect2(0, 0, 0, 0));
	void canvas_item_set_modulate(const RID item, const Color color);
	void canvas_item_set_self_modulate(const RID item, const Color color);
	void canvas_item_set_draw_behind_parent(const RID item, const bool enabled);
	void canvas_item_add_line(const RID item, const Vector2 from, const Vector2 to, const Color color, const double width = 1, const bool antialiased = false);
	void canvas_item_add_polyline(const RID item, const PoolVector2Array points, const PoolColorArray colors, const double width = 1, const bool antialiased = false);
	void canvas_item_add_rect(const RID item, const Rect2 rect, const Color color);
	void canvas_item_add_circle(const RID item, const Vector2 pos, const double radius, const Color color);
	void canvas_item_add_texture_rect(const RID item, const Rect2 rect, const RID texture, const bool tile = false, const Color modulate = Color(1,1,1,1), const bool transpose = false, const RID normal_map = RID());
	void canvas_item_add_texture_rect_region(const RID item, const Rect2 rect, const RID texture, const Rect2 src_rect, const Color modulate = Color(1,1,1,1), const bool transpose = false, const RID normal_map = RID(), const bool clip_uv = true);
	void canvas_item_add_nine_patch(const RID item, const Rect2 rect, const Rect2 source, const RID texture, const Vector2 topleft, const Vector2 bottomright, const int64_t x_axis_mode = 0, const int64_t y_axis_mode = 0, const bool draw_center = true, const Color modulate = Color(1,1,1,1), const RID normal_map = RID());
	void canvas_item_add_primitive(const RID item, const PoolVector2Array points, const PoolColorArray colors, const PoolVector2Array uvs, const RID texture, const double width = 1, const RID normal_map = RID());
	void canvas_item_add_polygon(const RID item, const PoolVector2Array points, const PoolColorArray colors, const PoolVector2Array uvs = PoolVector2Array(), const RID texture = RID(), const RID normal_map = RID(), const bool antialiased = false);
	void canvas_item_add_triangle_array(const RID item, const PoolIntArray indices, const PoolVector2Array points, const PoolColorArray colors, const PoolVector2Array uvs = PoolVector2Array(), const RID texture = RID(), const int64_t count = -1, const RID normal_map = RID());
	void canvas_item_add_mesh(const RID item, const RID mesh, const RID texture, const RID normal_map = RID());
	void canvas_item_add_multimesh(const RID item, const RID mesh, const RID texture, const RID normal_map = RID());
	void canvas_item_add_particles(const RID item, const RID particles, const RID texture, const RID normal_map, const int64_t h_frames, const int64_t v_frames);
	void canvas_item_add_set_transform(const RID item, const Transform2D transform);
	void canvas_item_add_clip_ignore(const RID item, const bool ignore);
	void canvas_item_set_sort_children_by_y(const RID item, const bool enabled);
	void canvas_item_set_z_index(const RID item, const int64_t z_index);
	void canvas_item_set_z_as_relative_to_parent(const RID item, const bool enabled);
	void canvas_item_set_copy_to_backbuffer(const RID item, const bool enabled, const Rect2 rect);
	void canvas_item_clear(const RID item);
	void canvas_item_set_draw_index(const RID item, const int64_t index);
	void canvas_item_set_material(const RID item, const RID material);
	void canvas_item_set_use_parent_material(const RID item, const bool enabled);
	RID canvas_light_create();
	void canvas_light_attach_to_canvas(const RID light, const RID canvas);
	void canvas_light_set_enabled(const RID light, const bool enabled);
	void canvas_light_set_scale(const RID light, const double scale);
	void canvas_light_set_transform(const RID light, const Transform2D transform);
	void canvas_light_set_texture(const RID light, const RID texture);
	void canvas_light_set_texture_offset(const RID light, const Vector2 offset);
	void canvas_light_set_color(const RID light, const Color color);
	void canvas_light_set_height(const RID light, const double height);
	void canvas_light_set_energy(const RID light, const double energy);
	void canvas_light_set_z_range(const RID light, const int64_t min_z, const int64_t max_z);
	void canvas_light_set_layer_range(const RID light, const int64_t min_layer, const int64_t max_layer);
	void canvas_light_set_item_cull_mask(const RID light, const int64_t mask);
	void canvas_light_set_item_shadow_cull_mask(const RID light, const int64_t mask);
	void canvas_light_set_mode(const RID light, const int64_t mode);
	void canvas_light_set_shadow_enabled(const RID light, const bool enabled);
	void canvas_light_set_shadow_buffer_size(const RID light, const int64_t size);
	void canvas_light_set_shadow_gradient_length(const RID light, const double length);
	void canvas_light_set_shadow_filter(const RID light, const int64_t filter);
	void canvas_light_set_shadow_color(const RID light, const Color color);
	void canvas_light_set_shadow_smooth(const RID light, const double smooth);
	RID canvas_light_occluder_create();
	void canvas_light_occluder_attach_to_canvas(const RID occluder, const RID canvas);
	void canvas_light_occluder_set_enabled(const RID occluder, const bool enabled);
	void canvas_light_occluder_set_polygon(const RID occluder, const RID polygon);
	void canvas_light_occluder_set_transform(const RID occluder, const Transform2D transform);
	void canvas_light_occluder_set_light_mask(const RID occluder, const int64_t mask);
	RID canvas_occluder_polygon_create();
	void canvas_occluder_polygon_set_shape(const RID occluder_polygon, const PoolVector2Array shape, const bool closed);
	void canvas_occluder_polygon_set_shape_as_lines(const RID occluder_polygon, const PoolVector2Array shape);
	void canvas_occluder_polygon_set_cull_mode(const RID occluder_polygon, const int64_t mode);
	void black_bars_set_margins(const int64_t left, const int64_t top, const int64_t right, const int64_t bottom);
	void black_bars_set_images(const RID left, const RID top, const RID right, const RID bottom);
	void free_rid(const RID rid);
	void request_frame_drawn_callback(const Object *where, const String method, const Variant userdata);
	bool has_changed() const;
	void init();
	void finish();
	int64_t get_render_info(const int64_t info);
	RID get_test_cube();
	RID get_test_texture();
	RID get_white_texture();
	RID make_sphere_mesh(const int64_t latitudes, const int64_t longitudes, const double radius);
	void set_boot_image(const Ref<Image> image, const Color color, const bool scale);
	void set_default_clear_color(const Color color);
	bool has_feature(const int64_t feature) const;
	bool has_os_feature(const String feature) const;
	void set_debug_generate_wireframes(const bool generate);

};

}

#endif