#include <CollisionShape2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Shape2D.hpp>


namespace godot {


void *CollisionShape2D::___get_type_tag()
{
	return (void *) &CollisionShape2D::___get_type_tag;
}

void *CollisionShape2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

CollisionShape2D *CollisionShape2D::_new()
{
	return (CollisionShape2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CollisionShape2D")());
}
void CollisionShape2D::set_shape(const Ref<Shape2D> shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape2D", "set_shape");
	}
	___godot_icall_void_Object(mb, (const Object *) this, shape.ptr());
}

Ref<Shape2D> CollisionShape2D::get_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape2D", "get_shape");
	}
	return Ref<Shape2D>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void CollisionShape2D::set_disabled(const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape2D", "set_disabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, disabled);
}

bool CollisionShape2D::is_disabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape2D", "is_disabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CollisionShape2D::set_one_way_collision(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape2D", "set_one_way_collision");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool CollisionShape2D::is_one_way_collision_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape2D", "is_one_way_collision_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CollisionShape2D::_shape_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionShape2D", "_shape_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}