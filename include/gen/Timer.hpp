#ifndef GODOT_CPP_TIMER_HPP
#define GODOT_CPP_TIMER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Timer.hpp"

#include "Node.hpp"
namespace godot {


class Timer : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Timer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum TimerProcessMode {
		TIMER_PROCESS_IDLE = 1,
		TIMER_PROCESS_PHYSICS = 0,
	};

	// constants


	static Timer *_new();

	// methods
	void set_wait_time(const double time_sec);
	double get_wait_time() const;
	void set_one_shot(const bool enable);
	bool is_one_shot() const;
	void set_autostart(const bool enable);
	bool has_autostart() const;
	void start(const double time_sec = -1);
	void stop();
	void set_paused(const bool paused);
	bool is_paused() const;
	bool is_stopped() const;
	double get_time_left() const;
	void set_timer_process_mode(const int64_t mode);
	Timer::TimerProcessMode get_timer_process_mode() const;

};

}

#endif