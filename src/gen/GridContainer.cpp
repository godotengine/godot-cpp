#include <GridContainer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *GridContainer::___get_type_tag()
{
	return (void *) &GridContainer::___get_type_tag;
}

void *GridContainer::___get_base_type_tag()
{
	return (void *) &Container::___get_type_tag;
}

GridContainer *GridContainer::_new()
{
	return (GridContainer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"GridContainer")());
}
void GridContainer::set_columns(const int64_t columns) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridContainer", "set_columns");
	}
	___godot_icall_void_int(mb, (const Object *) this, columns);
}

int64_t GridContainer::get_columns() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("GridContainer", "get_columns");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}