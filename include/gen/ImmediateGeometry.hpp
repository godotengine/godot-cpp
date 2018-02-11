#ifndef GODOT_CPP_IMMEDIATEGEOMETRY_HPP
#define GODOT_CPP_IMMEDIATEGEOMETRY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <GeometryInstance.hpp>
namespace godot {

class Texture;

class ImmediateGeometry : public GeometryInstance {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ImmediateGeometry"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ImmediateGeometry *_new();

	// methods
	void begin(const int64_t primitive, const Ref<Texture> texture = nullptr);
	void set_normal(const Vector3 normal);
	void set_tangent(const Plane tangent);
	void set_color(const Color color);
	void set_uv(const Vector2 uv);
	void set_uv2(const Vector2 uv);
	void add_vertex(const Vector3 position);
	void add_sphere(const int64_t lats, const int64_t lons, const double radius, const bool add_uv = true);
	void end();
	void clear();

};

}

#endif