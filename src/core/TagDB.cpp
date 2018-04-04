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

void register_global_type(const char *name, const void *type_tag, const void *base_type_tag)
{

	godot::nativescript_1_1_api->godot_nativescript_set_global_type_tag(godot::_RegisterState::language_index, name, type_tag);

	register_type(type_tag, base_type_tag);
}

bool is_type_compatible(const void *type_tag, const void *base_type_tag)
{
	if (type_tag == nullptr || base_type_tag == nullptr)
		return false;

	if (type_tag == base_type_tag)
		return true;

	const void *tag = type_tag;

	while (true) {
		if (tag == base_type_tag) {
			return true;
		}

		if (tag == nullptr) {
			return false;
		}

		tag = parent_to[tag];
	}

	return false;
}

}


}
