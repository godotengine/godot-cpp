#ifndef GODOT_CPP_LIGHTOCCLUDER2D_HPP
#define GODOT_CPP_LIGHTOCCLUDER2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node2D.hpp"
namespace godot {

class OccluderPolygon2D;

class LightOccluder2D : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "LightOccluder2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static LightOccluder2D *_new();

	// methods
	void set_occluder_polygon(const Ref<OccluderPolygon2D> polygon);
	Ref<OccluderPolygon2D> get_occluder_polygon() const;
	void set_occluder_light_mask(const int64_t mask);
	int64_t get_occluder_light_mask() const;
	void _poly_changed();

};

}

#endif