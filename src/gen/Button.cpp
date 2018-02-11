#include <Button.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *Button::___get_type_tag()
{
	return (void *) &Button::___get_type_tag;
}

void *Button::___get_base_type_tag()
{
	return (void *) &BaseButton::___get_type_tag;
}

Button *Button::_new()
{
	return (Button *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Button")());
}
void Button::set_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Button", "set_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

String Button::get_text() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Button", "get_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Button::set_button_icon(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Button", "set_button_icon");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> Button::get_button_icon() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Button", "get_button_icon");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Button::set_flat(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Button", "set_flat");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

void Button::set_clip_text(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Button", "set_clip_text");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Button::get_clip_text() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Button", "get_clip_text");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Button::set_text_align(const int64_t align) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Button", "set_text_align");
	}
	___godot_icall_void_int(mb, (const Object *) this, align);
}

Button::TextAlign Button::get_text_align() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Button", "get_text_align");
	}
	return (Button::TextAlign) ___godot_icall_int(mb, (const Object *) this);
}

bool Button::is_flat() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Button", "is_flat");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}