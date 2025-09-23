/**************************************************************************/
/*  script_instance.hpp                                                   */
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

#pragma once

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/templates/pair.hpp>
#include <godot_cpp/variant/string_name.hpp>

namespace godot {

class Script;
class ScriptExtension;
class ScriptLanguage;
class ScriptLanguageExtension;

class ScriptInstance {
	static GDExtensionScriptInstanceInfo3 script_instance_info;

	// Used to keep the refcounted properties alive after passing pointers to the data back to Godot.
	_GODOT_CPP_THREAD_LOCAL static List<PropertyInfo> property_list;
	_GODOT_CPP_THREAD_LOCAL static List<MethodInfo> method_list;

#ifdef _GODOT_CPP_AVOID_THREAD_LOCAL
	static std::recursive_mutex _property_list_mutex;
	static std::recursive_mutex _method_list_mutex;
#endif

	static GDExtensionBool gdextension_script_instance_set(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value);
	static GDExtensionBool gdextension_script_instance_get(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret);
	static const GDExtensionPropertyInfo *gdextension_script_instance_get_property_list(GDExtensionScriptInstanceDataPtr p_instance, uint32_t *r_count);
	static void gdextension_script_instance_free_property_list(GDExtensionScriptInstanceDataPtr p_instance, const GDExtensionPropertyInfo *p_list, uint32_t p_count);
	static GDExtensionVariantType gdextension_script_instance_get_property_type(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid);
	static GDExtensionBool gdextension_script_instance_validate_property(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionPropertyInfo *p_property);
	static GDExtensionBool gdextension_script_instance_property_can_revert(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name);
	static GDExtensionBool gdextension_script_instance_property_get_revert(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret);
	static GDExtensionObjectPtr gdextension_script_instance_get_owner(GDExtensionScriptInstanceDataPtr p_instance);
	static void gdextension_script_instance_get_property_state(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionScriptInstancePropertyStateAdd p_add_func, void *p_userdata);
	static const GDExtensionMethodInfo *gdextension_script_instance_get_method_list(GDExtensionScriptInstanceDataPtr p_instance, uint32_t *r_count);
	static void gdextension_script_instance_free_method_list(GDExtensionScriptInstanceDataPtr p_instance, const GDExtensionMethodInfo *p_list, uint32_t p_count);
	static GDExtensionBool gdextension_script_instance_has_method(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name);
	static GDExtensionInt gdextension_script_instance_get_method_argument_count(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid);
	static void gdextension_script_instance_call(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_method, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error);
	static void gdextension_script_instance_notification(GDExtensionScriptInstanceDataPtr p_instance, int32_t p_what, GDExtensionBool p_reversed);
	static void gdextension_script_instance_to_string(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out);
	static void gdextension_script_instance_refcount_incremented(GDExtensionScriptInstanceDataPtr p_instance);
	static GDExtensionBool gdextension_script_instance_refcount_decremented(GDExtensionScriptInstanceDataPtr p_instance);
	static GDExtensionObjectPtr gdextension_script_instance_get_script(GDExtensionScriptInstanceDataPtr p_instance);
	static GDExtensionBool gdextension_script_instance_is_placeholder(GDExtensionScriptInstanceDataPtr p_instance);
	static GDExtensionBool gdextension_script_instance_set_fallback(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value);
	static GDExtensionBool gdextension_script_instance_get_fallback(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret);
	static GDExtensionScriptLanguagePtr gdextension_script_instance_get_language(GDExtensionScriptInstanceDataPtr p_instance);
	static void gdextension_script_instance_free(GDExtensionScriptInstanceDataPtr p_instance);

	GDExtensionScriptInstancePtr _owner = nullptr;

public:
	GDExtensionScriptInstancePtr get_native_instance() {
		if (_owner == nullptr) {
			_owner = internal::gdextension_interface_script_instance_create3(&script_instance_info, this);
		}
		return _owner;
	}

	virtual bool set(const StringName &p_name, const Variant &p_value) = 0;
	virtual bool get(const StringName &p_name, Variant &r_ret) const = 0;
	virtual void get_property_list(List<PropertyInfo> *p_properties) const = 0;
	virtual Variant::Type get_property_type(const StringName &p_name, bool *r_is_valid) const = 0;
	virtual void validate_property(PropertyInfo &p_property) const = 0;
	virtual bool property_can_revert(const StringName &p_name) const = 0;
	virtual bool property_get_revert(const StringName &p_name, Variant &r_ret) const = 0;
	virtual Object *get_owner() = 0;
	virtual void get_property_state(List<Pair<StringName, Variant>> &state);
	virtual void get_method_list(List<MethodInfo> *p_info) const = 0;
	virtual bool has_method(const StringName &p_method) const = 0;
	virtual int get_method_argument_count(const StringName &p_method, bool *r_is_valid = nullptr) const = 0;
	virtual Variant callp(const StringName &p_method, const Variant **p_args, int p_argcount, Callable::CallError &r_error) = 0;
	virtual void notification(int p_notification, bool p_reversed) = 0;
	virtual String to_string(bool *r_valid) = 0;
	virtual void refcount_incremented() = 0;
	virtual bool refcount_decremented() = 0;
	virtual Ref<Script> get_script() const = 0;
	virtual bool is_placeholder() const = 0;
	virtual void property_set_fallback(const StringName &p_name, const Variant &p_value, bool *r_valid) = 0;
	virtual Variant property_get_fallback(const StringName &p_name, bool *r_valid) = 0;
	virtual ScriptLanguage *get_language() = 0;

	virtual ~ScriptInstance(){};
};

class PlaceHolderScriptInstance : public ScriptInstance {
	Object *owner = nullptr;
	List<PropertyInfo> properties;
	HashMap<StringName, Variant> values;
	Dictionary constants;
	ScriptLanguageExtension *language = nullptr;
	Ref<ScriptExtension> script;

public:
	virtual bool set(const StringName &p_name, const Variant &p_value) override;
	virtual bool get(const StringName &p_name, Variant &r_ret) const override;
	virtual void get_property_list(List<PropertyInfo> *p_properties) const override;
	virtual Variant::Type get_property_type(const StringName &p_name, bool *r_is_valid = nullptr) const override;
	virtual void validate_property(PropertyInfo &p_property) const override {}

	virtual bool property_can_revert(const StringName &p_name) const override { return false; }
	virtual bool property_get_revert(const StringName &p_name, Variant &r_ret) const override { return false; }

	virtual void get_method_list(List<MethodInfo> *p_list) const override;
	virtual bool has_method(const StringName &p_method) const override;

	virtual int get_method_argument_count(const StringName &p_method, bool *r_is_valid = nullptr) const override {
		if (r_is_valid) {
			*r_is_valid = false;
		}
		return 0;
	}

	virtual Variant callp(const StringName &p_method, const Variant **p_args, int p_argcount, Callable::CallError &r_error) override;
	virtual void notification(int p_notification, bool p_reversed = false) override {}

	virtual Ref<Script> get_script() const override { return script; }

	virtual ScriptLanguage *get_language() override { return (ScriptLanguage *)language; }

	Object *get_owner() override { return owner; }

	void update(const List<PropertyInfo> &p_properties, const HashMap<StringName, Variant> &p_values);

	virtual bool is_placeholder() const override { return true; }

	virtual void property_set_fallback(const StringName &p_name, const Variant &p_value, bool *r_valid = nullptr) override;
	virtual Variant property_get_fallback(const StringName &p_name, bool *r_valid = nullptr) override;

	PlaceHolderScriptInstance(ScriptLanguageExtension *p_language, Ref<ScriptExtension> p_script, Object *p_owner);
	~PlaceHolderScriptInstance();
};

}; // namespace godot
