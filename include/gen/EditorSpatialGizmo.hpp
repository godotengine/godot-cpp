#ifndef GODOT_CPP_EDITORSPATIALGIZMO_HPP
#define GODOT_CPP_EDITORSPATIALGIZMO_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "SpatialGizmo.hpp"
namespace godot {

class Camera;
class Material;
class ArrayMesh;
class TriangleMesh;
class Object;

class EditorSpatialGizmo : public SpatialGizmo {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorSpatialGizmo"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static EditorSpatialGizmo *_new();

	// methods
	void redraw();
	String get_handle_name(const int64_t index);
	Variant get_handle_value(const int64_t index);
	void set_handle(const int64_t index, const Camera *camera, const Vector2 point);
	void commit_handle(const int64_t index, const Variant restore, const bool cancel);
	void add_lines(const PoolVector3Array lines, const Ref<Material> material, const bool billboard = false);
	void add_mesh(const Ref<ArrayMesh> mesh, const bool billboard = false, const RID skeleton = RID());
	void add_collision_segments(const PoolVector3Array segments);
	void add_collision_triangles(const Ref<TriangleMesh> triangles, const AABB bounds);
	void add_unscaled_billboard(const Ref<Material> material, const double default_scale = 1);
	void add_handles(const PoolVector3Array handles, const bool billboard = false, const bool secondary = false);
	void set_spatial_node(const Object *node);
	void clear();

};

}

#endif