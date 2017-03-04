#ifndef NODEPATH_H
#define NODEPATH_H

#include "String.h"

#include <godot/godot_node_path.h>

namespace godot {


class NodePath
{
	godot_node_path _node_path;
public:
	NodePath()
	{

	}

	NodePath(const String &from)
	{
		godot_node_path_new(&_node_path, (godot_string *) &from);
	}

	String get_name(const int idx) const
	{
		godot_string str = godot_node_path_get_name(&_node_path, idx);

		return *(String *) &str;
	}

	int get_name_count() const
	{
		return godot_node_path_get_name_count(&_node_path);
	}

	String get_property() const
	{
		godot_string str = godot_node_path_get_property(&_node_path);
		return *(String *) &str;
	}

	String get_subname(const int idx) const
	{
		godot_string str = godot_node_path_get_subname(&_node_path, idx);
		return *(String *) &str;
	}

	int get_subname_count() const
	{
		return godot_node_path_get_subname_count(&_node_path);
	}

	bool is_absolute() const
	{
		return godot_node_path_is_absolute(&_node_path);
	}

	bool is_empty() const
	{
		return godot_node_path_is_empty(&_node_path);
	}

	operator String() const
	{
		godot_string str = godot_node_path_as_string(&_node_path);

		return *(String *) &str;
	}

	~NodePath()
	{
		godot_node_path_destroy(&_node_path);
	}
};



}

#endif // NODEPATH_H
