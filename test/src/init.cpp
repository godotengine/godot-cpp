#include <Godot.hpp>
#include <Reference.hpp>

using namespace godot;

class SimpleClass : public Reference {
	GODOT_CLASS(SimpleClass, Reference);

public:
	SimpleClass() {}

	/** `_init` must exist as it is called by Godot. */
	void _init() {
		_name = String("SimpleClass");
		_value = 0;
	}

	void test_void_method() {
		Godot::print("This is test");
	}

	Variant method(Variant arg) {
		Variant ret;
		ret = arg;

		return ret;
	}

	static void _register_methods() {
		register_method("method", &SimpleClass::method);

		/**
		 * The line below is equivalent to the following GDScript export:
		 *	 export var _name = "SimpleClass"
		 **/
		register_property<SimpleClass, String>("name", &SimpleClass::_name, String("SimpleClass"));

		/** Alternatively, with getter and setter methods: */
		register_property<SimpleClass, int>("value", &SimpleClass::set_value, &SimpleClass::get_value, 0);

		/** Registering a signal: **/
		register_signal<SimpleClass>("signal_name0"); // windows: error C2668: 'godot::register_signal': ambiguous call to overloaded function
		register_signal<SimpleClass>("signal_name1", "string_argument", GODOT_VARIANT_TYPE_STRING);
	}

	String _name;
	int _value;

	void set_value(int p_value) {
		_value = p_value;
	}

	int get_value() const {
		return _value;
	}
};

/** GDNative Initialize **/
extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
	godot::Godot::gdnative_init(o);
}

/** GDNative Terminate **/
extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
	godot::Godot::gdnative_terminate(o);
}

/** NativeScript Initialize **/
extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
	godot::Godot::nativescript_init(handle);

	godot::register_class<SimpleClass>();
}
