#include <Light.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *Light::___get_type_tag()
{
	return (void *) &Light::___get_type_tag;
}

void *Light::___get_base_type_tag()
{
	return (void *) &VisualInstance::___get_type_tag;
}

void Light::set_editor_only(const bool editor_only) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "set_editor_only");
	}
	___godot_icall_void_bool(mb, (const Object *) this, editor_only);
}

bool Light::is_editor_only() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "is_editor_only");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Light::set_param(const int64_t param, const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "set_param");
	}
	___godot_icall_void_int_float(mb, (const Object *) this, param, value);
}

double Light::get_param(const int64_t param) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "get_param");
	}
	return ___godot_icall_float_int(mb, (const Object *) this, param);
}

void Light::set_shadow(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "set_shadow");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Light::has_shadow() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "has_shadow");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Light::set_negative(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "set_negative");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Light::is_negative() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "is_negative");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Light::set_cull_mask(const int64_t cull_mask) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "set_cull_mask");
	}
	___godot_icall_void_int(mb, (const Object *) this, cull_mask);
}

int64_t Light::get_cull_mask() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "get_cull_mask");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void Light::set_color(const Color color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "set_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, color);
}

Color Light::get_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "get_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void Light::set_shadow_reverse_cull_face(const bool enable) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "set_shadow_reverse_cull_face");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enable);
}

bool Light::get_shadow_reverse_cull_face() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "get_shadow_reverse_cull_face");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Light::set_shadow_color(const Color shadow_color) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "set_shadow_color");
	}
	___godot_icall_void_Color(mb, (const Object *) this, shadow_color);
}

Color Light::get_shadow_color() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "get_shadow_color");
	}
	return ___godot_icall_Color(mb, (const Object *) this);
}

void Light::set_bake_mode(const int64_t bake_mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "set_bake_mode");
	}
	___godot_icall_void_int(mb, (const Object *) this, bake_mode);
}

Light::BakeMode Light::get_bake_mode() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Light", "get_bake_mode");
	}
	return (Light::BakeMode) ___godot_icall_int(mb, (const Object *) this);
}

}