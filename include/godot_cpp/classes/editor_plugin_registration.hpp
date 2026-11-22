/**************************************************************************/
/*  editor_plugin_registration.hpp                                        */
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

#include <godot_cpp/templates/vector.hpp>

namespace godot {

class EditorPlugin;
class StringName;

/**
 * Tracks GDExtension editor plugin classes added to Godot. It removes any remaining plugin classes when the editor initialization level shuts down.
 *
 * **Used for** activating registered extension plugins at editor startup and removing their editor instances at shutdown.
 *
 * ```cpp
 * // In the editor-level initializer. AtlasInspectorPlugin derives from EditorPlugin.
 * GDREGISTER_CLASS(AtlasInspectorPlugin);
 * EditorPlugins::add_by_type<AtlasInspectorPlugin>();
 * ```
 */
class EditorPlugins {
private:
	/**
	 * Stores registered plugin class names for duplicate checks and editor shutdown cleanup.
	 *
	 * ```cpp
	 * // In EditorPlugins::remove_plugin_class().
	 * int index = plugin_classes.find(p_class_name);
	 * ```
	 */
	static Vector<StringName> plugin_classes;

public:
	/**
	 * Records a registered editor plugin class and asks Godot to add it to the editor. A duplicate name reports an error.
	 *
	 * **Used for** activating an editor plugin when the caller has its registered name as a value.
	 *
	 * - `p_class_name` — Registered name of the class derived from `godot::EditorPlugin` to add.
	 *
	 * ```cpp
	 * // In the editor-level initializer, after registering the AtlasInspectorPlugin class.
	 * const StringName plugin_name = AtlasInspectorPlugin::get_class_static();
	 * EditorPlugins::add_plugin_class(plugin_name); // Godot can now add the plugin to the editor.
	 * ```
	 */
	static void add_plugin_class(const StringName &p_class_name);
	/**
	 * Removes a tracked plugin class from Godot's editor and from the tracked names. An untracked name reports an error.
	 *
	 * **Used for** removing a plugin by name before deinitializing its class.
	 *
	 * - `p_class_name` — Name previously added through `godot::EditorPlugins`.
	 *
	 * ```cpp
	 * // In the editor-level terminator, before ClassDB deinitializes the class.
	 * const StringName plugin_name = AtlasInspectorPlugin::get_class_static();
	 * EditorPlugins::remove_plugin_class(plugin_name); // Plugin was added in the initializer.
	 * ```
	 */
	static void remove_plugin_class(const StringName &p_class_name);
	/**
	 * At the editor initialization level, removes all tracked plugin classes and clears the list. Other levels leave the list intact.
	 *
	 * **Used for** cleaning up tracked plugins in the binding's level-specific deinitialization callback.
	 *
	 * - `p_level` — Level being deinitialized. Cleanup runs at `GDEXTENSION_INITIALIZATION_EDITOR`.
	 *
	 * ```cpp
	 * // In the binding's shutdown callback, for the level supplied by Godot.
	 * EditorPlugins::deinitialize(p_level);
	 * ```
	 */
	static void deinitialize(GDExtensionInitializationLevel p_level);

	/**
	 * Adds an editor plugin using the registered class name of the C++ type.
	 *
	 * **Used for** activating a known C++ plugin type during editor initialization.
	 *
	 * - `T` — Registered GDExtension class derived from `godot::EditorPlugin`.
	 *
	 * ```cpp
	 * // In a module initializer, with AtlasInspectorPlugin derived from EditorPlugin.
	 * if (p_level != MODULE_INITIALIZATION_LEVEL_EDITOR) { return; }
	 * GDREGISTER_CLASS(AtlasInspectorPlugin);
	 * EditorPlugins::add_by_type<AtlasInspectorPlugin>();
	 * ```
	 */
	template <typename T>
	static void add_by_type() {
		add_plugin_class(T::get_class_static());
	}
	/**
	 * Removes the editor plugin tracked under the C++ type's registered class name.
	 *
	 * **Used for** pairing an editor initializer's plugin registration with cleanup of the same C++ type.
	 *
	 * - `T` — Plugin class previously added through `godot::EditorPlugins`.
	 *
	 * ```cpp
	 * // In a paired module terminator, with AtlasInspectorPlugin added on editor startup.
	 * if (p_level != MODULE_INITIALIZATION_LEVEL_EDITOR) { return; }
	 * EditorPlugins::remove_by_type<AtlasInspectorPlugin>();
	 * ```
	 */
	template <typename T>
	static void remove_by_type() {
		remove_plugin_class(T::get_class_static());
	}
};

} // namespace godot
