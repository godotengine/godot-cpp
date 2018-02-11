#include <AtlasTexture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *AtlasTexture::___get_type_tag()
{
	return (void *) &AtlasTexture::___get_type_tag;
}

void *AtlasTexture::___get_base_type_tag()
{
	return (void *) &Texture::___get_type_tag;
}

AtlasTexture *AtlasTexture::_new()
{
	return (AtlasTexture *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AtlasTexture")());
}
void AtlasTexture::set_atlas(const Ref<Texture> atlas) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AtlasTexture", "set_atlas");
	}
	___godot_icall_void_Object(mb, (const Object *) this, atlas.ptr());
}

Ref<Texture> AtlasTexture::get_atlas() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AtlasTexture", "get_atlas");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void AtlasTexture::set_region(const Rect2 region) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AtlasTexture", "set_region");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, region);
}

Rect2 AtlasTexture::get_region() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AtlasTexture", "get_region");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void AtlasTexture::set_margin(const Rect2 margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AtlasTexture", "set_margin");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, margin);
}

Rect2 AtlasTexture::get_margin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AtlasTexture", "get_margin");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void AtlasTexture::set_filter_clip(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AtlasTexture", "set_filter_clip");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool AtlasTexture::has_filter_clip() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AtlasTexture", "has_filter_clip");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}