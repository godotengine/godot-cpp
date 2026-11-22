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

#pragma once

#include <godot_cpp/core/memory.hpp>

#include <godot_cpp/core/property_info.hpp>

#include <godot_cpp/templates/list.hpp>
#include <godot_cpp/templates/vector.hpp>

#include <godot_cpp/godot.hpp>

#if defined(MACOS_ENABLED) && defined(HOT_RELOAD_ENABLED)
#include <map>
#include <mutex>
#include <thread>
#endif

namespace godot {

/**
 * Declares the binding registry that has access to the engine wrapper's construction internals.
 */
class ClassDB;

/**
 * Opaque engine object type used behind the C++ wrapper's owner pointer.
 */
typedef void GodotObject;

/**
 * Prepares the thread's construction data for a wrapped engine class.
 */
template <typename T, std::enable_if_t<std::is_base_of<::godot::Wrapped, T>::value, bool> = true>
_ALWAYS_INLINE_ void _pre_initialize();

// Base for all engine classes, to contain the pointer to the engine instance.
/**
 * Base of the generated and custom Godot C++ object wrappers. Holds the engine object pointer and defines default extension callbacks.
 */
class Wrapped {
	/**
	 * Gives the binding initialization code access to wrapper lifecycle internals.
	 */
	friend class GDExtensionBinding;
	/**
	 * Gives the registry access to wrapper construction data and default callbacks.
	 */
	friend class ClassDB;
	/**
	 * Allows the adapter to send the wrapper's post-initialization notification.
	 */
	friend void postinitialize_handler(Wrapped *);

	/**
	 * Allows the wrapped-type construction hook to prepare private construction data.
	 */
	template <typename T, std::enable_if_t<std::is_base_of<::godot::Wrapped, T>::value, bool>>
	friend _ALWAYS_INLINE_ void _pre_initialize();

	/**
	 * Carries instance binding data from the allocation path into the wrapper constructor on the same thread.
	 */
	struct ConstructInfo {
		/**
		 * Points to the extension class name to attach while constructing the engine object.
		 */
		const StringName *extension_class_name = nullptr;
		/**
		 * Points to the callback table the constructor installs for this C++ binding.
		 */
		const GDExtensionInstanceBindingCallbacks *class_binding_callbacks = nullptr;
#ifdef HOT_RELOAD_ENABLED
		/**
		 * Holds the engine object to reuse while rebuilding its C++ wrapper during hot reload.
		 */
		GDExtensionObjectPtr recreate_owner = nullptr;
#endif
	};

#if defined(MACOS_ENABLED) && defined(HOT_RELOAD_ENABLED)
	// On macOS, `thread_local` storage keeps the library from being unloaded,
	// which breaks hot-reload. Instead we keep each thread's `ConstructInfo` in a
	// map keyed by thread id.
	/**
	 * Holds per-thread construction data in a map for macOS hot reload, where thread-local storage would keep the extension loaded.
	 */
	class ConstructInfoStore {
		/**
		 * Protects lookup and insertion in the per-thread map.
		 */
		std::mutex mutex;
		/**
		 * Stores the pending construction data for each thread.
		 */
		std::map<std::thread::id, ConstructInfo> infos;

	public:
		/**
		 * Returns the calling thread's construction record, creating one if necessary.
		 */
		ConstructInfo &get() {
			std::lock_guard<std::mutex> lock(mutex);
			return infos[std::this_thread::get_id()];
		}
	};

	/**
	 * Retrieves the calling thread's construction data from the hot-reload-compatible store.
	 */
	static ConstructInfo &_get_construct_info() {
		static ConstructInfoStore store;
		return store.get();
	}
#else
	/**
	 * Retrieves the calling thread's pending construction data from thread-local storage.
	 */
	static ConstructInfo &_get_construct_info() {
		static thread_local ConstructInfo info;
		return info;
	}
#endif

	/**
	 * Loads the extension identity and binding callbacks for the object about to be constructed.
	 */
	template <typename T>
	_ALWAYS_INLINE_ static void _set_construct_info() {
		ConstructInfo &info = _get_construct_info();
		info.extension_class_name = T::_get_extension_class_name();
		info.class_binding_callbacks = &T::_gde_binding_callbacks;
	}

protected:
	/**
	 * Returns false for the base wrapper. Extension wrappers override this discriminator.
	 */
	virtual bool _is_extension_class() const { return false; }
	/**
	 * Returns a null extension class name for the base wrapper.
	 */
	static const StringName *_get_extension_class_name(); // This is needed to retrieve the class name before the godot object has its _extension and _extension_instance members assigned.

	/**
	 * Default notification hook. The base wrapper ignores the notification.
	 */
	void _notification(int p_what) {}
	/**
	 * Default dynamic property setter. Reports that it did not handle the property.
	 */
	bool _set(const StringName &p_name, const Variant &p_property) { return false; }
	/**
	 * Default dynamic property getter. Reports that it did not provide a value.
	 */
	bool _get(const StringName &p_name, Variant &r_property) const { return false; }
	/**
	 * Default property list hook. Appends no dynamic properties.
	 */
	void _get_property_list(List<PropertyInfo> *p_list) const {}
	/**
	 * Default property revert check. Reports no revert value.
	 */
	bool _property_can_revert(const StringName &p_name) const { return false; }
	/**
	 * Default property revert getter. Reports that it did not produce a value.
	 */
	bool _property_get_revert(const StringName &p_name, Variant &r_property) const { return false; }
	/**
	 * Default property validation hook. Leaves the descriptor as received.
	 */
	void _validate_property(PropertyInfo &p_property) const {}
	/**
	 * Returns a placeholder string identifying the base wrapper.
	 */
	String _to_string() const { return "<Wrapped#0>"; }

	/**
	 * Base engine notification callback. Ignores the notification and dispatch order.
	 */
	static void notification_bind(GDExtensionClassInstancePtr p_instance, int32_t p_what, GDExtensionBool p_reversed) {}
	/**
	 * Base engine property setter callback. Reports an unhandled property.
	 */
	static GDExtensionBool set_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) { return false; }
	/**
	 * Base engine property getter callback. Reports an unhandled property.
	 */
	static GDExtensionBool get_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) { return false; }
	/**
	 * Base engine property-list callback. Returns no dynamic property array.
	 */
	static const GDExtensionPropertyInfo *get_property_list_bind(GDExtensionClassInstancePtr p_instance, uint32_t *r_count) { return nullptr; }
	/**
	 * Base engine property-list cleanup callback. The base callback owns no property array.
	 */
	static void free_property_list_bind(GDExtensionClassInstancePtr p_instance, const GDExtensionPropertyInfo *p_list, uint32_t p_count) {}
	/**
	 * Base engine revert availability callback. Reports that no revert value is available.
	 */
	static GDExtensionBool property_can_revert_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name) { return false; }
	/**
	 * Base engine revert-value callback. Reports that it did not produce a value.
	 */
	static GDExtensionBool property_get_revert_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) { return false; }
	/**
	 * Base engine property validation callback. Reports that it did not update the descriptor.
	 */
	static GDExtensionBool validate_property_bind(GDExtensionClassInstancePtr p_instance, GDExtensionPropertyInfo *p_property) { return false; }
	/**
	 * Base engine string conversion callback. Provides no custom representation.
	 */
	static void to_string_bind(GDExtensionClassInstancePtr p_instance, GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out) {}

	/**
	 * Sends the engine's post-initialization notification to an object wrapper.
	 */
	void _postinitialize();
	/**
	 * Base virtual notification dispatcher. Generated extension classes provide dispatch to their hooks.
	 */
	virtual void _notificationv(int32_t p_what, bool p_reversed = false) {}

	/**
	 * Constructs or reuses the engine object and installs this C++ instance and its binding callbacks from pending construction data.
	 */
	Wrapped(const StringName &p_godot_class);
	/**
	 * Attaches this C++ wrapper to an already existing engine object pointer.
	 */
	Wrapped(GodotObject *p_godot_object);
	/**
	 * Destroys the base C++ wrapper subobject through the virtual destructor.
	 */
	virtual ~Wrapped() {}

public:
	/**
	 * Returns the static interned name of the base wrapper.
	 */
	static const StringName &get_class_static() {
		static const StringName string_name = StringName("Wrapped");
		return string_name;
	}

	// Must be public but you should not touch this.
	/**
	 * Points to the engine-side object represented by this C++ wrapper.
	 */
	GodotObject *_owner = nullptr;
};

/**
 * Records the wrapped type's construction metadata for the next wrapper constructor on this thread.
 */
template <typename T, std::enable_if_t<std::is_base_of<::godot::Wrapped, T>::value, bool>>
_ALWAYS_INLINE_ void _pre_initialize() {
	Wrapped::_set_construct_info<T>();
}

/**
 * Terminates the variadic name append without changing the output vector.
 */
_FORCE_INLINE_ void snarray_add_str(Vector<StringName> &arr) {
}

/**
 * Appends one name to the output vector.
 */
_FORCE_INLINE_ void snarray_add_str(Vector<StringName> &arr, const StringName &p_str) {
	arr.push_back(p_str);
}

/**
 * Appends the first name and then the remaining names in order.
 */
template <typename... P>
_FORCE_INLINE_ void snarray_add_str(Vector<StringName> &arr, const StringName &p_str, P... p_args) {
	arr.push_back(p_str);
	snarray_add_str(arr, p_args...);
}

/**
 * Builds a vector of interned names from the supplied arguments.
 */
template <typename... P>
_FORCE_INLINE_ Vector<StringName> snarray(P... p_args) {
	Vector<StringName> arr;
	snarray_add_str(arr, p_args...);
	return arr;
}

namespace internal {

/**
 * Converts the owned C++ property list to an engine ABI array. Records the list in the allocation prefix so property strings stay alive until cleanup.
 */
GDExtensionPropertyInfo *create_c_property_list(::godot::List<::godot::PropertyInfo> *plist_cpp, uint32_t *r_size);
/**
 * Releases an ABI property array and destroys the C++ property list retained with it.
 */
void free_c_property_list(GDExtensionPropertyInfo *plist);

/**
 * Callback that registers a generated engine class's binding information.
 */
typedef void (*EngineClassRegistrationCallback)();
/**
 * Queues a class registration callback for library initialization.
 */
void add_engine_class_registration_callback(EngineClassRegistrationCallback p_callback);
/**
 * Associates an engine class name with its instance binding callbacks in the registry.
 */
void register_engine_class(const StringName &p_name, const GDExtensionInstanceBindingCallbacks *p_callbacks);
/**
 * Runs and clears the pending generated engine class registration callbacks.
 */
void register_engine_classes();

/**
 * Queues registration of a generated engine class and its binding callbacks.
 */
template <typename T>
struct EngineClassRegistration {
	/**
	 * Adds this specialization's callback to the queue.
	 */
	EngineClassRegistration() {
		add_engine_class_registration_callback(&EngineClassRegistration<T>::callback);
	}

	/**
	 * Registers the generated class name and its instance binding callbacks.
	 */
	static void callback() {
		register_engine_class(T::get_class_static(), &T::_gde_binding_callbacks);
	}
};

} // namespace internal

} // namespace godot

// Use this on top of your own classes.
// Note: the trail of `***` is to keep sane diffs in PRs, because clang-format otherwise moves every `\` which makes
// every line of the macro different
/**
 * Declares a custom extension class's registration traits, instance binding callbacks, and forwarding hooks for notifications, dynamic properties, validation, and string conversion. The macro also declares the class initialization and virtual registration helpers.
 *
 * **Used for** defining the metadata and callbacks needed to register a custom class with `godot::ClassDB`.
 *
 * - `m_class` — C++ class that contains the macro.
 * - `m_inherits` — Direct C++ base whose binding hooks are used by the generated methods.
 */
#define GDCLASS(m_class, m_inherits) \
private: \
	void operator=(const m_class &p_rval) = delete; \
	friend class ::godot::ClassDB; \
	friend class ::godot::Wrapped; \
\
protected: \
	virtual bool _is_extension_class() const override { \
		return true; \
	} \
\
	static const ::godot::StringName *_get_extension_class_name() { \
		const ::godot::StringName &string_name = get_class_static(); \
		return &string_name; \
	} \
\
	static void (*_get_bind_methods())() { \
		return &m_class::_bind_methods; \
	} \
\
	static void (::godot::Wrapped::*_get_notification())(int) { \
		return (void (::godot::Wrapped::*)(int)) & m_class::_notification; \
	} \
\
	static bool (::godot::Wrapped::*_get_set())(const ::godot::StringName &p_name, const ::godot::Variant &p_property) { \
		return (bool (::godot::Wrapped::*)(const ::godot::StringName &p_name, const ::godot::Variant &p_property)) & m_class::_set; \
	} \
\
	static bool (::godot::Wrapped::*_get_get())(const ::godot::StringName &p_name, ::godot::Variant &r_ret) const { \
		return (bool (::godot::Wrapped::*)(const ::godot::StringName &p_name, ::godot::Variant &r_ret) const) & m_class::_get; \
	} \
\
	static void (::godot::Wrapped::*_get_get_property_list())(::godot::List<::godot::PropertyInfo> * p_list) const { \
		return (void (::godot::Wrapped::*)(::godot::List<::godot::PropertyInfo> * p_list) const) & m_class::_get_property_list; \
	} \
\
	static bool (::godot::Wrapped::*_get_property_can_revert())(const ::godot::StringName &p_name) const { \
		return (bool (::godot::Wrapped::*)(const ::godot::StringName &p_name) const) & m_class::_property_can_revert; \
	} \
\
	static bool (::godot::Wrapped::*_get_property_get_revert())(const ::godot::StringName &p_name, ::godot::Variant &) const { \
		return (bool (::godot::Wrapped::*)(const ::godot::StringName &p_name, ::godot::Variant &) const) & m_class::_property_get_revert; \
	} \
\
	static void (::godot::Wrapped::*_get_validate_property())(::godot::PropertyInfo & p_property) const { \
		return (void (::godot::Wrapped::*)(::godot::PropertyInfo & p_property) const) & m_class::_validate_property; \
	} \
\
	static ::godot::String (::godot::Wrapped::*_get_to_string())() const { \
		return (::godot::String (::godot::Wrapped::*)() const) & m_class::_to_string; \
	} \
\
	template <typename T, typename B> \
	static void register_virtuals() { \
		m_inherits::register_virtuals<T, B>(); \
	} \
\
public: \
	typedef m_class self_type; \
	typedef m_inherits parent_type; \
\
	static void initialize_class() { \
		static bool initialized = false; \
		if (initialized) { \
			return; \
		} \
		m_inherits::initialize_class(); \
		if (m_class::_get_bind_methods() != m_inherits::_get_bind_methods()) { \
			_bind_methods(); \
			m_inherits::register_virtuals<m_class, m_inherits>(); \
		} \
		initialized = true; \
	} \
\
	static const ::godot::StringName &get_class_static() { \
		static const ::godot::StringName string_name = ::godot::StringName(U## #m_class); \
		return string_name; \
	} \
\
	static const ::godot::StringName &get_parent_class_static() { \
		return m_inherits::get_class_static(); \
	} \
\
	static void notification_bind(GDExtensionClassInstancePtr p_instance, int32_t p_what, GDExtensionBool p_reversed) { \
		if (p_instance && m_class::_get_notification()) { \
			if (!p_reversed) { \
				m_inherits::notification_bind(p_instance, p_what, p_reversed); \
			} \
			if (m_class::_get_notification() != m_inherits::_get_notification()) { \
				m_class *cls = reinterpret_cast<m_class *>(p_instance); \
				cls->_notification(p_what); \
			} \
			if (p_reversed) { \
				m_inherits::notification_bind(p_instance, p_what, p_reversed); \
			} \
		} \
	} \
\
	static GDExtensionBool set_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) { \
		if (p_instance) { \
			if (m_inherits::set_bind(p_instance, p_name, p_value)) { \
				return true; \
			} \
			if (m_class::_get_set() != m_inherits::_get_set()) { \
				m_class *cls = reinterpret_cast<m_class *>(p_instance); \
				return cls->_set(*reinterpret_cast<const ::godot::StringName *>(p_name), *reinterpret_cast<const ::godot::Variant *>(p_value)); \
			} \
		} \
		return false; \
	} \
\
	static GDExtensionBool get_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) { \
		if (p_instance) { \
			if (m_inherits::get_bind(p_instance, p_name, r_ret)) { \
				return true; \
			} \
			if (m_class::_get_get() != m_inherits::_get_get()) { \
				m_class *cls = reinterpret_cast<m_class *>(p_instance); \
				return cls->_get(*reinterpret_cast<const ::godot::StringName *>(p_name), *reinterpret_cast<::godot::Variant *>(r_ret)); \
			} \
		} \
		return false; \
	} \
\
	static inline bool has_get_property_list() { \
		return m_class::_get_get_property_list() && m_class::_get_get_property_list() != m_inherits::_get_get_property_list(); \
	} \
\
	static const GDExtensionPropertyInfo *get_property_list_bind(GDExtensionClassInstancePtr p_instance, uint32_t *r_count) { \
		if (!p_instance) { \
			if (r_count) \
				*r_count = 0; \
			return nullptr; \
		} \
		m_class *cls = reinterpret_cast<m_class *>(p_instance); \
		::godot::List<::godot::PropertyInfo> *plist_cpp = memnew(::godot::List<::godot::PropertyInfo>); \
		cls->_get_property_list(plist_cpp); \
		return ::godot::internal::create_c_property_list(plist_cpp, r_count); \
	} \
\
	static void free_property_list_bind(GDExtensionClassInstancePtr p_instance, const GDExtensionPropertyInfo *p_list, uint32_t /*p_count*/) { \
		if (p_instance) { \
			::godot::internal::free_c_property_list(const_cast<GDExtensionPropertyInfo *>(p_list)); \
		} \
	} \
\
	static GDExtensionBool property_can_revert_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name) { \
		if (p_instance && m_class::_get_property_can_revert()) { \
			if (m_class::_get_property_can_revert() != m_inherits::_get_property_can_revert()) { \
				m_class *cls = reinterpret_cast<m_class *>(p_instance); \
				return cls->_property_can_revert(*reinterpret_cast<const ::godot::StringName *>(p_name)); \
			} \
			return m_inherits::property_can_revert_bind(p_instance, p_name); \
		} \
		return false; \
	} \
\
	static GDExtensionBool property_get_revert_bind(GDExtensionClassInstancePtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) { \
		if (p_instance && m_class::_get_property_get_revert()) { \
			if (m_class::_get_property_get_revert() != m_inherits::_get_property_get_revert()) { \
				m_class *cls = reinterpret_cast<m_class *>(p_instance); \
				return cls->_property_get_revert(*reinterpret_cast<const ::godot::StringName *>(p_name), *reinterpret_cast<::godot::Variant *>(r_ret)); \
			} \
			return m_inherits::property_get_revert_bind(p_instance, p_name, r_ret); \
		} \
		return false; \
	} \
\
	static GDExtensionBool validate_property_bind(GDExtensionClassInstancePtr p_instance, GDExtensionPropertyInfo *p_property) { \
		bool ret = false; \
		if (p_instance && m_class::_get_validate_property()) { \
			ret = m_inherits::validate_property_bind(p_instance, p_property); \
			if (m_class::_get_validate_property() != m_inherits::_get_validate_property()) { \
				m_class *cls = reinterpret_cast<m_class *>(p_instance); \
				::godot::PropertyInfo info(p_property); \
				cls->_validate_property(info); \
				info._update(p_property); \
				return true; \
			} \
		} \
		return ret; \
	} \
\
	static void to_string_bind(GDExtensionClassInstancePtr p_instance, GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out) { \
		if (p_instance && m_class::_get_to_string()) { \
			if (m_class::_get_to_string() != m_inherits::_get_to_string()) { \
				m_class *cls = reinterpret_cast<m_class *>(p_instance); \
				*reinterpret_cast<::godot::String *>(r_out) = cls->_to_string(); \
				*r_is_valid = true; \
				return; \
			} \
			m_inherits::to_string_bind(p_instance, r_is_valid, r_out); \
		} \
	} \
\
	static void free(void * /*data*/, GDExtensionClassInstancePtr ptr) { \
		if (ptr) { \
			m_class *cls = reinterpret_cast<m_class *>(ptr); \
			cls->~m_class(); \
			::godot::Memory::free_static(cls); \
		} \
	} \
\
	static void *_gde_binding_create_callback(void * /*p_token*/, void * /*p_instance*/) { \
		return nullptr; \
	} \
\
	static void _gde_binding_free_callback(void * /*p_token*/, void * /*p_instance*/, void * /*p_binding*/) { \
	} \
\
	static GDExtensionBool _gde_binding_reference_callback(void * /*p_token*/, void * /*p_instance*/, GDExtensionBool /*p_reference*/) { \
		return true; \
	} \
\
	static constexpr GDExtensionInstanceBindingCallbacks _gde_binding_callbacks = { \
		_gde_binding_create_callback, \
		_gde_binding_free_callback, \
		_gde_binding_reference_callback, \
	}; \
\
protected: \
	virtual void _notificationv(int32_t p_what, bool p_reversed = false) override { \
		m_class::notification_bind(this, p_what, p_reversed); \
	} \
\
private:

// Don't use this for your classes, use GDCLASS() instead.
/**
 * Defines a generated wrapper's engine class identity, binding callbacks, and construction helpers. The C++ identifier and engine class name can differ.
 *
 * **Used for** looking up engine instances by their registered names while exposing them through the generated C++ wrapper.
 *
 * - `m_class` — Generated C++ wrapper class that contains the macro.
 * - `m_alias_for` — Registered engine class name used for lookup.
 * - `m_inherits` — Direct C++ base used to construct the wrapper.
 */
#define GDEXTENSION_CLASS_ALIAS(m_class, m_alias_for, m_inherits) \
private: \
	inline static ::godot::internal::EngineClassRegistration<m_class> _gde_engine_class_registration_helper; \
	void operator=(const m_class &p_rval) = delete; \
	friend class ::godot::ClassDB; \
	friend class ::godot::Wrapped; \
\
protected: \
	m_class(const char *p_godot_class) : m_inherits(p_godot_class) {} \
	m_class(GodotObject *p_godot_object) : m_inherits(p_godot_object) {} \
\
	static void _bind_methods() {} \
\
	static void (*_get_bind_methods())() { \
		return nullptr; \
	} \
\
	static void (Wrapped::*_get_notification())(int) { \
		return nullptr; \
	} \
\
	static bool (Wrapped::*_get_set())(const ::godot::StringName &p_name, const Variant &p_property) { \
		return nullptr; \
	} \
\
	static bool (Wrapped::*_get_get())(const ::godot::StringName &p_name, Variant &r_ret) const { \
		return nullptr; \
	} \
\
	static inline bool has_get_property_list() { \
		return false; \
	} \
\
	static void (Wrapped::*_get_get_property_list())(List<PropertyInfo> * p_list) const { \
		return nullptr; \
	} \
\
	static bool (Wrapped::*_get_property_can_revert())(const ::godot::StringName &p_name) const { \
		return nullptr; \
	} \
\
	static bool (Wrapped::*_get_property_get_revert())(const ::godot::StringName &p_name, Variant &) const { \
		return nullptr; \
	} \
\
	static void (Wrapped::*_get_validate_property())(::godot::PropertyInfo & p_property) const { \
		return nullptr; \
	} \
\
	static String (Wrapped::*_get_to_string())() const { \
		return nullptr; \
	} \
\
public: \
	typedef m_class self_type; \
	typedef m_inherits parent_type; \
\
	static void initialize_class() {} \
\
	static const ::godot::StringName &get_class_static() { \
		static const ::godot::StringName string_name = ::godot::StringName(#m_alias_for); \
		return string_name; \
	} \
\
	static const ::godot::StringName &get_parent_class_static() { \
		return m_inherits::get_class_static(); \
	} \
\
	static void free(void *data, GDExtensionClassInstancePtr ptr) { \
	} \
\
	static void *_gde_binding_create_callback(void *p_token, void *p_instance) { \
		/* Do not call memnew here, we don't want the post-initializer to be called */ \
		return new (::godot::DefaultAllocator{}) m_class((GodotObject *)p_instance); \
	} \
	static void _gde_binding_free_callback(void *p_token, void *p_instance, void *p_binding) { \
		/* Explicitly call the deconstructor to ensure proper lifecycle for non-trivial members */ \
		reinterpret_cast<m_class *>(p_binding)->~m_class(); \
		Memory::free_static(reinterpret_cast<m_class *>(p_binding)); \
	} \
	static GDExtensionBool _gde_binding_reference_callback(void *p_token, void *p_instance, GDExtensionBool p_reference) { \
		return true; \
	} \
	static constexpr GDExtensionInstanceBindingCallbacks _gde_binding_callbacks = { \
		_gde_binding_create_callback, \
		_gde_binding_free_callback, \
		_gde_binding_reference_callback, \
	}; \
	m_class() : m_class(#m_alias_for) {} \
\
private:

// Don't use this for your classes, use GDCLASS() instead.
/**
 * Defines a generated wrapper whose C++ class name matches the registered engine class name.
 *
 * **Used for** letting the generated class construct C++ wrappers for engine instances of the same name.
 *
 * - `m_class` — C++ wrapper whose name also identifies the engine class.
 * - `m_inherits` — Direct C++ base used to construct the wrapper.
 */
#define GDEXTENSION_CLASS(m_class, m_inherits) GDEXTENSION_CLASS_ALIAS(m_class, m_class, m_inherits)

/**
 * Invokes the script override of the named extension virtual on the current object through its generated call helper.
 * Returns true if the override call succeeds.
 *
 * **Used for** dispatching a callback to a script attached to the current extension object.
 *
 * - `m_name` — Name passed to the virtual declaration macro.
 * - `...` — Arguments forwarded to the generated helper. For a virtual with a result, pass its writable output reference last.
 */
#define GDVIRTUAL_CALL(m_name, ...) _gdvirtual_##m_name##_call(__VA_ARGS__)
/**
 * Invokes the script override of the named extension virtual on the supplied object through its generated call helper.
 * Returns true if the override call succeeds.
 *
 * **Used for** dispatching a callback to a script attached to another extension object.
 *
 * - `m_obj` — Non-null pointer to the object with the generated call helper.
 * - `m_name` — Name passed to the virtual declaration macro.
 * - `...` — Arguments forwarded to the generated helper. For a virtual with a result, pass its writable output reference last.
 */
#define GDVIRTUAL_CALL_PTR(m_obj, m_name, ...) m_obj->_gdvirtual_##m_name##_call(__VA_ARGS__)

/**
 * Registers the named extension virtual and its argument names with the engine so scripts can implement it.
 *
 * **Used for** publishing a virtual callback during the extension class's method binding.
 *
 * - `m_name` — Name passed to the virtual declaration macro.
 * - `...` — Script-facing argument names in declaration order.
 */
#define GDVIRTUAL_BIND(m_name, ...) ::godot::ClassDB::add_virtual_method(get_class_static(), _gdvirtual_##m_name##_get_method_info(), ::godot::snarray(__VA_ARGS__));
/**
 * Queries the current object for an override of the named extension virtual.
 *
 * **Used for** choosing a C++ fallback when the current object has no script override.
 *
 * - `m_name` — Name passed to the virtual declaration macro.
 */
#define GDVIRTUAL_IS_OVERRIDDEN(m_name) _gdvirtual_##m_name##_overridden()
/**
 * Queries the supplied object for an override of the named extension virtual.
 *
 * **Used for** deciding whether to prepare arguments for a callback on another extension object.
 *
 * - `m_obj` — Non-null pointer to the object whose override is checked.
 * - `m_name` — Name passed to the virtual declaration macro.
 */
#define GDVIRTUAL_IS_OVERRIDDEN_PTR(m_obj, m_name) m_obj->_gdvirtual_##m_name##_overridden()
