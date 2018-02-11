#ifndef GODOT_CPP_OBJECT_HPP
#define GODOT_CPP_OBJECT_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/TagDB.hpp>

namespace godot {

class Reference;
class Object;

class Object : public _Wrapped {
public: enum { ___CLASS_IS_SCRIPT = 0, };
private:

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "Object"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum ConnectFlags {
		CONNECT_PERSIST = 2,
		CONNECT_DEFERRED = 1,
		CONNECT_ONESHOT = 4,
	};

	// constants
	const static int NOTIFICATION_POSTINITIALIZE = 0;
	const static int NOTIFICATION_PREDELETE = 1;


	static Object *_new();

	// methods
#ifndef GODOT_CPP_NO_OBJECT_CAST
	template<class T>
	static T *cast_to(const Object *obj);
#endif

	void free();
	void _notification(const int64_t what);
	bool _set(const String property, const Variant value);
	void _get(const String property);
	Array _get_property_list();
	void _init();
	String get_class() const;
	bool is_class(const String type) const;
	void set(const String property, const Variant value);
	Variant get(const String property) const;
	void set_indexed(const NodePath property, const Variant value);
	Variant get_indexed(const NodePath property) const;
	Array get_property_list() const;
	Array get_method_list() const;
	void notification(const int64_t what, const bool reversed = false);
	int64_t get_instance_id() const;
	void set_script(const Reference *script);
	Reference *get_script() const;
	void set_meta(const String name, const Variant value);
	Variant get_meta(const String name) const;
	bool has_meta(const String name) const;
	PoolStringArray get_meta_list() const;
	void add_user_signal(const String signal, const Array arguments = Array());
	bool has_user_signal(const String signal) const;
	Variant emit_signal(const String signal, const Array& __var_args = Array());
	Variant call(const String method, const Array& __var_args = Array());
	Variant call_deferred(const String method, const Array& __var_args = Array());
	Variant callv(const String method, const Array arg_array);
	bool has_method(const String method) const;
	Array get_signal_list() const;
	Array get_signal_connection_list(const String signal) const;
	Array get_incoming_connections() const;
	Error connect(const String signal, const Object *target, const String method, const Array binds = Array(), const int64_t flags = 0);
	void disconnect(const String signal, const Object *target, const String method);
	bool is_connected(const String signal, const Object *target, const String method) const;
	void set_block_signals(const bool enable);
	bool is_blocking_signals() const;
	void property_list_changed_notify();
	void set_message_translation(const bool enable);
	bool can_translate_messages() const;
	String tr(const String message) const;
	bool is_queued_for_deletion() const;
	template <class... Args> Variant emit_signal(const String signal, Args... args){
		return emit_signal(signal, Array::make(args...));
	}
	template <class... Args> Variant call(const String method, Args... args){
		return call(method, Array::make(args...));
	}
	template <class... Args> Variant call_deferred(const String method, Args... args){
		return call_deferred(method, Array::make(args...));
	}

};

}

#endif