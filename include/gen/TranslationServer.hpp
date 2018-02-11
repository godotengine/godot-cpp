#ifndef GODOT_CPP_TRANSLATIONSERVER_HPP
#define GODOT_CPP_TRANSLATIONSERVER_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include <Object.hpp>
namespace godot {

class Translation;

class TranslationServer : public Object {
	static TranslationServer *_singleton;

	TranslationServer();

public:

	static void *___get_type_tag();
	static void *___get_base_type_tag();
	static inline TranslationServer *get_singleton()
	{
		if (!TranslationServer::_singleton) {
			TranslationServer::_singleton = new TranslationServer;
		}
		return TranslationServer::_singleton;
	}

	static inline const char *___get_class_name() { return (const char *) "TranslationServer"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o); }

	// enums

	// constants

	// methods
	void set_locale(const String locale);
	String get_locale() const;
	String get_locale_name(const String locale) const;
	String translate(const String message) const;
	void add_translation(const Ref<Translation> translation);
	void remove_translation(const Ref<Translation> translation);
	void clear();

};

}

#endif