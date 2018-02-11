#include <TileSet.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>
#include <Texture.hpp>
#include <ShaderMaterial.hpp>
#include <Shape2D.hpp>
#include <NavigationPolygon.hpp>
#include <OccluderPolygon2D.hpp>


namespace godot {


void *TileSet::___get_type_tag()
{
	return (void *) &TileSet::___get_type_tag;
}

void *TileSet::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

TileSet *TileSet::_new()
{
	return (TileSet *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"TileSet")());
}
bool TileSet::_is_tile_bound(const int64_t drawn_id, const int64_t neighbor_id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "_is_tile_bound");
	}
	return ___godot_icall_bool_int_int(mb, (const Object *) this, drawn_id, neighbor_id);
}

Vector2 TileSet::_forward_subtile_selection(const int64_t autotile_id, const int64_t bitmask, const Object *tilemap, const Vector2 tile_location) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "_forward_subtile_selection");
	}
	return ___godot_icall_Vector2_int_int_Object_Vector2(mb, (const Object *) this, autotile_id, bitmask, tilemap, tile_location);
}

void TileSet::create_tile(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "create_tile");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

void TileSet::autotile_set_bitmask_mode(const int64_t id, const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "autotile_set_bitmask_mode");
	}
	___godot_icall_void_int_int(mb, (const Object *) this, id, mode);
}

TileSet::BitmaskMode TileSet::autotile_get_bitmask_mode(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "autotile_get_bitmask_mode");
	}
	return (TileSet::BitmaskMode) ___godot_icall_int_int(mb, (const Object *) this, id);
}

void TileSet::tile_set_name(const int64_t id, const String name) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_name");
	}
	___godot_icall_void_int_String(mb, (const Object *) this, id, name);
}

String TileSet::tile_get_name(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_name");
	}
	return ___godot_icall_String_int(mb, (const Object *) this, id);
}

void TileSet::tile_set_texture(const int64_t id, const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_texture");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, id, texture.ptr());
}

Ref<Texture> TileSet::tile_get_texture(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, id));
}

void TileSet::tile_set_normal_map(const int64_t id, const Ref<Texture> normal_map) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_normal_map");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, id, normal_map.ptr());
}

Ref<Texture> TileSet::tile_get_normal_map(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_normal_map");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, id));
}

void TileSet::tile_set_material(const int64_t id, const Ref<ShaderMaterial> material) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_material");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, id, material.ptr());
}

Ref<ShaderMaterial> TileSet::tile_get_material(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_material");
	}
	return Ref<ShaderMaterial>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, id));
}

void TileSet::tile_set_texture_offset(const int64_t id, const Vector2 texture_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_texture_offset");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, id, texture_offset);
}

Vector2 TileSet::tile_get_texture_offset(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_texture_offset");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, id);
}

void TileSet::tile_set_region(const int64_t id, const Rect2 region) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_region");
	}
	___godot_icall_void_int_Rect2(mb, (const Object *) this, id, region);
}

Rect2 TileSet::tile_get_region(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_region");
	}
	return ___godot_icall_Rect2_int(mb, (const Object *) this, id);
}

void TileSet::tile_set_shape(const int64_t id, const int64_t shape_id, const Ref<Shape2D> shape) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_shape");
	}
	___godot_icall_void_int_int_Object(mb, (const Object *) this, id, shape_id, shape.ptr());
}

Ref<Shape2D> TileSet::tile_get_shape(const int64_t id, const int64_t shape_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_shape");
	}
	return Ref<Shape2D>::__internal_constructor(___godot_icall_Object_int_int(mb, (const Object *) this, id, shape_id));
}

void TileSet::tile_set_shape_transform(const int64_t id, const int64_t shape_id, const Transform2D shape_transform) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_shape_transform");
	}
	___godot_icall_void_int_int_Transform2D(mb, (const Object *) this, id, shape_id, shape_transform);
}

Transform2D TileSet::tile_get_shape_transform(const int64_t id, const int64_t shape_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_shape_transform");
	}
	return ___godot_icall_Transform2D_int_int(mb, (const Object *) this, id, shape_id);
}

void TileSet::tile_set_shape_one_way(const int64_t id, const int64_t shape_id, const bool one_way) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_shape_one_way");
	}
	___godot_icall_void_int_int_bool(mb, (const Object *) this, id, shape_id, one_way);
}

bool TileSet::tile_get_shape_one_way(const int64_t id, const int64_t shape_id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_shape_one_way");
	}
	return ___godot_icall_bool_int_int(mb, (const Object *) this, id, shape_id);
}

void TileSet::tile_add_shape(const int64_t id, const Ref<Shape2D> shape, const Transform2D shape_transform, const bool one_way, const Vector2 autotile_coord) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_add_shape");
	}
	___godot_icall_void_int_Object_Transform2D_bool_Vector2(mb, (const Object *) this, id, shape.ptr(), shape_transform, one_way, autotile_coord);
}

int64_t TileSet::tile_get_shape_count(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_shape_count");
	}
	return ___godot_icall_int_int(mb, (const Object *) this, id);
}

void TileSet::tile_set_shapes(const int64_t id, const Array shapes) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_shapes");
	}
	___godot_icall_void_int_Array(mb, (const Object *) this, id, shapes);
}

Array TileSet::tile_get_shapes(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_shapes");
	}
	return ___godot_icall_Array_int(mb, (const Object *) this, id);
}

void TileSet::tile_set_navigation_polygon(const int64_t id, const Ref<NavigationPolygon> navigation_polygon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_navigation_polygon");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, id, navigation_polygon.ptr());
}

Ref<NavigationPolygon> TileSet::tile_get_navigation_polygon(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_navigation_polygon");
	}
	return Ref<NavigationPolygon>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, id));
}

void TileSet::tile_set_navigation_polygon_offset(const int64_t id, const Vector2 navigation_polygon_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_navigation_polygon_offset");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, id, navigation_polygon_offset);
}

Vector2 TileSet::tile_get_navigation_polygon_offset(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_navigation_polygon_offset");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, id);
}

void TileSet::tile_set_light_occluder(const int64_t id, const Ref<OccluderPolygon2D> light_occluder) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_light_occluder");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, id, light_occluder.ptr());
}

Ref<OccluderPolygon2D> TileSet::tile_get_light_occluder(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_light_occluder");
	}
	return Ref<OccluderPolygon2D>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, id));
}

void TileSet::tile_set_occluder_offset(const int64_t id, const Vector2 occluder_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_set_occluder_offset");
	}
	___godot_icall_void_int_Vector2(mb, (const Object *) this, id, occluder_offset);
}

Vector2 TileSet::tile_get_occluder_offset(const int64_t id) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "tile_get_occluder_offset");
	}
	return ___godot_icall_Vector2_int(mb, (const Object *) this, id);
}

void TileSet::remove_tile(const int64_t id) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "remove_tile");
	}
	___godot_icall_void_int(mb, (const Object *) this, id);
}

void TileSet::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

int64_t TileSet::get_last_unused_tile_id() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "get_last_unused_tile_id");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t TileSet::find_tile_by_name(const String name) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "find_tile_by_name");
	}
	return ___godot_icall_int_String(mb, (const Object *) this, name);
}

Array TileSet::get_tiles_ids() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TileSet", "get_tiles_ids");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}