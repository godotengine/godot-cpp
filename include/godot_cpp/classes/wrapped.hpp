/*************************************************************************/
/*  wrapped.hpp                                                          */
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

#ifndef GODOT_CPP_WRAPPED_HPP
#define GODOT_CPP_WRAPPED_HPP

#include <godot_cpp/core/memory.hpp>

#include <godot_cpp/core/property_info.hpp>

#include <godot_cpp/templates/list.hpp>

#include <godot_cpp/godot.hpp>

namespace godot {

typedef void GodotObject;

// Base for all engine classes, to contain the pointer to the engine instance.
class Wrapped {
	friend class GDExtensionBinding;
	friend void postinitialize_handler(Wrapped *);

protected:
	virtual const char *_get_extension_class() const; // This is needed to retrieve the class name before the godot object has its _extension and _extension_instance members assigned.
	virtual const GDNativeInstanceBindingCallbacks *_get_bindings_callbacks() const = 0;

	void _notification(int p_what){};
	bool _set(const StringName &p_name, const Variant &p_property) { return false; };
	bool _get(const StringName &p_name, Variant &r_property) const { return false; };
	void _get_property_list(List<PropertyInfo> *p_list) const {};
	bool _property_can_revert(const StringName &p_name) const { return false; };
	bool _property_get_revert(const StringName &p_name, Variant &r_property) const { return false; };
	String _to_string() const { return "[" + String(get_class_static()) + ":" + itos(get_instance_id()) + "]"; }

	static void notification_bind(GDExtensionClassInstancePtr p_instance, int32_t p_what) {}
	static GDNativeBool set_bind(GDExtensionClassInstancePtr p_instance, const GDNativeStringNamePtr p_name, const GDNativeVariantPtr p_value) { return false; }
	static GDNativeBool get_bind(GDExtensionClassInstancePtr p_instance, const GDNativeStringNamePtr p_name, GDNativeVariantPtr r_ret) { return false; }
	static const GDNativePropertyInfo *get_property_list_bind(GDExtensionClassInstancePtr p_instance, uint32_t *r_count) { return nullptr; }
	static void free_property_list_bind(GDExtensionClassInstancePtr p_instance, const GDNativePropertyInfo *p_list) {}
	static GDNativeBool property_can_revert_bind(GDExtensionClassInstancePtr p_instance, const GDNativeStringNamePtr p_name) { return false; }
	static GDNativeBool property_get_revert_bind(GDExtensionClassInstancePtr p_instance, const GDNativeStringNamePtr p_name, GDNativeVariantPtr r_ret) { return false; }
	static void to_string_bind(GDExtensionClassInstancePtr p_instance, GDNativeStringPtr r_out) {}

	GDNativePropertyInfo *plist = nullptr;
	uint32_t plist_size = 0;

	void _postinitialize();

	Wrapped(const char *p_godot_class);
	Wrapped(GodotObject *p_godot_object);

public:
	static const char *get_class_static() {
		return "Wrapped";
	}

	uint64_t get_instance_id() const {
		return 0;
	}

	static _FORCE_INLINE_ char *_alloc_and_copy_cstr(const char *p_str) {
		size_t size = strlen(p_str) + 1;
		char *ret = reinterpret_cast<char *>(memalloc(size));
		memcpy(ret, p_str, size);
		return ret;
	}

	// Must be public but you should not touch this.
	GodotObject *_owner = nullptr;
};

} // namespace godot

#define GDCLASS(m_class, m_inherits)                                                                                                                     \
private:                                                                                                                                                 \
	void operator=(const m_class &p_rval) {}                                                                                                             \
	friend class ::godot::ClassDB;                                                                                                                       \
                                                                                                                                                         \
protected:                                                                                                                                               \
	virtual const char *_get_extension_class() const override {                                                                                          \
		return get_class_static();                                                                                                                       \
	}                                                                                                                                                    \
                                                                                                                                                         \
	virtual const GDNativeInstanceBindingCallbacks *_get_bindings_callbacks() const override {                                                           \
		return &___binding_callbacks;                                                                                                                    \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static void (*_get_bind_methods())() {                                                                                                               \
		return &m_class::_bind_methods;                                                                                                                  \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static void (::godot::Wrapped::*_get_notification())(int) {                                                                                          \
		return (void(::godot::Wrapped::*)(int)) & m_class::_notification;                                                                                \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static bool (::godot::Wrapped::*_get_set())(const ::godot::StringName &p_name, const ::godot::Variant &p_property) {                                 \
		return (bool(::godot::Wrapped::*)(const ::godot::StringName &p_name, const ::godot::Variant &p_property)) & m_class::_set;                       \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static bool (::godot::Wrapped::*_get_get())(const ::godot::StringName &p_name, ::godot::Variant &r_ret) const {                                      \
		return (bool(::godot::Wrapped::*)(const ::godot::StringName &p_name, ::godot::Variant &r_ret) const) & m_class::_get;                            \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static void (::godot::Wrapped::*_get_get_property_list())(::godot::List<::godot::PropertyInfo> * p_list) const {                                     \
		return (void(::godot::Wrapped::*)(::godot::List<::godot::PropertyInfo> * p_list) const) & m_class::_get_property_list;                           \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static bool (::godot::Wrapped::*_get_property_can_revert())(const ::godot::StringName &p_name) {                                                     \
		return (bool(::godot::Wrapped::*)(const ::godot::StringName &p_name)) & m_class::_property_can_revert;                                           \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static bool (::godot::Wrapped::*_get_property_get_revert())(const ::godot::StringName &p_name, ::godot::Variant &) {                                 \
		return (bool(::godot::Wrapped::*)(const ::godot::StringName &p_name, ::godot::Variant &)) & m_class::_property_get_revert;                       \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static ::godot::String (::godot::Wrapped::*_get_to_string())() {                                                                                     \
		return (::godot::String(::godot::Wrapped::*)()) & m_class::_to_string;                                                                           \
	}                                                                                                                                                    \
                                                                                                                                                         \
	template <class T>                                                                                                                                   \
	static void register_virtuals() {                                                                                                                    \
		m_inherits::register_virtuals<T>();                                                                                                              \
	}                                                                                                                                                    \
                                                                                                                                                         \
public:                                                                                                                                                  \
	static void initialize_class() {                                                                                                                     \
		static bool initialized = false;                                                                                                                 \
		if (initialized) {                                                                                                                               \
			return;                                                                                                                                      \
		}                                                                                                                                                \
		m_inherits::initialize_class();                                                                                                                  \
		if (m_class::_get_bind_methods() != m_inherits::_get_bind_methods()) {                                                                           \
			_bind_methods();                                                                                                                             \
			m_inherits::register_virtuals<m_class>();                                                                                                    \
		}                                                                                                                                                \
		initialized = true;                                                                                                                              \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static const char *get_class_static() {                                                                                                              \
		return #m_class;                                                                                                                                 \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static const char *get_parent_class_static() {                                                                                                       \
		return m_inherits::get_class_static();                                                                                                           \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static GDNativeObjectPtr create(void *data) {                                                                                                        \
		m_class *new_object = memnew(m_class);                                                                                                           \
		return new_object->_owner;                                                                                                                       \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static void notification_bind(GDExtensionClassInstancePtr p_instance, int32_t p_what) {                                                              \
		if (p_instance && m_class::_get_notification()) {                                                                                                \
			if (m_class::_get_notification() != m_inherits::_get_notification()) {                                                                       \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                  \
				return cls->_notification(p_what);                                                                                                       \
			}                                                                                                                                            \
			m_inherits::notification_bind(p_instance, p_what);                                                                                           \
		}                                                                                                                                                \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static GDNativeBool set_bind(GDExtensionClassInstancePtr p_instance, const GDNativeStringNamePtr p_name, const GDNativeVariantPtr p_value) {         \
		if (p_instance && m_class::_get_set()) {                                                                                                         \
			if (m_class::_get_set() != m_inherits::_get_set()) {                                                                                         \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                  \
				return cls->_set(*reinterpret_cast<const ::godot::StringName *>(p_name), *reinterpret_cast<const ::godot::Variant *>(p_value));          \
			}                                                                                                                                            \
			return m_inherits::set_bind(p_instance, p_name, p_value);                                                                                    \
		}                                                                                                                                                \
		return false;                                                                                                                                    \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static GDNativeBool get_bind(GDExtensionClassInstancePtr p_instance, const GDNativeStringNamePtr p_name, GDNativeVariantPtr r_ret) {                 \
		if (p_instance && m_class::_get_get()) {                                                                                                         \
			if (m_class::_get_get() != m_inherits::_get_get()) {                                                                                         \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                  \
				return cls->_get(*reinterpret_cast<const ::godot::StringName *>(p_name), *reinterpret_cast<::godot::Variant *>(r_ret));                  \
			}                                                                                                                                            \
			return m_inherits::get_bind(p_instance, p_name, r_ret);                                                                                      \
		}                                                                                                                                                \
		return false;                                                                                                                                    \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static const GDNativePropertyInfo *get_property_list_bind(GDExtensionClassInstancePtr p_instance, uint32_t *r_count) {                               \
		if (p_instance && m_class::_get_get_property_list()) {                                                                                           \
			if (m_class::_get_get_property_list() != m_inherits::_get_get_property_list()) {                                                             \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                  \
				::godot::List<::godot::PropertyInfo> list;                                                                                               \
				cls->_get_property_list(&list);                                                                                                          \
				ERR_FAIL_COND_V_MSG(cls->plist != nullptr || cls->plist_size != 0, nullptr, "Internal error, property list was not freed by engine!");   \
				cls->plist = reinterpret_cast<GDNativePropertyInfo *>(memalloc(sizeof(GDNativePropertyInfo) * list.size()));                             \
				cls->plist_size = 0;                                                                                                                     \
				for (const ::godot::PropertyInfo &E : list) {                                                                                            \
					cls->plist[cls->plist_size].type = E.type;                                                                                           \
					cls->plist[cls->plist_size].name = _alloc_and_copy_cstr(E.name.utf8().get_data());                                                   \
					cls->plist[cls->plist_size].hint = E.hint;                                                                                           \
					cls->plist[cls->plist_size].hint_string = _alloc_and_copy_cstr(E.hint_string.utf8().get_data());                                     \
					cls->plist[cls->plist_size].class_name = _alloc_and_copy_cstr(E.class_name.utf8().get_data());                                       \
					cls->plist[cls->plist_size].usage = E.usage;                                                                                         \
					cls->plist_size++;                                                                                                                   \
				}                                                                                                                                        \
				if (r_count)                                                                                                                             \
					*r_count = cls->plist_size;                                                                                                          \
				return cls->plist;                                                                                                                       \
			}                                                                                                                                            \
			return m_inherits::get_property_list_bind(p_instance, r_count);                                                                              \
		}                                                                                                                                                \
		return nullptr;                                                                                                                                  \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static void free_property_list_bind(GDExtensionClassInstancePtr p_instance, const GDNativePropertyInfo *p_list) {                                    \
		if (p_instance) {                                                                                                                                \
			m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                      \
			ERR_FAIL_COND_MSG(cls->plist == nullptr, "Internal error, property list double free!");                                                      \
			for (size_t i = 0; i < cls->plist_size; i++) {                                                                                               \
				memfree(const_cast<char *>(cls->plist[i].name));                                                                                         \
				memfree(const_cast<char *>(cls->plist[i].class_name));                                                                                   \
				memfree(const_cast<char *>(cls->plist[i].hint_string));                                                                                  \
			}                                                                                                                                            \
			memfree(cls->plist);                                                                                                                         \
			cls->plist = nullptr;                                                                                                                        \
			cls->plist_size = 0;                                                                                                                         \
		}                                                                                                                                                \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static GDNativeBool property_can_revert_bind(GDExtensionClassInstancePtr p_instance, const GDNativeStringNamePtr p_name) {                           \
		if (p_instance && m_class::_get_property_can_revert()) {                                                                                         \
			if (m_class::_get_property_can_revert() != m_inherits::_get_property_can_revert()) {                                                         \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                  \
				return cls->_property_can_revert(*reinterpret_cast<const ::godot::StringName *>(p_name));                                                \
			}                                                                                                                                            \
			return m_inherits::property_can_revert_bind(p_instance, p_name);                                                                             \
		}                                                                                                                                                \
		return false;                                                                                                                                    \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static GDNativeBool property_get_revert_bind(GDExtensionClassInstancePtr p_instance, const GDNativeStringNamePtr p_name, GDNativeVariantPtr r_ret) { \
		if (p_instance && m_class::_get_property_get_revert()) {                                                                                         \
			if (m_class::_get_property_get_revert() != m_inherits::_get_property_get_revert()) {                                                         \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                  \
				return cls->_property_get_revert(*reinterpret_cast<const ::godot::StringName *>(p_name), *reinterpret_cast<::godot::Variant *>(r_ret));  \
			}                                                                                                                                            \
			return m_inherits::property_get_revert_bind(p_instance, p_name, r_ret);                                                                      \
		}                                                                                                                                                \
		return false;                                                                                                                                    \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static void to_string_bind(GDExtensionClassInstancePtr p_instance, GDNativeStringPtr r_out) {                                                        \
		if (p_instance && m_class::_get_to_string()) {                                                                                                   \
			if (m_class::_get_to_string() != m_inherits::_get_to_string()) {                                                                             \
				m_class *cls = reinterpret_cast<m_class *>(p_instance);                                                                                  \
				*reinterpret_cast<::godot::String *>(r_out) = cls->_to_string();                                                                         \
				return;                                                                                                                                  \
			}                                                                                                                                            \
			m_inherits::to_string_bind(p_instance, r_out);                                                                                               \
		}                                                                                                                                                \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static void free(void *data, GDExtensionClassInstancePtr ptr) {                                                                                      \
		if (ptr) {                                                                                                                                       \
			m_class *cls = reinterpret_cast<m_class *>(ptr);                                                                                             \
			cls->~m_class();                                                                                                                             \
			::godot::Memory::free_static(cls);                                                                                                           \
		}                                                                                                                                                \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static void *___binding_create_callback(void *p_token, void *p_instance) {                                                                           \
		return nullptr;                                                                                                                                  \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static void ___binding_free_callback(void *p_token, void *p_instance, void *p_binding) {                                                             \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static GDNativeBool ___binding_reference_callback(void *p_token, void *p_instance, GDNativeBool p_reference) {                                       \
		return true;                                                                                                                                     \
	}                                                                                                                                                    \
                                                                                                                                                         \
	static constexpr GDNativeInstanceBindingCallbacks ___binding_callbacks = {                                                                           \
		___binding_create_callback,                                                                                                                      \
		___binding_free_callback,                                                                                                                        \
		___binding_reference_callback,                                                                                                                   \
	};

// Don't use this for your classes, use GDCLASS() instead.
#define GDNATIVE_CLASS(m_class, m_inherits)                                                                        \
private:                                                                                                           \
	void operator=(const m_class &p_rval) {}                                                                       \
                                                                                                                   \
protected:                                                                                                         \
	virtual const GDNativeInstanceBindingCallbacks *_get_bindings_callbacks() const override {                     \
		return &___binding_callbacks;                                                                              \
	}                                                                                                              \
                                                                                                                   \
	m_class(const char *p_godot_class) : m_inherits(p_godot_class) {}                                              \
	m_class(GodotObject *p_godot_object) : m_inherits(p_godot_object) {}                                           \
                                                                                                                   \
	static void (*_get_bind_methods())() {                                                                         \
		return nullptr;                                                                                            \
	}                                                                                                              \
                                                                                                                   \
	static void (Wrapped::*_get_notification())(int) {                                                             \
		return nullptr;                                                                                            \
	}                                                                                                              \
                                                                                                                   \
	static bool (Wrapped::*_get_set())(const StringName &p_name, const Variant &p_property) {                      \
		return nullptr;                                                                                            \
	}                                                                                                              \
                                                                                                                   \
	static bool (Wrapped::*_get_get())(const StringName &p_name, Variant &r_ret) const {                           \
		return nullptr;                                                                                            \
	}                                                                                                              \
                                                                                                                   \
	static void (Wrapped::*_get_get_property_list())(List<PropertyInfo> * p_list) const {                          \
		return nullptr;                                                                                            \
	}                                                                                                              \
                                                                                                                   \
	static bool (Wrapped::*_get_property_can_revert())(const StringName &p_name) {                                 \
		return nullptr;                                                                                            \
	}                                                                                                              \
                                                                                                                   \
	static bool (Wrapped::*_get_property_get_revert())(const StringName &p_name, Variant &) {                      \
		return nullptr;                                                                                            \
	}                                                                                                              \
                                                                                                                   \
	static String (Wrapped::*_get_to_string())() {                                                                 \
		return nullptr;                                                                                            \
	}                                                                                                              \
                                                                                                                   \
public:                                                                                                            \
	static void initialize_class() {}                                                                              \
                                                                                                                   \
	static const char *get_class_static() {                                                                        \
		return #m_class;                                                                                           \
	}                                                                                                              \
                                                                                                                   \
	static const char *get_parent_class_static() {                                                                 \
		return m_inherits::get_class_static();                                                                     \
	}                                                                                                              \
                                                                                                                   \
	static void *___binding_create_callback(void *p_token, void *p_instance) {                                     \
		/* Do not call memnew here, we don't want the postinitializer to be called */                              \
		return new ("") m_class((GodotObject *)p_instance);                                                        \
	}                                                                                                              \
	static void ___binding_free_callback(void *p_token, void *p_instance, void *p_binding) {                       \
		/* Explicitly call the deconstructor to ensure proper lifecycle for non-trivial members */                 \
		reinterpret_cast<m_class *>(p_binding)->~m_class();                                                        \
		Memory::free_static(reinterpret_cast<m_class *>(p_binding));                                               \
	}                                                                                                              \
	static GDNativeBool ___binding_reference_callback(void *p_token, void *p_instance, GDNativeBool p_reference) { \
		return true;                                                                                               \
	}                                                                                                              \
	static constexpr GDNativeInstanceBindingCallbacks ___binding_callbacks = {                                     \
		___binding_create_callback,                                                                                \
		___binding_free_callback,                                                                                  \
		___binding_reference_callback,                                                                             \
	};                                                                                                             \
	m_class() : m_class(#m_class) {}

#endif // ! GODOT_CPP_WRAPPED_HPP
