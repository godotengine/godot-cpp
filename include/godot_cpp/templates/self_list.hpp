/**************************************************************************/
/*  self_list.hpp                                                         */
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
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/templates/sort_list.hpp>

namespace godot {

/**
 * A link that associates an existing object with an intrusive doubly linked list. The link removes itself from its list on destruction. The object remains owned by its caller.
 *
 * ```cpp
 * // In a render task with a SelfList<RenderTask> member initialized with this.
 * ready_tasks.add_last(&ready_link); // Queue the task through its embedded link.
 * ```
 */
template <typename T>
class _WARN_UNUSED_ SelfList {
public:
	/**
	 * Tracks the head and tail of an intrusive list. The links and their objects have their own lifetimes. The list must be empty when it is destroyed.
	 *
	 * ```cpp
	 * // A renderer keeps a pending list of links embedded in its existing tasks.
	 * SelfList<RenderTask>::List pending;
	 * pending.add_last(&task.pending_link);
	 * pending.remove(&task.pending_link); // Task and link remain alive.
	 * ```
	 */
	class List {
		/**
		 * Points to the first attached link or is null when the list is empty.
		 *
		 * ```cpp
		 * // In List::add(), after linking the new first entry.
		 * _first = p_elem;
		 * ```
		 */
		SelfList<T> *_first = nullptr;
		/**
		 * Points to the last attached link or is null when the list is empty.
		 *
		 * ```cpp
		 * // In List::add_last(), after linking the new last entry.
		 * _last = p_elem;
		 * ```
		 */
		SelfList<T> *_last = nullptr;

	public:
		/**
		 * Links an unattached entry before the current first one. An entry already belonging to a list triggers an error.
		 *
		 * ```cpp
		 * // Put a newly prioritized job ahead of the other pending jobs.
		 * pending.add(&job.queue_link);
		 * ```
		 */
		void add(SelfList<T> *p_elem) {
			ERR_FAIL_COND(p_elem->_root);

			p_elem->_root = this;
			p_elem->_next = _first;
			p_elem->_prev = nullptr;

			if (_first) {
				_first->_prev = p_elem;

			} else {
				_last = p_elem;
			}

			_first = p_elem;
		}

		/**
		 * Links an unattached entry after the current last one. An entry already belonging to a list triggers an error.
		 *
		 * ```cpp
		 * // Put a new decode job after work already waiting in the queue.
		 * pending.add_last(&job.queue_link);
		 * ```
		 */
		void add_last(SelfList<T> *p_elem) {
			ERR_FAIL_COND(p_elem->_root);

			p_elem->_root = this;
			p_elem->_next = nullptr;
			p_elem->_prev = _last;

			if (_last) {
				_last->_next = p_elem;

			} else {
				_first = p_elem;
			}

			_last = p_elem;
		}

		/**
		 * Unlinks an entry belonging to this list and clears its links and membership pointer.
		 *
		 * ```cpp
		 * // The importer canceled this job while it was still queued.
		 * pending.remove(&job.queue_link);
		 * ```
		 */
		void remove(SelfList<T> *p_elem) {
			ERR_FAIL_COND(p_elem->_root != this);
			if (p_elem->_next) {
				p_elem->_next->_prev = p_elem->_prev;
			}

			if (p_elem->_prev) {
				p_elem->_prev->_next = p_elem->_next;
			}

			if (_first == p_elem) {
				_first = p_elem->_next;
			}

			if (_last == p_elem) {
				_last = p_elem->_prev;
			}

			p_elem->_next = nullptr;
			p_elem->_prev = nullptr;
			p_elem->_root = nullptr;
		}

		/**
		 * Unlinks every entry without deleting the entries or their associated objects.
		 *
		 * ```cpp
		 * // Cancel the queue when a scene unloads. Task owners keep their objects.
		 * pending.clear();
		 * ```
		 */
		void clear() {
			while (_first) {
				remove(_first);
			}
		}

		/**
		 * Reorders the links using the referenced values' default less-than comparison.
		 *
		 * ```cpp
		 * // Order pending jobs using RenderTask::operator<, which compares priority.
		 * pending.sort();
		 * if (auto *first = pending.first()) { first->self()->begin(); }
		 * ```
		 */
		void sort() {
			sort_custom<Comparator<T>>();
		}

		/**
		 * Reorders the links using a comparator applied to the referenced values.
		 *
		 * - `C` — A default-constructible comparator with a const call operator that tests whether one value precedes another.
		 *
		 * ```cpp
		 * // Reorder queued jobs by earliest deadline with a const comparator.
		 * pending.sort_custom<DeadlineOrder>();
		 * if (auto *first = pending.first()) { first->self()->begin(); }
		 * ```
		 */
		template <typename C>
		void sort_custom() {
			if (_first == _last) {
				return;
			}

			/**
			 * Adapts the value comparator to SortList's stored object pointers.
			 *
			 * ```cpp
			 * // In List::sort_custom().
			 * SortList<Element, T *, _self_ref, _prev_ref, _next_ref, PtrComparator> sorter;
			 * ```
			 */
			struct PtrComparator {
				/**
				 * Holds the value comparator invoked with the two referenced objects.
				 *
				 * ```cpp
				 * // In PtrComparator::operator()().
				 * return compare(*p_a, *p_b);
				 * ```
				 */
				C compare;
				/**
				 * Dereferences both object pointers and compares the resulting values.
				 *
				 * ```cpp
				 * // In List::sort_custom(), when comparing two existing links a and b.
				 * bool before = PtrComparator()(a->self(), b->self());
				 * ```
				 */
				_FORCE_INLINE_ bool operator()(const T *p_a, const T *p_b) const { return compare(*p_a, *p_b); }
			};
			/**
			 * Names the node type supplied to SortList. Each node owns its own links.
			 *
			 * ```cpp
			 * // In List::sort_custom().
			 * SortList<Element, T *, _self_ref, _prev_ref, _next_ref, PtrComparator> sorter;
			 * ```
			 */
			using Element = SelfList<T>;
			SortList<Element, T *, _self_ref, _prev_ref, _next_ref, PtrComparator> sorter;
			sorter.sort(_first, _last);
		}

		/**
		 * Returns the first mutable link or null if the list is empty.
		 *
		 * ```cpp
		 * // Remove the first job from a mutable ready queue before running it.
		 * if (auto *first = ready.first()) {
		 *     first->remove_from_list();
		 *     first->self()->begin();
		 * }
		 * ```
		 */
		_FORCE_INLINE_ SelfList<T> *first() { return _first; }
		/**
		 * Returns the first link as a const pointer for traversal, or null if the list is empty.
		 *
		 * ```cpp
		 * // Traverse a const job list while counting tasks for a diagnostics panel.
		 * int task_count = 0;
		 * for (const auto *link = pending.first(); link; link = link->next()) { ++task_count; }
		 * ```
		 */
		_FORCE_INLINE_ const SelfList<T> *first() const { return _first; }

		/**
		 * Disallows copy assignment because the links each point to their owning list.
		 *
		 * ```cpp
		 * static_assert(!std::is_copy_assignable_v<SelfList<int>::List>);
		 * ```
		 */
		void operator=(const List &) = delete;

		/**
		 * Checks in developer builds that no entries remain attached when the list is destroyed.
		 *
		 * ```cpp
		 * // In a queue owner's destructor, detach every link before the list member is destroyed.
		 * pending.clear();
		 * ```
		 */
		_FORCE_INLINE_ ~List() {
			// A self list must be empty on destruction.
			DEV_ASSERT(_first == nullptr);
		}
	};

private:
	/**
	 * Points to the list that currently owns the links. Null means this entry is detached.
	 *
	 * ```cpp
	 * // In SelfList::remove_from_list().
	 * if (_root) { _root->remove(this); }
	 * ```
	 */
	List *_root = nullptr;
	/**
	 * Points to the object associated with this link. The link does not delete the object.
	 *
	 * ```cpp
	 * // In SelfList's constructor.
	 * _self = p_self;
	 * ```
	 */
	T *_self = nullptr;
	/**
	 * Points to the next attached link, or is null at the tail or when detached.
	 *
	 * ```cpp
	 * // In List::add(), before replacing _first.
	 * p_elem->_next = _first;
	 * ```
	 */
	SelfList<T> *_next = nullptr;
	/**
	 * Points to the previous attached link, or is null at the head or when detached.
	 *
	 * ```cpp
	 * // In List::add_last(), before replacing _last.
	 * p_elem->_prev = _last;
	 * ```
	 */
	SelfList<T> *_prev = nullptr;
	// Specify pointers in variables to work around a VS 2022 bug (GH-121326).
	/**
	 * The member pointer that lets SortList read an element's associated object.
	 *
	 * ```cpp
	 * // In List::sort_custom().
	 * SortList<Element, T *, _self_ref, _prev_ref, _next_ref, PtrComparator> sorter;
	 * ```
	 */
	static constexpr T *SelfList<T>::*_self_ref = &SelfList<T>::_self;
	/**
	 * The member pointer that lets SortList read and update backward links.
	 *
	 * ```cpp
	 * // In List::sort_custom().
	 * SortList<Element, T *, _self_ref, _prev_ref, _next_ref, PtrComparator> sorter;
	 * ```
	 */
	static constexpr SelfList<T> *SelfList<T>::*_prev_ref = &SelfList<T>::_prev;
	/**
	 * The member pointer that lets SortList read and update forward links.
	 *
	 * ```cpp
	 * // In List::sort_custom().
	 * SortList<Element, T *, _self_ref, _prev_ref, _next_ref, PtrComparator> sorter;
	 * ```
	 */
	static constexpr SelfList<T> *SelfList<T>::*_next_ref = &SelfList<T>::_next;

public:
	/**
	 * Tests whether this link is currently attached to a list.
	 *
	 * ```cpp
	 * // Queue this task only if its embedded link is currently detached.
	 * if (!task.queue_link.in_list()) { pending.add_last(&task.queue_link); }
	 * ```
	 */
	_FORCE_INLINE_ bool in_list() const { return _root; }
	/**
	 * Detaches this link from its current list if it belongs to one.
	 *
	 * ```cpp
	 * // Cancel a job that may already have completed and left the queue.
	 * task.queue_link.remove_from_list();
	 * ```
	 */
	_FORCE_INLINE_ void remove_from_list() {
		if (_root) {
			_root->remove(this);
		}
	}
	/**
	 * Returns a mutable pointer to the next link. Returns null at the tail or when detached.
	 *
	 * ```cpp
	 * // During a forward traversal, save the successor before removing the current job.
	 * auto *next_job = link->next();
	 * link->remove_from_list();
	 * ```
	 */
	_FORCE_INLINE_ SelfList<T> *next() { return _next; }
	/**
	 * Returns a mutable pointer to the previous link. Returns null at the head or when detached.
	 *
	 * ```cpp
	 * // Insert a replacement at the front if there is no predecessor.
	 * bool replaces_head = link->prev() == nullptr;
	 * ```
	 */
	_FORCE_INLINE_ SelfList<T> *prev() { return _prev; }
	/**
	 * Returns a const pointer to the next link. Returns null at the tail or when detached.
	 *
	 * ```cpp
	 * // Count the remaining links after the current task in a read-only view.
	 * int remaining = 0;
	 * for (const auto *item = link->next(); item; item = item->next()) { ++remaining; }
	 * ```
	 */
	_FORCE_INLINE_ const SelfList<T> *next() const { return _next; }
	/**
	 * Returns a const pointer to the previous link. Returns null at the head or when detached.
	 *
	 * ```cpp
	 * // Walk backward from a const link until reaching the head.
	 * const auto *head = link;
	 * while (const auto *previous = head->prev()) { head = previous; }
	 * ```
	 */
	_FORCE_INLINE_ const SelfList<T> *prev() const { return _prev; }
	/**
	 * Returns the stored pointer to the associated object. A const link can still refer to a mutable object.
	 *
	 * ```cpp
	 * // In a ready queue, dispatch the object referenced by the first link.
	 * if (auto *first = ready.first()) { first->self()->begin(); }
	 * ```
	 */
	_FORCE_INLINE_ T *self() const { return _self; }

	/**
	 * Disallows assigning one link to another because a link's addresses and membership must stay consistent.
	 *
	 * ```cpp
	 * static_assert(!std::is_copy_assignable_v<SelfList<int>>);
	 * ```
	 */
	void operator=(const SelfList<T> &) = delete;

	/**
	 * Associates the new detached link with an existing object.
	 *
	 * ```cpp
	 * // As a member of RenderTask, link the task without allocating another node.
	 * SelfList<RenderTask> queue_link{ this };
	 * ```
	 */
	_FORCE_INLINE_ SelfList(T *p_self) {
		_self = p_self;
	}

	/**
	 * Detaches this link if it still belongs to a list, leaving the associated object alive.
	 *
	 * ```cpp
	 * // When a queued RenderTask is destroyed, its embedded link detaches automatically.
	 * SelfList<RenderTask>::List pending;
	 * {
	 *     RenderTask task;
	 *     pending.add_last(&task.queue_link);
	 * } // pending is empty.
	 * ```
	 */
	_FORCE_INLINE_ ~SelfList() {
		if (_root) {
			_root->remove(this);
		}
	}
};

} // namespace godot
