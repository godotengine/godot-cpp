#include <Popup.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Popup::___get_type_tag()
{
	return (void *) &Popup::___get_type_tag;
}

void *Popup::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

Popup *Popup::_new()
{
	return (Popup *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Popup")());
}
void Popup::popup_centered(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Popup", "popup_centered");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

void Popup::popup_centered_ratio(const double ratio) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Popup", "popup_centered_ratio");
	}
	___godot_icall_void_float(mb, (const Object *) this, ratio);
}

void Popup::popup_centered_minsize(const Vector2 minsize) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Popup", "popup_centered_minsize");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, minsize);
}

void Popup::popup(const Rect2 bounds) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Popup", "popup");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, bounds);
}

void Popup::set_exclusive(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Popup", "set_exclusive");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Popup::is_exclusive() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Popup", "is_exclusive");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}