#include <VisualScriptConstructor.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisualScriptConstructor::___get_type_tag()
{
	return (void *) &VisualScriptConstructor::___get_type_tag;
}

void *VisualScriptConstructor::___get_base_type_tag()
{
	return (void *) &VisualScriptNode::___get_type_tag;
}

VisualScriptConstructor *VisualScriptConstructor::_new()
{
	return (VisualScriptConstructor *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisualScriptConstructor")());
}
void VisualScriptConstructor::set_constructor_type(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptConstructor", "set_constructor_type");
	}
	___godot_icall_void_int(mb, (const Object *) this, type);
}

Variant::Type VisualScriptConstructor::get_constructor_type() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptConstructor", "get_constructor_type");
	}
	return (Variant::Type) ___godot_icall_int(mb, (const Object *) this);
}

void VisualScriptConstructor::set_constructor(const Dictionary constructor) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptConstructor", "set_constructor");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, constructor);
}

Dictionary VisualScriptConstructor::get_constructor() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisualScriptConstructor", "get_constructor");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

}