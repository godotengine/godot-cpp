#include "Rect3.hpp"
#include "Vector3.hpp"
#include "Plane.hpp"

#include <algorithm>

namespace godot {

bool Rect3::intersects(const Rect3& p_aabb) const {

	if ( pos.x >= (p_aabb.pos.x + p_aabb.size.x) )
		return false;
	if ( (pos.x+size.x) <= p_aabb.pos.x  )
		return false;
	if ( pos.y >= (p_aabb.pos.y + p_aabb.size.y) )
		return false;
	if ( (pos.y+size.y) <= p_aabb.pos.y  )
		return false;
	if ( pos.z >= (p_aabb.pos.z + p_aabb.size.z) )
		return false;
	if ( (pos.z+size.z) <= p_aabb.pos.z  )
		return false;

	return true;
}

bool Rect3::intersects_inclusive(const Rect3& p_aabb) const {

	if ( pos.x > (p_aabb.pos.x + p_aabb.size.x) )
		return false;
	if ( (pos.x+size.x) < p_aabb.pos.x  )
		return false;
	if ( pos.y > (p_aabb.pos.y + p_aabb.size.y) )
		return false;
	if ( (pos.y+size.y) < p_aabb.pos.y  )
		return false;
	if ( pos.z > (p_aabb.pos.z + p_aabb.size.z) )
		return false;
	if ( (pos.z+size.z) < p_aabb.pos.z  )
		return false;

	return true;
}

bool Rect3::encloses(const Rect3 & p_aabb) const {

	Vector3 src_min=pos;
	Vector3 src_max=pos+size;
	Vector3 dst_min=p_aabb.pos;
	Vector3 dst_max=p_aabb.pos+p_aabb.size;

	return  (
		 (src_min.x <= dst_min.x) &&
			(src_max.x > dst_max.x) &&
			(src_min.y <= dst_min.y) &&
			(src_max.y > dst_max.y) &&
			(src_min.z <= dst_min.z) &&
			(src_max.z > dst_max.z) );

}

Vector3 Rect3::get_support(const Vector3& p_normal) const {

	Vector3 half_extents = size * 0.5;
	Vector3 ofs = pos + half_extents;

	return Vector3(
			(p_normal.x>0) ? -half_extents.x : half_extents.x,
			(p_normal.y>0) ? -half_extents.y : half_extents.y,
			(p_normal.z>0) ? -half_extents.z : half_extents.z
		)+ofs;
}


Vector3 Rect3::get_endpoint(int p_point) const {

	switch(p_point) {
		case 0: return Vector3( pos.x	, pos.y		, pos.z		);
		case 1: return Vector3( pos.x	, pos.y		, pos.z+size.z	);
		case 2: return Vector3( pos.x	, pos.y+size.y	, pos.z		);
		case 3: return Vector3( pos.x	, pos.y+size.y	, pos.z+size.z	);
		case 4: return Vector3( pos.x+size.x	, pos.y		, pos.z		);
		case 5: return Vector3( pos.x+size.x	, pos.y		, pos.z+size.z	);
		case 6: return Vector3( pos.x+size.x	, pos.y+size.y	, pos.z		);
		case 7: return Vector3( pos.x+size.x	, pos.y+size.y	, pos.z+size.z	);
	};

	ERR_FAIL_V(Vector3());
}

bool Rect3::intersects_convex_shape(const Plane *p_planes, int p_plane_count) const {

	Vector3 half_extents = size * 0.5;
	Vector3 ofs = pos + half_extents;

	for(int i=0;i<p_plane_count;i++) {
		const Plane &p=p_planes[i];
		Vector3 point(
				(p.normal.x>0) ? -half_extents.x : half_extents.x,
				(p.normal.y>0) ? -half_extents.y : half_extents.y,
				(p.normal.z>0) ? -half_extents.z : half_extents.z
			);
		point+=ofs;
		if (p.is_point_over(point))
			return false;
	}

	return true;
}

bool Rect3::has_point(const Vector3& p_point) const {

	if (p_point.x<pos.x)
		return false;
	if (p_point.y<pos.y)
		return false;
	if (p_point.z<pos.z)
		return false;
	if (p_point.x>pos.x+size.x)
		return false;
	if (p_point.y>pos.y+size.y)
		return false;
	if (p_point.z>pos.z+size.z)
		return false;

	return true;
}


void Rect3::expand_to(const Vector3& p_vector) {

	Vector3 begin=pos;
	Vector3 end=pos+size;

	if (p_vector.x<begin.x)
		begin.x=p_vector.x;
	if (p_vector.y<begin.y)
		begin.y=p_vector.y;
	if (p_vector.z<begin.z)
		begin.z=p_vector.z;

	if (p_vector.x>end.x)
		end.x=p_vector.x;
	if (p_vector.y>end.y)
		end.y=p_vector.y;
	if (p_vector.z>end.z)
		end.z=p_vector.z;

	pos=begin;
	size=end-begin;
}

void Rect3::project_range_in_plane(const Plane& p_plane,real_t &r_min,real_t& r_max) const {

	Vector3 half_extents( size.x * 0.5, size.y * 0.5, size.z * 0.5 );
	Vector3 center( pos.x + half_extents.x, pos.y + half_extents.y, pos.z + half_extents.z );

	real_t length = p_plane.normal.abs().dot(half_extents);
	real_t distance = p_plane.distance_to( center );
	r_min = distance - length;
	r_max = distance + length;
}

real_t Rect3::get_longest_axis_size() const {

	real_t max_size=size.x;

	if (size.y > max_size ) {
		max_size=size.y;
	}

	if (size.z > max_size ) {
		max_size=size.z;
	}

	return max_size;
}

real_t Rect3::get_shortest_axis_size() const {

	real_t max_size=size.x;

	if (size.y < max_size ) {
		max_size=size.y;
	}

	if (size.z < max_size ) {
		max_size=size.z;
	}

	return max_size;
}

bool Rect3::smits_intersect_ray(const Vector3 &from,const Vector3& dir, real_t t0, real_t t1) const {

	real_t divx=1.0/dir.x;
	real_t divy=1.0/dir.y;
	real_t divz=1.0/dir.z;

	Vector3 upbound=pos+size;
	real_t tmin, tmax, tymin, tymax, tzmin, tzmax;
	if (dir.x >= 0) {
		tmin = (pos.x - from.x) * divx;
		tmax = (upbound.x - from.x) * divx;
	}
	else {
		tmin = (upbound.x - from.x) * divx;
		tmax = (pos.x - from.x) * divx;
	}
	if (dir.y >= 0) {
		tymin = (pos.y - from.y) * divy;
		tymax = (upbound.y - from.y) * divy;
	}
	else {
		tymin = (upbound.y - from.y) * divy;
		tymax = (pos.y - from.y) * divy;
	}
	if ( (tmin > tymax) || (tymin > tmax) )
		return false;
	if (tymin > tmin)
			tmin = tymin;
	if (tymax < tmax)
		tmax = tymax;
	if (dir.z >= 0) {
		tzmin = (pos.z - from.z) * divz;
		tzmax = (upbound.z - from.z) * divz;
	}
	else {
		tzmin = (upbound.z - from.z) * divz;
		tzmax = (pos.z - from.z) * divz;
	}
	if ( (tmin > tzmax) || (tzmin > tmax) )
		return false;
	if (tzmin > tmin)
		tmin = tzmin;
	if (tzmax < tmax)
		tmax = tzmax;
	return ( (tmin < t1) && (tmax > t0) );
}

void Rect3::grow_by(real_t p_amount) {

	pos.x-=p_amount;
	pos.y-=p_amount;
	pos.z-=p_amount;
	size.x+=2.0*p_amount;
	size.y+=2.0*p_amount;
	size.z+=2.0*p_amount;
}


real_t Rect3::get_area() const {

	return size.x*size.y*size.z;

}

bool Rect3::operator==(const Rect3& p_rval) const {

	return ((pos==p_rval.pos) && (size==p_rval.size));

}
bool Rect3::operator!=(const Rect3& p_rval) const {

	return ((pos!=p_rval.pos) || (size!=p_rval.size));

}

void Rect3::merge_with(const Rect3& p_aabb) {

	Vector3 beg_1,beg_2;
	Vector3 end_1,end_2;
	Vector3 min,max;

	beg_1=pos;
	beg_2=p_aabb.pos;
	end_1=Vector3(size.x,size.y,size.z)+beg_1;
	end_2=Vector3(p_aabb.size.x,p_aabb.size.y,p_aabb.size.z)+beg_2;

	min.x=(beg_1.x<beg_2.x)?beg_1.x:beg_2.x;
	min.y=(beg_1.y<beg_2.y)?beg_1.y:beg_2.y;
	min.z=(beg_1.z<beg_2.z)?beg_1.z:beg_2.z;

	max.x=(end_1.x>end_2.x)?end_1.x:end_2.x;
	max.y=(end_1.y>end_2.y)?end_1.y:end_2.y;
	max.z=(end_1.z>end_2.z)?end_1.z:end_2.z;

	pos=min;
	size=max-min;
}

Rect3 Rect3::intersection(const Rect3& p_aabb) const {

	Vector3 src_min=pos;
	Vector3 src_max=pos+size;
	Vector3 dst_min=p_aabb.pos;
	Vector3 dst_max=p_aabb.pos+p_aabb.size;

	Vector3 min,max;

	if (src_min.x > dst_max.x || src_max.x < dst_min.x )
		return Rect3();
	else {

		min.x= ( src_min.x > dst_min.x ) ? src_min.x :dst_min.x;
		max.x= ( src_max.x < dst_max.x ) ? src_max.x :dst_max.x;

	}

	if (src_min.y > dst_max.y || src_max.y < dst_min.y )
		return Rect3();
	else {

		min.y= ( src_min.y > dst_min.y ) ? src_min.y :dst_min.y;
		max.y= ( src_max.y < dst_max.y ) ? src_max.y :dst_max.y;

	}

	if (src_min.z > dst_max.z || src_max.z < dst_min.z )
		return Rect3();
	else {

		min.z= ( src_min.z > dst_min.z ) ? src_min.z :dst_min.z;
		max.z= ( src_max.z < dst_max.z ) ? src_max.z :dst_max.z;

	}


	return Rect3( min, max-min );
}

bool Rect3::intersects_ray(const Vector3& p_from, const Vector3& p_dir,Vector3* r_clip,Vector3* r_normal) const {

	Vector3 c1, c2;
	Vector3 end = pos+size;
	real_t near=-1e20;
	real_t far=1e20;
	int axis=0;

	for (int i=0;i<3;i++){
		if (p_dir[i] == 0){
			if ((p_from[i] < pos[i]) || (p_from[i] > end[i])) {
				return false;
			}
		} else { // ray not parallel to planes in this direction
			c1[i] = (pos[i] - p_from[i]) / p_dir[i];
			c2[i] = (end[i] - p_from[i]) / p_dir[i];

			if(c1[i] > c2[i]){
				std::swap(c1,c2);
			}
			if (c1[i] > near){
				near = c1[i];
				axis=i;
			}
			if (c2[i] < far){
				far = c2[i];
			}
			if( (near > far) || (far < 0) ){
				return false;
			}
		}
	}

	if (r_clip)
		*r_clip=c1;
	if (r_normal) {
		*r_normal=Vector3();
		(*r_normal)[axis]=p_dir[axis]?-1:1;
	}

	return true;

}


bool Rect3::intersects_segment(const Vector3& p_from, const Vector3& p_to,Vector3* r_clip,Vector3* r_normal) const {

	real_t min=0,max=1;
	int axis=0;
	real_t sign=0;

	for(int i=0;i<3;i++) {
		real_t seg_from=p_from[i];
		real_t seg_to=p_to[i];
		real_t box_begin=pos[i];
		real_t box_end=box_begin+size[i];
		real_t cmin,cmax;
		real_t csign;

		if (seg_from < seg_to) {

			if (seg_from > box_end || seg_to < box_begin)
				return false;
			real_t length=seg_to-seg_from;
			cmin = (seg_from < box_begin)?((box_begin - seg_from)/length):0;
			cmax = (seg_to > box_end)?((box_end - seg_from)/length):1;
			csign=-1.0;

		} else {

			if (seg_to > box_end || seg_from < box_begin)
				return false;
			real_t length=seg_to-seg_from;
			cmin = (seg_from > box_end)?(box_end - seg_from)/length:0;
			cmax = (seg_to < box_begin)?(box_begin - seg_from)/length:1;
			csign=1.0;
		}

		if (cmin > min) {
			min = cmin;
			axis=i;
			sign=csign;
		}
		if (cmax < max)
			max = cmax;
		if (max < min)
			return false;
	}


	Vector3 rel=p_to-p_from;

	if (r_normal) {
		Vector3 normal;
		normal[axis]=sign;
		*r_normal=normal;
	}

	if (r_clip)
		*r_clip=p_from+rel*min;

	return true;

}


bool Rect3::intersects_plane(const Plane &p_plane) const {

	Vector3 points[8] = {
		Vector3( pos.x	, pos.y		, pos.z		),
		Vector3( pos.x	, pos.y		, pos.z+size.z	),
		Vector3( pos.x	, pos.y+size.y	, pos.z		),
		Vector3( pos.x	, pos.y+size.y	, pos.z+size.z	),
		Vector3( pos.x+size.x	, pos.y		, pos.z		),
		Vector3( pos.x+size.x	, pos.y		, pos.z+size.z	),
		Vector3( pos.x+size.x	, pos.y+size.y	, pos.z		),
		Vector3( pos.x+size.x	, pos.y+size.y	, pos.z+size.z	),
	};

	bool over=false;
	bool under=false;

	for (int i=0;i<8;i++) {

		if (p_plane.distance_to(points[i])>0)
			over=true;
		else
			under=true;

	}

	return under && over;
}



Vector3 Rect3::get_longest_axis() const {

	Vector3 axis(1,0,0);
	real_t max_size=size.x;

	if (size.y > max_size ) {
		axis=Vector3(0,1,0);
		max_size=size.y;
	}

	if (size.z > max_size ) {
		axis=Vector3(0,0,1);
		max_size=size.z;
	}

	return axis;
}
int Rect3::get_longest_axis_index() const {

	int axis=0;
	real_t max_size=size.x;

	if (size.y > max_size ) {
		axis=1;
		max_size=size.y;
	}

	if (size.z > max_size ) {
		axis=2;
		max_size=size.z;
	}

	return axis;
}


Vector3 Rect3::get_shortest_axis() const {

	Vector3 axis(1,0,0);
	real_t max_size=size.x;

	if (size.y < max_size ) {
		axis=Vector3(0,1,0);
		max_size=size.y;
	}

	if (size.z < max_size ) {
		axis=Vector3(0,0,1);
		max_size=size.z;
	}

	return axis;
}
int Rect3::get_shortest_axis_index() const {

	int axis=0;
	real_t max_size=size.x;

	if (size.y < max_size ) {
		axis=1;
		max_size=size.y;
	}

	if (size.z < max_size ) {
		axis=2;
		max_size=size.z;
	}

	return axis;
}

Rect3 Rect3::merge(const Rect3& p_with) const {

	Rect3 aabb=*this;
	aabb.merge_with(p_with);
	return aabb;
}
Rect3 Rect3::expand(const Vector3& p_vector) const {
	Rect3 aabb=*this;
	aabb.expand_to(p_vector);
	return aabb;

}
Rect3 Rect3::grow(real_t p_by) const {

	Rect3 aabb=*this;
	aabb.grow_by(p_by);
	return aabb;
}

void Rect3::get_edge(int p_edge,Vector3& r_from,Vector3& r_to) const {

	ERR_FAIL_INDEX(p_edge,12);
	switch(p_edge) {

		case 0:{

			r_from=Vector3( pos.x+size.x	, pos.y		, pos.z		);
			r_to=Vector3( pos.x	, pos.y		, pos.z		);
		} break;
		case 1:{

			r_from=Vector3( pos.x+size.x	, pos.y		, pos.z+size.z	);
			r_to=Vector3( pos.x+size.x	, pos.y		, pos.z		);
		} break;
		case 2:{
			r_from=Vector3( pos.x	, pos.y		, pos.z+size.z	);
			r_to=Vector3( pos.x+size.x	, pos.y		, pos.z+size.z	);

		} break;
		case 3:{

			r_from=Vector3( pos.x	, pos.y		, pos.z		);
			r_to=Vector3( pos.x	, pos.y		, pos.z+size.z	);

		} break;
		case 4:{

			r_from=Vector3( pos.x	, pos.y+size.y		, pos.z		);
			r_to=Vector3( pos.x+size.x	, pos.y+size.y		, pos.z		);
		} break;
		case 5:{

			r_from=Vector3( pos.x+size.x	, pos.y+size.y		, pos.z		);
			r_to=Vector3( pos.x+size.x	, pos.y+size.y		, pos.z+size.z	);
		} break;
		case 6:{
			r_from=Vector3( pos.x+size.x	, pos.y+size.y		, pos.z+size.z	);
			r_to=Vector3( pos.x	, pos.y+size.y		, pos.z+size.z	);

		} break;
		case 7:{

			r_from=Vector3( pos.x	, pos.y+size.y		, pos.z+size.z	);
			r_to=Vector3( pos.x	, pos.y+size.y		, pos.z		);

		} break;
		case 8:{

			r_from=Vector3( pos.x	, pos.y		, pos.z+size.z	);
			r_to=Vector3( pos.x	, pos.y+size.y		, pos.z+size.z	);

		} break;
		case 9:{

			r_from=Vector3( pos.x	, pos.y		, pos.z		);
			r_to=Vector3( pos.x	, pos.y+size.y	, pos.z		);

		} break;
		case 10:{

			r_from=Vector3( pos.x+size.x	, pos.y		, pos.z		);
			r_to=Vector3( pos.x+size.x	, pos.y+size.y	, pos.z		);

		} break;
		case 11:{

			r_from=Vector3( pos.x+size.x	, pos.y		, pos.z+size.z		);
			r_to=Vector3( pos.x+size.x	, pos.y+size.y	, pos.z+size.z		);

		} break;

	}

}

Rect3::operator String() const {

	//return String()+pos +" - "+ size;
	return String(); // @Todo
}

}
