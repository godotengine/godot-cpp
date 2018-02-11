#include <VisibilityNotifier.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisibilityNotifier::___get_type_tag()
{
	return (void *) &VisibilityNotifier::___get_type_tag;
}

void *VisibilityNotifier::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

VisibilityNotifier *VisibilityNotifier::_new()
{
	return (VisibilityNotifier *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisibilityNotifier")());
}
void VisibilityNotifier::set_aabb(const AABB rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityNotifier", "set_aabb");
	}
	___godot_icall_void_AABB(mb, (const Object *) this, rect);
}

AABB VisibilityNotifier::get_aabb() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityNotifier", "get_aabb");
	}
	return ___godot_icall_AABB(mb, (const Object *) this);
}

bool VisibilityNotifier::is_on_screen() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityNotifier", "is_on_screen");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}