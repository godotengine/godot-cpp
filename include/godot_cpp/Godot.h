#ifndef GODOT_H
#define GODOT_H

#include <cstdlib>

#include <godot.h>


#include <godot_cpp/core/Variant.h>

namespace godot {


#define GODOT_CLASS(Name, Base) \
	public: static char *___get_type_name() { return (char *) #Name; } \
	static char *___get_base_type_name() { return (char *) #Base; } \
	Name(godot_object *o) { __core_object = o; } \
	private:



template<class A, class B>
A object_cast(B b)
{
	A *a = (A*) &b;
	return *a;
}





// instance and destroy funcs

template<class T>
void *_godot_class_instance_func(godot_object *p)
{
	T *d = new T(p);
	d->_init();
	return d;
}

template<class T>
void _godot_class_destroy_func(godot_object *p, void *data)
{
	T *d = (T *) data;
	delete d;
}



template<class T>
void register_class()
{
	godot_script_register(T::___get_type_name(), T::___get_base_type_name(), _godot_class_instance_func<T>, _godot_class_destroy_func<T>);
	T::_register_methods();
}






// wrapped methods

template<class T, class R, class A0, class A1, class A2, class A3, class A4, R (T::*p)(A0, A1, A2, A3, A4)>
struct WrappedMethod5 {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		godot::Variant *v = (godot::Variant *) &_variant;
		T *obj = (T *) data;
		godot::Variant **arg = (godot::Variant **) args;
		*v = (obj->*p)(*arg[0], *arg[1], *arg[2], *arg[3], *arg[4]);
		return _variant;
	}
};

template<class T, class A0, class A1, class A2, class A3, class A4, void (T::*p)(A0, A1, A2, A3, A4)>
struct WrappedMethod5<T, void, A0, A1, A2, A3, A4, p> {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		T *obj = (T *) data;
		godot::Variant **arg = (godot::Variant **) args;
		(obj->*p)(*arg[0], *arg[1], *arg[2], *arg[3], *arg[4]);
		return _variant;
	}
};

template<class T, class R, class A0, class A1, class A2, class A3, R (T::*p)(A0, A1, A2, A3)>
struct WrappedMethod4 {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		godot::Variant *v = (godot::Variant *) &_variant;
		T *obj = (T *) data;
		godot::Variant **arg = (godot::Variant **) args;
		*v = (obj->*p)(*arg[0], *arg[1], *arg[2], *arg[3]);
		return _variant;
	}
};

template<class T, class A0, class A1, class A2, class A3, void (T::*p)(A0, A1, A2, A3)>
struct WrappedMethod4<T, void, A0, A1, A2, A3, p> {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		T *obj = (T *) data;
		godot::Variant **arg = (godot::Variant **) args;
		(obj->*p)(*arg[0], *arg[1], *arg[2], *arg[3]);
		return _variant;
	}
};


template<class T, class R, class A0, class A1, class A2, R (T::*p)(A0, A1, A2)>
struct WrappedMethod3 {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		godot::Variant *v = (godot::Variant *) &_variant;
		T *obj = (T *) data;
		godot::Variant **arg = (godot::Variant **) args;
		*v = (obj->*p)(*arg[0], *arg[1], *arg[2]);
		return _variant;
	}
};

template<class T, class A0, class A1, class A2, void (T::*p)(A0, A1, A2)>
struct WrappedMethod3<T, void, A0, A1, A2, p> {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		T *obj = (T *) data;
		godot::Variant **arg = (godot::Variant **) args;
		(obj->*p)(*arg[0], *arg[1], *arg[2]);
		return _variant;
	}
};

template<class T, class R, class A0, class A1, R (T::*p)(A0, A1)>
struct WrappedMethod2 {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		godot::Variant *v = (godot::Variant *) &_variant;
		T *obj = (T *) data;
		godot::Variant **arg = (godot::Variant **) args;
		*v = (obj->*p)(*arg[0], *arg[1]);
		return _variant;
	}
};

template<class T, class A0, class A1, void (T::*p)(A0, A1)>
struct WrappedMethod2<T, void, A0, A1, p> {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		T *obj = (T *) data;
		godot::Variant **arg = (godot::Variant **) args;
		(obj->*p)(*arg[0], *arg[1]);
		return _variant;
	}
};

template<class T, class R, class I, R (T::*p)(I)>
struct WrappedMethod1 {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		godot::Variant *v = (godot::Variant *) &_variant;
		T *obj = (T *) data;
		godot::Variant **arg = (godot::Variant **) args;
		*v = (obj->*p)(*arg[0]);
		return _variant;
	}
};

template <class T, class I, void (T::*p)(I)>
struct WrappedMethod1<T, void, I, p> {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		T *obj = (T *) data;
		godot::Variant **arg = (godot::Variant **) args;
		(obj->*p)(*arg[0]);
		return _variant;
	}
};



template<class T, class R, R (T::*p)()>
struct WrappedMethod0 {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		godot::Variant *v = (godot::Variant *) &_variant;
		T *obj = (T *) data;
		*v = (obj->*p)();
		return _variant;
	}
};

template<class T, void (T::*p)()>
struct WrappedMethod0<T, void, p> {
	static godot_variant wrapped_method(godot_object *_, void *data, int num_args, godot_variant **args)
	{
		godot_variant _variant;
		godot_variant_new_nil(&_variant);
		T *obj = (T *) data;
		(obj->*p)();
		return _variant;
	}
};



template<class T, class R, class A0, class A1, R (T::*p)(A0, A1)>
struct WrappedMethod2;

template<class T, class R, class A0, class A1, class A2, R (T::*p)(A0, A1, A2)>
struct WrappedMethod3;

template<class T, class R, class A0, class A1, class A2, class A3, R (T::*p)(A0, A1, A2, A3)>
struct WrappedMethod4;

template<class T, class R, class A0, class A1, class A2, class A3, class A4, R (T::*p)(A0, A1, A2, A3, A4)>
struct WrappedMethod5;

// method registering


template<class T, class R, R (T::*p)()>
void register_method(char *name, godot_method_attributes attr = {}) {
	godot_script_add_method(T::___get_type_name(), name, &attr, &WrappedMethod0<T, R, p>::wrapped_method);
}

template<class T, class R, class A0, R (T::*p)(A0)>
void register_method(char *name, godot_method_attributes attr = {}) {
	godot_script_add_method(T::___get_type_name(), name, &attr, &WrappedMethod1<T, R, A0, p>::wrapped_method);
}

template<class T, class R, class A0, class A1, R (T::*p)(A0, A1)>
void register_method(char *name, godot_method_attributes attr = {}) {
	godot_script_add_method(T::___get_type_name(), name, &attr, &WrappedMethod2<T, R, A0, A1, p>::wrapped_method);
}

template<class T, class R, class A0, class A1, class A2, R (T::*p)(A0, A1, A2)>
void register_method(char *name, godot_method_attributes attr = {}) {
	godot_script_add_method(T::___get_type_name(), name, &attr, &WrappedMethod3<T, R, A0, A1, A2, p>::wrapped_method);
}

template<class T, class R, class A0, class A1, class A2, class A3, R (T::*p)(A0, A1, A2, A3)>
void register_method(char *name, godot_method_attributes attr = {}) {
	godot_script_add_method(T::___get_type_name(), name, &attr, &WrappedMethod4<T, R, A0, A1, A2, A3, p>::wrapped_method);
}


template<class T, class R, class A0, class A1, class A2, class A3, class A4, R (T::*p)(A0, A1, A2, A3, A4)>
void register_method(char *name, godot_method_attributes attr = {}) {
	godot_script_add_method(T::___get_type_name(), name, &attr, &WrappedMethod5<T, R, A0, A1, A2, A3, A4, p>::wrapped_method);
}


}

#endif // GODOT_H
