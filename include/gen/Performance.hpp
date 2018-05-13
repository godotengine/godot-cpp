#ifndef GODOT_CPP_PERFORMANCE_HPP
#define GODOT_CPP_PERFORMANCE_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "Object.hpp"
namespace godot {


class Performance : public Object {
	static Performance *_singleton;

	Performance();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline Performance *get_singleton()
	{
		if (!Performance::_singleton) {
			Performance::_singleton = new Performance;
		}
		return Performance::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "Performance"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum Monitor {
		RENDER_SHADER_CHANGES_IN_FRAME = 14,
		OBJECT_COUNT = 8,
		PHYSICS_3D_COLLISION_PAIRS = 25,
		TIME_PHYSICS_PROCESS = 2,
		OBJECT_NODE_COUNT = 10,
		PHYSICS_3D_ISLAND_COUNT = 26,
		MEMORY_DYNAMIC_MAX = 6,
		PHYSICS_2D_ISLAND_COUNT = 23,
		RENDER_OBJECTS_IN_FRAME = 11,
		PHYSICS_2D_COLLISION_PAIRS = 22,
		PHYSICS_3D_ACTIVE_OBJECTS = 24,
		MEMORY_DYNAMIC = 4,
		RENDER_DRAW_CALLS_IN_FRAME = 16,
		TIME_FPS = 0,
		MONITOR_MAX = 27,
		RENDER_VERTEX_MEM_USED = 19,
		RENDER_VIDEO_MEM_USED = 17,
		RENDER_TEXTURE_MEM_USED = 18,
		MEMORY_STATIC = 3,
		RENDER_MATERIAL_CHANGES_IN_FRAME = 13,
		TIME_PROCESS = 1,
		RENDER_USAGE_VIDEO_MEM_TOTAL = 20,
		MEMORY_MESSAGE_BUFFER_MAX = 7,
		PHYSICS_2D_ACTIVE_OBJECTS = 21,
		MEMORY_STATIC_MAX = 5,
		RENDER_SURFACE_CHANGES_IN_FRAME = 15,
		OBJECT_RESOURCE_COUNT = 9,
		RENDER_VERTICES_IN_FRAME = 12,
	};

	// constants

	// methods
	double get_monitor(const int64_t monitor) const;

};

}

#endif