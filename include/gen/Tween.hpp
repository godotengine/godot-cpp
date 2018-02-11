#ifndef GODOT_CPP_TWEEN_HPP
#define GODOT_CPP_TWEEN_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Tween.hpp>

#include <Node.hpp>
namespace godot {

class Object;

class Tween : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Tween"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum TransitionType {
		TRANS_BOUNCE = 9,
		TRANS_EXPO = 5,
		TRANS_SINE = 1,
		TRANS_CUBIC = 7,
		TRANS_QUAD = 4,
		TRANS_ELASTIC = 6,
		TRANS_BACK = 10,
		TRANS_CIRC = 8,
		TRANS_QUINT = 2,
		TRANS_LINEAR = 0,
		TRANS_QUART = 3,
	};
	enum TweenProcessMode {
		TWEEN_PROCESS_PHYSICS = 0,
		TWEEN_PROCESS_IDLE = 1,
	};
	enum EaseType {
		EASE_OUT = 1,
		EASE_IN_OUT = 2,
		EASE_IN = 0,
		EASE_OUT_IN = 3,
	};

	// constants


	static Tween *_new();

	// methods
	bool is_active() const;
	void set_active(const bool active);
	bool is_repeat() const;
	void set_repeat(const bool repeat);
	void set_speed_scale(const double speed);
	double get_speed_scale() const;
	void set_tween_process_mode(const int64_t mode);
	Tween::TweenProcessMode get_tween_process_mode() const;
	bool start();
	bool reset(const Object *object, const String key = "");
	bool reset_all();
	bool stop(const Object *object, const String key = "");
	bool stop_all();
	bool resume(const Object *object, const String key = "");
	bool resume_all();
	bool remove(const Object *object, const String key = "");
	void _remove(const Object *object, const String key, const bool first_only);
	bool remove_all();
	bool seek(const double time);
	double tell() const;
	double get_runtime() const;
	bool interpolate_property(const Object *object, const NodePath property, const Variant initial_val, const Variant final_val, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay = 0);
	bool interpolate_method(const Object *object, const String method, const Variant initial_val, const Variant final_val, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay = 0);
	bool interpolate_callback(const Object *object, const double duration, const String callback, const Variant arg1 = Variant(), const Variant arg2 = Variant(), const Variant arg3 = Variant(), const Variant arg4 = Variant(), const Variant arg5 = Variant());
	bool interpolate_deferred_callback(const Object *object, const double duration, const String callback, const Variant arg1 = Variant(), const Variant arg2 = Variant(), const Variant arg3 = Variant(), const Variant arg4 = Variant(), const Variant arg5 = Variant());
	bool follow_property(const Object *object, const NodePath property, const Variant initial_val, const Object *target, const NodePath target_property, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay = 0);
	bool follow_method(const Object *object, const String method, const Variant initial_val, const Object *target, const String target_method, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay = 0);
	bool targeting_property(const Object *object, const NodePath property, const Object *initial, const NodePath initial_val, const Variant final_val, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay = 0);
	bool targeting_method(const Object *object, const String method, const Object *initial, const String initial_method, const Variant final_val, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay = 0);

};

}

#endif