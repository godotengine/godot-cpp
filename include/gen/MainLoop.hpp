#ifndef GODOT_CPP_MAINLOOP_HPP
#define GODOT_CPP_MAINLOOP_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {

class InputEvent;

class MainLoop : public Object {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "MainLoop"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants
	const static int NOTIFICATION_WM_MOUSE_ENTER = 2;
	const static int NOTIFICATION_WM_MOUSE_EXIT = 3;
	const static int NOTIFICATION_WM_FOCUS_OUT = 5;
	const static int NOTIFICATION_WM_FOCUS_IN = 4;
	const static int NOTIFICATION_WM_UNFOCUS_REQUEST = 8;
	const static int NOTIFICATION_WM_GO_BACK_REQUEST = 7;
	const static int NOTIFICATION_WM_ABOUT = 91;
	const static int NOTIFICATION_WM_QUIT_REQUEST = 6;
	const static int NOTIFICATION_TRANSLATION_CHANGED = 90;
	const static int NOTIFICATION_OS_MEMORY_WARNING = 9;


	static MainLoop *_new();

	// methods
	void _input_event(const Ref<InputEvent> ev);
	void _input_text(const String text);
	void _initialize();
	void _iteration(const double delta);
	void _idle(const double delta);
	void _drop_files(const PoolStringArray files, const int64_t screen);
	void _finalize();
	void input_event(const Ref<InputEvent> ev);
	void input_text(const String text);
	void init();
	bool iteration(const double delta);
	bool idle(const double delta);
	void finish();

};

}

#endif