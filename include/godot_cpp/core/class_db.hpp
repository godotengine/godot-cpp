/*************************************************************************/
/*  class_db.hpp                                                         */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2021 Godot Engine contributors (cf. AUTHORS.md).   */
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

#ifndef CLASS_DB_HPP
#define CLASS_DB_HPP

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/core/method_bind.hpp>
#include <godot_cpp/core/object.hpp>

#include <list>
#include <string>
#include <unordered_map>
#include <vector>

namespace godot {

struct MethodDefinition {
	const char *name = nullptr;
	std::list<std::string> args;
	MethodDefinition() {}
	MethodDefinition(const char *p_name) :
			name(p_name) {}
};

MethodDefinition D_METHOD(const char *p_name);
MethodDefinition D_METHOD(const char *p_name, const char *p_arg1);
template <typename... Args>
MethodDefinition D_METHOD(const char *p_name, const char *p_arg1, Args... args) {
	MethodDefinition md = D_METHOD(p_name, args...);
	md.args.push_front(p_arg1);
	return md;
}

class ClassDB {
	static GDNativeInitializationLevel current_level;

	friend class godot::GDExtensionBinding;

public:
	struct PropertySetGet {
		int index;
		const char *setter;
		const char *getter;
		MethodBind *_setptr;
		MethodBind *_getptr;
		Variant::Type type;
	};

	struct ClassInfo {
		const char *name = nullptr;
		const char *parent_name = nullptr;
		GDNativeInitializationLevel level = GDNATIVE_INITIALIZATION_SCENE;
		std::unordered_map<std::string, MethodBind *> method_map;
		std::unordered_map<std::string, MethodInfo> signal_map;
		std::list<MethodBind *> method_order;
		GDExtensionClassInstancePtr (*constructor)(void *data);
		std::unordered_map<std::string, GDNativeExtensionClassCallVirtual> virtual_methods;
		void (*destructor)(void *data, GDExtensionClassInstancePtr ptr);
		void (*object_instance)(GDExtensionClassInstancePtr p_instance, GDNativeObjectPtr p_object_instance);
		std::unordered_map<std::string, PropertySetGet> property_setget;
		std::list<PropertyInfo> property_list;
		std::unordered_map<std::string, std::pair<std::string, GDNativeInt>> constant_map; // String in pair is enum name.
		std::list<std::string> constant_order;
		ClassInfo *parent_ptr = nullptr;
	};

private:
	static std::unordered_map<std::string, ClassInfo> classes;

	static MethodBind *bind_methodfi(uint32_t p_flags, MethodBind *p_bind, const MethodDefinition &method_name, const void **p_defs, int p_defcount);

public:
	template <class T>
	static void register_class();

	template <class N, class M>
	static MethodBind *bind_method(N p_method_name, M p_method);
	template <class M>
	static MethodBind *bind_vararg_method(uint32_t p_flags, const char *p_name, M p_method, const MethodInfo &p_info = MethodInfo(), const std::vector<Variant> &p_default_args = std::vector<Variant>{}, bool p_return_nil_is_variant = true);
	static void add_property_group(const char *p_class, const char *p_name, const char *p_prefix);
	static void add_property_subgroup(const char *p_class, const char *p_name, const char *p_prefix);
	static void add_property(const char *p_class, const PropertyInfo &p_pinfo, const char *p_setter, const char *p_getter, int p_index = -1);
	static void add_signal(const char *p_class, const MethodInfo &p_signal);
	static void bind_integer_constant(const char *p_class, const char *p_enum, const char *p_name, GDNativeInt p_constant);
	static void bind_virtual_method(const char *p_class, const char *p_method, GDNativeExtensionClassCallVirtual p_call);

	static MethodBind *get_method(const char *p_class, const char *p_method);

	static GDNativeExtensionClassCallVirtual get_virtual_func(void *p_userdata, const char *p_name);

	static void initialize(GDNativeInitializationLevel p_level);
	static void deinitialize(GDNativeInitializationLevel p_level);
};

#define BIND_CONSTANT(m_constant) \
	ClassDB::bind_integer_constant(get_class_static(), "", #m_constant, m_constant);

#define BIND_ENUM_CONSTANT(m_constant) \
	ClassDB::bind_integer_constant(get_class_static(), __constant_get_enum_name(m_constant, #m_constant), #m_constant, m_constant);

#define BIND_VIRTUAL_METHOD(m_class, m_method)                                                                                    \
	{                                                                                                                             \
		auto ___call##m_method = [](GDNativeObjectPtr p_instance, const GDNativeTypePtr *p_args, GDNativeTypePtr p_ret) -> void { \
			call_with_ptr_args(reinterpret_cast<m_class *>(p_instance), &m_class::m_method, p_args, p_ret);                       \
		};                                                                                                                        \
		ClassDB::bind_virtual_method(m_class::get_class_static(), #m_method, ___call##m_method);                                  \
	}

template <class T>
void ClassDB::register_class() {
	ClassInfo cl;
	cl.name = T::get_class_static();
	cl.parent_name = T::get_parent_class_static();
	cl.level = current_level;
	cl.constructor = T::create;
	cl.destructor = T::free;
	cl.object_instance = T::set_object_instance;
	classes[cl.name] = cl;
	if (classes.find(cl.parent_name) != classes.end()) {
		cl.parent_ptr = &classes[cl.parent_name];
	}
	T::initialize_class();
}

template <class N, class M>
MethodBind *ClassDB::bind_method(N p_method_name, M p_method) {
	MethodBind *bind = create_method_bind(p_method);

	return bind_methodfi(0, bind, p_method_name, nullptr, 0);
}

template <class M>
MethodBind *ClassDB::bind_vararg_method(uint32_t p_flags, const char *p_name, M p_method, const MethodInfo &p_info, const std::vector<Variant> &p_default_args, bool p_return_nil_is_variant) {
	MethodBind *bind = create_vararg_method_bind(p_method, p_info, p_return_nil_is_variant);
	ERR_FAIL_COND_V(!bind, nullptr);

	bind->set_name(p_name);
	bind->set_default_arguments(p_default_args);

	const char *instance_type = bind->get_instance_class();

	std::unordered_map<std::string, ClassInfo>::iterator type_it = classes.find(instance_type);
	if (type_it == classes.end()) {
		memdelete(bind);
		ERR_FAIL_V_MSG(nullptr, "Class doesn't exist.");
	}

	ClassInfo &type = type_it->second;

	if (type.method_map.find(p_name) != type.method_map.end()) {
		memdelete(bind);
		ERR_FAIL_V_MSG(nullptr, "Binding duplicate method.");
	}

	type.method_map[p_name] = bind;
	type.method_order.push_back(bind);

	return bind;
}
} // namespace godot

#endif // ! CLASS_DB_HPP
