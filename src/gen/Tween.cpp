#include <Tween.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *Tween::___get_type_tag()
{
	return (void *) &Tween::___get_type_tag;
}

void *Tween::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

Tween *Tween::_new()
{
	return (Tween *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Tween")());
}
bool Tween::is_active() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "is_active");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Tween::set_active(const bool active) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "set_active");
	}
	___godot_icall_void_bool(mb, (const Object *) this, active);
}

bool Tween::is_repeat() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "is_repeat");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Tween::set_repeat(const bool repeat) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "set_repeat");
	}
	___godot_icall_void_bool(mb, (const Object *) this, repeat);
}

void Tween::set_speed_scale(const double speed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "set_speed_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, speed);
}

double Tween::get_speed_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "get_speed_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Tween::set_tween_process_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "set_tween_process_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Tween::TweenProcessMode Tween::get_tween_process_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "get_tween_process_mode");
	}
	return (Tween::TweenProcessMode) ___godot_icall_int(mb, (const Object *) this);
}

bool Tween::start() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "start");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Tween::reset(const Object *object, const String key) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "reset");
	}
	return ___godot_icall_bool_Object_String(mb, (const Object *) this, object, key);
}

bool Tween::reset_all() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "reset_all");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Tween::stop(const Object *object, const String key) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "stop");
	}
	return ___godot_icall_bool_Object_String(mb, (const Object *) this, object, key);
}

bool Tween::stop_all() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "stop_all");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Tween::resume(const Object *object, const String key) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "resume");
	}
	return ___godot_icall_bool_Object_String(mb, (const Object *) this, object, key);
}

bool Tween::resume_all() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "resume_all");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Tween::remove(const Object *object, const String key) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "remove");
	}
	return ___godot_icall_bool_Object_String(mb, (const Object *) this, object, key);
}

void Tween::_remove(const Object *object, const String key, const bool first_only) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "_remove");
	}
	___godot_icall_void_Object_String_bool(mb, (const Object *) this, object, key, first_only);
}

bool Tween::remove_all() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "remove_all");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Tween::seek(const double time) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "seek");
	}
	return ___godot_icall_bool_float(mb, (const Object *) this, time);
}

double Tween::tell() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "tell");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Tween::get_runtime() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "get_runtime");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

bool Tween::interpolate_property(const Object *object, const NodePath property, const Variant initial_val, const Variant final_val, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "interpolate_property");
	}
	return ___godot_icall_bool_Object_NodePath_Variant_Variant_float_int_int_float(mb, (const Object *) this, object, property, initial_val, final_val, duration, trans_type, ease_type, delay);
}

bool Tween::interpolate_method(const Object *object, const String method, const Variant initial_val, const Variant final_val, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "interpolate_method");
	}
	return ___godot_icall_bool_Object_String_Variant_Variant_float_int_int_float(mb, (const Object *) this, object, method, initial_val, final_val, duration, trans_type, ease_type, delay);
}

bool Tween::interpolate_callback(const Object *object, const double duration, const String callback, const Variant arg1, const Variant arg2, const Variant arg3, const Variant arg4, const Variant arg5) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "interpolate_callback");
	}
	return ___godot_icall_bool_Object_float_String_Variant_Variant_Variant_Variant_Variant(mb, (const Object *) this, object, duration, callback, arg1, arg2, arg3, arg4, arg5);
}

bool Tween::interpolate_deferred_callback(const Object *object, const double duration, const String callback, const Variant arg1, const Variant arg2, const Variant arg3, const Variant arg4, const Variant arg5) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "interpolate_deferred_callback");
	}
	return ___godot_icall_bool_Object_float_String_Variant_Variant_Variant_Variant_Variant(mb, (const Object *) this, object, duration, callback, arg1, arg2, arg3, arg4, arg5);
}

bool Tween::follow_property(const Object *object, const NodePath property, const Variant initial_val, const Object *target, const NodePath target_property, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "follow_property");
	}
	return ___godot_icall_bool_Object_NodePath_Variant_Object_NodePath_float_int_int_float(mb, (const Object *) this, object, property, initial_val, target, target_property, duration, trans_type, ease_type, delay);
}

bool Tween::follow_method(const Object *object, const String method, const Variant initial_val, const Object *target, const String target_method, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "follow_method");
	}
	return ___godot_icall_bool_Object_String_Variant_Object_String_float_int_int_float(mb, (const Object *) this, object, method, initial_val, target, target_method, duration, trans_type, ease_type, delay);
}

bool Tween::targeting_property(const Object *object, const NodePath property, const Object *initial, const NodePath initial_val, const Variant final_val, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "targeting_property");
	}
	return ___godot_icall_bool_Object_NodePath_Object_NodePath_Variant_float_int_int_float(mb, (const Object *) this, object, property, initial, initial_val, final_val, duration, trans_type, ease_type, delay);
}

bool Tween::targeting_method(const Object *object, const String method, const Object *initial, const String initial_method, const Variant final_val, const double duration, const int64_t trans_type, const int64_t ease_type, const double delay) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Tween", "targeting_method");
	}
	return ___godot_icall_bool_Object_String_Object_String_Variant_float_int_int_float(mb, (const Object *) this, object, method, initial, initial_method, final_val, duration, trans_type, ease_type, delay);
}

}