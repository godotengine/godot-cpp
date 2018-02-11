#include <LinkButton.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *LinkButton::___get_type_tag()
{
	return (void *) &LinkButton::___get_type_tag;
}

void *LinkButton::___get_base_type_tag()
{
	return (void *) &BaseButton::___get_type_tag;
}

LinkButton *LinkButton::_new()
{
	return (LinkButton *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"LinkButton")());
}
void LinkButton::set_text(const String text) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LinkButton", "set_text");
	}
	___godot_icall_void_String(mb, (const Object *) this, text);
}

String LinkButton::get_text() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LinkButton", "get_text");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void LinkButton::set_underline_mode(const int64_t underline_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LinkButton", "set_underline_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, underline_mode);
}

LinkButton::UnderlineMode LinkButton::get_underline_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("LinkButton", "get_underline_mode");
	}
	return (LinkButton::UnderlineMode) ___godot_icall_int(mb, (const Object *) this);
}

}