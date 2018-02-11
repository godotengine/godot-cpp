#ifndef GODOT_CPP_EDITORSCRIPT_HPP
#define GODOT_CPP_EDITORSCRIPT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class Object;
class Node;
class EditorInterface;

class EditorScript : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorScript"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static EditorScript *_new();

	// methods
	void _run();
	void add_root_node(const Object *node);
	Node *get_scene();
	EditorInterface *get_editor_interface();

};

}

#endif