#include <ProxyTexture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *ProxyTexture::___get_type_tag()
{
	return (void *) &ProxyTexture::___get_type_tag;
}

void *ProxyTexture::___get_base_type_tag()
{
	return (void *) &Texture::___get_type_tag;
}

ProxyTexture *ProxyTexture::_new()
{
	return (ProxyTexture *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ProxyTexture")());
}
void ProxyTexture::set_base(const Ref<Texture> base) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProxyTexture", "set_base");
	}
	___godot_icall_void_Object(mb, (const Object *) this, base.ptr());
}

Ref<Texture> ProxyTexture::get_base() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProxyTexture", "get_base");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}