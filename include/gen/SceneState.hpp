#ifndef GODOT_CPP_SCENESTATE_HPP
#define GODOT_CPP_SCENESTATE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class PackedScene;

class SceneState : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "SceneState"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum GenEditState {
		GEN_EDIT_STATE_INSTANCE = 1,
		GEN_EDIT_STATE_DISABLED = 0,
		GEN_EDIT_STATE_MAIN = 2,
	};

	// constants

	// methods
	int64_t get_node_count() const;
	String get_node_type(const int64_t idx) const;
	String get_node_name(const int64_t idx) const;
	NodePath get_node_path(const int64_t idx, const bool for_parent = false) const;
	NodePath get_node_owner_path(const int64_t idx) const;
	bool is_node_instance_placeholder(const int64_t idx) const;
	String get_node_instance_placeholder(const int64_t idx) const;
	Ref<PackedScene> get_node_instance(const int64_t idx) const;
	PoolStringArray get_node_groups(const int64_t idx) const;
	int64_t get_node_index(const int64_t idx) const;
	int64_t get_node_property_count(const int64_t idx) const;
	String get_node_property_name(const int64_t idx, const int64_t prop_idx) const;
	Variant get_node_property_value(const int64_t idx, const int64_t prop_idx) const;
	int64_t get_connection_count() const;
	NodePath get_connection_source(const int64_t idx) const;
	String get_connection_signal(const int64_t idx) const;
	NodePath get_connection_target(const int64_t idx) const;
	String get_connection_method(const int64_t idx) const;
	int64_t get_connection_flags(const int64_t idx) const;
	Array get_connection_binds(const int64_t idx) const;

};

}

#endif