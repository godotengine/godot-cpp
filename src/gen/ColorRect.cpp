#include <ColorRect.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *ColorRect::___get_type_tag()
{
	return (void *) &ColorRect::___get_type_tag;
}

void *ColorRect::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

ColorRect *ColorRect::_new()
{
	return (ColorRect *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"ColorRect")());
}
void ColorRect::set_frame_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorRect", "set_frame_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color ColorRect::get_frame_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("ColorRect", "get_frame_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

}