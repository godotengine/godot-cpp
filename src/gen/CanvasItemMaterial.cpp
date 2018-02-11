#include <CanvasItemMaterial.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *CanvasItemMaterial::___get_type_tag()
{
	return (void *) &CanvasItemMaterial::___get_type_tag;
}

void *CanvasItemMaterial::___get_base_type_tag()
{
	return (void *) &Material::___get_type_tag;
}

CanvasItemMaterial *CanvasItemMaterial::_new()
{
	return (CanvasItemMaterial *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CanvasItemMaterial")());
}
void CanvasItemMaterial::set_blend_mode(const int64_t blend_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItemMaterial", "set_blend_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, blend_mode);
}

CanvasItemMaterial::BlendMode CanvasItemMaterial::get_blend_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItemMaterial", "get_blend_mode");
	}
	return (CanvasItemMaterial::BlendMode) ___godot_icall_int(mb, (const Object *) this);
}

void CanvasItemMaterial::set_light_mode(const int64_t light_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItemMaterial", "set_light_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, light_mode);
}

CanvasItemMaterial::LightMode CanvasItemMaterial::get_light_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasItemMaterial", "get_light_mode");
	}
	return (CanvasItemMaterial::LightMode) ___godot_icall_int(mb, (const Object *) this);
}

}