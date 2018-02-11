#include <VisualScriptEngineSingleton.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptEngineSingleton::___get_type_tag()
{
	return (void *) &VisualScriptEngineSingleton::___get_type_tag;
}

void *VisualScriptEngineSingleton::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptEngineSingleton *VisualScriptEngineSingleton::_new()
{
	return (VisualScriptEngineSingleton *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptEngineSingleton")());
}
void VisualScriptEngineSingleton::set_singleton(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptEngineSingleton", "set_singleton");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String VisualScriptEngineSingleton::get_singleton() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptEngineSingleton", "get_singleton");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}