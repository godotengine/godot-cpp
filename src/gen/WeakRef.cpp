#include <WeakRef.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *WeakRef::___get_type_tag()
{
	return (void *) &WeakRef::___get_type_tag;
}

void *WeakRef::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

WeakRef *WeakRef::_new()
{
	return (WeakRef *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"WeakRef")());
}
Variant WeakRef::get_ref() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("WeakRef", "get_ref");
	}
	return ___godot_icall_Variant(mb, (const Object *) this);
}

}