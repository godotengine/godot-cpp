#include <Listener.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Listener::___get_type_tag()
{
	return (void *) &Listener::___get_type_tag;
}

void *Listener::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

Listener *Listener::_new()
{
	return (Listener *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Listener")());
}
void Listener::make_current() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Listener", "make_current");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Listener::clear_current() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Listener", "clear_current");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool Listener::is_current() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Listener", "is_current");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Transform Listener::get_listener_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Listener", "get_listener_transform");
	}
	return ___godot_icall_Transform(mb, (const Object *) this);
}

}