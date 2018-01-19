#ifndef REF_H
#define REF_H

#include "Variant.hpp"
#include "GodotGlobal.hpp"

namespace godot {

template<class T>
class Ref {
	T *reference;

public:
	inline bool operator==(const Ref<T> &r) const
	{
		return reference == r.reference;
	}
	
	inline bool operator!=(const Ref<T> &r) const
	{
		return reference != r.reference;
	}
	
	inline T *operator->()
	{
		return reference;
	}
	
	inline T *operator*()
	{
		return reference;
	}
	
	inline T *ptr()
	{
		return reference;
	}
	
	inline const T *operator->() const
	{
		return reference;
	}
	
	inline const T *operator*() const
	{
		return reference;
	}
	
	inline const T *ptr() const
	{
		return reference;
	}
	
	
	
	void operator=(const Ref &from)
	{
		if (reference)
			unref();

		if (from.reference) {
			reference = from.reference;
			reference->reference();
		} else {
			reference = nullptr;
		}
	}

	template<class T_Other>
	void operator=(const Ref<T_Other> &from)
	{
		if (reference)
			unref();

		if (from.reference) {
			reference = (T *) from.reference;
			reference->reference();
		} else {
			reference = nullptr;
		}
	}
	
	void operator=(const Variant &variant)
	{
		if (reference)
			unref();

		reference = (T *) (Object *) variant;
	}
	
	operator Variant() const
	{
		return Variant((Object *) reference);
	}
	
	template<class T_Other>
	Ref(const Ref<T_Other> &from)
	{
		if (from.reference) {
			reference = (T *) from.reference;
			reference->reference();
		} else {
			reference = nullptr;
		}
	}
	
	Ref(const Ref &from)
	{
		if (from.reference) {
			reference = from.reference;
			reference->reference();
		} else {
			reference = nullptr;
		}
	}


	Ref(T *r)
	{
		reference = r;
	}
	
	template<class T_Other>
	Ref(T_Other *r) : Ref((T *) r) {}

	Ref(const Variant &variant)
	{
		reference = (T *) (Object *) variant;
	}

	inline bool is_valid() const { return reference != nullptr; }
	inline bool is_null() const { return reference == nullptr; }
	
	void unref()
	{
		if (reference && reference->unreference()) {
			godot::api->godot_object_destroy((godot_object *) reference);
		}
		reference = nullptr;
	}
	
	void instance()
	{
		unref();

		reference = new T;
	}

	Ref()
	{
		reference = nullptr;
	}
	
	~Ref()
	{
		unref();
	}
};

}

#endif
