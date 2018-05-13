#ifndef GODOT_CPP_LINE2D_HPP
#define GODOT_CPP_LINE2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include "Line2D.hpp"

#include "Node2D.hpp"
namespace godot {

class Gradient;
class Texture;

class Line2D : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Line2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum LineTextureMode {
		LINE_TEXTURE_TILE = 1,
		LINE_TEXTURE_NONE = 0,
	};
	enum LineCapMode {
		LINE_CAP_NONE = 0,
		LINE_CAP_ROUND = 2,
		LINE_CAP_BOX = 1,
	};
	enum LineJointMode {
		LINE_JOINT_ROUND = 2,
		LINE_JOINT_BEVEL = 1,
		LINE_JOINT_SHARP = 0,
	};

	// constants


	static Line2D *_new();

	// methods
	void set_points(const PoolVector2Array points);
	PoolVector2Array get_points() const;
	void set_point_position(const int64_t i, const Vector2 position);
	Vector2 get_point_position(const int64_t i) const;
	int64_t get_point_count() const;
	void add_point(const Vector2 position);
	void remove_point(const int64_t i);
	void set_width(const double width);
	double get_width() const;
	void set_default_color(const Color color);
	Color get_default_color() const;
	void set_gradient(const Ref<Gradient> color);
	Ref<Gradient> get_gradient() const;
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_texture_mode(const int64_t mode);
	Line2D::LineTextureMode get_texture_mode() const;
	void set_joint_mode(const int64_t mode);
	Line2D::LineJointMode get_joint_mode() const;
	void set_begin_cap_mode(const int64_t mode);
	Line2D::LineCapMode get_begin_cap_mode() const;
	void set_end_cap_mode(const int64_t mode);
	Line2D::LineCapMode get_end_cap_mode() const;
	void set_sharp_limit(const double limit);
	double get_sharp_limit() const;
	void set_round_precision(const int64_t precision);
	int64_t get_round_precision() const;
	void _gradient_changed();

};

}

#endif