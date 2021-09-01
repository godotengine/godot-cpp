#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/variant/vector3i.hpp>
#include <godot_cpp/variant/string.hpp>

namespace godot {

void Vector3i::set_axis(int p_axis, int32_t p_value) {
	ERR_FAIL_INDEX(p_axis, 3);
	coord[p_axis] = p_value;
}

int32_t Vector3i::get_axis(int p_axis) const {
	ERR_FAIL_INDEX_V(p_axis, 3, 0);
	return operator[](p_axis);
}

int Vector3i::min_axis() const {
	return x < y ? (x < z ? 0 : 2) : (y < z ? 1 : 2);
}

int Vector3i::max_axis() const {
	return x < y ? (y < z ? 2 : 1) : (x < z ? 2 : 0);
}

Vector3i::operator String() const {
	return (String::num(x, 0) + ", " + String::num(y, 0) + ", " + String::num(z, 5));
}

} // namespace godot
