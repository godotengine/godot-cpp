#ifndef GODOT_CPP_NAVIGATIONPOLYGONINSTANCE_HPP
#define GODOT_CPP_NAVIGATIONPOLYGONINSTANCE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node2D.hpp"
namespace godot {

class NavigationPolygon;

class NavigationPolygonInstance : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "NavigationPolygonInstance"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static NavigationPolygonInstance *_new();

	// methods
	void set_navigation_polygon(const Ref<NavigationPolygon> navpoly);
	Ref<NavigationPolygon> get_navigation_polygon() const;
	void set_enabled(const bool enabled);
	bool is_enabled() const;
	void _navpoly_changed();

};

}

#endif