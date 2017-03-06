#ifndef RID_H
#define RID_H

#include <godot/godot_rid.h>

namespace godot {

class Object;

class RID {
	godot_rid _godot_rid;
public:

	RID(Object *p);

	int32_t get_rid() const;

	~RID();
};

}

#endif // RID_H
