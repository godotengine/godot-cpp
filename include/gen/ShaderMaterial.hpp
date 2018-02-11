#ifndef GODOT_CPP_SHADERMATERIAL_HPP
#define GODOT_CPP_SHADERMATERIAL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Material.hpp>
namespace godot {

class Shader;

class ShaderMaterial : public Material {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ShaderMaterial"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ShaderMaterial *_new();

	// methods
	void set_shader(const Ref<Shader> shader);
	Ref<Shader> get_shader() const;
	void set_shader_param(const String param, const Variant value);
	Variant get_shader_param(const String param) const;

};

}

#endif