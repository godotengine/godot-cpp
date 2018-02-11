#include <PackedDataContainer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PackedDataContainer::___get_type_tag()
{
	return (void *) &PackedDataContainer::___get_type_tag;
}

void *PackedDataContainer::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

PackedDataContainer *PackedDataContainer::_new()
{
	return (PackedDataContainer *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"PackedDataContainer")());
}
void PackedDataContainer::_set_data(const PoolByteArray arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainer", "_set_data");
	}
	___godot_icall_void_PoolByteArray(mb, (const Object *) this, arg0);
}

PoolByteArray PackedDataContainer::_get_data() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainer", "_get_data");
	}
	return ___godot_icall_PoolByteArray(mb, (const Object *) this);
}

Variant PackedDataContainer::_iter_init(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainer", "_iter_init");
	}
	return ___godot_icall_Variant_Array(mb, (const Object *) this, arg0);
}

Variant PackedDataContainer::_iter_get(const Variant arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainer", "_iter_get");
	}
	return ___godot_icall_Variant_Variant(mb, (const Object *) this, arg0);
}

Variant PackedDataContainer::_iter_next(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainer", "_iter_next");
	}
	return ___godot_icall_Variant_Array(mb, (const Object *) this, arg0);
}

Error PackedDataContainer::pack(const Variant value) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainer", "pack");
	}
	return (Error) ___godot_icall_int_Variant(mb, (const Object *) this, value);
}

int64_t PackedDataContainer::size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainer", "size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

}