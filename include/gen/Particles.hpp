#ifndef GODOT_CPP_PARTICLES_HPP
#define GODOT_CPP_PARTICLES_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <Particles.hpp>

#include <GeometryInstance.hpp>
namespace godot {

class Material;
class Mesh;

class Particles : public GeometryInstance {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Particles"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum DrawOrder {
		DRAW_ORDER_LIFETIME = 1,
		DRAW_ORDER_INDEX = 0,
		DRAW_ORDER_VIEW_DEPTH = 2,
	};

	// constants
	const static int MAX_DRAW_PASSES = 4;


	static Particles *_new();

	// methods
	void set_emitting(const bool emitting);
	void set_amount(const int64_t amount);
	void set_lifetime(const double secs);
	void set_one_shot(const bool enable);
	void set_pre_process_time(const double secs);
	void set_explosiveness_ratio(const double ratio);
	void set_randomness_ratio(const double ratio);
	void set_visibility_aabb(const AABB aabb);
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
	AABB get_visibility_aabb() const;
	bool get_use_local_coordinates() const;
	int64_t get_fixed_fps() const;
	bool get_fractional_delta() const;
	Ref<Material> get_process_material() const;
	double get_speed_scale() const;
	void set_draw_order(const int64_t order);
	Particles::DrawOrder get_draw_order() const;
	void set_draw_passes(const int64_t passes);
	void set_draw_pass_mesh(const int64_t pass, const Ref<Mesh> mesh);
	int64_t get_draw_passes() const;
	Ref<Mesh> get_draw_pass_mesh(const int64_t pass) const;
	void restart();
	AABB capture_aabb() const;

};

}

#endif