#ifndef GODOT_CPP_PHYSICSSERVER_HPP
#define GODOT_CPP_PHYSICSSERVER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "PhysicsServer.hpp"

#include "Object.hpp"
namespace godot {

class PhysicsDirectSpaceState;
class Object;
class PhysicsDirectBodyState;

class PhysicsServer : public Object {
	static PhysicsServer *_singleton;

	PhysicsServer();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline PhysicsServer *get_singleton()
	{
		if (!PhysicsServer::_singleton) {
			PhysicsServer::_singleton = new PhysicsServer;
		}
		return PhysicsServer::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "PhysicsServer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum BodyAxis {
		BODY_AXIS_LINEAR_Z = 4,
		BODY_AXIS_LINEAR_Y = 2,
		BODY_AXIS_LINEAR_X = 1,
		BODY_AXIS_ANGULAR_Y = 16,
		BODY_AXIS_ANGULAR_X = 8,
		BODY_AXIS_ANGULAR_Z = 32,
	};
	enum ProcessInfo {
		INFO_ACTIVE_OBJECTS = 0,
		INFO_ISLAND_COUNT = 2,
		INFO_COLLISION_PAIRS = 1,
	};
	enum AreaBodyStatus {
		AREA_BODY_ADDED = 0,
		AREA_BODY_REMOVED = 1,
	};
	enum BodyMode {
		BODY_MODE_SOFT = 3,
		BODY_MODE_CHARACTER = 4,
		BODY_MODE_STATIC = 0,
		BODY_MODE_RIGID = 2,
		BODY_MODE_KINEMATIC = 1,
	};
	enum ShapeType {
		SHAPE_CUSTOM = 8,
		SHAPE_SPHERE = 2,
		SHAPE_RAY = 1,
		SHAPE_BOX = 3,
		SHAPE_HEIGHTMAP = 7,
		SHAPE_CONCAVE_POLYGON = 6,
		SHAPE_CONVEX_POLYGON = 5,
		SHAPE_PLANE = 0,
		SHAPE_CAPSULE = 4,
	};
	enum PinJointParam {
		PIN_JOINT_DAMPING = 1,
		PIN_JOINT_IMPULSE_CLAMP = 2,
		PIN_JOINT_BIAS = 0,
	};
	enum SpaceParameter {
		SPACE_PARAM_BODY_TIME_TO_SLEEP = 5,
		SPACE_PARAM_BODY_MAX_ALLOWED_PENETRATION = 2,
		SPACE_PARAM_CONTACT_MAX_SEPARATION = 1,
		SPACE_PARAM_BODY_LINEAR_VELOCITY_SLEEP_THRESHOLD = 3,
		SPACE_PARAM_BODY_ANGULAR_VELOCITY_SLEEP_THRESHOLD = 4,
		SPACE_PARAM_BODY_ANGULAR_VELOCITY_DAMP_RATIO = 6,
		SPACE_PARAM_CONTACT_RECYCLE_RADIUS = 0,
		SPACE_PARAM_CONSTRAINT_DEFAULT_BIAS = 7,
	};
	enum ConeTwistJointParam {
		CONE_TWIST_JOINT_TWIST_SPAN = 1,
		CONE_TWIST_JOINT_BIAS = 2,
		CONE_TWIST_JOINT_RELAXATION = 4,
		CONE_TWIST_JOINT_SWING_SPAN = 0,
		CONE_TWIST_JOINT_SOFTNESS = 3,
	};
	enum JointType {
		JOINT_6DOF = 4,
		JOINT_PIN = 0,
		JOINT_HINGE = 1,
		JOINT_SLIDER = 2,
		JOINT_CONE_TWIST = 3,
	};
	enum BodyState {
		BODY_STATE_CAN_SLEEP = 4,
		BODY_STATE_SLEEPING = 3,
		BODY_STATE_LINEAR_VELOCITY = 1,
		BODY_STATE_ANGULAR_VELOCITY = 2,
		BODY_STATE_TRANSFORM = 0,
	};
	enum BodyParameter {
		BODY_PARAM_GRAVITY_SCALE = 3,
		BODY_PARAM_FRICTION = 1,
		BODY_PARAM_BOUNCE = 0,
		BODY_PARAM_ANGULAR_DAMP = 5,
		BODY_PARAM_MASS = 2,
		BODY_PARAM_LINEAR_DAMP = 4,
		BODY_PARAM_MAX = 6,
	};
	enum G6DOFJointAxisParam {
		G6DOF_JOINT_LINEAR_LIMIT_SOFTNESS = 2,
		G6DOF_JOINT_ANGULAR_RESTITUTION = 11,
		G6DOF_JOINT_LINEAR_MOTOR_FORCE_LIMIT = 6,
		G6DOF_JOINT_LINEAR_DAMPING = 4,
		G6DOF_JOINT_LINEAR_LOWER_LIMIT = 0,
		G6DOF_JOINT_LINEAR_RESTITUTION = 3,
		G6DOF_JOINT_ANGULAR_FORCE_LIMIT = 12,
		G6DOF_JOINT_ANGULAR_LOWER_LIMIT = 7,
		G6DOF_JOINT_ANGULAR_UPPER_LIMIT = 8,
		G6DOF_JOINT_ANGULAR_LIMIT_SOFTNESS = 9,
		G6DOF_JOINT_LINEAR_MOTOR_TARGET_VELOCITY = 5,
		G6DOF_JOINT_ANGULAR_MOTOR_TARGET_VELOCITY = 14,
		G6DOF_JOINT_ANGULAR_ERP = 13,
		G6DOF_JOINT_ANGULAR_DAMPING = 10,
		G6DOF_JOINT_LINEAR_UPPER_LIMIT = 1,
		G6DOF_JOINT_ANGULAR_MOTOR_FORCE_LIMIT = 15,
	};
	enum SliderJointParam {
		SLIDER_JOINT_LINEAR_MOTION_RESTITUTION = 6,
		SLIDER_JOINT_LINEAR_LIMIT_LOWER = 1,
		SLIDER_JOINT_LINEAR_ORTHOGONAL_DAMPING = 10,
		SLIDER_JOINT_LINEAR_MOTION_DAMPING = 7,
		SLIDER_JOINT_ANGULAR_LIMIT_SOFTNESS = 13,
		SLIDER_JOINT_MAX = 22,
		SLIDER_JOINT_LINEAR_LIMIT_DAMPING = 4,
		SLIDER_JOINT_LINEAR_LIMIT_UPPER = 0,
		SLIDER_JOINT_ANGULAR_MOTION_RESTITUTION = 17,
		SLIDER_JOINT_LINEAR_MOTION_SOFTNESS = 5,
		SLIDER_JOINT_ANGULAR_LIMIT_DAMPING = 15,
		SLIDER_JOINT_ANGULAR_ORTHOGONAL_RESTITUTION = 20,
		SLIDER_JOINT_ANGULAR_LIMIT_UPPER = 11,
		SLIDER_JOINT_ANGULAR_LIMIT_LOWER = 12,
		SLIDER_JOINT_ANGULAR_ORTHOGONAL_DAMPING = 21,
		SLIDER_JOINT_LINEAR_LIMIT_RESTITUTION = 3,
		SLIDER_JOINT_LINEAR_LIMIT_SOFTNESS = 2,
		SLIDER_JOINT_ANGULAR_LIMIT_RESTITUTION = 14,
		SLIDER_JOINT_LINEAR_ORTHOGONAL_RESTITUTION = 9,
		SLIDER_JOINT_ANGULAR_MOTION_DAMPING = 18,
		SLIDER_JOINT_ANGULAR_MOTION_SOFTNESS = 16,
		SLIDER_JOINT_LINEAR_ORTHOGONAL_SOFTNESS = 8,
		SLIDER_JOINT_ANGULAR_ORTHOGONAL_SOFTNESS = 19,
	};
	enum HingeJointParam {
		HINGE_JOINT_MOTOR_MAX_IMPULSE = 7,
		HINGE_JOINT_LIMIT_SOFTNESS = 4,
		HINGE_JOINT_MOTOR_TARGET_VELOCITY = 6,
		HINGE_JOINT_LIMIT_RELAXATION = 5,
		HINGE_JOINT_BIAS = 0,
		HINGE_JOINT_LIMIT_UPPER = 1,
		HINGE_JOINT_LIMIT_LOWER = 2,
		HINGE_JOINT_LIMIT_BIAS = 3,
	};
	enum G6DOFJointAxisFlag {
		G6DOF_JOINT_FLAG_ENABLE_ANGULAR_LIMIT = 1,
		G6DOF_JOINT_FLAG_ENABLE_MOTOR = 2,
		G6DOF_JOINT_FLAG_ENABLE_LINEAR_LIMIT = 0,
		G6DOF_JOINT_FLAG_ENABLE_LINEAR_MOTOR = 3,
	};
	enum HingeJointFlag {
		HINGE_JOINT_FLAG_ENABLE_MOTOR = 1,
		HINGE_JOINT_FLAG_USE_LIMIT = 0,
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
	RID shape_create(const int64_t type);
	void shape_set_data(const RID shape, const Variant data);
	PhysicsServer::ShapeType shape_get_type(const RID shape) const;
	Variant shape_get_data(const RID shape) const;
	RID space_create();
	void space_set_active(const RID space, const bool active);
	bool space_is_active(const RID space) const;
	void space_set_param(const RID space, const int64_t param, const double value);
	double space_get_param(const RID space, const int64_t param) const;
	PhysicsDirectSpaceState *space_get_direct_state(const RID space);
	RID area_create();
	void area_set_space(const RID area, const RID space);
	RID area_get_space(const RID area) const;
	void area_set_space_override_mode(const RID area, const int64_t mode);
	PhysicsServer::AreaSpaceOverrideMode area_get_space_override_mode(const RID area) const;
	void area_add_shape(const RID area, const RID shape, const Transform transform = Transform());
	void area_set_shape(const RID area, const int64_t shape_idx, const RID shape);
	void area_set_shape_transform(const RID area, const int64_t shape_idx, const Transform transform);
	int64_t area_get_shape_count(const RID area) const;
	RID area_get_shape(const RID area, const int64_t shape_idx) const;
	Transform area_get_shape_transform(const RID area, const int64_t shape_idx) const;
	void area_remove_shape(const RID area, const int64_t shape_idx);
	void area_clear_shapes(const RID area);
	void area_set_collision_layer(const RID area, const int64_t layer);
	void area_set_collision_mask(const RID area, const int64_t mask);
	void area_set_param(const RID area, const int64_t param, const Variant value);
	void area_set_transform(const RID area, const Transform transform);
	Variant area_get_param(const RID area, const int64_t param) const;
	Transform area_get_transform(const RID area) const;
	void area_attach_object_instance_id(const RID area, const int64_t id);
	int64_t area_get_object_instance_id(const RID area) const;
	void area_set_monitor_callback(const RID area, const Object *receiver, const String method);
	void area_set_ray_pickable(const RID area, const bool enable);
	bool area_is_ray_pickable(const RID area) const;
	RID body_create(const int64_t mode = 2, const bool init_sleeping = false);
	void body_set_space(const RID body, const RID space);
	RID body_get_space(const RID body) const;
	void body_set_mode(const RID body, const int64_t mode);
	PhysicsServer::BodyMode body_get_mode(const RID body) const;
	void body_set_collision_layer(const RID body, const int64_t layer);
	int64_t body_get_collision_layer(const RID body) const;
	void body_set_collision_mask(const RID body, const int64_t mask);
	int64_t body_get_collision_mask(const RID body) const;
	void body_add_shape(const RID body, const RID shape, const Transform transform = Transform());
	void body_set_shape(const RID body, const int64_t shape_idx, const RID shape);
	void body_set_shape_transform(const RID body, const int64_t shape_idx, const Transform transform);
	int64_t body_get_shape_count(const RID body) const;
	RID body_get_shape(const RID body, const int64_t shape_idx) const;
	Transform body_get_shape_transform(const RID body, const int64_t shape_idx) const;
	void body_remove_shape(const RID body, const int64_t shape_idx);
	void body_clear_shapes(const RID body);
	void body_attach_object_instance_id(const RID body, const int64_t id);
	int64_t body_get_object_instance_id(const RID body) const;
	void body_set_enable_continuous_collision_detection(const RID body, const bool enable);
	bool body_is_continuous_collision_detection_enabled(const RID body) const;
	void body_set_param(const RID body, const int64_t param, const double value);
	double body_get_param(const RID body, const int64_t param) const;
	void body_set_kinematic_safe_margin(const RID body, const double margin);
	double body_get_kinematic_safe_margin(const RID body) const;
	void body_set_state(const RID body, const int64_t state, const Variant value);
	Variant body_get_state(const RID body, const int64_t state) const;
	void body_apply_impulse(const RID body, const Vector3 position, const Vector3 impulse);
	void body_apply_torque_impulse(const RID body, const Vector3 impulse);
	void body_set_axis_velocity(const RID body, const Vector3 axis_velocity);
	void body_set_axis_lock(const RID body, const int64_t axis, const bool lock);
	bool body_is_axis_locked(const RID body, const int64_t axis) const;
	void body_add_collision_exception(const RID body, const RID excepted_body);
	void body_remove_collision_exception(const RID body, const RID excepted_body);
	void body_set_max_contacts_reported(const RID body, const int64_t amount);
	int64_t body_get_max_contacts_reported(const RID body) const;
	void body_set_omit_force_integration(const RID body, const bool enable);
	bool body_is_omitting_force_integration(const RID body) const;
	void body_set_force_integration_callback(const RID body, const Object *receiver, const String method, const Variant userdata = Variant());
	void body_set_ray_pickable(const RID body, const bool enable);
	bool body_is_ray_pickable(const RID body) const;
	PhysicsDirectBodyState *body_get_direct_state(const RID body);
	RID joint_create_pin(const RID body_A, const Vector3 local_A, const RID body_B, const Vector3 local_B);
	void pin_joint_set_param(const RID joint, const int64_t param, const double value);
	double pin_joint_get_param(const RID joint, const int64_t param) const;
	void pin_joint_set_local_a(const RID joint, const Vector3 local_A);
	Vector3 pin_joint_get_local_a(const RID joint) const;
	void pin_joint_set_local_b(const RID joint, const Vector3 local_B);
	Vector3 pin_joint_get_local_b(const RID joint) const;
	RID joint_create_hinge(const RID body_A, const Transform hinge_A, const RID body_B, const Transform hinge_B);
	void hinge_joint_set_param(const RID joint, const int64_t param, const double value);
	double hinge_joint_get_param(const RID joint, const int64_t param) const;
	void hinge_joint_set_flag(const RID joint, const int64_t flag, const bool enabled);
	bool hinge_joint_get_flag(const RID joint, const int64_t flag) const;
	RID joint_create_slider(const RID body_A, const Transform local_ref_A, const RID body_B, const Transform local_ref_B);
	void slider_joint_set_param(const RID joint, const int64_t param, const double value);
	double slider_joint_get_param(const RID joint, const int64_t param) const;
	RID joint_create_cone_twist(const RID body_A, const Transform local_ref_A, const RID body_B, const Transform local_ref_B);
	void cone_twist_joint_set_param(const RID joint, const int64_t param, const double value);
	double cone_twist_joint_get_param(const RID joint, const int64_t param) const;
	PhysicsServer::JointType joint_get_type(const RID joint) const;
	void joint_set_solver_priority(const RID joint, const int64_t priority);
	int64_t joint_get_solver_priority(const RID joint) const;
	RID joint_create_generic_6dof(const RID body_A, const Transform local_ref_A, const RID body_B, const Transform local_ref_B);
	void generic_6dof_joint_set_param(const RID joint, const int64_t axis, const int64_t param, const double value);
	double generic_6dof_joint_get_param(const RID joint, const int64_t axis, const int64_t param);
	void generic_6dof_joint_set_flag(const RID joint, const int64_t axis, const int64_t flag, const bool enable);
	bool generic_6dof_joint_get_flag(const RID joint, const int64_t axis, const int64_t flag);
	void free_rid(const RID rid);
	void set_active(const bool active);
	int64_t get_process_info(const int64_t process_info);

};

}

#endif