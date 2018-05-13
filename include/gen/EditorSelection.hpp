#ifndef GODOT_CPP_EDITORSELECTION_HPP
#define GODOT_CPP_EDITORSELECTION_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Object.hpp"
namespace godot {

class Object;

class EditorSelection : public Object {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorSelection"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static EditorSelection *_new();

	// methods
	void _node_removed(const Object *arg0);
	void clear();
	void add_node(const Object *node);
	void remove_node(const Object *node);
	Array get_selected_nodes();
	Array get_transformable_selected_nodes();
	void _emit_change();

};

}

#endif