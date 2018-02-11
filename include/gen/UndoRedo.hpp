#ifndef GODOT_CPP_UNDOREDO_HPP
#define GODOT_CPP_UNDOREDO_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {

class Object;

class UndoRedo : public Object {
public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline const char *___get_class_name() { return (const char *) "UndoRedo"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums
	enum MergeMode {
		MERGE_DISABLE = 0,
		MERGE_ALL = 2,
		MERGE_ENDS = 1,
	};

	// constants


	static UndoRedo *_new();

	// methods
	void create_action(const String name, const int64_t merge_mode = 0);
	void commit_action();
	Variant add_do_method(const Object *object, const String method, const Array& __var_args = Array());
	Variant add_undo_method(const Object *object, const String method, const Array& __var_args = Array());
	void add_do_property(const Object *object, const String property, const Variant value);
	void add_undo_property(const Object *object, const String property, const Variant value);
	void add_do_reference(const Object *object);
	void add_undo_reference(const Object *object);
	void clear_history();
	String get_current_action_name() const;
	int64_t get_version() const;
	void redo();
	void undo();
	template <class... Args> Variant add_do_method(const Object *object, const String method, Args... args){
		return add_do_method(object,method, Array::make(args...));
	}
	template <class... Args> Variant add_undo_method(const Object *object, const String method, Args... args){
		return add_undo_method(object,method, Array::make(args...));
	}

};

}

#endif