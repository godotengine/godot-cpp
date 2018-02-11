#include <Environment.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Sky.hpp>
#include <Texture.hpp>


namespace godot {


void *Environment::___get_type_tag()
{
	return (void *) &Environment::___get_type_tag;
}

void *Environment::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Environment *Environment::_new()
{
	return (Environment *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Environment")());
}
void Environment::set_background(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_background");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

void Environment::set_sky(const Ref<Sky> sky) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_sky");
	}
	___godot_icall_void_Object(mb, (const Object *) this, sky.ptr());
}

void Environment::set_sky_custom_fov(const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_sky_custom_fov");
	}
	___godot_icall_void_float(mb, (const Object *) this, scale);
}

void Environment::set_bg_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_bg_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

void Environment::set_bg_energy(const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_bg_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, energy);
}

void Environment::set_canvas_max_layer(const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_canvas_max_layer");
	}
	___godot_icall_void_int(mb, (const Object *) this, layer);
}

void Environment::set_ambient_light_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ambient_light_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

void Environment::set_ambient_light_energy(const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ambient_light_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, energy);
}

void Environment::set_ambient_light_sky_contribution(const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ambient_light_sky_contribution");
	}
	___godot_icall_void_float(mb, (const Object *) this, energy);
}

Environment::BGMode Environment::get_background() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_background");
	}
	return (Environment::BGMode) ___godot_icall_int(mb, (const Object *) this);
}

Ref<Sky> Environment::get_sky() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_sky");
	}
	return Ref<Sky>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

double Environment::get_sky_custom_fov() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_sky_custom_fov");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

Color Environment::get_bg_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_bg_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

double Environment::get_bg_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_bg_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

int64_t Environment::get_canvas_max_layer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_canvas_max_layer");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Color Environment::get_ambient_light_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ambient_light_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

double Environment::get_ambient_light_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ambient_light_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Environment::get_ambient_light_sky_contribution() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ambient_light_sky_contribution");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_fog_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_fog_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_fog_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_fog_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color Environment::get_fog_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_fog_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void Environment::set_fog_sun_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_sun_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color Environment::get_fog_sun_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_fog_sun_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void Environment::set_fog_sun_amount(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_sun_amount");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double Environment::get_fog_sun_amount() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_fog_sun_amount");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_fog_depth_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_depth_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_fog_depth_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_fog_depth_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_fog_depth_begin(const double distance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_depth_begin");
	}
	___godot_icall_void_float(mb, (const Object *) this, distance);
}

double Environment::get_fog_depth_begin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_fog_depth_begin");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_fog_depth_curve(const double curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_depth_curve");
	}
	___godot_icall_void_float(mb, (const Object *) this, curve);
}

double Environment::get_fog_depth_curve() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_fog_depth_curve");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_fog_transmit_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_transmit_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_fog_transmit_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_fog_transmit_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_fog_transmit_curve(const double curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_transmit_curve");
	}
	___godot_icall_void_float(mb, (const Object *) this, curve);
}

double Environment::get_fog_transmit_curve() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_fog_transmit_curve");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_fog_height_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_height_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_fog_height_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_fog_height_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_fog_height_min(const double height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_height_min");
	}
	___godot_icall_void_float(mb, (const Object *) this, height);
}

double Environment::get_fog_height_min() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_fog_height_min");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_fog_height_max(const double height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_height_max");
	}
	___godot_icall_void_float(mb, (const Object *) this, height);
}

double Environment::get_fog_height_max() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_fog_height_max");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_fog_height_curve(const double curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_fog_height_curve");
	}
	___godot_icall_void_float(mb, (const Object *) this, curve);
}

double Environment::get_fog_height_curve() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_fog_height_curve");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_tonemapper(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_tonemapper");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Environment::ToneMapper Environment::get_tonemapper() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_tonemapper");
	}
	return (Environment::ToneMapper) ___godot_icall_int(mb, (const Object *) this);
}

void Environment::set_tonemap_exposure(const double exposure) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_tonemap_exposure");
	}
	___godot_icall_void_float(mb, (const Object *) this, exposure);
}

double Environment::get_tonemap_exposure() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_tonemap_exposure");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_tonemap_white(const double white) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_tonemap_white");
	}
	___godot_icall_void_float(mb, (const Object *) this, white);
}

double Environment::get_tonemap_white() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_tonemap_white");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_tonemap_auto_exposure(const bool auto_exposure) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_tonemap_auto_exposure");
	}
	___godot_icall_void_bool(mb, (const Object *) this, auto_exposure);
}

bool Environment::get_tonemap_auto_exposure() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_tonemap_auto_exposure");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_tonemap_auto_exposure_max(const double exposure_max) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_tonemap_auto_exposure_max");
	}
	___godot_icall_void_float(mb, (const Object *) this, exposure_max);
}

double Environment::get_tonemap_auto_exposure_max() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_tonemap_auto_exposure_max");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_tonemap_auto_exposure_min(const double exposure_min) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_tonemap_auto_exposure_min");
	}
	___godot_icall_void_float(mb, (const Object *) this, exposure_min);
}

double Environment::get_tonemap_auto_exposure_min() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_tonemap_auto_exposure_min");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_tonemap_auto_exposure_speed(const double exposure_speed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_tonemap_auto_exposure_speed");
	}
	___godot_icall_void_float(mb, (const Object *) this, exposure_speed);
}

double Environment::get_tonemap_auto_exposure_speed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_tonemap_auto_exposure_speed");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_tonemap_auto_exposure_grey(const double exposure_grey) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_tonemap_auto_exposure_grey");
	}
	___godot_icall_void_float(mb, (const Object *) this, exposure_grey);
}

double Environment::get_tonemap_auto_exposure_grey() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_tonemap_auto_exposure_grey");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_ssr_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssr_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_ssr_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_ssr_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_ssr_max_steps(const int64_t max_steps) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssr_max_steps");
	}
	___godot_icall_void_int(mb, (const Object *) this, max_steps);
}

int64_t Environment::get_ssr_max_steps() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssr_max_steps");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Environment::set_ssr_fade_in(const double fade_in) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssr_fade_in");
	}
	___godot_icall_void_float(mb, (const Object *) this, fade_in);
}

double Environment::get_ssr_fade_in() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssr_fade_in");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_ssr_fade_out(const double fade_out) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssr_fade_out");
	}
	___godot_icall_void_float(mb, (const Object *) this, fade_out);
}

double Environment::get_ssr_fade_out() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssr_fade_out");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_ssr_depth_tolerance(const double depth_tolerance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssr_depth_tolerance");
	}
	___godot_icall_void_float(mb, (const Object *) this, depth_tolerance);
}

double Environment::get_ssr_depth_tolerance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssr_depth_tolerance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_ssr_rough(const bool rough) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssr_rough");
	}
	___godot_icall_void_bool(mb, (const Object *) this, rough);
}

bool Environment::is_ssr_rough() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_ssr_rough");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_ssao_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_ssao_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_ssao_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_ssao_radius(const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_radius");
	}
	___godot_icall_void_float(mb, (const Object *) this, radius);
}

double Environment::get_ssao_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssao_radius");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_ssao_intensity(const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_intensity");
	}
	___godot_icall_void_float(mb, (const Object *) this, intensity);
}

double Environment::get_ssao_intensity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssao_intensity");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_ssao_radius2(const double radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_radius2");
	}
	___godot_icall_void_float(mb, (const Object *) this, radius);
}

double Environment::get_ssao_radius2() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssao_radius2");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_ssao_intensity2(const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_intensity2");
	}
	___godot_icall_void_float(mb, (const Object *) this, intensity);
}

double Environment::get_ssao_intensity2() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssao_intensity2");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_ssao_bias(const double bias) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_bias");
	}
	___godot_icall_void_float(mb, (const Object *) this, bias);
}

double Environment::get_ssao_bias() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssao_bias");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_ssao_direct_light_affect(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_direct_light_affect");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double Environment::get_ssao_direct_light_affect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssao_direct_light_affect");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_ssao_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color Environment::get_ssao_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssao_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void Environment::set_ssao_blur(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_blur");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Environment::SSAOBlur Environment::get_ssao_blur() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssao_blur");
	}
	return (Environment::SSAOBlur) ___godot_icall_int(mb, (const Object *) this);
}

void Environment::set_ssao_quality(const int64_t quality) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_quality");
	}
	___godot_icall_void_int(mb, (const Object *) this, quality);
}

Environment::SSAOQuality Environment::get_ssao_quality() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssao_quality");
	}
	return (Environment::SSAOQuality) ___godot_icall_int(mb, (const Object *) this);
}

void Environment::set_ssao_edge_sharpness(const double edge_sharpness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_ssao_edge_sharpness");
	}
	___godot_icall_void_float(mb, (const Object *) this, edge_sharpness);
}

double Environment::get_ssao_edge_sharpness() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_ssao_edge_sharpness");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_dof_blur_far_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_dof_blur_far_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_dof_blur_far_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_dof_blur_far_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_dof_blur_far_distance(const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_dof_blur_far_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, intensity);
}

double Environment::get_dof_blur_far_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_dof_blur_far_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_dof_blur_far_transition(const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_dof_blur_far_transition");
	}
	___godot_icall_void_float(mb, (const Object *) this, intensity);
}

double Environment::get_dof_blur_far_transition() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_dof_blur_far_transition");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_dof_blur_far_amount(const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_dof_blur_far_amount");
	}
	___godot_icall_void_float(mb, (const Object *) this, intensity);
}

double Environment::get_dof_blur_far_amount() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_dof_blur_far_amount");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_dof_blur_far_quality(const int64_t intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_dof_blur_far_quality");
	}
	___godot_icall_void_int(mb, (const Object *) this, intensity);
}

Environment::DOFBlurQuality Environment::get_dof_blur_far_quality() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_dof_blur_far_quality");
	}
	return (Environment::DOFBlurQuality) ___godot_icall_int(mb, (const Object *) this);
}

void Environment::set_dof_blur_near_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_dof_blur_near_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_dof_blur_near_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_dof_blur_near_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_dof_blur_near_distance(const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_dof_blur_near_distance");
	}
	___godot_icall_void_float(mb, (const Object *) this, intensity);
}

double Environment::get_dof_blur_near_distance() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_dof_blur_near_distance");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_dof_blur_near_transition(const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_dof_blur_near_transition");
	}
	___godot_icall_void_float(mb, (const Object *) this, intensity);
}

double Environment::get_dof_blur_near_transition() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_dof_blur_near_transition");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_dof_blur_near_amount(const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_dof_blur_near_amount");
	}
	___godot_icall_void_float(mb, (const Object *) this, intensity);
}

double Environment::get_dof_blur_near_amount() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_dof_blur_near_amount");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_dof_blur_near_quality(const int64_t level) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_dof_blur_near_quality");
	}
	___godot_icall_void_int(mb, (const Object *) this, level);
}

Environment::DOFBlurQuality Environment::get_dof_blur_near_quality() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_dof_blur_near_quality");
	}
	return (Environment::DOFBlurQuality) ___godot_icall_int(mb, (const Object *) this);
}

void Environment::set_glow_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_glow_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_glow_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_glow_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_glow_level(const int64_t idx, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_glow_level");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, idx, enabled);
}

bool Environment::is_glow_level_enabled(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_glow_level_enabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

void Environment::set_glow_intensity(const double intensity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_glow_intensity");
	}
	___godot_icall_void_float(mb, (const Object *) this, intensity);
}

double Environment::get_glow_intensity() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_glow_intensity");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_glow_strength(const double strength) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_glow_strength");
	}
	___godot_icall_void_float(mb, (const Object *) this, strength);
}

double Environment::get_glow_strength() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_glow_strength");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_glow_bloom(const double amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_glow_bloom");
	}
	___godot_icall_void_float(mb, (const Object *) this, amount);
}

double Environment::get_glow_bloom() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_glow_bloom");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_glow_blend_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_glow_blend_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Environment::GlowBlendMode Environment::get_glow_blend_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_glow_blend_mode");
	}
	return (Environment::GlowBlendMode) ___godot_icall_int(mb, (const Object *) this);
}

void Environment::set_glow_hdr_bleed_threshold(const double threshold) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_glow_hdr_bleed_threshold");
	}
	___godot_icall_void_float(mb, (const Object *) this, threshold);
}

double Environment::get_glow_hdr_bleed_threshold() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_glow_hdr_bleed_threshold");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_glow_hdr_bleed_scale(const double scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_glow_hdr_bleed_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, scale);
}

double Environment::get_glow_hdr_bleed_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_glow_hdr_bleed_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_glow_bicubic_upscale(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_glow_bicubic_upscale");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_glow_bicubic_upscale_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_glow_bicubic_upscale_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_adjustment_enable(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_adjustment_enable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Environment::is_adjustment_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "is_adjustment_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Environment::set_adjustment_brightness(const double brightness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_adjustment_brightness");
	}
	___godot_icall_void_float(mb, (const Object *) this, brightness);
}

double Environment::get_adjustment_brightness() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_adjustment_brightness");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_adjustment_contrast(const double contrast) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_adjustment_contrast");
	}
	___godot_icall_void_float(mb, (const Object *) this, contrast);
}

double Environment::get_adjustment_contrast() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_adjustment_contrast");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_adjustment_saturation(const double saturation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_adjustment_saturation");
	}
	___godot_icall_void_float(mb, (const Object *) this, saturation);
}

double Environment::get_adjustment_saturation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_adjustment_saturation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Environment::set_adjustment_color_correction(const Ref<Texture> color_correction) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "set_adjustment_color_correction");
	}
	___godot_icall_void_Object(mb, (const Object *) this, color_correction.ptr());
}

Ref<Texture> Environment::get_adjustment_color_correction() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Environment", "get_adjustment_color_correction");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}