#ifndef GODOT_CPP_COLLISIONPOLYGON_HPP
#define GODOT_CPP_COLLISIONPOLYGON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Spatial.hpp"
namespace godot {


class CollisionPolygon : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "CollisionPolygon"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static CollisionPolygon *_new();

	// methods
	void set_depth(const double depth);
	double get_depth() const;
	void set_polygon(const PoolVector2Array polygon);
	PoolVector2Array get_polygon() const;
	void set_disabled(const bool disabled);
	bool is_disabled() const;
	bool _is_editable_3d_polygon() const;

};

}

#endif