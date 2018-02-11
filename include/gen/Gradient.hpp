#ifndef GODOT_CPP_GRADIENT_HPP
#define GODOT_CPP_GRADIENT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {


class Gradient : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Gradient"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Gradient *_new();

	// methods
	void add_point(const double offset, const Color color);
	void remove_point(const int64_t offset);
	void set_offset(const int64_t point, const double offset);
	double get_offset(const int64_t point) const;
	void set_color(const int64_t point, const Color color);
	Color get_color(const int64_t point) const;
	Color interpolate(const double offset);
	int64_t get_point_count() const;
	void set_offsets(const PoolRealArray offsets);
	PoolRealArray get_offsets() const;
	void set_colors(const PoolColorArray colors);
	PoolColorArray get_colors() const;

};

}

#endif