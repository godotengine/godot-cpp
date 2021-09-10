/*************************************************************************/
/*  class_db.cpp                                                         */
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

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/godot.hpp>

#include <godot_cpp/core/memory.hpp>

#include <algorithm>

namespace godot {

std::unordered_map<std::string, ClassDB::ClassInfo> ClassDB::classes;
GDNativeInitializationLevel ClassDB::current_level = GDNATIVE_INITIALIZATION_CORE;

MethodDefinition D_METHOD(const char *p_name) {
	return MethodDefinition(p_name);
}

MethodDefinition D_METHOD(const char *p_name, const char *p_arg1) {
	MethodDefinition method(p_name);
	method.args.push_front(p_arg1);
	return method;
}

void ClassDB::add_property(const char *p_class, const PropertyInfo &p_pinfo, const char *p_setter, const char *p_getter, int p_index) {
	ERR_FAIL_COND_MSG(classes.find(p_class) == classes.end(), "Trying to add property to non-existing class.");

	ClassInfo &info = classes[p_class];

	ERR_FAIL_COND_MSG(info.property_setget.find(p_pinfo.name) != info.property_setget.end(), "Property already exists in class.");

	MethodBind *setter = nullptr;
	if (p_setter) {
		setter = get_method(p_class, p_setter);

		ERR_FAIL_COND_MSG(!setter, "Setter method not found for property.");

		size_t exp_args = 1 + (p_index >= 0 ? 1 : 0);
		ERR_FAIL_COND_MSG(exp_args != setter->get_argument_count(), "Setter method must take a single argument.");
	}

	ERR_FAIL_COND_MSG(!p_getter, "Getter method must be specified.");

	MethodBind *getter = get_method(p_class, p_getter);
	ERR_FAIL_COND_MSG(!getter, "Getter method not found for property.");
	{
		size_t exp_args = 0 + (p_index >= 0 ? 1 : 0);
		ERR_FAIL_COND_MSG(exp_args != getter->get_argument_count(), "Getter method must not take any argument.");
	}

	info.property_list.push_back(p_pinfo);

	PropertySetGet setget;
	setget.setter = p_setter;
	setget.getter = p_getter;
	setget._setptr = setter;
	setget._getptr = getter;
	setget.index = p_index;
	setget.type = p_pinfo.type;

	info.property_setget[p_pinfo.name] = setget;
}

MethodBind *ClassDB::get_method(const char *p_class, const char *p_method) {
	ERR_FAIL_COND_V_MSG(classes.find(p_class) == classes.end(), nullptr, "Class not found.");

	ClassInfo *type = &classes[p_class];
	while (type) {
		std::unordered_map<std::string, MethodBind *>::iterator method = type->method_map.find(p_method);
		if (method != type->method_map.end()) {
			return method->second;
		}
		type = type->parent_ptr;
		continue;
	}

	return nullptr;
}

MethodBind *ClassDB::bind_methodfi(uint32_t p_flags, MethodBind *p_bind, const MethodDefinition &method_name, const void **p_defs, int p_defcount) {
	const char *instance_type = p_bind->get_instance_class();

	std::unordered_map<std::string, ClassInfo>::iterator type_it = classes.find(instance_type);
	if (type_it == classes.end()) {
		memdelete(p_bind);
		ERR_FAIL_V_MSG(nullptr, "Class doesn't exist.");
	}

	ClassInfo &type = type_it->second;

	if (type.method_map.find(method_name.name) != type.method_map.end()) {
		memdelete(p_bind);
		ERR_FAIL_V_MSG(nullptr, "Binding duplicate method.");
	}

	if (type.virtual_methods.find(method_name.name) != type.virtual_methods.end()) {
		memdelete(p_bind);
		ERR_FAIL_V_MSG(nullptr, "Method already bound as virtual.");
	}

	p_bind->set_name(method_name.name);

	if (method_name.args.size() > p_bind->get_argument_count()) {
		memdelete(p_bind);
		ERR_FAIL_V_MSG(nullptr, "Method definition has more arguments than the actual method.");
	}

	p_bind->set_hint_flags(p_flags);

	std::vector<std::string> args;
	args.resize(method_name.args.size());
	size_t arg_index = 0;
	for (std::string arg : method_name.args) {
		args[arg_index++] = arg;
	}

	p_bind->set_argument_names(args);

	type.method_order.push_back(p_bind);
	type.method_map[method_name.name] = p_bind;

	return p_bind;
}

void ClassDB::add_signal(const char *p_class, const MethodInfo &p_signal) {
	std::unordered_map<std::string, ClassInfo>::iterator type_it = classes.find(p_class);

	ERR_FAIL_COND_MSG(type_it == classes.end(), "Class doesn't exist.");

	ClassInfo &base = type_it->second;
	ClassInfo *check = &base;
	while (check) {
		ERR_FAIL_COND_MSG(check->signal_map.find(p_signal.name) != check->signal_map.end(), String("Class '" + String(p_class) + "' already has signal '" + String(p_signal.name) + "'.").utf8().get_data());
		check = check->parent_ptr;
	}

	base.signal_map[p_signal.name] = p_signal;
}

void ClassDB::bind_integer_constant(const char *p_class, const char *p_enum, const char *p_name, GDNativeInt p_constant) {
	std::unordered_map<std::string, ClassInfo>::iterator type_it = classes.find(p_class);

	ERR_FAIL_COND_MSG(type_it == classes.end(), "Class doesn't exist.");

	ClassInfo &type = type_it->second;

	ERR_FAIL_COND_MSG(type.constant_map.find(p_name) != type.constant_map.end(), "Constant already registered.");

	type.constant_map[p_name] = std::pair<std::string, GDNativeInt>{ p_enum, p_constant };
	type.constant_order.push_back(p_name);
}

GDNativeExtensionClassCallVirtual ClassDB::get_virtual_func(void *p_userdata, const char *p_name) {
	const char *class_name = (const char *)p_userdata;

	std::unordered_map<std::string, ClassInfo>::iterator type_it = classes.find(class_name);
	ERR_FAIL_COND_V_MSG(type_it == classes.end(), nullptr, "Class doesn't exist.");

	ClassInfo &type = type_it->second;

	std::unordered_map<std::string, GDNativeExtensionClassCallVirtual>::iterator method_it = type.virtual_methods.find(p_name);

	if (method_it == type.virtual_methods.end()) {
		return nullptr;
	}

	return method_it->second;
}

void ClassDB::bind_virtual_method(const char *p_class, const char *p_method, GDNativeExtensionClassCallVirtual p_call) {
	std::unordered_map<std::string, ClassInfo>::iterator type_it = classes.find(p_class);
	ERR_FAIL_COND_MSG(type_it == classes.end(), "Class doesn't exist.");

	ClassInfo &type = type_it->second;

	ERR_FAIL_COND_MSG(type.method_map.find(p_method) != type.method_map.end(), "Method already registered as non-virtual.");
	ERR_FAIL_COND_MSG(type.virtual_methods.find(p_method) != type.virtual_methods.end(), "Virtual method already registered.");

	type.virtual_methods[p_method] = p_call;
}

void ClassDB::initialize(GDNativeInitializationLevel p_level) {
	for (const std::pair<std::string, ClassInfo> pair : classes) {
		const ClassInfo &cl = pair.second;
		if (cl.level != p_level) {
			continue;
		}

		GDNativeExtensionClassCreationInfo class_info = {
			nullptr, // GDNativeExtensionClassSet set_func;
			nullptr, // GDNativeExtensionClassGet get_func;
			nullptr, // GDNativeExtensionClassGetPropertyList get_property_list_func;
			nullptr, // GDNativeExtensionClassFreePropertyList free_property_list_func;
			nullptr, // GDNativeExtensionClassNotification notification_func;
			nullptr, // GDNativeExtensionClassToString to_string_func;
			nullptr, // GDNativeExtensionClassReference reference_func;
			nullptr, // GDNativeExtensionClassUnreference
			cl.constructor, // GDNativeExtensionClassCreateInstance create_instance_func; /* this one is mandatory */
			cl.destructor, // GDNativeExtensionClassFreeInstance free_instance_func; /* this one is mandatory */
			cl.object_instance, // GDNativeExtensionClassObjectInstance object_instance_func; /* this one is mandatory */
			&ClassDB::get_virtual_func, // GDNativeExtensionClassGetVirtual get_virtual_func;
			(void *)cl.name, //void *class_userdata;
		};

		internal::interface->classdb_register_extension_class(internal::library, cl.name, cl.parent_name, &class_info);

		for (MethodBind *method : cl.method_order) {
			GDNativeExtensionClassMethodInfo method_info = {
				method->get_name(), //const char *name;
				method, //void *method_userdata;
				MethodBind::bind_call, //GDNativeExtensionClassMethodCall call_func;
				MethodBind::bind_ptrcall, //GDNativeExtensionClassMethodPtrCall ptrcall_func;
				GDNATIVE_EXTENSION_METHOD_FLAGS_DEFAULT, //uint32_t method_flags; /* GDNativeExtensionClassMethodFlags */
				(uint32_t)method->get_argument_count(), //uint32_t argument_count;
				(GDNativeBool)method->has_return(), //GDNativeBool has_return_value;
				MethodBind::bind_get_argument_type, //(GDNativeExtensionClassMethodGetArgumentType) get_argument_type_func;
				MethodBind::bind_get_argument_info, //GDNativeExtensionClassMethodGetArgumentInfo get_argument_info_func; /* name and hint information for the argument can be omitted in release builds. Class name should always be present if it applies. */
				MethodBind::bind_get_argument_metadata, //GDNativeExtensionClassMethodGetArgumentMetadata get_argument_metadata_func;
				method->get_hint_flags(), //uint32_t default_argument_count;
				nullptr, //GDNativeVariantPtr *default_arguments;
			};
			internal::interface->classdb_register_extension_class_method(internal::library, cl.name, &method_info);
		}

		for (const PropertyInfo &property : cl.property_list) {
			GDNativePropertyInfo info = {
				(uint32_t)property.type, //uint32_t type;
				property.name, //const char *name;
				property.class_name, //const char *class_name;
				property.hint, // NONE //uint32_t hint;
				property.hint_string, // const char *hint_string;
				property.usage, // DEFAULT //uint32_t usage;
			};

			const PropertySetGet &setget = cl.property_setget.find(property.name)->second;

			internal::interface->classdb_register_extension_class_property(internal::library, cl.name, &info, setget.setter, setget.getter);
		}

		for (const std::pair<std::string, MethodInfo> pair : cl.signal_map) {
			const MethodInfo &signal = pair.second;

			std::vector<GDNativePropertyInfo> parameters;
			parameters.reserve(signal.arguments.size());

			for (const PropertyInfo &par : signal.arguments) {
				parameters.push_back(GDNativePropertyInfo{
						static_cast<uint32_t>(par.type), // uint32_t type;
						par.name, // const char *name;
						par.class_name, // const char *class_name;
						par.hint, // uint32_t hint;
						par.hint_string, // const char *hint_string;
						par.usage, // uint32_t usage;
				});
			}

			internal::interface->classdb_register_extension_class_signal(internal::library, cl.name, pair.first.c_str(), parameters.data(), parameters.size());
		}

		for (std::string constant : cl.constant_order) {
			const std::pair<std::string, GDNativeInt> &def = cl.constant_map.find(constant)->second;

			internal::interface->classdb_register_extension_class_integer_constant(internal::library, cl.name, def.first.c_str(), constant.c_str(), def.second);
		}
	}
}

void ClassDB::deinitialize(GDNativeInitializationLevel p_level) {
	for (const std::pair<std::string, ClassInfo> pair : classes) {
		const ClassInfo &cl = pair.second;
		if (cl.level != p_level) {
			continue;
		}

		internal::interface->classdb_unregister_extension_class(internal::library, cl.name);

		for (MethodBind *method : cl.method_order) {
			memdelete(method);
		}
	}
}

} // namespace godot
