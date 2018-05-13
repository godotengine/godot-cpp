#ifndef GODOT_CPP_NAVIGATIONPOLYGON_HPP
#define GODOT_CPP_NAVIGATIONPOLYGON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Resource.hpp"
namespace godot {


class NavigationPolygon : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "NavigationPolygon"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static NavigationPolygon *_new();

	// methods
	void set_vertices(const PoolVector2Array vertices);
	PoolVector2Array get_vertices() const;
	void add_polygon(const PoolIntArray polygon);
	int64_t get_polygon_count() const;
	PoolIntArray get_polygon(const int64_t idx);
	void clear_polygons();
	void add_outline(const PoolVector2Array outline);
	void add_outline_at_index(const PoolVector2Array outline, const int64_t index);
	int64_t get_outline_count() const;
	void set_outline(const int64_t idx, const PoolVector2Array outline);
	PoolVector2Array get_outline(const int64_t idx) const;
	void remove_outline(const int64_t idx);
	void clear_outlines();
	void make_polygons_from_outlines();
	void _set_polygons(const Array polygons);
	Array _get_polygons() const;
	void _set_outlines(const Array outlines);
	Array _get_outlines() const;

};

}

#endif