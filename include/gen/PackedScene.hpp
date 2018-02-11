#ifndef GODOT_CPP_PACKEDSCENE_HPP
#define GODOT_CPP_PACKEDSCENE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {

class Object;
class Node;
class SceneState;

class PackedScene : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PackedScene"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum GenEditState {
		GEN_EDIT_STATE_INSTANCE = 1,
		GEN_EDIT_STATE_DISABLED = 0,
		GEN_EDIT_STATE_MAIN = 2,
	};

	// constants


	static PackedScene *_new();

	// methods
	Error pack(const Object *path);
	Node *instance(const int64_t edit_state = 0) const;
	bool can_instance() const;
	void _set_bundled_scene(const Dictionary arg0);
	Dictionary _get_bundled_scene() const;
	Ref<SceneState> get_state();

};

}

#endif