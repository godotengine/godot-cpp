/**************************************************************************/
/*  bindings.hpp                                                          */
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

#ifndef GODOT_MEMBER_BINDINGS_HPP
#define GODOT_MEMBER_BINDINGS_HPP

#define GDBIND(m_class, m_name, m_properties) 	\
const char* getter_##m_name = "get_" #m_name;			\
const char* setter_##m_name = "set_" #m_name;			\
ClassDB::bind_method(D_METHOD(getter_##m_name), &m_class::get_##m_name);	\
ClassDB::bind_method(D_METHOD(setter_##m_name, "p_temp"), &m_class::set_##m_name);	\
ClassDB::add_property(#m_class, m_properties, setter_##m_name, getter_##m_name); \


#define GDPROP(m_type, m_name) /**********************************************/ \
private:                                                                        \
    m_type m_name;                                                              \
                                                                                \
public:                                                                         \
    inline void set_##m_name(const m_type p_temp) { m_name = p_temp; }          \
    inline m_type get_##m_name() const { return m_name; }                       \


#endif // GODOT_MEMBER_BINDINGS_HPP