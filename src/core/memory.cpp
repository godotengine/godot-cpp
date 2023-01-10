/**************************************************************************/
/*  memory.cpp                                                            */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include <godot_cpp/core/memory.hpp>

#include <godot_cpp/godot.hpp>

namespace godot {

void *Memory::alloc_static(size_t p_bytes) {
	return internal::gde_interface->mem_alloc(p_bytes);
}

void *Memory::realloc_static(void *p_memory, size_t p_bytes) {
	return internal::gde_interface->mem_realloc(p_memory, p_bytes);
}

void Memory::free_static(void *p_ptr) {
	internal::gde_interface->mem_free(p_ptr);
}

_GlobalNil::_GlobalNil() {
	left = this;
	right = this;
	parent = this;
}

_GlobalNil _GlobalNilClass::_nil;

} // namespace godot

void *operator new(size_t p_size, const char *p_description) {
	return godot::Memory::alloc_static(p_size);
}

void *operator new(size_t p_size, void *(*p_allocfunc)(size_t p_size)) {
	return p_allocfunc(p_size);
}

using namespace godot;

#ifdef _MSC_VER
void operator delete(void *p_mem, const char *p_description) {
	ERR_PRINT("Call to placement delete should not happen.");
	CRASH_NOW();
}

void operator delete(void *p_mem, void *(*p_allocfunc)(size_t p_size)) {
	ERR_PRINT("Call to placement delete should not happen.");
	CRASH_NOW();
}

void operator delete(void *p_mem, void *p_pointer, size_t check, const char *p_description) {
	ERR_PRINT("Call to placement delete should not happen.");
	CRASH_NOW();
}

#endif
