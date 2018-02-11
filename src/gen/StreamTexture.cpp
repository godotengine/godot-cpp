#include <StreamTexture.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *StreamTexture::___get_type_tag()
{
	return (void *) &StreamTexture::___get_type_tag;
}

void *StreamTexture::___get_base_type_tag()
{
	return (void *) &Texture::___get_type_tag;
}

StreamTexture *StreamTexture::_new()
{
	return (StreamTexture *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"StreamTexture")());
}
Error StreamTexture::load(const String path) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamTexture", "load");
	}
	return (Error) ___godot_icall_int_String(mb, (const Object *) this, path);
}

String StreamTexture::get_load_path() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("StreamTexture", "get_load_path");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}