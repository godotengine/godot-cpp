#include <SplitContainer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <InputEvent.hpp>


namespace godot {


void *SplitContainer::___get_type_tag()
{
	return (void *) &SplitContainer::___get_type_tag;
}

void *SplitContainer::___get_base_type_tag()
{
	return (void *) &Container::___get_type_tag;
}

void SplitContainer::_gui_input(const Ref<InputEvent> arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SplitContainer", "_gui_input");
	}
	___godot_icall_void_Object(mb, (const Object *) this, arg0.ptr());
}

void SplitContainer::set_split_offset(const int64_t offset) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SplitContainer", "set_split_offset");
	}
	___godot_icall_void_int(mb, (const Object *) this, offset);
}

int64_t SplitContainer::get_split_offset() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SplitContainer", "get_split_offset");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

void SplitContainer::set_collapsed(const bool collapsed) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SplitContainer", "set_collapsed");
	}
	___godot_icall_void_bool(mb, (const Object *) this, collapsed);
}

bool SplitContainer::is_collapsed() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SplitContainer", "is_collapsed");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

void SplitContainer::set_dragger_visibility(const int64_t mode) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SplitContainer", "set_dragger_visibility");
	}
	___godot_icall_void_int(mb, (const Object *) this, mode);
}

SplitContainer::DraggerVisibility SplitContainer::get_dragger_visibility() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("SplitContainer", "get_dragger_visibility");
	}
	return (SplitContainer::DraggerVisibility) ___godot_icall_int(mb, (const Object *) this);
}

}