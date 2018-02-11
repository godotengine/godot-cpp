#include <ProximityGroup.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ProximityGroup::___get_type_tag()
{
	return (void *) &ProximityGroup::___get_type_tag;
}

void *ProximityGroup::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

ProximityGroup *ProximityGroup::_new()
{
	return (ProximityGroup *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ProximityGroup")());
}
void ProximityGroup::set_group_name(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProximityGroup", "set_group_name");
	}
	___godot_icall_void_String(mb, (const Object *) this, name);
}

String ProximityGroup::get_group_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProximityGroup", "get_group_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void ProximityGroup::set_dispatch_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProximityGroup", "set_dispatch_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

ProximityGroup::DispatchMode ProximityGroup::get_dispatch_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProximityGroup", "get_dispatch_mode");
	}
	return (ProximityGroup::DispatchMode) ___godot_icall_int(mb, (const Object *) this);
}

void ProximityGroup::set_grid_radius(const Vector3 radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProximityGroup", "set_grid_radius");
	}
	___godot_icall_void_Vector3(mb, (const Object *) this, radius);
}

Vector3 ProximityGroup::get_grid_radius() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProximityGroup", "get_grid_radius");
	}
	return ___godot_icall_Vector3(mb, (const Object *) this);
}

void ProximityGroup::broadcast(const String name, const Variant parameters) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProximityGroup", "broadcast");
	}
	___godot_icall_void_String_Variant(mb, (const Object *) this, name, parameters);
}

void ProximityGroup::_proximity_group_broadcast(const String name, const Variant params) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProximityGroup", "_proximity_group_broadcast");
	}
	___godot_icall_void_String_Variant(mb, (const Object *) this, name, params);
}

}