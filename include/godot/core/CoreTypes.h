#ifndef CORETYPES_H
#define CORETYPES_H

#include "Defs.h"

#include "Array.h"
#include "Basis.h"
#include "Color.h"
#include "Dictionary.h"
#include "Image.h"
#include "InputEvent.h"
#include "NodePath.h"
#include "Plane.h"
#include "PoolArrays.h"
#include "Quat.h"
#include "Rect2.h"
#include "Rect3.h"
#include "RID.h"
#include "String.h"
#include "Transform.h"
#include "Transform2D.h"
#include "Variant.h"
#include "Vector2.h"
#include "Vector3.h"


// This is ugly, sorry
// but those two casts need to be the last thing EVEEEEER
//
// if you can make it prettier feel free to open a Pull Request on
// https://github.com/GodotNativeTools/cpp_bindings
// or message someone on the IRC freenode #godotengine-devel
namespace godot {


Variant::operator Dictionary() const
{
	godot_dictionary d = godot_variant_as_dictionary(&_godot_variant);
	return *(Dictionary *) &d;
}



Variant::operator Array() const
{
	godot_array s = godot_variant_as_array(&_godot_variant);
	return *(Array *) &s;
}

}


#endif // CORETYPES_H
