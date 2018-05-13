#ifndef GODOT_CPP_CYLINDERMESH_HPP
#define GODOT_CPP_CYLINDERMESH_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "PrimitiveMesh.hpp"
namespace godot {


class CylinderMesh : public PrimitiveMesh {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "CylinderMesh"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static CylinderMesh *_new();

	// methods
	void set_top_radius(const double radius);
	double get_top_radius() const;
	void set_bottom_radius(const double radius);
	double get_bottom_radius() const;
	void set_height(const double height);
	double get_height() const;
	void set_radial_segments(const int64_t segments);
	int64_t get_radial_segments() const;
	void set_rings(const int64_t rings);
	int64_t get_rings() const;

};

}

#endif