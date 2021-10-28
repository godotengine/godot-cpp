/*************************************************************************/
/*  wrapped.hpp                                                          */
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

#ifndef GODOT_CPP_WRAPPED_HPP
#define GODOT_CPP_WRAPPED_HPP

#include <godot_cpp/core/memory.hpp>

#include <godot_cpp/godot.hpp>
namespace godot {

typedef void GodotObject;

// Base for all engine classes, to contain the pointer to the engine instance.
class Wrapped {
	friend class GDExtensionBinding;

	// Private constructor, this should not be created directly by users.
	Wrapped(GodotObject *p_owner) :
			_owner(p_owner) {}

protected:
	Wrapped() = default;

public:
	// Must be public but you should not touch this.
	GodotObject *_owner = nullptr;

	static Wrapped *_new() {
		return nullptr;
	}
};

namespace internal {

template <class T, class Enable = void>
struct Creator {
	static T *_new() { return nullptr; }
};

template <class T>
struct Creator<T, typename std::enable_if<std::is_base_of_v<godot::Wrapped, T>>::type> {
	static T *_new() { return T::_new(); }
};

// template <class T>
// struct Creator<T, std::false_type> {
// };

// template <class T>
// struct Creator<T, std::enable_if_t<std::is_base_of_v<godot::Wrapped, T>, bool>> {
// 	static T *_new() { return T::_new(); }
// };

}; // namespace internal

} // namespace godot

#ifdef DEBUG_ENABLED
#define CHECK_CLASS_CONSTRUCTOR(m_constructor, m_class)                                                      \
	if (unlikely(!m_constructor)) {                                                                          \
		ERR_PRINT_ONCE("Constructor for class " #m_class "not found. Likely wasn't registered in ClassDB."); \
		return nullptr;                                                                                      \
	} else                                                                                                   \
		((void)0)
#else
#define CHECK_CLASS_CONSTRUCTOR(m_constructor, m_class)
#endif

#define GDCLASS(m_class, m_inherits)                                                                                                                                  \
private:                                                                                                                                                              \
	friend class ClassDB;                                                                                                                                             \
                                                                                                                                                                      \
	using SelfType = m_class;                                                                                                                                         \
                                                                                                                                                                      \
protected:                                                                                                                                                            \
	static void (*_get_bind_methods())() {                                                                                                                            \
		return &m_class::_bind_methods;                                                                                                                               \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
	template <class T>                                                                                                                                                \
	static void register_virtuals() {                                                                                                                                 \
		m_inherits::register_virtuals<T>();                                                                                                                           \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
public:                                                                                                                                                               \
	static void initialize_class() {                                                                                                                                  \
		static bool initialized = false;                                                                                                                              \
		if (initialized) {                                                                                                                                            \
			return;                                                                                                                                                   \
		}                                                                                                                                                             \
		m_inherits::initialize_class();                                                                                                                               \
		if (m_class::_get_bind_methods() != m_inherits::_get_bind_methods()) {                                                                                        \
			_bind_methods();                                                                                                                                          \
			m_inherits::register_virtuals<m_class>();                                                                                                                 \
		}                                                                                                                                                             \
		initialized = true;                                                                                                                                           \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
	static const char *get_class_static() {                                                                                                                           \
		return #m_class;                                                                                                                                              \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
	static const char *get_parent_class_static() {                                                                                                                    \
		return #m_inherits;                                                                                                                                           \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
	static GDExtensionClassInstancePtr create(void *data) {                                                                                                           \
		return reinterpret_cast<GDExtensionClassInstancePtr>(new ("") m_class);                                                                                       \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
	static void free(void *data, GDExtensionClassInstancePtr ptr) {                                                                                                   \
		if (ptr) {                                                                                                                                                    \
			m_class *cls = reinterpret_cast<m_class *>(ptr);                                                                                                          \
			cls->~m_class();                                                                                                                                          \
			::godot::Memory::free_static(cls);                                                                                                                        \
		}                                                                                                                                                             \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
	static void set_object_instance(GDExtensionClassInstancePtr p_instance, GDNativeObjectPtr p_object_instance) {                                                    \
		godot::internal::gdn_interface->object_set_instance_binding(p_object_instance, godot::internal::token, p_instance, &m_class::___binding_callbacks);           \
		reinterpret_cast<m_class *>(p_instance)->_owner = reinterpret_cast<godot::GodotObject *>(p_object_instance);                                                  \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
	static void *___binding_create_callback(void *p_token, void *p_instance) {                                                                                        \
		return nullptr;                                                                                                                                               \
	}                                                                                                                                                                 \
	static void ___binding_free_callback(void *p_token, void *p_instance, void *p_binding) {                                                                          \
	}                                                                                                                                                                 \
	static GDNativeBool ___binding_reference_callback(void *p_token, void *p_instance, GDNativeBool p_reference) {                                                    \
		return true;                                                                                                                                                  \
	}                                                                                                                                                                 \
	static constexpr GDNativeInstanceBindingCallbacks ___binding_callbacks = {                                                                                        \
		___binding_create_callback,                                                                                                                                   \
		___binding_free_callback,                                                                                                                                     \
		___binding_reference_callback,                                                                                                                                \
	};                                                                                                                                                                \
                                                                                                                                                                      \
	static m_class *_new() {                                                                                                                                          \
		static GDNativeExtensionPtr ___extension = nullptr;                                                                                                           \
		static GDNativeClassConstructor ___constructor = godot::internal::gdn_interface->classdb_get_constructor(#m_class, &___extension);                            \
		CHECK_CLASS_CONSTRUCTOR(___constructor, m_class);                                                                                                             \
		GDNativeObjectPtr obj = godot::internal::gdn_interface->classdb_construct_object(___constructor, ___extension);                                               \
		return reinterpret_cast<m_class *>(godot::internal::gdn_interface->object_get_instance_binding(obj, godot::internal::token, &m_class::___binding_callbacks)); \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
private:

// Don't use this for your classes, use GDCLASS() instead.
#define GDNATIVE_CLASS(m_class, m_inherits)                                                                                                                           \
protected:                                                                                                                                                            \
	static void (*_get_bind_methods())() {                                                                                                                            \
		return nullptr;                                                                                                                                               \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
public:                                                                                                                                                               \
	static void initialize_class() {}                                                                                                                                 \
                                                                                                                                                                      \
	static const char *get_class_static() {                                                                                                                           \
		return #m_class;                                                                                                                                              \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
	static const char *get_parent_class_static() {                                                                                                                    \
		return #m_inherits;                                                                                                                                           \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
	static void *___binding_create_callback(void *p_token, void *p_instance) {                                                                                        \
		m_class *obj = new ("") m_class;                                                                                                                              \
		obj->_owner = (godot::GodotObject *)p_instance;                                                                                                               \
		return obj;                                                                                                                                                   \
	}                                                                                                                                                                 \
	static void ___binding_free_callback(void *p_token, void *p_instance, void *p_binding) {                                                                          \
		Memory::free_static(reinterpret_cast<m_class *>(p_binding));                                                                                                  \
	}                                                                                                                                                                 \
	static GDNativeBool ___binding_reference_callback(void *p_token, void *p_instance, GDNativeBool p_reference) {                                                    \
		return true;                                                                                                                                                  \
	}                                                                                                                                                                 \
	static constexpr GDNativeInstanceBindingCallbacks ___binding_callbacks = {                                                                                        \
		___binding_create_callback,                                                                                                                                   \
		___binding_free_callback,                                                                                                                                     \
		___binding_reference_callback,                                                                                                                                \
	};                                                                                                                                                                \
	static m_class *_new() {                                                                                                                                          \
		static GDNativeClassConstructor ___constructor = godot::internal::gdn_interface->classdb_get_constructor(#m_class, nullptr);                                  \
		CHECK_CLASS_CONSTRUCTOR(___constructor, m_class);                                                                                                             \
		GDNativeObjectPtr obj = ___constructor();                                                                                                                     \
		return reinterpret_cast<m_class *>(godot::internal::gdn_interface->object_get_instance_binding(obj, godot::internal::token, &m_class::___binding_callbacks)); \
	}                                                                                                                                                                 \
                                                                                                                                                                      \
private:

#endif // ! GODOT_CPP_WRAPPED_HPP
