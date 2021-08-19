#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class Example : public Control {
	GDCLASS(Example, Control);

protected:
	static void _bind_methods();

private:
	Vector2 custom_position;

public:
	// Constants.
	enum Constants {
		FIRST,
		ANSWER_TO_EVERYTHING = 42,
	};

	enum {
		CONSTANT_WITHOUT_ENUM = 314,
	};

	// Functions
	void simple_func();
	void simple_const_func() const;
	String return_something(const String &base);
	Viewport *return_something_const() const;
	Variant varargs_func(const Variant **args, GDNativeInt arg_count, GDNativeCallError &error);
	void emit_custom_signal(const String &name, int value);

	// Property
	void set_custom_position(const Vector2 &pos);
	Vector2 get_custom_position() const;

	// Virtual function override
	virtual bool _has_point(const Vector2 &point);
};

VARIANT_ENUM_CAST(Example, Constants);

#endif // ! EXAMPLE_CLASS_H
