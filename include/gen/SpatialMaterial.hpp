#ifndef GODOT_CPP_SPATIALMATERIAL_HPP
#define GODOT_CPP_SPATIALMATERIAL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <SpatialMaterial.hpp>

#include <Material.hpp>
namespace godot {

class Texture;

class SpatialMaterial : public Material {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "SpatialMaterial"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum EmissionOperator {
		EMISSION_OP_MULTIPLY = 1,
		EMISSION_OP_ADD = 0,
	};
	enum DiffuseMode {
		DIFFUSE_OREN_NAYAR = 3,
		DIFFUSE_TOON = 4,
		DIFFUSE_LAMBERT = 1,
		DIFFUSE_BURLEY = 0,
		DIFFUSE_LAMBERT_WRAP = 2,
	};
	enum SpecularMode {
		SPECULAR_SCHLICK_GGX = 0,
		SPECULAR_PHONG = 2,
		SPECULAR_BLINN = 1,
		SPECULAR_TOON = 3,
		SPECULAR_DISABLED = 4,
	};
	enum Feature {
		FEATURE_CLEARCOAT = 4,
		FEATURE_TRANSMISSION = 9,
		FEATURE_NORMAL_MAPPING = 2,
		FEATURE_RIM = 3,
		FEATURE_SUBSURACE_SCATTERING = 8,
		FEATURE_DEPTH_MAPPING = 7,
		FEATURE_AMBIENT_OCCLUSION = 6,
		FEATURE_MAX = 12,
		FEATURE_TRANSPARENT = 0,
		FEATURE_DETAIL = 11,
		FEATURE_REFRACTION = 10,
		FEATURE_EMISSION = 1,
		FEATURE_ANISOTROPY = 5,
	};
	enum Flags {
		FLAG_SRGB_VERTEX_COLOR = 4,
		FLAG_UV1_USE_TRIPLANAR = 7,
		FLAG_USE_VERTEX_LIGHTING = 1,
		FLAG_USE_POINT_SIZE = 5,
		FLAG_ALBEDO_TEXTURE_FORCE_SRGB = 13,
		FLAG_EMISSION_ON_UV2 = 11,
		FLAG_MAX = 14,
		FLAG_FIXED_SIZE = 6,
		FLAG_UV2_USE_TRIPLANAR = 8,
		FLAG_ALBEDO_FROM_VERTEX_COLOR = 3,
		FLAG_UNSHADED = 0,
		FLAG_TRIPLANAR_USE_WORLD = 9,
		FLAG_USE_ALPHA_SCISSOR = 12,
		FLAG_AO_ON_UV2 = 10,
		FLAG_DISABLE_DEPTH_TEST = 2,
	};
	enum CullMode {
		CULL_BACK = 0,
		CULL_DISABLED = 2,
		CULL_FRONT = 1,
	};
	enum DetailUV {
		DETAIL_UV_1 = 0,
		DETAIL_UV_2 = 1,
	};
	enum BillboardMode {
		BILLBOARD_PARTICLES = 3,
		BILLBOARD_FIXED_Y = 2,
		BILLBOARD_ENABLED = 1,
		BILLBOARD_DISABLED = 0,
	};
	enum DepthDrawMode {
		DEPTH_DRAW_OPAQUE_ONLY = 0,
		DEPTH_DRAW_ALPHA_OPAQUE_PREPASS = 3,
		DEPTH_DRAW_DISABLED = 2,
		DEPTH_DRAW_ALWAYS = 1,
	};
	enum TextureChannel {
		TEXTURE_CHANNEL_BLUE = 2,
		TEXTURE_CHANNEL_ALPHA = 3,
		TEXTURE_CHANNEL_GREEN = 1,
		TEXTURE_CHANNEL_RED = 0,
		TEXTURE_CHANNEL_GRAYSCALE = 4,
	};
	enum BlendMode {
		BLEND_MODE_SUB = 2,
		BLEND_MODE_MUL = 3,
		BLEND_MODE_MIX = 0,
		BLEND_MODE_ADD = 1,
	};
	enum TextureParam {
		TEXTURE_DETAIL_ALBEDO = 14,
		TEXTURE_ALBEDO = 0,
		TEXTURE_METALLIC = 1,
		TEXTURE_TRANSMISSION = 11,
		TEXTURE_DEPTH = 9,
		TEXTURE_FLOWMAP = 7,
		TEXTURE_SUBSURFACE_SCATTERING = 10,
		TEXTURE_EMISSION = 3,
		TEXTURE_ROUGHNESS = 2,
		TEXTURE_NORMAL = 4,
		TEXTURE_CLEARCOAT = 6,
		TEXTURE_REFRACTION = 12,
		TEXTURE_AMBIENT_OCCLUSION = 8,
		TEXTURE_MAX = 16,
		TEXTURE_DETAIL_NORMAL = 15,
		TEXTURE_DETAIL_MASK = 13,
		TEXTURE_RIM = 5,
	};

	// constants


	static SpatialMaterial *_new();

	// methods
	void set_albedo(const Color albedo);
	Color get_albedo() const;
	void set_specular(const double specular);
	double get_specular() const;
	void set_metallic(const double metallic);
	double get_metallic() const;
	void set_roughness(const double roughness);
	double get_roughness() const;
	void set_emission(const Color emission);
	Color get_emission() const;
	void set_emission_energy(const double emission_energy);
	double get_emission_energy() const;
	void set_normal_scale(const double normal_scale);
	double get_normal_scale() const;
	void set_rim(const double rim);
	double get_rim() const;
	void set_rim_tint(const double rim_tint);
	double get_rim_tint() const;
	void set_clearcoat(const double clearcoat);
	double get_clearcoat() const;
	void set_clearcoat_gloss(const double clearcoat_gloss);
	double get_clearcoat_gloss() const;
	void set_anisotropy(const double anisotropy);
	double get_anisotropy() const;
	void set_depth_scale(const double depth_scale);
	double get_depth_scale() const;
	void set_subsurface_scattering_strength(const double strength);
	double get_subsurface_scattering_strength() const;
	void set_transmission(const Color transmission);
	Color get_transmission() const;
	void set_refraction(const double refraction);
	double get_refraction() const;
	void set_line_width(const double line_width);
	double get_line_width() const;
	void set_point_size(const double point_size);
	double get_point_size() const;
	void set_detail_uv(const int64_t detail_uv);
	SpatialMaterial::DetailUV get_detail_uv() const;
	void set_blend_mode(const int64_t blend_mode);
	SpatialMaterial::BlendMode get_blend_mode() const;
	void set_depth_draw_mode(const int64_t depth_draw_mode);
	SpatialMaterial::DepthDrawMode get_depth_draw_mode() const;
	void set_cull_mode(const int64_t cull_mode);
	SpatialMaterial::CullMode get_cull_mode() const;
	void set_diffuse_mode(const int64_t diffuse_mode);
	SpatialMaterial::DiffuseMode get_diffuse_mode() const;
	void set_specular_mode(const int64_t specular_mode);
	SpatialMaterial::SpecularMode get_specular_mode() const;
	void set_flag(const int64_t flag, const bool enable);
	bool get_flag(const int64_t flag) const;
	void set_feature(const int64_t feature, const bool enable);
	bool get_feature(const int64_t feature) const;
	void set_texture(const int64_t param, const Ref<Texture> texture);
	Ref<Texture> get_texture(const int64_t param) const;
	void set_detail_blend_mode(const int64_t detail_blend_mode);
	SpatialMaterial::BlendMode get_detail_blend_mode() const;
	void set_uv1_scale(const Vector3 scale);
	Vector3 get_uv1_scale() const;
	void set_uv1_offset(const Vector3 offset);
	Vector3 get_uv1_offset() const;
	void set_uv1_triplanar_blend_sharpness(const double sharpness);
	double get_uv1_triplanar_blend_sharpness() const;
	void set_uv2_scale(const Vector3 scale);
	Vector3 get_uv2_scale() const;
	void set_uv2_offset(const Vector3 offset);
	Vector3 get_uv2_offset() const;
	void set_uv2_triplanar_blend_sharpness(const double sharpness);
	double get_uv2_triplanar_blend_sharpness() const;
	void set_billboard_mode(const int64_t mode);
	SpatialMaterial::BillboardMode get_billboard_mode() const;
	void set_particles_anim_h_frames(const int64_t frames);
	int64_t get_particles_anim_h_frames() const;
	void set_particles_anim_v_frames(const int64_t frames);
	int64_t get_particles_anim_v_frames() const;
	void set_particles_anim_loop(const int64_t frames);
	int64_t get_particles_anim_loop() const;
	void set_depth_deep_parallax(const bool enable);
	bool is_depth_deep_parallax_enabled() const;
	void set_depth_deep_parallax_min_layers(const int64_t layer);
	int64_t get_depth_deep_parallax_min_layers() const;
	void set_depth_deep_parallax_max_layers(const int64_t layer);
	int64_t get_depth_deep_parallax_max_layers() const;
	void set_grow(const double amount);
	double get_grow() const;
	void set_emission_operator(const int64_t _operator);
	SpatialMaterial::EmissionOperator get_emission_operator() const;
	void set_ao_light_affect(const double amount);
	double get_ao_light_affect() const;
	void set_alpha_scissor_threshold(const double threshold);
	double get_alpha_scissor_threshold() const;
	void set_grow_enabled(const bool enable);
	bool is_grow_enabled() const;
	void set_metallic_texture_channel(const int64_t channel);
	SpatialMaterial::TextureChannel get_metallic_texture_channel() const;
	void set_roughness_texture_channel(const int64_t channel);
	SpatialMaterial::TextureChannel get_roughness_texture_channel() const;
	void set_ao_texture_channel(const int64_t channel);
	SpatialMaterial::TextureChannel get_ao_texture_channel() const;
	void set_refraction_texture_channel(const int64_t channel);
	SpatialMaterial::TextureChannel get_refraction_texture_channel() const;
	void set_proximity_fade(const bool enabled);
	bool is_proximity_fade_enabled() const;
	void set_proximity_fade_distance(const double distance);
	double get_proximity_fade_distance() const;
	void set_distance_fade(const bool enabled);
	bool is_distance_fade_enabled() const;
	void set_distance_fade_max_distance(const double distance);
	double get_distance_fade_max_distance() const;
	void set_distance_fade_min_distance(const double distance);
	double get_distance_fade_min_distance() const;

};

}

#endif