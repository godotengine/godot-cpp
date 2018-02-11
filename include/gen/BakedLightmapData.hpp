#ifndef GODOT_CPP_BAKEDLIGHTMAPDATA_HPP
#define GODOT_CPP_BAKEDLIGHTMAPDATA_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {

class Texture;

class BakedLightmapData : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "BakedLightmapData"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static BakedLightmapData *_new();

	// methods
	void _set_user_data(const Array data);
	Array _get_user_data() const;
	void set_bounds(const AABB bounds);
	AABB get_bounds() const;
	void set_cell_space_transform(const Transform xform);
	Transform get_cell_space_transform() const;
	void set_cell_subdiv(const int64_t cell_subdiv);
	int64_t get_cell_subdiv() const;
	void set_octree(const PoolByteArray octree);
	PoolByteArray get_octree() const;
	void set_energy(const double energy);
	double get_energy() const;
	void add_user(const NodePath path, const Ref<Texture> lightmap, const int64_t instance);
	int64_t get_user_count() const;
	NodePath get_user_path(const int64_t user_idx) const;
	Ref<Texture> get_user_lightmap(const int64_t user_idx) const;
	void clear_users();

};

}

#endif