#ifndef GODOT_CPP_SPATIAL_HPP
#define GODOT_CPP_SPATIAL_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node.hpp"
namespace godot {

class Spatial;
class World;
class SpatialGizmo;

class Spatial : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Spatial"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants
	const static int NOTIFICATION_ENTER_WORLD = 41;
	const static int NOTIFICATION_VISIBILITY_CHANGED = 43;
	const static int NOTIFICATION_TRANSFORM_CHANGED = 29;
	const static int NOTIFICATION_EXIT_WORLD = 42;


	static Spatial *_new();

	// methods
	void set_transform(const Transform local);
	Transform get_transform() const;
	void set_translation(const Vector3 translation);
	Vector3 get_translation() const;
	void set_rotation(const Vector3 euler);
	Vector3 get_rotation() const;
	void set_rotation_degrees(const Vector3 euler_degrees);
	Vector3 get_rotation_degrees() const;
	void set_scale(const Vector3 scale);
	Vector3 get_scale() const;
	void set_global_transform(const Transform global);
	Transform get_global_transform() const;
	Spatial *get_parent_spatial() const;
	void set_ignore_transform_notification(const bool enabled);
	void set_as_toplevel(const bool enable);
	bool is_set_as_toplevel() const;
	Ref<World> get_world() const;
	void _update_gizmo();
	void update_gizmo();
	void set_gizmo(const Ref<SpatialGizmo> gizmo);
	Ref<SpatialGizmo> get_gizmo() const;
	void set_visible(const bool visible);
	bool is_visible() const;
	bool is_visible_in_tree() const;
	void show();
	void hide();
	void set_notify_local_transform(const bool enable);
	bool is_local_transform_notification_enabled() const;
	void set_notify_transform(const bool enable);
	bool is_transform_notification_enabled() const;
	void rotate(const Vector3 axis, const double angle);
	void global_rotate(const Vector3 axis, const double angle);
	void global_scale(const Vector3 scale);
	void global_translate(const Vector3 offset);
	void rotate_object_local(const Vector3 axis, const double angle);
	void scale_object_local(const Vector3 scale);
	void translate_object_local(const Vector3 offset);
	void rotate_x(const double angle);
	void rotate_y(const double angle);
	void rotate_z(const double angle);
	void translate(const Vector3 offset);
	void orthonormalize();
	void set_identity();
	void look_at(const Vector3 target, const Vector3 up);
	void look_at_from_position(const Vector3 position, const Vector3 target, const Vector3 up);
	Vector3 to_local(const Vector3 global_point) const;
	Vector3 to_global(const Vector3 local_point) const;

};

}

#endif