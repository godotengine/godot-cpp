#ifndef RID_H
#define RID_H

#if defined(_WIN32)
#  ifdef _GD_CPP_CORE_API_IMPL
#    define GD_CPP_CORE_API __declspec(dllexport)
#  else
#    define GD_CPP_CORE_API __declspec(dllimport)
#  endif
#else
#  define GD_CPP_CORE_API
#endif

#include <godot/godot_rid.h>

namespace godot {

class Object;

class GD_CPP_CORE_API RID {
	godot_rid _godot_rid;
public:

	inline RID() {}

	RID(Object *p);

	int32_t get_rid() const;

	~RID();
};

}

#endif // RID_H
