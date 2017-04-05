#ifndef GODOT_H
#define GODOT_H

#include <cstdlib>

#include <godot.h>


#include <godot_cpp/core/CoreTypes.hpp>
#include <godot_cpp/core/Variant.hpp>

namespace godot {




#if !defined(_WIN32)
#define GD_EXPORT
#else
#define GD_EXPORT __declspec(dllexport)
#endif


#define GODOT_DLSCRIPT_INIT(arg) extern "C" void GD_EXPORT godot_dlscript_init(arg)
#define GODOT_DLSCRIPT_TERMINATE(arg) extern "C" void GD_EXPORT godot_dlscript_terminate(arg)



#define GODOT_CLASS(Name, Base) \
	public: inline static char *___get_type_name() { return (char *) #Name; } \
	inline static char *___get_base_type_name() { return (char *) #Base; } \
	Base *self; \
	inline Name(godot_object *o) { self = (Base *) o; } \
	private:
        // inline Name(Object o) { this = (Name *) godot_dlinstance_get_userdata(o.__core_object);\
        //         memcpy(this, p, sizeof(Name)); } \
        // inline Name(const Variant& obj) { __core_object = ((Object) obj).__core_object; } \



template<class T>
T *as(Object *obj)
{
	return (T *) godot_dlinstance_get_userdata(obj);
}

// instance and destroy funcs

template<class T>
void *_godot_class_instance_func(godot_object *p, void *method_data)
{
	T *d = new T(p);
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

		*var = (obj->*(method->f))(*arg[0]);

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

		(obj->*(method->f))(*arg[0]);

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

		*var = (obj->*(method->f))(*arg[0], *arg[1]);

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

		(obj->*(method->f))(*arg[0], *arg[1]);

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

		*var = (obj->*(method->f))(*arg[0], *arg[1], *arg[2]);

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

		(obj->*(method->f))(*arg[0], *arg[1], *arg[2]);

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

		*var = (obj->*(method->f))(*arg[0], *arg[1], *arg[2], *arg[3]);

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

		(obj->*(method->f))(*arg[0], *arg[1], *arg[2], *arg[3]);

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

		*var = (obj->*(method->f))(*arg[0], *arg[1], *arg[2], *arg[3], *arg[4]);

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

		(obj->*(method->f))(*arg[0], *arg[1], *arg[2], *arg[3], *arg[4]);

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

		(obj->*(set_func->f))(*v);
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
void register_property(char *name, void (T::*setter)(P), P (T::*getter)(), P default_value, godot_method_rpc_mode rpc_mode = GODOT_METHOD_RPC_MODE_DISABLED,  godot_property_usage_flags usage = GODOT_PROPERTY_USAGE_DEFAULT, godot_property_hint hint = GODOT_PROPERTY_HINT_NONE)
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

}

#endif // GODOT_H
