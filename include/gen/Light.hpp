#ifndef GODOT_CPP_LIGHT_HPP
#define GODOT_CPP_LIGHT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Light.hpp"

#include "VisualInstance.hpp"
namespace godot {


class Light : public VisualInstance {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Light"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum BakeMode {
		BAKE_ALL = 2,
		BAKE_INDIRECT = 1,
		BAKE_DISABLED = 0,
	};
	enum Param {
		PARAM_SHADOW_SPLIT_1_OFFSET = 9,
		PARAM_SHADOW_SPLIT_2_OFFSET = 10,
		PARAM_CONTACT_SHADOW_SIZE = 7,
		PARAM_SHADOW_BIAS_SPLIT_SCALE = 14,
		PARAM_INDIRECT_ENERGY = 1,
		PARAM_ATTENUATION = 4,
		PARAM_ENERGY = 0,
		PARAM_SHADOW_BIAS = 13,
		PARAM_SHADOW_SPLIT_3_OFFSET = 11,
		PARAM_MAX = 15,
		PARAM_SHADOW_MAX_DISTANCE = 8,
		PARAM_SPOT_ANGLE = 5,
		PARAM_RANGE = 3,
		PARAM_SPECULAR = 2,
		PARAM_SHADOW_NORMAL_BIAS = 12,
		PARAM_SPOT_ATTENUATION = 6,
	};

	// constants

	// methods
	void set_editor_only(const bool editor_only);
	bool is_editor_only() const;
	void set_param(const int64_t param, const double value);
	double get_param(const int64_t param) const;
	void set_shadow(const bool enabled);
	bool has_shadow() const;
	void set_negative(const bool enabled);
	bool is_negative() const;
	void set_cull_mask(const int64_t cull_mask);
	int64_t get_cull_mask() const;
	void set_color(const Color color);
	Color get_color() const;
	void set_shadow_reverse_cull_face(const bool enable);
	bool get_shadow_reverse_cull_face() const;
	void set_shadow_color(const Color shadow_color);
	Color get_shadow_color() const;
	void set_bake_mode(const int64_t bake_mode);
	Light::BakeMode get_bake_mode() const;

};

}

#endif