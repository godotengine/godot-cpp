#include <Skeleton.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *Skeleton::___get_type_tag()
{
	return (void *) &Skeleton::___get_type_tag;
}

void *Skeleton::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

Skeleton *Skeleton::_new()
{
	return (Skeleton *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Skeleton")());
}
void Skeleton::add_bone(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "add_bone");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

int64_t Skeleton::find_bone(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "find_bone");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, name);
}

String Skeleton::get_bone_name(const int64_t bone_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "get_bone_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, bone_idx);
}

int64_t Skeleton::get_bone_parent(const int64_t bone_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "get_bone_parent");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, bone_idx);
}

void Skeleton::set_bone_parent(const int64_t bone_idx, const int64_t parent_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "set_bone_parent");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, bone_idx, parent_idx);
}

int64_t Skeleton::get_bone_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "get_bone_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Skeleton::unparent_bone_and_rest(const int64_t bone_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "unparent_bone_and_rest");
	}
	___godot_icall_void_int(mb, (const Object *) this, bone_idx);
}

Transform Skeleton::get_bone_rest(const int64_t bone_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "get_bone_rest");
	}
	return ___godot_icall_Transform_int(mb, (const Object *) this, bone_idx);
}

void Skeleton::set_bone_rest(const int64_t bone_idx, const Transform rest) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "set_bone_rest");
	}
	___godot_icall_void_int_Transform(mb, (const Object *) this, bone_idx, rest);
}

void Skeleton::set_bone_disable_rest(const int64_t bone_idx, const bool disable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "set_bone_disable_rest");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bone_idx, disable);
}

bool Skeleton::is_bone_rest_disabled(const int64_t bone_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "is_bone_rest_disabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bone_idx);
}

void Skeleton::bind_child_node_to_bone(const int64_t bone_idx, const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "bind_child_node_to_bone");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, bone_idx, node);
}

void Skeleton::unbind_child_node_from_bone(const int64_t bone_idx, const Object *node) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "unbind_child_node_from_bone");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, bone_idx, node);
}

Array Skeleton::get_bound_child_nodes_to_bone(const int64_t bone_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "get_bound_child_nodes_to_bone");
	}
	return ___godot_icall_Array_int(mb, (const Object *) this, bone_idx);
}

void Skeleton::clear_bones() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "clear_bones");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Transform Skeleton::get_bone_pose(const int64_t bone_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "get_bone_pose");
	}
	return ___godot_icall_Transform_int(mb, (const Object *) this, bone_idx);
}

void Skeleton::set_bone_pose(const int64_t bone_idx, const Transform pose) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "set_bone_pose");
	}
	___godot_icall_void_int_Transform(mb, (const Object *) this, bone_idx, pose);
}

void Skeleton::set_bone_global_pose(const int64_t bone_idx, const Transform pose) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "set_bone_global_pose");
	}
	___godot_icall_void_int_Transform(mb, (const Object *) this, bone_idx, pose);
}

Transform Skeleton::get_bone_global_pose(const int64_t bone_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "get_bone_global_pose");
	}
	return ___godot_icall_Transform_int(mb, (const Object *) this, bone_idx);
}

Transform Skeleton::get_bone_custom_pose(const int64_t bone_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "get_bone_custom_pose");
	}
	return ___godot_icall_Transform_int(mb, (const Object *) this, bone_idx);
}

void Skeleton::set_bone_custom_pose(const int64_t bone_idx, const Transform custom_pose) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "set_bone_custom_pose");
	}
	___godot_icall_void_int_Transform(mb, (const Object *) this, bone_idx, custom_pose);
}

Transform Skeleton::get_bone_transform(const int64_t bone_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Skeleton", "get_bone_transform");
	}
	return ___godot_icall_Transform_int(mb, (const Object *) this, bone_idx);
}

}