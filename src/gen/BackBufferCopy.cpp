#include <BackBufferCopy.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *BackBufferCopy::___get_type_tag()
{
	return (void *) &BackBufferCopy::___get_type_tag;
}

void *BackBufferCopy::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

BackBufferCopy *BackBufferCopy::_new()
{
	return (BackBufferCopy *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"BackBufferCopy")());
}
void BackBufferCopy::set_rect(const Rect2 rect) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BackBufferCopy", "set_rect");
	}
	___godot_icall_void_Rect2(mb, (const Object *) this, rect);
}

Rect2 BackBufferCopy::get_rect() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BackBufferCopy", "get_rect");
	}
	return ___godot_icall_Rect2(mb, (const Object *) this);
}

void BackBufferCopy::set_copy_mode(const int64_t copy_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BackBufferCopy", "set_copy_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, copy_mode);
}

BackBufferCopy::CopyMode BackBufferCopy::get_copy_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BackBufferCopy", "get_copy_mode");
	}
	return (BackBufferCopy::CopyMode) ___godot_icall_int(mb, (const Object *) this);
}

}