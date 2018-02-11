#include <PhysicsBody2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *PhysicsBody2D::___get_type_tag()
{
	return (void *) &PhysicsBody2D::___get_type_tag;
}

void *PhysicsBody2D::___get_base_type_tag()
{
	return (void *) &CollisionObject2D::___get_type_tag;
}

void PhysicsBody2D::set_collision_layer(const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "set_collision_layer");
	}
	___godot_icall_void_int(mb, (const Object *) this, layer);
}

int64_t PhysicsBody2D::get_collision_layer() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "get_collision_layer");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void PhysicsBody2D::set_collision_mask(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "set_collision_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t PhysicsBody2D::get_collision_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "get_collision_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void PhysicsBody2D::set_collision_mask_bit(const int64_t bit, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "set_collision_mask_bit");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bit, value);
}

bool PhysicsBody2D::get_collision_mask_bit(const int64_t bit) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "get_collision_mask_bit");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bit);
}

void PhysicsBody2D::set_collision_layer_bit(const int64_t bit, const bool value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "set_collision_layer_bit");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, bit, value);
}

bool PhysicsBody2D::get_collision_layer_bit(const int64_t bit) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "get_collision_layer_bit");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, bit);
}

void PhysicsBody2D::_set_layers(const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "_set_layers");
	}
	___godot_icall_void_int(mb, (const Object *) this, mask);
}

int64_t PhysicsBody2D::_get_layers() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "_get_layers");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void PhysicsBody2D::add_collision_exception_with(const Object *body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "add_collision_exception_with");
	}
	___godot_icall_void_Object(mb, (const Object *) this, body);
}

void PhysicsBody2D::remove_collision_exception_with(const Object *body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsBody2D", "remove_collision_exception_with");
	}
	___godot_icall_void_Object(mb, (const Object *) this, body);
}

}