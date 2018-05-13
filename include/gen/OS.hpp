#ifndef GODOT_CPP_OS_HPP
#define GODOT_CPP_OS_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "OS.hpp"

#include "Object.hpp"
namespace godot {

class Image;

class OS : public Object {
	static OS *_singleton;

	OS();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline OS *get_singleton()
	{
		if (!OS::_singleton) {
			OS::_singleton = new OS;
		}
		return OS::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "OS"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum SystemDir {
		SYSTEM_DIR_MOVIES = 4,
		SYSTEM_DIR_PICTURES = 6,
		SYSTEM_DIR_DCIM = 1,
		SYSTEM_DIR_DOWNLOADS = 3,
		SYSTEM_DIR_DOCUMENTS = 2,
		SYSTEM_DIR_MUSIC = 5,
		SYSTEM_DIR_RINGTONES = 7,
		SYSTEM_DIR_DESKTOP = 0,
	};
	enum ScreenOrientation {
		SCREEN_ORIENTATION_REVERSE_LANDSCAPE = 2,
		SCREEN_ORIENTATION_LANDSCAPE = 0,
		SCREEN_ORIENTATION_SENSOR = 6,
		SCREEN_ORIENTATION_PORTRAIT = 1,
		SCREEN_ORIENTATION_SENSOR_LANDSCAPE = 4,
		SCREEN_ORIENTATION_SENSOR_PORTRAIT = 5,
		SCREEN_ORIENTATION_REVERSE_PORTRAIT = 3,
	};
	enum PowerState {
		POWERSTATE_CHARGED = 4,
		POWERSTATE_ON_BATTERY = 1,
		POWERSTATE_NO_BATTERY = 2,
		POWERSTATE_CHARGING = 3,
		POWERSTATE_UNKNOWN = 0,
	};
	enum Month {
		MONTH_JULY = 7,
		MONTH_AUGUST = 8,
		MONTH_JUNE = 6,
		MONTH_DECEMBER = 12,
		MONTH_JANUARY = 1,
		MONTH_APRIL = 4,
		MONTH_MARCH = 3,
		MONTH_SEPTEMBER = 9,
		MONTH_MAY = 5,
		MONTH_NOVEMBER = 11,
		MONTH_OCTOBER = 10,
		MONTH_FEBRUARY = 2,
	};
	enum Weekday {
		DAY_MONDAY = 1,
		DAY_WEDNESDAY = 3,
		DAY_SUNDAY = 0,
		DAY_TUESDAY = 2,
		DAY_SATURDAY = 6,
		DAY_FRIDAY = 5,
		DAY_THURSDAY = 4,
	};

	// constants

	// methods
	void set_clipboard(const String clipboard);
	String get_clipboard() const;
	int64_t get_video_driver_count() const;
	String get_video_driver_name(const int64_t driver) const;
	int64_t get_audio_driver_count() const;
	String get_audio_driver_name(const int64_t driver) const;
	int64_t get_screen_count() const;
	int64_t get_current_screen() const;
	void set_current_screen(const int64_t screen);
	Vector2 get_screen_position(const int64_t screen = -1) const;
	Vector2 get_screen_size(const int64_t screen = -1) const;
	int64_t get_screen_dpi(const int64_t screen = -1) const;
	Vector2 get_window_position() const;
	void set_window_position(const Vector2 position);
	Vector2 get_window_size() const;
	void set_window_size(const Vector2 size);
	Rect2 get_window_safe_area() const;
	void set_window_fullscreen(const bool enabled);
	bool is_window_fullscreen() const;
	void set_window_resizable(const bool enabled);
	bool is_window_resizable() const;
	void set_window_minimized(const bool enabled);
	bool is_window_minimized() const;
	void set_window_maximized(const bool enabled);
	bool is_window_maximized() const;
	void set_window_always_on_top(const bool enabled);
	bool is_window_always_on_top() const;
	void request_attention();
	Vector2 get_real_window_size() const;
	void center_window();
	void set_borderless_window(const bool borderless);
	bool get_borderless_window() const;
	bool get_window_per_pixel_transparency_enabled() const;
	void set_window_per_pixel_transparency_enabled(const bool enabled);
	void set_ime_position(const Vector2 position);
	void set_screen_orientation(const int64_t orientation);
	OS::ScreenOrientation get_screen_orientation() const;
	void set_keep_screen_on(const bool enabled);
	bool is_keep_screen_on() const;
	bool has_touchscreen_ui_hint() const;
	void set_window_title(const String title);
	void set_low_processor_usage_mode(const bool enable);
	bool is_in_low_processor_usage_mode() const;
	int64_t get_processor_count() const;
	String get_executable_path() const;
	int64_t execute(const String path, const PoolStringArray arguments, const bool blocking, const Array output = Array());
	Error kill(const int64_t pid);
	Error shell_open(const String uri);
	int64_t get_process_id() const;
	String get_environment(const String environment) const;
	bool has_environment(const String environment) const;
	String get_name() const;
	PoolStringArray get_cmdline_args();
	Dictionary get_datetime(const bool utc = false) const;
	Dictionary get_date(const bool utc = false) const;
	Dictionary get_time(const bool utc = false) const;
	Dictionary get_time_zone_info() const;
	int64_t get_unix_time() const;
	Dictionary get_datetime_from_unix_time(const int64_t unix_time_val) const;
	int64_t get_unix_time_from_datetime(const Dictionary datetime) const;
	int64_t get_system_time_secs() const;
	void set_icon(const Ref<Image> icon);
	int64_t get_exit_code() const;
	void set_exit_code(const int64_t code);
	void delay_usec(const int64_t usec) const;
	void delay_msec(const int64_t msec) const;
	int64_t get_ticks_msec() const;
	int64_t get_splash_tick_msec() const;
	String get_locale() const;
	String get_latin_keyboard_variant() const;
	String get_model_name() const;
	bool can_draw() const;
	bool is_userfs_persistent() const;
	bool is_stdout_verbose() const;
	bool can_use_threads() const;
	bool is_debug_build() const;
	void dump_memory_to_file(const String file);
	void dump_resources_to_file(const String file);
	bool has_virtual_keyboard() const;
	void show_virtual_keyboard(const String existing_text = "");
	void hide_virtual_keyboard();
	int64_t get_virtual_keyboard_height();
	void print_resources_in_use(const bool _short = false);
	void print_all_resources(const String tofile = "");
	int64_t get_static_memory_usage() const;
	int64_t get_static_memory_peak_usage() const;
	int64_t get_dynamic_memory_usage() const;
	String get_user_data_dir() const;
	String get_system_dir(const int64_t dir) const;
	String get_unique_id() const;
	bool is_ok_left_and_cancel_right() const;
	void print_all_textures_by_size();
	void print_resources_by_type(const PoolStringArray types);
	Error native_video_play(const String path, const double volume, const String audio_track, const String subtitle_track);
	bool native_video_is_playing();
	void native_video_stop();
	void native_video_pause();
	void native_video_unpause();
	String get_scancode_string(const int64_t code) const;
	bool is_scancode_unicode(const int64_t code) const;
	int64_t find_scancode_from_string(const String string) const;
	void set_use_file_access_save_and_swap(const bool enabled);
	void alert(const String text, const String title = "Alert!");
	Error set_thread_name(const String name);
	void set_use_vsync(const bool enable);
	bool is_vsync_enabled() const;
	bool has_feature(const String tag_name) const;
	OS::PowerState get_power_state();
	int64_t get_power_seconds_left();
	int64_t get_power_percent_left();

};

}

#endif