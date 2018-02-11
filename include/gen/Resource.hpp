#ifndef GODOT_CPP_RESOURCE_HPP
#define GODOT_CPP_RESOURCE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class Node;
class Resource;

class Resource : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Resource"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static Resource *_new();

	// methods
	void _setup_local_to_scene();
	void set_path(const String path);
	void take_over_path(const String path);
	String get_path() const;
	void set_name(const String name);
	String get_name() const;
	RID get_rid() const;
	void set_local_to_scene(const bool enable);
	bool is_local_to_scene() const;
	Node *get_local_scene() const;
	void setup_local_to_scene();
	Ref<Resource> duplicate(const bool subresources = false) const;

};

}

#endif