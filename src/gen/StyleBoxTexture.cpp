#include <StyleBoxTexture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *StyleBoxTexture::___get_type_tag()
{
	return (void *) &StyleBoxTexture::___get_type_tag;
}

void *StyleBoxTexture::___get_base_type_tag()
{
	return (void *) &StyleBox::___get_type_tag;
}

StyleBoxTexture *StyleBoxTexture::_new()
{
	return (StyleBoxTexture *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"StyleBoxTexture")());
}
void StyleBoxTexture::set_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> StyleBoxTexture::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void StyleBoxTexture::set_normal_map(const Ref<Texture> normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_normal_map");
	}
	___godot_icall_void_Object(mb, (const Object *) this, normal_map.ptr());
}

Ref<Texture> StyleBoxTexture::get_normal_map() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "get_normal_map");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void StyleBoxTexture::set_margin_size(const int64_t margin, const double size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_margin_size");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, margin, size);
}

double StyleBoxTexture::get_margin_size(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "get_margin_size");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, margin);
}

void StyleBoxTexture::set_expand_margin_size(const int64_t margin, const double size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_expand_margin_size");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, margin, size);
}

void StyleBoxTexture::set_expand_margin_all(const double size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_expand_margin_all");
	}
	___godot_icall_void_float(mb, (const Object *) this, size);
}

void StyleBoxTexture::set_expand_margin_individual(const double size_left, const double size_top, const double size_right, const double size_bottom) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_expand_margin_individual");
	}
	___godot_icall_void_float_float_float_float(mb, (const Object *) this, size_left, size_top, size_right, size_bottom);
}

double StyleBoxTexture::get_expand_margin_size(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "get_expand_margin_size");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, margin);
}

void StyleBoxTexture::set_region_rect(const Rect2 region) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_region_rect");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, region);
}

Rect2 StyleBoxTexture::get_region_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "get_region_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void StyleBoxTexture::set_draw_center(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_draw_center");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool StyleBoxTexture::is_draw_center_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "is_draw_center_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void StyleBoxTexture::set_modulate(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_modulate");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color StyleBoxTexture::get_modulate() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "get_modulate");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void StyleBoxTexture::set_h_axis_stretch_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_h_axis_stretch_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

StyleBoxTexture::AxisStretchMode StyleBoxTexture::get_h_axis_stretch_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "get_h_axis_stretch_mode");
	}
	return (StyleBoxTexture::AxisStretchMode) ___godot_icall_int(mb, (const Object *) this);
}

void StyleBoxTexture::set_v_axis_stretch_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "set_v_axis_stretch_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

StyleBoxTexture::AxisStretchMode StyleBoxTexture::get_v_axis_stretch_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBoxTexture", "get_v_axis_stretch_mode");
	}
	return (StyleBoxTexture::AxisStretchMode) ___godot_icall_int(mb, (const Object *) this);
}

}