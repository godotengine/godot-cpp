#ifndef GODOT_CPP_NODE2D_HPP
#define GODOT_CPP_NODE2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "CanvasItem.hpp"
namespace godot {

class Object;

class Node2D : public CanvasItem {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Node2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Node2D *_new();

	// methods
	void set_position(const Vector2 position);
	void set_rotation(const double radians);
	void set_rotation_degrees(const double degrees);
	void set_scale(const Vector2 scale);
	Vector2 get_position() const;
	double get_rotation() const;
	double get_rotation_degrees() const;
	Vector2 get_scale() const;
	void rotate(const double radians);
	void move_local_x(const double delta, const bool scaled = false);
	void move_local_y(const double delta, const bool scaled = false);
	void translate(const Vector2 offset);
	void global_translate(const Vector2 offset);
	void apply_scale(const Vector2 ratio);
	void set_global_position(const Vector2 position);
	Vector2 get_global_position() const;
	void set_global_rotation(const double radians);
	double get_global_rotation() const;
	void set_global_rotation_degrees(const double degrees);
	double get_global_rotation_degrees() const;
	void set_global_scale(const Vector2 scale);
	Vector2 get_global_scale() const;
	void set_transform(const Transform2D xform);
	void set_global_transform(const Transform2D xform);
	void look_at(const Vector2 point);
	double get_angle_to(const Vector2 point) const;
	Vector2 to_local(const Vector2 global_point) const;
	Vector2 to_global(const Vector2 local_point) const;
	void set_z_index(const int64_t z_index);
	int64_t get_z_index() const;
	void set_z_as_relative(const bool enable);
	bool is_z_relative() const;
	Transform2D get_relative_transform_to_parent(const Object *parent) const;

};

}

#endif