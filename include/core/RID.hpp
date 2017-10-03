#ifndef RID_H
#define RID_H

#include <gdnative/rid.h>

namespace godot {

class Object;

class RID {
	godot_rid _godot_rid;
public:

	inline RID() {}

	RID(Object *p);

	int32_t get_rid() const;

};

}

#endif // RID_H
