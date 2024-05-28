/**************************************************************************/
/*  wrapped.hpp                                                           */
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

#ifndef GODOT_WRAPPED_HPP
#define GODOT_WRAPPED_HPP

#include <godot_cpp/core/memory.hpp>

#include <godot_cpp/core/property_info.hpp>

#include <godot_cpp/templates/list.hpp>

#include <godot_cpp/godot.hpp>

namespace godot {

class ClassDB;

typedef void GodotObject;

// Base for all engine classes, to contain the pointer to the engine instance.
class Wrapped {
	friend class GDExtensionBinding;
	friend class ClassDB;
	friend void postinitialize_handler(Wrapped *);

protected:
#ifdef HOT_RELOAD_ENABLED
	struct RecreateInstance {
		GDExtensionClassInstancePtr wrapper;
		GDExtensionObjectPtr owner;
		RecreateInstance *next;
	};
	inline static RecreateInstance *recreate_instance = nullptr;
#endif

	virtual const StringName *_get_extension_class_name() const; // This is needed to retrieve the class name before the godot object has its _extension and _extension_instance members assigned.
	virtual const GDExtensionInstanceBindingCallbacks *_get_bindings_callbacks() const = 0;

	void _notification(int p_what) {}
	bool _set(const StringName &p_name, const Variant &p_property) { return false; }
	bool _get(const StringName &p_name, Variant &r_property) const { return false; }
	void _get_property_list(List<PropertyInfo> *p_list) const {}
	bool _property_can_revert(const StringName &p_name) const { return false; }
	bool _property_get_revert(const StringName &p_name, Variant &r_property) const { return false; }
	void _validate_property(PropertyInfo &p_property) const {}
	String _to_string() const { return "[" + String(get_class_static()) + ":" + itos(get_instance_id()) + "]"; }

	static void notification_bind(GDExtensionClassInstancePtr p_instance, int32_t p_what, GDExtensionBool p_reversed) {}
	static GDExtensionBool set_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) { return false; }
	static GDExtensionBool get_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) { return false; }
	static const GDExtensionPropertyInfo *get_property_list_bind(GDExtensionClassInstancePtr p_instance, uint32_t *r_count) { return nullptr; }
	static void free_property_list_bind(GDExtensionClassInstancePtr p_instance, const GDExtensionPropertyInfo *p_list) {}
	static GDExtensionBool property_can_revert_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name) { return false; }
	static GDExtensionBool property_get_revert_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) { return false; }
	static GDExtensionBool validate_property_bind(GDExtensionClassInstancePtr p_instance, GDExtensionPropertyInfo *p_property) { return false; }
	static void to_string_bind(GDExtensionClassInstancePtr p_instance, GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out) {}

	// The only reason this has to be held here, is when we return results of `_get_property_list` to Godot, we pass
	// pointers to strings in this list. They have to remain valid to pass the bridge, until the list is freed by Godot...
	::godot::List<::godot::PropertyInfo> plist_owned;

	void _postinitialize();
	virtual void _notificationv(int32_t p_what, bool p_reversed = false) {}

	Wrapped(const StringName p_godot_class);
	Wrapped(GodotObject *p_godot_object);
	virtual ~Wrapped() {}

public:
	static const StringName &get_class_static() {
		static const StringName string_name = StringName("Wrapped");
		return string_name;
	}

	uint64_t get_instance_id() const {
		return 0;
	}

	// Must be public but you should not touch this.
	GodotObject *_owner = nullptr;
};

namespace internal {

GDExtensionPropertyInfo *create_c_property_list(const ::godot::List<::godot::PropertyInfo> &plist_cpp, uint32_t *r_size);
void free_c_property_list(GDExtensionPropertyInfo *plist);

typedef void (*EngineClassRegistrationCallback)();
void add_engine_class_registration_callback(EngineClassRegistrationCallback p_callback);
void register_engine_class(const StringName &p_name, const GDExtensionInstanceBindingCallbacks *p_callbacks);
void register_engine_classes();

template <typename T>
struct EngineClassRegistration {
	EngineClassRegistration() {
		add_engine_class_registration_callback(&EngineClassRegistration<T>::callback);
	}

	static void callback() {
		register_engine_class(T::get_class_static(), &T::_gde_binding_callbacks);
	}
};

} // namespace internal

} // namespace godot

// Use this on top of your own classes.
// Note: the trail of `***` is to keep sane diffs in PRs, because clang-format otherwise moves every `\` which makes
// every line of the macro different
#define GDCLASS(m_class, m_inherits) /***********************************************************************************************************************************************/ \
private:                                                                                                                                                                               \
	void operator=(const m_class &p_rval) {}                                                                                                                                           \
	friend class ::godot::ClassDB;                                                                                                                                                     \
                                                                                                                                                                                       \
protected:                                                                                                                                                                             \
	virtual const ::godot::StringName *_get_extension_class_name() const override {                                                                                                    \
		static ::godot::StringName string_name = get_class_static();                                                                                                                   \
		return &string_name;                                                                                                                                                           \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	virtual const GDExtensionInstanceBindingCallbacks *_get_bindings_callbacks() const override {                                                                                      \
		return &_gde_binding_callbacks;                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void (*_get_bind_methods())() {                                                                                                                                             \
		return &m_class::_bind_methods;                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void (::godot::Wrapped::*_get_notification())(int) {                                                                                                                        \
		return (void(::godot::Wrapped::*)(int)) & m_class::_notification;                                                                                                              \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static bool (::godot::Wrapped::*_get_set())(const ::godot::StringName &p_name, const ::godot::Variant &p_property) {                                                               \
		return (bool(::godot::Wrapped::*)(const ::godot::StringName &p_name, const ::godot::Variant &p_property)) & m_class::_set;                                                     \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static bool (::godot::Wrapped::*_get_get())(const ::godot::StringName &p_name, ::godot::Variant &r_ret) const {                                                                    \
		return (bool(::godot::Wrapped::*)(const ::godot::StringName &p_name, ::godot::Variant &r_ret) const) & m_class::_get;                                                          \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void (::godot::Wrapped::*_get_get_property_list())(::godot::List<::godot::PropertyInfo> * p_list) const {                                                                   \
		return (void(::godot::Wrapped::*)(::godot::List<::godot::PropertyInfo> * p_list) const) & m_class::_get_property_list;                                                         \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static bool (::godot::Wrapped::*_get_property_can_revert())(const ::godot::StringName &p_name) const {                                                                             \
		return (bool(::godot::Wrapped::*)(const ::godot::StringName &p_name) const) & m_class::_property_can_revert;                                                                   \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static bool (::godot::Wrapped::*_get_property_get_revert())(const ::godot::StringName &p_name, ::godot::Variant &) const {                                                         \
		return (bool(::godot::Wrapped::*)(const ::godot::StringName &p_name, ::godot::Variant &) const) & m_class::_property_get_revert;                                               \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void (::godot::Wrapped::*_get_validate_property())(::godot::PropertyInfo & p_property) const {                                                                              \
		return (void(::godot::Wrapped::*)(::godot::PropertyInfo & p_property) const) & m_class::_validate_property;                                                                    \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static ::godot::String (::godot::Wrapped::*_get_to_string())() const {                                                                                                             \
		return (::godot::String(::godot::Wrapped::*)() const) & m_class::_to_string;                                                                                                   \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	template <typename T, typename B>                                                                                                                                                  \
	static void register_virtuals() {                                                                                                                                                  \
		m_inherits::register_virtuals<T, B>();                                                                                                                                         \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
public:                                                                                                                                                                                \
	typedef m_class self_type;                                                                                                                                                         \
	typedef m_inherits parent_type;                                                                                                                                                    \
                                                                                                                                                                                       \
	static void initialize_class() {                                                                                                                                                   \
		static bool initialized = false;                                                                                                                                               \
		if (initialized) {                                                                                                                                                             \
			return;                                                                                                                                                                    \
		}                                                                                                                                                                              \
		m_inherits::initialize_class();                                                                                                                                                \
		if (m_class::_get_bind_methods() != m_inherits::_get_bind_methods()) {                                                                                                         \
			_bind_methods();                                                                                                                                                           \
			m_inherits::register_virtuals<m_class, m_inherits>();                                                                                                                      \
		}                                                                                                                                                                              \
		initialized = true;                                                                                                                                                            \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static const ::godot::StringName &get_class_static() {                                                                                                                             \
		static const ::godot::StringName string_name = ::godot::StringName(#m_class);                                                                                                  \
		return string_name;                                                                                                                                                            \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static const ::godot::StringName &get_parent_class_static() {                                                                                                                      \
		return m_inherits::get_class_static();                                                                                                                                         \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void notification_bind(GDExtensionClassInstancePtr p_instance, int32_t p_what, GDExtensionBool p_reversed) {                                                                \
		if (p_instance && m_class::_get_notification()) {                                                                                                                              \
			if (!p_reversed) {                                                                                                                                                         \
				m_inherits::notification_bind(p_instance, p_what, p_reversed);                                                                                                         \
			}                                                                                                                                                                          \
			if (m_class::_get_notification() != m_inherits::_get_notification()) {                                                                                                     \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                                                \
				cls->_notification(p_what);                                                                                                                                            \
			}                                                                                                                                                                          \
			if (p_reversed) {                                                                                                                                                          \
				m_inherits::notification_bind(p_instance, p_what, p_reversed);                                                                                                         \
			}                                                                                                                                                                          \
		}                                                                                                                                                                              \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static GDExtensionBool set_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) {                                \
		if (p_instance && m_class::_get_set()) {                                                                                                                                       \
			if (m_class::_get_set() != m_inherits::_get_set()) {                                                                                                                       \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                                                \
				return cls->_set(*reinterpret_cast<const ::godot::StringName *>(p_name), *reinterpret_cast<const ::godot::Variant *>(p_value));                                        \
			}                                                                                                                                                                          \
			return m_inherits::set_bind(p_instance, p_name, p_value);                                                                                                                  \
		}                                                                                                                                                                              \
		return false;                                                                                                                                                                  \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static GDExtensionBool get_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {                                       \
		if (p_instance && m_class::_get_get()) {                                                                                                                                       \
			if (m_class::_get_get() != m_inherits::_get_get()) {                                                                                                                       \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                                                \
				return cls->_get(*reinterpret_cast<const ::godot::StringName *>(p_name), *reinterpret_cast<::godot::Variant *>(r_ret));                                                \
			}                                                                                                                                                                          \
			return m_inherits::get_bind(p_instance, p_name, r_ret);                                                                                                                    \
		}                                                                                                                                                                              \
		return false;                                                                                                                                                                  \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static inline bool has_get_property_list() {                                                                                                                                       \
		return m_class::_get_get_property_list() && m_class::_get_get_property_list() != m_inherits::_get_get_property_list();                                                         \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static const GDExtensionPropertyInfo *get_property_list_bind(GDExtensionClassInstancePtr p_instance, uint32_t *r_count) {                                                          \
		if (!p_instance) {                                                                                                                                                             \
			if (r_count)                                                                                                                                                               \
				*r_count = 0;                                                                                                                                                          \
			return nullptr;                                                                                                                                                            \
		}                                                                                                                                                                              \
		m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                                                        \
		::godot::List<::godot::PropertyInfo> &plist_cpp = cls->plist_owned;                                                                                                            \
		ERR_FAIL_COND_V_MSG(!plist_cpp.is_empty(), nullptr, "Internal error, property list was not freed by engine!");                                                                 \
		cls->_get_property_list(&plist_cpp);                                                                                                                                           \
		return ::godot::internal::create_c_property_list(plist_cpp, r_count);                                                                                                          \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void free_property_list_bind(GDExtensionClassInstancePtr p_instance, const GDExtensionPropertyInfo *p_list) {                                                               \
		if (p_instance) {                                                                                                                                                              \
			m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                                                    \
			cls->plist_owned.clear();                                                                                                                                                  \
			::godot::internal::free_c_property_list(const_cast<GDExtensionPropertyInfo *>(p_list));                                                                                    \
		}                                                                                                                                                                              \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static GDExtensionBool property_can_revert_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name) {                                                    \
		if (p_instance && m_class::_get_property_can_revert()) {                                                                                                                       \
			if (m_class::_get_property_can_revert() != m_inherits::_get_property_can_revert()) {                                                                                       \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                                                \
				return cls->_property_can_revert(*reinterpret_cast<const ::godot::StringName *>(p_name));                                                                              \
			}                                                                                                                                                                          \
			return m_inherits::property_can_revert_bind(p_instance, p_name);                                                                                                           \
		}                                                                                                                                                                              \
		return false;                                                                                                                                                                  \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static GDExtensionBool property_get_revert_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {                       \
		if (p_instance && m_class::_get_property_get_revert()) {                                                                                                                       \
			if (m_class::_get_property_get_revert() != m_inherits::_get_property_get_revert()) {                                                                                       \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                                                \
				return cls->_property_get_revert(*reinterpret_cast<const ::godot::StringName *>(p_name), *reinterpret_cast<::godot::Variant *>(r_ret));                                \
			}                                                                                                                                                                          \
			return m_inherits::property_get_revert_bind(p_instance, p_name, r_ret);                                                                                                    \
		}                                                                                                                                                                              \
		return false;                                                                                                                                                                  \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static GDExtensionBool validate_property_bind(GDExtensionClassInstancePtr p_instance, GDExtensionPropertyInfo *p_property) {                                                       \
		bool ret = false;                                                                                                                                                              \
		if (p_instance && m_class::_get_validate_property()) {                                                                                                                         \
			ret = m_inherits::validate_property_bind(p_instance, p_property);                                                                                                          \
			if (m_class::_get_validate_property() != m_inherits::_get_validate_property()) {                                                                                           \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                                                \
				::godot::PropertyInfo info(p_property);                                                                                                                                \
				cls->_validate_property(info);                                                                                                                                         \
				info._update(p_property);                                                                                                                                              \
				return true;                                                                                                                                                           \
			}                                                                                                                                                                          \
		}                                                                                                                                                                              \
		return ret;                                                                                                                                                                    \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void to_string_bind(GDExtensionClassInstancePtr p_instance, GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out) {                                                      \
		if (p_instance && m_class::_get_to_string()) {                                                                                                                                 \
			if (m_class::_get_to_string() != m_inherits::_get_to_string()) {                                                                                                           \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                                                \
				*reinterpret_cast<::godot::String *>(r_out) = cls->_to_string();                                                                                                       \
				*r_is_valid = true;                                                                                                                                                    \
				return;                                                                                                                                                                \
			}                                                                                                                                                                          \
			m_inherits::to_string_bind(p_instance, r_is_valid, r_out);                                                                                                                 \
		}                                                                                                                                                                              \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void free(void *data, GDExtensionClassInstancePtr ptr) {                                                                                                                    \
		if (ptr) {                                                                                                                                                                     \
			m_class *cls = reinterpret_cast<m_class *>(ptr);                                                                                                                           \
			cls->~m_class();                                                                                                                                                           \
			::godot::Memory::free_static(cls);                                                                                                                                         \
		}                                                                                                                                                                              \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void *_gde_binding_create_callback(void *p_token, void *p_instance) {                                                                                                       \
		return nullptr;                                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void _gde_binding_free_callback(void *p_token, void *p_instance, void *p_binding) {                                                                                         \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static GDExtensionBool _gde_binding_reference_callback(void *p_token, void *p_instance, GDExtensionBool p_reference) {                                                             \
		return true;                                                                                                                                                                   \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static constexpr GDExtensionInstanceBindingCallbacks _gde_binding_callbacks = {                                                                                                    \
		_gde_binding_create_callback,                                                                                                                                                  \
		_gde_binding_free_callback,                                                                                                                                                    \
		_gde_binding_reference_callback,                                                                                                                                               \
	};                                                                                                                                                                                 \
                                                                                                                                                                                       \
protected:                                                                                                                                                                             \
	virtual void _notificationv(int32_t p_what, bool p_reversed = false) override {                                                                                                    \
		m_class::notification_bind(this, p_what, p_reversed);                                                                                                                          \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
private:

// Don't use this for your classes, use GDCLASS() instead.
#define GDEXTENSION_CLASS_ALIAS(m_class, m_alias_for, m_inherits) /******************************************************************************************************************/ \
private:                                                                                                                                                                               \
	inline static ::godot::internal::EngineClassRegistration<m_class> _gde_engine_class_registration_helper;                                                                           \
	void operator=(const m_class &p_rval) {}                                                                                                                                           \
	friend class ::godot::ClassDB;                                                                                                                                                     \
                                                                                                                                                                                       \
protected:                                                                                                                                                                             \
	virtual const GDExtensionInstanceBindingCallbacks *_get_bindings_callbacks() const override {                                                                                      \
		return &_gde_binding_callbacks;                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	m_class(const char *p_godot_class) : m_inherits(p_godot_class) {}                                                                                                                  \
	m_class(GodotObject *p_godot_object) : m_inherits(p_godot_object) {}                                                                                                               \
                                                                                                                                                                                       \
	static void _bind_methods() {}                                                                                                                                                     \
                                                                                                                                                                                       \
	static void (*_get_bind_methods())() {                                                                                                                                             \
		return nullptr;                                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void (Wrapped::*_get_notification())(int) {                                                                                                                                 \
		return nullptr;                                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static bool (Wrapped::*_get_set())(const ::godot::StringName &p_name, const Variant &p_property) {                                                                                 \
		return nullptr;                                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static bool (Wrapped::*_get_get())(const ::godot::StringName &p_name, Variant &r_ret) const {                                                                                      \
		return nullptr;                                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static inline bool has_get_property_list() {                                                                                                                                       \
		return false;                                                                                                                                                                  \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void (Wrapped::*_get_get_property_list())(List<PropertyInfo> * p_list) const {                                                                                              \
		return nullptr;                                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static bool (Wrapped::*_get_property_can_revert())(const ::godot::StringName &p_name) const {                                                                                      \
		return nullptr;                                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static bool (Wrapped::*_get_property_get_revert())(const ::godot::StringName &p_name, Variant &) const {                                                                           \
		return nullptr;                                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void (Wrapped::*_get_validate_property())(::godot::PropertyInfo & p_property) const {                                                                                       \
		return nullptr;                                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static String (Wrapped::*_get_to_string())() const {                                                                                                                               \
		return nullptr;                                                                                                                                                                \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
public:                                                                                                                                                                                \
	typedef m_class self_type;                                                                                                                                                         \
	typedef m_inherits parent_type;                                                                                                                                                    \
                                                                                                                                                                                       \
	static void initialize_class() {}                                                                                                                                                  \
                                                                                                                                                                                       \
	static const ::godot::StringName &get_class_static() {                                                                                                                             \
		static const ::godot::StringName string_name = ::godot::StringName(#m_alias_for);                                                                                              \
		return string_name;                                                                                                                                                            \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static const ::godot::StringName &get_parent_class_static() {                                                                                                                      \
		return m_inherits::get_class_static();                                                                                                                                         \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void free(void *data, GDExtensionClassInstancePtr ptr) {                                                                                                                    \
	}                                                                                                                                                                                  \
                                                                                                                                                                                       \
	static void *_gde_binding_create_callback(void *p_token, void *p_instance) {                                                                                                       \
		/* Do not call memnew here, we don't want the post-initializer to be called */                                                                                                 \
		return new ("", "") m_class((GodotObject *)p_instance);                                                                                                                        \
	}                                                                                                                                                                                  \
	static void _gde_binding_free_callback(void *p_token, void *p_instance, void *p_binding) {                                                                                         \
		/* Explicitly call the deconstructor to ensure proper lifecycle for non-trivial members */                                                                                     \
		reinterpret_cast<m_class *>(p_binding)->~m_class();                                                                                                                            \
		Memory::free_static(reinterpret_cast<m_class *>(p_binding));                                                                                                                   \
	}                                                                                                                                                                                  \
	static GDExtensionBool _gde_binding_reference_callback(void *p_token, void *p_instance, GDExtensionBool p_reference) {                                                             \
		return true;                                                                                                                                                                   \
	}                                                                                                                                                                                  \
	static constexpr GDExtensionInstanceBindingCallbacks _gde_binding_callbacks = {                                                                                                    \
		_gde_binding_create_callback,                                                                                                                                                  \
		_gde_binding_free_callback,                                                                                                                                                    \
		_gde_binding_reference_callback,                                                                                                                                               \
	};                                                                                                                                                                                 \
	m_class() : m_class(#m_alias_for) {}                                                                                                                                               \
                                                                                                                                                                                       \
private:

// Don't use this for your classes, use GDCLASS() instead.
#define GDEXTENSION_CLASS(m_class, m_inherits) GDEXTENSION_CLASS_ALIAS(m_class, m_class, m_inherits)

#endif // GODOT_WRAPPED_HPP
