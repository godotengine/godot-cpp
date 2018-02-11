#ifndef GODOT_CPP_EDITORRESOURCEPREVIEWGENERATOR_HPP
#define GODOT_CPP_EDITORRESOURCEPREVIEWGENERATOR_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Reference.hpp>
namespace godot {

class Texture;
class Resource;

class EditorResourcePreviewGenerator : public Reference {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorResourcePreviewGenerator"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants


	static EditorResourcePreviewGenerator *_new();

	// methods
	bool handles(const String type);
	Ref<Texture> generate(const Ref<Resource> from);
	Ref<Texture> generate_from_path(const String path);

};

}

#endif