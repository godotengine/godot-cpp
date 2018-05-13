#ifndef GODOT_CPP_CANVASITEMMATERIAL_HPP
#define GODOT_CPP_CANVASITEMMATERIAL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "CanvasItemMaterial.hpp"

#include "Material.hpp"
namespace godot {


class CanvasItemMaterial : public Material {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "CanvasItemMaterial"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum LightMode {
		LIGHT_MODE_UNSHADED = 1,
		LIGHT_MODE_NORMAL = 0,
		LIGHT_MODE_LIGHT_ONLY = 2,
	};
	enum BlendMode {
		BLEND_MODE_SUB = 2,
		BLEND_MODE_MUL = 3,
		BLEND_MODE_MIX = 0,
		BLEND_MODE_PREMULT_ALPHA = 4,
		BLEND_MODE_ADD = 1,
	};

	// constants


	static CanvasItemMaterial *_new();

	// methods
	void set_blend_mode(const int64_t blend_mode);
	CanvasItemMaterial::BlendMode get_blend_mode() const;
	void set_light_mode(const int64_t light_mode);
	CanvasItemMaterial::LightMode get_light_mode() const;

};

}

#endif