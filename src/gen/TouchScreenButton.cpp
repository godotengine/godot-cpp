#include <TouchScreenButton.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>
#include <BitMap.hpp>
#include <Shape2D.hpp>
#include <InputEvent.hpp>


namespace godot {


void *TouchScreenButton::___get_type_tag()
{
	return (void *) &TouchScreenButton::___get_type_tag;
}

void *TouchScreenButton::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

TouchScreenButton *TouchScreenButton::_new()
{
	return (TouchScreenButton *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"TouchScreenButton")());
}
void TouchScreenButton::set_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "set_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> TouchScreenButton::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void TouchScreenButton::set_texture_pressed(const Ref<Texture> texture_pressed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "set_texture_pressed");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture_pressed.ptr());
}

Ref<Texture> TouchScreenButton::get_texture_pressed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "get_texture_pressed");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void TouchScreenButton::set_bitmask(const Ref<BitMap> bitmask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "set_bitmask");
	}
	___godot_icall_void_Object(mb, (const Object *) this, bitmask.ptr());
}

Ref<BitMap> TouchScreenButton::get_bitmask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "get_bitmask");
	}
	return Ref<BitMap>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void TouchScreenButton::set_shape(const Ref<Shape2D> shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "set_shape");
	}
	___godot_icall_void_Object(mb, (const Object *) this, shape.ptr());
}

Ref<Shape2D> TouchScreenButton::get_shape() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "get_shape");
	}
	return Ref<Shape2D>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void TouchScreenButton::set_shape_centered(const bool _bool) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "set_shape_centered");
	}
	___godot_icall_void_bool(mb, (const Object *) this, _bool);
}

bool TouchScreenButton::is_shape_centered() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "is_shape_centered");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TouchScreenButton::set_shape_visible(const bool _bool) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "set_shape_visible");
	}
	___godot_icall_void_bool(mb, (const Object *) this, _bool);
}

bool TouchScreenButton::is_shape_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "is_shape_visible");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TouchScreenButton::set_action(const String action) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "set_action");
	}
	___godot_icall_void_String(mb, (const Object *) this, action);
}

String TouchScreenButton::get_action() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "get_action");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void TouchScreenButton::set_visibility_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "set_visibility_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

TouchScreenButton::VisibilityMode TouchScreenButton::get_visibility_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "get_visibility_mode");
	}
	return (TouchScreenButton::VisibilityMode) ___godot_icall_int(mb, (const Object *) this);
}

void TouchScreenButton::set_passby_press(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "set_passby_press");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool TouchScreenButton::is_passby_press_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "is_passby_press_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

bool TouchScreenButton::is_pressed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "is_pressed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void TouchScreenButton::_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TouchScreenButton", "_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

}