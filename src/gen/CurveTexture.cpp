#include <CurveTexture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Curve.hpp>


namespace godot {


void *CurveTexture::___get_type_tag()
{
	return (void *) &CurveTexture::___get_type_tag;
}

void *CurveTexture::___get_base_type_tag()
{
	return (void *) &Texture::___get_type_tag;
}

CurveTexture *CurveTexture::_new()
{
	return (CurveTexture *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CurveTexture")());
}
void CurveTexture::set_width(const int64_t width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CurveTexture", "set_width");
	}
	___godot_icall_void_int(mb, (const Object *) this, width);
}

void CurveTexture::set_curve(const Ref<Curve> curve) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CurveTexture", "set_curve");
	}
	___godot_icall_void_Object(mb, (const Object *) this, curve.ptr());
}

Ref<Curve> CurveTexture::get_curve() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CurveTexture", "get_curve");
	}
	return Ref<Curve>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void CurveTexture::_update() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CurveTexture", "_update");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}