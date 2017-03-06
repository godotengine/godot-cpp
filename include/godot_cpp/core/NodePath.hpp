#ifndef NODEPATH_H
#define NODEPATH_H

#include "String.hpp"

#include <godot/godot_node_path.h>

namespace godot {


class NodePath
{
	godot_node_path _node_path;
public:
	NodePath();

	NodePath(const String &from);

	String get_name(const int idx) const;

	int get_name_count() const;

	String get_property() const;

	String get_subname(const int idx) const;

	int get_subname_count() const;

	bool is_absolute() const;

	bool is_empty() const;

	operator String() const;

	~NodePath();
};



}

#endif // NODEPATH_H
