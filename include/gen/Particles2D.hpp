#ifndef GODOT_CPP_PARTICLES2D_HPP
#define GODOT_CPP_PARTICLES2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Particles2D.hpp"

#include "Node2D.hpp"
namespace godot {

class Material;
class Texture;

class Particles2D : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Particles2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum DrawOrder {
		DRAW_ORDER_LIFETIME = 1,
		DRAW_ORDER_INDEX = 0,
	};

	// constants


	static Particles2D *_new();

	// methods
	void set_emitting(const bool emitting);
	void set_amount(const int64_t amount);
	void set_lifetime(const double secs);
	void set_one_shot(const bool secs);
	void set_pre_process_time(const double secs);
	void set_explosiveness_ratio(const double ratio);
	void set_randomness_ratio(const double ratio);
	void set_visibility_rect(const Rect2 aabb);
	void set_use_local_coordinates(const bool enable);
	void set_fixed_fps(const int64_t fps);
	void set_fractional_delta(const bool enable);
	void set_process_material(const Ref<Material> material);
	void set_speed_scale(const double scale);
	bool is_emitting() const;
	int64_t get_amount() const;
	double get_lifetime() const;
	bool get_one_shot() const;
	double get_pre_process_time() const;
	double get_explosiveness_ratio() const;
	double get_randomness_ratio() const;
	Rect2 get_visibility_rect() const;
	bool get_use_local_coordinates() const;
	int64_t get_fixed_fps() const;
	bool get_fractional_delta() const;
	Ref<Material> get_process_material() const;
	double get_speed_scale() const;
	void set_draw_order(const int64_t order);
	Particles2D::DrawOrder get_draw_order() const;
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_normal_map(const Ref<Texture> texture);
	Ref<Texture> get_normal_map() const;
	Rect2 capture_rect() const;
	void set_v_frames(const int64_t frames);
	int64_t get_v_frames() const;
	void set_h_frames(const int64_t frames);
	int64_t get_h_frames() const;
	void restart();

};

}

#endif