#include <ParallaxBackground.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ParallaxBackground::___get_type_tag()
{
	return (void *) &ParallaxBackground::___get_type_tag;
}

void *ParallaxBackground::___get_base_type_tag()
{
	return (void *) &CanvasLayer::___get_type_tag;
}

ParallaxBackground *ParallaxBackground::_new()
{
	return (ParallaxBackground *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ParallaxBackground")());
}
void ParallaxBackground::_camera_moved(const Transform2D arg0, const Vector2 arg1) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "_camera_moved");
	}
	___godot_icall_void_Transform2D_Vector2(mb, (const Object *) this, arg0, arg1);
}

void ParallaxBackground::set_scroll_offset(const Vector2 ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "set_scroll_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, ofs);
}

Vector2 ParallaxBackground::get_scroll_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "get_scroll_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void ParallaxBackground::set_scroll_base_offset(const Vector2 ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "set_scroll_base_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, ofs);
}

Vector2 ParallaxBackground::get_scroll_base_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "get_scroll_base_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void ParallaxBackground::set_scroll_base_scale(const Vector2 scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "set_scroll_base_scale");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, scale);
}

Vector2 ParallaxBackground::get_scroll_base_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "get_scroll_base_scale");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void ParallaxBackground::set_limit_begin(const Vector2 ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "set_limit_begin");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, ofs);
}

Vector2 ParallaxBackground::get_limit_begin() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "get_limit_begin");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void ParallaxBackground::set_limit_end(const Vector2 ofs) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "set_limit_end");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, ofs);
}

Vector2 ParallaxBackground::get_limit_end() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "get_limit_end");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void ParallaxBackground::set_ignore_camera_zoom(const bool ignore) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "set_ignore_camera_zoom");
	}
	___godot_icall_void_bool(mb, (const Object *) this, ignore);
}

bool ParallaxBackground::is_ignore_camera_zoom() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ParallaxBackground", "is_ignore_camera_zoom");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}