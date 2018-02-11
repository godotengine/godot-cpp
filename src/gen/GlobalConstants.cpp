#include <GlobalConstants.hpp>


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


void *GlobalConstants::___get_type_tag()
{
	return (void *) &GlobalConstants::___get_type_tag;
}

void *GlobalConstants::___get_base_type_tag()
{
	return (void *) nullptr;
}

GlobalConstants *GlobalConstants::_singleton = NULL;


GlobalConstants::GlobalConstants() {
	_owner = godot::api->godot_global_get_singleton((char *) "GlobalConstants");
}


}