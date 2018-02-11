#include <VideoStreamWebm.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *VideoStreamWebm::___get_type_tag()
{
	return (void *) &VideoStreamWebm::___get_type_tag;
}

void *VideoStreamWebm::___get_base_type_tag()
{
	return (void *) &VideoStream::___get_type_tag;
}

VideoStreamWebm *VideoStreamWebm::_new()
{
	return (VideoStreamWebm *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"VideoStreamWebm")());
}
void VideoStreamWebm::set_file(const String file) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoStreamWebm", "set_file");
	}
	___godot_icall_void_String(mb, (const Object *) this, file);
}

String VideoStreamWebm::get_file() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("VideoStreamWebm", "get_file");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

}