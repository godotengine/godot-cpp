/**************************************************************************/
/*  property_info.hpp                                                     */
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

#include <godot_cpp/classes/global_constants.hpp>

#include <godot_cpp/variant/variant.hpp>

#include <godot_cpp/godot.hpp>

#include <gdextension_interface.h>

namespace godot {

/**
 * Describes a Godot property for registration or introspection. It records the value type, name, and metadata that the editor and serializer use.
 *
 * ```cpp
 * // In a Node subclass's _bind_methods(), with both accessors already bound.
 * ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "opacity", PROPERTY_HINT_RANGE, "0,1,0.01"),
 *         "set_opacity", "get_opacity");
 * ```
 */
struct PropertyInfo {
	/**
	 * Identifies the Godot Variant type declared for the property.
	 *
	 * ```cpp
	 * // In _get_property_list(), identify the Variant type returned by _get().
	 * PropertyInfo prop;
	 * prop.name = "frame_index";
	 * prop.type = Variant::INT;
	 * p_list->push_back(prop);
	 * ```
	 */
	Variant::Type type = Variant::NIL;
	/**
	 * Holds the name Godot uses to identify the property.
	 *
	 * ```cpp
	 * // In _validate_property(PropertyInfo &property) const.
	 * if (property.name == StringName("preview_opacity")) {
	 *     property.usage |= PROPERTY_USAGE_READ_ONLY;
	 * }
	 * ```
	 */
	StringName name;
	/**
	 * Holds class or type information for the declared property. For `PROPERTY_HINT_RESOURCE_TYPE`, construction fills it from the hint string.
	 *
	 * ```cpp
	 * // In _get_property_list(), expose an object slot for Texture2D resources.
	 * PropertyInfo texture(Variant::OBJECT, "preview_texture");
	 * texture.class_name = "Texture2D";
	 * p_list->push_back(texture);
	 * ```
	 */
	StringName class_name;
	/**
	 * Identifies how to interpret the hint string and how the editor presents the property.
	 *
	 * ```cpp
	 * // In _validate_property(PropertyInfo &property) const, for the preview opacity.
	 * property.hint = PROPERTY_HINT_RANGE;
	 * property.hint_string = "0,1,0.01";
	 * ```
	 */
	uint32_t hint = PROPERTY_HINT_NONE;
	/**
	 * Holds text interpreted according to `hint`, such as a range's minimum, maximum, and step.
	 *
	 * ```cpp
	 * // In an editor property validation hook, with frame_count read from the atlas.
	 * property.hint = PROPERTY_HINT_RANGE;
	 * property.hint_string = "0," + itos(frame_count - 1) + ",1"; // frame_count > 0.
	 * ```
	 */
	String hint_string;
	/**
	 * Stores the flags that control how Godot handles the property. The default enables storage and editor display.
	 *
	 * ```cpp
	 * // In _validate_property(PropertyInfo &property) const.
	 * if (property.name == StringName("import_status")) { property.usage = PROPERTY_USAGE_EDITOR | PROPERTY_USAGE_READ_ONLY; }
	 * ```
	 */
	uint32_t usage = PROPERTY_USAGE_DEFAULT;

	/**
	 * Creates unnamed metadata with Variant type `NIL`, no hint, and the default usage flags.
	 *
	 * ```cpp
	 * // When building an Inspector property list for a generated frame name.
	 * PropertyInfo prop;
	 * prop.type = Variant::INT;
	 * prop.name = "active_frame";
	 * p_list->push_back(prop);
	 * ```
	 */
	PropertyInfo() = default;

	/**
	 * Creates metadata from a C++ Variant type and property details. A resource type hint supplies the class name from its hint string.
	 *
	 * ```cpp
	 * // In _bind_methods(), after binding the preview texture accessors.
	 * ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "preview_texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"),
	 *         "set_preview_texture", "get_preview_texture");
	 * ```
	 */
	PropertyInfo(Variant::Type p_type, const StringName &p_name, PropertyHint p_hint = PROPERTY_HINT_NONE, const String &p_hint_string = "", uint32_t p_usage = PROPERTY_USAGE_DEFAULT, const StringName &p_class_name = "") :
			type(p_type),
			name(p_name),
			hint(p_hint),
			hint_string(p_hint_string),
			usage(p_usage) {
		if (hint == PROPERTY_HINT_RESOURCE_TYPE) {
			class_name = hint_string;
		} else {
			class_name = p_class_name;
		}
	}

	/**
	 * Converts a GDExtension ABI type tag to the C++ Variant type and uses it to construct the property metadata.
	 *
	 * ```cpp
	 * // In a native metadata adapter that exposes the selected frame index.
	 * const GDExtensionVariantType abi_type = GDEXTENSION_VARIANT_TYPE_INT;
	 * PropertyInfo index(abi_type, "active_frame");
	 * Dictionary inspector_metadata = index;
	 * ```
	 */
	PropertyInfo(GDExtensionVariantType p_type, const StringName &p_name, PropertyHint p_hint = PROPERTY_HINT_NONE, const String &p_hint_string = "", uint32_t p_usage = PROPERTY_USAGE_DEFAULT, const StringName &p_class_name = "") :
			PropertyInfo((Variant::Type)p_type, p_name, p_hint, p_hint_string, p_usage, p_class_name) {}

	/**
	 * Copies property metadata from a GDExtension ABI record using the regular constructor's resource hint handling.
	 *
	 * - `p_info` — A live record with valid pointers to its name, class name, and hint string.
	 *
	 * ```cpp
	 * // In the GDCLASS callback for validating a property, p_property comes from Godot.
	 * PropertyInfo info(p_property);
	 * if (info.name == StringName("import_status")) { info.usage |= PROPERTY_USAGE_READ_ONLY; }
	 * info._update(p_property);
	 * ```
	 */
	PropertyInfo(const GDExtensionPropertyInfo *p_info) :
			PropertyInfo(p_info->type, *reinterpret_cast<StringName *>(p_info->name), (PropertyHint)p_info->hint, *reinterpret_cast<String *>(p_info->hint_string), p_info->usage, *reinterpret_cast<StringName *>(p_info->class_name)) {}

	/**
	 * Exports the property metadata by field name. Omits the `usage` key when its value is `PROPERTY_USAGE_NONE`.
	 *
	 * ```cpp
	 * PropertyInfo frame(Variant::INT, "active_frame", PROPERTY_HINT_RANGE, "0,11,1");
	 * Dictionary metadata = frame;
	 * Array schema;
	 * schema.append(metadata); // Collect property descriptors for a diagnostics panel.
	 * ```
	 */
	operator Dictionary() const {
		Dictionary dict;
		dict["name"] = name;
		dict["class_name"] = class_name;
		dict["type"] = type;
		dict["hint"] = hint;
		dict["hint_string"] = hint_string;
		if (usage != PROPERTY_USAGE_NONE) {
			dict["usage"] = usage;
		}
		return dict;
	}

	/**
	 * Reads property metadata from named dictionary entries. Fields absent from the dictionary keep their default values.
	 *
	 * ```cpp
	 * // In a diagnostics tool, with metadata supplied by Object::get_property_list().
	 * PropertyInfo info = PropertyInfo::from_dict(metadata);
	 * if (info.usage & PROPERTY_USAGE_STORAGE) { print_line(info.name); }
	 * ```
	 */
	static PropertyInfo from_dict(const Dictionary &p_dict) {
		PropertyInfo pi;
		if (p_dict.has("type")) {
			pi.type = Variant::Type(int(p_dict["type"]));
		}
		if (p_dict.has("name")) {
			pi.name = p_dict["name"];
		}
		if (p_dict.has("class_name")) {
			pi.class_name = p_dict["class_name"];
		}
		if (p_dict.has("hint")) {
			pi.hint = PropertyHint(int(p_dict["hint"]));
		}
		if (p_dict.has("hint_string")) {
			pi.hint_string = p_dict["hint_string"];
		}
		if (p_dict.has("usage")) {
			pi.usage = p_dict["usage"];
		}
		return pi;
	}

	/**
	 * Writes the metadata into an existing GDExtension ABI record, including the strings stored at its existing pointers.
	 *
	 * - `p_info` — A record whose string pointers refer to writable instances of the corresponding Godot types.
	 *
	 * ```cpp
	 * // In the GDCLASS property validation callback, after the class changes info.
	 * info._update(p_property);
	 * ```
	 */
	void _update(GDExtensionPropertyInfo *p_info) {
		p_info->type = (GDExtensionVariantType)type;
		*(reinterpret_cast<StringName *>(p_info->name)) = name;
		p_info->hint = hint;
		*(reinterpret_cast<String *>(p_info->hint_string)) = hint_string;
		p_info->usage = usage;
		*(reinterpret_cast<StringName *>(p_info->class_name)) = class_name;
	}

	/**
	 * Builds a GDExtension ABI record that borrows pointers to this object's strings. Keep this metadata alive while the native record is in use.
	 *
	 * ```cpp
	 * // When building a native virtual method registration from a MethodInfo.
	 * mi.return_value = p_method.return_val._to_gdextension();
	 * ```
	 */
	GDExtensionPropertyInfo _to_gdextension() const {
		return {
			(GDExtensionVariantType)type,
			name._native_ptr(),
			class_name._native_ptr(),
			hint,
			hint_string._native_ptr(),
			usage,
		};
	}
};

} // namespace godot
