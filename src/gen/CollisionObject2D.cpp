#include <CollisionObject2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <InputEvent.hpp>
#include <Shape2D.hpp>


namespace godot {


void *CollisionObject2D::___get_type_tag()
{
	return (void *) &CollisionObject2D::___get_type_tag;
}

void *CollisionObject2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

void CollisionObject2D::_input_event(const Object *viewport, const Ref<InputEvent> event, const int64_t shape_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "_input_event");
	}
	___godot_icall_void_Object_Object_int(mb, (const Object *) this, viewport, event.ptr(), shape_idx);
}

RID CollisionObject2D::get_rid() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "get_rid");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void CollisionObject2D::set_pickable(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "set_pickable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool CollisionObject2D::is_pickable() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "is_pickable");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t CollisionObject2D::create_shape_owner(const Object *owner) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "create_shape_owner");
	}
	return ___godot_icall_int_Object(mb, (const Object *) this, owner);
}

void CollisionObject2D::remove_shape_owner(const int64_t owner_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "remove_shape_owner");
	}
	___godot_icall_void_int(mb, (const Object *) this, owner_id);
}

Array CollisionObject2D::get_shape_owners() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "get_shape_owners");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void CollisionObject2D::shape_owner_set_transform(const int64_t owner_id, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_set_transform");
	}
	___godot_icall_void_int_Transform2D(mb, (const Object *) this, owner_id, transform);
}

Transform2D CollisionObject2D::shape_owner_get_transform(const int64_t owner_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_get_transform");
	}
	return ___godot_icall_Transform2D_int(mb, (const Object *) this, owner_id);
}

Object *CollisionObject2D::shape_owner_get_owner(const int64_t owner_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_get_owner");
	}
	return (Object *) ___godot_icall_Object_int(mb, (const Object *) this, owner_id);
}

void CollisionObject2D::shape_owner_set_disabled(const int64_t owner_id, const bool disabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_set_disabled");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, owner_id, disabled);
}

bool CollisionObject2D::is_shape_owner_disabled(const int64_t owner_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "is_shape_owner_disabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, owner_id);
}

void CollisionObject2D::shape_owner_set_one_way_collision(const int64_t owner_id, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_set_one_way_collision");
	}
	___godot_icall_void_int_bool(mb, (const Object *) this, owner_id, enable);
}

bool CollisionObject2D::is_shape_owner_one_way_collision_enabled(const int64_t owner_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "is_shape_owner_one_way_collision_enabled");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, owner_id);
}

void CollisionObject2D::shape_owner_add_shape(const int64_t owner_id, const Ref<Shape2D> shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_add_shape");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, owner_id, shape.ptr());
}

int64_t CollisionObject2D::shape_owner_get_shape_count(const int64_t owner_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_get_shape_count");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, owner_id);
}

Ref<Shape2D> CollisionObject2D::shape_owner_get_shape(const int64_t owner_id, const int64_t shape_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_get_shape");
	}
	return Ref<Shape2D>::__internal_constructor(___godot_icall_Object_int_int(mb, (const Object *) this, owner_id, shape_id));
}

int64_t CollisionObject2D::shape_owner_get_shape_index(const int64_t owner_id, const int64_t shape_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_get_shape_index");
	}
	return ___godot_icall_int_int_int(mb, (const Object *) this, owner_id, shape_id);
}

void CollisionObject2D::shape_owner_remove_shape(const int64_t owner_id, const int64_t shape_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_remove_shape");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, owner_id, shape_id);
}

void CollisionObject2D::shape_owner_clear_shapes(const int64_t owner_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_owner_clear_shapes");
	}
	___godot_icall_void_int(mb, (const Object *) this, owner_id);
}

int64_t CollisionObject2D::shape_find_owner(const int64_t shape_index) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CollisionObject2D", "shape_find_owner");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, shape_index);
}

}