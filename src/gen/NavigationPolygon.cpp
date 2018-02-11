#include <NavigationPolygon.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *NavigationPolygon::___get_type_tag()
{
	return (void *) &NavigationPolygon::___get_type_tag;
}

void *NavigationPolygon::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

NavigationPolygon *NavigationPolygon::_new()
{
	return (NavigationPolygon *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"NavigationPolygon")());
}
void NavigationPolygon::set_vertices(const PoolVector2Array vertices) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "set_vertices");
	}
	___godot_icall_void_PoolVector2Array(mb, (const Object *) this, vertices);
}

PoolVector2Array NavigationPolygon::get_vertices() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "get_vertices");
	}
	return ___godot_icall_PoolVector2Array(mb, (const Object *) this);
}

void NavigationPolygon::add_polygon(const PoolIntArray polygon) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "add_polygon");
	}
	___godot_icall_void_PoolIntArray(mb, (const Object *) this, polygon);
}

int64_t NavigationPolygon::get_polygon_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "get_polygon_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

PoolIntArray NavigationPolygon::get_polygon(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "get_polygon");
	}
	return ___godot_icall_PoolIntArray_int(mb, (const Object *) this, idx);
}

void NavigationPolygon::clear_polygons() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "clear_polygons");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void NavigationPolygon::add_outline(const PoolVector2Array outline) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "add_outline");
	}
	___godot_icall_void_PoolVector2Array(mb, (const Object *) this, outline);
}

void NavigationPolygon::add_outline_at_index(const PoolVector2Array outline, const int64_t index) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "add_outline_at_index");
	}
	___godot_icall_void_PoolVector2Array_int(mb, (const Object *) this, outline, index);
}

int64_t NavigationPolygon::get_outline_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "get_outline_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void NavigationPolygon::set_outline(const int64_t idx, const PoolVector2Array outline) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "set_outline");
	}
	___godot_icall_void_int_PoolVector2Array(mb, (const Object *) this, idx, outline);
}

PoolVector2Array NavigationPolygon::get_outline(const int64_t idx) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "get_outline");
	}
	return ___godot_icall_PoolVector2Array_int(mb, (const Object *) this, idx);
}

void NavigationPolygon::remove_outline(const int64_t idx) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "remove_outline");
	}
	___godot_icall_void_int(mb, (const Object *) this, idx);
}

void NavigationPolygon::clear_outlines() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "clear_outlines");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void NavigationPolygon::make_polygons_from_outlines() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "make_polygons_from_outlines");
	}
	___godot_icall_void(mb, (const Object *) this);
}

void NavigationPolygon::_set_polygons(const Array polygons) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "_set_polygons");
	}
	___godot_icall_void_Array(mb, (const Object *) this, polygons);
}

Array NavigationPolygon::_get_polygons() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "_get_polygons");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

void NavigationPolygon::_set_outlines(const Array outlines) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "_set_outlines");
	}
	___godot_icall_void_Array(mb, (const Object *) this, outlines);
}

Array NavigationPolygon::_get_outlines() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("NavigationPolygon", "_get_outlines");
	}
	return ___godot_icall_Array(mb, (const Object *) this);
}

}