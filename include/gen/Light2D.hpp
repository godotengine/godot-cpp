#ifndef GODOT_CPP_LIGHT2D_HPP
#define GODOT_CPP_LIGHT2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Light2D.hpp"

#include "Node2D.hpp"
namespace godot {

class Texture;

class Light2D : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Light2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum ShadowFilter {
		SHADOW_FILTER_PCF3 = 1,
		SHADOW_FILTER_PCF13 = 5,
		SHADOW_FILTER_PCF7 = 3,
		SHADOW_FILTER_PCF5 = 2,
		SHADOW_FILTER_PCF9 = 4,
		SHADOW_FILTER_NONE = 0,
	};
	enum Mode {
		MODE_SUB = 1,
		MODE_ADD = 0,
		MODE_MIX = 2,
		MODE_MASK = 3,
	};

	// constants


	static Light2D *_new();

	// methods
	void set_enabled(const bool enabled);
	bool is_enabled() const;
	void set_editor_only(const bool editor_only);
	bool is_editor_only() const;
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_texture_offset(const Vector2 texture_offset);
	Vector2 get_texture_offset() const;
	void set_color(const Color color);
	Color get_color() const;
	void set_height(const double height);
	double get_height() const;
	void set_energy(const double energy);
	double get_energy() const;
	void set_texture_scale(const double texture_scale);
	double get_texture_scale() const;
	void set_z_range_min(const int64_t z);
	int64_t get_z_range_min() const;
	void set_z_range_max(const int64_t z);
	int64_t get_z_range_max() const;
	void set_layer_range_min(const int64_t layer);
	int64_t get_layer_range_min() const;
	void set_layer_range_max(const int64_t layer);
	int64_t get_layer_range_max() const;
	void set_item_cull_mask(const int64_t item_cull_mask);
	int64_t get_item_cull_mask() const;
	void set_item_shadow_cull_mask(const int64_t item_shadow_cull_mask);
	int64_t get_item_shadow_cull_mask() const;
	void set_mode(const int64_t mode);
	Light2D::Mode get_mode() const;
	void set_shadow_enabled(const bool enabled);
	bool is_shadow_enabled() const;
	void set_shadow_buffer_size(const int64_t size);
	int64_t get_shadow_buffer_size() const;
	void set_shadow_smooth(const double smooth);
	double get_shadow_smooth() const;
	void set_shadow_gradient_length(const double multiplier);
	double get_shadow_gradient_length() const;
	void set_shadow_filter(const int64_t filter);
	Light2D::ShadowFilter get_shadow_filter() const;
	void set_shadow_color(const Color shadow_color);
	Color get_shadow_color() const;

};

}

#endif