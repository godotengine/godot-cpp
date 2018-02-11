#include <PackedDataContainerRef.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *PackedDataContainerRef::___get_type_tag()
{
	return (void *) &PackedDataContainerRef::___get_type_tag;
}

void *PackedDataContainerRef::___get_base_type_tag()
{
	return (void *) &Reference::___get_type_tag;
}

int64_t PackedDataContainerRef::size() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainerRef", "size");
	}
	return ___godot_icall_int(mb, (const Object *) this);
}

Variant PackedDataContainerRef::_iter_init(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainerRef", "_iter_init");
	}
	return ___godot_icall_Variant_Array(mb, (const Object *) this, arg0);
}

Variant PackedDataContainerRef::_iter_get(const Variant arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainerRef", "_iter_get");
	}
	return ___godot_icall_Variant_Variant(mb, (const Object *) this, arg0);
}

Variant PackedDataContainerRef::_iter_next(const Array arg0) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainerRef", "_iter_next");
	}
	return ___godot_icall_Variant_Array(mb, (const Object *) this, arg0);
}

bool PackedDataContainerRef::_is_dictionary() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("PackedDataContainerRef", "_is_dictionary");
	}
	return ___godot_icall_bool(mb, (const Object *) this);
}

}