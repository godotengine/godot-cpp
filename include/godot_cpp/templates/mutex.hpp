/**************************************************************************/
/*  mutex.hpp                                                             */
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

#include <godot_cpp/core/defs.hpp>

#ifdef MINGW_ENABLED
/**
 * Configures the MinGW thread compatibility header's redundancy warning.
 */
#define MINGW_STDTHREAD_REDUNDANCY_WARNING
#include <thirdparty/mingw-std-threads/mingw.mutex.h>
/**
 * Selects the MinGW mutex and lock implementations.
 */
#define THREADING_NAMESPACE mingw_stdthread
#else
#include <mutex>
/**
 * Selects the standard C++ mutex and lock implementations.
 */
#define THREADING_NAMESPACE std
#endif

namespace godot {

#ifdef THREADS_ENABLED

/**
 * Declares the scoped lock wrapper for use by the mutex implementation.
 */
template <typename MutexT>
class MutexLock;

/**
 * Wraps a platform mutex and allows locking from const methods.
 *
 * - `StdMutexT` — The underlying recursive or nonrecursive platform mutex type.
 */
template <typename StdMutexT>
class MutexImpl {
	/**
	 * Gives the matching scoped lock access to the underlying mutex.
	 */
	friend class MutexLock<MutexImpl<StdMutexT>>;

	/**
	 * Exposes the underlying mutex type to the scoped lock.
	 */
	using StdMutexType = StdMutexT;

	/**
	 * Holds the native mutex, including when acquired through a const wrapper.
	 */
	mutable StdMutexT mutex;

public:
	/**
	 * Blocks until the calling thread acquires the mutex.
	 */
	_ALWAYS_INLINE_ void lock() const {
		mutex.lock();
	}

	/**
	 * Releases one acquisition by the calling thread.
	 */
	_ALWAYS_INLINE_ void unlock() const {
		mutex.unlock();
	}

	/**
	 * Attempts to acquire the mutex without blocking and reports whether it succeeded.
	 */
	_ALWAYS_INLINE_ bool try_lock() const {
		return mutex.try_lock();
	}
};

/**
 * Acquires a mutex for the lifetime of the scoped lock, with explicit temporary release and reacquisition.
 */
template <typename MutexT>
class [[nodiscard]] MutexLock {
	/**
	 * Owns the native scoped lock and tracks whether it currently holds the mutex.
	 */
	mutable THREADING_NAMESPACE::unique_lock<typename MutexT::StdMutexType> lock;

public:
	/**
	 * Acquires the supplied mutex and stores it for scoped release.
	 */
	explicit MutexLock(const MutexT &p_mutex) :
			lock(p_mutex.mutex) {}

	// Clarification: all the funny syntax is needed so this function exists only for binary mutexes.
	/**
	 * Provides access to the underlying unique lock for a compatible native binary mutex type.
	 */
	template <typename T = MutexT>
	_ALWAYS_INLINE_ THREADING_NAMESPACE::unique_lock<THREADING_NAMESPACE::mutex> &_get_lock(
			typename std::enable_if<std::is_same<T, THREADING_NAMESPACE::mutex>::value> * = nullptr) const {
		return lock;
	}

	/**
	 * Reacquires the mutex after a temporary release.
	 */
	_ALWAYS_INLINE_ void temp_relock() const {
		lock.lock();
	}

	/**
	 * Releases the mutex and keeps the scoped lock associated with it for later reacquisition.
	 */
	_ALWAYS_INLINE_ void temp_unlock() const {
		lock.unlock();
	}

	// TODO: Implement a `try_temp_relock` if needed (will also need a dummy method below).
};

/**
 * Recursive mutex. The owning thread can acquire it again and must release each acquisition.
 */
using Mutex = MutexImpl<THREADING_NAMESPACE::recursive_mutex>; // Recursive, for general use
/**
 * Nonrecursive mutex. The owning thread must release it before acquiring it again.
 */
using BinaryMutex = MutexImpl<THREADING_NAMESPACE::mutex>; // Non-recursive, handle with care

/**
 * Declares the per-instance recursive mutex used by the thread-safety macros.
 */
#define _THREAD_SAFE_CLASS_ mutable Mutex _thread_safe_;
/**
 * Acquires the per-instance mutex for the current scope.
 */
#define _THREAD_SAFE_METHOD_ MutexLock _thread_safe_method_(_thread_safe_);
/**
 * Explicitly acquires the per-instance mutex until a matching release.
 */
#define _THREAD_SAFE_LOCK_ _thread_safe_.lock();
/**
 * Releases an explicit acquisition of the per-instance mutex.
 */
#define _THREAD_SAFE_UNLOCK_ _thread_safe_.unlock();

#else // No threads.

/**
 * Provides the mutex interface in builds with thread support disabled.
 */
class MutexImpl {
	/**
	 * Stores the native mutex member in the disabled-thread implementation.
	 */
	mutable THREADING_NAMESPACE::mutex mutex;

public:
	/**
	 * Accepts a lock request without acquiring a mutex.
	 */
	void lock() const {}
	/**
	 * Accepts an unlock request without releasing a mutex.
	 */
	void unlock() const {}
	/**
	 * Reports success for a lock request in builds without thread support.
	 */
	bool try_lock() const { return true; }
};

/**
 * Provides the scoped mutex interface without acquiring a mutex in builds without thread support.
 */
template <typename MutexT>
class [[nodiscard]] MutexLock {
public:
	/**
	 * Constructs the disabled-thread scoped lock without touching the supplied mutex.
	 */
	MutexLock(const MutexT &p_mutex) {}

	/**
	 * Accepts a scoped reacquisition request in builds without thread support.
	 */
	void temp_relock() const {}
	/**
	 * Accepts a scoped release request in builds without thread support.
	 */
	void temp_unlock() const {}
};

/**
 * Alias for the disabled-thread implementation of the recursive mutex.
 */
using Mutex = MutexImpl;
/**
 * Alias for the disabled-thread implementation of the binary mutex.
 */
using BinaryMutex = MutexImpl;

/**
 * Expands to no member declaration when threads are disabled.
 */
#define _THREAD_SAFE_CLASS_
/**
 * Expands to no scoped lock when threads are disabled.
 */
#define _THREAD_SAFE_METHOD_
/**
 * Expands to no acquisition when threads are disabled.
 */
#define _THREAD_SAFE_LOCK_
/**
 * Expands to no release when threads are disabled.
 */
#define _THREAD_SAFE_UNLOCK_

#endif // THREADS_ENABLED

} // namespace godot
