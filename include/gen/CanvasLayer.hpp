#ifndef GODOT_CPP_CANVASLAYER_HPP
#define GODOT_CPP_CANVASLAYER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node.hpp"
namespace godot {

class Object;
class Node;

class CanvasLayer : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "CanvasLayer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static CanvasLayer *_new();

	// methods
	void set_layer(const int64_t layer);
	int64_t get_layer() const;
	void set_transform(const Transform2D transform);
	Transform2D get_transform() const;
	void set_offset(const Vector2 offset);
	Vector2 get_offset() const;
	void set_rotation(const double radians);
	double get_rotation() const;
	void set_rotation_degrees(const double degrees);
	double get_rotation_degrees() const;
	void set_scale(const Vector2 scale);
	Vector2 get_scale() const;
	void set_custom_viewport(const Object *viewport);
	Node *get_custom_viewport() const;
	RID get_canvas() const;

};

}

#endif