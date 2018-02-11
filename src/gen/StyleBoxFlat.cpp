#include <StyleBoxFlat.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *StyleBoxFlat::___get_type_tag()
{
	return (void *) &StyleBoxFlat::___get_type_tag;
}

void *StyleBoxFlat::___get_base_type_tag()
{
	return (void *) &StyleBox::___get_type_tag;
}

StyleBoxFlat *StyleBoxFlat::_new()
{
	return (StyleBoxFlat *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"StyleBoxFlat")());
}
void StyleBoxFlat::set_bg_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_bg_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color StyleBoxFlat::get_bg_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_bg_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void StyleBoxFlat::set_border_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_border_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color StyleBoxFlat::get_border_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_border_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void StyleBoxFlat::set_border_width_all(const int64_t width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_border_width_all");
	}
	___godot_icall_void_int(mb, (const Object *) this, width);
}

int64_t StyleBoxFlat::get_border_width_min() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_border_width_min");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void StyleBoxFlat::set_border_width(const int64_t margin, const int64_t width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_border_width");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, margin, width);
}

int64_t StyleBoxFlat::get_border_width(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_border_width");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, margin);
}

void StyleBoxFlat::set_border_blend(const bool blend) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_border_blend");
	}
	___godot_icall_void_bool(mb, (const Object *) this, blend);
}

bool StyleBoxFlat::get_border_blend() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_border_blend");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void StyleBoxFlat::set_corner_radius_individual(const int64_t radius_top_left, const int64_t radius_top_right, const int64_t radius_bottom_right, const int64_t radius_bottom_left) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_corner_radius_individual");
	}
	___godot_icall_void_int_int_int_int(mb, (const Object *) this, radius_top_left, radius_top_right, radius_bottom_right, radius_bottom_left);
}

void StyleBoxFlat::set_corner_radius_all(const int64_t radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_corner_radius_all");
	}
	___godot_icall_void_int(mb, (const Object *) this, radius);
}

void StyleBoxFlat::set_corner_radius(const int64_t corner, const int64_t radius) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_corner_radius");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, corner, radius);
}

int64_t StyleBoxFlat::get_corner_radius(const int64_t corner) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_corner_radius");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, corner);
}

void StyleBoxFlat::set_expand_margin(const int64_t margin, const double size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_expand_margin");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, margin, size);
}

void StyleBoxFlat::set_expand_margin_all(const double size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_expand_margin_all");
	}
	___godot_icall_void_float(mb, (const Object *) this, size);
}

void StyleBoxFlat::set_expand_margin_individual(const double size_left, const double size_top, const double size_right, const double size_bottom) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_expand_margin_individual");
	}
	___godot_icall_void_float_float_float_float(mb, (const Object *) this, size_left, size_top, size_right, size_bottom);
}

double StyleBoxFlat::get_expand_margin(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_expand_margin");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, margin);
}

void StyleBoxFlat::set_draw_center(const bool draw_center) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_draw_center");
	}
	___godot_icall_void_bool(mb, (const Object *) this, draw_center);
}

bool StyleBoxFlat::is_draw_center_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "is_draw_center_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void StyleBoxFlat::set_shadow_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_shadow_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color StyleBoxFlat::get_shadow_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_shadow_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void StyleBoxFlat::set_shadow_size(const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_shadow_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, size);
}

int64_t StyleBoxFlat::get_shadow_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_shadow_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void StyleBoxFlat::set_anti_aliased(const bool anti_aliased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_anti_aliased");
	}
	___godot_icall_void_bool(mb, (const Object *) this, anti_aliased);
}

bool StyleBoxFlat::is_anti_aliased() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "is_anti_aliased");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void StyleBoxFlat::set_aa_size(const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_aa_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, size);
}

int64_t StyleBoxFlat::get_aa_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_aa_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void StyleBoxFlat::set_corner_detail(const int64_t detail) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "set_corner_detail");
	}
	___godot_icall_void_int(mb, (const Object *) this, detail);
}

int64_t StyleBoxFlat::get_corner_detail() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxFlat", "get_corner_detail");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}