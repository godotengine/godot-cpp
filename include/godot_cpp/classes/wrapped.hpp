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

	void _postinitialize();

	Wrapped(const char *p_godot_class);
	Wrapped(GodotObject *p_godot_object);

public:
	static const char *get_class_static() {
		return "Wrapped";
	}

	// Must be public but you should not touch this.
	GodotObject *_owner = nullptr;
};

} // namespace godot

#define GDCLASS(m_class, m_inherits)                                                                               \
private:                                                                                                           \
	void operator=(const m_class &p_rval) {}                                                                       \
	friend class ClassDB;                                                                                          \
                                                                                                                   \
protected:                                                                                                         \
	virtual const char *_get_extension_class() const override {                                                    \
		return get_class_static();                                                                                 \
	}                                                                                                              \
                                                                                                                   \
	virtual const GDNativeInstanceBindingCallbacks *_get_bindings_callbacks() const override {                     \
		return &___binding_callbacks;                                                                              \
	}                                                                                                              \
                                                                                                                   \
	static void (*_get_bind_methods())() {                                                                         \
		return &m_class::_bind_methods;                                                                            \
	}                                                                                                              \
                                                                                                                   \
	template <class T>                                                                                             \
	static void register_virtuals() {                                                                              \
		m_inherits::register_virtuals<T>();                                                                        \
	}                                                                                                              \
                                                                                                                   \
public:                                                                                                            \
	static void initialize_class() {                                                                               \
		static bool initialized = false;                                                                           \
		if (initialized) {                                                                                         \
			return;                                                                                                \
		}                                                                                                          \
		m_inherits::initialize_class();                                                                            \
		if (m_class::_get_bind_methods() != m_inherits::_get_bind_methods()) {                                     \
			_bind_methods();                                                                                       \
			m_inherits::register_virtuals<m_class>();                                                              \
		}                                                                                                          \
		initialized = true;                                                                                        \
	}                                                                                                              \
                                                                                                                   \
	static const char *get_class_static() {                                                                        \
		return #m_class;                                                                                           \
	}                                                                                                              \
                                                                                                                   \
	static const char *get_parent_class_static() {                                                                 \
		return m_inherits::get_class_static();                                                                     \
	}                                                                                                              \
                                                                                                                   \
	static GDNativeObjectPtr create(void *data) {                                                                  \
		m_class *new_object = memnew(m_class);                                                                     \
		return new_object->_owner;                                                                                 \
	}                                                                                                              \
                                                                                                                   \
	static void free(void *data, GDExtensionClassInstancePtr ptr) {                                                \
		if (ptr) {                                                                                                 \
			m_class *cls = reinterpret_cast<m_class *>(ptr);                                                       \
			cls->~m_class();                                                                                       \
			::godot::Memory::free_static(cls);                                                                     \
		}                                                                                                          \
	}                                                                                                              \
                                                                                                                   \
	static void *___binding_create_callback(void *p_token, void *p_instance) {                                     \
		return nullptr;                                                                                            \
	}                                                                                                              \
	static void ___binding_free_callback(void *p_token, void *p_instance, void *p_binding) {                       \
	}                                                                                                              \
	static GDNativeBool ___binding_reference_callback(void *p_token, void *p_instance, GDNativeBool p_reference) { \
		return true;                                                                                               \
	}                                                                                                              \
	static constexpr GDNativeInstanceBindingCallbacks ___binding_callbacks = {                                     \
		___binding_create_callback,                                                                                \
		___binding_free_callback,                                                                                  \
		___binding_reference_callback,                                                                             \
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
		return memnew(m_class((GodotObject *)p_instance));                                                         \
	}                                                                                                              \
	static void ___binding_free_callback(void *p_token, void *p_instance, void *p_binding) {                       \
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
