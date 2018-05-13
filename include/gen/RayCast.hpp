#ifndef GODOT_CPP_RAYCAST_HPP
#define GODOT_CPP_RAYCAST_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Spatial.hpp"
namespace godot {

class Object;

class RayCast : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "RayCast"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static RayCast *_new();

	// methods
	void set_enabled(const bool enabled);
	bool is_enabled() const;
	void set_cast_to(const Vector3 local_point);
	Vector3 get_cast_to() const;
	bool is_colliding() const;
	void force_raycast_update();
	Object *get_collider() const;
	int64_t get_collider_shape() const;
	Vector3 get_collision_point() const;
	Vector3 get_collision_normal() const;
	void add_exception_rid(const RID rid);
	void add_exception(const Object *node);
	void remove_exception_rid(const RID rid);
	void remove_exception(const Object *node);
	void clear_exceptions();
	void set_collision_mask(const int64_t mask);
	int64_t get_collision_mask() const;
	void set_collision_mask_bit(const int64_t bit, const bool value);
	bool get_collision_mask_bit(const int64_t bit) const;
	void set_exclude_parent_body(const bool mask);
	bool get_exclude_parent_body() const;

};

}

#endif