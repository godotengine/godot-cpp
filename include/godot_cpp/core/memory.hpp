/**************************************************************************/
/*  memory.hpp                                                            */
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

#include <cstddef>
#include <cstdint>
#include <new> // IWYU pragma: keep // `new` operators.

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/godot.hpp>

#include <type_traits>

namespace godot {
/**
 * Declares the common engine wrapper type used to select object destruction and construction hooks.
 */
class Wrapped;

/**
 * Provides allocation helpers and buffer layout constants for storage managed through the Godot engine.
 */
namespace Memory {
/**
 * Rounds an integer address or offset up to a multiple of a positive alignment.
 *
 * - `p_address` — Integer address or offset to align.
 * - `p_alignment` — Positive alignment in bytes.
 */
constexpr size_t get_aligned_address(size_t p_address, size_t p_alignment) {
	const size_t n_bytes_unaligned = p_address % p_alignment;
	return (n_bytes_unaligned == 0) ? p_address : (p_address + p_alignment - n_bytes_unaligned);
}

#if defined(__MINGW32__) && !defined(__MINGW64__)
// Note: Using hardcoded value, since the value can end up different in different compile units on 32-bit windows
// due to a compiler bug (see GH-113145)
/**
 * Maximum buffer alignment fixed at 16 bytes for 32-bit MinGW to keep allocation layouts consistent across translation units.
 */
static constexpr size_t MAX_ALIGN = 16;
static_assert(MAX_ALIGN % alignof(max_align_t) == 0);
#else
/**
 * Maximum buffer alignment derived from the platform's ordinary maximum alignment.
 */
static constexpr size_t MAX_ALIGN = alignof(max_align_t);
#endif

// Alignment:  ↓ max_align_t        ↓ uint64_t          ↓ MAX_ALIGN
//             ┌─────────────────┬──┬────────────────┬──┬───────────...
//             │ uint64_t        │░░│ uint64_t       │░░│ T[]
//             │ alloc size      │░░│ element count  │░░│ data
//             └─────────────────┴──┴────────────────┴──┴───────────...
// Offset:     ↑ SIZE_OFFSET        ↑ ELEMENT_OFFSET    ↑ DATA_OFFSET
// Note: "alloc size" is used and set by the engine and is never accessed or changed for the extension.

/**
 * Byte offset of the allocation-size field maintained by the engine.
 */
inline constexpr size_t SIZE_OFFSET = 0;
/**
 * Aligned byte offset of the array element count in the allocation prefix.
 */
inline constexpr size_t ELEMENT_OFFSET = get_aligned_address(SIZE_OFFSET + sizeof(uint64_t), alignof(uint64_t));
/**
 * Aligned byte offset at which array element storage begins.
 */
inline constexpr size_t DATA_OFFSET = get_aligned_address(ELEMENT_OFFSET + sizeof(uint64_t), MAX_ALIGN);

/**
 * Allocates the requested number of bytes through the engine. `p_pad_align` requests the array allocation prefix.
 *
 * - `p_bytes` — Requested payload size in bytes, excluding any allocation prefix.
 * - `p_pad_align` — Whether to use the allocation prefix required by padded arrays.
 */
void *alloc_static(size_t p_bytes, bool p_pad_align = false);
/**
 * Allocates storage through the engine and zeroes the requested payload bytes.
 *
 * - `p_bytes` — Requested payload size in bytes, excluding any allocation prefix.
 * - `p_pad_align` — Whether to use the allocation prefix required by padded arrays.
 */
void *alloc_static_zeroed(size_t p_bytes, bool p_pad_align = false);
/**
 * Changes the payload size using the engine allocator. A null pointer requests allocation. For an existing allocation, zero bytes frees it and returns null. Use the same padding mode as the original allocation.
 *
 * - `p_memory` — Existing allocation, or null to allocate a new block.
 * - `p_bytes` — Requested payload size in bytes, excluding any allocation prefix.
 * - `p_pad_align` — Padding mode used to allocate the original block.
 */
void *realloc_static(void *p_memory, size_t p_bytes, bool p_pad_align = false);
/**
 * Frees engine-allocated storage with the padding mode used to allocate it.
 *
 * - `p_ptr` — Start of the payload returned by the allocator.
 * - `p_pad_align` — Padding mode used to allocate the original block.
 */
void free_static(void *p_ptr, bool p_pad_align = false);
}; //namespace Memory

/**
 * Provides unpadded engine storage to the default allocation helpers.
 */
class DefaultAllocator {
public:
	/**
	 * Allocates an unpadded block of the requested byte size through the engine.
	 *
	 * - `p_memory` — Number of payload bytes to allocate.
	 */
	_ALWAYS_INLINE_ static void *alloc(size_t p_memory) { return Memory::alloc_static(p_memory); }
	/**
	 * Frees an unpadded block allocated through the engine.
	 *
	 * - `p_ptr` — Allocation returned by the unpadded allocator.
	 */
	_ALWAYS_INLINE_ static void free(void *p_ptr) { Memory::free_static(p_ptr); }
};

} // namespace godot

// Overload of `new` operator to use the `Memory::alloc_static()` function.
// The `DefaultAllocator` parameter is just a tag to select this overload.
// NOTE: do not inline `new` operators due to GCC+LTO compiler bug (see GH-119752).
/**
 * Allocates storage for a new object through Godot's default allocator. The allocator tag selects this overload.
 *
 * - `p_size` — Number of bytes requested by the new expression.
 * - `p_allocator` — Tag that selects the Godot allocation overload.
 */
void *operator new(size_t p_size, ::godot::DefaultAllocator p_allocator);

// Overload of `new` operator to use a custom allocation function.
// p_allocator argument is added to avoid conflicts with the engine functions when both engine and GDExtension are built as a static library on iOS.
/**
 * Allocates object storage by calling the supplied allocation function with the required byte count.
 *
 * - `p_size` — Number of bytes requested by the new expression.
 * - `p_allocator` — Tag that selects the Godot allocation overload.
 * - `p_allocfunc` — Callback that receives the requested byte count and returns object storage.
 */
void *operator new(size_t p_size, ::godot::DefaultAllocator p_allocator, void *(*p_allocfunc)(size_t p_size));

#if defined(_MSC_VER) && !defined(__clang__)
// When compiling with VC++ 2017, the above declarations of placement new generate many irrelevant warnings (C4291).
// The purpose of the following definitions is to muffle these warnings, not to provide a usable implementation of placement delete.
/**
 * Provides the matching default placement deallocation overload for MSVC. Executing it triggers a crash.
 *
 * - `p_mem` — Object storage from the matching allocation attempt. The dummy overload does not read it.
 * - `p_allocator` — Tag that matches the allocation overload.
 */
inline void operator delete(void *p_mem, ::godot::DefaultAllocator p_allocator) {
	CRASH_NOW_MSG("Call to placement delete should not happen.");
}
/**
 * Provides the matching callback-based placement deallocation overload for MSVC. Executing it triggers a crash.
 *
 * - `p_mem` — Object storage from the matching allocation attempt. The dummy overload does not read it.
 * - `p_allocator` — Tag that matches the allocation overload.
 * - `p_allocfunc` — Allocation function supplied to the matching placement new. The dummy overload does not call it.
 */
inline void operator delete(void *p_mem, ::godot::DefaultAllocator, void *(*p_allocfunc)(size_t p_size)) {
	CRASH_NOW_MSG("Call to placement delete should not happen.");
}
#endif // defined(_MSC_VER) && !defined(__clang__)

namespace godot {
/**
 * Defines the no-op construction hook for types outside the engine wrapper hierarchy.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `second template parameter` — Selects this overload for types outside the Godot wrapper hierarchy.
 */
template <typename T, std::enable_if_t<!std::is_base_of<::godot::Wrapped, T>::value, bool> = true>
_ALWAYS_INLINE_ void _pre_initialize() {}

/**
 * Selects how the allocation macros return an instance after construction. The primary template returns a raw pointer.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `Enable` — Substitution parameter used to select a specialized result for certain types.
 */
template <typename T, typename Enable = void>
struct memnew_result {
	/**
	 * Raw pointer result for a type without a specialized allocation result.
	 */
	using class_name = T *;
	/**
	 * Returns the constructed pointer unchanged.
	 *
	 * - `p_obj` — Pointer to the constructed object.
	 */
	_ALWAYS_INLINE_ static class_name capture(T *p_obj) { return p_obj; }
};

/**
 * Resolves the C++ result type for an instance created by `memnew`.
 *
 * - `T` — C++ type of the object managed by this operation.
 */
template <typename T>
using memnew_result_t = typename memnew_result<T>::class_name;

/**
 * Defines the no-op fallback post-construction hook for ordinary C++ types.
 *
 * - `first void pointer parameter` — Address of the ordinary C++ object. This fallback does not use it.
 */
_ALWAYS_INLINE_ void postinitialize_handler(void *) {}

/**
 * Captures the allocation result and runs the matching post-initialization handler before returning it.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `p_obj` — Pointer to the object that has just been constructed.
 */
template <typename T>
_ALWAYS_INLINE_ memnew_result_t<T> _post_initialize(T *p_obj) {
	memnew_result_t<T> result(memnew_result<T>::capture(p_obj));
	postinitialize_handler(p_obj);
	return result;
}

/**
 * Allocates the supplied byte count through Godot's unpadded allocator.
 *
 * - `m_size` — Requested number of payload bytes.
 */
#define memalloc(m_size) ::godot::Memory::alloc_static(m_size)
/**
 * Resizes an unpadded allocation through Godot's allocator.
 *
 * - `m_mem` — Existing unpadded allocation, or null to allocate a new block.
 * - `m_size` — New payload size in bytes. Zero releases a non-null allocation.
 */
#define memrealloc(m_mem, m_size) ::godot::Memory::realloc_static(m_mem, m_size)
/**
 * Releases unpadded storage through Godot's allocator.
 *
 * - `m_mem` — Pointer returned by the unpadded Godot allocator.
 */
#define memfree(m_mem) ::godot::Memory::free_static(m_mem)

/**
 * Constructs an object in Godot-allocated storage and runs the appropriate construction hooks.
 *
 * - `m_class` — C++ type with its optional constructor arguments.
 */
#define memnew(m_class) (::godot::_pre_initialize<std::remove_pointer_t<decltype(new (::godot::DefaultAllocator{}) m_class)>>(), ::godot::_post_initialize(new (::godot::DefaultAllocator{}) m_class))

/**
 * Constructs an object in storage provided by the named allocator's allocation function and runs the construction hooks.
 *
 * - `m_class` — C++ type with its optional constructor arguments.
 * - `m_allocator` — Allocator type whose static allocation function supplies the storage.
 */
#define memnew_allocator(m_class, m_allocator) (::godot::_pre_initialize<std::remove_pointer_t<decltype(new (::godot::DefaultAllocator{}, m_allocator::alloc) m_class)>>(), ::godot::_post_initialize(new (::godot::DefaultAllocator{}, m_allocator::alloc) m_class))
/**
 * Constructs an object in the supplied storage and runs the construction hooks.
 *
 * - `m_placement` — Address of writable storage with the size and alignment required by the type.
 * - `m_class` — C++ type with its optional constructor arguments.
 */
#define memnew_placement(m_placement, m_class) (::godot::_pre_initialize<std::remove_pointer_t<decltype(new (m_placement) m_class)>>(), ::godot::_post_initialize(new (m_placement) m_class))

/**
 * Destroys an ordinary C++ object when needed and releases its engine-allocated storage.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `p_class` — Object created in storage from the Godot allocator.
 * - `second function parameter` — Unnamed pointer used to select this overload for ordinary C++ types.
 */
template <typename T>
void memdelete(T *p_class, typename std::enable_if<!std::is_base_of_v<::godot::Wrapped, T>>::type * = nullptr) {
	if constexpr (!std::is_trivially_destructible_v<T>) {
		p_class->~T();
	}

	Memory::free_static(p_class);
}

/**
 * Destroys an engine-wrapped object through the Godot object interface.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `second template parameter` — Selects the overload for a type derived from the Godot engine wrapper.
 * - `p_class` — C++ wrapper whose engine object is destroyed.
 */
template <typename T, std::enable_if_t<std::is_base_of_v<::godot::Wrapped, T>, bool> = true>
void memdelete(T *p_class) {
	::godot::gdextension_interface::object_destroy(p_class->_owner);
}

/**
 * Destroys the object when needed and releases storage through allocator `A`.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `A` — Allocator type whose free function releases the storage.
 * - `p_class` — Object stored in a block provided by the allocator.
 */
template <typename T, typename A>
void memdelete_allocator(T *p_class) {
	if constexpr (!std::is_trivially_destructible_v<T>) {
		p_class->~T();
	}

	A::free(p_class);
}

/**
 * Allocates and destroys individual C++ objects using the default Godot allocation helpers.
 *
 * - `T` — C++ type of the object managed by this operation.
 */
template <typename T>
class DefaultTypedAllocator {
public:
	/**
	 * Constructs an object from the supplied arguments in Godot-allocated storage.
	 *
	 * - `Args` — Types of the supplied constructor arguments.
	 * - `p_args` — Arguments passed to the constructor.
	 */
	template <typename... Args>
	_ALWAYS_INLINE_ T *new_allocation(const Args &&...p_args) { return memnew(T(p_args...)); }
	/**
	 * Destroys the object and returns its storage to the Godot allocator.
	 *
	 * - `p_allocation` — Object previously created with this typed allocator.
	 */
	_ALWAYS_INLINE_ void delete_allocation(T *p_allocation) { memdelete(p_allocation); }
};

/**
 * Allocates an array with an element count stored in its prefix. Use `godot::memdelete_arr` to release the array.
 *
 * - `m_class` — Element type stored in the array.
 * - `m_count` — Number of elements to allocate. Zero returns null.
 */
#define memnew_arr(m_class, m_count) ::godot::memnew_arr_template<m_class>(m_count)

/**
 * Locates the element count in the prefix immediately before an array payload.
 *
 * - `p_ptr` — Array payload address returned by the padded allocator.
 */
_FORCE_INLINE_ uint64_t *_get_element_count_ptr(uint8_t *p_ptr) {
	return (uint64_t *)(p_ptr - Memory::DATA_OFFSET + Memory::ELEMENT_OFFSET);
}

/**
 * Allocates a padded array and records its length. A zero count returns null. The implementation invokes constructors for nontrivially destructible element types.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `p_elements` — Number of elements to allocate. Zero returns null.
 */
template <typename T>
T *memnew_arr_template(size_t p_elements) {
	if (p_elements == 0) {
		return nullptr;
	}
	/** overloading operator new[] cannot be done , because it may not return the real allocated address (it may pad the 'element count' before the actual array). Because of that, it must be done by hand. This is the
	same strategy used by std::vector, and the Vector class, so it should be safe.*/

	size_t len = sizeof(T) * p_elements;
	uint8_t *mem = (uint8_t *)Memory::alloc_static(len, true);
	T *failptr = nullptr; // Get rid of a warning.
	ERR_FAIL_NULL_V(mem, failptr);

	uint64_t *_elem_count_ptr = _get_element_count_ptr(mem);
	*(_elem_count_ptr) = p_elements;

	if constexpr (!std::is_trivially_destructible_v<T>) {
		T *elems = (T *)mem;

		/* call operator new */
		for (size_t i = 0; i < p_elements; i++) {
			new (&elems[i]) T;
		}
	}

	return (T *)mem;
}

// Fast alternative to a loop constructor pattern.
/**
 * Initializes a range of uninitialized element storage. Uses zero initialization for types marked zero-constructible and placement construction otherwise.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `p_start` — Start of uninitialized storage for the new elements.
 * - `p_num` — Number of elements in the supplied range.
 */
template <typename T>
_FORCE_INLINE_ void memnew_arr_placement(T *p_start, size_t p_num) {
	if constexpr (is_zero_constructible_v<T>) {
		// Can optimize with memset.
		memset(static_cast<void *>(p_start), 0, p_num * sizeof(T));
	} else {
		// Need to use a for loop.
		for (size_t i = 0; i < p_num; i++) {
			memnew_placement(p_start + i, T());
		}
	}
}

// Convenient alternative to a loop copy pattern.
/**
 * Copy-constructs elements in uninitialized destination storage. Trivially copyable elements are copied as bytes.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `p_dst` — Start of the uninitialized destination range.
 * - `p_src` — Start of the live source range. It must not overlap the destination.
 * - `p_num` — Number of elements in the supplied range.
 */
template <typename T>
_FORCE_INLINE_ void copy_arr_placement(T *p_dst, const T *p_src, size_t p_num) {
	if constexpr (std::is_trivially_copyable_v<T>) {
		memcpy((uint8_t *)p_dst, (uint8_t *)p_src, p_num * sizeof(T));
	} else {
		for (size_t i = 0; i < p_num; i++) {
			memnew_placement(p_dst + i, T(p_src[i]));
		}
	}
}

// Convenient alternative to a loop destructor pattern.
/**
 * Invokes destructors across the live range when the element type requires destruction. The storage itself remains allocated.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `p_dst` — Start of the live element range to destroy.
 * - `p_num` — Number of elements in the supplied range.
 */
template <typename T>
_FORCE_INLINE_ void destruct_arr_placement(T *p_dst, size_t p_num) {
	if constexpr (!std::is_trivially_destructible_v<T>) {
		for (size_t i = 0; i < p_num; i++) {
			p_dst[i].~T();
		}
	}
}

/**
 * Reads the recorded element count from an array created by `memnew_arr`.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `p_class` — Array returned by `memnew_arr`. The array pointer must be non-null.
 */
template <typename T>
size_t memarr_len(const T *p_class) {
	uint8_t *ptr = (uint8_t *)p_class;
	uint64_t *_elem_count_ptr = _get_element_count_ptr(ptr);
	return *(_elem_count_ptr);
}

/**
 * Destroys array elements when required and frees the padded allocation created by `memnew_arr`.
 *
 * - `T` — C++ type of the object managed by this operation.
 * - `p_class` — Array whose elements and storage are released.
 */
template <typename T>
void memdelete_arr(T *p_class) {
	uint8_t *ptr = (uint8_t *)p_class;

	if constexpr (!std::is_trivially_destructible_v<T>) {
		uint64_t *_elem_count_ptr = _get_element_count_ptr(ptr);
		uint64_t elem_count = *(_elem_count_ptr);

		for (uint64_t i = 0; i < elem_count; i++) {
			p_class[i].~T();
		}
	}

	Memory::free_static(ptr, true);
}

/**
 * Shared black sentinel node for absent links in the red-black tree containers.
 */
struct _GlobalNil {
	/**
	 * Stores the black color value used by the tree algorithms.
	 */
	int color = 1;
	/**
	 * Points back to the sentinel for its missing right child.
	 */
	_GlobalNil *right;
	/**
	 * Points back to the sentinel for its missing left child.
	 */
	_GlobalNil *left;
	/**
	 * Points back to the sentinel for its absent parent.
	 */
	_GlobalNil *parent;

	/**
	 * Initializes the sentinel's links to point back to itself.
	 */
	_GlobalNil();
};

/**
 * Owns the shared sentinel used by the tree containers.
 */
struct _GlobalNilClass {
	/**
	 * The process-wide black sentinel node used in place of missing tree links.
	 */
	static _GlobalNil _nil;
};

} // namespace godot
