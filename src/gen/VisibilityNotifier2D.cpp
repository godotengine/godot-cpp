#include <VisibilityNotifier2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VisibilityNotifier2D::___get_type_tag()
{
	return (void *) &VisibilityNotifier2D::___get_type_tag;
}

void *VisibilityNotifier2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

VisibilityNotifier2D *VisibilityNotifier2D::_new()
{
	return (VisibilityNotifier2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VisibilityNotifier2D")());
}
void VisibilityNotifier2D::set_rect(const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityNotifier2D", "set_rect");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, rect);
}

Rect2 VisibilityNotifier2D::get_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityNotifier2D", "get_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

bool VisibilityNotifier2D::is_on_screen() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VisibilityNotifier2D", "is_on_screen");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}