#include <ProgressBar.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ProgressBar::___get_type_tag()
{
	return (void *) &ProgressBar::___get_type_tag;
}

void *ProgressBar::___get_base_type_tag()
{
	return (void *) &Range::___get_type_tag;
}

ProgressBar *ProgressBar::_new()
{
	return (ProgressBar *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ProgressBar")());
}
void ProgressBar::set_percent_visible(const bool visible) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProgressBar", "set_percent_visible");
	}
	___godot_icall_void_bool(mb, (const Object *) this, visible);
}

bool ProgressBar::is_percent_visible() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ProgressBar", "is_percent_visible");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}