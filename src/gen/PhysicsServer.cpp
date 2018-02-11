#include <PhysicsServer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <PhysicsDirectSpaceState.hpp>
#include <Object.hpp>
#include <PhysicsDirectBodyState.hpp>


namespace godot {


void *PhysicsServer::___get_type_tag()
{
	return (void *) &PhysicsServer::___get_type_tag;
}

void *PhysicsServer::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

PhysicsServer *PhysicsServer::_singleton = NULL;


PhysicsServer::PhysicsServer() {
	_owner = godot::api->godot_global_get_singleton((char *) "PhysicsServer");
}


RID PhysicsServer::shape_create(const int64_t type) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "shape_create");
	}
	return ___godot_icall_RID_int(mb, (const Object *) this, type);
}

void PhysicsServer::shape_set_data(const RID shape, const Variant data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "shape_set_data");
	}
	___godot_icall_void_RID_Variant(mb, (const Object *) this, shape, data);
}

PhysicsServer::ShapeType PhysicsServer::shape_get_type(const RID shape) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "shape_get_type");
	}
	return (PhysicsServer::ShapeType) ___godot_icall_int_RID(mb, (const Object *) this, shape);
}

Variant PhysicsServer::shape_get_data(const RID shape) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "shape_get_data");
	}
	return ___godot_icall_Variant_RID(mb, (const Object *) this, shape);
}

RID PhysicsServer::space_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "space_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void PhysicsServer::space_set_active(const RID space, const bool active) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "space_set_active");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, space, active);
}

bool PhysicsServer::space_is_active(const RID space) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "space_is_active");
	}
	return ___godot_icall_bool_RID(mb, (const Object *) this, space);
}

void PhysicsServer::space_set_param(const RID space, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "space_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, space, param, value);
}

double PhysicsServer::space_get_param(const RID space, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "space_get_param");
	}
	return ___godot_icall_float_RID_int(mb, (const Object *) this, space, param);
}

PhysicsDirectSpaceState *PhysicsServer::space_get_direct_state(const RID space) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "space_get_direct_state");
	}
	return (PhysicsDirectSpaceState *) ___godot_icall_Object_RID(mb, (const Object *) this, space);
}

RID PhysicsServer::area_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void PhysicsServer::area_set_space(const RID area, const RID space) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_set_space");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, area, space);
}

RID PhysicsServer::area_get_space(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_get_space");
	}
	return ___godot_icall_RID_RID(mb, (const Object *) this, area);
}

void PhysicsServer::area_set_space_override_mode(const RID area, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_set_space_override_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, area, mode);
}

PhysicsServer::AreaSpaceOverrideMode PhysicsServer::area_get_space_override_mode(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_get_space_override_mode");
	}
	return (PhysicsServer::AreaSpaceOverrideMode) ___godot_icall_int_RID(mb, (const Object *) this, area);
}

void PhysicsServer::area_add_shape(const RID area, const RID shape, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_add_shape");
	}
	___godot_icall_void_RID_RID_Transform(mb, (const Object *) this, area, shape, transform);
}

void PhysicsServer::area_set_shape(const RID area, const int64_t shape_idx, const RID shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_set_shape");
	}
	___godot_icall_void_RID_int_RID(mb, (const Object *) this, area, shape_idx, shape);
}

void PhysicsServer::area_set_shape_transform(const RID area, const int64_t shape_idx, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_set_shape_transform");
	}
	___godot_icall_void_RID_int_Transform(mb, (const Object *) this, area, shape_idx, transform);
}

int64_t PhysicsServer::area_get_shape_count(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_get_shape_count");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, area);
}

RID PhysicsServer::area_get_shape(const RID area, const int64_t shape_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_get_shape");
	}
	return ___godot_icall_RID_RID_int(mb, (const Object *) this, area, shape_idx);
}

Transform PhysicsServer::area_get_shape_transform(const RID area, const int64_t shape_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_get_shape_transform");
	}
	return ___godot_icall_Transform_RID_int(mb, (const Object *) this, area, shape_idx);
}

void PhysicsServer::area_remove_shape(const RID area, const int64_t shape_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_remove_shape");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, area, shape_idx);
}

void PhysicsServer::area_clear_shapes(const RID area) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_clear_shapes");
	}
	___godot_icall_void_RID(mb, (const Object *) this, area);
}

void PhysicsServer::area_set_collision_layer(const RID area, const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_set_collision_layer");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, area, layer);
}

void PhysicsServer::area_set_collision_mask(const RID area, const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_set_collision_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, area, mask);
}

void PhysicsServer::area_set_param(const RID area, const int64_t param, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_set_param");
	}
	___godot_icall_void_RID_int_Variant(mb, (const Object *) this, area, param, value);
}

void PhysicsServer::area_set_transform(const RID area, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_set_transform");
	}
	___godot_icall_void_RID_Transform(mb, (const Object *) this, area, transform);
}

Variant PhysicsServer::area_get_param(const RID area, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_get_param");
	}
	return ___godot_icall_Variant_RID_int(mb, (const Object *) this, area, param);
}

Transform PhysicsServer::area_get_transform(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_get_transform");
	}
	return ___godot_icall_Transform_RID(mb, (const Object *) this, area);
}

void PhysicsServer::area_attach_object_instance_id(const RID area, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_attach_object_instance_id");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, area, id);
}

int64_t PhysicsServer::area_get_object_instance_id(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_get_object_instance_id");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, area);
}

void PhysicsServer::area_set_monitor_callback(const RID area, const Object *receiver, const String method) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_set_monitor_callback");
	}
	___godot_icall_void_RID_Object_String(mb, (const Object *) this, area, receiver, method);
}

void PhysicsServer::area_set_ray_pickable(const RID area, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_set_ray_pickable");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, area, enable);
}

bool PhysicsServer::area_is_ray_pickable(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "area_is_ray_pickable");
	}
	return ___godot_icall_bool_RID(mb, (const Object *) this, area);
}

RID PhysicsServer::body_create(const int64_t mode, const bool init_sleeping) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_create");
	}
	return ___godot_icall_RID_int_bool(mb, (const Object *) this, mode, init_sleeping);
}

void PhysicsServer::body_set_space(const RID body, const RID space) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_space");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, body, space);
}

RID PhysicsServer::body_get_space(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_space");
	}
	return ___godot_icall_RID_RID(mb, (const Object *) this, body);
}

void PhysicsServer::body_set_mode(const RID body, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, mode);
}

PhysicsServer::BodyMode PhysicsServer::body_get_mode(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_mode");
	}
	return (PhysicsServer::BodyMode) ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void PhysicsServer::body_set_collision_layer(const RID body, const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_collision_layer");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, layer);
}

int64_t PhysicsServer::body_get_collision_layer(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_collision_layer");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void PhysicsServer::body_set_collision_mask(const RID body, const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_collision_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, mask);
}

int64_t PhysicsServer::body_get_collision_mask(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_collision_mask");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void PhysicsServer::body_add_shape(const RID body, const RID shape, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_add_shape");
	}
	___godot_icall_void_RID_RID_Transform(mb, (const Object *) this, body, shape, transform);
}

void PhysicsServer::body_set_shape(const RID body, const int64_t shape_idx, const RID shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_shape");
	}
	___godot_icall_void_RID_int_RID(mb, (const Object *) this, body, shape_idx, shape);
}

void PhysicsServer::body_set_shape_transform(const RID body, const int64_t shape_idx, const Transform transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_shape_transform");
	}
	___godot_icall_void_RID_int_Transform(mb, (const Object *) this, body, shape_idx, transform);
}

int64_t PhysicsServer::body_get_shape_count(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_shape_count");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, body);
}

RID PhysicsServer::body_get_shape(const RID body, const int64_t shape_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_shape");
	}
	return ___godot_icall_RID_RID_int(mb, (const Object *) this, body, shape_idx);
}

Transform PhysicsServer::body_get_shape_transform(const RID body, const int64_t shape_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_shape_transform");
	}
	return ___godot_icall_Transform_RID_int(mb, (const Object *) this, body, shape_idx);
}

void PhysicsServer::body_remove_shape(const RID body, const int64_t shape_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_remove_shape");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, shape_idx);
}

void PhysicsServer::body_clear_shapes(const RID body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_clear_shapes");
	}
	___godot_icall_void_RID(mb, (const Object *) this, body);
}

void PhysicsServer::body_attach_object_instance_id(const RID body, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_attach_object_instance_id");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, id);
}

int64_t PhysicsServer::body_get_object_instance_id(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_object_instance_id");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void PhysicsServer::body_set_enable_continuous_collision_detection(const RID body, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_enable_continuous_collision_detection");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, body, enable);
}

bool PhysicsServer::body_is_continuous_collision_detection_enabled(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_is_continuous_collision_detection_enabled");
	}
	return ___godot_icall_bool_RID(mb, (const Object *) this, body);
}

void PhysicsServer::body_set_param(const RID body, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, body, param, value);
}

double PhysicsServer::body_get_param(const RID body, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_param");
	}
	return ___godot_icall_float_RID_int(mb, (const Object *) this, body, param);
}

void PhysicsServer::body_set_kinematic_safe_margin(const RID body, const double margin) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_kinematic_safe_margin");
	}
	___godot_icall_void_RID_float(mb, (const Object *) this, body, margin);
}

double PhysicsServer::body_get_kinematic_safe_margin(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_kinematic_safe_margin");
	}
	return ___godot_icall_float_RID(mb, (const Object *) this, body);
}

void PhysicsServer::body_set_state(const RID body, const int64_t state, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_state");
	}
	___godot_icall_void_RID_int_Variant(mb, (const Object *) this, body, state, value);
}

Variant PhysicsServer::body_get_state(const RID body, const int64_t state) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_state");
	}
	return ___godot_icall_Variant_RID_int(mb, (const Object *) this, body, state);
}

void PhysicsServer::body_apply_impulse(const RID body, const Vector3 position, const Vector3 impulse) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_apply_impulse");
	}
	___godot_icall_void_RID_Vector3_Vector3(mb, (const Object *) this, body, position, impulse);
}

void PhysicsServer::body_apply_torque_impulse(const RID body, const Vector3 impulse) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_apply_torque_impulse");
	}
	___godot_icall_void_RID_Vector3(mb, (const Object *) this, body, impulse);
}

void PhysicsServer::body_set_axis_velocity(const RID body, const Vector3 axis_velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_axis_velocity");
	}
	___godot_icall_void_RID_Vector3(mb, (const Object *) this, body, axis_velocity);
}

void PhysicsServer::body_set_axis_lock(const RID body, const int64_t axis, const bool lock) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_axis_lock");
	}
	___godot_icall_void_RID_int_bool(mb, (const Object *) this, body, axis, lock);
}

bool PhysicsServer::body_is_axis_locked(const RID body, const int64_t axis) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_is_axis_locked");
	}
	return ___godot_icall_bool_RID_int(mb, (const Object *) this, body, axis);
}

void PhysicsServer::body_add_collision_exception(const RID body, const RID excepted_body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_add_collision_exception");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, body, excepted_body);
}

void PhysicsServer::body_remove_collision_exception(const RID body, const RID excepted_body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_remove_collision_exception");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, body, excepted_body);
}

void PhysicsServer::body_set_max_contacts_reported(const RID body, const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_max_contacts_reported");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, amount);
}

int64_t PhysicsServer::body_get_max_contacts_reported(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_max_contacts_reported");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void PhysicsServer::body_set_omit_force_integration(const RID body, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_omit_force_integration");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, body, enable);
}

bool PhysicsServer::body_is_omitting_force_integration(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_is_omitting_force_integration");
	}
	return ___godot_icall_bool_RID(mb, (const Object *) this, body);
}

void PhysicsServer::body_set_force_integration_callback(const RID body, const Object *receiver, const String method, const Variant userdata) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_force_integration_callback");
	}
	___godot_icall_void_RID_Object_String_Variant(mb, (const Object *) this, body, receiver, method, userdata);
}

void PhysicsServer::body_set_ray_pickable(const RID body, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_set_ray_pickable");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, body, enable);
}

bool PhysicsServer::body_is_ray_pickable(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_is_ray_pickable");
	}
	return ___godot_icall_bool_RID(mb, (const Object *) this, body);
}

PhysicsDirectBodyState *PhysicsServer::body_get_direct_state(const RID body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "body_get_direct_state");
	}
	return (PhysicsDirectBodyState *) ___godot_icall_Object_RID(mb, (const Object *) this, body);
}

RID PhysicsServer::joint_create_pin(const RID body_A, const Vector3 local_A, const RID body_B, const Vector3 local_B) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "joint_create_pin");
	}
	return ___godot_icall_RID_RID_Vector3_RID_Vector3(mb, (const Object *) this, body_A, local_A, body_B, local_B);
}

void PhysicsServer::pin_joint_set_param(const RID joint, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "pin_joint_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, joint, param, value);
}

double PhysicsServer::pin_joint_get_param(const RID joint, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "pin_joint_get_param");
	}
	return ___godot_icall_float_RID_int(mb, (const Object *) this, joint, param);
}

void PhysicsServer::pin_joint_set_local_a(const RID joint, const Vector3 local_A) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "pin_joint_set_local_a");
	}
	___godot_icall_void_RID_Vector3(mb, (const Object *) this, joint, local_A);
}

Vector3 PhysicsServer::pin_joint_get_local_a(const RID joint) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "pin_joint_get_local_a");
	}
	return ___godot_icall_Vector3_RID(mb, (const Object *) this, joint);
}

void PhysicsServer::pin_joint_set_local_b(const RID joint, const Vector3 local_B) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "pin_joint_set_local_b");
	}
	___godot_icall_void_RID_Vector3(mb, (const Object *) this, joint, local_B);
}

Vector3 PhysicsServer::pin_joint_get_local_b(const RID joint) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "pin_joint_get_local_b");
	}
	return ___godot_icall_Vector3_RID(mb, (const Object *) this, joint);
}

RID PhysicsServer::joint_create_hinge(const RID body_A, const Transform hinge_A, const RID body_B, const Transform hinge_B) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "joint_create_hinge");
	}
	return ___godot_icall_RID_RID_Transform_RID_Transform(mb, (const Object *) this, body_A, hinge_A, body_B, hinge_B);
}

void PhysicsServer::hinge_joint_set_param(const RID joint, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "hinge_joint_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, joint, param, value);
}

double PhysicsServer::hinge_joint_get_param(const RID joint, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "hinge_joint_get_param");
	}
	return ___godot_icall_float_RID_int(mb, (const Object *) this, joint, param);
}

void PhysicsServer::hinge_joint_set_flag(const RID joint, const int64_t flag, const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "hinge_joint_set_flag");
	}
	___godot_icall_void_RID_int_bool(mb, (const Object *) this, joint, flag, enabled);
}

bool PhysicsServer::hinge_joint_get_flag(const RID joint, const int64_t flag) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "hinge_joint_get_flag");
	}
	return ___godot_icall_bool_RID_int(mb, (const Object *) this, joint, flag);
}

RID PhysicsServer::joint_create_slider(const RID body_A, const Transform local_ref_A, const RID body_B, const Transform local_ref_B) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "joint_create_slider");
	}
	return ___godot_icall_RID_RID_Transform_RID_Transform(mb, (const Object *) this, body_A, local_ref_A, body_B, local_ref_B);
}

void PhysicsServer::slider_joint_set_param(const RID joint, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "slider_joint_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, joint, param, value);
}

double PhysicsServer::slider_joint_get_param(const RID joint, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "slider_joint_get_param");
	}
	return ___godot_icall_float_RID_int(mb, (const Object *) this, joint, param);
}

RID PhysicsServer::joint_create_cone_twist(const RID body_A, const Transform local_ref_A, const RID body_B, const Transform local_ref_B) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "joint_create_cone_twist");
	}
	return ___godot_icall_RID_RID_Transform_RID_Transform(mb, (const Object *) this, body_A, local_ref_A, body_B, local_ref_B);
}

void PhysicsServer::cone_twist_joint_set_param(const RID joint, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "cone_twist_joint_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, joint, param, value);
}

double PhysicsServer::cone_twist_joint_get_param(const RID joint, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "cone_twist_joint_get_param");
	}
	return ___godot_icall_float_RID_int(mb, (const Object *) this, joint, param);
}

PhysicsServer::JointType PhysicsServer::joint_get_type(const RID joint) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "joint_get_type");
	}
	return (PhysicsServer::JointType) ___godot_icall_int_RID(mb, (const Object *) this, joint);
}

void PhysicsServer::joint_set_solver_priority(const RID joint, const int64_t priority) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "joint_set_solver_priority");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, joint, priority);
}

int64_t PhysicsServer::joint_get_solver_priority(const RID joint) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "joint_get_solver_priority");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, joint);
}

RID PhysicsServer::joint_create_generic_6dof(const RID body_A, const Transform local_ref_A, const RID body_B, const Transform local_ref_B) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "joint_create_generic_6dof");
	}
	return ___godot_icall_RID_RID_Transform_RID_Transform(mb, (const Object *) this, body_A, local_ref_A, body_B, local_ref_B);
}

void PhysicsServer::generic_6dof_joint_set_param(const RID joint, const int64_t axis, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "generic_6dof_joint_set_param");
	}
	___godot_icall_void_RID_int_int_float(mb, (const Object *) this, joint, axis, param, value);
}

double PhysicsServer::generic_6dof_joint_get_param(const RID joint, const int64_t axis, const int64_t param) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "generic_6dof_joint_get_param");
	}
	return ___godot_icall_float_RID_int_int(mb, (const Object *) this, joint, axis, param);
}

void PhysicsServer::generic_6dof_joint_set_flag(const RID joint, const int64_t axis, const int64_t flag, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "generic_6dof_joint_set_flag");
	}
	___godot_icall_void_RID_int_int_bool(mb, (const Object *) this, joint, axis, flag, enable);
}

bool PhysicsServer::generic_6dof_joint_get_flag(const RID joint, const int64_t axis, const int64_t flag) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "generic_6dof_joint_get_flag");
	}
	return ___godot_icall_bool_RID_int_int(mb, (const Object *) this, joint, axis, flag);
}

void PhysicsServer::free_rid(const RID rid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "free_rid");
	}
	___godot_icall_void_RID(mb, (const Object *) this, rid);
}

void PhysicsServer::set_active(const bool active) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "set_active");
	}
	___godot_icall_void_bool(mb, (const Object *) this, active);
}

int64_t PhysicsServer::get_process_info(const int64_t process_info) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PhysicsServer", "get_process_info");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, process_info);
}

}