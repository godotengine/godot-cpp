#include "TagDB.hpp"

#include <unordered_map>

#include <GodotGlobal.hpp>

namespace godot {

namespace _TagDB {

std::unordered_map<const void *, const void *> parent_to;

void register_type(const void *type_tag, const void *base_type_tag)
{
	parent_to[type_tag] = base_type_tag;
}

bool is_type_known(const void *type_tag)
{
	return parent_to.find(type_tag) != parent_to.end();
}

void register_global_type(const char *name, const void *type_tag, const void *base_type_tag)
{

	godot::nativescript_1_1_api->godot_nativescript_set_global_type_tag(godot::_RegisterState::language_index, name, type_tag);

	register_type(type_tag, base_type_tag);
}

bool is_type_compatible(const void *ask_tag, const void *have_tag)
{

	if (have_tag == nullptr)
		return false;

	const void *tag = have_tag;

	while (tag != nullptr) {
		if (tag == ask_tag)
			return true;

		tag = parent_to[tag];
	}

	return false;
}

}


}
