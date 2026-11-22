/**************************************************************************/
/*  class_db.hpp                                                          */
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

#include <gdextension_interface.h>

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/core/method_bind.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/print_string.hpp>

#include <godot_cpp/classes/class_db_singleton.hpp>

// Makes callable_mp readily available in all classes connecting signals.
// Needs to come after method_bind and object have been included.
#include <godot_cpp/variant/callable_method_pointer.hpp>

#include <godot_cpp/templates/a_hash_map.hpp>
#include <godot_cpp/templates/hash_set.hpp>
#include <godot_cpp/templates/list.hpp>
#include <mutex>

namespace godot {

/**
 * Wraps a default value expression for a method binding so it can be passed as a trailing argument.
 *
 * **Used for** making trailing arguments optional when registering a bound method.
 *
 * - `m_defval` — Default value expression supplied for a trailing C++ parameter.
 */
#define DEFVAL(m_defval) (m_defval)

/**
 * Holds the exposed name of a bound method and its argument names in declaration order.
 */
struct MethodDefinition {
	/**
	 * The name exposed to Godot for this binding.
	 */
	StringName name;
	/**
	 * Names of the declared parameters in argument order.
	 */
	List<StringName> args;
	/**
	 * Creates an empty binding description.
	 */
	MethodDefinition() {}
	/**
	 * Records a method name with no argument names.
	 *
	 * - `p_name` — Name used to expose the method to Godot.
	 */
	MethodDefinition(StringName p_name) :
			name(p_name) {}
};

/**
 * Describes a method by name without naming any parameters.
 *
 * - `p_name` — Name used to expose the method to Godot.
 */
MethodDefinition D_METHOD(StringName p_name);
/**
 * Describes a method and names its first parameter.
 *
 * - `p_name` — Name used to expose the method to Godot.
 * - `p_arg1` — Name of the first method parameter.
 */
MethodDefinition D_METHOD(StringName p_name, StringName p_arg1);
/**
 * Builds a method description from a name and a list of parameter names in order.
 *
 * - `Args` — Types of additional names convertible to interned strings.
 * - `p_name` — Name used to expose the method to Godot.
 * - `p_arg1` — Name of the first method parameter.
 * - `args` — Remaining parameter names in method argument order.
 */
template <typename... Args>
MethodDefinition D_METHOD(StringName p_name, StringName p_arg1, Args... args) {
	MethodDefinition md = D_METHOD(p_name, args...);
	md.args.push_front(p_arg1);
	return md;
}

/**
 * Registers extension classes and their members with Godot. Tracks the bindings used for dispatch and class shutdown.
 */
class ClassDB {
	/**
	 * Records the engine initialization level assigned to newly registered extension classes.
	 */
	static GDExtensionInitializationLevel current_level;

	/**
	 * Gives the binding lifecycle access to the active registration level and private registration state.
	 */
	friend class ::godot::GDExtensionBinding;

public:
	/**
	 * Stores registration data for one custom extension class.
	 */
	struct ClassInfo {
		/**
		 * Pairs a registered virtual dispatch function with its engine signature hash.
		 */
		struct VirtualMethod {
			/**
			 * Callback invoked by the engine for the virtual method.
			 */
			GDExtensionClassCallVirtual func;
			/**
			 * Signature hash the engine supplies when looking up a virtual call.
			 */
			uint32_t hash;
		};

		/**
		 * Registered name of the extension class.
		 */
		StringName name;
		/**
		 * Registered name of the immediate base class.
		 */
		StringName parent_name;
		/**
		 * Initialization level that owns the class registration.
		 */
		GDExtensionInitializationLevel level = GDEXTENSION_INITIALIZATION_SCENE;
		/**
		 * Owns the bindings for methods declared by this class.
		 */
		AHashMap<StringName, MethodBind *> method_map;
		/**
		 * Tracks the signal names registered directly on this class.
		 */
		HashSet<StringName> signal_names;
		/**
		 * Indexes this class's virtual callbacks by method name.
		 */
		AHashMap<StringName, VirtualMethod> virtual_methods;
		/**
		 * Tracks the property names registered directly on this class.
		 */
		HashSet<StringName> property_names;
		/**
		 * Tracks the integer constants registered directly on this class.
		 */
		HashSet<StringName> constant_names;
		// Pointer to the parent custom class, if any. Will be null if the parent class is a Godot class.
		/**
		 * Links to the registered extension base class, or is null when the base is an engine class.
		 */
		ClassInfo *parent_ptr = nullptr;
	};

private:
	// This may only contain custom classes, not Godot classes
	/**
	 * Stores metadata for custom extension classes by registered name.
	 */
	static HashMap<StringName, ClassInfo> classes;
	/**
	 * Maps engine and extension class names to C++ instance binding callbacks.
	 */
	static AHashMap<StringName, const GDExtensionInstanceBindingCallbacks *> instance_binding_callbacks;
	// Used to remember the custom class registration order.
	/**
	 * Records custom classes in registration order so shutdown can unregister them in reverse.
	 */
	static LocalVector<StringName> class_register_order;
	/**
	 * Maps engine singleton class names to their C++ object wrappers.
	 */
	static AHashMap<StringName, Object *> engine_singletons;
	/**
	 * Serializes access to the singleton wrapper map.
	 */
	static std::mutex engine_singletons_mutex;

	/**
	 * Validates the class and method name, applies argument metadata and defaults, and registers the binding. Frees rejected bindings and returns null on failure.
	 *
	 * - `p_flags` — Flags recorded for the method.
	 * - `p_bind` — New binding. The registry keeps it on success and deletes it on failure.
	 * - `method_name` — Exposed method name and the names of its arguments.
	 * - `p_defs` — Pointers to default variants for the final arguments, in order.
	 * - `p_defcount` — Number of default variant pointers.
	 */
	static MethodBind *bind_methodfi(uint32_t p_flags, MethodBind *p_bind, const MethodDefinition &method_name, const void **p_defs, int p_defcount);
	/**
	 * Runs the per-class initialization hook after class and member registration. The current implementation has no actions.
	 *
	 * - `cl` — Class record supplied by the registry. The current hook does not use it.
	 */
	static void initialize_class(const ClassInfo &cl);
	/**
	 * Marshals the bound method's call handlers and metadata to Godot's class registration interface.
	 *
	 * - `p_class_name` — Name of the registered extension class that receives the method.
	 * - `p_method` — Binding whose call entry points, flags, arguments, and defaults to register.
	 */
	static void bind_method_godot(const StringName &p_class_name, MethodBind *p_method);

	/**
	 * Registers a class and its lifecycle callbacks with the engine, then invokes the class's member binding.
	 *
	 * - `is_abstract` — Indicates that the engine must treat the class as abstract.
	 *
	 * - `T` — C++ extension class being registered.
	 * - `p_virtual` — Virtual-class flag passed to the engine.
	 * - `p_exposed` — Whether the registered class is exposed to the engine.
	 * - `p_runtime` — Runtime-class flag passed to the engine.
	 */
	template <typename T, bool is_abstract>
	static void _register_class(bool p_virtual = false, bool p_exposed = true, bool p_runtime = false);

	/**
	 * Constructs an engine-owned extension instance and returns its engine object pointer. Abstract C++ classes yield null. Godot 4.4 and later can request the post-initialization notification.
	 *
	 * - `T` — Extension class to create.
	 * - `data` — Userdata supplied by the engine. Instance creation does not use it.
	 * - `p_notify_postinitialize` — On supported Godot versions, whether to send the post-initialization notification.
	 */
	template <typename T>
#if GODOT_VERSION_MINOR >= 4
	static GDExtensionObjectPtr _create_instance_func(void *data, GDExtensionBool p_notify_postinitialize) {
#else
	static GDExtensionObjectPtr _create_instance_func(void *data) {
#endif // GODOT_VERSION_MINOR >= 4
		if constexpr (!std::is_abstract_v<T>) {
			Wrapped::_set_construct_info<T>();
#if GODOT_VERSION_MINOR >= 4
			T *new_object = new (::godot::DefaultAllocator{}) T;
			if (p_notify_postinitialize) {
				new_object->_postinitialize();
			}
#else
			T *new_object = memnew(T);
#endif // GODOT_VERSION_MINOR >= 4
			return new_object->_owner;
		} else {
			return nullptr;
		}
	}

	/**
	 * Constructs a new extension wrapper around an existing engine object during hot reload. Returns null for abstract types or when hot reload is disabled.
	 *
	 * - `T` — Extension class whose wrapper is rebuilt.
	 * - `data` — Class userdata supplied by the engine. This callback does not use it.
	 * - `obj` — Existing engine object to keep while replacing the C++ wrapper.
	 */
	template <typename T>
	static GDExtensionClassInstancePtr _recreate_instance_func(void *data, GDExtensionObjectPtr obj) {
		if constexpr (!std::is_abstract_v<T>) {
#ifdef HOT_RELOAD_ENABLED
			Wrapped::_get_construct_info().recreate_owner = obj;
			T *new_instance = (T *)memalloc(sizeof(T));
			memnew_placement(new_instance, T);
			return new_instance;
#else
			return nullptr;
#endif
		} else {
			return nullptr;
		}
	}

public:
	/**
	 * Registers a concrete extension class. The virtual flag is passed to the engine's class registration.
	 *
	 * - `T` — C++ extension class being registered.
	 * - `p_virtual` — Whether to mark the class virtual in Godot's registry.
	 */
	template <typename T>
	static void register_class(bool p_virtual = false);
	/**
	 * Registers an extension class as abstract.
	 *
	 * - `T` — C++ extension class being registered.
	 */
	template <typename T>
	static void register_abstract_class();
	/**
	 * Registers an extension class with engine exposure disabled.
	 *
	 * - `T` — C++ extension class being registered.
	 */
	template <typename T>
	static void register_internal_class();
	/**
	 * Registers an exposed extension class with the runtime-class flag.
	 *
	 * - `T` — C++ extension class being registered.
	 */
	template <typename T>
	static void register_runtime_class();

	/**
	 * Associates a generated engine class name with its instance binding callbacks.
	 *
	 * - `p_name` — Registered engine class name.
	 * - `p_callbacks` — Callback table to keep for instance binding. It must outlive the registration.
	 */
	_FORCE_INLINE_ static void _register_engine_class(const StringName &p_name, const GDExtensionInstanceBindingCallbacks *p_callbacks) {
		instance_binding_callbacks[p_name] = p_callbacks;
	}

	/**
	 * Replaces the editor's output array with the names for which instance binding callbacks are known.
	 *
	 * - `p_packed_string_array` — Writable packed string array supplied by the editor. Receives the class names.
	 */
	static void _editor_get_classes_used_callback(GDExtensionTypePtr p_packed_string_array);

	/**
	 * Caches a singleton wrapper under a class name. Reports an error if that name already refers to a different wrapper.
	 *
	 * - `p_class_name` — Registered engine class name used to index the entry.
	 * - `p_singleton` — Engine-owned singleton's C++ wrapper. The cache does not own it.
	 */
	static void _register_engine_singleton(const StringName &p_class_name, Object *p_singleton) {
		std::lock_guard<std::mutex> lock(engine_singletons_mutex);
		AHashMap<StringName, Object *>::ConstIterator i = engine_singletons.find(p_class_name);
		if (i != engine_singletons.end()) {
			ERR_FAIL_COND((*i).value != p_singleton);
			return;
		}
		engine_singletons[p_class_name] = p_singleton;
	}

	/**
	 * Removes the named singleton wrapper from the cache under the singleton mutex.
	 *
	 * - `p_class_name` — Registered engine class name used to index the entry.
	 */
	static void _unregister_engine_singleton(const StringName &p_class_name) {
		std::lock_guard<std::mutex> lock(engine_singletons_mutex);
		engine_singletons.erase(p_class_name);
	}

	/**
	 * Registers a C++ instance method for Godot. The trailing values supply defaults for the final parameters. Returns the stored binding or null on registration failure.
	 *
	 * - `N` — Type of the method description.
	 * - `M` — C++ function pointer type.
	 * - `VarArgs` — Types of the supplied default values.
	 * - `p_method_name` — Exposed name and argument names.
	 * - `p_method` — C++ function pointer being bound.
	 * - `p_args` — Default values for the trailing parameters, in their parameter order.
	 */
	template <typename N, typename M, typename... VarArgs>
	static MethodBind *bind_method(N p_method_name, M p_method, VarArgs... p_args);

	/**
	 * Registers a C++ static function as a method on the named extension class, with optional trailing default arguments.
	 *
	 * - `N` — Type of the method description.
	 * - `M` — C++ function pointer type.
	 * - `VarArgs` — Types of the supplied default values.
	 * - `p_method_name` — Exposed name and argument names.
	 * - `p_method` — C++ function pointer being bound.
	 * - `p_args` — Default values for the trailing parameters, in their parameter order.
	 * - `p_class` — Name of the registered extension class that receives the declaration.
	 */
	template <typename N, typename M, typename... VarArgs>
	static MethodBind *bind_static_method(StringName p_class, N p_method_name, M p_method, VarArgs... p_args);

	/**
	 * Registers a method that receives the incoming variant array and argument count directly. Returns null if class or method registration fails.
	 *
	 * - `M` — Member function pointer type for the variadic signature.
	 * - `p_flags` — Method flags passed to the binding request. This implementation does not read them.
	 * - `p_name` — Name exposed to Godot.
	 * - `p_method` — Member function that accepts a variant pointer array, argument count, and error output.
	 * - `p_info` — Registration metadata for the declared argument prefix.
	 * - `p_default_args` — Default variants associated with the method registration.
	 * - `p_return_nil_is_variant` — Forwarded to the binding constructor. Return metadata is currently derived from the C++ return type.
	 */
	template <typename M>
	static MethodBind *bind_vararg_method(uint32_t p_flags, StringName p_name, M p_method, const MethodInfo &p_info = MethodInfo(), const LocalVector<Variant> &p_default_args = LocalVector<Variant>{}, bool p_return_nil_is_variant = true);

	/**
	 * Registers a property group with a display name and member name prefix.
	 *
	 * - `p_class` — Name of the registered extension class that receives the declaration.
	 * - `p_name` — Group name displayed by the editor.
	 * - `p_prefix` — Property name prefix used to match members of the group.
	 */
	static void add_property_group(const StringName &p_class, const String &p_name, const String &p_prefix);
	/**
	 * Registers a property subgroup with a display name and member name prefix.
	 *
	 * - `p_class` — Name of the registered extension class that receives the declaration.
	 * - `p_name` — Group name displayed by the editor.
	 * - `p_prefix` — Property name prefix used to match members of the group.
	 */
	static void add_property_subgroup(const StringName &p_class, const String &p_name, const String &p_prefix);
	/**
	 * Registers a property with named accessors. The getter is required. A nonnegative index adds an index parameter to both the getter and the optional setter.
	 *
	 * - `p_class` — Name of the registered extension class that receives the declaration.
	 * - `p_pinfo` — Property type, name, and editor metadata.
	 * - `p_setter` — Registered setter name, or an empty name for a read-only property.
	 * - `p_getter` — Required registered getter name.
	 * - `p_index` — Nonnegative index supplied to the getter and setter of an indexed property. Use a negative value for a plain property.
	 */
	static void add_property(const StringName &p_class, const PropertyInfo &p_pinfo, const StringName &p_setter, const StringName &p_getter, int p_index = -1);
	/**
	 * Registers a named signal and its argument descriptors on an extension class.
	 *
	 * - `p_class` — Name of the registered extension class that receives the declaration.
	 * - `p_signal` — Signal name and argument metadata.
	 */
	static void add_signal(const StringName &p_class, const MethodInfo &p_signal);
	/**
	 * Exposes an integer constant. An enum name associates the constant with that enum and the bitfield flag marks a flags declaration.
	 *
	 * - `p_class_name` — Registered engine class name used to index the entry.
	 * - `p_enum_name` — Enum that owns the constant, or an empty name for a standalone constant.
	 * - `p_constant_name` — Name exposed to Godot.
	 * - `p_constant_value` — Integer associated with the name.
	 * - `p_is_bitfield` — Whether the value belongs to a bitfield.
	 */
	static void bind_integer_constant(const StringName &p_class_name, const StringName &p_enum_name, const StringName &p_constant_name, GDExtensionInt p_constant_value, bool p_is_bitfield = false);
	// Binds an implementation of a virtual method defined in Godot.
	/**
	 * Registers a C++ callback implementing an engine virtual method with the matching signature hash.
	 *
	 * - `p_class` — Name of the registered extension class that receives the declaration.
	 * - `p_method` — Name of the registered method.
	 * - `p_call` — Typed callback implementing the virtual method.
	 * - `p_hash` — Engine signature hash for the virtual method.
	 */
	static void bind_virtual_method(const StringName &p_class, const StringName &p_method, GDExtensionClassCallVirtual p_call, uint32_t p_hash);
	// Add a new virtual method that can be implemented by scripts.
	/**
	 * Registers a virtual method signature that scripts can implement. A matching list of names supplies the exposed argument names.
	 *
	 * - `p_class` — Name of the registered extension class that receives the declaration.
	 * - `p_method` — Signature and flags of the virtual method exposed to scripts.
	 * - `p_arg_names` — Argument names in signature order. A count mismatch leaves the names from the supplied method information.
	 */
	static void add_virtual_method(const StringName &p_class, const MethodInfo &p_method, const Vector<StringName> &p_arg_names = Vector<StringName>());

	/**
	 * Finds a bound method on a custom class or its registered custom ancestors. Returns null if absent.
	 *
	 * - `p_class` — Name of the registered extension class that receives the declaration.
	 * - `p_method` — Name of the registered method.
	 */
	static MethodBind *get_method(const StringName &p_class, const StringName &p_method);

#if GODOT_VERSION_MINOR >= 4
	/**
	 * Looks up the virtual callback by name and signature hash along the custom class hierarchy.
	 *
	 * - `p_userdata` — Pointer to the registered class name supplied as class userdata.
	 * - `p_name` — Interned name of the virtual method.
	 * - `p_hash` — Engine signature hash used to select the matching callback.
	 */
	static GDExtensionClassCallVirtual get_virtual_func(void *p_userdata, GDExtensionConstStringNamePtr p_name, uint32_t p_hash);
#else
	/**
	 * Looks up the virtual callback by name along the custom class hierarchy for older engines.
	 *
	 * - `p_userdata` — Pointer to the registered class name supplied as class userdata.
	 * - `p_name` — Interned name of the virtual method.
	 */
	static GDExtensionClassCallVirtual get_virtual_func(void *p_userdata, GDExtensionConstStringNamePtr p_name);
#endif // GODOT_VERSION_MINOR >= 4

	/**
	 * Retrieves callbacks for the class or its nearest parent with a binding, returning null when none can be found.
	 *
	 * - `p_class` — Engine or extension class whose instance binding callback table is requested.
	 */
	static const GDExtensionInstanceBindingCallbacks *get_instance_binding_callbacks(const StringName &p_class);

	/**
	 * Visits classes registered at this initialization level. The current implementation performs no per-class initialization at this stage.
	 *
	 * - `p_level` — Engine initialization level used to select registrations.
	 */
	static void initialize(GDExtensionInitializationLevel p_level);
	/**
	 * Unregisters classes belonging to the given level in reverse registration order, and destroys their method bindings.
	 *
	 * - `p_level` — Engine initialization level used to select registrations.
	 */
	static void deinitialize(GDExtensionInitializationLevel p_level);

	CLASSDB_SINGLETON_FORWARD_METHODS;
};

/**
 * Exposes the named integer constant on the current extension class.
 *
 * **Used for** making a class constant available to scripts after the class is registered.
 *
 * - `m_constant` — Named integer value declared by the bound class.
 */
#define BIND_CONSTANT(m_constant) \
	::godot::ClassDB::bind_integer_constant(get_class_static(), "", #m_constant, m_constant);

/**
 * Exposes the named integer constant as a member of its registered enum.
 *
 * **Used for** making a named enum choice available to scripts under the corresponding enum.
 *
 * - `m_constant` — Named integer value declared by the bound class.
 */
#define BIND_ENUM_CONSTANT(m_constant) \
	::godot::ClassDB::bind_integer_constant(get_class_static(), ::godot::_gde_constant_get_enum_name(m_constant, #m_constant), #m_constant, m_constant);

/**
 * Exposes the named flag as a member of its registered bitfield.
 *
 * **Used for** exposing a flag that scripts can combine with other flags in the same bitfield.
 *
 * - `m_constant` — Named integer value declared by the bound class.
 */
#define BIND_BITFIELD_FLAG(m_constant) \
	::godot::ClassDB::bind_integer_constant(get_class_static(), ::godot::_gde_constant_get_bitfield_name(m_constant, #m_constant), #m_constant, m_constant, true);

/**
 * Builds a pointer-call trampoline for the extension implementation of an engine virtual method and registers it with the supplied signature hash.
 *
 * **Used for** dispatching an engine virtual call to its registered C++ override.
 *
 * - `m_class` — Extension class that implements the virtual method.
 * - `m_method` — C++ member function to bind as the virtual implementation.
 * - `m_hash` — Engine signature hash for the virtual method.
 */
#define BIND_VIRTUAL_METHOD(m_class, m_method, m_hash) \
	{ \
		auto _call##m_method = [](GDExtensionObjectPtr p_instance, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr p_ret) -> void { \
			call_with_ptr_args(reinterpret_cast<m_class *>(p_instance), &m_class::m_method, p_args, p_ret); \
		}; \
		::godot::ClassDB::bind_virtual_method(m_class::get_class_static(), #m_method, _call##m_method, m_hash); \
	}

template <typename T, bool is_abstract>
void ClassDB::_register_class(bool p_virtual, bool p_exposed, bool p_runtime) {
	static_assert(TypesAreSame<typename T::self_type, T>::value, "Class not declared properly, please use GDCLASS.");
	static_assert(!FunctionsAreSame<T::self_type::_bind_methods, T::parent_type::_bind_methods>::value, "Class must declare 'static void _bind_methods'.");
	static_assert(!std::is_abstract_v<T> || is_abstract, "Class is abstract, please use GDREGISTER_ABSTRACT_CLASS.");
	instance_binding_callbacks[T::get_class_static()] = &T::_gde_binding_callbacks;

	// Register this class within our plugin
	ClassInfo cl;
	cl.name = T::get_class_static();
	cl.parent_name = T::get_parent_class_static();
	cl.level = current_level;
	HashMap<StringName, ClassInfo>::Iterator parent_it = classes.find(cl.parent_name);
	if (parent_it != classes.end()) {
		// Assign parent if it is also a custom class
		cl.parent_ptr = &parent_it->value;
	}
	classes[cl.name] = cl;
	class_register_order.push_back(cl.name);

	// Register this class with Godot
#if GODOT_VERSION_MINOR >= 7
	GDExtensionClassCreationInfo6 class_info = {
#elif GODOT_VERSION_MINOR >= 5
	GDExtensionClassCreationInfo5 class_info = {
#elif GODOT_VERSION_MINOR >= 4
	GDExtensionClassCreationInfo4 class_info = {
#else
	GDExtensionClassCreationInfo3 class_info = {
#endif
		p_virtual, // GDExtensionBool is_virtual;
		is_abstract, // GDExtensionBool is_abstract;
		p_exposed, // GDExtensionBool is_exposed;
		p_runtime, // GDExtensionBool is_runtime;
#if GODOT_VERSION_MINOR >= 4
		nullptr, // GDExtensionConstStringPtr icon_path;
#endif // GODOT_VERSION_MINOR >= 4
		T::set_bind, // GDExtensionClassSet set_func;
		T::get_bind, // GDExtensionClassGet get_func;
		T::has_get_property_list() ? T::get_property_list_bind : nullptr, // GDExtensionClassGetPropertyList get_property_list_func;
		T::free_property_list_bind, // GDExtensionClassFreePropertyList2 free_property_list_func;
		T::property_can_revert_bind, // GDExtensionClassPropertyCanRevert property_can_revert_func;
		T::property_get_revert_bind, // GDExtensionClassPropertyGetRevert property_get_revert_func;
		T::validate_property_bind, // GDExtensionClassValidateProperty validate_property_func;
		T::notification_bind, // GDExtensionClassNotification2 notification_func;
		T::to_string_bind, // GDExtensionClassToString to_string_func;
		nullptr, // GDExtensionClassReference reference_func;
		nullptr, // GDExtensionClassUnreference unreference_func;
		&_create_instance_func<T>, // GDExtensionClassCreateInstance create_instance_func; /* this one is mandatory */
		T::free, // GDExtensionClassFreeInstance free_instance_func; /* this one is mandatory */
		&_recreate_instance_func<T>, // GDExtensionClassRecreateInstance recreate_instance_func;
		&ClassDB::get_virtual_func, // GDExtensionClassGetVirtual get_virtual_func;
		nullptr, // GDExtensionClassGetVirtualCallData get_virtual_call_data_func;
		nullptr, // GDExtensionClassCallVirtualWithData call_virtual_func;
#if GODOT_VERSION_MINOR <= 3
		nullptr, // GDExtensionClassGetRID get_rid;
#endif // GODOT_VERSION_MINOR <= 3
		(void *)&T::get_class_static(), // void *class_userdata;
	};

#if GODOT_VERSION_MINOR >= 7
	::godot::gdextension_interface::classdb_register_extension_class6(::godot::gdextension_interface::library, cl.name._native_ptr(), cl.parent_name._native_ptr(), &class_info);
#elif GODOT_VERSION_MINOR >= 5
	::godot::gdextension_interface::classdb_register_extension_class5(::godot::gdextension_interface::library, cl.name._native_ptr(), cl.parent_name._native_ptr(), &class_info);
#elif GODOT_VERSION_MINOR >= 4
	::godot::gdextension_interface::classdb_register_extension_class4(::godot::gdextension_interface::library, cl.name._native_ptr(), cl.parent_name._native_ptr(), &class_info);
#else
	::godot::gdextension_interface::classdb_register_extension_class3(::godot::gdextension_interface::library, cl.name._native_ptr(), cl.parent_name._native_ptr(), &class_info);
#endif

	// call bind_methods etc. to register all members of the class
	T::initialize_class();

	// now register our class within ClassDB within Godot
	initialize_class(classes[cl.name]);
}

template <typename T>
void ClassDB::register_class(bool p_virtual) {
	ClassDB::_register_class<T, false>(p_virtual);
}

template <typename T>
void ClassDB::register_abstract_class() {
	ClassDB::_register_class<T, true>();
}

template <typename T>
void ClassDB::register_internal_class() {
	ClassDB::_register_class<T, false>(false, false);
}

template <typename T>
void ClassDB::register_runtime_class() {
	ClassDB::_register_class<T, false>(false, true, true);
}

template <typename N, typename M, typename... VarArgs>
MethodBind *ClassDB::bind_method(N p_method_name, M p_method, VarArgs... p_args) {
	Variant args[sizeof...(p_args) + 1] = { p_args..., Variant() }; // +1 makes sure zero sized arrays are also supported.
	const Variant *argptrs[sizeof...(p_args) + 1];
	for (uint32_t i = 0; i < sizeof...(p_args); i++) {
		argptrs[i] = &args[i];
	}
	MethodBind *bind = create_method_bind(p_method);
	return bind_methodfi(METHOD_FLAGS_DEFAULT, bind, p_method_name, sizeof...(p_args) == 0 ? nullptr : (const void **)argptrs, sizeof...(p_args));
}

template <typename N, typename M, typename... VarArgs>
MethodBind *ClassDB::bind_static_method(StringName p_class, N p_method_name, M p_method, VarArgs... p_args) {
	Variant args[sizeof...(p_args) + 1] = { p_args..., Variant() }; // +1 makes sure zero sized arrays are also supported.
	const Variant *argptrs[sizeof...(p_args) + 1];
	for (uint32_t i = 0; i < sizeof...(p_args); i++) {
		argptrs[i] = &args[i];
	}
	MethodBind *bind = create_static_method_bind(p_method);
	bind->set_instance_class(p_class);
	return bind_methodfi(0, bind, p_method_name, sizeof...(p_args) == 0 ? nullptr : (const void **)argptrs, sizeof...(p_args));
}

template <typename M>
MethodBind *ClassDB::bind_vararg_method(uint32_t p_flags, StringName p_name, M p_method, const MethodInfo &p_info, const LocalVector<Variant> &p_default_args, bool p_return_nil_is_variant) {
	MethodBind *bind = create_vararg_method_bind(p_method, p_info, p_return_nil_is_variant);
	ERR_FAIL_NULL_V(bind, nullptr);

	bind->set_name(p_name);
	bind->set_default_arguments(p_default_args);

	StringName instance_type = bind->get_instance_class();

	HashMap<StringName, ClassInfo>::Iterator type_it = classes.find(instance_type);
	if (type_it == classes.end()) {
		memdelete(bind);
		ERR_FAIL_V_MSG(nullptr, String("Class '{0}' doesn't exist.").format(Array::make(instance_type)));
	}

	ClassInfo &type = type_it->value;

	if (type.method_map.find(p_name) != type.method_map.end()) {
		memdelete(bind);
		ERR_FAIL_V_MSG(nullptr, String("Binding duplicate method: {0}::{1}.").format(Array::make(instance_type, p_method)));
	}

	// register our method bind within our plugin
	type.method_map[p_name] = bind;

	// and register with godot
	bind_method_godot(type.name, bind);

	return bind;
}

/**
 * Registers the C++ extension class as a concrete class.
 *
 * **Used for** making an extension class available for engine construction after module initialization.
 *
 * - `m_class` — C++ extension class declared with Godot class metadata.
 */
#define GDREGISTER_CLASS(m_class) ::godot::ClassDB::register_class<m_class>();
/**
 * Registers the C++ extension class with its virtual flag set.
 *
 * **Used for** registering an extension base class that the editor's Create dialog skips as a direct construction choice.
 *
 * - `m_class` — C++ extension class declared with Godot class metadata.
 */
#define GDREGISTER_VIRTUAL_CLASS(m_class) ::godot::ClassDB::register_class<m_class>(true);
/**
 * Registers the C++ extension class as abstract.
 *
 * **Used for** registering a base type whose concrete subclasses provide the required implementation.
 *
 * - `m_class` — C++ extension class declared with Godot class metadata.
 */
#define GDREGISTER_ABSTRACT_CLASS(m_class) ::godot::ClassDB::register_abstract_class<m_class>();
/**
 * Registers the C++ extension class without engine exposure.
 *
 * **Used for** registering a C++ helper type for the extension's own use without exposing it to scripts.
 *
 * - `m_class` — C++ extension class declared with Godot class metadata.
 */
#define GDREGISTER_INTERNAL_CLASS(m_class) ::godot::ClassDB::register_internal_class<m_class>();
/**
 * Registers the C++ extension class as an exposed runtime class.
 *
 * **Used for** registering a runtime type whose instances can be represented by placeholders in the editor.
 *
 * - `m_class` — C++ extension class declared with Godot class metadata.
 */
#define GDREGISTER_RUNTIME_CLASS(m_class) ::godot::ClassDB::register_runtime_class<m_class>();

} // namespace godot

CLASSDB_SINGLETON_VARIANT_CAST;
