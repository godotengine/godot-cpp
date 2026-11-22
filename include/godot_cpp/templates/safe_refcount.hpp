/**************************************************************************/
/*  safe_refcount.hpp                                                     */
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

#if !defined(NO_THREADS)

#include <atomic>
#include <godot_cpp/core/defs.hpp>
#include <type_traits>

namespace godot {

// Design goals for these classes:
// - No automatic conversions or arithmetic operators,
//   to keep explicit the use of atomics everywhere.
// - Using acquire-release semantics, even to set the first value.
//   The first value may be set relaxedly in many cases, but adding the distinction
//   between relaxed and unrelaxed operation to the interface would make it needlessly
//   flexible. There's negligible waste in having release semantics for the initial
//   value and, as an important benefit, you can be sure the value is properly synchronized
//   even with threads that are already running.

// These are used in very specific areas of the engine where it's critical that these guarantees are held
/**
 * Asserts the size, alignment, and trivial destruction requirements used when treating supported values as atomic numeric storage.
 *
 * **Used for** checking the layout assumptions of storage that represents a number and its atomic wrapper.
 *
 * - `m_type` — Numeric storage type whose size, alignment, and atomic destruction properties are checked.
 */
#define SAFE_NUMERIC_TYPE_PUN_GUARANTEES(m_type) \
	static_assert(sizeof(::godot::SafeNumeric<m_type>) == sizeof(m_type)); \
	static_assert(alignof(::godot::SafeNumeric<m_type>) == alignof(m_type)); \
	static_assert(std::is_trivially_destructible_v<std::atomic<m_type>>);
/**
 * Asserts that `godot::SafeFlag` matches the size and alignment of `bool`.
 *
 * **Used for** checking layout before placing a safe flag in storage laid out as a boolean.
 */
#define SAFE_FLAG_TYPE_PUN_GUARANTEES \
	static_assert(sizeof(::godot::SafeFlag) == sizeof(bool)); \
	static_assert(alignof(::godot::SafeFlag) == alignof(bool));

/**
 * Wraps a lock-free atomic number with explicit load, store, and read-modify-write operations.
 *
 * **Used for** sharing a numeric state such as a copy-on-write allocation's reference count.
 *
 * - `T` — Numeric type with an always lock-free atomic representation. Each selected arithmetic or bit operation must support this type.
 */
template <typename T>
class SafeNumeric {
	/**
	 * Holds the shared numeric value used by the atomic operations.
	 */
	std::atomic<T> value;

	static_assert(std::atomic<T>::is_always_lock_free);

public:
	/**
	 * Stores a new value with release ordering.
	 *
	 * **Used for** publishing a counter or numeric state to readers that load it with acquire ordering.
	 *
	 * - `p_value` — New value to store.
	 */
	_ALWAYS_INLINE_ void set(T p_value) {
		value.store(p_value, std::memory_order_release);
	}

	/**
	 * Loads the current value with acquire ordering.
	 *
	 * **Used for** checking a shared numeric state before deciding which work to do next.
	 */
	_ALWAYS_INLINE_ T get() const {
		return value.load(std::memory_order_acquire);
	}

	/**
	 * Atomically adds one and returns the new value.
	 *
	 * **Used for** taking a new count and using the resulting value to classify the transition.
	 */
	_ALWAYS_INLINE_ T increment() {
		return value.fetch_add(1, std::memory_order_acq_rel) + 1;
	}

	// Returns the original value instead of the new one
	/**
	 * Atomically adds one and returns the previous value.
	 *
	 * **Used for** reserving a sequential entry whose index is the count before the reservation.
	 */
	_ALWAYS_INLINE_ T postincrement() {
		return value.fetch_add(1, std::memory_order_acq_rel);
	}

	/**
	 * Atomically subtracts one and returns the new value.
	 *
	 * **Used for** detecting when releasing an item leaves a shared count at zero.
	 */
	_ALWAYS_INLINE_ T decrement() {
		return value.fetch_sub(1, std::memory_order_acq_rel) - 1;
	}

	// Returns the original value instead of the new one
	/**
	 * Atomically subtracts one and returns the previous value.
	 *
	 * **Used for** detecting a transition from one remaining item by inspecting the previous count.
	 */
	_ALWAYS_INLINE_ T postdecrement() {
		return value.fetch_sub(1, std::memory_order_acq_rel);
	}

	/**
	 * Atomically adds the amount and returns the new value.
	 *
	 * **Used for** updating a shared total and checking the new total against a limit.
	 *
	 * - `p_value` — Amount to add.
	 */
	_ALWAYS_INLINE_ T add(T p_value) {
		return value.fetch_add(p_value, std::memory_order_acq_rel) + p_value;
	}

	// Returns the original value instead of the new one
	/**
	 * Atomically adds the amount and returns the previous value.
	 *
	 * **Used for** reserving a block of entries and using the old count as the start index.
	 *
	 * - `p_value` — Amount to add.
	 */
	_ALWAYS_INLINE_ T postadd(T p_value) {
		return value.fetch_add(p_value, std::memory_order_acq_rel);
	}

	/**
	 * Atomically subtracts the amount and returns the new value.
	 *
	 * **Used for** releasing part of a shared allocation and checking the amount still in use.
	 *
	 * - `p_value` — Amount to subtract.
	 */
	_ALWAYS_INLINE_ T sub(T p_value) {
		return value.fetch_sub(p_value, std::memory_order_acq_rel) - p_value;
	}

	/**
	 * Atomically sets all bits present in the mask and returns the previous value.
	 *
	 * **Used for** setting shared state flags and finding which were already set.
	 *
	 * - `p_value` — Mask whose set bits are set in the stored value.
	 */
	_ALWAYS_INLINE_ T bit_or(T p_value) {
		return value.fetch_or(p_value, std::memory_order_acq_rel);
	}
	/**
	 * Atomically clears bits outside the mask and returns the previous value.
	 *
	 * **Used for** clearing selected flags and checking their state before the change.
	 *
	 * - `p_value` — Mask whose set bits are preserved.
	 */
	_ALWAYS_INLINE_ T bit_and(T p_value) {
		return value.fetch_and(p_value, std::memory_order_acq_rel);
	}

	/**
	 * Atomically toggles all bits present in the mask and returns the previous value.
	 *
	 * **Used for** flipping selected shared flags and recording their previous state.
	 *
	 * - `p_value` — Mask whose set bits select the bits to toggle.
	 */
	_ALWAYS_INLINE_ T bit_xor(T p_value) {
		return value.fetch_xor(p_value, std::memory_order_acq_rel);
	}

	// Returns the original value instead of the new one
	/**
	 * Atomically subtracts the amount and returns the previous value.
	 *
	 * **Used for** releasing part of a shared allocation when the caller needs its previous usage.
	 *
	 * - `p_value` — Amount to subtract.
	 */
	_ALWAYS_INLINE_ T postsub(T p_value) {
		return value.fetch_sub(p_value, std::memory_order_acq_rel);
	}

	/**
	 * Raises the value to the supplied minimum if needed and returns the observed or stored value.
	 *
	 * **Used for** publishing a high-water mark shared by several writers.
	 *
	 * - `p_value` — Minimum value to publish. Existing values at least this large are retained.
	 */
	_ALWAYS_INLINE_ T exchange_if_greater(T p_value) {
		while (true) {
			T tmp = value.load(std::memory_order_acquire);
			if (tmp >= p_value) {
				return tmp; // already greater, or equal
			}

			if (value.compare_exchange_weak(tmp, p_value, std::memory_order_acq_rel)) {
				return p_value;
			}
		}
	}

	/**
	 * Increments only while the value is nonzero. Returns zero on refusal or the new value after an increment.
	 *
	 * **Used for** acquiring a counted reference only while an allocation still has an owner.
	 */
	_ALWAYS_INLINE_ T conditional_increment() {
		while (true) {
			T c = value.load(std::memory_order_acquire);
			if (c == 0) {
				return 0;
			}
			if (value.compare_exchange_weak(c, c + 1, std::memory_order_acq_rel)) {
				return c + 1;
			}
		}
	}

	/**
	 * Initializes the shared value with a release store.
	 *
	 * **Used for** establishing the initial shared count or numeric state.
	 *
	 * - `p_value` — Initial value. Defaults to zero converted to T.
	 */
	_ALWAYS_INLINE_ explicit SafeNumeric(T p_value = static_cast<T>(0)) {
		set(p_value);
	}
};

/**
 * Stores a shared boolean using acquire loads and release stores.
 *
 * **Used for** sharing a state such as whether a worker has published a result.
 */
class SafeFlag {
	/**
	 * Holds the lock-free atomic boolean.
	 */
	std::atomic_bool flag;

	static_assert(std::atomic_bool::is_always_lock_free);

public:
	/**
	 * Reads the flag with acquire ordering and returns whether it is set.
	 *
	 * **Used for** checking whether other work has published a flag before using its result.
	 */
	_ALWAYS_INLINE_ bool is_set() const {
		return flag.load(std::memory_order_acquire);
	}

	/**
	 * Sets the shared flag to true with release ordering.
	 *
	 * **Used for** publishing a completed state to other threads.
	 */
	_ALWAYS_INLINE_ void set() {
		flag.store(true, std::memory_order_release);
	}

	/**
	 * Clears the shared flag with release ordering.
	 *
	 * **Used for** resetting a shared state before the next work cycle.
	 */
	_ALWAYS_INLINE_ void clear() {
		flag.store(false, std::memory_order_release);
	}

	/**
	 * Stores the supplied boolean with release ordering.
	 *
	 * **Used for** publishing a boolean that was computed by the caller.
	 *
	 * - `p_value` — Boolean state to publish.
	 */
	_ALWAYS_INLINE_ void set_to(bool p_value) {
		flag.store(p_value, std::memory_order_release);
	}

	/**
	 * Initializes the flag to the supplied state with a release store.
	 *
	 * **Used for** choosing the state readers first observe when the flag is shared.
	 *
	 * - `p_value` — Initial state. Defaults to false.
	 */
	_ALWAYS_INLINE_ explicit SafeFlag(bool p_value = false) {
		set_to(p_value);
	}
};

/**
 * Tracks a shared reference count. A counter that has reached zero cannot acquire another reference through this class.
 *
 * **Used for** deciding which owner releases the last reference to shared storage.
 */
class SafeRefCount {
	/**
	 * Holds the number of references in lock-free storage.
	 */
	SafeNumeric<uint32_t> count;

#ifdef DEV_ENABLED
	/**
	 * Checks in development builds that a decrement does not start from an observed count of zero.
	 */
	_ALWAYS_INLINE_ void _check_unref_safety() {
		// This won't catch every misuse, but it's better than nothing.
		CRASH_COND_MSG(count.get() == 0,
				"Trying to unreference a SafeRefCount which is already zero is wrong and a symptom of it being misused.\n"
				"Upon a SafeRefCount reaching zero any object whose lifetime is tied to it, as well as the ref count itself, must be destroyed.\n"
				"Moreover, to guarantee that, no multiple threads should be racing to do the final unreferencing to zero.");
	}
#endif

public:
	/**
	 * Attempts to acquire a reference and returns false if the count was zero.
	 *
	 * **Used for** checking whether a new owner acquired a reference before proceeding.
	 */
	_ALWAYS_INLINE_ bool ref() { // true on success
		return count.conditional_increment() != 0;
	}

	/**
	 * Attempts to acquire a reference and returns the new count, or zero if acquisition failed.
	 *
	 * **Used for** acquiring a reference when the caller also needs the resulting count.
	 */
	_ALWAYS_INLINE_ uint32_t refval() { // none-zero on success
		return count.conditional_increment();
	}

	/**
	 * Releases a reference and returns whether that decrement reached zero. The caller must own a reference.
	 *
	 * **Used for** identifying the owner responsible for destroying the shared storage.
	 */
	_ALWAYS_INLINE_ bool unref() { // true if must be disposed of
#ifdef DEV_ENABLED
		_check_unref_safety();
#endif
		return count.decrement() == 0;
	}

	/**
	 * Releases a reference and returns the remaining count. A result of zero marks the final reference.
	 *
	 * **Used for** releasing ownership when the caller also needs the number of remaining references.
	 */
	_ALWAYS_INLINE_ uint32_t unrefval() { // 0 if must be disposed of
#ifdef DEV_ENABLED
		_check_unref_safety();
#endif
		return count.decrement();
	}

	/**
	 * Reads the current count with acquire ordering.
	 *
	 * **Used for** reporting the observed owner count in diagnostics.
	 */
	_ALWAYS_INLINE_ uint32_t get() const {
		return count.get();
	}

	/**
	 * Publishes the starting reference count with release ordering.
	 *
	 * **Used for** establishing ownership before sharing a newly initialized object.
	 *
	 * - `p_value` — Starting count. Defaults to one for a single initial owner.
	 */
	_ALWAYS_INLINE_ void init(uint32_t p_value = 1) {
		count.set(p_value);
	}
};

} // namespace godot

#endif // !defined(NO_THREADS)
