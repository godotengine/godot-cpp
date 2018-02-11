#ifndef GODOT_CPP_BAKEDLIGHTMAP_HPP
#define GODOT_CPP_BAKEDLIGHTMAP_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <BakedLightmap.hpp>

#include <VisualInstance.hpp>
namespace godot {

class BakedLightmapData;
class Object;

class BakedLightmap : public VisualInstance {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "BakedLightmap"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum BakeQuality {
		BAKE_QUALITY_HIGH = 2,
		BAKE_QUALITY_LOW = 0,
		BAKE_QUALITY_MEDIUM = 1,
	};
	enum BakeError {
		BAKE_ERROR_OK = 0,
		BAKE_ERROR_USER_ABORTED = 4,
		BAKE_ERROR_NO_MESHES = 2,
		BAKE_ERROR_CANT_CREATE_IMAGE = 3,
		BAKE_ERROR_NO_SAVE_PATH = 1,
	};
	enum BakeMode {
		BAKE_MODE_CONE_TRACE = 0,
		BAKE_MODE_RAY_TRACE = 1,
	};

	// constants


	static BakedLightmap *_new();

	// methods
	void set_light_data(const Ref<BakedLightmapData> data);
	Ref<BakedLightmapData> get_light_data() const;
	void set_bake_cell_size(const double bake_cell_size);
	double get_bake_cell_size() const;
	void set_capture_cell_size(const double capture_cell_size);
	double get_capture_cell_size() const;
	void set_bake_quality(const int64_t bake_quality);
	BakedLightmap::BakeQuality get_bake_quality() const;
	void set_bake_mode(const int64_t bake_mode);
	BakedLightmap::BakeMode get_bake_mode() const;
	void set_extents(const Vector3 extents);
	Vector3 get_extents() const;
	void set_propagation(const double propagation);
	double get_propagation() const;
	void set_energy(const double energy);
	double get_energy() const;
	void set_hdr(const bool hdr);
	bool is_hdr() const;
	void set_image_path(const String image_path);
	String get_image_path() const;
	BakedLightmap::BakeError bake(const Object *from_node = nullptr, const bool create_visual_debug = false);
	void debug_bake();

};

}

#endif