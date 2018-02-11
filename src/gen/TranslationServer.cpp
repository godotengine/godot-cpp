#include <TranslationServer.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"


#include <Translation.hpp>


namespace godot {


void *TranslationServer::___get_type_tag()
{
	return (void *) &TranslationServer::___get_type_tag;
}

void *TranslationServer::___get_base_type_tag()
{
	return (void *) &Object::___get_type_tag;
}

TranslationServer *TranslationServer::_singleton = NULL;


TranslationServer::TranslationServer() {
	_owner = godot::api->godot_global_get_singleton((char *) "TranslationServer");
}


void TranslationServer::set_locale(const String locale) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TranslationServer", "set_locale");
	}
	___godot_icall_void_String(mb, (const Object *) this, locale);
}

String TranslationServer::get_locale() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TranslationServer", "get_locale");
	}
	return ___godot_icall_String(mb, (const Object *) this);
}

String TranslationServer::get_locale_name(const String locale) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TranslationServer", "get_locale_name");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, locale);
}

String TranslationServer::translate(const String message) const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TranslationServer", "translate");
	}
	return ___godot_icall_String_String(mb, (const Object *) this, message);
}

void TranslationServer::add_translation(const Ref<Translation> translation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TranslationServer", "add_translation");
	}
	___godot_icall_void_Object(mb, (const Object *) this, translation.ptr());
}

void TranslationServer::remove_translation(const Ref<Translation> translation) {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TranslationServer", "remove_translation");
	}
	___godot_icall_void_Object(mb, (const Object *) this, translation.ptr());
}

void TranslationServer::clear() {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("TranslationServer", "clear");
	}
	___godot_icall_void(mb, (const Object *) this);
}

}