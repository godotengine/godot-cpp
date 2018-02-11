#include <VisualScriptResourcePath.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptResourcePath::___get_type_tag()
{
	return (void *) &VisualScriptResourcePath::___get_type_tag;
}

void *VisualScriptResourcePath::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptResourcePath *VisualScriptResourcePath::_new()
{
	return (VisualScriptResourcePath *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptResourcePath")());
}
void VisualScriptResourcePath::set_resource_path(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptResourcePath", "set_resource_path");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

String VisualScriptResourcePath::get_resource_path() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptResourcePath", "get_resource_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}