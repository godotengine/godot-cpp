#ifndef GODOT_CPP_MESHDATATOOL_HPP
#define GODOT_CPP_MESHDATATOOL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class ArrayMesh;
class Material;

class MeshDataTool : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "MeshDataTool"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static MeshDataTool *_new();

	// methods
	void clear();
	Error create_from_surface(const Ref<ArrayMesh> mesh, const int64_t surface);
	Error commit_to_surface(const Ref<ArrayMesh> mesh);
	int64_t get_format() const;
	int64_t get_vertex_count() const;
	int64_t get_edge_count() const;
	int64_t get_face_count() const;
	void set_vertex(const int64_t idx, const Vector3 vertex);
	Vector3 get_vertex(const int64_t idx) const;
	void set_vertex_normal(const int64_t idx, const Vector3 normal);
	Vector3 get_vertex_normal(const int64_t idx) const;
	void set_vertex_tangent(const int64_t idx, const Plane tangent);
	Plane get_vertex_tangent(const int64_t idx) const;
	void set_vertex_uv(const int64_t idx, const Vector2 uv);
	Vector2 get_vertex_uv(const int64_t idx) const;
	void set_vertex_uv2(const int64_t idx, const Vector2 uv2);
	Vector2 get_vertex_uv2(const int64_t idx) const;
	void set_vertex_color(const int64_t idx, const Color color);
	Color get_vertex_color(const int64_t idx) const;
	void set_vertex_bones(const int64_t idx, const PoolIntArray bones);
	PoolIntArray get_vertex_bones(const int64_t idx) const;
	void set_vertex_weights(const int64_t idx, const PoolRealArray weights);
	PoolRealArray get_vertex_weights(const int64_t idx) const;
	void set_vertex_meta(const int64_t idx, const Variant meta);
	Variant get_vertex_meta(const int64_t idx) const;
	PoolIntArray get_vertex_edges(const int64_t idx) const;
	PoolIntArray get_vertex_faces(const int64_t idx) const;
	int64_t get_edge_vertex(const int64_t idx, const int64_t vertex) const;
	PoolIntArray get_edge_faces(const int64_t idx) const;
	void set_edge_meta(const int64_t idx, const Variant meta);
	Variant get_edge_meta(const int64_t idx) const;
	int64_t get_face_vertex(const int64_t idx, const int64_t vertex) const;
	int64_t get_face_edge(const int64_t idx, const int64_t edge) const;
	void set_face_meta(const int64_t idx, const Variant meta);
	Variant get_face_meta(const int64_t idx) const;
	Vector3 get_face_normal(const int64_t idx) const;
	void set_material(const Ref<Material> material);
	Ref<Material> get_material() const;

};

}

#endif