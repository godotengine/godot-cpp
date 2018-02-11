#include <NavigationPolygonInstance.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <NavigationPolygon.hpp>


namespace godot {


void *NavigationPolygonInstance::___get_type_tag()
{
	return (void *) &NavigationPolygonInstance::___get_type_tag;
}

void *NavigationPolygonInstance::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

NavigationPolygonInstance *NavigationPolygonInstance::_new()
{
	return (NavigationPolygonInstance *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"NavigationPolygonInstance")());
}
void NavigationPolygonInstance::set_navigation_polygon(const Ref<NavigationPolygon> navpoly) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygonInstance", "set_navigation_polygon");
	}
	___godot_icall_void_Object(mb, (const Object *) this, navpoly.ptr());
}

Ref<NavigationPolygon> NavigationPolygonInstance::get_navigation_polygon() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygonInstance", "get_navigation_polygon");
	}
	return Ref<NavigationPolygon>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void NavigationPolygonInstance::set_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygonInstance", "set_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool NavigationPolygonInstance::is_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygonInstance", "is_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void NavigationPolygonInstance::_navpoly_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygonInstance", "_navpoly_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}