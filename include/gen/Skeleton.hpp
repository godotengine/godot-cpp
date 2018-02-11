#ifndef GODOT_CPP_SKELETON_HPP
#define GODOT_CPP_SKELETON_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Spatial.hpp>
namespace godot {

class Object;

class Skeleton : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Skeleton"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants
	const static int NOTIFICATION_UPDATE_SKELETON = 50;


	static Skeleton *_new();

	// methods
	void add_bone(const String name);
	int64_t find_bone(const String name) const;
	String get_bone_name(const int64_t bone_idx) const;
	int64_t get_bone_parent(const int64_t bone_idx) const;
	void set_bone_parent(const int64_t bone_idx, const int64_t parent_idx);
	int64_t get_bone_count() const;
	void unparent_bone_and_rest(const int64_t bone_idx);
	Transform get_bone_rest(const int64_t bone_idx) const;
	void set_bone_rest(const int64_t bone_idx, const Transform rest);
	void set_bone_disable_rest(const int64_t bone_idx, const bool disable);
	bool is_bone_rest_disabled(const int64_t bone_idx) const;
	void bind_child_node_to_bone(const int64_t bone_idx, const Object *node);
	void unbind_child_node_from_bone(const int64_t bone_idx, const Object *node);
	Array get_bound_child_nodes_to_bone(const int64_t bone_idx) const;
	void clear_bones();
	Transform get_bone_pose(const int64_t bone_idx) const;
	void set_bone_pose(const int64_t bone_idx, const Transform pose);
	void set_bone_global_pose(const int64_t bone_idx, const Transform pose);
	Transform get_bone_global_pose(const int64_t bone_idx) const;
	Transform get_bone_custom_pose(const int64_t bone_idx) const;
	void set_bone_custom_pose(const int64_t bone_idx, const Transform custom_pose);
	Transform get_bone_transform(const int64_t bone_idx) const;

};

}

#endif