#ifndef GODOT_CPP_ENVIRONMENT_HPP
#define GODOT_CPP_ENVIRONMENT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Environment.hpp>

#include <Resource.hpp>
namespace godot {

class Sky;
class Texture;

class Environment : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Environment"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum SSAOBlur {
		SSAO_BLUR_3x3 = 3,
		SSAO_BLUR_DISABLED = 0,
		SSAO_BLUR_2x2 = 2,
		SSAO_BLUR_1x1 = 1,
	};
	enum ToneMapper {
		TONE_MAPPER_ACES = 3,
		TONE_MAPPER_LINEAR = 0,
		TONE_MAPPER_REINHARDT = 1,
		TONE_MAPPER_FILMIC = 2,
	};
	enum GlowBlendMode {
		GLOW_BLEND_MODE_SCREEN = 1,
		GLOW_BLEND_MODE_REPLACE = 3,
		GLOW_BLEND_MODE_ADDITIVE = 0,
		GLOW_BLEND_MODE_SOFTLIGHT = 2,
	};
	enum BGMode {
		BG_MAX = 6,
		BG_SKY = 2,
		BG_COLOR_SKY = 3,
		BG_CANVAS = 4,
		BG_KEEP = 5,
		BG_COLOR = 1,
		BG_CLEAR_COLOR = 0,
	};
	enum SSAOQuality {
		SSAO_QUALITY_MEDIUM = 1,
		SSAO_QUALITY_LOW = 0,
		SSAO_QUALITY_HIGH = 2,
	};
	enum DOFBlurQuality {
		DOF_BLUR_QUALITY_MEDIUM = 1,
		DOF_BLUR_QUALITY_HIGH = 2,
		DOF_BLUR_QUALITY_LOW = 0,
	};

	// constants


	static Environment *_new();

	// methods
	void set_background(const int64_t mode);
	void set_sky(const Ref<Sky> sky);
	void set_sky_custom_fov(const double scale);
	void set_bg_color(const Color color);
	void set_bg_energy(const double energy);
	void set_canvas_max_layer(const int64_t layer);
	void set_ambient_light_color(const Color color);
	void set_ambient_light_energy(const double energy);
	void set_ambient_light_sky_contribution(const double energy);
	Environment::BGMode get_background() const;
	Ref<Sky> get_sky() const;
	double get_sky_custom_fov() const;
	Color get_bg_color() const;
	double get_bg_energy() const;
	int64_t get_canvas_max_layer() const;
	Color get_ambient_light_color() const;
	double get_ambient_light_energy() const;
	double get_ambient_light_sky_contribution() const;
	void set_fog_enabled(const bool enabled);
	bool is_fog_enabled() const;
	void set_fog_color(const Color color);
	Color get_fog_color() const;
	void set_fog_sun_color(const Color color);
	Color get_fog_sun_color() const;
	void set_fog_sun_amount(const double amount);
	double get_fog_sun_amount() const;
	void set_fog_depth_enabled(const bool enabled);
	bool is_fog_depth_enabled() const;
	void set_fog_depth_begin(const double distance);
	double get_fog_depth_begin() const;
	void set_fog_depth_curve(const double curve);
	double get_fog_depth_curve() const;
	void set_fog_transmit_enabled(const bool enabled);
	bool is_fog_transmit_enabled() const;
	void set_fog_transmit_curve(const double curve);
	double get_fog_transmit_curve() const;
	void set_fog_height_enabled(const bool enabled);
	bool is_fog_height_enabled() const;
	void set_fog_height_min(const double height);
	double get_fog_height_min() const;
	void set_fog_height_max(const double height);
	double get_fog_height_max() const;
	void set_fog_height_curve(const double curve);
	double get_fog_height_curve() const;
	void set_tonemapper(const int64_t mode);
	Environment::ToneMapper get_tonemapper() const;
	void set_tonemap_exposure(const double exposure);
	double get_tonemap_exposure() const;
	void set_tonemap_white(const double white);
	double get_tonemap_white() const;
	void set_tonemap_auto_exposure(const bool auto_exposure);
	bool get_tonemap_auto_exposure() const;
	void set_tonemap_auto_exposure_max(const double exposure_max);
	double get_tonemap_auto_exposure_max() const;
	void set_tonemap_auto_exposure_min(const double exposure_min);
	double get_tonemap_auto_exposure_min() const;
	void set_tonemap_auto_exposure_speed(const double exposure_speed);
	double get_tonemap_auto_exposure_speed() const;
	void set_tonemap_auto_exposure_grey(const double exposure_grey);
	double get_tonemap_auto_exposure_grey() const;
	void set_ssr_enabled(const bool enabled);
	bool is_ssr_enabled() const;
	void set_ssr_max_steps(const int64_t max_steps);
	int64_t get_ssr_max_steps() const;
	void set_ssr_fade_in(const double fade_in);
	double get_ssr_fade_in() const;
	void set_ssr_fade_out(const double fade_out);
	double get_ssr_fade_out() const;
	void set_ssr_depth_tolerance(const double depth_tolerance);
	double get_ssr_depth_tolerance() const;
	void set_ssr_rough(const bool rough);
	bool is_ssr_rough() const;
	void set_ssao_enabled(const bool enabled);
	bool is_ssao_enabled() const;
	void set_ssao_radius(const double radius);
	double get_ssao_radius() const;
	void set_ssao_intensity(const double intensity);
	double get_ssao_intensity() const;
	void set_ssao_radius2(const double radius);
	double get_ssao_radius2() const;
	void set_ssao_intensity2(const double intensity);
	double get_ssao_intensity2() const;
	void set_ssao_bias(const double bias);
	double get_ssao_bias() const;
	void set_ssao_direct_light_affect(const double amount);
	double get_ssao_direct_light_affect() const;
	void set_ssao_color(const Color color);
	Color get_ssao_color() const;
	void set_ssao_blur(const int64_t mode);
	Environment::SSAOBlur get_ssao_blur() const;
	void set_ssao_quality(const int64_t quality);
	Environment::SSAOQuality get_ssao_quality() const;
	void set_ssao_edge_sharpness(const double edge_sharpness);
	double get_ssao_edge_sharpness() const;
	void set_dof_blur_far_enabled(const bool enabled);
	bool is_dof_blur_far_enabled() const;
	void set_dof_blur_far_distance(const double intensity);
	double get_dof_blur_far_distance() const;
	void set_dof_blur_far_transition(const double intensity);
	double get_dof_blur_far_transition() const;
	void set_dof_blur_far_amount(const double intensity);
	double get_dof_blur_far_amount() const;
	void set_dof_blur_far_quality(const int64_t intensity);
	Environment::DOFBlurQuality get_dof_blur_far_quality() const;
	void set_dof_blur_near_enabled(const bool enabled);
	bool is_dof_blur_near_enabled() const;
	void set_dof_blur_near_distance(const double intensity);
	double get_dof_blur_near_distance() const;
	void set_dof_blur_near_transition(const double intensity);
	double get_dof_blur_near_transition() const;
	void set_dof_blur_near_amount(const double intensity);
	double get_dof_blur_near_amount() const;
	void set_dof_blur_near_quality(const int64_t level);
	Environment::DOFBlurQuality get_dof_blur_near_quality() const;
	void set_glow_enabled(const bool enabled);
	bool is_glow_enabled() const;
	void set_glow_level(const int64_t idx, const bool enabled);
	bool is_glow_level_enabled(const int64_t idx) const;
	void set_glow_intensity(const double intensity);
	double get_glow_intensity() const;
	void set_glow_strength(const double strength);
	double get_glow_strength() const;
	void set_glow_bloom(const double amount);
	double get_glow_bloom() const;
	void set_glow_blend_mode(const int64_t mode);
	Environment::GlowBlendMode get_glow_blend_mode() const;
	void set_glow_hdr_bleed_threshold(const double threshold);
	double get_glow_hdr_bleed_threshold() const;
	void set_glow_hdr_bleed_scale(const double scale);
	double get_glow_hdr_bleed_scale() const;
	void set_glow_bicubic_upscale(const bool enabled);
	bool is_glow_bicubic_upscale_enabled() const;
	void set_adjustment_enable(const bool enabled);
	bool is_adjustment_enabled() const;
	void set_adjustment_brightness(const double brightness);
	double get_adjustment_brightness() const;
	void set_adjustment_contrast(const double contrast);
	double get_adjustment_contrast() const;
	void set_adjustment_saturation(const double saturation);
	double get_adjustment_saturation() const;
	void set_adjustment_color_correction(const Ref<Texture> color_correction);
	Ref<Texture> get_adjustment_color_correction() const;

};

}

#endif