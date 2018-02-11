#ifndef GODOT_CPP_MESHLIBRARY_HPP
#define GODOT_CPP_MESHLIBRARY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {

class Mesh;
class NavigationMesh;
class Texture;

class MeshLibrary : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "MeshLibrary"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static MeshLibrary *_new();

	// methods
	void create_item(const int64_t id);
	void set_item_name(const int64_t id, const String name);
	void set_item_mesh(const int64_t id, const Ref<Mesh> mesh);
	void set_item_navmesh(const int64_t id, const Ref<NavigationMesh> navmesh);
	void set_item_shapes(const int64_t id, const Array shapes);
	void set_item_preview(const int64_t id, const Ref<Texture> texture);
	String get_item_name(const int64_t id) const;
	Ref<Mesh> get_item_mesh(const int64_t id) const;
	Ref<NavigationMesh> get_item_navmesh(const int64_t id) const;
	Array get_item_shapes(const int64_t id) const;
	Ref<Texture> get_item_preview(const int64_t id) const;
	void remove_item(const int64_t id);
	int64_t find_item_by_name(const String name) const;
	void clear();
	PoolIntArray get_item_list() const;
	int64_t get_last_unused_item_id() const;

};

}

#endif