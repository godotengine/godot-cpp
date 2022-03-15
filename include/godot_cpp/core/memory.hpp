/*************************************************************************/
/*  memory.hpp                                                           */
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

#ifndef GODOT_CPP_MEMORY_HPP
#define GODOT_CPP_MEMORY_HPP

#include <cstddef>
#include <cstdint>

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/godot.hpp>

#include <type_traits>

void *operator new(size_t p_size, const char *p_description); ///< operator new that takes a description and uses MemoryStaticPool
void *operator new(size_t p_size, void *(*p_allocfunc)(size_t p_size)); ///< operator new that takes a description and uses MemoryStaticPool
void *operator new(size_t p_size, void *p_pointer, size_t check, const char *p_description); ///< operator new that takes a description and uses a pointer to the preallocated memory

_ALWAYS_INLINE_ void *operator new(size_t p_size, void *p_pointer, size_t check, const char *p_description) {
	return p_pointer;
}

#ifdef _MSC_VER
// When compiling with VC++ 2017, the above declarations of placement new generate many irrelevant warnings (C4291).
// The purpose of the following definitions is to muffle these warnings, not to provide a usable implementation of placement delete.
void operator delete(void *p_mem, const char *p_description);
void operator delete(void *p_mem, void *(*p_allocfunc)(size_t p_size));
void operator delete(void *p_mem, void *p_pointer, size_t check, const char *p_description);
#endif

namespace godot {

class Wrapped;

class Memory {
	Memory();

public:
	static void *alloc_static(size_t p_bytes);
	static void *realloc_static(void *p_memory, size_t p_bytes);
	static void free_static(void *p_ptr);
};

_ALWAYS_INLINE_ void postinitialize_handler(void *) {}

template <class T>
_ALWAYS_INLINE_ T *_post_initialize(T *p_obj) {
	postinitialize_handler(p_obj);
	return p_obj;
}

#define memalloc(m_size) Memory::alloc_static(m_size)
#define memrealloc(m_mem, m_size) Memory::realloc_static(m_mem, m_size)
#define memfree(m_mem) Memory::free_static(m_mem)

#define memnew(m_class) _post_initialize(new ("") m_class)

#define memnew_allocator(m_class, m_allocator) _post_initialize(new (m_allocator::alloc) m_class)
#define memnew_placement(m_placement, m_class) _post_initialize(new (m_placement, sizeof(m_class), "") m_class)

// Generic comparator used in Map, List, etc.
template <class T>
struct Comparator {
	_ALWAYS_INLINE_ bool operator()(const T &p_a, const T &p_b) const { return (p_a < p_b); }
};

class DefaultAllocator {
public:
	_ALWAYS_INLINE_ static void *alloc(size_t p_memory) { return Memory::alloc_static(p_memory); }
	_ALWAYS_INLINE_ static void free(void *p_ptr) { Memory::free_static(p_ptr); }
};

template <class T>
void memdelete(T *p_class, typename std::enable_if<!std::is_base_of_v<godot::Wrapped, T>>::type * = 0) {
	if (!__has_trivial_destructor(T)) {
		p_class->~T();
	}

	Memory::free_static(p_class);
}

template <class T, std::enable_if_t<std::is_base_of_v<godot::Wrapped, T>, bool> = true>
void memdelete(T *p_class) {
	godot::internal::gdn_interface->object_destroy(p_class->_owner);
}

template <class T, class A>
void memdelete_allocator(T *p_class) {
	if (!__has_trivial_destructor(T)) {
		p_class->~T();
	}

	A::free(p_class);
}

#define memnew_arr(m_class, m_count) memnew_arr_template<m_class>(m_count)

template <typename T>
T *memnew_arr_template(size_t p_elements, const char *p_descr = "") {
	if (p_elements == 0) {
		return nullptr;
	}
	/** overloading operator new[] cannot be done , because it may not return the real allocated address (it may pad the 'element count' before the actual array). Because of that, it must be done by hand. This is the
	same strategy used by std::vector, and the Vector class, so it should be safe.*/

	size_t len = sizeof(T) * p_elements;
	uint64_t *mem = (uint64_t *)Memory::alloc_static(len);
	T *failptr = nullptr; // Get rid of a warning.
	ERR_FAIL_COND_V(!mem, failptr);
	*(mem - 1) = p_elements;

	if (!__has_trivial_constructor(T)) {
		T *elems = (T *)mem;

		/* call operator new */
		for (size_t i = 0; i < p_elements; i++) {
			new (&elems[i], sizeof(T), p_descr) T;
		}
	}

	return (T *)mem;
}

template <typename T>
void memdelete_arr(T *p_class) {
	uint64_t *ptr = (uint64_t *)p_class;

	if (!__has_trivial_destructor(T)) {
		uint64_t elem_count = *(ptr - 1);

		for (uint64_t i = 0; i < elem_count; i++) {
			p_class[i].~T();
		}
	}

	Memory::free_static(ptr);
}

struct _GlobalNil {
	int color = 1;
	_GlobalNil *right;
	_GlobalNil *left;
	_GlobalNil *parent;

	_GlobalNil();
};

struct _GlobalNilClass {
	static _GlobalNil _nil;
};

} // namespace godot

#endif // ! GODOT_CPP_MEMORY_HPP
