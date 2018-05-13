#ifndef GODOT_CPP_POLYGONPATHFINDER_HPP
#define GODOT_CPP_POLYGONPATHFINDER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {


class PolygonPathFinder : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PolygonPathFinder"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static PolygonPathFinder *_new();

	// methods
	void setup(const PoolVector2Array points, const PoolIntArray connections);
	PoolVector2Array find_path(const Vector2 from, const Vector2 to);
	PoolVector2Array get_intersections(const Vector2 from, const Vector2 to) const;
	Vector2 get_closest_point(const Vector2 point) const;
	bool is_point_inside(const Vector2 point) const;
	void set_point_penalty(const int64_t idx, const double penalty);
	double get_point_penalty(const int64_t idx) const;
	Rect2 get_bounds() const;
	void _set_data(const Dictionary arg0);
	Dictionary _get_data() const;

};

}

#endif