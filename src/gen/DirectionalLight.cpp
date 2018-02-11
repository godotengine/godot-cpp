#include <DirectionalLight.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *DirectionalLight::___get_type_tag()
{
	return (void *) &DirectionalLight::___get_type_tag;
}

void *DirectionalLight::___get_base_type_tag()
{
	return (void *) &Light::___get_type_tag;
}

DirectionalLight *DirectionalLight::_new()
{
	return (DirectionalLight *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"DirectionalLight")());
}
void DirectionalLight::set_shadow_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DirectionalLight", "set_shadow_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

DirectionalLight::ShadowMode DirectionalLight::get_shadow_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DirectionalLight", "get_shadow_mode");
	}
	return (DirectionalLight::ShadowMode) ___godot_icall_int(mb, (const Object *) this);
}

void DirectionalLight::set_shadow_depth_range(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DirectionalLight", "set_shadow_depth_range");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

DirectionalLight::ShadowDepthRange DirectionalLight::get_shadow_depth_range() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DirectionalLight", "get_shadow_depth_range");
	}
	return (DirectionalLight::ShadowDepthRange) ___godot_icall_int(mb, (const Object *) this);
}

void DirectionalLight::set_blend_splits(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DirectionalLight", "set_blend_splits");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool DirectionalLight::is_blend_splits_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("DirectionalLight", "is_blend_splits_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}