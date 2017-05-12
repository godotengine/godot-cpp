#include "RID.hpp"

#include <godot/godot_rid.h>

namespace godot {


RID::RID(Object *p)
{
	godot_rid_new(&_godot_rid, p);
}

int32_t RID::get_rid() const
{
	return godot_rid_get_rid(&_godot_rid);
}

RID::~RID()
{
	godot_rid_destroy(&_godot_rid);
}


}
