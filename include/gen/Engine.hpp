#ifndef GODOT_CPP_ENGINE_HPP
#define GODOT_CPP_ENGINE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {

class MainLoop;
class Object;

class Engine : public Object {
	static Engine *_singleton;

	Engine();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline Engine *get_singleton()
	{
		if (!Engine::_singleton) {
			Engine::_singleton = new Engine;
		}
		return Engine::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "Engine"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void set_iterations_per_second(const int64_t iterations_per_second);
	int64_t get_iterations_per_second() const;
	void set_target_fps(const int64_t target_fps);
	int64_t get_target_fps() const;
	void set_time_scale(const double time_scale);
	double get_time_scale();
	int64_t get_frames_drawn();
	double get_frames_per_second() const;
	MainLoop *get_main_loop() const;
	Dictionary get_version_info() const;
	bool is_in_physics_frame() const;
	bool has_singleton(const String name) const;
	Object *get_singleton(const String name) const;
	void set_editor_hint(const bool enabled);
	bool is_editor_hint() const;

};

}

#endif