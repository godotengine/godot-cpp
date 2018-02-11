#ifndef GODOT_CPP_REFLECTIONPROBE_HPP
#define GODOT_CPP_REFLECTIONPROBE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <ReflectionProbe.hpp>

#include <VisualInstance.hpp>
namespace godot {


class ReflectionProbe : public VisualInstance {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ReflectionProbe"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum UpdateMode {
		UPDATE_ALWAYS = 1,
		UPDATE_ONCE = 0,
	};

	// constants


	static ReflectionProbe *_new();

	// methods
	void set_intensity(const double intensity);
	double get_intensity() const;
	void set_interior_ambient(const Color ambient);
	Color get_interior_ambient() const;
	void set_interior_ambient_energy(const double ambient_energy);
	double get_interior_ambient_energy() const;
	void set_interior_ambient_probe_contribution(const double ambient_probe_contribution);
	double get_interior_ambient_probe_contribution() const;
	void set_max_distance(const double max_distance);
	double get_max_distance() const;
	void set_extents(const Vector3 extents);
	Vector3 get_extents() const;
	void set_origin_offset(const Vector3 origin_offset);
	Vector3 get_origin_offset() const;
	void set_as_interior(const bool enable);
	bool is_set_as_interior() const;
	void set_enable_box_projection(const bool enable);
	bool is_box_projection_enabled() const;
	void set_enable_shadows(const bool enable);
	bool are_shadows_enabled() const;
	void set_cull_mask(const int64_t layers);
	int64_t get_cull_mask() const;
	void set_update_mode(const int64_t mode);
	ReflectionProbe::UpdateMode get_update_mode() const;

};

}

#endif