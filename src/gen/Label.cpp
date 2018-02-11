#include <Label.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Label::___get_type_tag()
{
	return (void *) &Label::___get_type_tag;
}

void *Label::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

Label *Label::_new()
{
	return (Label *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Label")());
}
void Label::set_align(const int64_t align) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "set_align");
	}
	___godot_icall_void_int(mb, (const Object *) this, align);
}

Label::Align Label::get_align() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_align");
	}
	return (Label::Align) ___godot_icall_int(mb, (const Object *) this);
}

void Label::set_valign(const int64_t valign) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "set_valign");
	}
	___godot_icall_void_int(mb, (const Object *) this, valign);
}

Label::VAlign Label::get_valign() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_valign");
	}
	return (Label::VAlign) ___godot_icall_int(mb, (const Object *) this);
}

void Label::set_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "set_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

String Label::get_text() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Label::set_autowrap(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "set_autowrap");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Label::has_autowrap() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "has_autowrap");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Label::set_clip_text(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "set_clip_text");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Label::is_clipping_text() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "is_clipping_text");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Label::set_uppercase(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "set_uppercase");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Label::is_uppercase() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "is_uppercase");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

int64_t Label::get_line_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_line_height");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t Label::get_line_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_line_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t Label::get_visible_line_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_visible_line_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t Label::get_total_character_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_total_character_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Label::set_visible_characters(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "set_visible_characters");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

int64_t Label::get_visible_characters() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_visible_characters");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Label::set_percent_visible(const double percent_visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "set_percent_visible");
	}
	___godot_icall_void_float(mb, (const Object *) this, percent_visible);
}

double Label::get_percent_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_percent_visible");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Label::set_lines_skipped(const int64_t lines_skipped) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "set_lines_skipped");
	}
	___godot_icall_void_int(mb, (const Object *) this, lines_skipped);
}

int64_t Label::get_lines_skipped() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_lines_skipped");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Label::set_max_lines_visible(const int64_t lines_visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "set_max_lines_visible");
	}
	___godot_icall_void_int(mb, (const Object *) this, lines_visible);
}

int64_t Label::get_max_lines_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Label", "get_max_lines_visible");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}