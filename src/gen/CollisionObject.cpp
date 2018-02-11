#include <CollisionObject.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <InputEvent.hpp>
#include <Shape.hpp>


namespace godot {


void *CollisionObject::___get_type_tag()
{
	return (void *) &CollisionObject::___get_type_tag;
}

void *CollisionObject::___get_base_type_tag()
{
	return (void *) &Spatial::___get_type_tag;
}

void CollisionObject::_input_event(const Object *camera, const Ref<InputEvent> event, const Vector3 click_position, const Vector3 click_normal, const int64_t shape_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "_input_event");
	}
	___godot_icall_void_Object_Object_Vector3_Vector3_int(mb, (const Object *) this, camera, event.ptr(), click_position, click_normal, shape_idx);
}

void CollisionObject::set_ray_pickable(const bool ray_pickable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "set_ray_pickable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, ray_pickable);
}

bool CollisionObject::is_ray_pickable() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "is_ray_pickable");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void CollisionObject::set_capture_input_on_drag(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "set_capture_input_on_drag");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool CollisionObject::get_capture_input_on_drag() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "get_capture_input_on_drag");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

RID CollisionObject::get_rid() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "get_rid");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

int64_t CollisionObject::create_shape_owner(const Object *owner) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "create_shape_owner");
	}
	return ___godot_icall_int_Object(mb, (const Object *) this, owner);
}

void CollisionObject::remove_shape_owner(const int64_t owner_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "remove_shape_owner");
	}
	___godot_icall_void_int(mb, (const Object *) this, owner_id);
}

Array CollisionObject::get_shape_owners() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "get_shape_owners");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void CollisionObject::shape_owner_set_transform(const int64_t owner_id, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_owner_set_transform");
	}
	___godot_icall_void_int_Transform(mb, (const Object *) this, owner_id, transform);
}

Transform CollisionObject::shape_owner_get_transform(const int64_t owner_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_owner_get_transform");
	}
	return ___godot_icall_Transform_int(mb, (const Object *) this, owner_id);
}

Object *CollisionObject::shape_owner_get_owner(const int64_t owner_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_owner_get_owner");
	}
	return (Object *) ___godot_icall_Object_int(mb, (const Object *) this, owner_id);
}

void CollisionObject::shape_owner_set_disabled(const int64_t owner_id, const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_owner_set_disabled");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, owner_id, disabled);
}

bool CollisionObject::is_shape_owner_disabled(const int64_t owner_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "is_shape_owner_disabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, owner_id);
}

void CollisionObject::shape_owner_add_shape(const int64_t owner_id, const Ref<Shape> shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_owner_add_shape");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, owner_id, shape.ptr());
}

int64_t CollisionObject::shape_owner_get_shape_count(const int64_t owner_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_owner_get_shape_count");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, owner_id);
}

Ref<Shape> CollisionObject::shape_owner_get_shape(const int64_t owner_id, const int64_t shape_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_owner_get_shape");
	}
	return Ref<Shape>::__internal_constructor(___godot_icall_Object_int_int(mb, (const Object *) this, owner_id, shape_id));
}

int64_t CollisionObject::shape_owner_get_shape_index(const int64_t owner_id, const int64_t shape_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_owner_get_shape_index");
	}
	return ___godot_icall_int_int_int(mb, (const Object *) this, owner_id, shape_id);
}

void CollisionObject::shape_owner_remove_shape(const int64_t owner_id, const int64_t shape_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_owner_remove_shape");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, owner_id, shape_id);
}

void CollisionObject::shape_owner_clear_shapes(const int64_t owner_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_owner_clear_shapes");
	}
	___godot_icall_void_int(mb, (const Object *) this, owner_id);
}

int64_t CollisionObject::shape_find_owner(const int64_t shape_index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject", "shape_find_owner");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, shape_index);
}

}