#include <DynamicFontData.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *DynamicFontData::___get_type_tag()
{
	return (void *) &DynamicFontData::___get_type_tag;
}

void *DynamicFontData::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

DynamicFontData *DynamicFontData::_new()
{
	return (DynamicFontData *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"DynamicFontData")());
}
void DynamicFontData::set_font_path(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFontData", "set_font_path");
	}
	___godot_icall_void_String(mb, (const Object *) this, path);
}

String DynamicFontData::get_font_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFontData", "get_font_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void DynamicFontData::set_hinting(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFontData", "set_hinting");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

DynamicFontData::Hinting DynamicFontData::get_hinting() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DynamicFontData", "get_hinting");
	}
	return (DynamicFontData::Hinting) ___godot_icall_int(mb, (const Object *) this);
}

}