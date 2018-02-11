#ifndef GODOT_CPP_MESHINSTANCE_HPP
#define GODOT_CPP_MESHINSTANCE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <GeometryInstance.hpp>
namespace godot {

class Mesh;
class Material;

class MeshInstance : public GeometryInstance {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "MeshInstance"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static MeshInstance *_new();

	// methods
	void set_mesh(const Ref<Mesh> mesh);
	Ref<Mesh> get_mesh() const;
	void set_skeleton_path(const NodePath skeleton_path);
	NodePath get_skeleton_path();
	void set_surface_material(const int64_t surface, const Ref<Material> material);
	Ref<Material> get_surface_material(const int64_t surface) const;
	void create_trimesh_collision();
	void create_convex_collision();
	void _mesh_changed();
	void create_debug_tangents();

};

}

#endif