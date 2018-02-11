#ifndef GODOT_CPP_CURVE2D_HPP
#define GODOT_CPP_CURVE2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Resource.hpp>
namespace godot {


class Curve2D : public Resource {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Curve2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Curve2D *_new();

	// methods
	int64_t get_point_count() const;
	void add_point(const Vector2 position, const Vector2 in = Vector2(0, 0), const Vector2 out = Vector2(0, 0), const int64_t at_position = -1);
	void set_point_position(const int64_t idx, const Vector2 position);
	Vector2 get_point_position(const int64_t idx) const;
	void set_point_in(const int64_t idx, const Vector2 position);
	Vector2 get_point_in(const int64_t idx) const;
	void set_point_out(const int64_t idx, const Vector2 position);
	Vector2 get_point_out(const int64_t idx) const;
	void remove_point(const int64_t idx);
	void clear_points();
	Vector2 interpolate(const int64_t idx, const double t) const;
	Vector2 interpolatef(const double fofs) const;
	void set_bake_interval(const double distance);
	double get_bake_interval() const;
	double get_baked_length() const;
	Vector2 interpolate_baked(const double offset, const bool cubic = false) const;
	PoolVector2Array get_baked_points() const;
	PoolVector2Array tessellate(const int64_t max_stages = 5, const double tolerance_degrees = 4) const;
	Dictionary _get_data() const;
	void _set_data(const Dictionary arg0);

};

}

#endif