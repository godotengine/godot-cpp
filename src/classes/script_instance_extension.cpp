/**************************************************************************/
/*  script_instance_extension.cpp                                         */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include <godot_cpp/classes/script_instance_extension.hpp>

#include <godot_cpp/classes/script.hpp>
#include <godot_cpp/classes/script_language_extension.hpp>

using namespace godot;

GDExtensionBool ScriptInstanceExtension::gdextension_script_instance_set(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);
	const Variant *value = reinterpret_cast<const Variant *>(p_value);

	return instance->set(*name, *value);
}

GDExtensionBool ScriptInstanceExtension::gdextension_script_instance_get(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);
	Variant *ret = reinterpret_cast<Variant *>(r_ret);

	return instance->get(*name, *ret);
}

const GDExtensionPropertyInfo *ScriptInstanceExtension::gdextension_script_instance_get_property_list(GDExtensionScriptInstanceDataPtr p_instance, uint32_t *r_count) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);

	instance->get_property_list(&instance->property_list);

	if (instance->property_list.size() == 0) {
		*r_count = 0;
		return nullptr;
	}

	*r_count = instance->property_list.size();
	GDExtensionPropertyInfo *property_array = memnew_arr(GDExtensionPropertyInfo, instance->property_list.size());

	int index = 0;
	for (const PropertyInfo &prop : instance->property_list) {
		// @todo Do we need to allocate memory for the String and StringName pointers so the memory remains valid?
		property_array[index] = prop._to_gdextension();
		index++;
	}

	return property_array;
}

void ScriptInstanceExtension::gdextension_script_instance_free_property_list(GDExtensionScriptInstanceDataPtr p_instance, const GDExtensionPropertyInfo *p_list, uint32_t p_count) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	memfree((void *)p_list);
	instance->property_list.clear();
}

GDExtensionVariantType ScriptInstanceExtension::gdextension_script_instance_get_property_type(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);

	bool is_valid;
	GDExtensionVariantType ret = (GDExtensionVariantType)instance->get_property_type(*name, &is_valid);
	*r_is_valid = is_valid;

	return ret;
}

GDExtensionBool ScriptInstanceExtension::gdextension_script_instance_validate_property(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionPropertyInfo *p_property) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);

	PropertyInfo property(p_property);
	instance->validate_property(property);

	*p_property = property._to_gdextension();

	return true;
}

GDExtensionBool ScriptInstanceExtension::gdextension_script_instance_property_can_revert(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);

	return instance->property_can_revert(*name);
}

GDExtensionBool ScriptInstanceExtension::gdextension_script_instance_property_get_revert(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);
	Variant *ret = reinterpret_cast<Variant *>(r_ret);

	return instance->property_get_revert(*name, *ret);
}

GDExtensionObjectPtr ScriptInstanceExtension::gdextension_script_instance_get_owner(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);

	Object *ret = instance->get_owner();
	return ret->_owner;
}

void ScriptInstanceExtension::gdextension_script_instance_get_property_state(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionScriptInstancePropertyStateAdd p_add_func, void *p_userdata) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);

	List<Pair<StringName, Variant>> property_state;
	instance->get_property_state(property_state);

	for (const Pair<StringName, Variant> &state : property_state) {
		p_add_func(state.first._native_ptr(), state.second._native_ptr(), p_userdata);
	}
}

const GDExtensionMethodInfo *ScriptInstanceExtension::gdextension_script_instance_get_method_list(GDExtensionScriptInstanceDataPtr p_instance, uint32_t *r_count) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);

	List<MethodInfo> methods;
	instance->get_method_list(&methods);

	if (methods.size() == 0) {
		*r_count = 0;
		return nullptr;
	}

	*r_count = methods.size();
	GDExtensionMethodInfo *method_array = memnew_arr(GDExtensionMethodInfo, methods.size());

	int index = 0;
	for (const MethodInfo &method : methods) {
		method_array[index].name = method.name._native_ptr();
		method_array[index].return_value = method.return_val._to_gdextension();
		method_array[index].flags = method.flags;
		method_array[index].id = method.id;
		method_array[index].argument_count = method.arguments.size();
		method_array[index].arguments = memnew_arr(GDExtensionPropertyInfo, method.arguments.size());
		for (int n = 0; n < method.arguments.size(); n++) {
			method_array[index].arguments[n] = method.arguments[n]._to_gdextension();
		}
		method_array[index].default_argument_count = method.default_arguments.size();
		method_array[index].default_arguments = memnew_arr(GDExtensionVariantPtr, method.default_arguments.size());
		for (int n = 0; n < method.default_arguments.size(); n++) {
			method_array[index].default_arguments[n] = method.default_arguments[n]._native_ptr();
		}

		index++;
	}

	return method_array;
}

void ScriptInstanceExtension::gdextension_script_instance_free_method_list(GDExtensionScriptInstanceDataPtr p_instance, const GDExtensionMethodInfo *p_list, uint32_t p_count) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	for (int i = 0; i < p_count; i++) {
		memfree(p_list[i].arguments);
		memfree(p_list[i].default_arguments);
	}
	memfree((void *)p_list);
	instance->method_list.clear();
}

GDExtensionBool ScriptInstanceExtension::gdextension_script_instance_has_method(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);

	return instance->has_method(*name);
}

GDExtensionInt ScriptInstanceExtension::gdextension_script_instance_get_method_argument_count(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);

	bool is_valid;
	GDExtensionInt ret = instance->get_method_argument_count(*name, &is_valid);
	*r_is_valid = is_valid;

	return ret;
}

void ScriptInstanceExtension::gdextension_script_instance_call(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_method, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	const StringName *method = reinterpret_cast<const StringName *>(p_method);
	const Variant **args = reinterpret_cast<const Variant **>(const_cast<const void **>(p_args));
	Variant *ret = reinterpret_cast<Variant *>(r_return);

	Callable::CallError error;
	*ret = instance->callp(*method, args, p_argument_count, error);

	r_error->error = (GDExtensionCallErrorType)error.error;
	r_error->argument = error.argument;
	r_error->expected = error.expected;
}

void ScriptInstanceExtension::gdextension_script_instance_notification(GDExtensionScriptInstanceDataPtr p_instance, int32_t p_what, GDExtensionBool p_reversed) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	instance->notification(p_what, p_reversed);
}

void ScriptInstanceExtension::gdextension_script_instance_to_string(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	String *out = reinterpret_cast<String *>(r_out);

	bool is_valid = false;
	*out = instance->to_string(&is_valid);
	*r_is_valid = is_valid;
}

void ScriptInstanceExtension::gdextension_script_instance_refcount_incremented(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	instance->refcount_incremented();
}

GDExtensionBool ScriptInstanceExtension::gdextension_script_instance_refcount_decremented(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	return instance->refcount_decremented();
}

GDExtensionObjectPtr ScriptInstanceExtension::gdextension_script_instance_get_script(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	return instance->get_script()->_owner;
}

GDExtensionBool ScriptInstanceExtension::gdextension_script_instance_is_placeholder(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	return instance->is_placeholder();
}

GDExtensionBool ScriptInstanceExtension::gdextension_script_instance_set_fallback(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);
	const Variant *value = reinterpret_cast<const Variant *>(p_value);

	bool is_valid = false;
	instance->property_set_fallback(*name, *value, &is_valid);
	return is_valid;
}

GDExtensionBool ScriptInstanceExtension::gdextension_script_instance_get_fallback(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);
	Variant *ret = reinterpret_cast<Variant *>(r_ret);

	bool is_valid = false;
	instance->property_get_fallback(*name, &is_valid);
	return is_valid;
}

GDExtensionScriptLanguagePtr ScriptInstanceExtension::gdextension_script_instance_get_language(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
	return instance->get_language()->_owner;
}

void ScriptInstanceExtension::gdextension_script_instance_free(GDExtensionScriptInstanceDataPtr p_instance) {
	if (p_instance) {
		ScriptInstanceExtension *instance = reinterpret_cast<ScriptInstanceExtension *>(p_instance);
		memdelete(instance);
	}
}

thread_local List<PropertyInfo> ScriptInstanceExtension::property_list;
thread_local List<MethodInfo> ScriptInstanceExtension::method_list;

GDExtensionScriptInstanceInfo3 ScriptInstanceExtension::script_instance_info = {
	&ScriptInstanceExtension::gdextension_script_instance_set,
	&ScriptInstanceExtension::gdextension_script_instance_get,
	&ScriptInstanceExtension::gdextension_script_instance_get_property_list,
	&ScriptInstanceExtension::gdextension_script_instance_free_property_list,
	// We omit get_class_category_func for parity with Godot modules, which aren't able to
	// customize the category from the ScriptInstance - only the Script - which is what happens
	// if we omit this.
	nullptr,
	&ScriptInstanceExtension::gdextension_script_instance_property_can_revert,
	&ScriptInstanceExtension::gdextension_script_instance_property_get_revert,
	&ScriptInstanceExtension::gdextension_script_instance_get_owner,
	&ScriptInstanceExtension::gdextension_script_instance_get_property_state,
	&ScriptInstanceExtension::gdextension_script_instance_get_method_list,
	&ScriptInstanceExtension::gdextension_script_instance_free_method_list,
	&ScriptInstanceExtension::gdextension_script_instance_get_property_type,
	&ScriptInstanceExtension::gdextension_script_instance_validate_property,
	&ScriptInstanceExtension::gdextension_script_instance_has_method,
	&ScriptInstanceExtension::gdextension_script_instance_get_method_argument_count,
	&ScriptInstanceExtension::gdextension_script_instance_call,
	&ScriptInstanceExtension::gdextension_script_instance_notification,
	&ScriptInstanceExtension::gdextension_script_instance_to_string,
	&ScriptInstanceExtension::gdextension_script_instance_refcount_incremented,
	&ScriptInstanceExtension::gdextension_script_instance_refcount_decremented,
	&ScriptInstanceExtension::gdextension_script_instance_get_script,
	&ScriptInstanceExtension::gdextension_script_instance_is_placeholder,
	&ScriptInstanceExtension::gdextension_script_instance_set_fallback,
	&ScriptInstanceExtension::gdextension_script_instance_get_fallback,
	&ScriptInstanceExtension::gdextension_script_instance_get_language,
	&ScriptInstanceExtension::gdextension_script_instance_free,
};
