#ifndef TAGDB_HPP
#define TAGDB_HPP

namespace godot {

namespace _TagDB {

void register_type(const void *type_tag, const void *base_type_tag);
void register_global_type(const char *name, const void *type_tag, const void *base_type_tag);

bool is_type_compatible(const void *type_tag, const void *base_type_tag);

}

}

#endif // TAGDB_HPP
