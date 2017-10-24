#include "RID.hpp"

#include <gdnative/rid.h>

#include "GodotGlobal.hpp"

namespace godot {


RID::RID(Object *p)
{
	godot::api->godot_rid_new_with_resource(&_godot_rid, (const godot_object *) p);
}

int32_t RID::get_rid() const
{
	return godot::api->godot_rid_get_id(&_godot_rid);
}


}
