#include <Physics2DServer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Physics2DDirectSpaceState.hpp>
#include <Object.hpp>
#include <Physics2DTestMotionResult.hpp>
#include <Physics2DDirectBodyState.hpp>


namespace godot {


void *Physics2DServer::___get_type_tag()
{
	return (void *) &Physics2DServer::___get_type_tag;
}

void *Physics2DServer::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

Physics2DServer *Physics2DServer::_singleton = NULL;


Physics2DServer::Physics2DServer() {
	_owner = godot::api->godot_global_get_singleton((char *) "Physics2DServer");
}


RID Physics2DServer::line_shape_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "line_shape_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID Physics2DServer::ray_shape_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "ray_shape_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID Physics2DServer::segment_shape_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "segment_shape_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID Physics2DServer::circle_shape_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "circle_shape_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID Physics2DServer::rectangle_shape_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "rectangle_shape_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID Physics2DServer::capsule_shape_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "capsule_shape_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID Physics2DServer::convex_polygon_shape_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "convex_polygon_shape_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID Physics2DServer::concave_polygon_shape_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "concave_polygon_shape_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void Physics2DServer::shape_set_data(const RID shape, const Variant data) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "shape_set_data");
	}
	___godot_icall_void_RID_Variant(mb, (const Object *) this, shape, data);
}

Physics2DServer::ShapeType Physics2DServer::shape_get_type(const RID shape) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "shape_get_type");
	}
	return (Physics2DServer::ShapeType) ___godot_icall_int_RID(mb, (const Object *) this, shape);
}

Variant Physics2DServer::shape_get_data(const RID shape) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "shape_get_data");
	}
	return ___godot_icall_Variant_RID(mb, (const Object *) this, shape);
}

RID Physics2DServer::space_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "space_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void Physics2DServer::space_set_active(const RID space, const bool active) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "space_set_active");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, space, active);
}

bool Physics2DServer::space_is_active(const RID space) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "space_is_active");
	}
	return ___godot_icall_bool_RID(mb, (const Object *) this, space);
}

void Physics2DServer::space_set_param(const RID space, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "space_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, space, param, value);
}

double Physics2DServer::space_get_param(const RID space, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "space_get_param");
	}
	return ___godot_icall_float_RID_int(mb, (const Object *) this, space, param);
}

Physics2DDirectSpaceState *Physics2DServer::space_get_direct_state(const RID space) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "space_get_direct_state");
	}
	return (Physics2DDirectSpaceState *) ___godot_icall_Object_RID(mb, (const Object *) this, space);
}

RID Physics2DServer::area_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void Physics2DServer::area_set_space(const RID area, const RID space) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_set_space");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, area, space);
}

RID Physics2DServer::area_get_space(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_get_space");
	}
	return ___godot_icall_RID_RID(mb, (const Object *) this, area);
}

void Physics2DServer::area_set_space_override_mode(const RID area, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_set_space_override_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, area, mode);
}

Physics2DServer::AreaSpaceOverrideMode Physics2DServer::area_get_space_override_mode(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_get_space_override_mode");
	}
	return (Physics2DServer::AreaSpaceOverrideMode) ___godot_icall_int_RID(mb, (const Object *) this, area);
}

void Physics2DServer::area_add_shape(const RID area, const RID shape, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_add_shape");
	}
	___godot_icall_void_RID_RID_Transform2D(mb, (const Object *) this, area, shape, transform);
}

void Physics2DServer::area_set_shape(const RID area, const int64_t shape_idx, const RID shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_set_shape");
	}
	___godot_icall_void_RID_int_RID(mb, (const Object *) this, area, shape_idx, shape);
}

void Physics2DServer::area_set_shape_transform(const RID area, const int64_t shape_idx, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_set_shape_transform");
	}
	___godot_icall_void_RID_int_Transform2D(mb, (const Object *) this, area, shape_idx, transform);
}

void Physics2DServer::area_set_shape_disabled(const RID area, const int64_t shape_idx, const bool disable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_set_shape_disabled");
	}
	___godot_icall_void_RID_int_bool(mb, (const Object *) this, area, shape_idx, disable);
}

int64_t Physics2DServer::area_get_shape_count(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_get_shape_count");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, area);
}

RID Physics2DServer::area_get_shape(const RID area, const int64_t shape_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_get_shape");
	}
	return ___godot_icall_RID_RID_int(mb, (const Object *) this, area, shape_idx);
}

Transform2D Physics2DServer::area_get_shape_transform(const RID area, const int64_t shape_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_get_shape_transform");
	}
	return ___godot_icall_Transform2D_RID_int(mb, (const Object *) this, area, shape_idx);
}

void Physics2DServer::area_remove_shape(const RID area, const int64_t shape_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_remove_shape");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, area, shape_idx);
}

void Physics2DServer::area_clear_shapes(const RID area) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_clear_shapes");
	}
	___godot_icall_void_RID(mb, (const Object *) this, area);
}

void Physics2DServer::area_set_collision_layer(const RID area, const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_set_collision_layer");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, area, layer);
}

void Physics2DServer::area_set_collision_mask(const RID area, const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_set_collision_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, area, mask);
}

void Physics2DServer::area_set_param(const RID area, const int64_t param, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_set_param");
	}
	___godot_icall_void_RID_int_Variant(mb, (const Object *) this, area, param, value);
}

void Physics2DServer::area_set_transform(const RID area, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_set_transform");
	}
	___godot_icall_void_RID_Transform2D(mb, (const Object *) this, area, transform);
}

Variant Physics2DServer::area_get_param(const RID area, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_get_param");
	}
	return ___godot_icall_Variant_RID_int(mb, (const Object *) this, area, param);
}

Transform2D Physics2DServer::area_get_transform(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_get_transform");
	}
	return ___godot_icall_Transform2D_RID(mb, (const Object *) this, area);
}

void Physics2DServer::area_attach_object_instance_id(const RID area, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_attach_object_instance_id");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, area, id);
}

int64_t Physics2DServer::area_get_object_instance_id(const RID area) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_get_object_instance_id");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, area);
}

void Physics2DServer::area_set_monitor_callback(const RID area, const Object *receiver, const String method) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "area_set_monitor_callback");
	}
	___godot_icall_void_RID_Object_String(mb, (const Object *) this, area, receiver, method);
}

RID Physics2DServer::body_create() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_create");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

void Physics2DServer::body_set_space(const RID body, const RID space) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_space");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, body, space);
}

RID Physics2DServer::body_get_space(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_space");
	}
	return ___godot_icall_RID_RID(mb, (const Object *) this, body);
}

void Physics2DServer::body_set_mode(const RID body, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, mode);
}

Physics2DServer::BodyMode Physics2DServer::body_get_mode(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_mode");
	}
	return (Physics2DServer::BodyMode) ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void Physics2DServer::body_add_shape(const RID body, const RID shape, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_add_shape");
	}
	___godot_icall_void_RID_RID_Transform2D(mb, (const Object *) this, body, shape, transform);
}

void Physics2DServer::body_set_shape(const RID body, const int64_t shape_idx, const RID shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_shape");
	}
	___godot_icall_void_RID_int_RID(mb, (const Object *) this, body, shape_idx, shape);
}

void Physics2DServer::body_set_shape_transform(const RID body, const int64_t shape_idx, const Transform2D transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_shape_transform");
	}
	___godot_icall_void_RID_int_Transform2D(mb, (const Object *) this, body, shape_idx, transform);
}

void Physics2DServer::body_set_shape_metadata(const RID body, const int64_t shape_idx, const Variant metadata) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_shape_metadata");
	}
	___godot_icall_void_RID_int_Variant(mb, (const Object *) this, body, shape_idx, metadata);
}

int64_t Physics2DServer::body_get_shape_count(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_shape_count");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, body);
}

RID Physics2DServer::body_get_shape(const RID body, const int64_t shape_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_shape");
	}
	return ___godot_icall_RID_RID_int(mb, (const Object *) this, body, shape_idx);
}

Transform2D Physics2DServer::body_get_shape_transform(const RID body, const int64_t shape_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_shape_transform");
	}
	return ___godot_icall_Transform2D_RID_int(mb, (const Object *) this, body, shape_idx);
}

Variant Physics2DServer::body_get_shape_metadata(const RID body, const int64_t shape_idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_shape_metadata");
	}
	return ___godot_icall_Variant_RID_int(mb, (const Object *) this, body, shape_idx);
}

void Physics2DServer::body_remove_shape(const RID body, const int64_t shape_idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_remove_shape");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, shape_idx);
}

void Physics2DServer::body_clear_shapes(const RID body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_clear_shapes");
	}
	___godot_icall_void_RID(mb, (const Object *) this, body);
}

void Physics2DServer::body_set_shape_disabled(const RID body, const int64_t shape_idx, const bool disable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_shape_disabled");
	}
	___godot_icall_void_RID_int_bool(mb, (const Object *) this, body, shape_idx, disable);
}

void Physics2DServer::body_set_shape_as_one_way_collision(const RID body, const int64_t shape_idx, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_shape_as_one_way_collision");
	}
	___godot_icall_void_RID_int_bool(mb, (const Object *) this, body, shape_idx, enable);
}

void Physics2DServer::body_attach_object_instance_id(const RID body, const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_attach_object_instance_id");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, id);
}

int64_t Physics2DServer::body_get_object_instance_id(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_object_instance_id");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void Physics2DServer::body_set_continuous_collision_detection_mode(const RID body, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_continuous_collision_detection_mode");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, mode);
}

Physics2DServer::CCDMode Physics2DServer::body_get_continuous_collision_detection_mode(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_continuous_collision_detection_mode");
	}
	return (Physics2DServer::CCDMode) ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void Physics2DServer::body_set_collision_layer(const RID body, const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_collision_layer");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, layer);
}

int64_t Physics2DServer::body_get_collision_layer(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_collision_layer");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void Physics2DServer::body_set_collision_mask(const RID body, const int64_t mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_collision_mask");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, mask);
}

int64_t Physics2DServer::body_get_collision_mask(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_collision_mask");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void Physics2DServer::body_set_param(const RID body, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, body, param, value);
}

double Physics2DServer::body_get_param(const RID body, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_param");
	}
	return ___godot_icall_float_RID_int(mb, (const Object *) this, body, param);
}

void Physics2DServer::body_set_state(const RID body, const int64_t state, const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_state");
	}
	___godot_icall_void_RID_int_Variant(mb, (const Object *) this, body, state, value);
}

Variant Physics2DServer::body_get_state(const RID body, const int64_t state) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_state");
	}
	return ___godot_icall_Variant_RID_int(mb, (const Object *) this, body, state);
}

void Physics2DServer::body_apply_impulse(const RID body, const Vector2 position, const Vector2 impulse) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_apply_impulse");
	}
	___godot_icall_void_RID_Vector2_Vector2(mb, (const Object *) this, body, position, impulse);
}

void Physics2DServer::body_add_force(const RID body, const Vector2 offset, const Vector2 force) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_add_force");
	}
	___godot_icall_void_RID_Vector2_Vector2(mb, (const Object *) this, body, offset, force);
}

void Physics2DServer::body_set_axis_velocity(const RID body, const Vector2 axis_velocity) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_axis_velocity");
	}
	___godot_icall_void_RID_Vector2(mb, (const Object *) this, body, axis_velocity);
}

void Physics2DServer::body_add_collision_exception(const RID body, const RID excepted_body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_add_collision_exception");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, body, excepted_body);
}

void Physics2DServer::body_remove_collision_exception(const RID body, const RID excepted_body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_remove_collision_exception");
	}
	___godot_icall_void_RID_RID(mb, (const Object *) this, body, excepted_body);
}

void Physics2DServer::body_set_max_contacts_reported(const RID body, const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_max_contacts_reported");
	}
	___godot_icall_void_RID_int(mb, (const Object *) this, body, amount);
}

int64_t Physics2DServer::body_get_max_contacts_reported(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_max_contacts_reported");
	}
	return ___godot_icall_int_RID(mb, (const Object *) this, body);
}

void Physics2DServer::body_set_omit_force_integration(const RID body, const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_omit_force_integration");
	}
	___godot_icall_void_RID_bool(mb, (const Object *) this, body, enable);
}

bool Physics2DServer::body_is_omitting_force_integration(const RID body) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_is_omitting_force_integration");
	}
	return ___godot_icall_bool_RID(mb, (const Object *) this, body);
}

void Physics2DServer::body_set_force_integration_callback(const RID body, const Object *receiver, const String method, const Variant userdata) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_set_force_integration_callback");
	}
	___godot_icall_void_RID_Object_String_Variant(mb, (const Object *) this, body, receiver, method, userdata);
}

bool Physics2DServer::body_test_motion(const RID body, const Transform2D from, const Vector2 motion, const bool infinite_inertia, const double margin, const Ref<Physics2DTestMotionResult> result) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_test_motion");
	}
	return ___godot_icall_bool_RID_Transform2D_Vector2_bool_float_Object(mb, (const Object *) this, body, from, motion, infinite_inertia, margin, result.ptr());
}

Physics2DDirectBodyState *Physics2DServer::body_get_direct_state(const RID body) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "body_get_direct_state");
	}
	return (Physics2DDirectBodyState *) ___godot_icall_Object_RID(mb, (const Object *) this, body);
}

void Physics2DServer::joint_set_param(const RID joint, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "joint_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, joint, param, value);
}

double Physics2DServer::joint_get_param(const RID joint, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "joint_get_param");
	}
	return ___godot_icall_float_RID_int(mb, (const Object *) this, joint, param);
}

RID Physics2DServer::pin_joint_create(const Vector2 anchor, const RID body_a, const RID body_b) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "pin_joint_create");
	}
	return ___godot_icall_RID_Vector2_RID_RID(mb, (const Object *) this, anchor, body_a, body_b);
}

RID Physics2DServer::groove_joint_create(const Vector2 groove1_a, const Vector2 groove2_a, const Vector2 anchor_b, const RID body_a, const RID body_b) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "groove_joint_create");
	}
	return ___godot_icall_RID_Vector2_Vector2_Vector2_RID_RID(mb, (const Object *) this, groove1_a, groove2_a, anchor_b, body_a, body_b);
}

RID Physics2DServer::damped_spring_joint_create(const Vector2 anchor_a, const Vector2 anchor_b, const RID body_a, const RID body_b) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "damped_spring_joint_create");
	}
	return ___godot_icall_RID_Vector2_Vector2_RID_RID(mb, (const Object *) this, anchor_a, anchor_b, body_a, body_b);
}

void Physics2DServer::damped_string_joint_set_param(const RID joint, const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "damped_string_joint_set_param");
	}
	___godot_icall_void_RID_int_float(mb, (const Object *) this, joint, param, value);
}

double Physics2DServer::damped_string_joint_get_param(const RID joint, const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "damped_string_joint_get_param");
	}
	return ___godot_icall_float_RID_int(mb, (const Object *) this, joint, param);
}

Physics2DServer::JointType Physics2DServer::joint_get_type(const RID joint) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "joint_get_type");
	}
	return (Physics2DServer::JointType) ___godot_icall_int_RID(mb, (const Object *) this, joint);
}

void Physics2DServer::free_rid(const RID rid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "free_rid");
	}
	___godot_icall_void_RID(mb, (const Object *) this, rid);
}

void Physics2DServer::set_active(const bool active) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "set_active");
	}
	___godot_icall_void_bool(mb, (const Object *) this, active);
}

int64_t Physics2DServer::get_process_info(const int64_t process_info) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Physics2DServer", "get_process_info");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, process_info);
}

}