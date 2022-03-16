/*************************************************************************/
/*  object.hpp                                                           */
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

#ifndef GODOT_OBJECT_HPP
#define GODOT_OBJECT_HPP

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <godot_cpp/classes/object.hpp>

#include <godot_cpp/godot.hpp>

#include <godot/gdnative_interface.h>

#include <vector>

#define ADD_SIGNAL(m_signal) godot::ClassDB::add_signal(get_class_static(), m_signal)
#define ADD_GROUP(m_name, m_prefix) godot::ClassDB::add_property_group(get_class_static(), m_name, m_prefix)
#define ADD_SUBGROUP(m_name, m_prefix) godot::ClassDB::add_property_subgroup(get_class_static(), m_name, m_prefix)
#define ADD_PROPERTY(m_property, m_setter, m_getter) godot::ClassDB::add_property(get_class_static(), m_property, m_setter, m_getter)

namespace godot {

struct PropertyInfo {
	Variant::Type type = Variant::NIL;
	const char *name = nullptr;
	const char *class_name = nullptr;
	uint32_t hint = 0;
	const char *hint_string = nullptr;
	uint32_t usage = 7;

	operator GDNativePropertyInfo() const {
		GDNativePropertyInfo info;
		info.type = type;
		info.name = name;
		info.hint = hint;
		info.hint_string = hint_string;
		info.class_name = class_name;
		info.usage = usage;
		return info;
	}

	PropertyInfo() = default;

	PropertyInfo(Variant::Type p_type, const char *p_name, PropertyHint p_hint = PROPERTY_HINT_NONE, const char *p_hint_string = "", uint32_t p_usage = PROPERTY_USAGE_DEFAULT, const char *p_class_name = "") :
			type(p_type),
			name(p_name),
			hint(p_hint),
			hint_string(p_hint_string),
			usage(p_usage) {
		if (hint == PROPERTY_HINT_RESOURCE_TYPE) {
			class_name = hint_string;
		} else {
			class_name = p_class_name;
		}
	}

	PropertyInfo(GDNativeVariantType p_type, const char *p_name, PropertyHint p_hint = PROPERTY_HINT_NONE, const char *p_hint_string = "", uint32_t p_usage = PROPERTY_USAGE_DEFAULT, const char *p_class_name = "") :
			PropertyInfo((Variant::Type)p_type, p_name, p_hint, p_hint_string, p_usage, p_class_name) {}
};

struct MethodInfo {
	const char *name;
	PropertyInfo return_val;
	uint32_t flags;
	int id = 0;
	std::vector<PropertyInfo> arguments;
	std::vector<Variant> default_arguments;

	inline bool operator==(const MethodInfo &p_method) const { return id == p_method.id; }
	inline bool operator<(const MethodInfo &p_method) const { return id == p_method.id ? (name < p_method.name) : (id < p_method.id); }

	operator Dictionary() const;

	static MethodInfo from_dict(const Dictionary &p_dict);

	MethodInfo();
	MethodInfo(const char *p_name);
	template <class... Args>
	MethodInfo(const char *p_name, const Args &...args);
	MethodInfo(Variant::Type ret);
	MethodInfo(Variant::Type ret, const char *p_name);
	template <class... Args>
	MethodInfo(Variant::Type ret, const char *p_name, const Args &...args);
	MethodInfo(const PropertyInfo &p_ret, const char *p_name);
	template <class... Args>
	MethodInfo(const PropertyInfo &p_ret, const char *p_name, const Args &...);
};

template <class... Args>
MethodInfo::MethodInfo(const char *p_name, const Args &...args) :
		name(p_name), flags(METHOD_FLAG_NORMAL) {
	arguments = { args... };
}

template <class... Args>
MethodInfo::MethodInfo(Variant::Type ret, const char *p_name, const Args &...args) :
		name(p_name), flags(METHOD_FLAG_NORMAL) {
	return_val.type = ret;
	arguments = { args... };
}

template <class... Args>
MethodInfo::MethodInfo(const PropertyInfo &p_ret, const char *p_name, const Args &...args) :
		name(p_name), return_val(p_ret), flags(METHOD_FLAG_NORMAL) {
	arguments = { args... };
}

class ObjectID {
	uint64_t id = 0;

public:
	_FORCE_INLINE_ bool is_ref_counted() const { return (id & (uint64_t(1) << 63)) != 0; }
	_FORCE_INLINE_ bool is_valid() const { return id != 0; }
	_FORCE_INLINE_ bool is_null() const { return id == 0; }
	_FORCE_INLINE_ operator uint64_t() const { return id; }
	_FORCE_INLINE_ operator int64_t() const { return id; }

	_FORCE_INLINE_ bool operator==(const ObjectID &p_id) const { return id == p_id.id; }
	_FORCE_INLINE_ bool operator!=(const ObjectID &p_id) const { return id != p_id.id; }
	_FORCE_INLINE_ bool operator<(const ObjectID &p_id) const { return id < p_id.id; }

	_FORCE_INLINE_ void operator=(int64_t p_int64) { id = p_int64; }
	_FORCE_INLINE_ void operator=(uint64_t p_uint64) { id = p_uint64; }

	_FORCE_INLINE_ ObjectID() {}
	_FORCE_INLINE_ explicit ObjectID(const uint64_t p_id) { id = p_id; }
	_FORCE_INLINE_ explicit ObjectID(const int64_t p_id) { id = p_id; }
};

class ObjectDB {
public:
	static Object *get_instance(uint64_t p_object_id) {
		GDNativeObjectPtr obj = internal::gdn_interface->object_get_instance_from_id(p_object_id);
		if (obj == nullptr) {
			return nullptr;
		}
		return reinterpret_cast<Object *>(internal::gdn_interface->object_get_instance_binding(obj, internal::token, &Object::___binding_callbacks));
	}
};

template <class T>
T *Object::cast_to(Object *p_object) {
	GDNativeObjectPtr casted = internal::gdn_interface->object_cast_to(p_object->_owner, internal::gdn_interface->classdb_get_class_tag(T::get_class_static()));
	if (casted == nullptr) {
		return nullptr;
	}
	return reinterpret_cast<T *>(internal::gdn_interface->object_get_instance_binding(casted, internal::token, &T::___binding_callbacks));
}

} // namespace godot

#endif // ! GODOT_OBJECT_HPP
