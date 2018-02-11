#include <ScrollBar.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>


namespace godot {


void *ScrollBar::___get_type_tag()
{
	return (void *) &ScrollBar::___get_type_tag;
}

void *ScrollBar::___get_base_type_tag()
{
	return (void *) &Range::___get_type_tag;
}

void ScrollBar::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScrollBar", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ScrollBar::set_custom_step(const double step) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScrollBar", "set_custom_step");
	}
	___godot_icall_void_float(mb, (const Object *) this, step);
}

double ScrollBar::get_custom_step() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScrollBar", "get_custom_step");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void ScrollBar::_drag_slave_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScrollBar", "_drag_slave_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void ScrollBar::_drag_slave_exit() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ScrollBar", "_drag_slave_exit");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}