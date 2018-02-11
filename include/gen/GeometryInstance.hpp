#ifndef GODOT_CPP_GEOMETRYINSTANCE_HPP
#define GODOT_CPP_GEOMETRYINSTANCE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <GeometryInstance.hpp>

#include <VisualInstance.hpp>
namespace godot {

class Material;

class GeometryInstance : public VisualInstance {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "GeometryInstance"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Flags {
		FLAG_USE_BAKED_LIGHT = 0,
		FLAG_MAX = 1,
	};
	enum ShadowCastingSetting {
		SHADOW_CASTING_SETTING_ON = 1,
		SHADOW_CASTING_SETTING_SHADOWS_ONLY = 3,
		SHADOW_CASTING_SETTING_DOUBLE_SIDED = 2,
		SHADOW_CASTING_SETTING_OFF = 0,
	};

	// constants

	// methods
	void set_material_override(const Ref<Material> material);
	Ref<Material> get_material_override() const;
	void set_flag(const int64_t flag, const bool value);
	bool get_flag(const int64_t flag) const;
	void set_cast_shadows_setting(const int64_t shadow_casting_setting);
	GeometryInstance::ShadowCastingSetting get_cast_shadows_setting() const;
	void set_lod_max_hysteresis(const double mode);
	double get_lod_max_hysteresis() const;
	void set_lod_max_distance(const double mode);
	double get_lod_max_distance() const;
	void set_lod_min_hysteresis(const double mode);
	double get_lod_min_hysteresis() const;
	void set_lod_min_distance(const double mode);
	double get_lod_min_distance() const;
	void set_extra_cull_margin(const double margin);
	double get_extra_cull_margin() const;

};

}

#endif