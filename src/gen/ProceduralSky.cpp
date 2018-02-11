#include <ProceduralSky.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Image.hpp>


namespace godot {


void *ProceduralSky::___get_type_tag()
{
	return (void *) &ProceduralSky::___get_type_tag;
}

void *ProceduralSky::___get_base_type_tag()
{
	return (void *) &Sky::___get_type_tag;
}

ProceduralSky *ProceduralSky::_new()
{
	return (ProceduralSky *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ProceduralSky")());
}
void ProceduralSky::_update_sky() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "_update_sky");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void ProceduralSky::set_sky_top_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sky_top_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color ProceduralSky::get_sky_top_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sky_top_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void ProceduralSky::set_sky_horizon_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sky_horizon_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color ProceduralSky::get_sky_horizon_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sky_horizon_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void ProceduralSky::set_sky_curve(const double curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sky_curve");
	}
	___godot_icall_void_float(mb, (const Object *) this, curve);
}

double ProceduralSky::get_sky_curve() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sky_curve");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ProceduralSky::set_sky_energy(const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sky_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, energy);
}

double ProceduralSky::get_sky_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sky_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ProceduralSky::set_ground_bottom_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_ground_bottom_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color ProceduralSky::get_ground_bottom_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_ground_bottom_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void ProceduralSky::set_ground_horizon_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_ground_horizon_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color ProceduralSky::get_ground_horizon_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_ground_horizon_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void ProceduralSky::set_ground_curve(const double curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_ground_curve");
	}
	___godot_icall_void_float(mb, (const Object *) this, curve);
}

double ProceduralSky::get_ground_curve() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_ground_curve");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ProceduralSky::set_ground_energy(const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_ground_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, energy);
}

double ProceduralSky::get_ground_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_ground_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ProceduralSky::set_sun_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sun_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color ProceduralSky::get_sun_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sun_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void ProceduralSky::set_sun_latitude(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sun_latitude");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

double ProceduralSky::get_sun_latitude() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sun_latitude");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ProceduralSky::set_sun_longitude(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sun_longitude");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

double ProceduralSky::get_sun_longitude() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sun_longitude");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ProceduralSky::set_sun_angle_min(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sun_angle_min");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

double ProceduralSky::get_sun_angle_min() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sun_angle_min");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ProceduralSky::set_sun_angle_max(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sun_angle_max");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

double ProceduralSky::get_sun_angle_max() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sun_angle_max");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ProceduralSky::set_sun_curve(const double curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sun_curve");
	}
	___godot_icall_void_float(mb, (const Object *) this, curve);
}

double ProceduralSky::get_sun_curve() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sun_curve");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ProceduralSky::set_sun_energy(const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_sun_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, energy);
}

double ProceduralSky::get_sun_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_sun_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ProceduralSky::set_texture_size(const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "set_texture_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, size);
}

ProceduralSky::TextureSize ProceduralSky::get_texture_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "get_texture_size");
	}
	return (ProceduralSky::TextureSize) ___godot_icall_int(mb, (const Object *) this);
}

void ProceduralSky::_thread_done(const Ref<Image> image) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProceduralSky", "_thread_done");
	}
	___godot_icall_void_Object(mb, (const Object *) this, image.ptr());
}

}