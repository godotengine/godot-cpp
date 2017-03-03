#ifndef RID_H
#define RID_H

#include <godot/godot_rid.h>

namespace godot {

class Object;

class RID {
	godot_rid _godot_rid;
public:

	RID(Object *p)
	{
		godot_rid_new(&_godot_rid, p);
	}

	int32_t get_rid() const
	{
		return godot_rid_get_rid(&_godot_rid);
	}

	~RID()
	{
		godot_rid_destroy(&_godot_rid);
	}
};

}

#endif // RID_H
