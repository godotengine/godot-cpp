#include <StyleBox.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *StyleBox::___get_type_tag()
{
	return (void *) &StyleBox::___get_type_tag;
}

void *StyleBox::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

bool StyleBox::test_mask(const Vector2 point, const Rect2 rect) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBox", "test_mask");
	}
	return ___godot_icall_bool_Vector2_Rect2(mb, (const Object *) this, point, rect);
}

void StyleBox::set_default_margin(const int64_t margin, const double offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBox", "set_default_margin");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, margin, offset);
}

double StyleBox::get_default_margin(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBox", "get_default_margin");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, margin);
}

double StyleBox::get_margin(const int64_t margin) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBox", "get_margin");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, margin);
}

Vector2 StyleBox::get_minimum_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBox", "get_minimum_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 StyleBox::get_center_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBox", "get_center_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

Vector2 StyleBox::get_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBox", "get_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void StyleBox::draw(const RID canvas_item, const Rect2 rect) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StyleBox", "draw");
	}
	___godot_icall_void_RID_Rect2(mb, (const Object *) this, canvas_item, rect);
}

}