/*************************************************************************/
/*  class_db.cpp                                                         */
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

void ClassDB::add_property_group(const char *p_class, const char *p_name, const char *p_prefix) {
	ERR_FAIL_COND_MSG(classes.find(p_class) == classes.end(), "Trying to add property to non-existing class.");

	internal::gdn_interface->classdb_register_extension_class_property_group(internal::library, p_class, p_name, p_prefix);
}

void ClassDB::add_property_subgroup(const char *p_class, const char *p_name, const char *p_prefix) {
	ERR_FAIL_COND_MSG(classes.find(p_class) == classes.end(), "Trying to add property to non-existing class.");

	internal::gdn_interface->classdb_register_extension_class_property_subgroup(internal::library, p_class, p_name, p_prefix);
}

void ClassDB::add_property(const char *p_class, const PropertyInfo &p_pinfo, const char *p_setter, const char *p_getter, int p_index) {
	ERR_FAIL_COND_MSG(classes.find(p_class) == classes.end(), "Trying to add property to non-existing class.");

	ClassInfo &info = classes[p_class];

	ERR_FAIL_COND_MSG(info.property_names.find(p_pinfo.name) != info.property_names.end(), "Property already exists in class.");

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

	// register property with plugin
	info.property_names.insert(p_pinfo.name);

	// register with Godot
	GDNativePropertyInfo prop_info = {
		(uint32_t)p_pinfo.type, //uint32_t type;
		p_pinfo.name, //const char *name;
		p_pinfo.class_name, //const char *class_name;
		p_pinfo.hint, // NONE //uint32_t hint;
		p_pinfo.hint_string, // const char *hint_string;
		p_pinfo.usage, // DEFAULT //uint32_t usage;
	};

	PropertySetGet setget;
	setget.setter = p_setter;
	setget.getter = p_getter;
	setget._setptr = setter;
	setget._getptr = getter;
	setget.index = p_index;
	setget.type = p_pinfo.type;

	internal::gdn_interface->classdb_register_extension_class_property(internal::library, info.name, &prop_info, setget.setter, setget.getter);
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

	// register our method bind within our plugin
	type.method_map[method_name.name] = p_bind;

	// and register with godot
	bind_method_godot(type.name, p_bind);

	return p_bind;
}

void ClassDB::bind_method_godot(const char *p_class_name, MethodBind *p_method) {
	GDNativeExtensionClassMethodInfo method_info = {
		p_method->get_name(), //const char *name;
		p_method, //void *method_userdata;
		MethodBind::bind_call, //GDNativeExtensionClassMethodCall call_func;
		MethodBind::bind_ptrcall, //GDNativeExtensionClassMethodPtrCall ptrcall_func;
		GDNATIVE_EXTENSION_METHOD_FLAGS_DEFAULT, //uint32_t method_flags; /* GDNativeExtensionClassMethodFlags */
		(uint32_t)p_method->get_argument_count(), //uint32_t argument_count;
		(GDNativeBool)p_method->has_return(), //GDNativeBool has_return_value;
		MethodBind::bind_get_argument_type, //(GDNativeExtensionClassMethodGetArgumentType) get_argument_type_func;
		MethodBind::bind_get_argument_info, //GDNativeExtensionClassMethodGetArgumentInfo get_argument_info_func; /* name and hint information for the argument can be omitted in release builds. Class name should always be present if it applies. */
		MethodBind::bind_get_argument_metadata, //GDNativeExtensionClassMethodGetArgumentMetadata get_argument_metadata_func;
		p_method->get_hint_flags(), //uint32_t default_argument_count;
		nullptr, //GDNativeVariantPtr *default_arguments;
	};
	internal::gdn_interface->classdb_register_extension_class_method(internal::library, p_class_name, &method_info);
}

void ClassDB::add_signal(const char *p_class, const MethodInfo &p_signal) {
	std::unordered_map<std::string, ClassInfo>::iterator type_it = classes.find(p_class);

	ERR_FAIL_COND_MSG(type_it == classes.end(), "Class doesn't exist.");

	ClassInfo &cl = type_it->second;

	// Check if this signal is already register
	ClassInfo *check = &cl;
	while (check) {
		ERR_FAIL_COND_MSG(check->signal_names.find(p_signal.name) != check->signal_names.end(), String("Class '" + String(p_class) + "' already has signal '" + String(p_signal.name) + "'.").utf8().get_data());
		check = check->parent_ptr;
	}

	// register our signal in our plugin
	cl.signal_names.insert(p_signal.name);

	// register our signal in godot
	std::vector<GDNativePropertyInfo> parameters;
	parameters.reserve(p_signal.arguments.size());

	for (const PropertyInfo &par : p_signal.arguments) {
		parameters.push_back(GDNativePropertyInfo{
				static_cast<uint32_t>(par.type), // uint32_t type;
				par.name, // const char *name;
				par.class_name, // const char *class_name;
				par.hint, // uint32_t hint;
				par.hint_string, // const char *hint_string;
				par.usage, // uint32_t usage;
		});
	}

	internal::gdn_interface->classdb_register_extension_class_signal(internal::library, cl.name, p_signal.name, parameters.data(), parameters.size());
}

void ClassDB::bind_integer_constant(const char *p_class_name, const char *p_enum_name, const char *p_constant_name, GDNativeInt p_constant_value) {
	std::unordered_map<std::string, ClassInfo>::iterator type_it = classes.find(p_class_name);

	ERR_FAIL_COND_MSG(type_it == classes.end(), "Class doesn't exist.");

	ClassInfo &type = type_it->second;

	// check if it already exists
	ERR_FAIL_COND_MSG(type.constant_names.find(p_constant_name) != type.constant_names.end(), "Constant already registered.");

	// register it with our plugin (purely to check for duplicates)
	type.constant_names.insert(p_constant_name);

	// Register it with Godot
	internal::gdn_interface->classdb_register_extension_class_integer_constant(internal::library, p_class_name, p_enum_name, p_constant_name, p_constant_value);
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

void ClassDB::initialize_class(const ClassInfo &p_cl) {
}

void ClassDB::initialize(GDNativeInitializationLevel p_level) {
	for (const std::pair<std::string, ClassInfo> pair : classes) {
		const ClassInfo &cl = pair.second;
		if (cl.level != p_level) {
			continue;
		}

		// Nothing to do here for now...
	}
}

void ClassDB::deinitialize(GDNativeInitializationLevel p_level) {
	for (const std::pair<std::string, ClassInfo> pair : classes) {
		const ClassInfo &cl = pair.second;
		if (cl.level != p_level) {
			continue;
		}

		internal::gdn_interface->classdb_unregister_extension_class(internal::library, cl.name);

		for (auto method : cl.method_map) {
			memdelete(method.second);
		}
	}
}

} // namespace godot
