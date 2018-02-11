#include <CanvasLayer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <Node.hpp>
#include <World2D.hpp>


namespace godot {


void *CanvasLayer::___get_type_tag()
{
	return (void *) &CanvasLayer::___get_type_tag;
}

void *CanvasLayer::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

CanvasLayer *CanvasLayer::_new()
{
	return (CanvasLayer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CanvasLayer")());
}
void CanvasLayer::set_layer(const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "set_layer");
	}
	___godot_icall_void_int(mb, (const Object *) this, layer);
}

int64_t CanvasLayer::get_layer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "get_layer");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void CanvasLayer::set_transform(const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "set_transform");
	}
	___godot_icall_void_Transform2D(mb, (const Object *) this, transform);
}

Transform2D CanvasLayer::get_transform() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "get_transform");
	}
	return ___godot_icall_Transform2D(mb, (const Object *) this);
}

void CanvasLayer::set_offset(const Vector2 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "set_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, offset);
}

Vector2 CanvasLayer::get_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "get_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void CanvasLayer::set_rotation(const double radians) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "set_rotation");
	}
	___godot_icall_void_float(mb, (const Object *) this, radians);
}

double CanvasLayer::get_rotation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "get_rotation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void CanvasLayer::set_rotation_degrees(const double degrees) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "set_rotation_degrees");
	}
	___godot_icall_void_float(mb, (const Object *) this, degrees);
}

double CanvasLayer::get_rotation_degrees() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "get_rotation_degrees");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void CanvasLayer::set_scale(const Vector2 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "set_scale");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, scale);
}

Vector2 CanvasLayer::get_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "get_scale");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void CanvasLayer::set_custom_viewport(const Object *viewport) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "set_custom_viewport");
	}
	___godot_icall_void_Object(mb, (const Object *) this, viewport);
}

Node *CanvasLayer::get_custom_viewport() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "get_custom_viewport");
	}
	return (Node *) ___godot_icall_Object(mb, (const Object *) this);
}

Ref<World2D> CanvasLayer::get_world_2d() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CanvasLayer", "get_world_2d");
	}
	return Ref<World2D>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

}