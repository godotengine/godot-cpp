#ifndef GODOT_CPP_MULTIMESH_HPP
#define GODOT_CPP_MULTIMESH_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "MultiMesh.hpp"

#include "Resource.hpp"
namespace godot {

class Mesh;

class MultiMesh : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "MultiMesh"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum TransformFormat {
		TRANSFORM_2D = 0,
		TRANSFORM_3D = 1,
	};
	enum ColorFormat {
		COLOR_8BIT = 1,
		COLOR_NONE = 0,
		COLOR_FLOAT = 2,
	};

	// constants


	static MultiMesh *_new();

	// methods
	void set_mesh(const Ref<Mesh> mesh);
	Ref<Mesh> get_mesh() const;
	void set_color_format(const int64_t format);
	MultiMesh::ColorFormat get_color_format() const;
	void set_transform_format(const int64_t format);
	MultiMesh::TransformFormat get_transform_format() const;
	void set_instance_count(const int64_t count);
	int64_t get_instance_count() const;
	void set_instance_transform(const int64_t instance, const Transform transform);
	Transform get_instance_transform(const int64_t instance) const;
	void set_instance_color(const int64_t instance, const Color color);
	Color get_instance_color(const int64_t instance) const;
	AABB get_aabb() const;
	void _set_transform_array(const PoolVector3Array arg0);
	PoolVector3Array _get_transform_array() const;
	void _set_color_array(const PoolColorArray arg0);
	PoolColorArray _get_color_array() const;

};

}

#endif