#include <World2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Physics2DDirectSpaceState.hpp>


namespace godot {


void *World2D::___get_type_tag()
{
	return (void *) &World2D::___get_type_tag;
}

void *World2D::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

World2D *World2D::_new()
{
	return (World2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"World2D")());
}
RID World2D::get_canvas() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("World2D", "get_canvas");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

RID World2D::get_space() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("World2D", "get_space");
	}
	return ___godot_icall_RID(mb, (const Object *) this);
}

Physics2DDirectSpaceState *World2D::get_direct_space_state() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("World2D", "get_direct_space_state");
	}
	return (Physics2DDirectSpaceState *) ___godot_icall_Object(mb, (const Object *) this);
}

}