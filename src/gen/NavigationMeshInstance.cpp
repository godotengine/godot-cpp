#include <NavigationMeshInstance.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <NavigationMesh.hpp>


namespace godot {


void *NavigationMeshInstance::___get_type_tag()
{
	return (void *) &NavigationMeshInstance::___get_type_tag;
}

void *NavigationMeshInstance::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

NavigationMeshInstance *NavigationMeshInstance::_new()
{
	return (NavigationMeshInstance *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"NavigationMeshInstance")());
}
void NavigationMeshInstance::set_navigation_mesh(const Ref<NavigationMesh> navmesh) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMeshInstance", "set_navigation_mesh");
	}
	___godot_icall_void_Object(mb, (const Object *) this, navmesh.ptr());
}

Ref<NavigationMesh> NavigationMeshInstance::get_navigation_mesh() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMeshInstance", "get_navigation_mesh");
	}
	return Ref<NavigationMesh>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void NavigationMeshInstance::set_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMeshInstance", "set_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool NavigationMeshInstance::is_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationMeshInstance", "is_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}