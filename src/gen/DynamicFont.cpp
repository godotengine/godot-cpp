#include <DynamicFont.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <DynamicFontData.hpp>


namespace godot {


void *DynamicFont::___get_type_tag()
{
	return (void *) &DynamicFont::___get_type_tag;
}

void *DynamicFont::___get_base_type_tag()
{
	return (void *) &Font::___get_type_tag;
}

DynamicFont *DynamicFont::_new()
{
	return (DynamicFont *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"DynamicFont")());
}
void DynamicFont::set_font_data(const Ref<DynamicFontData> data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "set_font_data");
	}
	___godot_icall_void_Object(mb, (const Object *) this, data.ptr());
}

Ref<DynamicFontData> DynamicFont::get_font_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "get_font_data");
	}
	return Ref<DynamicFontData>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void DynamicFont::set_size(const int64_t data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "set_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, data);
}

int64_t DynamicFont::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "get_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void DynamicFont::set_use_mipmaps(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "set_use_mipmaps");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool DynamicFont::get_use_mipmaps() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "get_use_mipmaps");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void DynamicFont::set_use_filter(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "set_use_filter");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool DynamicFont::get_use_filter() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "get_use_filter");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void DynamicFont::set_spacing(const int64_t type, const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "set_spacing");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, type, value);
}

int64_t DynamicFont::get_spacing(const int64_t type) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "get_spacing");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, type);
}

void DynamicFont::add_fallback(const Ref<DynamicFontData> data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "add_fallback");
	}
	___godot_icall_void_Object(mb, (const Object *) this, data.ptr());
}

void DynamicFont::set_fallback(const int64_t idx, const Ref<DynamicFontData> data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "set_fallback");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, idx, data.ptr());
}

Ref<DynamicFontData> DynamicFont::get_fallback(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "get_fallback");
	}
	return Ref<DynamicFontData>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, idx));
}

void DynamicFont::remove_fallback(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "remove_fallback");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

int64_t DynamicFont::get_fallback_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFont", "get_fallback_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}