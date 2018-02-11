#include <VideoStreamTheora.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VideoStreamTheora::___get_type_tag()
{
	return (void *) &VideoStreamTheora::___get_type_tag;
}

void *VideoStreamTheora::___get_base_type_tag()
{
	return (void *) &VideoStream::___get_type_tag;
}

VideoStreamTheora *VideoStreamTheora::_new()
{
	return (VideoStreamTheora *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VideoStreamTheora")());
}
void VideoStreamTheora::set_file(const String file) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoStreamTheora", "set_file");
	}
	___godot_icall_void_String(mb, (const Object *) this, file);
}

String VideoStreamTheora::get_file() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoStreamTheora", "get_file");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}