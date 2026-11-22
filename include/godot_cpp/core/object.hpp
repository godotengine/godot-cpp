/**************************************************************************/
/*  object.hpp                                                            */
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

#include <godot_cpp/core/object_id.hpp>

#include <godot_cpp/core/property_info.hpp>

#include <godot_cpp/variant/variant.hpp>

#include <godot_cpp/templates/local_vector.hpp>

#include <godot_cpp/classes/object.hpp>

#include <godot_cpp/godot.hpp>

#include <gdextension_interface.h>

/**
 * Registers a signal on the current extension class by using its static class name and the supplied signal descriptor.
 *
 * ```cpp
 * // In TilePreview::_bind_methods(), register the signal emitted after a redraw.
 * ADD_SIGNAL(MethodInfo("tile_redrawn", PropertyInfo(Variant::INT, "tile_id")));
 * ```
 */
#define ADD_SIGNAL(m_signal) ::godot::ClassDB::add_signal(get_class_static(), m_signal)
/**
 * Registers an Inspector group for properties whose names begin with the supplied prefix.
 *
 * ```cpp
 * // In TilePreview::_bind_methods(), before registering preview_opacity.
 * ADD_GROUP("Preview", "preview_");
 * ```
 */
#define ADD_GROUP(m_name, m_prefix) ::godot::ClassDB::add_property_group(get_class_static(), m_name, m_prefix)
/**
 * Registers an Inspector subgroup for properties whose names begin with the supplied prefix.
 *
 * ```cpp
 * // In TilePreview::_bind_methods(), within the Preview group.
 * ADD_SUBGROUP("Outline", "preview_outline_");
 * ```
 */
#define ADD_SUBGROUP(m_name, m_prefix) ::godot::ClassDB::add_property_subgroup(get_class_static(), m_name, m_prefix)
/**
 * Registers a property and its accessor names on the current extension class.
 *
 * ```cpp
 * // In TilePreview::_bind_methods(), after binding both accessors.
 * ADD_PROPERTY(PropertyInfo(Variant::INT, "active_tile"), "set_active_tile", "get_active_tile");
 * ```
 */
#define ADD_PROPERTY(m_property, m_setter, m_getter) ::godot::ClassDB::add_property(get_class_static(), m_property, m_setter, m_getter)
/**
 * Registers a property that passes a fixed index to its bound accessor methods.
 *
 * ```cpp
 * // In TilePreview::_bind_methods(), bind the first slot of shared indexed accessors.
 * ADD_PROPERTYI(PropertyInfo(Variant::INT, "tile_slot_0"), "set_tile_slot", "get_tile_slot", 0);
 * ```
 */
#define ADD_PROPERTYI(m_property, m_setter, m_getter, m_index) ::godot::ClassDB::add_property(get_class_static(), m_property, m_setter, m_getter, m_index)

namespace godot {

namespace internal {

/**
 * Gets the extension's C++ wrapper for a native engine object. Uses an existing wrapper or asks Godot to create one with the registered class callbacks. Returns null for a null engine pointer.
 *
 * ```cpp
 * // In ObjectDB::get_instance(), after looking up the native pointer.
 * return internal::get_object_instance_binding(obj);
 * ```
 */
Object *get_object_instance_binding(GodotObject *);

} // namespace internal

/**
 * Describes a method or signal for registration and introspection. It stores the name, parameter and return metadata, default arguments, and method flags.
 *
 * ```cpp
 * // In AtlasPreview::_bind_methods(), describe the argument of a signal.
 * ADD_SIGNAL(MethodInfo("frame_changed", PropertyInfo(Variant::INT, "frame_index")));
 * ```
 */
struct MethodInfo {
	/**
	 * Stores the name exposed by the method or signal descriptor.
	 *
	 * ```cpp
	 * // While inspecting a descriptor from Object::get_method_list().
	 * if (info.name == StringName("set_frame")) { print_line(info.arguments.size()); }
	 * ```
	 */
	StringName name;
	/**
	 * Describes the type and property metadata of the method's result.
	 *
	 * ```cpp
	 * // When describing an extension virtual method that returns a frame index.
	 * method.return_val.type = Variant::INT;
	 * ```
	 */
	PropertyInfo return_val;
	/**
	 * Holds the GDExtension method flags, such as const, static, or virtual.
	 *
	 * ```cpp
	 * // When inspecting a method descriptor before invoking it on an instance.
	 * bool is_static = (method.flags & GDEXTENSION_METHOD_FLAG_STATIC) != 0;
	 * ```
	 */
	uint32_t flags;
	/**
	 * Stores the method ID used alongside the name for comparison. Defaults to zero when no ID is supplied.
	 *
	 * ```cpp
	 * // In diagnostics that index reflected methods within one class.
	 * method_index[info.id] = info.name;
	 * ```
	 */
	int id = 0;
	/**
	 * Stores parameter metadata in call order.
	 *
	 * ```cpp
	 * // When registering a virtual method that receives an atlas frame index.
	 * method.arguments.push_back(PropertyInfo(Variant::INT, "frame_index"));
	 * ```
	 */
	LocalVector<PropertyInfo> arguments;
	/**
	 * Stores default values in argument order for parameters with defaults.
	 *
	 * ```cpp
	 * // When building a descriptor for preview_frame(frame, scale = 1.0).
	 * method.default_arguments.push_back(1.0);
	 * ```
	 */
	LocalVector<Variant> default_arguments;
	/**
	 * Stores ABI metadata that refines the declared Variant return type, such as the width of an integer result.
	 *
	 * ```cpp
	 * // When declaring a virtual returning an int32_t frame index.
	 * method.return_val_metadata = GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_INT32;
	 * ```
	 */
	GDExtensionClassMethodArgumentMetadata return_val_metadata;
	/**
	 * Stores one ABI metadata tag per parameter when the descriptor provides argument metadata.
	 *
	 * ```cpp
	 * // For the first and only parameter of a virtual accepting an int32_t frame index.
	 * method.arguments_metadata.push_back(GDEXTENSION_METHOD_ARGUMENT_METADATA_INT_IS_INT32);
	 * ```
	 */
	LocalVector<GDExtensionClassMethodArgumentMetadata> arguments_metadata;

	/**
	 * Compares method IDs and names for equality.
	 *
	 * ```cpp
	 * // In a reflected method browser, preserve the matching row after refresh.
	 * bool keep_selection = old_selection == candidate;
	 * ```
	 */
	inline bool operator==(const MethodInfo &p_method) const { return id == p_method.id && name == p_method.name; }
	/**
	 * Orders descriptors by method ID and then by name when IDs match.
	 *
	 * ```cpp
	 * // Order a LocalVector<MethodInfo> returned by the inspection code.
	 * methods.sort();
	 * ```
	 */
	inline bool operator<(const MethodInfo &p_method) const { return id == p_method.id ? (name < p_method.name) : (id < p_method.id); }

	/**
	 * Exports the descriptor as a dictionary with the method name, arguments, defaults, flags, ID, and return metadata. ABI argument metadata is omitted.
	 *
	 * ```cpp
	 * // Export a method descriptor for a diagnostics panel.
	 * Dictionary descriptor = method;
	 * method_rows.append(descriptor);
	 * ```
	 */
	operator Dictionary() const;

	/**
	 * Reads the name, arguments, defaults, flags, and return metadata from a method dictionary. The ID and ABI metadata are left at their default initialization.
	 *
	 * ```cpp
	 * // Inspect a descriptor obtained from Object::get_method_list().
	 * MethodInfo method = MethodInfo::from_dict(row);
	 * print_line(method.name);
	 * ```
	 */
	static MethodInfo from_dict(const Dictionary &p_dict);

	/**
	 * Creates an unnamed descriptor with normal method flags and no arguments.
	 *
	 * ```cpp
	 * // Assemble a virtual-method descriptor when the method name is supplied at runtime.
	 * MethodInfo method;
	 * method.name = virtual_name;
	 * method.return_val.type = Variant::BOOL;
	 * ```
	 */
	MethodInfo();
	/**
	 * Creates a named descriptor with normal flags and no argument or return type metadata.
	 *
	 * ```cpp
	 * // Inside _bind_methods(), register a signal with no arguments.
	 * ADD_SIGNAL(MethodInfo("atlas_loaded"));
	 * ```
	 */
	MethodInfo(StringName p_name);
	/**
	 * Creates named metadata with the supplied argument descriptors in call order.
	 *
	 * - `Args` — Types used to build the `PropertyInfo` items.
	 *
	 * ```cpp
	 * // Inside _bind_methods(), register the tile ID and texture page of a redraw.
	 * ADD_SIGNAL(MethodInfo("tile_redrawn", PropertyInfo(Variant::INT, "tile_id"), PropertyInfo(Variant::INT, "page")));
	 * ```
	 */
	template <typename... Args>
	MethodInfo(StringName p_name, const Args &...args);
	/**
	 * Creates unnamed method metadata with a specified Variant return type.
	 *
	 * ```cpp
	 * // Prepare return metadata for a generated accessor, then assign its computed name.
	 * MethodInfo getter(Variant::INT);
	 * getter.name = generated_name;
	 * ```
	 */
	MethodInfo(Variant::Type ret);
	/**
	 * Creates a named descriptor with a return type and no arguments.
	 *
	 * ```cpp
	 * // Describe a virtual query returning the number of atlas frames.
	 * MethodInfo frame_count(Variant::INT, "_get_frame_count");
	 * ```
	 */
	MethodInfo(Variant::Type ret, StringName p_name);
	/**
	 * Creates named metadata with the given Variant return type and the supplied parameter descriptors.
	 *
	 * ```cpp
	 * // Describe a virtual query taking a frame index and returning its pixel bounds.
	 * MethodInfo query(Variant::RECT2I, "_get_frame_bounds", PropertyInfo(Variant::INT, "frame_index"));
	 * ```
	 */
	template <typename... Args>
	MethodInfo(Variant::Type ret, StringName p_name, const Args &...args);
	/**
	 * Creates a named descriptor and copies the supplied complete return metadata.
	 *
	 * ```cpp
	 * // Describe a virtual getter whose result is a Texture2D resource.
	 * MethodInfo getter(PropertyInfo(Variant::OBJECT, "", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "_get_atlas");
	 * ```
	 */
	MethodInfo(const PropertyInfo &p_ret, StringName p_name);
	/**
	 * Creates a named descriptor with complete return metadata and parameter descriptors in call order.
	 *
	 * ```cpp
	 * // Describe a virtual getter returning a Texture2D for the requested slot.
	 * MethodInfo getter(PropertyInfo(Variant::OBJECT, "", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"),
	 *         "_get_tile_texture", PropertyInfo(Variant::INT, "slot"));
	 * ```
	 */
	template <typename... Args>
	MethodInfo(const PropertyInfo &p_ret, StringName p_name, const Args &...);
};

template <typename... Args>
MethodInfo::MethodInfo(StringName p_name, const Args &...args) :
		name(p_name), flags(GDEXTENSION_METHOD_FLAG_NORMAL), arguments({ args... }) {}

template <typename... Args>
MethodInfo::MethodInfo(Variant::Type ret, StringName p_name, const Args &...args) :
		name(p_name), flags(GDEXTENSION_METHOD_FLAG_NORMAL), arguments({ args... }) {
	return_val.type = ret;
}

template <typename... Args>
MethodInfo::MethodInfo(const PropertyInfo &p_ret, StringName p_name, const Args &...args) :
		name(p_name), return_val(p_ret), flags(GDEXTENSION_METHOD_FLAG_NORMAL), arguments({ args... }) {
}

/**
 * Looks up live Godot objects by instance ID and returns their C++ wrappers. Holding an ID does not keep an object alive.
 *
 * ```cpp
 * // In a deferred thumbnail update, recover the node selected on the previous frame.
 * if (Object *selected = ObjectDB::get_instance(selected_id)) { selected->call("refresh_thumbnail"); }
 * ```
 */
class ObjectDB {
public:
	/**
	 * Returns the wrapper for a live object, or null if the engine cannot find the ID. The result does not own the object.
	 *
	 * ```cpp
	 * // Resolve a saved ID after a tree update. The node might have been freed.
	 * Node *node = Object::cast_to<Node>(ObjectDB::get_instance(saved_id));
	 * if (node) { node->queue_free(); }
	 * ```
	 */
	static Object *get_instance(uint64_t p_object_id) {
		GDExtensionObjectPtr obj = ::godot::gdextension_interface::object_get_instance_from_id(p_object_id);
		if (obj == nullptr) {
			return nullptr;
		}
		return ::godot::internal::get_object_instance_binding(obj);
	}
};

/**
 * Returns a mutable `T` pointer if the object belongs to that Godot class or a derived class. Returns null for a null or incompatible object.
 *
 * ```cpp
 * // In a tool that can move any selected Node2D in local coordinates.
 * if (auto *node = Object::cast_to<Node2D>(selection)) { node->set_position(cursor_in_parent); }
 * ```
 */
template <typename T>
T *Object::cast_to(Object *p_object) {
#if GODOT_VERSION_MINOR >= 7
	return p_object && p_object->is_class(T::get_class_static()) ? static_cast<T *>(p_object) : nullptr;
#else
	return p_object ? dynamic_cast<T *>(p_object) : nullptr;
#endif
}

/**
 * Checks whether a read-only object can be viewed as `T` and preserves const access. A null or incompatible object yields null.
 *
 * ```cpp
 * // In an Inspector summary that receives a const Object pointer.
 * if (const auto *node = Object::cast_to<Node2D>(selection)) { print_line(node->get_position()); }
 * ```
 */
template <typename T>
const T *Object::cast_to(const Object *p_object) {
#if GODOT_VERSION_MINOR >= 7
	return p_object && p_object->is_class(T::get_class_static()) ? static_cast<const T *>(p_object) : nullptr;
#else
	return p_object ? dynamic_cast<const T *>(p_object) : nullptr;
#endif
}

} // namespace godot
