#ifndef GODOT_CPP_PHYSICS2DTESTMOTIONRESULT_HPP
#define GODOT_CPP_PHYSICS2DTESTMOTIONRESULT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class Object;

class Physics2DTestMotionResult : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Physics2DTestMotionResult"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Physics2DTestMotionResult *_new();

	// methods
	Vector2 get_motion() const;
	Vector2 get_motion_remainder() const;
	Vector2 get_collision_point() const;
	Vector2 get_collision_normal() const;
	Vector2 get_collider_velocity() const;
	int64_t get_collider_id() const;
	RID get_collider_rid() const;
	Object *get_collider() const;
	int64_t get_collider_shape() const;

};

}

#endif