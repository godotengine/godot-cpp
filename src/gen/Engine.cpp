#include <Engine.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <MainLoop.hpp>
#include <Object.hpp>


namespace godot {


void *Engine::___get_type_tag()
{
	return (void *) &Engine::___get_type_tag;
}

void *Engine::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

Engine *Engine::_singleton = NULL;


Engine::Engine() {
	_owner = godot::api->godot_global_get_singleton((char *) "Engine");
}


void Engine::set_iterations_per_second(const int64_t iterations_per_second) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "set_iterations_per_second");
	}
	___godot_icall_void_int(mb, (const Object *) this, iterations_per_second);
}

int64_t Engine::get_iterations_per_second() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "get_iterations_per_second");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Engine::set_target_fps(const int64_t target_fps) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "set_target_fps");
	}
	___godot_icall_void_int(mb, (const Object *) this, target_fps);
}

int64_t Engine::get_target_fps() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "get_target_fps");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Engine::set_time_scale(const double time_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "set_time_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, time_scale);
}

double Engine::get_time_scale() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "get_time_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

int64_t Engine::get_frames_drawn() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "get_frames_drawn");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

double Engine::get_frames_per_second() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "get_frames_per_second");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

MainLoop *Engine::get_main_loop() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "get_main_loop");
	}
	return (MainLoop *) ___godot_icall_Object(mb, (const Object *) this);
}

Dictionary Engine::get_version_info() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "get_version_info");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

bool Engine::is_in_physics_frame() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "is_in_physics_frame");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool Engine::has_singleton(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "has_singleton");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

Object *Engine::get_singleton(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "get_singleton");
	}
	return (Object *) ___godot_icall_Object_String(mb, (const Object *) this, name);
}

void Engine::set_editor_hint(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "set_editor_hint");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Engine::is_editor_hint() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_Engine", "is_editor_hint");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}