#ifndef GODOT_CPP_EDITORRESOURCEPREVIEW_HPP
#define GODOT_CPP_EDITORRESOURCEPREVIEW_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Node.hpp"
namespace godot {

class Texture;
class Object;
class Resource;
class EditorResourcePreviewGenerator;

class EditorResourcePreview : public Node {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "EditorResourcePreview"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void _preview_ready(const String arg0, const Ref<Texture> arg1, const int64_t arg2, const String arg3, const Variant arg4);
	void queue_resource_preview(const String path, const Object *receiver, const String receiver_func, const Variant userdata);
	void queue_edited_resource_preview(const Ref<Resource> resource, const Object *receiver, const String receiver_func, const Variant userdata);
	void add_preview_generator(const Ref<EditorResourcePreviewGenerator> generator);
	void remove_preview_generator(const Ref<EditorResourcePreviewGenerator> generator);
	void check_for_invalidation(const String path);

};

}

#endif