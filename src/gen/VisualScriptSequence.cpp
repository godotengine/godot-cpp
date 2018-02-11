#include <VisualScriptSequence.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptSequence::___get_type_tag()
{
	return (void *) &VisualScriptSequence::___get_type_tag;
}

void *VisualScriptSequence::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptSequence *VisualScriptSequence::_new()
{
	return (VisualScriptSequence *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptSequence")());
}
void VisualScriptSequence::set_steps(const int64_t steps) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptSequence", "set_steps");
	}
	___godot_icall_void_int(mb, (const Object *) this, steps);
}

int64_t VisualScriptSequence::get_steps() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptSequence", "get_steps");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}