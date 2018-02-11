#include <EncodedObjectAsID.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *EncodedObjectAsID::___get_type_tag()
{
	return (void *) &EncodedObjectAsID::___get_type_tag;
}

void *EncodedObjectAsID::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

EncodedObjectAsID *EncodedObjectAsID::_new()
{
	return (EncodedObjectAsID *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"EncodedObjectAsID")());
}
void EncodedObjectAsID::set_object_id(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EncodedObjectAsID", "set_object_id");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

int64_t EncodedObjectAsID::get_object_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("EncodedObjectAsID", "get_object_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}