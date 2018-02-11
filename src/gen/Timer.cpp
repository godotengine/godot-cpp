#include <Timer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Timer::___get_type_tag()
{
	return (void *) &Timer::___get_type_tag;
}

void *Timer::___get_base_type_tag()
{
	return (void *) &Node::___get_type_tag;
}

Timer *Timer::_new()
{
	return (Timer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Timer")());
}
void Timer::set_wait_time(const double time_sec) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "set_wait_time");
	}
	___godot_icall_void_float(mb, (const Object *) this, time_sec);
}

double Timer::get_wait_time() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "get_wait_time");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Timer::set_one_shot(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "set_one_shot");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Timer::is_one_shot() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "is_one_shot");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Timer::set_autostart(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "set_autostart");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Timer::has_autostart() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "has_autostart");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Timer::start() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "start");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Timer::stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Timer::set_paused(const bool paused) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "set_paused");
	}
	___godot_icall_void_bool(mb, (const Object *) this, paused);
}

bool Timer::is_paused() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "is_paused");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Timer::is_stopped() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "is_stopped");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

double Timer::get_time_left() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "get_time_left");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Timer::set_timer_process_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "set_timer_process_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Timer::TimerProcessMode Timer::get_timer_process_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Timer", "get_timer_process_mode");
	}
	return (Timer::TimerProcessMode) ___godot_icall_int(mb, (const Object *) this);
}

}