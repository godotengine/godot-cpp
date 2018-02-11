#include <ViewportContainer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>


namespace godot {


void *ViewportContainer::___get_type_tag()
{
	return (void *) &ViewportContainer::___get_type_tag;
}

void *ViewportContainer::___get_base_type_tag()
{
	return (void *) &Container::___get_type_tag;
}

ViewportContainer *ViewportContainer::_new()
{
	return (ViewportContainer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ViewportContainer")());
}
void ViewportContainer::_input(const Ref<InputEvent> event) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ViewportContainer", "_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, event.ptr());
}

void ViewportContainer::set_stretch(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ViewportContainer", "set_stretch");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool ViewportContainer::is_stretch_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ViewportContainer", "is_stretch_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void ViewportContainer::set_stretch_shrink(const int64_t amount) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ViewportContainer", "set_stretch_shrink");
	}
	___godot_icall_void_int(mb, (const Object *) this, amount);
}

int64_t ViewportContainer::get_stretch_shrink() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ViewportContainer", "get_stretch_shrink");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}