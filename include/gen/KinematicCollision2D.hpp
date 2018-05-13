#ifndef GODOT_CPP_KINEMATICCOLLISION2D_HPP
#define GODOT_CPP_KINEMATICCOLLISION2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Reference.hpp"
namespace godot {

class Object;

class KinematicCollision2D : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "KinematicCollision2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static KinematicCollision2D *_new();

	// methods
	Vector2 get_position() const;
	Vector2 get_normal() const;
	Vector2 get_travel() const;
	Vector2 get_remainder() const;
	Object *get_local_shape() const;
	Object *get_collider() const;
	int64_t get_collider_id() const;
	Object *get_collider_shape() const;
	int64_t get_collider_shape_index() const;
	Vector2 get_collider_velocity() const;
	Variant get_collider_metadata() const;

};

}

#endif