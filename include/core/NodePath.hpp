/*************************************************************************/
/*  NodePath.hpp                                                         */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef NODEPATH_H
#define NODEPATH_H

#include "String.hpp"

#include <gdnative/node_path.h>

namespace godot {

class NodePath {
	godot_node_path _node_path;

	friend class Variant;
	inline explicit NodePath(godot_node_path node_path) {
		_node_path = node_path;
	}

public:
	NodePath();

	NodePath(const NodePath &other);

	NodePath(const String &from);

	NodePath(const char *contents);

	String get_name(const int idx) const;

	int get_name_count() const;

	String get_subname(const int idx) const;

	int get_subname_count() const;

	bool is_absolute() const;

	bool is_empty() const;

	NodePath get_as_property_path() const;

	String get_concatenated_subnames() const;

	operator String() const;

	void operator=(const NodePath &other);

	bool operator==(const NodePath &other);

	~NodePath();
};

} // namespace godot

#endif // NODEPATH_H
