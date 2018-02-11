#ifndef GODOT_CPP_COLLISIONSHAPE2D_HPP
#define GODOT_CPP_COLLISIONSHAPE2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Node2D.hpp>
namespace godot {

class Shape2D;

class CollisionShape2D : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "CollisionShape2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static CollisionShape2D *_new();

	// methods
	void set_shape(const Ref<Shape2D> shape);
	Ref<Shape2D> get_shape() const;
	void set_disabled(const bool disabled);
	bool is_disabled() const;
	void set_one_way_collision(const bool enabled);
	bool is_one_way_collision_enabled() const;
	void _shape_changed();

};

}

#endif