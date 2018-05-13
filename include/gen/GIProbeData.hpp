#ifndef GODOT_CPP_GIPROBEDATA_HPP
#define GODOT_CPP_GIPROBEDATA_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {


class GIProbeData : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GIProbeData"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static GIProbeData *_new();

	// methods
	void set_bounds(const AABB bounds);
	AABB get_bounds() const;
	void set_cell_size(const double cell_size);
	double get_cell_size() const;
	void set_to_cell_xform(const Transform to_cell_xform);
	Transform get_to_cell_xform() const;
	void set_dynamic_data(const PoolIntArray dynamic_data);
	PoolIntArray get_dynamic_data() const;
	void set_dynamic_range(const int64_t dynamic_range);
	int64_t get_dynamic_range() const;
	void set_energy(const double energy);
	double get_energy() const;
	void set_bias(const double bias);
	double get_bias() const;
	void set_normal_bias(const double bias);
	double get_normal_bias() const;
	void set_propagation(const double propagation);
	double get_propagation() const;
	void set_interior(const bool interior);
	bool is_interior() const;
	void set_compress(const bool compress);
	bool is_compressed() const;

};

}

#endif