#ifndef GODOT_CPP_PHYSICS2DSERVER_HPP
#define GODOT_CPP_PHYSICS2DSERVER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Physics2DServer.hpp>

#include <Object.hpp>
namespace godot {

class Physics2DDirectSpaceState;
class Object;
class Physics2DTestMotionResult;
class Physics2DDirectBodyState;

class Physics2DServer : public Object {
	static Physics2DServer *_singleton;

	Physics2DServer();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline Physics2DServer *get_singleton()
	{
		if (!Physics2DServer::_singleton) {
			Physics2DServer::_singleton = new Physics2DServer;
		}
		return Physics2DServer::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "Physics2DServer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum ProcessInfo {
		INFO_ACTIVE_OBJECTS = 0,
		INFO_ISLAND_COUNT = 2,
		INFO_COLLISION_PAIRS = 1,
	};
	enum AreaBodyStatus {
		AREA_BODY_ADDED = 0,
		AREA_BODY_REMOVED = 1,
	};
	enum DampedStringParam {
		DAMPED_STRING_REST_LENGTH = 0,
		DAMPED_STRING_STIFFNESS = 1,
		DAMPED_STRING_DAMPING = 2,
	};
	enum BodyMode {
		BODY_MODE_CHARACTER = 3,
		BODY_MODE_STATIC = 0,
		BODY_MODE_RIGID = 2,
		BODY_MODE_KINEMATIC = 1,
	};
	enum ShapeType {
		SHAPE_SEGMENT = 2,
		SHAPE_RECTANGLE = 4,
		SHAPE_LINE = 0,
		SHAPE_CIRCLE = 3,
		SHAPE_RAY = 1,
		SHAPE_CONCAVE_POLYGON = 7,
		SHAPE_CONVEX_POLYGON = 6,
		SHAPE_CUSTOM = 8,
		SHAPE_CAPSULE = 5,
	};
	enum JointParam {
		JOINT_PARAM_MAX_FORCE = 2,
		JOINT_PARAM_BIAS = 0,
		JOINT_PARAM_MAX_BIAS = 1,
	};
	enum SpaceParameter {
		SPACE_PARAM_BODY_TIME_TO_SLEEP = 5,
		SPACE_PARAM_BODY_MAX_ALLOWED_PENETRATION = 2,
		SPACE_PARAM_CONTACT_MAX_SEPARATION = 1,
		SPACE_PARAM_BODY_LINEAR_VELOCITY_SLEEP_THRESHOLD = 3,
		SPACE_PARAM_BODY_ANGULAR_VELOCITY_SLEEP_THRESHOLD = 4,
		SPACE_PARAM_CONTACT_RECYCLE_RADIUS = 0,
		SPACE_PARAM_CONSTRAINT_DEFAULT_BIAS = 6,
	};
	enum JointType {
		JOINT_PIN = 0,
		JOINT_DAMPED_SPRING = 2,
		JOINT_GROOVE = 1,
	};
	enum CCDMode {
		CCD_MODE_DISABLED = 0,
		CCD_MODE_CAST_SHAPE = 2,
		CCD_MODE_CAST_RAY = 1,
	};
	enum BodyState {
		BODY_STATE_CAN_SLEEP = 4,
		BODY_STATE_SLEEPING = 3,
		BODY_STATE_LINEAR_VELOCITY = 1,
		BODY_STATE_ANGULAR_VELOCITY = 2,
		BODY_STATE_TRANSFORM = 0,
	};
	enum BodyParameter {
		BODY_PARAM_GRAVITY_SCALE = 4,
		BODY_PARAM_INERTIA = 3,
		BODY_PARAM_FRICTION = 1,
		BODY_PARAM_BOUNCE = 0,
		BODY_PARAM_ANGULAR_DAMP = 6,
		BODY_PARAM_MASS = 2,
		BODY_PARAM_LINEAR_DAMP = 5,
		BODY_PARAM_MAX = 7,
	};
	enum AreaSpaceOverrideMode {
		AREA_SPACE_OVERRIDE_REPLACE = 3,
		AREA_SPACE_OVERRIDE_DISABLED = 0,
		AREA_SPACE_OVERRIDE_COMBINE_REPLACE = 2,
		AREA_SPACE_OVERRIDE_COMBINE = 1,
		AREA_SPACE_OVERRIDE_REPLACE_COMBINE = 4,
	};
	enum AreaParameter {
		AREA_PARAM_ANGULAR_DAMP = 6,
		AREA_PARAM_GRAVITY_DISTANCE_SCALE = 3,
		AREA_PARAM_LINEAR_DAMP = 5,
		AREA_PARAM_GRAVITY_POINT_ATTENUATION = 4,
		AREA_PARAM_GRAVITY_IS_POINT = 2,
		AREA_PARAM_GRAVITY = 0,
		AREA_PARAM_GRAVITY_VECTOR = 1,
		AREA_PARAM_PRIORITY = 7,
	};

	// constants

	// methods
	RID line_shape_create();
	RID ray_shape_create();
	RID segment_shape_create();
	RID circle_shape_create();
	RID rectangle_shape_create();
	RID capsule_shape_create();
	RID convex_polygon_shape_create();
	RID concave_polygon_shape_create();
	void shape_set_data(const RID shape, const Variant data);
	Physics2DServer::ShapeType shape_get_type(const RID shape) const;
	Variant shape_get_data(const RID shape) const;
	RID space_create();
	void space_set_active(const RID space, const bool active);
	bool space_is_active(const RID space) const;
	void space_set_param(const RID space, const int64_t param, const double value);
	double space_get_param(const RID space, const int64_t param) const;
	Physics2DDirectSpaceState *space_get_direct_state(const RID space);
	RID area_create();
	void area_set_space(const RID area, const RID space);
	RID area_get_space(const RID area) const;
	void area_set_space_override_mode(const RID area, const int64_t mode);
	Physics2DServer::AreaSpaceOverrideMode area_get_space_override_mode(const RID area) const;
	void area_add_shape(const RID area, const RID shape, const Transform2D transform = Transform2D());
	void area_set_shape(const RID area, const int64_t shape_idx, const RID shape);
	void area_set_shape_transform(const RID area, const int64_t shape_idx, const Transform2D transform);
	void area_set_shape_disabled(const RID area, const int64_t shape_idx, const bool disable);
	int64_t area_get_shape_count(const RID area) const;
	RID area_get_shape(const RID area, const int64_t shape_idx) const;
	Transform2D area_get_shape_transform(const RID area, const int64_t shape_idx) const;
	void area_remove_shape(const RID area, const int64_t shape_idx);
	void area_clear_shapes(const RID area);
	void area_set_collision_layer(const RID area, const int64_t layer);
	void area_set_collision_mask(const RID area, const int64_t mask);
	void area_set_param(const RID area, const int64_t param, const Variant value);
	void area_set_transform(const RID area, const Transform2D transform);
	Variant area_get_param(const RID area, const int64_t param) const;
	Transform2D area_get_transform(const RID area) const;
	void area_attach_object_instance_id(const RID area, const int64_t id);
	int64_t area_get_object_instance_id(const RID area) const;
	void area_set_monitor_callback(const RID area, const Object *receiver, const String method);
	RID body_create();
	void body_set_space(const RID body, const RID space);
	RID body_get_space(const RID body) const;
	void body_set_mode(const RID body, const int64_t mode);
	Physics2DServer::BodyMode body_get_mode(const RID body) const;
	void body_add_shape(const RID body, const RID shape, const Transform2D transform = Transform2D());
	void body_set_shape(const RID body, const int64_t shape_idx, const RID shape);
	void body_set_shape_transform(const RID body, const int64_t shape_idx, const Transform2D transform);
	void body_set_shape_metadata(const RID body, const int64_t shape_idx, const Variant metadata);
	int64_t body_get_shape_count(const RID body) const;
	RID body_get_shape(const RID body, const int64_t shape_idx) const;
	Transform2D body_get_shape_transform(const RID body, const int64_t shape_idx) const;
	Variant body_get_shape_metadata(const RID body, const int64_t shape_idx) const;
	void body_remove_shape(const RID body, const int64_t shape_idx);
	void body_clear_shapes(const RID body);
	void body_set_shape_disabled(const RID body, const int64_t shape_idx, const bool disable);
	void body_set_shape_as_one_way_collision(const RID body, const int64_t shape_idx, const bool enable);
	void body_attach_object_instance_id(const RID body, const int64_t id);
	int64_t body_get_object_instance_id(const RID body) const;
	void body_set_continuous_collision_detection_mode(const RID body, const int64_t mode);
	Physics2DServer::CCDMode body_get_continuous_collision_detection_mode(const RID body) const;
	void body_set_collision_layer(const RID body, const int64_t layer);
	int64_t body_get_collision_layer(const RID body) const;
	void body_set_collision_mask(const RID body, const int64_t mask);
	int64_t body_get_collision_mask(const RID body) const;
	void body_set_param(const RID body, const int64_t param, const double value);
	double body_get_param(const RID body, const int64_t param) const;
	void body_set_state(const RID body, const int64_t state, const Variant value);
	Variant body_get_state(const RID body, const int64_t state) const;
	void body_apply_impulse(const RID body, const Vector2 position, const Vector2 impulse);
	void body_add_force(const RID body, const Vector2 offset, const Vector2 force);
	void body_set_axis_velocity(const RID body, const Vector2 axis_velocity);
	void body_add_collision_exception(const RID body, const RID excepted_body);
	void body_remove_collision_exception(const RID body, const RID excepted_body);
	void body_set_max_contacts_reported(const RID body, const int64_t amount);
	int64_t body_get_max_contacts_reported(const RID body) const;
	void body_set_omit_force_integration(const RID body, const bool enable);
	bool body_is_omitting_force_integration(const RID body) const;
	void body_set_force_integration_callback(const RID body, const Object *receiver, const String method, const Variant userdata = Variant());
	bool body_test_motion(const RID body, const Transform2D from, const Vector2 motion, const bool infinite_inertia, const double margin = 0.08, const Ref<Physics2DTestMotionResult> result = nullptr);
	Physics2DDirectBodyState *body_get_direct_state(const RID body);
	void joint_set_param(const RID joint, const int64_t param, const double value);
	double joint_get_param(const RID joint, const int64_t param) const;
	RID pin_joint_create(const Vector2 anchor, const RID body_a, const RID body_b = RID());
	RID groove_joint_create(const Vector2 groove1_a, const Vector2 groove2_a, const Vector2 anchor_b, const RID body_a = RID(), const RID body_b = RID());
	RID damped_spring_joint_create(const Vector2 anchor_a, const Vector2 anchor_b, const RID body_a, const RID body_b = RID());
	void damped_string_joint_set_param(const RID joint, const int64_t param, const double value);
	double damped_string_joint_get_param(const RID joint, const int64_t param) const;
	Physics2DServer::JointType joint_get_type(const RID joint) const;
	void free_rid(const RID rid);
	void set_active(const bool active);
	int64_t get_process_info(const int64_t process_info);

};

}

#endif