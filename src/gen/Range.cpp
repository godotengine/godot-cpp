#include <Range.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Object.hpp>


namespace godot {


void *Range::___get_type_tag()
{
	return (void *) &Range::___get_type_tag;
}

void *Range::___get_base_type_tag()
{
	return (void *) &Control::___get_type_tag;
}

double Range::get_value() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "get_value");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Range::get_min() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "get_min");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Range::get_max() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "get_max");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Range::get_step() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "get_step");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Range::get_page() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "get_page");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

double Range::get_as_ratio() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "get_as_ratio");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

void Range::set_value(const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "set_value");
	}
	___godot_icall_void_float(mb, (const Object *) this, value);
}

void Range::set_min(const double minimum) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "set_min");
	}
	___godot_icall_void_float(mb, (const Object *) this, minimum);
}

void Range::set_max(const double maximum) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "set_max");
	}
	___godot_icall_void_float(mb, (const Object *) this, maximum);
}

void Range::set_step(const double step) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "set_step");
	}
	___godot_icall_void_float(mb, (const Object *) this, step);
}

void Range::set_page(const double pagesize) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "set_page");
	}
	___godot_icall_void_float(mb, (const Object *) this, pagesize);
}

void Range::set_as_ratio(const double value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "set_as_ratio");
	}
	___godot_icall_void_float(mb, (const Object *) this, value);
}

void Range::set_use_rounded_values(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "set_use_rounded_values");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Range::is_using_rounded_values() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "is_using_rounded_values");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Range::set_exp_ratio(const bool enabled) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "set_exp_ratio");
	}
	___godot_icall_void_bool(mb, (const Object *) this, enabled);
}

bool Range::is_ratio_exp() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "is_ratio_exp");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void Range::share(const Object *with) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "share");
	}
	___godot_icall_void_Object(mb, (const Object *) this, with);
}

void Range::unshare() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("Range", "unshare");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}