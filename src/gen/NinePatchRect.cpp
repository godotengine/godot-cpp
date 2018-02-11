#include <NinePatchRect.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *NinePatchRect::___get_type_tag()
{
	return (void *) &NinePatchRect::___get_type_tag;
}

void *NinePatchRect::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

NinePatchRect *NinePatchRect::_new()
{
	return (NinePatchRect *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"NinePatchRect")());
}
void NinePatchRect::set_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "set_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> NinePatchRect::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void NinePatchRect::set_patch_margin(const int64_t margin, const int64_t value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "set_patch_margin");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, margin, value);
}

int64_t NinePatchRect::get_patch_margin(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "get_patch_margin");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, margin);
}

void NinePatchRect::set_region_rect(const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "set_region_rect");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, rect);
}

Rect2 NinePatchRect::get_region_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "get_region_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void NinePatchRect::set_draw_center(const bool draw_center) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "set_draw_center");
	}
	___godot_icall_void_bool(mb, (const Object *) this, draw_center);
}

bool NinePatchRect::is_draw_center_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "is_draw_center_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void NinePatchRect::set_h_axis_stretch_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "set_h_axis_stretch_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

NinePatchRect::AxisStretchMode NinePatchRect::get_h_axis_stretch_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "get_h_axis_stretch_mode");
	}
	return (NinePatchRect::AxisStretchMode) ___godot_icall_int(mb, (const Object *) this);
}

void NinePatchRect::set_v_axis_stretch_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "set_v_axis_stretch_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

NinePatchRect::AxisStretchMode NinePatchRect::get_v_axis_stretch_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NinePatchRect", "get_v_axis_stretch_mode");
	}
	return (NinePatchRect::AxisStretchMode) ___godot_icall_int(mb, (const Object *) this);
}

}