#include <SegmentShape2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *SegmentShape2D::___get_type_tag()
{
	return (void *) &SegmentShape2D::___get_type_tag;
}

void *SegmentShape2D::___get_base_type_tag()
{
	return (void *) &Shape2D::___get_type_tag;
}

SegmentShape2D *SegmentShape2D::_new()
{
	return (SegmentShape2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"SegmentShape2D")());
}
void SegmentShape2D::set_a(const Vector2 a) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SegmentShape2D", "set_a");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, a);
}

Vector2 SegmentShape2D::get_a() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SegmentShape2D", "get_a");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void SegmentShape2D::set_b(const Vector2 b) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SegmentShape2D", "set_b");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, b);
}

Vector2 SegmentShape2D::get_b() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SegmentShape2D", "get_b");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

}