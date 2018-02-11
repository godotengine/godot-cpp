#include <Slider.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>


namespace godot {


void *Slider::___get_type_tag()
{
	return (void *) &Slider::___get_type_tag;
}

void *Slider::___get_base_type_tag()
{
	return (void *) &Range::___get_type_tag;
}

void Slider::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Slider", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void Slider::set_ticks(const int64_t count) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Slider", "set_ticks");
	}
	___godot_icall_void_int(mb, (const Object *) this, count);
}

int64_t Slider::get_ticks() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Slider", "get_ticks");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

bool Slider::get_ticks_on_borders() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Slider", "get_ticks_on_borders");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Slider::set_ticks_on_borders(const bool ticks_on_border) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Slider", "set_ticks_on_borders");
	}
	___godot_icall_void_bool(mb, (const Object *) this, ticks_on_border);
}

void Slider::set_editable(const bool editable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Slider", "set_editable");
	}
	___godot_icall_void_bool(mb, (const Object *) this, editable);
}

bool Slider::is_editable() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Slider", "is_editable");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}