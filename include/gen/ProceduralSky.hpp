#ifndef GODOT_CPP_PROCEDURALSKY_HPP
#define GODOT_CPP_PROCEDURALSKY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "ProceduralSky.hpp"

#include "Sky.hpp"
namespace godot {

class Image;

class ProceduralSky : public Sky {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ProceduralSky"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum TextureSize {
		TEXTURE_SIZE_2048 = 3,
		TEXTURE_SIZE_512 = 1,
		TEXTURE_SIZE_256 = 0,
		TEXTURE_SIZE_4096 = 4,
		TEXTURE_SIZE_MAX = 5,
		TEXTURE_SIZE_1024 = 2,
	};

	// constants


	static ProceduralSky *_new();

	// methods
	void _update_sky();
	void set_sky_top_color(const Color color);
	Color get_sky_top_color() const;
	void set_sky_horizon_color(const Color color);
	Color get_sky_horizon_color() const;
	void set_sky_curve(const double curve);
	double get_sky_curve() const;
	void set_sky_energy(const double energy);
	double get_sky_energy() const;
	void set_ground_bottom_color(const Color color);
	Color get_ground_bottom_color() const;
	void set_ground_horizon_color(const Color color);
	Color get_ground_horizon_color() const;
	void set_ground_curve(const double curve);
	double get_ground_curve() const;
	void set_ground_energy(const double energy);
	double get_ground_energy() const;
	void set_sun_color(const Color color);
	Color get_sun_color() const;
	void set_sun_latitude(const double degrees);
	double get_sun_latitude() const;
	void set_sun_longitude(const double degrees);
	double get_sun_longitude() const;
	void set_sun_angle_min(const double degrees);
	double get_sun_angle_min() const;
	void set_sun_angle_max(const double degrees);
	double get_sun_angle_max() const;
	void set_sun_curve(const double curve);
	double get_sun_curve() const;
	void set_sun_energy(const double energy);
	double get_sun_energy() const;
	void set_texture_size(const int64_t size);
	ProceduralSky::TextureSize get_texture_size() const;
	void _thread_done(const Ref<Image> image);

};

}

#endif