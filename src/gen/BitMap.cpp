#include <BitMap.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Image.hpp>


namespace godot {


void *BitMap::___get_type_tag()
{
	return (void *) &BitMap::___get_type_tag;
}

void *BitMap::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

BitMap *BitMap::_new()
{
	return (BitMap *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"BitMap")());
}
void BitMap::create(const Vector2 size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitMap", "create");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, size);
}

void BitMap::create_from_image_alpha(const Ref<Image> image, const double threshold) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitMap", "create_from_image_alpha");
	}
	___godot_icall_void_Object_float(mb, (const Object *) this, image.ptr(), threshold);
}

void BitMap::set_bit(const Vector2 position, const bool bit) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitMap", "set_bit");
	}
	___godot_icall_void_Vector2_bool(mb, (const Object *) this, position, bit);
}

bool BitMap::get_bit(const Vector2 position) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitMap", "get_bit");
	}
	return ___godot_icall_bool_Vector2(mb, (const Object *) this, position);
}

void BitMap::set_bit_rect(const Rect2 p_rect, const bool bit) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitMap", "set_bit_rect");
	}
	___godot_icall_void_Rect2_bool(mb, (const Object *) this, p_rect, bit);
}

int64_t BitMap::get_true_bit_count() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitMap", "get_true_bit_count");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Vector2 BitMap::get_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitMap", "get_size");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void BitMap::_set_data(const Dictionary arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitMap", "_set_data");
	}
	___godot_icall_void_Dictionary(mb, (const Object *) this, arg0);
}

Dictionary BitMap::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("BitMap", "_get_data");
	}
	return ___godot_icall_Dictionary(mb, (const Object *) this);
}

}