#include <Theme.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>
#include <StyleBox.hpp>
#include <Font.hpp>


namespace godot {


void *Theme::___get_type_tag()
{
	return (void *) &Theme::___get_type_tag;
}

void *Theme::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Theme *Theme::_new()
{
	return (Theme *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Theme")());
}
void Theme::set_icon(const String name, const String type, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "set_icon");
	}
	___godot_icall_void_String_String_Object(mb, (const Object *) this, name, type, texture.ptr());
}

Ref<Texture> Theme::get_icon(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_icon");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_String_String(mb, (const Object *) this, name, type));
}

bool Theme::has_icon(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "has_icon");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, name, type);
}

void Theme::clear_icon(const String name, const String type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "clear_icon");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, type);
}

PoolStringArray Theme::get_icon_list(const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_icon_list");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, type);
}

void Theme::set_stylebox(const String name, const String type, const Ref<StyleBox> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "set_stylebox");
	}
	___godot_icall_void_String_String_Object(mb, (const Object *) this, name, type, texture.ptr());
}

Ref<StyleBox> Theme::get_stylebox(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_stylebox");
	}
	return Ref<StyleBox>::__internal_constructor(___godot_icall_Object_String_String(mb, (const Object *) this, name, type));
}

bool Theme::has_stylebox(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "has_stylebox");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, name, type);
}

void Theme::clear_stylebox(const String name, const String type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "clear_stylebox");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, type);
}

PoolStringArray Theme::get_stylebox_list(const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_stylebox_list");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, type);
}

PoolStringArray Theme::get_stylebox_types() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_stylebox_types");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

void Theme::set_font(const String name, const String type, const Ref<Font> font) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "set_font");
	}
	___godot_icall_void_String_String_Object(mb, (const Object *) this, name, type, font.ptr());
}

Ref<Font> Theme::get_font(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_font");
	}
	return Ref<Font>::__internal_constructor(___godot_icall_Object_String_String(mb, (const Object *) this, name, type));
}

bool Theme::has_font(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "has_font");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, name, type);
}

void Theme::clear_font(const String name, const String type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "clear_font");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, type);
}

PoolStringArray Theme::get_font_list(const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_font_list");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, type);
}

void Theme::set_color(const String name, const String type, const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "set_color");
	}
	___godot_icall_void_String_String_Color(mb, (const Object *) this, name, type, color);
}

Color Theme::get_color(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_color");
	}
	return ___godot_icall_Color_String_String(mb, (const Object *) this, name, type);
}

bool Theme::has_color(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "has_color");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, name, type);
}

void Theme::clear_color(const String name, const String type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "clear_color");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, type);
}

PoolStringArray Theme::get_color_list(const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_color_list");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, type);
}

void Theme::set_constant(const String name, const String type, const int64_t constant) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "set_constant");
	}
	___godot_icall_void_String_String_int(mb, (const Object *) this, name, type, constant);
}

int64_t Theme::get_constant(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_constant");
	}
	return ___godot_icall_int_String_String(mb, (const Object *) this, name, type);
}

bool Theme::has_constant(const String name, const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "has_constant");
	}
	return ___godot_icall_bool_String_String(mb, (const Object *) this, name, type);
}

void Theme::clear_constant(const String name, const String type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "clear_constant");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, name, type);
}

PoolStringArray Theme::get_constant_list(const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_constant_list");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, type);
}

void Theme::set_default_font(const Ref<Font> font) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "set_default_font");
	}
	___godot_icall_void_Object(mb, (const Object *) this, font.ptr());
}

Ref<Font> Theme::get_default_font() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_default_font");
	}
	return Ref<Font>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

PoolStringArray Theme::get_type_list(const String type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "get_type_list");
	}
	return ___godot_icall_PoolStringArray_String(mb, (const Object *) this, type);
}

void Theme::_emit_theme_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "_emit_theme_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Theme::copy_default_theme() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Theme", "copy_default_theme");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}