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

#ifndef GODOT_SAFE_REFCOUNT_HPP
#define GODOT_SAFE_REFCOUNT_HPP

#ifdef GODOT_MODULE
#include "core/templates/safe_refcount.h"
#else

#if !defined(NO_THREADS)

#include <atomic>
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
#define SAFE_NUMERIC_TYPE_PUN_GUARANTEES(m_type)                    \
	static_assert(sizeof(SafeNumeric<m_type>) == sizeof(m_type));   \
	static_assert(alignof(SafeNumeric<m_type>) == alignof(m_type)); \
	static_assert(std::is_trivially_destructible<std::atomic<m_type>>::value);
#define SAFE_FLAG_TYPE_PUN_GUARANTEES                \
	static_assert(sizeof(SafeFlag) == sizeof(bool)); \
	static_assert(alignof(SafeFlag) == alignof(bool));

template <typename T>
class SafeNumeric {
	std::atomic<T> value;

	static_assert(std::atomic<T>::is_always_lock_free);

public:
	_ALWAYS_INLINE_ void set(T p_value) {
		value.store(p_value, std::memory_order_release);
	}

	_ALWAYS_INLINE_ T get() const {
		return value.load(std::memory_order_acquire);
	}

	_ALWAYS_INLINE_ T increment() {
		return value.fetch_add(1, std::memory_order_acq_rel) + 1;
	}

	// Returns the original value instead of the new one
	_ALWAYS_INLINE_ T postincrement() {
		return value.fetch_add(1, std::memory_order_acq_rel);
	}

	_ALWAYS_INLINE_ T decrement() {
		return value.fetch_sub(1, std::memory_order_acq_rel) - 1;
	}

	// Returns the original value instead of the new one
	_ALWAYS_INLINE_ T postdecrement() {
		return value.fetch_sub(1, std::memory_order_acq_rel);
	}

	_ALWAYS_INLINE_ T add(T p_value) {
		return value.fetch_add(p_value, std::memory_order_acq_rel) + p_value;
	}

	// Returns the original value instead of the new one
	_ALWAYS_INLINE_ T postadd(T p_value) {
		return value.fetch_add(p_value, std::memory_order_acq_rel);
	}

	_ALWAYS_INLINE_ T sub(T p_value) {
		return value.fetch_sub(p_value, std::memory_order_acq_rel) - p_value;
	}

	// Returns the original value instead of the new one
	_ALWAYS_INLINE_ T postsub(T p_value) {
		return value.fetch_sub(p_value, std::memory_order_acq_rel);
	}

	_ALWAYS_INLINE_ T exchange_if_greater(T p_value) {
		while (true) {
			T tmp = value.load(std::memory_order_acquire);
			if (tmp >= p_value) {
				return tmp; // already greater, or equal
			}
			if (value.compare_exchange_weak(tmp, p_value, std::memory_order_release)) {
				return p_value;
			}
		}
	}

	_ALWAYS_INLINE_ T conditional_increment() {
		while (true) {
			T c = value.load(std::memory_order_acquire);
			if (c == 0) {
				return 0;
			}
			if (value.compare_exchange_weak(c, c + 1, std::memory_order_release)) {
				return c + 1;
			}
		}
	}

	_ALWAYS_INLINE_ explicit SafeNumeric(T p_value = static_cast<T>(0)) {
		set(p_value);
	}
};

class SafeFlag {
	std::atomic_bool flag;

	static_assert(std::atomic_bool::is_always_lock_free);

public:
	_ALWAYS_INLINE_ bool is_set() const {
		return flag.load(std::memory_order_acquire);
	}

	_ALWAYS_INLINE_ void set() {
		flag.store(true, std::memory_order_release);
	}

	_ALWAYS_INLINE_ void clear() {
		flag.store(false, std::memory_order_release);
	}

	_ALWAYS_INLINE_ void set_to(bool p_value) {
		flag.store(p_value, std::memory_order_release);
	}

	_ALWAYS_INLINE_ explicit SafeFlag(bool p_value = false) {
		set_to(p_value);
	}
};

class SafeRefCount {
	SafeNumeric<uint32_t> count;

public:
	_ALWAYS_INLINE_ bool ref() { // true on success
		return count.conditional_increment() != 0;
	}

	_ALWAYS_INLINE_ uint32_t refval() { // none-zero on success
		return count.conditional_increment();
	}

	_ALWAYS_INLINE_ bool unref() { // true if must be disposed of
		return count.decrement() == 0;
	}

	_ALWAYS_INLINE_ uint32_t unrefval() { // 0 if must be disposed of
		return count.decrement();
	}

	_ALWAYS_INLINE_ uint32_t get() const {
		return count.get();
	}

	_ALWAYS_INLINE_ void init(uint32_t p_value = 1) {
		count.set(p_value);
	}
};

#else

template <typename T>
class SafeNumeric {
protected:
	T value;

public:
	_ALWAYS_INLINE_ void set(T p_value) {
		value = p_value;
	}

	_ALWAYS_INLINE_ T get() const {
		return value;
	}

	_ALWAYS_INLINE_ T increment() {
		return ++value;
	}

	_ALWAYS_INLINE_ T postincrement() {
		return value++;
	}

	_ALWAYS_INLINE_ T decrement() {
		return --value;
	}

	_ALWAYS_INLINE_ T postdecrement() {
		return value--;
	}

	_ALWAYS_INLINE_ T add(T p_value) {
		return value += p_value;
	}

	_ALWAYS_INLINE_ T postadd(T p_value) {
		T old = value;
		value += p_value;
		return old;
	}

	_ALWAYS_INLINE_ T sub(T p_value) {
		return value -= p_value;
	}

	_ALWAYS_INLINE_ T postsub(T p_value) {
		T old = value;
		value -= p_value;
		return old;
	}

	_ALWAYS_INLINE_ T exchange_if_greater(T p_value) {
		if (value < p_value) {
			value = p_value;
		}
		return value;
	}

	_ALWAYS_INLINE_ T conditional_increment() {
		if (value == 0) {
			return 0;
		} else {
			return ++value;
		}
	}

	_ALWAYS_INLINE_ explicit SafeNumeric<T>(T p_value = static_cast<T>(0)) :
			value(p_value) {
	}
};

class SafeFlag {
protected:
	bool flag;

public:
	_ALWAYS_INLINE_ bool is_set() const {
		return flag;
	}

	_ALWAYS_INLINE_ void set() {
		flag = true;
	}

	_ALWAYS_INLINE_ void clear() {
		flag = false;
	}

	_ALWAYS_INLINE_ void set_to(bool p_value) {
		flag = p_value;
	}

	_ALWAYS_INLINE_ explicit SafeFlag(bool p_value = false) :
			flag(p_value) {}
};

class SafeRefCount {
	uint32_t count = 0;

public:
	_ALWAYS_INLINE_ bool ref() { // true on success
		if (count != 0) {
			++count;
			return true;
		} else {
			return false;
		}
	}

	_ALWAYS_INLINE_ uint32_t refval() { // none-zero on success
		if (count != 0) {
			return ++count;
		} else {
			return 0;
		}
	}

	_ALWAYS_INLINE_ bool unref() { // true if must be disposed of
		return --count == 0;
	}

	_ALWAYS_INLINE_ uint32_t unrefval() { // 0 if must be disposed of
		return --count;
	}

	_ALWAYS_INLINE_ uint32_t get() const {
		return count;
	}

	_ALWAYS_INLINE_ void init(uint32_t p_value = 1) {
		count = p_value;
	}
};

#endif

} // namespace godot

#endif
#endif // GODOT_SAFE_REFCOUNT_HPP
