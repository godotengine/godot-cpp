#ifndef GODOT_CPP_LABEL_HPP
#define GODOT_CPP_LABEL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Label.hpp>

#include <Control.hpp>
namespace godot {


class Label : public Control {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Label"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Align {
		ALIGN_FILL = 3,
		ALIGN_LEFT = 0,
		ALIGN_CENTER = 1,
		ALIGN_RIGHT = 2,
	};
	enum VAlign {
		VALIGN_BOTTOM = 2,
		VALIGN_CENTER = 1,
		VALIGN_FILL = 3,
		VALIGN_TOP = 0,
	};

	// constants


	static Label *_new();

	// methods
	void set_align(const int64_t align);
	Label::Align get_align() const;
	void set_valign(const int64_t valign);
	Label::VAlign get_valign() const;
	void set_text(const String text);
	String get_text() const;
	void set_autowrap(const bool enable);
	bool has_autowrap() const;
	void set_clip_text(const bool enable);
	bool is_clipping_text() const;
	void set_uppercase(const bool enable);
	bool is_uppercase() const;
	int64_t get_line_height() const;
	int64_t get_line_count() const;
	int64_t get_visible_line_count() const;
	int64_t get_total_character_count() const;
	void set_visible_characters(const int64_t amount);
	int64_t get_visible_characters() const;
	void set_percent_visible(const double percent_visible);
	double get_percent_visible() const;
	void set_lines_skipped(const int64_t lines_skipped);
	int64_t get_lines_skipped() const;
	void set_max_lines_visible(const int64_t lines_visible);
	int64_t get_max_lines_visible() const;

};

}

#endif