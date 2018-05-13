#ifndef GODOT_CPP_ARVRANCHOR_HPP
#define GODOT_CPP_ARVRANCHOR_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Spatial.hpp"
namespace godot {


class ARVRAnchor : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ARVRAnchor"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ARVRAnchor *_new();

	// methods
	void set_anchor_id(const int64_t anchor_id);
	int64_t get_anchor_id() const;
	String get_anchor_name() const;
	bool get_is_active() const;
	Vector3 get_size() const;
	Plane get_plane() const;

};

}

#endif