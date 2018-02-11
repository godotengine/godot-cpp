#include <Light2D.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Texture.hpp>


namespace godot {


void *Light2D::___get_type_tag()
{
	return (void *) &Light2D::___get_type_tag;
}

void *Light2D::___get_base_type_tag()
{
	return (void *) &Node2D::___get_type_tag;
}

Light2D *Light2D::_new()
{
	return (Light2D *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"Light2D")());
}
void Light2D::set_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Light2D::is_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "is_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Light2D::set_editor_only(const bool editor_only) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_editor_only");
	}
	___godot_icall_void_bool(mb, (const Object *) this, editor_only);
}

bool Light2D::is_editor_only() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "is_editor_only");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Light2D::set_texture(const Ref<Texture> texture) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_texture");
	}
	___godot_icall_void_Object(mb, (const Object *) this, texture.ptr());
}

Ref<Texture> Light2D::get_texture() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_texture");
	}
	return Ref<Texture>::__internal_constructor(___godot_icall_Object(mb, (const Object *) this));
}

void Light2D::set_texture_offset(const Vector2 texture_offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_texture_offset");
	}
	___godot_icall_void_Vector2(mb, (const Object *) this, texture_offset);
}

Vector2 Light2D::get_texture_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_texture_offset");
	}
	return ___godot_icall_Vector2(mb, (const Object *) this);
}

void Light2D::set_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color Light2D::get_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void Light2D::set_height(const double height) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_height");
	}
	___godot_icall_void_float(mb, (const Object *) this, height);
}

double Light2D::get_height() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_height");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Light2D::set_energy(const double energy) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_energy");
	}
	___godot_icall_void_float(mb, (const Object *) this, energy);
}

double Light2D::get_energy() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_energy");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Light2D::set_texture_scale(const double texture_scale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_texture_scale");
	}
	___godot_icall_void_float(mb, (const Object *) this, texture_scale);
}

double Light2D::get_texture_scale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_texture_scale");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Light2D::set_z_range_min(const int64_t z) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_z_range_min");
	}
	___godot_icall_void_int(mb, (const Object *) this, z);
}

int64_t Light2D::get_z_range_min() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_z_range_min");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Light2D::set_z_range_max(const int64_t z) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_z_range_max");
	}
	___godot_icall_void_int(mb, (const Object *) this, z);
}

int64_t Light2D::get_z_range_max() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_z_range_max");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Light2D::set_layer_range_min(const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_layer_range_min");
	}
	___godot_icall_void_int(mb, (const Object *) this, layer);
}

int64_t Light2D::get_layer_range_min() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_layer_range_min");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Light2D::set_layer_range_max(const int64_t layer) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_layer_range_max");
	}
	___godot_icall_void_int(mb, (const Object *) this, layer);
}

int64_t Light2D::get_layer_range_max() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_layer_range_max");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Light2D::set_item_cull_mask(const int64_t item_cull_mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_item_cull_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, item_cull_mask);
}

int64_t Light2D::get_item_cull_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_item_cull_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Light2D::set_item_shadow_cull_mask(const int64_t item_shadow_cull_mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_item_shadow_cull_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, item_shadow_cull_mask);
}

int64_t Light2D::get_item_shadow_cull_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_item_shadow_cull_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Light2D::set_mode(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

Light2D::Mode Light2D::get_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_mode");
	}
	return (Light2D::Mode) ___godot_icall_int(mb, (const Object *) this);
}

void Light2D::set_shadow_enabled(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_shadow_enabled");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Light2D::is_shadow_enabled() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "is_shadow_enabled");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Light2D::set_shadow_buffer_size(const int64_t size) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_shadow_buffer_size");
	}
	___godot_icall_void_int(mb, (const Object *) this, size);
}

int64_t Light2D::get_shadow_buffer_size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_shadow_buffer_size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Light2D::set_shadow_smooth(const double smooth) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_shadow_smooth");
	}
	___godot_icall_void_float(mb, (const Object *) this, smooth);
}

double Light2D::get_shadow_smooth() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_shadow_smooth");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Light2D::set_shadow_gradient_length(const double multiplier) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_shadow_gradient_length");
	}
	___godot_icall_void_float(mb, (const Object *) this, multiplier);
}

double Light2D::get_shadow_gradient_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_shadow_gradient_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Light2D::set_shadow_filter(const int64_t filter) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_shadow_filter");
	}
	___godot_icall_void_int(mb, (const Object *) this, filter);
}

Light2D::ShadowFilter Light2D::get_shadow_filter() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_shadow_filter");
	}
	return (Light2D::ShadowFilter) ___godot_icall_int(mb, (const Object *) this);
}

void Light2D::set_shadow_color(const Color shadow_color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "set_shadow_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, shadow_color);
}

Color Light2D::get_shadow_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light2D", "get_shadow_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

}