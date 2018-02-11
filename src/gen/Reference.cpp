#include <Reference.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Reference::___get_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

void *Reference::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

Reference *Reference::_new()
{
	return (Reference *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Reference")());
}
bool Reference::init_ref() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Reference", "init_ref");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Reference::reference() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Reference", "reference");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Reference::unreference() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Reference", "unreference");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}