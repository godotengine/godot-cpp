#ifndef GODOT_CPP_VISUALINSTANCE_HPP
#define GODOT_CPP_VISUALINSTANCE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Spatial.hpp"
namespace godot {


class VisualInstance : public Spatial {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "VisualInstance"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	RID _get_visual_instance_rid() const;
	void set_base(const RID base);
	void set_layer_mask(const int64_t mask);
	int64_t get_layer_mask() const;
	AABB get_transformed_aabb() const;
	AABB get_aabb() const;

};

}

#endif