/**************************************************************************/
/*  spin_lock.hpp                                                         */
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

#include <atomic>
#include <godot_cpp/core/defs.hpp>

namespace godot {

/**
 * Provides exclusive access through an atomic flag. A thread waiting to acquire the flag repeatedly tests it.
 *
 * **Used for** protecting a worker queue while a thread adds or removes an item.
 *
 * ```cpp
 * // A worker has decoded decoded_id. SpinLock ready_lock protects the shared ready_ids queue.
 * std::lock_guard<SpinLock> guard(ready_lock); // With <mutex> included.
 * ready_ids.push_back(decoded_id);
 * ```
 */
class SpinLock {
	/**
	 * Tracks ownership. The flag starts clear and is published as clear when the owner releases it.
	 *
	 * ```cpp
	 * // In SpinLock::unlock().
	 * locked.clear(std::memory_order_release);
	 * ```
	 */
	std::atomic_flag locked = ATOMIC_FLAG_INIT;

public:
	/**
	 * Waits until it can set the flag and take the lock. The acquire operation observes work published by a previous unlock.
	 *
	 * **Used for** taking exclusive access before writing an item to a shared queue.
	 *
	 * ```cpp
	 * // A worker publishes decoded_id after decoding it. SpinLock ready_lock protects ready_ids.
	 * ready_lock.lock();
	 * ready_ids.push_back(decoded_id);
	 * ready_lock.unlock();
	 * ```
	 */
	_ALWAYS_INLINE_ void lock() {
		while (locked.test_and_set(std::memory_order_acquire)) {
			;
		}
	}
	/**
	 * Clears the flag with release ordering so another thread can acquire the lock and observe the protected writes.
	 *
	 * **Used for** letting another worker take the lock before the current thread processes the work it
	 * removed.
	 *
	 * ```cpp
	 * // In the main thread, with ready_lock taken and ready_ids shared with workers.
	 * const bool has_finished_work = !ready_ids.is_empty();
	 * ready_lock.unlock(); // Workers can publish more IDs before main-thread processing.
	 * ```
	 */
	_ALWAYS_INLINE_ void unlock() {
		locked.clear(std::memory_order_release);
	}
};

} // namespace godot
