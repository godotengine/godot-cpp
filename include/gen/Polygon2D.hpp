#ifndef GODOT_CPP_POLYGON2D_HPP
#define GODOT_CPP_POLYGON2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node2D.hpp"
namespace godot {

class Texture;

class Polygon2D : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Polygon2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Polygon2D *_new();

	// methods
	void set_polygon(const PoolVector2Array polygon);
	PoolVector2Array get_polygon() const;
	void set_uv(const PoolVector2Array uv);
	PoolVector2Array get_uv() const;
	void set_color(const Color color);
	Color get_color() const;
	void set_splits(const PoolIntArray splits);
	PoolIntArray get_splits() const;
	void set_vertex_colors(const PoolColorArray vertex_colors);
	PoolColorArray get_vertex_colors() const;
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_texture_offset(const Vector2 texture_offset);
	Vector2 get_texture_offset() const;
	void set_texture_rotation(const double texture_rotation);
	double get_texture_rotation() const;
	void set_texture_rotation_degrees(const double texture_rotation);
	double get_texture_rotation_degrees() const;
	void set_texture_scale(const Vector2 texture_scale);
	Vector2 get_texture_scale() const;
	void set_invert(const bool invert);
	bool get_invert() const;
	void set_antialiased(const bool antialiased);
	bool get_antialiased() const;
	void set_invert_border(const double invert_border);
	double get_invert_border() const;
	void set_offset(const Vector2 offset);
	Vector2 get_offset() const;
	void add_bone(const NodePath path, const PoolRealArray weights);
	int64_t get_bone_count() const;
	NodePath get_bone_path(const int64_t index) const;
	PoolRealArray get_bone_weights(const int64_t index) const;
	void erase_bone(const int64_t index);
	void clear_bones();
	void set_bone_path(const int64_t index, const NodePath path);
	void set_bone_weights(const int64_t index, const PoolRealArray weights);
	void set_skeleton(const NodePath skeleton);
	NodePath get_skeleton() const;
	void _set_bones(const Array bones);
	Array _get_bones() const;

};

}

#endif