#ifndef RECT2_H
#define RECT2_H

#include "Vector2.hpp"

#include <cmath>

#include <cstdlib>

namespace godot {

class String;

typedef Vector2 Size2;
typedef Vector2 Point2;

struct Transform2D;

struct Rect2 {

	Point2 pos;
	Size2 size;

	inline const Vector2 &get_pos() const { return pos; }
	inline void set_pos(const Vector2 &p_pos) { pos = p_pos; }
	inline const Vector2 &get_size() const { return size; }
	inline void set_size(const Vector2 &p_size) { size = p_size; }

	inline real_t get_area() const { return size.width * size.height; }

	inline bool intersects(const Rect2 &p_rect) const {
		if (pos.x >= (p_rect.pos.x + p_rect.size.width))
			return false;
		if ((pos.x + size.width) <= p_rect.pos.x)
			return false;
		if (pos.y >= (p_rect.pos.y + p_rect.size.height))
			return false;
		if ((pos.y + size.height) <= p_rect.pos.y)
			return false;

		return true;
	}

	real_t distance_to(const Vector2 &p_point) const;

	bool intersects_transformed(const Transform2D &p_xform, const Rect2 &p_rect) const;

	bool intersects_segment(const Point2 &p_from, const Point2 &p_to, Point2 *r_pos = nullptr, Point2 *r_normal = nullptr) const;

	inline bool encloses(const Rect2 &p_rect) const {

		return (p_rect.pos.x >= pos.x) && (p_rect.pos.y >= pos.y) &&
			   ((p_rect.pos.x + p_rect.size.x) < (pos.x + size.x)) &&
			   ((p_rect.pos.y + p_rect.size.y) < (pos.y + size.y));
	}

	inline bool has_no_area() const {

		return (size.x <= 0 || size.y <= 0);
	}
	Rect2 clip(const Rect2 &p_rect) const;

	Rect2 merge(const Rect2 &p_rect) const;

	inline bool has_point(const Point2 &p_point) const {
		if (p_point.x < pos.x)
			return false;
		if (p_point.y < pos.y)
			return false;

		if (p_point.x >= (pos.x + size.x))
			return false;
		if (p_point.y >= (pos.y + size.y))
			return false;

		return true;
	}

	inline bool no_area() const { return (size.width <= 0 || size.height <= 0); }

	inline bool operator==(const Rect2 &p_rect) const { return pos == p_rect.pos && size == p_rect.size; }
	inline bool operator!=(const Rect2 &p_rect) const { return pos != p_rect.pos || size != p_rect.size; }

	inline Rect2 grow(real_t p_by) const {

		Rect2 g = *this;
		g.pos.x -= p_by;
		g.pos.y -= p_by;
		g.size.width += p_by * 2;
		g.size.height += p_by * 2;
		return g;
	}

	inline Rect2 expand(const Vector2 &p_vector) const {

		Rect2 r = *this;
		r.expand_to(p_vector);
		return r;
	}

	inline void expand_to(const Vector2 &p_vector) { //in place function for speed

		Vector2 begin = pos;
		Vector2 end = pos + size;

		if (p_vector.x < begin.x)
			begin.x = p_vector.x;
		if (p_vector.y < begin.y)
			begin.y = p_vector.y;

		if (p_vector.x > end.x)
			end.x = p_vector.x;
		if (p_vector.y > end.y)
			end.y = p_vector.y;

		pos = begin;
		size = end - begin;
	}

	operator String() const;

	inline Rect2() {}
	inline Rect2(real_t p_x, real_t p_y, real_t p_width, real_t p_height) {
		pos = Point2(p_x, p_y);
		size = Size2(p_width, p_height);
	}
	inline Rect2(const Point2 &p_pos, const Size2 &p_size) {
		pos = p_pos;
		size = p_size;
	}
};

} // namespace godot

#endif // RECT2_H
