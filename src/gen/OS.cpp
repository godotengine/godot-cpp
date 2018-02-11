#include <OS.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Image.hpp>


namespace godot {


void *OS::___get_type_tag()
{
	return (void *) &OS::___get_type_tag;
}

void *OS::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

OS *OS::_singleton = NULL;


OS::OS() {
	_owner = godot::api->godot_global_get_singleton((char *) "OS");
}


void OS::set_clipboard(const String clipboard) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_clipboard");
	}
	___godot_icall_void_String(mb, (const Object *) this, clipboard);
}

String OS::get_clipboard() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_clipboard");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t OS::get_video_driver_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_video_driver_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String OS::get_video_driver_name(const int64_t arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_video_driver_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, arg0);
}

int64_t OS::get_audio_driver_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_audio_driver_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String OS::get_audio_driver_name(const int64_t arg0) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_audio_driver_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, arg0);
}

int64_t OS::get_screen_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_screen_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t OS::get_current_screen() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_current_screen");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void OS::set_current_screen(const int64_t screen) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_current_screen");
	}
	___godot_icall_void_int(mb, (const Object *) this, screen);
}

Vector2 OS::get_screen_position(const int64_t screen) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_screen_position");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, screen);
}

Vector2 OS::get_screen_size(const int64_t screen) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_screen_size");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, screen);
}

int64_t OS::get_screen_dpi(const int64_t screen) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_screen_dpi");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, screen);
}

Vector2 OS::get_window_position() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_window_position");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void OS::set_window_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_window_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

Vector2 OS::get_window_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_window_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void OS::set_window_size(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_window_size");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

void OS::set_window_fullscreen(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_window_fullscreen");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool OS::is_window_fullscreen() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_window_fullscreen");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::set_window_resizable(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_window_resizable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool OS::is_window_resizable() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_window_resizable");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::set_window_minimized(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_window_minimized");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool OS::is_window_minimized() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_window_minimized");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::set_window_maximized(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_window_maximized");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool OS::is_window_maximized() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_window_maximized");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::set_window_always_on_top(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_window_always_on_top");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool OS::is_window_always_on_top() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_window_always_on_top");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::request_attention() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "request_attention");
	}
	___godot_icall_void(mb, (const Object *) this);
}

Vector2 OS::get_real_window_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_real_window_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void OS::center_window() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "center_window");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void OS::set_borderless_window(const bool borderless) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_borderless_window");
	}
	___godot_icall_void_bool(mb, (const Object *) this, borderless);
}

bool OS::get_borderless_window() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_borderless_window");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::set_ime_position(const Vector2 position) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_ime_position");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, position);
}

void OS::set_screen_orientation(const int64_t orientation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_screen_orientation");
	}
	___godot_icall_void_int(mb, (const Object *) this, orientation);
}

OS::ScreenOrientation OS::get_screen_orientation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_screen_orientation");
	}
	return (OS::ScreenOrientation) ___godot_icall_int(mb, (const Object *) this);
}

void OS::set_keep_screen_on(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_keep_screen_on");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool OS::is_keep_screen_on() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_keep_screen_on");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool OS::has_touchscreen_ui_hint() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "has_touchscreen_ui_hint");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::set_window_title(const String title) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_window_title");
	}
	___godot_icall_void_String(mb, (const Object *) this, title);
}

void OS::set_low_processor_usage_mode(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_low_processor_usage_mode");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool OS::is_in_low_processor_usage_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_in_low_processor_usage_mode");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t OS::get_processor_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_processor_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String OS::get_executable_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_executable_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

int64_t OS::execute(const String path, const PoolStringArray arguments, const bool blocking, const Array output) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "execute");
	}
	return ___godot_icall_int_String_PoolStringArray_bool_Array(mb, (const Object *) this, path, arguments, blocking, output);
}

Error OS::kill(const int64_t pid) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "kill");
	}
	return (Error) ___godot_icall_int_int(mb, (const Object *) this, pid);
}

Error OS::shell_open(const String uri) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "shell_open");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, uri);
}

int64_t OS::get_process_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_process_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String OS::get_environment(const String environment) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_environment");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, environment);
}

bool OS::has_environment(const String environment) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "has_environment");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, environment);
}

String OS::get_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

PoolStringArray OS::get_cmdline_args() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_cmdline_args");
	}
	return ___godot_icall_PoolStringArray(mb, (const Object *) this);
}

Dictionary OS::get_datetime(const bool utc) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_datetime");
	}
	return ___godot_icall_Dictionary_bool(mb, (const Object *) this, utc);
}

Dictionary OS::get_date(const bool utc) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_date");
	}
	return ___godot_icall_Dictionary_bool(mb, (const Object *) this, utc);
}

Dictionary OS::get_time(const bool utc) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_time");
	}
	return ___godot_icall_Dictionary_bool(mb, (const Object *) this, utc);
}

Dictionary OS::get_time_zone_info() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_time_zone_info");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

int64_t OS::get_unix_time() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_unix_time");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Dictionary OS::get_datetime_from_unix_time(const int64_t unix_time_val) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_datetime_from_unix_time");
	}
	return ___godot_icall_Dictionary_int(mb, (const Object *) this, unix_time_val);
}

int64_t OS::get_unix_time_from_datetime(const Dictionary datetime) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_unix_time_from_datetime");
	}
	return ___godot_icall_int_Dictionary(mb, (const Object *) this, datetime);
}

int64_t OS::get_system_time_secs() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_system_time_secs");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void OS::set_icon(const Ref<Image> icon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_icon");
	}
	___godot_icall_void_Object(mb, (const Object *) this, icon.ptr());
}

int64_t OS::get_exit_code() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_exit_code");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void OS::set_exit_code(const int64_t code) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_exit_code");
	}
	___godot_icall_void_int(mb, (const Object *) this, code);
}

void OS::delay_usec(const int64_t usec) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "delay_usec");
	}
	___godot_icall_void_int(mb, (const Object *) this, usec);
}

void OS::delay_msec(const int64_t msec) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "delay_msec");
	}
	___godot_icall_void_int(mb, (const Object *) this, msec);
}

int64_t OS::get_ticks_msec() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_ticks_msec");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t OS::get_splash_tick_msec() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_splash_tick_msec");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String OS::get_locale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_locale");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String OS::get_latin_keyboard_variant() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_latin_keyboard_variant");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String OS::get_model_name() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_model_name");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool OS::can_draw() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "can_draw");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool OS::is_userfs_persistent() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_userfs_persistent");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool OS::is_stdout_verbose() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_stdout_verbose");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool OS::can_use_threads() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "can_use_threads");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool OS::is_debug_build() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_debug_build");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::dump_memory_to_file(const String file) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "dump_memory_to_file");
	}
	___godot_icall_void_String(mb, (const Object *) this, file);
}

void OS::dump_resources_to_file(const String file) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "dump_resources_to_file");
	}
	___godot_icall_void_String(mb, (const Object *) this, file);
}

bool OS::has_virtual_keyboard() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "has_virtual_keyboard");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::show_virtual_keyboard(const String existing_text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "show_virtual_keyboard");
	}
	___godot_icall_void_String(mb, (const Object *) this, existing_text);
}

void OS::hide_virtual_keyboard() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "hide_virtual_keyboard");
	}
	___godot_icall_void(mb, (const Object *) this);
}

int64_t OS::get_virtual_keyboard_height() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_virtual_keyboard_height");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void OS::print_resources_in_use(const bool _short) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "print_resources_in_use");
	}
	___godot_icall_void_bool(mb, (const Object *) this, _short);
}

void OS::print_all_resources(const String tofile) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "print_all_resources");
	}
	___godot_icall_void_String(mb, (const Object *) this, tofile);
}

int64_t OS::get_static_memory_usage() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_static_memory_usage");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t OS::get_static_memory_peak_usage() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_static_memory_peak_usage");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t OS::get_dynamic_memory_usage() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_dynamic_memory_usage");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

String OS::get_user_data_dir() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_user_data_dir");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String OS::get_system_dir(const int64_t dir) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_system_dir");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, dir);
}

String OS::get_unique_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_unique_id");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

bool OS::is_ok_left_and_cancel_right() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_ok_left_and_cancel_right");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::print_all_textures_by_size() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "print_all_textures_by_size");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void OS::print_resources_by_type(const PoolStringArray types) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "print_resources_by_type");
	}
	___godot_icall_void_PoolStringArray(mb, (const Object *) this, types);
}

Error OS::native_video_play(const String path, const double volume, const String audio_track, const String subtitle_track) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "native_video_play");
	}
	return (Error) ___godot_icall_int_String_float_String_String(mb, (const Object *) this, path, volume, audio_track, subtitle_track);
}

bool OS::native_video_is_playing() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "native_video_is_playing");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void OS::native_video_stop() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "native_video_stop");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void OS::native_video_pause() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "native_video_pause");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void OS::native_video_unpause() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "native_video_unpause");
	}
	___godot_icall_void(mb, (const Object *) this);
}

String OS::get_scancode_string(const int64_t code) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_scancode_string");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, code);
}

bool OS::is_scancode_unicode(const int64_t code) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_scancode_unicode");
	}
	return ___godot_icall_bool_int(mb, (const Object *) this, code);
}

int64_t OS::find_scancode_from_string(const String string) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "find_scancode_from_string");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, string);
}

void OS::set_use_file_access_save_and_swap(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_use_file_access_save_and_swap");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

void OS::alert(const String text, const String title) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "alert");
	}
	___godot_icall_void_String_String(mb, (const Object *) this, text, title);
}

Error OS::set_thread_name(const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_thread_name");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, name);
}

void OS::set_use_vsync(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "set_use_vsync");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool OS::is_vsync_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "is_vsync_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool OS::has_feature(const String tag_name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "has_feature");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, tag_name);
}

OS::PowerState OS::get_power_state() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_power_state");
	}
	return (OS::PowerState) ___godot_icall_int(mb, (const Object *) this);
}

int64_t OS::get_power_seconds_left() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_power_seconds_left");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t OS::get_power_percent_left() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("_OS", "get_power_percent_left");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}