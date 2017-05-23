#include "RID.hpp"

#include <godot/godot_rid.h>

namespace godot {


RID::RID(Object *p)
{
	godot_rid_new_with_resource(&_godot_rid, (const godot_object *) p);
}

int32_t RID::get_rid() const
{
	return godot_rid_get_id(&_godot_rid);
}


}
