/**************************************************************************/
/*  converter.hpp                                                         */
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

#pragma once

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/method_ptrcall.hpp>
#include <godot_cpp/core/type_info.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <gdextension_interface.h>

#define GD_REGISTER_CONVERSION(m_type, m_conv, m_to, m_from, m_var_type)      \
	namespace godot {                                                         \
	template <>                                                               \
	struct VariantCaster<m_type> {                                            \
		_FORCE_INLINE_ static m_type cast(const Variant &p_variant) {         \
			return m_to(p_variant);                                           \
		}                                                                     \
		template <>                                                           \
		struct VariantCaster<m_type &> {                                      \
			_FORCE_INLINE_ static m_type cast(const Variant &p_variant) {     \
				return m_to(p_variant);                                       \
			}                                                                 \
			template <>                                                       \
			struct VariantCaster<const m_type &> {                            \
				_FORCE_INLINE_ static m_type cast(const Variant &p_variant) { \
					return m_to(p_variant);                                   \
				}                                                             \
				MAKE_TYPE_INFO(m_type, m_var_type)                            \
				MAKE_PTRARG_CONVERTER(m_type, m_conv, m_to, m_from);          \
			}

#define GD_REGISTER_CONVERSION_BY_REFERENCE(m_type, m_conv, m_to, m_from, m_var_type) \
	namespace godot {                                                                 \
	template <>                                                                       \
	struct VariantCaster<m_type> {                                                    \
		_FORCE_INLINE_ static m_type cast(const Variant &p_variant) {                 \
			return m_to(p_variant);                                                   \
		}                                                                             \
		template <>                                                                   \
		struct VariantCaster<m_type &> {                                              \
			_FORCE_INLINE_ static m_type cast(const Variant &p_variant) {             \
				return m_to(p_variant);                                               \
			}                                                                         \
			template <>                                                               \
			struct VariantCaster<const m_type &> {                                    \
				_FORCE_INLINE_ static m_type cast(const Variant &p_variant) {         \
					return m_to(p_variant);                                           \
				}                                                                     \
				MAKE_TYPE_INFO(m_type, m_var_type)                                    \
				MAKE_PTRARG_CONVERTER_BY_REFERENCE(m_type, m_conv, m_to, m_from);     \
			}
