#ifndef GODOT_CPP_ARRAYMESH_HPP
#define GODOT_CPP_ARRAYMESH_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Mesh.hpp>

#include <Mesh.hpp>
namespace godot {

class Material;

class ArrayMesh : public Mesh {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ArrayMesh"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum ArrayFormat {
		ARRAY_FORMAT_WEIGHTS = 128,
		ARRAY_FORMAT_COLOR = 8,
		ARRAY_FORMAT_TEX_UV = 16,
		ARRAY_FORMAT_TEX_UV2 = 32,
		ARRAY_FORMAT_INDEX = 256,
		ARRAY_FORMAT_BONES = 64,
		ARRAY_FORMAT_VERTEX = 1,
		ARRAY_FORMAT_TANGENT = 4,
		ARRAY_FORMAT_NORMAL = 2,
	};
	enum ArrayType {
		ARRAY_VERTEX = 0,
		ARRAY_TEX_UV2 = 5,
		ARRAY_MAX = 9,
		ARRAY_BONES = 6,
		ARRAY_NORMAL = 1,
		ARRAY_WEIGHTS = 7,
		ARRAY_COLOR = 3,
		ARRAY_INDEX = 8,
		ARRAY_TANGENT = 2,
		ARRAY_TEX_UV = 4,
	};

	// constants
	const static int ARRAY_WEIGHTS_SIZE = 4;
	const static int NO_INDEX_ARRAY = -1;


	static ArrayMesh *_new();

	// methods
	void add_blend_shape(const String name);
	int64_t get_blend_shape_count() const;
	String get_blend_shape_name(const int64_t index) const;
	void clear_blend_shapes();
	void set_blend_shape_mode(const int64_t mode);
	Mesh::BlendShapeMode get_blend_shape_mode() const;
	void add_surface_from_arrays(const int64_t primitive, const Array arrays, const Array blend_shapes = Array(), const int64_t compress_flags = 97792);
	int64_t get_surface_count() const;
	void surface_remove(const int64_t surf_idx);
	void surface_update_region(const int64_t surf_idx, const int64_t offset, const PoolByteArray data);
	int64_t surface_get_array_len(const int64_t surf_idx) const;
	int64_t surface_get_array_index_len(const int64_t surf_idx) const;
	int64_t surface_get_format(const int64_t surf_idx) const;
	Mesh::PrimitiveType surface_get_primitive_type(const int64_t surf_idx) const;
	void surface_set_material(const int64_t surf_idx, const Ref<Material> material);
	Ref<Material> surface_get_material(const int64_t surf_idx) const;
	void surface_set_name(const int64_t surf_idx, const String name);
	String surface_get_name(const int64_t surf_idx) const;
	Array surface_get_arrays(const int64_t surf_idx) const;
	Array surface_get_blend_shape_arrays(const int64_t surf_idx) const;
	void center_geometry();
	void regen_normalmaps();
	Error lightmap_unwrap(const Transform arg0, const double arg1);
	void set_custom_aabb(const AABB aabb);
	AABB get_custom_aabb() const;

};

}

#endif