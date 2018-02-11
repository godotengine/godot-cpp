#include <LineShape2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *LineShape2D::___get_type_tag()
{
	return (void *) &LineShape2D::___get_type_tag;
}

void *LineShape2D::___get_base_type_tag()
{
	return (void *) &Shape2D::___get_type_tag;
}

LineShape2D *LineShape2D::_new()
{
	return (LineShape2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"LineShape2D")());
}
void LineShape2D::set_normal(const Vector2 normal) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineShape2D", "set_normal");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, normal);
}

Vector2 LineShape2D::get_normal() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineShape2D", "get_normal");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void LineShape2D::set_d(const double d) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineShape2D", "set_d");
	}
	___godot_icall_void_float(mb, (const Object *) this, d);
}

double LineShape2D::get_d() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LineShape2D", "get_d");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}