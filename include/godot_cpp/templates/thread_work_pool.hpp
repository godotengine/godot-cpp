/**************************************************************************/
/*  thread_work_pool.hpp                                                  */
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

#ifndef GODOT_THREAD_WORK_POOL_HPP
#define GODOT_THREAD_WORK_POOL_HPP

#ifdef GODOT_MODULE
#include "core/object/worker_thread_pool.h"
#else

#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/semaphore.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/core/memory.hpp>

#include <thread>

#include <atomic>

namespace godot {

class ThreadWorkPool {
	std::atomic<uint32_t> index;

	struct BaseWork {
		std::atomic<uint32_t> *index = nullptr;
		uint32_t max_elements = 0;
		virtual void work() = 0;
		virtual ~BaseWork() = default;
	};

	template <typename C, typename M, typename U>
	struct Work : public BaseWork {
		C *instance;
		M method;
		U userdata;
		virtual void work() {
			while (true) {
				uint32_t work_index = index->fetch_add(1, std::memory_order_relaxed);
				if (work_index >= max_elements) {
					break;
				}
				(instance->*method)(work_index, userdata);
			}
		}
	};

	struct ThreadData {
		std::thread thread;
		Semaphore start;
		Semaphore completed;
		std::atomic<bool> exit;
		BaseWork *work;
	};

	ThreadData *threads = nullptr;
	uint32_t thread_count = 0;
	uint32_t threads_working = 0;
	BaseWork *current_work = nullptr;

	static void _thread_function(void *p_user) {
		ThreadData *thread = static_cast<ThreadData *>(p_user);
		while (true) {
			thread->start.wait();
			if (thread->exit.load()) {
				break;
			}
			thread->work->work();
			thread->completed.post();
		}
	}

public:
	template <typename C, typename M, typename U>
	void begin_work(uint32_t p_elements, C *p_instance, M p_method, U p_userdata) {
		ERR_FAIL_NULL(threads); // Never initialized.
		ERR_FAIL_COND(current_work != nullptr);

		index.store(0, std::memory_order_release);

		Work<C, M, U> *w = new (Work<C, M, U>);
		w->instance = p_instance;
		w->userdata = p_userdata;
		w->method = p_method;
		w->index = &index;
		w->max_elements = p_elements;

		current_work = w;

		threads_working = Math::min(p_elements, thread_count);

		for (uint32_t i = 0; i < threads_working; i++) {
			threads[i].work = w;
			threads[i].start.post();
		}
	}

	bool is_working() const {
		return current_work != nullptr;
	}

	bool is_done_dispatching() const {
		ERR_FAIL_NULL_V(current_work, true);
		return index.load(std::memory_order_acquire) >= current_work->max_elements;
	}

	uint32_t get_work_index() const {
		ERR_FAIL_NULL_V(current_work, 0);
		uint32_t idx = index.load(std::memory_order_acquire);
		return Math::min(idx, current_work->max_elements);
	}

	void end_work() {
		ERR_FAIL_NULL(current_work);
		for (uint32_t i = 0; i < threads_working; i++) {
			threads[i].completed.wait();
			threads[i].work = nullptr;
		}

		threads_working = 0;
		delete current_work;
		current_work = nullptr;
	}

	template <typename C, typename M, typename U>
	void do_work(uint32_t p_elements, C *p_instance, M p_method, U p_userdata) {
		switch (p_elements) {
			case 0:
				// Nothing to do, so do nothing.
				break;
			case 1:
				// No value in pushing the work to another thread if it's a single job
				// and we're going to wait for it to finish. Just run it right here.
				(p_instance->*p_method)(0, p_userdata);
				break;
			default:
				// Multiple jobs to do; commence threaded business.
				begin_work(p_elements, p_instance, p_method, p_userdata);
				end_work();
		}
	}

	_FORCE_INLINE_ int get_thread_count() const { return thread_count; }
	void init(int p_thread_count = -1) {
		ERR_FAIL_COND(threads != nullptr);
		if (p_thread_count < 0) {
			p_thread_count = OS::get_singleton()->get_processor_count();
		}

		thread_count = p_thread_count;
		threads = new ThreadData[thread_count];

		for (uint32_t i = 0; i < thread_count; i++) {
			threads[i].exit.store(false);
			threads[i].thread = std::thread(&ThreadWorkPool::_thread_function, &threads[i]);
		}
	}

	void finish() {
		if (threads == nullptr) {
			return;
		}

		for (uint32_t i = 0; i < thread_count; i++) {
			threads[i].exit.store(true);
			threads[i].start.post();
		}
		for (uint32_t i = 0; i < thread_count; i++) {
			threads[i].thread.join();
		}

		delete[] (threads);
		threads = nullptr;
	}
	~ThreadWorkPool() {
		finish();
	}
};

} // namespace godot

#endif
#endif // GODOT_THREAD_WORK_POOL_HPP
