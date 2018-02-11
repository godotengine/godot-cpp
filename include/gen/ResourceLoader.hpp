#ifndef GODOT_CPP_RESOURCELOADER_HPP
#define GODOT_CPP_RESOURCELOADER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {

class ResourceInteractiveLoader;
class Resource;

class ResourceLoader : public Object {
	static ResourceLoader *_singleton;

	ResourceLoader();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline ResourceLoader *get_singleton()
	{
		if (!ResourceLoader::_singleton) {
			ResourceLoader::_singleton = new ResourceLoader;
		}
		return ResourceLoader::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "ResourceLoader"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	Ref<ResourceInteractiveLoader> load_interactive(const String path, const String type_hint = "");
	Ref<Resource> load(const String path, const String type_hint = "", const bool p_no_cache = false);
	PoolStringArray get_recognized_extensions_for_type(const String type);
	void set_abort_on_missing_resources(const bool abort);
	PoolStringArray get_dependencies(const String path);
	bool has(const String path);

};

}

#endif