/**************************************************************************/
/*  script_instance.cpp                                                   */
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

#include <godot_cpp/classes/script_instance.hpp>

#include <godot_cpp/classes/script_extension.hpp>
#include <godot_cpp/classes/script_language_extension.hpp>
#include <godot_cpp/templates/hash_set.hpp>

using namespace godot;

GDExtensionBool ScriptInstance::gdextension_script_instance_set(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);
	const Variant *value = reinterpret_cast<const Variant *>(p_value);

	return instance->set(*name, *value);
}

GDExtensionBool ScriptInstance::gdextension_script_instance_get(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);
	Variant *ret = reinterpret_cast<Variant *>(r_ret);

	return instance->get(*name, *ret);
}

const GDExtensionPropertyInfo *ScriptInstance::gdextension_script_instance_get_property_list(GDExtensionScriptInstanceDataPtr p_instance, uint32_t *r_count) {
#ifdef _GODOT_CPP_AVOID_THREAD_LOCAL
	_property_list_mutex.lock();
#endif

	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);

	instance->get_property_list(&property_list);

	if (property_list.size() == 0) {
		*r_count = 0;
		return nullptr;
	}

	*r_count = property_list.size();
	GDExtensionPropertyInfo *property_array = memnew_arr(GDExtensionPropertyInfo, property_list.size());

	int index = 0;
	for (const PropertyInfo &prop : property_list) {
		property_array[index] = prop._to_gdextension();
		index++;
	}

	return property_array;
}

void ScriptInstance::gdextension_script_instance_free_property_list(GDExtensionScriptInstanceDataPtr p_instance, const GDExtensionPropertyInfo *p_list, uint32_t p_count) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	memfree((void *)p_list);
	property_list.clear();

#ifdef _GODOT_CPP_AVOID_THREAD_LOCAL
	_property_list_mutex.unlock();
#endif
}

GDExtensionVariantType ScriptInstance::gdextension_script_instance_get_property_type(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);

	bool is_valid;
	GDExtensionVariantType ret = (GDExtensionVariantType)instance->get_property_type(*name, &is_valid);
	*r_is_valid = is_valid;

	return ret;
}

GDExtensionBool ScriptInstance::gdextension_script_instance_validate_property(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionPropertyInfo *p_property) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);

	PropertyInfo property_to_validate(p_property);
	instance->validate_property(property_to_validate);

	// @todo Check if any changes were made and return false if nothing changed

	// We can't use `property_to_validate._to_gdextension()` here, because the memory the pointers point to
	// will no longer be valid as soon as this function returns. Instead, we have to copy into the original
	// memory that is pointed to by `p_property`, like this:
	*((StringName *)p_property->name) = property_to_validate.name;
	*((StringName *)p_property->class_name) = property_to_validate.class_name;
	*((String *)p_property->hint_string) = property_to_validate.hint_string;

	p_property->type = (GDExtensionVariantType)property_to_validate.type;
	p_property->hint = property_to_validate.hint;
	p_property->usage = property_to_validate.usage;

	return true;
}

GDExtensionBool ScriptInstance::gdextension_script_instance_property_can_revert(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);

	return instance->property_can_revert(*name);
}

GDExtensionBool ScriptInstance::gdextension_script_instance_property_get_revert(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);
	Variant *ret = reinterpret_cast<Variant *>(r_ret);

	return instance->property_get_revert(*name, *ret);
}

GDExtensionObjectPtr ScriptInstance::gdextension_script_instance_get_owner(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);

	Object *ret = instance->get_owner();
	return ret->_owner;
}

void ScriptInstance::gdextension_script_instance_get_property_state(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionScriptInstancePropertyStateAdd p_add_func, void *p_userdata) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);

	List<Pair<StringName, Variant>> property_state;
	instance->get_property_state(property_state);

	for (const Pair<StringName, Variant> &state : property_state) {
		p_add_func(state.first._native_ptr(), state.second._native_ptr(), p_userdata);
	}
}

const GDExtensionMethodInfo *ScriptInstance::gdextension_script_instance_get_method_list(GDExtensionScriptInstanceDataPtr p_instance, uint32_t *r_count) {
#ifdef _GODOT_CPP_AVOID_THREAD_LOCAL
	_method_list_mutex.lock();
#endif

	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);

	instance->get_method_list(&method_list);

	if (method_list.size() == 0) {
		*r_count = 0;
		return nullptr;
	}

	*r_count = method_list.size();
	GDExtensionMethodInfo *method_array = memnew_arr(GDExtensionMethodInfo, method_list.size());

	int index = 0;
	for (const MethodInfo &method : method_list) {
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

void ScriptInstance::gdextension_script_instance_free_method_list(GDExtensionScriptInstanceDataPtr p_instance, const GDExtensionMethodInfo *p_list, uint32_t p_count) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	for (int i = 0; i < p_count; i++) {
		memfree(p_list[i].arguments);
		memfree(p_list[i].default_arguments);
	}
	memfree((void *)p_list);
	method_list.clear();

#ifdef _GODOT_CPP_AVOID_THREAD_LOCAL
	_method_list_mutex.unlock();
#endif
}

GDExtensionBool ScriptInstance::gdextension_script_instance_has_method(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);

	return instance->has_method(*name);
}

GDExtensionInt ScriptInstance::gdextension_script_instance_get_method_argument_count(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);

	bool is_valid;
	GDExtensionInt ret = instance->get_method_argument_count(*name, &is_valid);
	*r_is_valid = is_valid;

	return ret;
}

void ScriptInstance::gdextension_script_instance_call(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_method, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	const StringName *method = reinterpret_cast<const StringName *>(p_method);
	const Variant **args = reinterpret_cast<const Variant **>(const_cast<const void **>(p_args));
	Variant *ret = reinterpret_cast<Variant *>(r_return);

	Callable::CallError error;
	*ret = instance->callp(*method, args, p_argument_count, error);

	r_error->error = (GDExtensionCallErrorType)error.error;
	r_error->argument = error.argument;
	r_error->expected = error.expected;
}

void ScriptInstance::gdextension_script_instance_notification(GDExtensionScriptInstanceDataPtr p_instance, int32_t p_what, GDExtensionBool p_reversed) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	instance->notification(p_what, p_reversed);
}

void ScriptInstance::gdextension_script_instance_to_string(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	String *out = reinterpret_cast<String *>(r_out);

	bool is_valid = false;
	*out = instance->to_string(&is_valid);
	*r_is_valid = is_valid;
}

void ScriptInstance::gdextension_script_instance_refcount_incremented(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	instance->refcount_incremented();
}

GDExtensionBool ScriptInstance::gdextension_script_instance_refcount_decremented(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	return instance->refcount_decremented();
}

GDExtensionObjectPtr ScriptInstance::gdextension_script_instance_get_script(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	return instance->get_script()->_owner;
}

GDExtensionBool ScriptInstance::gdextension_script_instance_is_placeholder(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	return instance->is_placeholder();
}

GDExtensionBool ScriptInstance::gdextension_script_instance_set_fallback(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);
	const Variant *value = reinterpret_cast<const Variant *>(p_value);

	bool is_valid = false;
	instance->property_set_fallback(*name, *value, &is_valid);
	return is_valid;
}

GDExtensionBool ScriptInstance::gdextension_script_instance_get_fallback(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	const StringName *name = reinterpret_cast<const StringName *>(p_name);
	Variant *ret = reinterpret_cast<Variant *>(r_ret);

	bool is_valid = false;
	instance->property_get_fallback(*name, &is_valid);
	return is_valid;
}

GDExtensionScriptLanguagePtr ScriptInstance::gdextension_script_instance_get_language(GDExtensionScriptInstanceDataPtr p_instance) {
	ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
	return instance->get_language()->_owner;
}

void ScriptInstance::gdextension_script_instance_free(GDExtensionScriptInstanceDataPtr p_instance) {
	if (p_instance) {
		ScriptInstance *instance = reinterpret_cast<ScriptInstance *>(p_instance);
		memdelete(instance);
	}
}

void ScriptInstance::get_property_state(List<Pair<StringName, Variant>> &state) {
	List<PropertyInfo> pinfo;
	get_property_list(&pinfo);
	for (const PropertyInfo &E : pinfo) {
		if (E.usage & PROPERTY_USAGE_STORAGE) {
			Pair<StringName, Variant> p;
			p.first = E.name;
			if (get(p.first, p.second)) {
				state.push_back(p);
			}
		}
	}
}

_GODOT_CPP_THREAD_LOCAL List<PropertyInfo> ScriptInstance::property_list;
_GODOT_CPP_THREAD_LOCAL List<MethodInfo> ScriptInstance::method_list;

#ifdef _GODOT_CPP_AVOID_THREAD_LOCAL
std::recursive_mutex ScriptInstance::_property_list_mutex;
std::recursive_mutex ScriptInstance::_method_list_mutex;
#endif

GDExtensionScriptInstanceInfo3 ScriptInstance::script_instance_info = {
	&ScriptInstance::gdextension_script_instance_set,
	&ScriptInstance::gdextension_script_instance_get,
	&ScriptInstance::gdextension_script_instance_get_property_list,
	&ScriptInstance::gdextension_script_instance_free_property_list,
	// We omit get_class_category_func for parity with Godot modules, which aren't able to
	// customize the category from the ScriptInstance - only the Script - which is what happens
	// if we omit this.
	nullptr,
	&ScriptInstance::gdextension_script_instance_property_can_revert,
	&ScriptInstance::gdextension_script_instance_property_get_revert,
	&ScriptInstance::gdextension_script_instance_get_owner,
	&ScriptInstance::gdextension_script_instance_get_property_state,
	&ScriptInstance::gdextension_script_instance_get_method_list,
	&ScriptInstance::gdextension_script_instance_free_method_list,
	&ScriptInstance::gdextension_script_instance_get_property_type,
	&ScriptInstance::gdextension_script_instance_validate_property,
	&ScriptInstance::gdextension_script_instance_has_method,
	&ScriptInstance::gdextension_script_instance_get_method_argument_count,
	&ScriptInstance::gdextension_script_instance_call,
	&ScriptInstance::gdextension_script_instance_notification,
	&ScriptInstance::gdextension_script_instance_to_string,
	&ScriptInstance::gdextension_script_instance_refcount_incremented,
	&ScriptInstance::gdextension_script_instance_refcount_decremented,
	&ScriptInstance::gdextension_script_instance_get_script,
	&ScriptInstance::gdextension_script_instance_is_placeholder,
	&ScriptInstance::gdextension_script_instance_set_fallback,
	&ScriptInstance::gdextension_script_instance_get_fallback,
	&ScriptInstance::gdextension_script_instance_get_language,
	&ScriptInstance::gdextension_script_instance_free,
};

bool PlaceHolderScriptInstance::set(const StringName &p_name, const Variant &p_value) {
	if (script->_is_placeholder_fallback_enabled()) {
		return false;
	}

	if (values.has(p_name)) {
		if (script->_has_property_default_value(p_name)) {
			Variant defval = script->_get_property_default_value(p_name);
			// The evaluate function ensures that a NIL variant is equal to e.g. an empty Resource.
			// Simply doing defval == p_value does not do this.
			if (Variant::evaluate(Variant::OP_EQUAL, defval, p_value)) {
				values.erase(p_name);
				return true;
			}
		}
		values[p_name] = p_value;
		return true;
	} else {
		if (script->_has_property_default_value(p_name)) {
			Variant defval = script->_get_property_default_value(p_name);
			if (Variant::evaluate(Variant::OP_NOT_EQUAL, defval, p_value)) {
				values[p_name] = p_value;
			}
		}
		return true;
	}
	return false;
}

bool PlaceHolderScriptInstance::get(const StringName &p_name, Variant &r_ret) const {
	if (values.has(p_name)) {
		r_ret = values[p_name];
		return true;
	}

	if (constants.has(p_name)) {
		r_ret = constants[p_name];
		return true;
	}

	if (!script->_is_placeholder_fallback_enabled()) {
		if (script->_has_property_default_value(p_name)) {
			r_ret = script->_get_property_default_value(p_name);
			return true;
		}
	}

	return false;
}

void PlaceHolderScriptInstance::get_property_list(List<PropertyInfo> *p_properties) const {
	if (script->_is_placeholder_fallback_enabled()) {
		for (const PropertyInfo &E : properties) {
			p_properties->push_back(E);
		}
	} else {
		for (const PropertyInfo &E : properties) {
			PropertyInfo pinfo = E;
			p_properties->push_back(E);
		}
	}
}

Variant::Type PlaceHolderScriptInstance::get_property_type(const StringName &p_name, bool *r_is_valid) const {
	if (values.has(p_name)) {
		if (r_is_valid) {
			*r_is_valid = true;
		}
		return values[p_name].get_type();
	}

	if (constants.has(p_name)) {
		if (r_is_valid) {
			*r_is_valid = true;
		}
		return constants[p_name].get_type();
	}

	if (r_is_valid) {
		*r_is_valid = false;
	}

	return Variant::NIL;
}

void PlaceHolderScriptInstance::get_method_list(List<MethodInfo> *p_list) const {
	if (script->_is_placeholder_fallback_enabled()) {
		return;
	}

	if (script.is_valid()) {
		TypedArray<Dictionary> methods = script->_get_script_method_list();
		for (int i = 0; i < methods.size(); i++) {
			p_list->push_back(MethodInfo::from_dict(methods[i]));
		}
	}
}

bool PlaceHolderScriptInstance::has_method(const StringName &p_method) const {
	if (script->_is_placeholder_fallback_enabled()) {
		return false;
	}

	if (script.is_valid()) {
		Ref<Script> scr = script;
		while (scr.is_valid()) {
			if (scr->has_method(p_method)) {
				return true;
			}
			scr = scr->get_base_script();
		}
	}
	return false;
}

Variant PlaceHolderScriptInstance::callp(const StringName &p_method, const Variant **p_args, int p_argcount, Callable::CallError &r_error) {
	r_error.error = Callable::CallError::CALL_ERROR_INVALID_METHOD;
#if TOOLS_ENABLED
	if (Engine::get_singleton()->is_editor_hint()) {
		return String("Attempt to call a method on a placeholder instance. Check if the script is in tool mode.");
	} else {
		return String("Attempt to call a method on a placeholder instance. Probably a bug, please report.");
	}
#else
	return Variant();
#endif // TOOLS_ENABLED
}

void PlaceHolderScriptInstance::update(const List<PropertyInfo> &p_properties, const HashMap<StringName, Variant> &p_values) {
	HashSet<StringName> new_values;
	for (const PropertyInfo &E : p_properties) {
		if (E.usage & (PROPERTY_USAGE_GROUP | PROPERTY_USAGE_SUBGROUP | PROPERTY_USAGE_CATEGORY)) {
			continue;
		}

		StringName n = E.name;
		new_values.insert(n);

		if (!values.has(n) || values[n].get_type() != E.type) {
			if (p_values.has(n)) {
				values[n] = p_values[n];
			}
		}
	}

	properties = p_properties;
	List<StringName> to_remove;

	for (KeyValue<StringName, Variant> &E : values) {
		if (!new_values.has(E.key)) {
			to_remove.push_back(E.key);
		}

		if (script->_has_property_default_value(E.key)) {
			Variant defval = script->_get_property_default_value(E.key);
			//remove because it's the same as the default value
			if (defval == E.value) {
				to_remove.push_back(E.key);
			}
		}
	}

	while (to_remove.size()) {
		values.erase(to_remove.front()->get());
		to_remove.pop_front();
	}

	if (owner) {
		GDExtensionScriptInstanceDataPtr script_instance = internal::gdextension_interface_object_get_script_instance(owner->_owner, language->_owner);
		if (get_native_instance() == script_instance) {
			owner->notify_property_list_changed();
		}
	}

	constants = script->_get_constants();
}

void PlaceHolderScriptInstance::property_set_fallback(const StringName &p_name, const Variant &p_value, bool *r_valid) {
	if (script->_is_placeholder_fallback_enabled()) {
		HashMap<StringName, Variant>::Iterator E = values.find(p_name);

		if (E) {
			E->value = p_value;
		} else {
			values.insert(p_name, p_value);
		}

		bool found = false;
		for (const PropertyInfo &F : properties) {
			if (F.name == p_name) {
				found = true;
				break;
			}
		}
		if (!found) {
			PropertyHint hint = PROPERTY_HINT_NONE;
			const Object *obj = p_value.get_validated_object();
			if (obj && obj->is_class("Node")) {
				hint = PROPERTY_HINT_NODE_TYPE;
			}
			properties.push_back(PropertyInfo(p_value.get_type(), p_name, hint, "", PROPERTY_USAGE_NO_EDITOR | PROPERTY_USAGE_SCRIPT_VARIABLE));
		}
	}

	if (r_valid) {
		*r_valid = false; // Cannot change the value in either case
	}
}

Variant PlaceHolderScriptInstance::property_get_fallback(const StringName &p_name, bool *r_valid) {
	if (script->_is_placeholder_fallback_enabled()) {
		HashMap<StringName, Variant>::ConstIterator E = values.find(p_name);

		if (E) {
			if (r_valid) {
				*r_valid = true;
			}
			return E->value;
		}

		if (constants.has(p_name)) {
			if (r_valid) {
				*r_valid = true;
			}
			return constants[p_name];
		}
	}

	if (r_valid) {
		*r_valid = false;
	}

	return Variant();
}

PlaceHolderScriptInstance::PlaceHolderScriptInstance(ScriptLanguageExtension *p_language, Ref<ScriptExtension> p_script, Object *p_owner) :
		owner(p_owner),
		language(p_language),
		script(p_script) {
}

PlaceHolderScriptInstance::~PlaceHolderScriptInstance() {
	if (script.is_valid()) {
		script->_placeholder_erased(this);
	}
}
