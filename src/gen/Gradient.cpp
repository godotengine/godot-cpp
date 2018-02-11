#include <Gradient.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Gradient::___get_type_tag()
{
	return (void *) &Gradient::___get_type_tag;
}

void *Gradient::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Gradient *Gradient::_new()
{
	return (Gradient *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Gradient")());
}
void Gradient::add_point(const double offset, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "add_point");
	}
	___godot_icall_void_float_Color(mb, (const Object *) this, offset, color);
}

void Gradient::remove_point(const int64_t offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "remove_point");
	}
	___godot_icall_void_int(mb, (const Object *) this, offset);
}

void Gradient::set_offset(const int64_t point, const double offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "set_offset");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, point, offset);
}

double Gradient::get_offset(const int64_t point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "get_offset");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, point);
}

void Gradient::set_color(const int64_t point, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "set_color");
	}
	___godot_icall_void_int_Color(mb, (const Object *) this, point, color);
}

Color Gradient::get_color(const int64_t point) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "get_color");
	}
	return ___godot_icall_Color_int(mb, (const Object *) this, point);
}

Color Gradient::interpolate(const double offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "interpolate");
	}
	return ___godot_icall_Color_float(mb, (const Object *) this, offset);
}

int64_t Gradient::get_point_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "get_point_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Gradient::set_offsets(const PoolRealArray offsets) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "set_offsets");
	}
	___godot_icall_void_PoolRealArray(mb, (const Object *) this, offsets);
}

PoolRealArray Gradient::get_offsets() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "get_offsets");
	}
	return ___godot_icall_PoolRealArray(mb, (const Object *) this);
}

void Gradient::set_colors(const PoolColorArray colors) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "set_colors");
	}
	___godot_icall_void_PoolColorArray(mb, (const Object *) this, colors);
}

PoolColorArray Gradient::get_colors() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Gradient", "get_colors");
	}
	return ___godot_icall_PoolColorArray(mb, (const Object *) this);
}

}