#ifndef WRAPPED_HPP
#define WRAPPED_HPP

#include <gdnative/gdnative.h>

namespace godot {

class _Wrapped {
public:
	godot_object *_owner;
	const void *_type_tag;
};

}

#endif // WRAPPED_HPP
