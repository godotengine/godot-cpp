#include <AudioStream.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *AudioStream::___get_type_tag()
{
	return (void *) &AudioStream::___get_type_tag;
}

void *AudioStream::___get_base_type_tag()
{
	return (void *) &Resource::___get_type_tag;
}

double AudioStream::get_length() const {
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = godot::api->godot_method_bind_get_method("AudioStream", "get_length");
	}
	return ___godot_icall_float(mb, (const Object *) this);
}

}