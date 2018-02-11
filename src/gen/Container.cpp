#include <Container.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *Container::___get_type_tag()
{
	return (void *) &Container::___get_type_tag;
}

void *Container::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

Container *Container::_new()
{
	return (Container *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Container")());
}
void Container::_sort_children() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Container", "_sort_children");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Container::_child_minsize_changed() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Container", "_child_minsize_changed");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Container::queue_sort() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Container", "queue_sort");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void Container::fit_child_in_rect(const Object *child, const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Container", "fit_child_in_rect");
	}
	___godot_icall_void_Object_Rect2(mb, (const Object *) this, child, rect);
}

}