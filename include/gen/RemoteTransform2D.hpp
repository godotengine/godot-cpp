#ifndef GODOT_CPP_REMOTETRANSFORM2D_HPP
#define GODOT_CPP_REMOTETRANSFORM2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Node2D.hpp>
namespace godot {


class RemoteTransform2D : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "RemoteTransform2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static RemoteTransform2D *_new();

	// methods
	void set_remote_node(const NodePath path);
	NodePath get_remote_node() const;
	void set_use_global_coordinates(const bool use_global_coordinates);
	bool get_use_global_coordinates() const;
	void set_update_position(const bool update_remote_position);
	bool get_update_position() const;
	void set_update_rotation(const bool update_remote_rotation);
	bool get_update_rotation() const;
	void set_update_scale(const bool update_remote_scale);
	bool get_update_scale() const;

};

}

#endif