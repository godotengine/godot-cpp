/**************************************************************************/
/*  object_id.hpp                                                         */
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

namespace godot {

/**
 * A 64-bit Godot object instance identifier. Zero represents no object.
 * An identifier on its own does not keep its object alive.
 *
 * **Used for** remembering an editor selection across updates and looking it up again if the object is
 * still alive.
 *
 * ```cpp
 * // In an editor selection tool, with Node *selected supplied by the selection event.
 * ObjectID selected_id(selected->get_instance_id()); // Store it for the next update.
 * Node *live_selection = Object::cast_to<Node>(ObjectDB::get_instance(selected_id));
 * if (!live_selection) { return; } // The selection may have been freed.
 * ```
 */
class ObjectID {
	/**
	 * Stores the instance identifier. The top bit marks IDs issued to reference-counted objects.
	 *
	 * ```cpp
	 * // In ObjectID::is_ref_counted().
	 * return (id & (uint64_t(1) << 63)) != 0;
	 * ```
	 */
	uint64_t id = 0;

public:
	/**
	 * Tests the bit that marks identifiers issued to reference-counted objects.
	 *
	 * **Used for** checking the kind of object an ID was issued for before resolving the ID.
	 *
	 * ```cpp
	 * Ref<Resource> resource;
	 * resource.instantiate();
	 * ObjectID id(resource->get_instance_id());
	 * // Retain the Ref while a deferred job uses the resource. This ID carries no ownership.
	 * bool is_resource_id = id.is_ref_counted();
	 * ```
	 */
	_FORCE_INLINE_ bool is_ref_counted() const { return (id & (uint64_t(1) << 63)) != 0; }
	/**
	 * Tests whether the stored identifier is nonzero. It can still refer to a destroyed object.
	 *
	 * **Used for** skipping an object lookup when a stored selection ID was never set.
	 *
	 * ```cpp
	 * // In a deferred update, with cached_id saved from the previous selection event.
	 * if (!cached_id.is_valid()) { return; } // No initial selection.
	 * Object *selection = ObjectDB::get_instance(cached_id); // Check whether it still exists.
	 * ```
	 */
	_FORCE_INLINE_ bool is_valid() const { return id != 0; }
	/**
	 * Tests whether the identifier contains the zero sentinel.
	 *
	 * **Used for** recognizing the cleared selection in a tool that stores an object ID.
	 *
	 * ```cpp
	 * // In a drag handler that stores the grabbed node's ID across pointer events.
	 * if (grabbed_id.is_null()) { return; } // The pointer press grabbed no node.
	 * ```
	 */
	_FORCE_INLINE_ bool is_null() const { return id == 0; }
	/**
	 * Returns the full identifier as an unsigned integer for native object lookup.
	 *
	 * **Used for** passing a saved ID to `godot::ObjectDB::get_instance()`.
	 *
	 * ```cpp
	 * // In the deferred update, with saved_id captured from Node::get_instance_id().
	 * Object *live_node = ObjectDB::get_instance(static_cast<uint64_t>(saved_id));
	 * ```
	 */
	_FORCE_INLINE_ operator uint64_t() const { return id; }
	/**
	 * Returns the identifier in the signed 64-bit integer form used by Variant.
	 *
	 * **Used for** writing an ID to a `godot::Variant` integer in a deferred event.
	 *
	 * ```cpp
	 * // When writing a selection ID captured from a Node into a Variant-backed event.
	 * Dictionary event;
	 * event["target_id"] = static_cast<int64_t>(selected_id);
	 * ```
	 */
	_FORCE_INLINE_ operator int64_t() const { return id; }

	/**
	 * Compares the complete identifiers for equality.
	 *
	 * **Used for** checking whether a selection event targets the already selected object.
	 *
	 * - `p_id` — Identifier to compare with the current ID.
	 *
	 * ```cpp
	 * // In an editor selection handler receiving a Node *clicked and a cached ObjectID.
	 * ObjectID clicked_id(clicked->get_instance_id());
	 * if (clicked_id == selected_id) { return; } // Avoid restarting the same preview.
	 * ```
	 */
	_FORCE_INLINE_ bool operator==(const ObjectID &p_id) const { return id == p_id.id; }
	/**
	 * Tests whether the stored identifiers differ.
	 *
	 * **Used for** detecting whether the press and release in a click event targeted different objects.
	 *
	 * - `p_id` — Identifier to test for a different value.
	 *
	 * ```cpp
	 * // In an input handler, with both IDs captured from the pressed and released nodes.
	 * bool cancel_click = pressed_id != released_id;
	 * ```
	 */
	_FORCE_INLINE_ bool operator!=(const ObjectID &p_id) const { return id != p_id.id; }
	/**
	 * Orders identifiers by their unsigned integer values.
	 *
	 * **Used for** sorting recorded object IDs into numeric order for diagnostics.
	 *
	 * - `p_id` — Identifier on the right side of the unsigned comparison.
	 *
	 * ```cpp
	 * // When emitting diagnostics in a repeatable order within the current run.
	 * LocalVector<ObjectID> ids;
	 * ids.push_back(ObjectID(uint64_t(11)));
	 * ids.push_back(ObjectID(uint64_t(7)));
	 * ids.sort(); // Numeric ID order.
	 * ```
	 */
	_FORCE_INLINE_ bool operator<(const ObjectID &p_id) const { return id < p_id.id; }

	/**
	 * Stores an identifier supplied in signed 64-bit form.
	 *
	 * **Used for** replacing a stored target ID with one read from a Variant event.
	 *
	 * - `p_int64` — Signed integer form of the new ID. Zero clears the stored ID.
	 *
	 * ```cpp
	 * // When decoding an event written with a signed Variant integer.
	 * ObjectID receiver;
	 * receiver = static_cast<int64_t>(event["target_id"]);
	 * Object *live_target = ObjectDB::get_instance(receiver);
	 * ```
	 */
	_FORCE_INLINE_ void operator=(int64_t p_int64) { id = p_int64; }
	/**
	 * Stores the supplied native unsigned instance identifier.
	 *
	 * **Used for** updating a stored focus ID from the focused object's instance ID.
	 *
	 * - `p_uint64` — Native unsigned instance ID to store. Zero clears the stored ID.
	 *
	 * ```cpp
	 * // In a focus handler with Node *focused supplied by the UI.
	 * focused_id = focused->get_instance_id(); // focused_id is a stored ObjectID.
	 * ```
	 */
	_FORCE_INLINE_ void operator=(uint64_t p_uint64) { id = p_uint64; }

	/**
	 * Creates a null identifier with value zero.
	 *
	 * **Used for** starting an object tracking field before a target has been assigned.
	 *
	 * ```cpp
	 * // In a tool's state, before a preview node has been created.
	 * ObjectID preview_id;
	 * if (preview_id.is_null()) { return; } // Skip lookup until a preview is assigned.
	 * ```
	 */
	_FORCE_INLINE_ ObjectID() {}
	/**
	 * Creates an identifier from a native unsigned instance ID.
	 *
	 * **Used for** saving an object's instance ID for work queued for a later update.
	 *
	 * - `p_id` — Native unsigned ID, such as one returned by `godot::Object::get_instance_id()`.
	 *
	 * ```cpp
	 * // In a Node-derived class scheduling work on itself for the next event cycle.
	 * ObjectID receiver(get_instance_id()); // Store this ID with the deferred work.
	 * ```
	 */
	_FORCE_INLINE_ explicit ObjectID(const uint64_t p_id) { id = p_id; }
	/**
	 * Creates an identifier from the signed integer form used by Variant.
	 *
	 * **Used for** recovering a target ID from a Variant-backed event before looking up the object.
	 *
	 * - `p_id` — Signed integer form of the ID. The value is converted to unsigned storage.
	 *
	 * ```cpp
	 * // When unpacking the Variant integer from a deferred event.
	 * ObjectID receiver(static_cast<int64_t>(event["target_id"]));
	 * Object *target = ObjectDB::get_instance(receiver);
	 * ```
	 */
	_FORCE_INLINE_ explicit ObjectID(const int64_t p_id) { id = p_id; }
};

} // namespace godot
