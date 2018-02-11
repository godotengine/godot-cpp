#include <ParallaxLayer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ParallaxLayer::___get_type_tag()
{
	return (void *) &ParallaxLayer::___get_type_tag;
}

void *ParallaxLayer::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

ParallaxLayer *ParallaxLayer::_new()
{
	return (ParallaxLayer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ParallaxLayer")());
}
void ParallaxLayer::set_motion_scale(const Vector2 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxLayer", "set_motion_scale");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, scale);
}

Vector2 ParallaxLayer::get_motion_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxLayer", "get_motion_scale");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void ParallaxLayer::set_motion_offset(const Vector2 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxLayer", "set_motion_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, offset);
}

Vector2 ParallaxLayer::get_motion_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxLayer", "get_motion_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void ParallaxLayer::set_mirroring(const Vector2 mirror) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxLayer", "set_mirroring");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, mirror);
}

Vector2 ParallaxLayer::get_mirroring() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxLayer", "get_mirroring");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

}