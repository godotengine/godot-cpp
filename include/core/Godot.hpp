#ifndef GODOT_HPP
#define GODOT_HPP

#include <cstdlib>
#include <cstring>

#include <godot.h>


#include <CoreTypes.hpp>
#include <Variant.hpp>
#include <Ref.hpp>

#include <Object.hpp>

#include <GodotGlobal.hpp>


namespace godot {


template<class T>
class GodotScript {
public:
	T *owner;
	
	// GodotScript() {}

	void _init() {}
	static char *___get_base_type_name()
	{
		return T::___get_class_name();
	}

	static void _register_methods() {}
};





#if !defined(_WIN32)
#define GD_EXPORT
#else
#define GD_EXPORT __declspec(dllexport)
#endif


#define GODOT_NATIVE_INIT(arg) extern "C" void GD_EXPORT godot_native_init(arg)
#define GODOT_NATIVE_TERMINATE(arg) extern "C" void GD_EXPORT godot_native_terminate(arg)



#define GODOT_CLASS(Name) \
	public: inline static char *___get_type_name() { return (char *) #Name; } \
	private:

#define GODOT_SUBCLASS(Name, Base) \
	public: inline static char *___get_type_name() { return (char *) #Name; } \
	inline static char *___get_base_type_name() { return (char *) #Base; } \
	inline Name(godot_object *o) : Base(o) {} \
	private:



template<class T>
struct _ArgCast {
	static T _arg_cast(Variant a)
	{
		return static_cast<T>(a);
	}
};

template<class T>
struct _ArgCast<T*> {
	static T *_arg_cast(Variant a)
	{
		return (T *) ((Object *) a);
	}
};

template<>
struct _ArgCast<Variant> {
	static Variant _arg_cast(Variant a)
	{
		return a;
	}
};




template<class T>
T *as(Object *obj)
{
	return (T *) godot_native_get_userdata(obj);
}

// instance and destroy funcs

template<class T>
void *_godot_class_instance_func(godot_object *p, void *method_data)
{
	T *d = new T();
	*(godot_object **) &d->owner = p;
	d->_init();
	return d;
}

template<class T>
void _godot_class_destroy_func(godot_object *p, void *method_data, void *data)
{
	T *d = (T *) data;
	delete d;
}



template<class T>
void register_class()
{
	godot_instance_create_func create = {};
	create.create_func = _godot_class_instance_func<T>;

	godot_instance_destroy_func destroy = {};
	destroy.destroy_func = _godot_class_destroy_func<T>;


	godot_script_register_class(T::___get_type_name(), T::___get_base_type_name(), create, destroy);
	T::_register_methods();
}

template<class T>
void register_tool_class()
{
	godot_instance_create_func create = {};
	create.create_func = _godot_class_instance_func<T>;

	godot_instance_destroy_func destroy = {};
	destroy.destroy_func = _godot_class_destroy_func<T>;


	godot_script_register_tool_class(T::___get_type_name(), T::___get_base_type_name(), create, destroy);
	T::_register_methods();
}












// method registering

typedef godot_variant (*__godot_wrapper_method)(godot_object *, void *, void *, int, godot_variant **);


template<class T, class R, class ...args>
char *___get_method_class_name(R (T::*p)(args... a))
{
	return T::___get_type_name();
}

template<class T, class R, class ...args>
char *___get_method_class_name(R (T::*p)(args... a) const)
{
	return T::___get_type_name();
}


// wohooo, let the fun begin.

template<class T, class R>
struct _WrappedMethod0 {
	R (T::*f)();
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod0<T, R> *method = (_WrappedMethod0<T, R>*) method_data;

		Variant *var = (Variant *) &v;

		*var = (obj->*(method->f))();

		return v;
	}
};


template<class T>
struct _WrappedMethod0<T, void> {
	void (T::*f)();
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod0<T, void> *method = (_WrappedMethod0<T, void>*) method_data;

		(obj->*(method->f))();

		return v;
	}
};

template<class T, class R>
void *___make_wrapper_function(R (T::*f)())
{
	_WrappedMethod0<T, R> *p = (_WrappedMethod0<T, R> *) malloc(sizeof(_WrappedMethod0<T, R>));
	p->f = f;
	return (void *) p;
}

template<class T, class R>
__godot_wrapper_method ___get_wrapper_function(R (T::*f)())
{
	return (__godot_wrapper_method) &_WrappedMethod0<T, R>::__wrapped_method;
}








template<class T, class R, class A0>
struct _WrappedMethod1 {
	R (T::*f)(A0);
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod1<T, R, A0> *method = (_WrappedMethod1<T, R, A0>*) method_data;

		Variant *var = (Variant *) &v;
		Variant **arg = (Variant **) args;

		*var = (obj->*(method->f))(_ArgCast<A0>::_arg_cast(*arg[0]));

		return v;
	}
};

template<class T, class A0>
struct _WrappedMethod1<T, void, A0> {
	void (T::*f)(A0);
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod1<T, void, A0> *method = (_WrappedMethod1<T, void, A0>*) method_data;

		Variant **arg = (Variant **) args;

		(obj->*(method->f))(_ArgCast<A0>::_arg_cast(*arg[0]));

		return v;
 	}
};


template<class T, class R, class A0>
void *___make_wrapper_function(R (T::*f)(A0))
{
	_WrappedMethod1<T, R, A0> *p = (_WrappedMethod1<T, R, A0> *) malloc(sizeof(_WrappedMethod1<T, R, A0>));
	p->f = f;
	return (void *) p;
}

template<class T, class R, class A0>
__godot_wrapper_method ___get_wrapper_function(R (T::*f)(A0))
{
	return (__godot_wrapper_method) &_WrappedMethod1<T, R, A0>::__wrapped_method;
}












template<class T, class R, class A0, class A1>
struct _WrappedMethod2 {
	R (T::*f)(A0, A1);
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod2<T, R, A0, A1> *method = (_WrappedMethod2<T, R, A0, A1>*) method_data;

		Variant *var = (Variant *) &v;
		Variant **arg = (Variant **) args;

		*var = (obj->*(method->f))(_ArgCast<A0>::_arg_cast(*arg[0]), _ArgCast<A1>::_arg_cast(*arg[1]));

		return v;
	}
};

template<class T, class A0, class A1>
struct _WrappedMethod2<T, void, A0, A1> {
	void (T::*f)(A0, A1);
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod2<T, void, A0, A1> *method = (_WrappedMethod2<T, void, A0, A1>*) method_data;

		Variant **arg = (Variant **) args;

		(obj->*(method->f))(_ArgCast<A0>::_arg_cast(*arg[0]), _ArgCast<A1>::_arg_cast(*arg[1]));

		return v;
	}
};


template<class T, class R, class A0, class A1>
void *___make_wrapper_function(R (T::*f)(A0, A1))
{
	_WrappedMethod2<T, R, A0, A1> *p = (_WrappedMethod2<T, R, A0, A1> *) malloc(sizeof(_WrappedMethod2<T, R, A0, A1>));
	p->f = f;
	return (void *) p;
}

template<class T, class R, class A0, class A1>
__godot_wrapper_method ___get_wrapper_function(R (T::*f)(A0, A1))
{
	return (__godot_wrapper_method) &_WrappedMethod2<T, R, A0, A1>::__wrapped_method;
}












template<class T, class R, class A0, class A1, class A2>
struct _WrappedMethod3 {
	R (T::*f)(A0, A1, A2);
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod3<T, R, A0, A1, A2> *method = (_WrappedMethod3<T, R, A0, A1, A2>*) method_data;

		Variant *var = (Variant *) &v;
		Variant **arg = (Variant **) args;

		*var = (obj->*(method->f))(_ArgCast<A0>::_arg_cast(*arg[0]), _ArgCast<A1>::_arg_cast(*arg[1]), _ArgCast<A2>::_arg_cast(*arg[2]));

		return v;
	}
};

template<class T, class A0, class A1, class A2>
struct _WrappedMethod3<T, void, A0, A1, A2> {
	void (T::*f)(A0, A1, A2);
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod3<T, void, A0, A1, A2> *method = (_WrappedMethod3<T, void, A0, A1, A2>*) method_data;

		Variant **arg = (Variant **) args;

		(obj->*(method->f))(_ArgCast<A0>::_arg_cast(*arg[0]), _ArgCast<A1>::_arg_cast(*arg[1]), _ArgCast<A2>::_arg_cast(*arg[2]));

		return v;
	}
};


template<class T, class R, class A0, class A1, class A2>
void *___make_wrapper_function(R (T::*f)(A0, A1, A2))
{
	_WrappedMethod3<T, R, A0, A1, A2> *p = (_WrappedMethod3<T, R, A0, A1, A2> *) malloc(sizeof(_WrappedMethod3<T, R, A0, A1, A2>));
	p->f = f;
	return (void *) p;
}

template<class T, class R, class A0, class A1, class A2>
__godot_wrapper_method ___get_wrapper_function(R (T::*f)(A0, A1, A2))
{
	return (__godot_wrapper_method) &_WrappedMethod3<T, R, A0, A1, A2>::__wrapped_method;
}











template<class T, class R, class A0, class A1, class A2, class A3>
struct _WrappedMethod4 {
	R (T::*f)(A0, A1, A2, A3);
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod4<T, R, A0, A1, A2, A3> *method = (_WrappedMethod4<T, R, A0, A1, A2, A3>*) method_data;

		Variant *var = (Variant *) &v;
		Variant **arg = (Variant **) args;

		*var = (obj->*(method->f))(_ArgCast<A0>::_arg_cast(*arg[0]), _ArgCast<A1>::_arg_cast(*arg[1]), _ArgCast<A2>::_arg_cast(*arg[2]), _ArgCast<A3>::_arg_cast(*arg[3]));

		return v;
	}
};

template<class T, class A0, class A1, class A2, class A3>
struct _WrappedMethod4<T, void, A0, A1, A2, A3> {
	void (T::*f)(A0, A1, A2, A3);
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod4<T, void, A0, A1, A2, A3> *method = (_WrappedMethod4<T, void, A0, A1, A2, A3>*) method_data;

		Variant **arg = (Variant **) args;

		(obj->*(method->f))(_ArgCast<A0>::_arg_cast(*arg[0]), _ArgCast<A1>::_arg_cast(*arg[1]), _ArgCast<A2>::_arg_cast(*arg[2]), _ArgCast<A3>::_arg_cast(*arg[3]));

		return v;
	}
};


template<class T, class R, class A0, class A1, class A2, class A3>
void *___make_wrapper_function(R (T::*f)(A0, A1, A2, A3))
{
	_WrappedMethod4<T, R, A0, A1, A2, A3> *p = (_WrappedMethod4<T, R, A0, A1, A2, A3> *) malloc(sizeof(_WrappedMethod4<T, R, A0, A1, A2, A3>));
	p->f = f;
	return (void *) p;
}

template<class T, class R, class A0, class A1, class A2, class A3>
__godot_wrapper_method ___get_wrapper_function(R (T::*f)(A0, A1, A2, A3))
{
	return (__godot_wrapper_method) &_WrappedMethod4<T, R, A0, A1, A2, A3>::__wrapped_method;
}










template<class T, class R, class A0, class A1, class A2, class A3, class A4>
struct _WrappedMethod5 {
	R (T::*f)(A0, A1, A2, A3, A4);
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod5<T, R, A0, A1, A2, A3, A4> *method = (_WrappedMethod5<T, R, A0, A1, A2, A3, A4>*) method_data;

		Variant *var = (Variant *) &v;
		Variant **arg = (Variant **) args;

		*var = (obj->*(method->f))(_ArgCast<A0>::_arg_cast(*arg[0]), _ArgCast<A1>::_arg_cast(*arg[1]), _ArgCast<A2>::_arg_cast(*arg[2]), _ArgCast<A3>::_arg_cast(*arg[3]), _ArgCast<A4>::_arg_cast(*arg[4]));

		return v;
	}
};

template<class T, class A0, class A1, class A2, class A3, class A4>
struct _WrappedMethod5<T, void, A0, A1, A2, A3, A4> {
	void (T::*f)(A0, A1, A2, A3, A4);
	static godot_variant __wrapped_method(godot_object *, void *method_data, void *user_data, int num_args, godot_variant **args)
	{
		godot_variant v;
		godot_variant_new_nil(&v);

		T *obj = (T *) user_data;
		_WrappedMethod5<T, void, A0, A1, A2, A3, A4> *method = (_WrappedMethod5<T, void, A0, A1, A2, A3, A4>*) method_data;

		Variant **arg = (Variant **) args;

		(obj->*(method->f))(_ArgCast<A0>::_arg_cast(*arg[0]), _ArgCast<A1>::_arg_cast(*arg[1]), _ArgCast<A2>::_arg_cast(*arg[2]), _ArgCast<A3>::_arg_cast(*arg[3]), _ArgCast<A4>::_arg_cast(*arg[4]));

		return v;
	}
};


template<class T, class R, class A0, class A1, class A2, class A3, class A4>
void *___make_wrapper_function(R (T::*f)(A0, A1, A2, A3, A4))
{
	_WrappedMethod5<T, R, A0, A1, A2, A3, A4> *p = (_WrappedMethod5<T, R, A0, A1, A2, A3, A4> *) malloc(sizeof(_WrappedMethod5<T, R, A0, A1, A2, A3, A4>));
	p->f = f;
	return (void *) p;
}

template<class T, class R, class A0, class A1, class A2, class A3, class A4>
__godot_wrapper_method ___get_wrapper_function(R (T::*f)(A0, A1, A2, A3, A4))
{
	return (__godot_wrapper_method) &_WrappedMethod5<T, R, A0, A1, A2, A3, A4>::__wrapped_method;
}

template<class T, class R, class ...A>
void *___make_wrapper_function(R (T::*f)(A...) const)
{
	return ___make_wrapper_function((R (T::*)(A...)) f);
}


template<class T, class R, class ...A>
__godot_wrapper_method ___get_wrapper_function(R (T::*f)(A...) const)
{
	return ___get_wrapper_function((R (T::*)(A...)) f);
}













template<class M>
void register_method(char *name, M method_ptr, godot_method_rpc_mode rpc_type = GODOT_METHOD_RPC_MODE_DISABLED)
{
	godot_instance_method method = {};
	method.method_data = ___make_wrapper_function(method_ptr);
	method.free_func = free;
	method.method = (__godot_wrapper_method) ___get_wrapper_function(method_ptr);


	godot_method_attributes attr = {};
	attr.rpc_type = rpc_type;

	godot_script_register_method(___get_method_class_name(method_ptr), name, attr, method);
}



template<class T, class P>
struct _PropertySetFunc {
	void (T::*f)(P);
	static void _wrapped_setter(godot_object *object, void *method_data, void *user_data, godot_variant value)
	{
		_PropertySetFunc<T, P> *set_func = (_PropertySetFunc<T, P> *) method_data;
		T *obj = (T *) user_data;

		Variant *v = (Variant *) &value;

		(obj->*(set_func->f))(_ArgCast<P>::_arg_cast(*v));
	}
};

template<class T, class P>
struct _PropertyGetFunc {
	P (T::*f)();
	static godot_variant _wrapped_getter(godot_object *object, void *method_data, void *user_data)
	{
		_PropertyGetFunc<T, P> *get_func = (_PropertyGetFunc<T, P> *) method_data;
		T *obj = (T *) user_data;

		godot_variant var;
		godot_variant_new_nil(&var);

		Variant *v = (Variant *) &var;

		*v = (obj->*(get_func->f))();

		return var;
	}
};






template<class T, class P>
struct _PropertyDefaultSetFunc {
	P (T::*f);
	static void _wrapped_setter(godot_object *object, void *method_data, void *user_data, godot_variant value)
	{
		_PropertyDefaultSetFunc<T, P> *set_func = (_PropertyDefaultSetFunc<T, P> *) method_data;
		T *obj = (T *) user_data;

		Variant *v = (Variant *) &value;

		(obj->*(set_func->f)) = _ArgCast<P>::_arg_cast(*v);
	}
};

template<class T, class P>
struct _PropertyDefaultGetFunc {
	P (T::*f);
	static godot_variant _wrapped_getter(godot_object *object, void *method_data, void *user_data)
	{
		_PropertyDefaultGetFunc<T, P> *get_func = (_PropertyDefaultGetFunc<T, P> *) method_data;
		T *obj = (T *) user_data;

		godot_variant var;
		godot_variant_new_nil(&var);

		Variant *v = (Variant *) &var;

		*v = (obj->*(get_func->f));

		return var;
	}
};


template<class T, class P>
void register_property(char *name, P (T::*var), P default_value, godot_method_rpc_mode rpc_mode = GODOT_METHOD_RPC_MODE_DISABLED,  godot_property_usage_flags usage = GODOT_PROPERTY_USAGE_DEFAULT, godot_property_hint hint = GODOT_PROPERTY_HINT_NONE, String hint_string = "")
{
	Variant def_val = default_value;

	usage = (godot_property_usage_flags) ((int) usage | GODOT_PROPERTY_USAGE_SCRIPT_VARIABLE);

	if (def_val.get_type() == Variant::OBJECT) {
		Object *o = def_val;
		if (o && o->is_class("Resource")) {
			hint = (godot_property_hint) ((int) hint | GODOT_PROPERTY_HINT_RESOURCE_TYPE);
			hint_string = o->get_class();
		}
	}

	godot_string *_hint_string = (godot_string*) &hint_string;

	godot_property_attributes attr = {};
	attr.type = def_val.get_type();
	attr.default_value = *(godot_variant *) &def_val;
	attr.hint = hint;
	attr.rset_type = rpc_mode;
	attr.usage = usage;
	attr.hint_string = *_hint_string;

	_PropertyDefaultSetFunc<T, P> *wrapped_set = (_PropertyDefaultSetFunc<T, P> *) malloc(sizeof(_PropertyDefaultSetFunc<T, P>));
	wrapped_set->f = var;

	_PropertyDefaultGetFunc<T, P> *wrapped_get = (_PropertyDefaultGetFunc<T, P> *) malloc(sizeof(_PropertyDefaultGetFunc<T, P>));
	wrapped_get->f = var;

	godot_property_set_func set_func = {};
	set_func.method_data = (void *) wrapped_set;
	set_func.free_func   = free;
	set_func.set_func    = &_PropertyDefaultSetFunc<T, P>::_wrapped_setter;

	godot_property_get_func get_func = {};
	get_func.method_data = (void *) wrapped_get;
	get_func.free_func   = free;
	get_func.get_func    = &_PropertyDefaultGetFunc<T, P>::_wrapped_getter;

	godot_script_register_property(T::___get_type_name(), name, &attr, set_func, get_func);
}




template<class T, class P>
void register_property(char *name, void (T::*setter)(P), P (T::*getter)(), P default_value, godot_method_rpc_mode rpc_mode = GODOT_METHOD_RPC_MODE_DISABLED,  godot_property_usage_flags usage = GODOT_PROPERTY_USAGE_DEFAULT, godot_property_hint hint = GODOT_PROPERTY_HINT_NONE, String hint_string = "")
{
	Variant def_val = default_value;

	godot_property_attributes attr = {};
	attr.type = def_val.get_type();
	attr.default_value = *(godot_variant *) &def_val;
	attr.hint = hint;
	attr.rset_type = rpc_mode;
	attr.usage = usage;

	_PropertySetFunc<T, P> *wrapped_set = (_PropertySetFunc<T, P> *) malloc(sizeof(_PropertySetFunc<T, P>));
	wrapped_set->f = setter;

	_PropertyGetFunc<T, P> *wrapped_get = (_PropertyGetFunc<T, P> *) malloc(sizeof(_PropertyGetFunc<T, P>));
	wrapped_get->f = getter;

	godot_property_set_func set_func = {};
	set_func.method_data = (void *) wrapped_set;
	set_func.free_func   = free;
	set_func.set_func    = &_PropertySetFunc<T, P>::_wrapped_setter;

	godot_property_get_func get_func = {};
	get_func.method_data = (void *) wrapped_get;
	get_func.free_func   = free;
	get_func.get_func    = &_PropertyGetFunc<T, P>::_wrapped_getter;

	godot_script_register_property(T::___get_type_name(), name, &attr, set_func, get_func);

}

template<class T>
void register_signal(String name, Dictionary args = Dictionary())
{
	godot_signal signal = {};
	signal.name = *(godot_string *)&name;
	signal.num_args = args.size();
	signal.num_default_args = 0;

	signal.args = (godot_signal_argument*) godot_alloc(sizeof(godot_signal_argument) * signal.num_args);
	memset((void *) signal.args, 0, sizeof(godot_signal_argument) * signal.num_args);


	for (int i = 0; i < signal.num_args; i++) {
		// Array entry = args[i];
		// String name = entry[0];
		String name = args.keys()[i];
		godot_string *_key = (godot_string *)&name;
		godot_string_new_copy(&signal.args[i].name, _key);

		// if (entry.size() > 1) {
		// 	signal.args[i].type = entry[1];
		// }
		signal.args[i].type = args.values()[i];
	}

	godot_script_register_signal(T::___get_type_name(), &signal);

	for (int i = 0; i < signal.num_args; i++) {
		godot_string_destroy(&signal.args[i].name);
	}
}


}

#endif // GODOT_H
