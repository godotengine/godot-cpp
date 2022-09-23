/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

// We don't need windows.h in this example plugin but many others do, and it can
// lead to annoying situations due to the ton of macros it defines.
// So we include it and make sure CI warns us if we use something that conflicts
// with a Windows define.
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class ExampleRef : public RefCounted {
	GDCLASS(ExampleRef, RefCounted);

protected:
	static void _bind_methods() {}

public:
	ExampleRef();
	~ExampleRef();
};

class ExampleMin : public Control {
	GDCLASS(ExampleMin, Control);

protected:
	static void _bind_methods(){};
};

class Example : public Control {
	GDCLASS(Example, Control);

protected:
	static void _bind_methods();

	void _notification(int p_what);
	bool _set(const StringName &p_name, const Variant &p_value);
	bool _get(const StringName &p_name, Variant &r_ret) const;
	void _get_property_list(List<PropertyInfo> *p_list) const;
	bool _property_can_revert(const StringName &p_name) const;
	bool _property_get_revert(const StringName &p_name, Variant &r_property) const;

	String _to_string() const;

private:
	Vector2 custom_position;
	Vector3 property_from_list;
	Vector2 dprop[3];

public:
	// Constants.
	enum Constants {
		FIRST,
		ANSWER_TO_EVERYTHING = 42,
	};

	enum {
		CONSTANT_WITHOUT_ENUM = 314,
	};

	Example();
	~Example();

	// Functions.
	void simple_func();
	void simple_const_func() const;
	String return_something(const String &base);
	Viewport *return_something_const() const;
	ExampleRef *return_extended_ref() const;
	Ref<ExampleRef> extended_ref_checks(Ref<ExampleRef> p_ref) const;
	Variant varargs_func(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error);
	int varargs_func_nv(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error);
	void varargs_func_void(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error);
	void emit_custom_signal(const String &name, int value);
	int def_args(int p_a = 100, int p_b = 200);

	Array test_array() const;
	void test_tarray_arg(const TypedArray<int64_t> &p_array);
	TypedArray<Vector2> test_tarray() const;
	Dictionary test_dictionary() const;

	// Property.
	void set_custom_position(const Vector2 &pos);
	Vector2 get_custom_position() const;
	Vector4 get_v4() const;

	// Static method.
	static int test_static(int p_a, int p_b);
	static void test_static2();

	// Virtual function override (no need to bind manually).
	virtual bool _has_point(const Vector2 &point) const override;
};

VARIANT_ENUM_CAST(Example, Constants);

#endif // EXAMPLE_CLASS_H
