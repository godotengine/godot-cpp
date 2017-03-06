#include "NodePath.hpp"

#include "String.hpp"

#include <godot/godot_node_path.h>

namespace godot {


NodePath::NodePath()
{

}

NodePath::NodePath(const String &from)
{
	godot_node_path_new(&_node_path, (godot_string *) &from);
}

String NodePath::get_name(const int idx) const
{
	godot_string str = godot_node_path_get_name(&_node_path, idx);

	return *(String *) &str;
}

int NodePath::get_name_count() const
{
	return godot_node_path_get_name_count(&_node_path);
}

String NodePath::get_property() const
{
	godot_string str = godot_node_path_get_property(&_node_path);
	return *(String *) &str;
}

String NodePath::get_subname(const int idx) const
{
	godot_string str = godot_node_path_get_subname(&_node_path, idx);
	return *(String *) &str;
}

int NodePath::get_subname_count() const
{
	return godot_node_path_get_subname_count(&_node_path);
}

bool NodePath::is_absolute() const
{
	return godot_node_path_is_absolute(&_node_path);
}

bool NodePath::is_empty() const
{
	return godot_node_path_is_empty(&_node_path);
}

NodePath::operator String() const
{
	godot_string str = godot_node_path_as_string(&_node_path);

	return *(String *) &str;
}

NodePath::~NodePath()
{
	godot_node_path_destroy(&_node_path);
}



}
