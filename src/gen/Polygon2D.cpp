#include <Polygon2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *Polygon2D::___get_type_tag()
{
	return (void *) &Polygon2D::___get_type_tag;
}

void *Polygon2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

Polygon2D *Polygon2D::_new()
{
	return (Polygon2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Polygon2D")());
}
void Polygon2D::set_polygon(const PoolVector2Array polygon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_polygon");
	}
	___godot_icall_void_PoolVector2Array(mb, (const Object *) this, polygon);
}

PoolVector2Array Polygon2D::get_polygon() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_polygon");
	}
	return ___godot_icall_PoolVector2Array(mb, (const Object *) this);
}

void Polygon2D::set_uv(const PoolVector2Array uv) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_uv");
	}
	___godot_icall_void_PoolVector2Array(mb, (const Object *) this, uv);
}

PoolVector2Array Polygon2D::get_uv() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_uv");
	}
	return ___godot_icall_PoolVector2Array(mb, (const Object *) this);
}

void Polygon2D::set_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color Polygon2D::get_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void Polygon2D::set_splits(const PoolIntArray splits) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_splits");
	}
	___godot_icall_void_PoolIntArray(mb, (const Object *) this, splits);
}

PoolIntArray Polygon2D::get_splits() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_splits");
	}
	return ___godot_icall_PoolIntArray(mb, (const Object *) this);
}

void Polygon2D::set_vertex_colors(const PoolColorArray vertex_colors) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_vertex_colors");
	}
	___godot_icall_void_PoolColorArray(mb, (const Object *) this, vertex_colors);
}

PoolColorArray Polygon2D::get_vertex_colors() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_vertex_colors");
	}
	return ___godot_icall_PoolColorArray(mb, (const Object *) this);
}

void Polygon2D::set_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> Polygon2D::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Polygon2D::set_texture_offset(const Vector2 texture_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_texture_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, texture_offset);
}

Vector2 Polygon2D::get_texture_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_texture_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Polygon2D::set_texture_rotation(const double texture_rotation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_texture_rotation");
	}
	___godot_icall_void_float(mb, (const Object *) this, texture_rotation);
}

double Polygon2D::get_texture_rotation() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_texture_rotation");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Polygon2D::set_texture_rotation_degrees(const double texture_rotation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_texture_rotation_degrees");
	}
	___godot_icall_void_float(mb, (const Object *) this, texture_rotation);
}

double Polygon2D::get_texture_rotation_degrees() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_texture_rotation_degrees");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Polygon2D::set_texture_scale(const Vector2 texture_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_texture_scale");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, texture_scale);
}

Vector2 Polygon2D::get_texture_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_texture_scale");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Polygon2D::set_invert(const bool invert) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_invert");
	}
	___godot_icall_void_bool(mb, (const Object *) this, invert);
}

bool Polygon2D::get_invert() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_invert");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Polygon2D::set_antialiased(const bool antialiased) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_antialiased");
	}
	___godot_icall_void_bool(mb, (const Object *) this, antialiased);
}

bool Polygon2D::get_antialiased() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_antialiased");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Polygon2D::set_invert_border(const double invert_border) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_invert_border");
	}
	___godot_icall_void_float(mb, (const Object *) this, invert_border);
}

double Polygon2D::get_invert_border() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_invert_border");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Polygon2D::set_offset(const Vector2 offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "set_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, offset);
}

Vector2 Polygon2D::get_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Polygon2D", "get_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

}