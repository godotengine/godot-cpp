#include <CubeMap.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Image.hpp>


namespace godot {


void *CubeMap::___get_type_tag()
{
	return (void *) &CubeMap::___get_type_tag;
}

void *CubeMap::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

CubeMap *CubeMap::_new()
{
	return (CubeMap *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"CubeMap")());
}
int64_t CubeMap::get_width() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMap", "get_width");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

int64_t CubeMap::get_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMap", "get_height");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void CubeMap::set_flags(const int64_t flags) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMap", "set_flags");
	}
	___godot_icall_void_int(mb, (const Object *) this, flags);
}

int64_t CubeMap::get_flags() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMap", "get_flags");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void CubeMap::set_side(const int64_t side, const Ref<Image> image) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMap", "set_side");
	}
	___godot_icall_void_int_Object(mb, (const Object *) this, side, image.ptr());
}

Ref<Image> CubeMap::get_side(const int64_t side) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMap", "get_side");
	}
	return Ref<Image>::__internal_constructor(___godot_icall_Object_int(mb, (const Object *) this, side));
}

void CubeMap::set_storage(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMap", "set_storage");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

CubeMap::Storage CubeMap::get_storage() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMap", "get_storage");
	}
	return (CubeMap::Storage) ___godot_icall_int(mb, (const Object *) this);
}

void CubeMap::set_lossy_storage_quality(const double quality) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMap", "set_lossy_storage_quality");
	}
	___godot_icall_void_float(mb, (const Object *) this, quality);
}

double CubeMap::get_lossy_storage_quality() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("CubeMap", "get_lossy_storage_quality");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}