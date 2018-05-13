#ifndef GODOT_CPP_SURFACETOOL_HPP
#define GODOT_CPP_SURFACETOOL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Reference.hpp"
namespace godot {

class Material;
class Mesh;
class ArrayMesh;

class SurfaceTool : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "SurfaceTool"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static SurfaceTool *_new();

	// methods
	void begin(const int64_t primitive);
	void add_vertex(const Vector3 vertex);
	void add_color(const Color color);
	void add_normal(const Vector3 normal);
	void add_tangent(const Plane tangent);
	void add_uv(const Vector2 uv);
	void add_uv2(const Vector2 uv2);
	void add_bones(const PoolIntArray bones);
	void add_weights(const PoolRealArray weights);
	void add_smooth_group(const bool smooth);
	void add_triangle_fan(const PoolVector3Array vertexes, const PoolVector2Array uvs = PoolVector2Array(), const PoolColorArray colors = PoolColorArray(), const PoolVector2Array uv2s = PoolVector2Array(), const PoolVector3Array normals = PoolVector3Array(), const Array tangents = Array());
	void add_index(const int64_t index);
	void index();
	void deindex();
	void generate_normals(const bool flip = false);
	void generate_tangents();
	void add_to_format(const int64_t flags);
	void set_material(const Ref<Material> material);
	void clear();
	void create_from(const Ref<Mesh> existing, const int64_t surface);
	void append_from(const Ref<Mesh> existing, const int64_t surface, const Transform transform);
	Ref<ArrayMesh> commit(const Ref<ArrayMesh> existing = nullptr, const int64_t flags = 97792);

};

}

#endif