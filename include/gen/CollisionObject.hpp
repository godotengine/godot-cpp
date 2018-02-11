#ifndef GODOT_CPP_COLLISIONOBJECT_HPP
#define GODOT_CPP_COLLISIONOBJECT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Spatial.hpp>
namespace godot {

class Object;
class InputEvent;
class Shape;

class CollisionObject : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "CollisionObject"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void _input_event(const Object *camera, const Ref<InputEvent> event, const Vector3 click_position, const Vector3 click_normal, const int64_t shape_idx);
	void set_ray_pickable(const bool ray_pickable);
	bool is_ray_pickable() const;
	void set_capture_input_on_drag(const bool enable);
	bool get_capture_input_on_drag() const;
	RID get_rid() const;
	int64_t create_shape_owner(const Object *owner);
	void remove_shape_owner(const int64_t owner_id);
	Array get_shape_owners();
	void shape_owner_set_transform(const int64_t owner_id, const Transform transform);
	Transform shape_owner_get_transform(const int64_t owner_id) const;
	Object *shape_owner_get_owner(const int64_t owner_id) const;
	void shape_owner_set_disabled(const int64_t owner_id, const bool disabled);
	bool is_shape_owner_disabled(const int64_t owner_id) const;
	void shape_owner_add_shape(const int64_t owner_id, const Ref<Shape> shape);
	int64_t shape_owner_get_shape_count(const int64_t owner_id) const;
	Ref<Shape> shape_owner_get_shape(const int64_t owner_id, const int64_t shape_id) const;
	int64_t shape_owner_get_shape_index(const int64_t owner_id, const int64_t shape_id) const;
	void shape_owner_remove_shape(const int64_t owner_id, const int64_t shape_id);
	void shape_owner_clear_shapes(const int64_t owner_id);
	int64_t shape_find_owner(const int64_t shape_index) const;

};

}

#endif