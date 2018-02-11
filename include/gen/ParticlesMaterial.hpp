#ifndef GODOT_CPP_PARTICLESMATERIAL_HPP
#define GODOT_CPP_PARTICLESMATERIAL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <ParticlesMaterial.hpp>

#include <Material.hpp>
namespace godot {

class Texture;
class CurveTexture;
class GradientTexture;

class ParticlesMaterial : public Material {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ParticlesMaterial"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Flags {
		FLAG_ALIGN_Y_TO_VELOCITY = 0,
		FLAG_ROTATE_Y = 1,
		FLAG_MAX = 4,
	};
	enum EmissionShape {
		EMISSION_SHAPE_SPHERE = 1,
		EMISSION_SHAPE_BOX = 2,
		EMISSION_SHAPE_POINT = 0,
		EMISSION_SHAPE_DIRECTED_POINTS = 4,
		EMISSION_SHAPE_POINTS = 3,
	};
	enum Parameter {
		PARAM_TANGENTIAL_ACCEL = 5,
		PARAM_HUE_VARIATION = 9,
		PARAM_ANGULAR_VELOCITY = 1,
		PARAM_INITIAL_LINEAR_VELOCITY = 0,
		PARAM_SCALE = 8,
		PARAM_RADIAL_ACCEL = 4,
		PARAM_ANGLE = 7,
		PARAM_ORBIT_VELOCITY = 2,
		PARAM_ANIM_SPEED = 10,
		PARAM_LINEAR_ACCEL = 3,
		PARAM_DAMPING = 6,
		PARAM_ANIM_OFFSET = 11,
		PARAM_MAX = 12,
	};

	// constants


	static ParticlesMaterial *_new();

	// methods
	void set_spread(const double degrees);
	double get_spread() const;
	void set_flatness(const double amount);
	double get_flatness() const;
	void set_param(const int64_t param, const double value);
	double get_param(const int64_t param) const;
	void set_param_randomness(const int64_t param, const double randomness);
	double get_param_randomness(const int64_t param) const;
	void set_param_texture(const int64_t param, const Ref<Texture> texture);
	Ref<Texture> get_param_texture(const int64_t param) const;
	void set_color(const Color color);
	Color get_color() const;
	void set_color_ramp(const Ref<Texture> ramp);
	Ref<Texture> get_color_ramp() const;
	void set_flag(const int64_t flag, const bool enable);
	bool get_flag(const int64_t flag) const;
	void set_emission_shape(const int64_t shape);
	ParticlesMaterial::EmissionShape get_emission_shape() const;
	void set_emission_sphere_radius(const double radius);
	double get_emission_sphere_radius() const;
	void set_emission_box_extents(const Vector3 extents);
	Vector3 get_emission_box_extents() const;
	void set_emission_point_texture(const Ref<Texture> texture);
	Ref<Texture> get_emission_point_texture() const;
	void set_emission_normal_texture(const Ref<Texture> texture);
	Ref<Texture> get_emission_normal_texture() const;
	void set_emission_color_texture(const Ref<Texture> texture);
	Ref<Texture> get_emission_color_texture() const;
	void set_emission_point_count(const int64_t point_count);
	int64_t get_emission_point_count() const;
	void set_trail_divisor(const int64_t divisor);
	int64_t get_trail_divisor() const;
	void set_trail_size_modifier(const Ref<CurveTexture> texture);
	Ref<CurveTexture> get_trail_size_modifier() const;
	void set_trail_color_modifier(const Ref<GradientTexture> texture);
	Ref<GradientTexture> get_trail_color_modifier() const;
	Vector3 get_gravity() const;
	void set_gravity(const Vector3 accel_vec);

};

}

#endif