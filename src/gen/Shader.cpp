#include <Shader.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *Shader::___get_type_tag()
{
	return (void *) &Shader::___get_type_tag;
}

void *Shader::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

Shader *Shader::_new()
{
	return (Shader *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Shader")());
}
Shader::Mode Shader::get_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shader", "get_mode");
	}
	return (Shader::Mode) ___godot_icall_int(mb, (const Object *) this);
}

void Shader::set_code(const String code) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shader", "set_code");
	}
	___godot_icall_void_String(mb, (const Object *) this, code);
}

String Shader::get_code() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shader", "get_code");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

void Shader::set_default_texture_param(const String param, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shader", "set_default_texture_param");
	}
	___godot_icall_void_String_Object(mb, (const Object *) this, param, texture.ptr());
}

Ref<Texture> Shader::get_default_texture_param(const String param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shader", "get_default_texture_param");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_String(mb, (const Object *) this, param));
}

bool Shader::has_param(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Shader", "has_param");
	}
	return ___godot_icall_bool_String(mb, (const Object *) this, name);
}

}