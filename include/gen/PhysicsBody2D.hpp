#ifndef GODOT_CPP_PHYSICSBODY2D_HPP
#define GODOT_CPP_PHYSICSBODY2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "CollisionObject2D.hpp"
namespace godot {

class Object;

class PhysicsBody2D : public CollisionObject2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "PhysicsBody2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void set_collision_layer(const int64_t layer);
	int64_t get_collision_layer() const;
	void set_collision_mask(const int64_t mask);
	int64_t get_collision_mask() const;
	void set_collision_mask_bit(const int64_t bit, const bool value);
	bool get_collision_mask_bit(const int64_t bit) const;
	void set_collision_layer_bit(const int64_t bit, const bool value);
	bool get_collision_layer_bit(const int64_t bit) const;
	void _set_layers(const int64_t mask);
	int64_t _get_layers() const;
	void add_collision_exception_with(const Object *body);
	void remove_collision_exception_with(const Object *body);

};

}

#endif