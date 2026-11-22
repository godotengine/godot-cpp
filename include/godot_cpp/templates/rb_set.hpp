/**************************************************************************/
/*  rb_set.hpp                                                            */
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

#include <godot_cpp/core/memory.hpp>

#include <initializer_list>

namespace godot {
/**
 * Stores unique values in a red-black tree ordered by the comparator.
 *
 * The address of a stored node stays valid until that node is erased.
 *
 * - `T` — Type of the values stored and compared.
 * - `C` — Strict ordering predicate for lookup and iteration.
 * - `A` — Allocator used for tree nodes.
 *
 * Implementation based on:
 * https://web.archive.org/web/20120507164830/https://web.mit.edu/~emin/www/source_code/red_black_tree/index.html
 *
 * Core container guidance:
 * https://docs.godotengine.org/en/latest/engine_details/architecture/core_types.html#containers
 */
template <typename T, typename C = Comparator<T>, typename A = DefaultAllocator>
class _WARN_UNUSED_ RBSet {
	/**
	 * Stores the node colors used to maintain the balance of the red-black tree.
	 */
	enum Color {
		/// Marks a red node. Its children must be black when the tree is balanced.
		RED,
		/// Marks a black node. The empty-child sentinel is black.
		BLACK
	};
	/**
	 * Declares the record that holds the root, sentinel, and element count.
	 */
	struct _Data;

public:
	/**
	 * Holds a stored value at a stable address and links it into the tree and sorted list.
	 */
	class Element {
	private:
		/**
		 * Allows the container to change this node's links and stored data.
		 */
		friend class RBSet<T, C, A>;
		/**
		 * Stores this node's balance color. New nodes start red.
		 */
		int color = RED;
		/**
		 * Points to the subtree whose values follow this node in sorted order.
		 */
		Element *right = nullptr;
		/**
		 * Points to the subtree whose values precede this node in sorted order.
		 */
		Element *left = nullptr;
		/**
		 * Points to the parent node. The actual root is a child of the root sentinel.
		 */
		Element *parent = nullptr;
		/**
		 * Points to the next element in sorted order, or is null at the end.
		 */
		Element *_next = nullptr;
		/**
		 * Points to the preceding element in sorted order, or is null at the start.
		 */
		Element *_prev = nullptr;
		/**
		 * Stores the value used to order the node.
		 */
		T value;
		//_Data *data;

	public:
		/**
		 * Returns a read-only pointer to the next node in sorted order, or null if there is none.
		 */
		const Element *next() const {
			return _next;
		}
		/**
		 * Returns a writable pointer to the next node in sorted order, or null if there is none.
		 */
		Element *next() {
			return _next;
		}
		/**
		 * Returns a read-only pointer to the preceding node in sorted order, or null if there is none.
		 */
		const Element *prev() const {
			return _prev;
		}
		/**
		 * Returns a writable pointer to the preceding node in sorted order, or null if there is none.
		 */
		Element *prev() {
			return _prev;
		}
		/**
		 * Returns a writable reference to the stored value. A change that affects the sort order breaks tree lookups.
		 */
		T &get() {
			return value;
		}
		/**
		 * Returns a read-only reference to the stored value.
		 */
		const T &get() const {
			return value;
		}
	};

	/**
	 * Value type stored in each set node.
	 */
	typedef T ValueType;

	/**
	 * Visits elements in sorted order through links between adjacent nodes. Provides writable access to the stored values.
	 */
	struct Iterator {
		/**
		 * Returns the current value by reference. The iterator must refer to a node.
		 */
		_FORCE_INLINE_ T &operator*() const {
			return E->get();
		}
		/**
		 * Returns a pointer to the current value. The iterator must refer to a node.
		 */
		_FORCE_INLINE_ T *operator->() const { return &E->get(); }
		/**
		 * Moves from the current node to its successor. Advancing past the last node reaches the end iterator.
		 */
		_FORCE_INLINE_ Iterator &operator++() {
			E = E->next();
			return *this;
		}
		/**
		 * Moves from the current node to its predecessor. Moving before the first node leaves a null node pointer.
		 */
		_FORCE_INLINE_ Iterator &operator--() {
			E = E->prev();
			return *this;
		}

		/**
		 * Tests whether the iterators point to the same node.
		 *
		 * - `p_other` — Iterator whose node is compared with this iterator's node.
		 */
		_FORCE_INLINE_ bool operator==(const Iterator &p_other) const { return E == p_other.E; }
		/**
		 * Tests whether the iterators point to different nodes.
		 *
		 * - `p_other` — Iterator whose node is compared with this iterator's node.
		 */
		_FORCE_INLINE_ bool operator!=(const Iterator &p_other) const { return E != p_other.E; }

		/**
		 * Tests whether the iterator refers to a node. A null node pointer represents the end.
		 */
		explicit operator bool() const { return E != nullptr; }
		/**
		 * Starts at the supplied node, with null representing the end.
		 *
		 * - `p_element` — Node at which to place the iterator.
		 */
		Iterator(Element *p_element) { E = p_element; }
		/**
		 * Creates an iterator with no current node.
		 */
		Iterator() {}
		/**
		 * Copies the source iterator's node position.
		 *
		 * - `p_it` — Iterator whose node pointer is copied.
		 */
		Iterator(const Iterator &p_it) { E = p_it.E; }

	private:
		/**
		 * Points to the current node or is null when the iterator has no node.
		 */
		Element *E = nullptr;
	};

	/**
	 * Visits elements in sorted order through links between adjacent nodes. Provides read-only access to the stored values.
	 */
	struct ConstIterator {
		/**
		 * Returns the current value by const reference. The iterator must refer to a node.
		 */
		_FORCE_INLINE_ const T &operator*() const {
			return E->get();
		}
		/**
		 * Returns a pointer to the current value. The iterator must refer to a node.
		 */
		_FORCE_INLINE_ const T *operator->() const { return &E->get(); }
		/**
		 * Moves from the current node to its successor. Advancing past the last node reaches the end iterator.
		 */
		_FORCE_INLINE_ ConstIterator &operator++() {
			E = E->next();
			return *this;
		}
		/**
		 * Moves from the current node to its predecessor. Moving before the first node leaves a null node pointer.
		 */
		_FORCE_INLINE_ ConstIterator &operator--() {
			E = E->prev();
			return *this;
		}

		/**
		 * Tests whether the iterators point to the same node.
		 *
		 * - `p_other` — Iterator whose node is compared with this iterator's node.
		 */
		_FORCE_INLINE_ bool operator==(const ConstIterator &p_other) const { return E == p_other.E; }
		/**
		 * Tests whether the iterators point to different nodes.
		 *
		 * - `p_other` — Iterator whose node is compared with this iterator's node.
		 */
		_FORCE_INLINE_ bool operator!=(const ConstIterator &p_other) const { return E != p_other.E; }

		/**
		 * Starts at the supplied node, with null representing the end.
		 *
		 * - `p_element` — Node at which to place the iterator.
		 */
		_FORCE_INLINE_ ConstIterator(const Element *p_element) { E = p_element; }
		/**
		 * Creates an iterator with no current node.
		 */
		_FORCE_INLINE_ ConstIterator() {}
		/**
		 * Copies the source iterator's node position.
		 *
		 * - `p_it` — Iterator whose node pointer is copied.
		 */
		_FORCE_INLINE_ ConstIterator(const ConstIterator &p_it) { E = p_it.E; }

		/**
		 * Tests whether the iterator refers to a node. A null node pointer represents the end.
		 */
		explicit operator bool() const { return E != nullptr; }

	private:
		/**
		 * Points to the current node or is null when the iterator has no node.
		 */
		const Element *E = nullptr;
	};

	/**
	 * Returns a writable iterator to the first node in sorted order, or the end if empty.
	 */
	_FORCE_INLINE_ Iterator begin() {
		return Iterator(front());
	}
	/**
	 * Returns the writable end iterator with no current node.
	 */
	_FORCE_INLINE_ Iterator end() {
		return Iterator(nullptr);
	}

#if 0
	//to use when replacing find()
	/**
	 * In this disabled branch, wraps the result of key lookup in a writable iterator.
	 *
	 * - `p_key` — Lookup key.
	 */
	_FORCE_INLINE_ Iterator find(const K &p_key) {
		return Iterator(find(p_key));
	}
#endif

	/**
	 * Returns a read-only iterator to the first node in sorted order, or the end if empty.
	 */
	_FORCE_INLINE_ ConstIterator begin() const {
		return ConstIterator(front());
	}
	/**
	 * Returns the read-only end iterator with no current node.
	 */
	_FORCE_INLINE_ ConstIterator end() const {
		return ConstIterator(nullptr);
	}

#if 0
	//to use when replacing find()
	/**
	 * In this disabled branch, wraps the result of key lookup in a read-only iterator.
	 *
	 * - `p_key` — Lookup key.
	 */
	_FORCE_INLINE_ ConstIterator find(const K &p_key) const {
		return ConstIterator(find(p_key));
	}
#endif
private:
	/**
	 * Holds the tree sentinels and the number of stored elements.
	 */
	struct _Data {
		/**
		 * Points to the root sentinel. Its left link leads to the actual root.
		 */
		Element *_root = nullptr;
		/**
		 * Points to the black sentinel used for absent tree links.
		 */
		Element *_nil = nullptr;
		/**
		 * Counts stored nodes without counting either sentinel.
		 */
		int size_cache = 0;

		/**
		 * Sets up the empty-child sentinel. Uses the shared sentinel unless the build disables it.
		 */
		_FORCE_INLINE_ _Data() {
#ifdef GLOBALNIL_DISABLED
			_nil = memnew_allocator(Element, A);
			_nil->parent = _nil->left = _nil->right = _nil;
			_nil->color = BLACK;
#else
			_nil = (Element *)&_GlobalNilClass::_nil;
#endif
		}

		/**
		 * Creates the root sentinel and sets its links to the empty-child sentinel.
		 */
		void _create_root() {
			_root = memnew_allocator(Element, A);
			_root->parent = _root->left = _root->right = _nil;
			_root->color = BLACK;
		}

		/**
		 * Frees an existing root sentinel and sets its pointer to null.
		 */
		void _free_root() {
			if (_root) {
				memdelete_allocator<Element, A>(_root);
				_root = nullptr;
			}
		}

		/**
		 * Frees the root sentinel and frees the empty-child sentinel if this record owns it.
		 */
		~_Data() {
			_free_root();

#ifdef GLOBALNIL_DISABLED
			memdelete_allocator<Element, A>(_nil);
#endif
		}
	};

	/**
	 * Stores the sentinels and count for this tree.
	 */
	_Data _data;

	/**
	 * Sets the node's color while keeping the empty-child sentinel black.
	 *
	 * - `p_node` — Node in this tree.
	 * - `p_color` — Color to apply to a regular node.
	 */
	inline void _set_color(Element *p_node, int p_color) {
		ERR_FAIL_COND(p_node == _data._nil && p_color == RED);
		p_node->color = p_color;
	}

	/**
	 * Rotates a subtree left, putting the right child in the old root's place.
	 *
	 * - `p_node` — Root of the subtree to rotate.
	 */
	inline void _rotate_left(Element *p_node) {
		Element *r = p_node->right;
		p_node->right = r->left;
		if (r->left != _data._nil) {
			r->left->parent = p_node;
		}
		r->parent = p_node->parent;
		if (p_node == p_node->parent->left) {
			p_node->parent->left = r;
		} else {
			p_node->parent->right = r;
		}

		r->left = p_node;
		p_node->parent = r;
	}

	/**
	 * Rotates a subtree right, putting the left child in the old root's place.
	 *
	 * - `p_node` — Root of the subtree to rotate.
	 */
	inline void _rotate_right(Element *p_node) {
		Element *l = p_node->left;
		p_node->left = l->right;
		if (l->right != _data._nil) {
			l->right->parent = p_node;
		}
		l->parent = p_node->parent;
		if (p_node == p_node->parent->right) {
			p_node->parent->right = l;
		} else {
			p_node->parent->left = l;
		}

		l->right = p_node;
		p_node->parent = l;
	}

	/**
	 * Finds the next node in sorted order by following child and parent links.
	 *
	 * - `p_node` — Node in this tree.
	 */
	inline Element *_successor(Element *p_node) const {
		Element *node = p_node;

		if (node->right != _data._nil) {
			node = node->right;
			while (node->left != _data._nil) { /* returns the minimum of the right subtree of node */
				node = node->left;
			}
			return node;
		} else {
			while (node == node->parent->right) {
				node = node->parent;
			}

			if (node->parent == _data._root) {
				return nullptr; // No successor, as p_node = last node
			}
			return node->parent;
		}
	}

	/**
	 * Finds the preceding node in sorted order by following child and parent links.
	 *
	 * - `p_node` — Node in this tree.
	 */
	inline Element *_predecessor(Element *p_node) const {
		Element *node = p_node;

		if (node->left != _data._nil) {
			node = node->left;
			while (node->right != _data._nil) { /* returns the minimum of the left subtree of node */
				node = node->right;
			}
			return node;
		} else {
			while (node == node->parent->left) {
				node = node->parent;
			}

			if (node == _data._root) {
				return nullptr; // No predecessor, as p_node = first node.
			}
			return node->parent;
		}
	}

	/**
	 * Searches the tree for an equivalent value. Returns null if it reaches the empty-child sentinel.
	 *
	 * - `p_value` — Value used in the tree comparison.
	 */
	Element *_find(const T &p_value) const {
		Element *node = _data._root->left;
		C less;

		while (node != _data._nil) {
			if (less(p_value, node->value)) {
				node = node->left;
			} else if (less(node->value, p_value)) {
				node = node->right;
			} else {
				return node; // found
			}
		}

		return nullptr;
	}

	/**
	 * Finds the smallest value at or above the search value, or returns null.
	 *
	 * - `p_value` — Value used in the tree comparison.
	 */
	Element *_lower_bound(const T &p_value) const {
		Element *node = _data._root->left;
		Element *prev = nullptr;
		C less;

		while (node != _data._nil) {
			prev = node;

			if (less(p_value, node->value)) {
				node = node->left;
			} else if (less(node->value, p_value)) {
				node = node->right;
			} else {
				return node; // found
			}
		}

		if (prev == nullptr) {
			return nullptr; // tree empty
		}

		if (less(prev->value, p_value)) {
			prev = prev->_next;
		}

		return prev;
	}

	/**
	 * Restores red-black balance after linking a new red node. Uses recoloring and rotations.
	 *
	 * - `p_new_node` — Node that was just linked into the tree.
	 */
	void _insert_rb_fix(Element *p_new_node) {
		Element *node = p_new_node;
		Element *nparent = node->parent;
		Element *ngrand_parent = nullptr;

		while (nparent->color == RED) {
			ngrand_parent = nparent->parent;

			if (nparent == ngrand_parent->left) {
				if (ngrand_parent->right->color == RED) {
					_set_color(nparent, BLACK);
					_set_color(ngrand_parent->right, BLACK);
					_set_color(ngrand_parent, RED);
					node = ngrand_parent;
					nparent = node->parent;
				} else {
					if (node == nparent->right) {
						_rotate_left(nparent);
						node = nparent;
						nparent = node->parent;
					}
					_set_color(nparent, BLACK);
					_set_color(ngrand_parent, RED);
					_rotate_right(ngrand_parent);
				}
			} else {
				if (ngrand_parent->left->color == RED) {
					_set_color(nparent, BLACK);
					_set_color(ngrand_parent->left, BLACK);
					_set_color(ngrand_parent, RED);
					node = ngrand_parent;
					nparent = node->parent;
				} else {
					if (node == nparent->left) {
						_rotate_right(nparent);
						node = nparent;
						nparent = node->parent;
					}
					_set_color(nparent, BLACK);
					_set_color(ngrand_parent, RED);
					_rotate_left(ngrand_parent);
				}
			}
		}

		_set_color(_data._root->left, BLACK);
	}

	/**
	 * Adds the value in sorted order, or returns the existing node when an equivalent value is present.
	 *
	 * - `p_value` — Value to store, ordered by the set comparator.
	 */
	Element *_insert(const T &p_value) {
		Element *new_parent = _data._root;
		Element *node = _data._root->left;
		C less;

		while (node != _data._nil) {
			new_parent = node;

			if (less(p_value, node->value)) {
				node = node->left;
			} else if (less(node->value, p_value)) {
				node = node->right;
			} else {
				return node; // Return existing node
			}
		}

		Element *new_node = memnew_allocator(Element, A);
		new_node->parent = new_parent;
		new_node->right = _data._nil;
		new_node->left = _data._nil;
		new_node->value = p_value;
		//new_node->data=_data;

		if (new_parent == _data._root || less(p_value, new_parent->value)) {
			new_parent->left = new_node;
		} else {
			new_parent->right = new_node;
		}

		new_node->_next = _successor(new_node);
		new_node->_prev = _predecessor(new_node);
		if (new_node->_next) {
			new_node->_next->_prev = new_node;
		}
		if (new_node->_prev) {
			new_node->_prev->_next = new_node;
		}

		_data.size_cache++;
		_insert_rb_fix(new_node);
		return new_node;
	}

	/**
	 * Restores red-black balance after removing a black node. The repair starts from the sibling of the replacement position.
	 *
	 * - `p_node` — Sibling at the position where black depth needs repair.
	 */
	void _erase_fix_rb(Element *p_node) {
		Element *root = _data._root->left;
		Element *node = _data._nil;
		Element *sibling = p_node;
		Element *parent = sibling->parent;

		while (node != root) { // If red node found, will exit at a break
			if (sibling->color == RED) {
				_set_color(sibling, BLACK);
				_set_color(parent, RED);
				if (sibling == parent->right) {
					sibling = sibling->left;
					_rotate_left(parent);
				} else {
					sibling = sibling->right;
					_rotate_right(parent);
				}
			}
			if ((sibling->left->color == BLACK) && (sibling->right->color == BLACK)) {
				_set_color(sibling, RED);
				if (parent->color == RED) {
					_set_color(parent, BLACK);
					break;
				} else { // loop: haven't found any red nodes yet
					node = parent;
					parent = node->parent;
					sibling = (node == parent->left) ? parent->right : parent->left;
				}
			} else {
				if (sibling == parent->right) {
					if (sibling->right->color == BLACK) {
						_set_color(sibling->left, BLACK);
						_set_color(sibling, RED);
						_rotate_right(sibling);
						sibling = sibling->parent;
					}
					_set_color(sibling, parent->color);
					_set_color(parent, BLACK);
					_set_color(sibling->right, BLACK);
					_rotate_left(parent);
					break;
				} else {
					if (sibling->left->color == BLACK) {
						_set_color(sibling->right, BLACK);
						_set_color(sibling, RED);
						_rotate_left(sibling);
						sibling = sibling->parent;
					}

					_set_color(sibling, parent->color);
					_set_color(parent, BLACK);
					_set_color(sibling->left, BLACK);
					_rotate_right(parent);
					break;
				}
			}
		}

		ERR_FAIL_COND(_data._nil->color != BLACK);
	}

	/**
	 * Unlinks and destroys the target node and updates its neighbors in sorted order. A successor can take its place in the tree.
	 *
	 * - `p_node` — Node to erase from this tree.
	 */
	void _erase(Element *p_node) {
		Element *rp = ((p_node->left == _data._nil) || (p_node->right == _data._nil)) ? p_node : p_node->_next;
		Element *node = (rp->left == _data._nil) ? rp->right : rp->left;

		Element *sibling = nullptr;
		if (rp == rp->parent->left) {
			rp->parent->left = node;
			sibling = rp->parent->right;
		} else {
			rp->parent->right = node;
			sibling = rp->parent->left;
		}

		if (node->color == RED) {
			node->parent = rp->parent;
			_set_color(node, BLACK);
		} else if (rp->color == BLACK && rp->parent != _data._root) {
			_erase_fix_rb(sibling);
		}

		if (rp != p_node) {
			ERR_FAIL_COND(rp == _data._nil);

			rp->left = p_node->left;
			rp->right = p_node->right;
			rp->parent = p_node->parent;
			rp->color = p_node->color;
			if (p_node->left != _data._nil) {
				p_node->left->parent = rp;
			}
			if (p_node->right != _data._nil) {
				p_node->right->parent = rp;
			}

			if (p_node == p_node->parent->left) {
				p_node->parent->left = rp;
			} else {
				p_node->parent->right = rp;
			}
		}

		if (p_node->_next) {
			p_node->_next->_prev = p_node->_prev;
		}
		if (p_node->_prev) {
			p_node->_prev->_next = p_node->_next;
		}

		memdelete_allocator<Element, A>(p_node);
		_data.size_cache--;
		ERR_FAIL_COND(_data._nil->color == RED);
	}

	/**
	 * Visits every node in the subtree and records the greatest depth encountered.
	 *
	 * - `p_element` — Root of the subtree to visit, or the empty-child sentinel.
	 * - `p_max_d` — Running maximum. Updated when this subtree contains a deeper node.
	 * - `p_d` — Depth of the supplied node in edges from the actual tree root.
	 */
	void _calculate_depth(Element *p_element, int &p_max_d, int p_d) const {
		if (p_element == _data._nil) {
			return;
		}

		_calculate_depth(p_element->left, p_max_d, p_d + 1);
		_calculate_depth(p_element->right, p_max_d, p_d + 1);

		if (p_d > p_max_d) {
			p_max_d = p_d;
		}
	}

	/**
	 * Destroys the subtree after destroying both children of each node.
	 *
	 * - `p_element` — Root of the subtree to destroy, or the empty-child sentinel.
	 */
	void _cleanup_tree(Element *p_element) {
		if (p_element == _data._nil) {
			return;
		}

		_cleanup_tree(p_element->left);
		_cleanup_tree(p_element->right);
		memdelete_allocator<Element, A>(p_element);
	}

	/**
	 * Clears the destination and inserts copies of the source elements in sorted order.
	 *
	 * - `p_set` — Source set.
	 */
	void _copy_from(const RBSet &p_set) {
		clear();
		// not the fastest way, but safeset to write.
		for (Element *I = p_set.front(); I; I = I->next()) {
			insert(I->get());
		}
	}

public:
	/**
	 * Returns a read-only pointer to the matching value's node, or null.
	 *
	 * - `p_value` — Value used in the tree comparison.
	 */
	const Element *find(const T &p_value) const {
		if (!_data._root) {
			return nullptr;
		}

		const Element *res = _find(p_value);
		return res;
	}

	/**
	 * Returns a writable pointer to the matching value's node, or null.
	 *
	 * - `p_value` — Value used in the tree comparison.
	 */
	Element *find(const T &p_value) {
		if (!_data._root) {
			return nullptr;
		}

		Element *res = _find(p_value);
		return res;
	}

	/**
	 * Returns the node with the smallest value at or above the supplied value, or null.
	 *
	 * - `p_value` — Value used in the tree comparison.
	 */
	Element *lower_bound(const T &p_value) const {
		if (!_data._root) {
			return nullptr;
		}
		return _lower_bound(p_value);
	}

	/**
	 * Tests whether an equivalent value is present.
	 *
	 * - `p_value` — Value used in the tree comparison.
	 */
	bool has(const T &p_value) const {
		return find(p_value) != nullptr;
	}

	/**
	 * Adds the value if absent and returns the new or existing node.
	 *
	 * - `p_value` — Value to store, ordered by the set comparator.
	 */
	Element *insert(const T &p_value) {
		if (!_data._root) {
			_data._create_root();
		}
		return _insert(p_value);
	}

	/**
	 * Erases the given node and frees the root sentinel if the tree becomes empty.
	 *
	 * - `p_element` — Node in this tree to erase. Null has no effect.
	 */
	void erase(Element *p_element) {
		if (!_data._root || !p_element) {
			return;
		}

		_erase(p_element);
		if (_data.size_cache == 0 && _data._root) {
			_data._free_root();
		}
	}

	/**
	 * Erases the matching value and returns whether it was present.
	 *
	 * - `p_value` — Value used in the tree comparison.
	 */
	bool erase(const T &p_value) {
		if (!_data._root) {
			return false;
		}

		Element *e = find(p_value);
		if (!e) {
			return false;
		}

		_erase(e);
		if (_data.size_cache == 0 && _data._root) {
			_data._free_root();
		}
		return true;
	}

	/**
	 * Returns the node with the first value in sorted order, or null if empty.
	 */
	Element *front() const {
		if (!_data._root) {
			return nullptr;
		}

		Element *e = _data._root->left;
		if (e == _data._nil) {
			return nullptr;
		}

		while (e->left != _data._nil) {
			e = e->left;
		}

		return e;
	}

	/**
	 * Returns the node with the last value in sorted order, or null if empty.
	 */
	Element *back() const {
		if (!_data._root) {
			return nullptr;
		}

		Element *e = _data._root->left;
		if (e == _data._nil) {
			return nullptr;
		}

		while (e->right != _data._nil) {
			e = e->right;
		}

		return e;
	}

	/**
	 * Tests whether the tree stores no elements.
	 */
	inline bool is_empty() const {
		return _data.size_cache == 0;
	}
	/**
	 * Returns the number of stored elements.
	 */
	inline int size() const {
		return _data.size_cache;
	}

	/**
	 * Returns the greatest node depth measured in edges from the actual root. An empty tree has depth zero.
	 */
	int calculate_depth() const {
		// used for debug mostly
		if (!_data._root) {
			return 0;
		}

		int max_d = 0;
		_calculate_depth(_data._root->left, max_d, 0);
		return max_d;
	}

	/**
	 * Destroys all stored nodes and frees the root sentinel.
	 */
	void clear() {
		if (!_data._root) {
			return;
		}

		_cleanup_tree(_data._root->left);
		_data._root->left = _data._nil;
		_data.size_cache = 0;
		_data._free_root();
	}

	/**
	 * Replaces the stored elements with copies of the source elements. Self-assignment has no effect.
	 *
	 * - `p_set` — Source set.
	 */
	void operator=(const RBSet &p_set) {
		if (this == &p_set) {
			return;
		}

		_copy_from(p_set);
	}

	/**
	 * Exchanges the two roots and counts. Self-assignment has no effect.
	 *
	 * - `p_set` — Other set whose tree is exchanged with this one.
	 */
	void operator=(RBSet &&p_set) {
		if (this == &p_set) {
			return;
		}

		SWAP(_data._root, p_set._data._root);
		SWAP(_data.size_cache, p_set._data.size_cache);
	}

	/**
	 * Creates a tree with independent copies of the source elements.
	 *
	 * - `p_set` — Source set.
	 */
	explicit RBSet(const RBSet &p_set) {
		_copy_from(p_set);
	}

	/**
	 * Takes the source tree and leaves it empty.
	 *
	 * - `p_set` — Source set.
	 */
	RBSet(RBSet &&p_set) {
		_data._root = p_set._data._root;
		_data.size_cache = p_set._data.size_cache;

		p_set._data._root = nullptr;
		p_set._data.size_cache = 0;
	}

	/**
	 * Inserts the values in the list. Equivalent values share one node.
	 *
	 * - `p_init` — Initial values in insertion order.
	 */
	RBSet(std::initializer_list<T> p_init) {
		for (const T &E : p_init) {
			insert(E);
		}
	}

	/**
	 * Creates an empty tree. The root sentinel is created when an insertion needs it.
	 */
	_FORCE_INLINE_ RBSet() {}

	/**
	 * Destroys the stored nodes and releases the owned sentinels.
	 */
	~RBSet() {
		clear();
	}
};

} // namespace godot
