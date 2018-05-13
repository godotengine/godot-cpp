#ifndef GODOT_CPP_OMNILIGHT_HPP
#define GODOT_CPP_OMNILIGHT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "OmniLight.hpp"

#include "Light.hpp"
namespace godot {


class OmniLight : public Light {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "OmniLight"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum ShadowMode {
		SHADOW_DUAL_PARABOLOID = 0,
		SHADOW_CUBE = 1,
	};
	enum ShadowDetail {
		SHADOW_DETAIL_HORIZONTAL = 1,
		SHADOW_DETAIL_VERTICAL = 0,
	};

	// constants


	static OmniLight *_new();

	// methods
	void set_shadow_mode(const int64_t mode);
	OmniLight::ShadowMode get_shadow_mode() const;
	void set_shadow_detail(const int64_t detail);
	OmniLight::ShadowDetail get_shadow_detail() const;

};

}

#endif