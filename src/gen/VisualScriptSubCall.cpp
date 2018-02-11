#include <VisualScriptSubCall.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptSubCall::___get_type_tag()
{
	return (void *) &VisualScriptSubCall::___get_type_tag;
}

void *VisualScriptSubCall::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptSubCall *VisualScriptSubCall::_new()
{
	return (VisualScriptSubCall *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptSubCall")());
}
Variant VisualScriptSubCall::_subcall(const Variant arguments) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptSubCall", "_subcall");
	}
	return ___godot_icall_Variant_Variant(mb, (const Object *) this, arguments);
}

}