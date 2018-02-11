#include <GradientTexture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Gradient.hpp>


namespace godot {


void *GradientTexture::___get_type_tag()
{
	return (void *) &GradientTexture::___get_type_tag;
}

void *GradientTexture::___get_base_type_tag()
{
	return (void *) &Texture::___get_type_tag;
}

GradientTexture *GradientTexture::_new()
{
	return (GradientTexture *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"GradientTexture")());
}
void GradientTexture::set_gradient(const Ref<Gradient> gradient) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GradientTexture", "set_gradient");
	}
	___godot_icall_void_Object(mb, (const Object *) this, gradient.ptr());
}

Ref<Gradient> GradientTexture::get_gradient() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GradientTexture", "get_gradient");
	}
	return Ref<Gradient>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void GradientTexture::set_width(const int64_t width) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GradientTexture", "set_width");
	}
	___godot_icall_void_int(mb, (const Object *) this, width);
}

void GradientTexture::_update() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GradientTexture", "_update");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}