#include <MainLoop.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>


namespace godot {


void *MainLoop::___get_type_tag()
{
	return (void *) &MainLoop::___get_type_tag;
}

void *MainLoop::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

MainLoop *MainLoop::_new()
{
	return (MainLoop *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"MainLoop")());
}
void MainLoop::_input_event(const Ref<InputEvent> ev) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "_input_event");
	}
	___godot_icall_void_Object(mb, (const Object *) this, ev.ptr());
}

void MainLoop::_input_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "_input_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

void MainLoop::_initialize() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "_initialize");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void MainLoop::_iteration(const double delta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "_iteration");
	}
	___godot_icall_void_float(mb, (const Object *) this, delta);
}

void MainLoop::_idle(const double delta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "_idle");
	}
	___godot_icall_void_float(mb, (const Object *) this, delta);
}

void MainLoop::_drop_files(const PoolStringArray files, const int64_t screen) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "_drop_files");
	}
	___godot_icall_void_PoolStringArray_int(mb, (const Object *) this, files, screen);
}

void MainLoop::_finalize() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "_finalize");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void MainLoop::input_event(const Ref<InputEvent> ev) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "input_event");
	}
	___godot_icall_void_Object(mb, (const Object *) this, ev.ptr());
}

void MainLoop::input_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "input_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

void MainLoop::init() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "init");
	}
	___godot_icall_void(mb, (const Object *) this);
}

bool MainLoop::iteration(const double delta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "iteration");
	}
	return ___godot_icall_bool_float(mb, (const Object *) this, delta);
}

bool MainLoop::idle(const double delta) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "idle");
	}
	return ___godot_icall_bool_float(mb, (const Object *) this, delta);
}

void MainLoop::finish() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("MainLoop", "finish");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}