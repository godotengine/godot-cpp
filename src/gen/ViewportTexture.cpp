#include <ViewportTexture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ViewportTexture::___get_type_tag()
{
	return (void *) &ViewportTexture::___get_type_tag;
}

void *ViewportTexture::___get_base_type_tag()
{
	return (void *) &Texture::___get_type_tag;
}

ViewportTexture *ViewportTexture::_new()
{
	return (ViewportTexture *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ViewportTexture")());
}
void ViewportTexture::set_viewport_path_in_scene(const NodePath path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ViewportTexture", "set_viewport_path_in_scene");
	}
	___godot_icall_void_NodePath(mb, (const Object *) this, path);
}

NodePath ViewportTexture::get_viewport_path_in_scene() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ViewportTexture", "get_viewport_path_in_scene");
	}
	return ___godot_icall_NodePath(mb, (const Object *) this);
}

}