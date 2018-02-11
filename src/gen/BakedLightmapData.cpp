#include <BakedLightmapData.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *BakedLightmapData::___get_type_tag()
{
	return (void *) &BakedLightmapData::___get_type_tag;
}

void *BakedLightmapData::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

BakedLightmapData *BakedLightmapData::_new()
{
	return (BakedLightmapData *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"BakedLightmapData")());
}
void BakedLightmapData::_set_user_data(const Array data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "_set_user_data");
	}
	___godot_icall_void_Array(mb, (const Object *) this, data);
}

Array BakedLightmapData::_get_user_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "_get_user_data");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void BakedLightmapData::set_bounds(const AABB bounds) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "set_bounds");
	}
	___godot_icall_void_AABB(mb, (const Object *) this, bounds);
}

AABB BakedLightmapData::get_bounds() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "get_bounds");
	}
	return ___godot_icall_AABB(mb, (const Object *) this);
}

void BakedLightmapData::set_cell_space_transform(const Transform xform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "set_cell_space_transform");
	}
	___godot_icall_void_Transform(mb, (const Object *) this, xform);
}

Transform BakedLightmapData::get_cell_space_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "get_cell_space_transform");
	}
	return ___godot_icall_Transform(mb, (const Object *) this);
}

void BakedLightmapData::set_cell_subdiv(const int64_t cell_subdiv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "set_cell_subdiv");
	}
	___godot_icall_void_int(mb, (const Object *) this, cell_subdiv);
}

int64_t BakedLightmapData::get_cell_subdiv() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "get_cell_subdiv");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void BakedLightmapData::set_octree(const PoolByteArray octree) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "set_octree");
	}
	___godot_icall_void_PoolByteArray(mb, (const Object *) this, octree);
}

PoolByteArray BakedLightmapData::get_octree() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "get_octree");
	}
	return ___godot_icall_PoolByteArray(mb, (const Object *) this);
}

void BakedLightmapData::set_energy(const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "set_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, energy);
}

double BakedLightmapData::get_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "get_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void BakedLightmapData::add_user(const NodePath path, const Ref<Texture> lightmap, const int64_t instance) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "add_user");
	}
	___godot_icall_void_NodePath_Object_int(mb, (const Object *) this, path, lightmap.ptr(), instance);
}

int64_t BakedLightmapData::get_user_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "get_user_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

NodePath BakedLightmapData::get_user_path(const int64_t user_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "get_user_path");
	}
	return ___godot_icall_NodePath_int(mb, (const Object *) this, user_idx);
}

Ref<Texture> BakedLightmapData::get_user_lightmap(const int64_t user_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "get_user_lightmap");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, user_idx));
}

void BakedLightmapData::clear_users() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BakedLightmapData", "clear_users");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}