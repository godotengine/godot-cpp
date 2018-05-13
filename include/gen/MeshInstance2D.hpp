#ifndef GODOT_CPP_MESHINSTANCE2D_HPP
#define GODOT_CPP_MESHINSTANCE2D_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node2D.hpp"
namespace godot {

class Mesh;
class Texture;

class MeshInstance2D : public Node2D {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "MeshInstance2D"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static MeshInstance2D *_new();

	// methods
	void set_mesh(const Ref<Mesh> mesh);
	Ref<Mesh> get_mesh() const;
	void set_texture(const Ref<Texture> texture);
	Ref<Texture> get_texture() const;
	void set_normal_map(const Ref<Texture> normal_map);
	Ref<Texture> get_normal_map() const;

};

}

#endif