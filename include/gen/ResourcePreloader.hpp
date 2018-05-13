#ifndef GODOT_CPP_RESOURCEPRELOADER_HPP
#define GODOT_CPP_RESOURCEPRELOADER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node.hpp"
namespace godot {

class Resource;

class ResourcePreloader : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "ResourcePreloader"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static ResourcePreloader *_new();

	// methods
	void _set_resources(const Array arg0);
	Array _get_resources() const;
	void add_resource(const String name, const Ref<Resource> resource);
	void remove_resource(const String name);
	void rename_resource(const String name, const String newname);
	bool has_resource(const String name) const;
	Ref<Resource> get_resource(const String name) const;
	PoolStringArray get_resource_list() const;

};

}

#endif