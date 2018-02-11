#include <VisualScriptEditor.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Script.hpp>


namespace godot {


void *VisualScriptEditor::___get_type_tag()
{
	return (void *) &VisualScriptEditor::___get_type_tag;
}

void *VisualScriptEditor::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

VisualScriptEditor *VisualScriptEditor::_singleton = NULL;


VisualScriptEditor::VisualScriptEditor() {
	_owner = godot::api->godot_global_get_singleton((char *) "VisualScriptEditor");
}


void VisualScriptEditor::add_custom_node(const String name, const String category, const Ref<Script> script) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_VisualScriptEditor", "add_custom_node");
	}
	___godot_icall_void_String_String_Object(mb, (const Object *) this, name, category, script.ptr());
}

void VisualScriptEditor::remove_custom_node(const String name, const String category) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_VisualScriptEditor", "remove_custom_node");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, category);
}

}