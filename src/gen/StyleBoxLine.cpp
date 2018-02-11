#include <StyleBoxLine.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *StyleBoxLine::___get_type_tag()
{
	return (void *) &StyleBoxLine::___get_type_tag;
}

void *StyleBoxLine::___get_base_type_tag()
{
	return (void *) &StyleBox::___get_type_tag;
}

StyleBoxLine *StyleBoxLine::_new()
{
	return (StyleBoxLine *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"StyleBoxLine")());
}
void StyleBoxLine::set_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxLine", "set_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color StyleBoxLine::get_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxLine", "get_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void StyleBoxLine::set_thickness(const int64_t thickness) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxLine", "set_thickness");
	}
	___godot_icall_void_int(mb, (const Object *) this, thickness);
}

int64_t StyleBoxLine::get_thickness() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxLine", "get_thickness");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void StyleBoxLine::set_grow(const double grow) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxLine", "set_grow");
	}
	___godot_icall_void_float(mb, (const Object *) this, grow);
}

double StyleBoxLine::get_grow() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxLine", "get_grow");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void StyleBoxLine::set_vertical(const bool vertical) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxLine", "set_vertical");
	}
	___godot_icall_void_bool(mb, (const Object *) this, vertical);
}

bool StyleBoxLine::is_vertical() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxLine", "is_vertical");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}