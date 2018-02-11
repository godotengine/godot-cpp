#include <YSort.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *YSort::___get_type_tag()
{
	return (void *) &YSort::___get_type_tag;
}

void *YSort::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

YSort *YSort::_new()
{
	return (YSort *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"YSort")());
}
void YSort::set_sort_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("YSort", "set_sort_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool YSort::is_sort_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("YSort", "is_sort_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}