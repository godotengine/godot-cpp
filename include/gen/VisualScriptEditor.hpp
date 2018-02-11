#ifndef GODOT_CPP_VISUALSCRIPTEDITOR_HPP
#define GODOT_CPP_VISUALSCRIPTEDITOR_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {

class Script;

class VisualScriptEditor : public Object {
	static VisualScriptEditor *_singleton;

	VisualScriptEditor();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline VisualScriptEditor *get_singleton()
	{
		if (!VisualScriptEditor::_singleton) {
			VisualScriptEditor::_singleton = new VisualScriptEditor;
		}
		return VisualScriptEditor::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "VisualScriptEditor"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void add_custom_node(const String name, const String category, const Ref<Script> script);
	void remove_custom_node(const String name, const String category);

};

}

#endif