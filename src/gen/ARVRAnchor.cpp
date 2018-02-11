#include <ARVRAnchor.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ARVRAnchor::___get_type_tag()
{
	return (void *) &ARVRAnchor::___get_type_tag;
}

void *ARVRAnchor::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

ARVRAnchor *ARVRAnchor::_new()
{
	return (ARVRAnchor *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ARVRAnchor")());
}
void ARVRAnchor::set_anchor_id(const int64_t anchor_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRAnchor", "set_anchor_id");
	}
	___godot_icall_void_int(mb, (const Object *) this, anchor_id);
}

int64_t ARVRAnchor::get_anchor_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRAnchor", "get_anchor_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String ARVRAnchor::get_anchor_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRAnchor", "get_anchor_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool ARVRAnchor::get_is_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRAnchor", "get_is_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

Vector3 ARVRAnchor::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRAnchor", "get_size");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

Plane ARVRAnchor::get_plane() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ARVRAnchor", "get_plane");
	}
	return ___godot_icall_Plane(mb, (const Object *) this);
}

}