#include <SceneState.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <PackedScene.hpp>


namespace godot {


void *SceneState::___get_type_tag()
{
	return (void *) &SceneState::___get_type_tag;
}

void *SceneState::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

int64_t SceneState::get_node_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String SceneState::get_node_type(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_type");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

String SceneState::get_node_name(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

NodePath SceneState::get_node_path(const int64_t idx, const bool for_parent) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_path");
	}
	return ___godot_icall_NodePath_int_bool(mb, (const Object *) this, idx, for_parent);
}

NodePath SceneState::get_node_owner_path(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_owner_path");
	}
	return ___godot_icall_NodePath_int(mb, (const Object *) this, idx);
}

bool SceneState::is_node_instance_placeholder(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "is_node_instance_placeholder");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, idx);
}

String SceneState::get_node_instance_placeholder(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_instance_placeholder");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

Ref<PackedScene> SceneState::get_node_instance(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_instance");
	}
	return Ref<PackedScene>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, idx));
}

PoolStringArray SceneState::get_node_groups(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_groups");
	}
	return ___godot_icall_PoolStringArray_int(mb, (const Object *) this, idx);
}

int64_t SceneState::get_node_index(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_index");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

int64_t SceneState::get_node_property_count(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_property_count");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

String SceneState::get_node_property_name(const int64_t idx, const int64_t prop_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_property_name");
	}
	return ___godot_icall_String_int_int(mb, (const Object *) this, idx, prop_idx);
}

Variant SceneState::get_node_property_value(const int64_t idx, const int64_t prop_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_node_property_value");
	}
	return ___godot_icall_Variant_int_int(mb, (const Object *) this, idx, prop_idx);
}

int64_t SceneState::get_connection_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_connection_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

NodePath SceneState::get_connection_source(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_connection_source");
	}
	return ___godot_icall_NodePath_int(mb, (const Object *) this, idx);
}

String SceneState::get_connection_signal(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_connection_signal");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

NodePath SceneState::get_connection_target(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_connection_target");
	}
	return ___godot_icall_NodePath_int(mb, (const Object *) this, idx);
}

String SceneState::get_connection_method(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_connection_method");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, idx);
}

int64_t SceneState::get_connection_flags(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_connection_flags");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, idx);
}

Array SceneState::get_connection_binds(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SceneState", "get_connection_binds");
	}
	return ___godot_icall_Array_int(mb, (const Object *) this, idx);
}

}