/**************************************************************************/
/*  defs.hpp                                                              */
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

/**
 * Basic definitions and simple functions to be used everywhere.
 */

// IWYU pragma: always_keep

// Ensure that C++ standard is at least C++17.
// If on MSVC, also ensures that the `Zc:__cplusplus` flag is present.
static_assert(__cplusplus >= 201703L, "Minimum of C++17 required.");

// IWYU pragma: begin_exports

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <type_traits>
#include <utility>

#if __has_include(<godot_cpp/core/version.hpp>)
#include <godot_cpp/core/version.hpp>
#endif

// IWYU pragma: end_exports

namespace godot {

#if defined(__has_feature)
/**
 * Expands to the compiler's availability result for the named feature.
 */
#define GD_HAS_FEATURE(m_feature) __has_feature(m_feature)
#else
/**
 * Reports zero when the compiler has no feature query operator.
 */
#define GD_HAS_FEATURE(m_feature) 0
#endif

#if defined(__has_cpp_attribute)
/**
 * Expands to the compiler's support value for the supplied C++ attribute.
 */
#define GD_HAS_CPP_ATTRIBUTE(m_feature) __has_cpp_attribute(m_feature)
#else
/**
 * Reports zero when the compiler has no C++ attribute query operator.
 */
#define GD_HAS_CPP_ATTRIBUTE(m_feature) 0
#endif

#if (GD_HAS_FEATURE(address_sanitizer) || defined(__SANITIZE_ADDRESS__)) && !defined(ASAN_ENABLED)
#error Address sanitizer was enabled without defining `ASAN_ENABLED`
#endif

#if (GD_HAS_FEATURE(leak_sanitizer) || defined(__SANITIZE_LEAKS__)) && !defined(LSAN_ENABLED)
#error Leak sanitizer was enabled without defining `LSAN_ENABLED`
#endif

#if (GD_HAS_FEATURE(memory_sanitizer) || defined(__SANITIZE_MEMORY__)) && !defined(MSAN_ENABLED)
#error Memory sanitizer was enabled without defining `MSAN_ENABLED`
#endif

#if (GD_HAS_FEATURE(thread_sanitizer) || defined(__SANITIZE_THREAD__)) && !defined(TSAN_ENABLED)
#error Thread sanitizer was enabled without defining `TSAN_ENABLED`
#endif

#if (GD_HAS_FEATURE(undefined_behavior_sanitizer) || defined(__UNDEFINED_SANITIZER__)) && !defined(UBSAN_ENABLED)
#error Undefined behavior sanitizer was enabled without defining `UBSAN_ENABLED`
#endif

#if !defined(GDE_EXPORT)
#if defined(_WIN32)
/**
 * Marks a Windows extension entry point for export from the DLL.
 */
#define GDE_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
/**
 * Gives an extension entry point default symbol visibility on GCC-compatible platforms.
 */
#define GDE_EXPORT __attribute__((visibility("default")))
#else
/**
 * Leaves the export declaration unannotated on other compilers.
 */
#define GDE_EXPORT
#endif
#endif

// Turn argument to string constant:
// https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html#Stringizing
#ifndef _STR
/**
 * Stringizes the supplied token sequence without expanding it first.
 */
#define _STR(m_x) #m_x
/**
 * Expands the argument before stringizing its tokens.
 */
#define _MKSTR(m_x) _STR(m_x)
#endif

// Should always inline no matter what.
#ifndef _ALWAYS_INLINE_
#if defined(__GNUC__)
/**
 * Requests forced inlining and declares the function inline on GCC-compatible compilers.
 */
#define _ALWAYS_INLINE_ __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
/**
 * Requests forced inlining through the MSVC declaration specifier.
 */
#define _ALWAYS_INLINE_ __forceinline
#else
/**
 * Declares the function inline on compilers without a special forced-inline branch.
 */
#define _ALWAYS_INLINE_ inline
#endif
#endif

// Should always inline, except in dev builds because it makes debugging harder,
// or `size_enabled` builds where inlining is actively avoided.
#ifndef _FORCE_INLINE_
#if defined(DEV_ENABLED) || defined(SIZE_EXTRA)
/**
 * Declares a function inline without a forced-inlining attribute in development or size-focused builds.
 */
#define _FORCE_INLINE_ inline
#else
/**
 * Requests forced inlining in builds that enable it.
 */
#define _FORCE_INLINE_ _ALWAYS_INLINE_
#endif
#endif

// Should never inline.
#ifndef _NO_INLINE_
#if defined(__GNUC__)
/**
 * Requests that the GCC-compatible compiler keep the function out of line.
 */
#define _NO_INLINE_ __attribute__((noinline))
#elif defined(_MSC_VER)
/**
 * Requests that MSVC keep the function out of line.
 */
#define _NO_INLINE_ __declspec(noinline)
#else
/**
 * Leaves the declaration unannotated when there is no supported no-inline specifier.
 */
#define _NO_INLINE_
#endif
#endif

// In some cases [[nodiscard]] will get false positives,
// we can prevent the warning in specific cases by preceding the call with a cast.
#ifndef _ALLOW_DISCARD_
/**
 * Explicitly discards an expression result through a cast to void.
 */
#define _ALLOW_DISCARD_ (void)
#endif

#if GD_HAS_CPP_ATTRIBUTE(clang::lifetimebound)
/**
 * Tells Clang that returned references or pointers can depend on the annotated object's lifetime.
 */
#define _LIFETIME_BOUND_ [[clang::lifetimebound]]
#elif GD_HAS_CPP_ATTRIBUTE(gnu::lifetimebound)
/**
 * Uses the GNU lifetime-bound attribute to associate a result with the annotated input's lifetime.
 */
#define _LIFETIME_BOUND_ [[gnu::lifetimebound]]
#elif GD_HAS_CPP_ATTRIBUTE(msvc::lifetimebound)
/**
 * Uses the MSVC lifetime-bound attribute to associate a result with the annotated input's lifetime.
 */
#define _LIFETIME_BOUND_ [[msvc::lifetimebound]]
#elif GD_HAS_CPP_ATTRIBUTE(lifetimebound)
/**
 * Uses the unqualified lifetime-bound attribute supported by the compiler.
 */
#define _LIFETIME_BOUND_ [[lifetimebound]]
#else
/**
 * Leaves the declaration unannotated when no lifetime-bound attribute is available.
 */
#define _LIFETIME_BOUND_
#endif

// Windows badly defines a lot of stuff we'll never use. Undefine it.
#ifdef _WIN32
#undef min // override standard definition
#undef max // override standard definition
#undef ERROR // override (really stupid) wingdi.h standard definition
#undef DELETE // override (another really stupid) winnt.h standard definition
#undef MessageBox // override winuser.h standard definition
#undef Error
#undef OK
#undef CONNECT_DEFERRED // override from Windows SDK, clashes with Object enum
#undef MemoryBarrier
#undef MONO_FONT
#endif

// Make room for our constexpr's below by overriding potential system-specific macros.
#undef SIGN
#undef MIN
#undef MAX
#undef CLAMP

/**
 * Returns one, minus one, or zero according to the input's comparison with zero.
 */
template <typename T>
constexpr const T SIGN(const T p_value) {
	return p_value > 0 ? +1.0f : (p_value < 0 ? -1.0f : 0.0f);
}

/**
 * Returns the smaller value after the comparison. Equal values select the right operand.
 */
template <typename T, typename T2>
constexpr auto MIN(const T p_left, const T2 p_right) {
	return p_left < p_right ? p_left : p_right;
}

/**
 * Returns the larger value after the comparison. Equal values select the right operand.
 */
template <typename T, typename T2>
constexpr auto MAX(const T p_left, const T2 p_right) {
	return p_left > p_right ? p_left : p_right;
}

/**
 * Restricts the value to the inclusive interval between the supplied lower and upper bounds.
 */
template <typename T, typename T2, typename T3>
constexpr auto CLAMP(const T p_value, const T2 p_min, const T3 p_max) {
	return p_value < p_min ? p_min : (p_value > p_max ? p_max : p_value);
}

// Like std::size, but without requiring any additional includes.
/**
 * Returns the compile-time number of elements in a built-in array.
 */
template <typename T, size_t SIZE>
constexpr size_t std_size(const T (&)[SIZE]) {
	return SIZE;
}

// Generic swap template.
#ifndef SWAP
/**
 * Exchanges the values through `std::swap`.
 */
#define SWAP(m_x, m_y) std::swap((m_x), (m_y))
#endif // SWAP

// Swap 16, 32 and 64 bits value for endianness.
#if defined(__GNUC__)
/**
 * Reverses the two bytes of a 16-bit integer using the compiler intrinsic.
 */
#define BSWAP16(x) __builtin_bswap16(x)
/**
 * Reverses the four bytes of a 32-bit integer using the compiler intrinsic.
 */
#define BSWAP32(x) __builtin_bswap32(x)
/**
 * Reverses the eight bytes of a 64-bit integer using the compiler intrinsic.
 */
#define BSWAP64(x) __builtin_bswap64(x)
#elif defined(_MSC_VER)
/**
 * Reverses the bytes of a 16-bit integer using the MSVC intrinsic.
 */
#define BSWAP16(x) _byteswap_ushort(x)
/**
 * Reverses the bytes of a 32-bit integer using the MSVC intrinsic.
 */
#define BSWAP32(x) _byteswap_ulong(x)
/**
 * Reverses the bytes of a 64-bit integer using the MSVC intrinsic.
 */
#define BSWAP64(x) _byteswap_uint64(x)
#else
/**
 * Reverses the bytes of a 16-bit integer with shift operations.
 */
static inline uint16_t BSWAP16(uint16_t x) {
	return (x >> 8) | (x << 8);
}

/**
 * Reverses the bytes of a 32-bit integer with shift operations.
 */
static inline uint32_t BSWAP32(uint32_t x) {
	return ((x << 24) | ((x << 8) & 0x00FF0000) | ((x >> 8) & 0x0000FF00) | (x >> 24));
}

/**
 * Reverses the bytes of a 64-bit integer with shift operations.
 */
static inline uint64_t BSWAP64(uint64_t x) {
	x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
	x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
	x = (x & 0x00FF00FF00FF00FF) << 8 | (x & 0xFF00FF00FF00FF00) >> 8;
	return x;
}
#endif

// Generic comparator used in Map, List, etc.
/**
 * Default strict ordering predicate for containers and sorting helpers.
 */
template <typename T>
struct Comparator {
	/**
	 * Returns whether the first value precedes the second according to `operator<`.
	 */
	_ALWAYS_INLINE_ bool operator()(const T &p_a, const T &p_b) const { return (p_a < p_b); }
};

// Global lock macro, relies on the static Mutex::_global_mutex.
/**
 * Acquires the binding's shared lock.
 */
void _global_lock();
/**
 * Releases the binding's shared lock acquired by the calling thread.
 */
void _global_unlock();

/**
 * Holds the binding's shared lock for the lifetime of the guard.
 */
struct _GlobalLock {
	/**
	 * Acquires the binding's shared lock.
	 */
	_GlobalLock() { _global_lock(); }
	/**
	 * Releases the binding's shared lock.
	 */
	~_GlobalLock() { _global_unlock(); }
};

/**
 * Declares a scoped guard that acquires the binding's shared lock until scope exit.
 */
#define GLOBAL_LOCK_FUNCTION _GlobalLock _global_lock_;

#if defined(__GNUC__)
/**
 * Converts the condition to a boolean and indicates that the true branch is expected.
 */
#define likely(x) __builtin_expect(!!(x), 1)
/**
 * Converts the condition to a boolean and indicates that the false branch is expected.
 */
#define unlikely(x) __builtin_expect(!!(x), 0)
#else
/**
 * Expands to the original condition on compilers without the branch hint.
 */
#define likely(x) x
/**
 * Expands to the original condition on compilers without the branch hint.
 */
#define unlikely(x) x
#endif

#if defined(__GNUC__)
/**
 * Marks argument two as a printf format string without checking a variadic argument list.
 */
#define _PRINTF_FORMAT_ATTRIBUTE_2_0 __attribute__((format(printf, 2, 0)))
/**
 * Marks argument two as the printf format string and starts checking variadic values at argument three.
 */
#define _PRINTF_FORMAT_ATTRIBUTE_2_3 __attribute__((format(printf, 2, 3)))
#else
/**
 * Omits the format-only attribute on unsupported compilers.
 */
#define _PRINTF_FORMAT_ATTRIBUTE_2_0
/**
 * Omits the variadic format checking attribute on unsupported compilers.
 */
#define _PRINTF_FORMAT_ATTRIBUTE_2_3
#endif

// This is needed due to a strange OpenGL API that expects a pointer
// type for an argument that is actually an offset.
/**
 * Encodes an integer byte offset in a pointer-typed argument for APIs that use that convention.
 */
#define CAST_INT_TO_UCHAR_PTR(ptr) ((uint8_t *)(uintptr_t)(ptr))

// Home-made index sequence trick, so it can be used everywhere without the costly include of std::tuple.
// https://stackoverflow.com/questions/15014096/c-index-of-type-during-variadic-template-expansion
/**
 * Holds a compile-time list of indices used to expand parameter packs.
 */
template <size_t... Is>
struct IndexSequence {};

/**
 * Prepends the indices below `N` until the sequence builder reaches zero.
 */
template <size_t N, size_t... Is>
struct BuildIndexSequence : BuildIndexSequence<N - 1, N - 1, Is...> {};

/**
 * Ends recursion and exposes the accumulated compile-time indices.
 */
template <size_t... Is>
struct BuildIndexSequence<0, Is...> : IndexSequence<Is...> {};

// Limit the depth of recursive algorithms when dealing with Array/Dictionary
/**
 * Bounds recursive processing of nested arrays and dictionaries.
 */
#define MAX_RECURSION 100

// Macro GD_IS_DEFINED() allows to check if a macro is defined. It needs to be defined to anything (say 1) to work.
/**
 * Inserts a comma for a flag that expands to the token `1`.
 */
#define __GDARG_PLACEHOLDER_1 false,
/**
 * Extracts the second preprocessor argument during flag detection.
 */
#define __gd_take_second_arg(__ignored, val, ...) val
/**
 * Selects true when placeholder expansion introduced an argument separator, and false otherwise.
 */
#define ____gd_is_defined(arg1_or_junk) __gd_take_second_arg(arg1_or_junk true, false)
/**
 * Resolves the placeholder corresponding to the expanded flag token.
 */
#define ___gd_is_defined(val) ____gd_is_defined(__GDARG_PLACEHOLDER_##val)
/**
 * Expands to true when the supplied preprocessor flag expands to `1`.
 */
#define GD_IS_DEFINED(x) ___gd_is_defined(x)

// Whether the default value of a type is just all-0 bytes.
// This can most commonly be exploited by using memset for these types instead of loop-construct.
// Trivially constructible types are also zero-constructible.
/**
 * Indicates whether all-zero bytes represent an initialized value of the type.
 */
template <typename T>
struct is_zero_constructible : std::is_trivially_constructible<T> {};

/**
 * Uses the unqualified type's zero-initialization result for const types.
 */
template <typename T>
struct is_zero_constructible<const T> : is_zero_constructible<T> {};

/**
 * Uses the unqualified type's zero-initialization result for volatile types.
 */
template <typename T>
struct is_zero_constructible<volatile T> : is_zero_constructible<T> {};

/**
 * Uses the unqualified type's zero-initialization result for const volatile types.
 */
template <typename T>
struct is_zero_constructible<const volatile T> : is_zero_constructible<T> {};

/**
 * Exposes the zero-initialization trait as a constant expression.
 */
template <typename T>
inline constexpr bool is_zero_constructible_v = is_zero_constructible<T>::value;

#if GD_HAS_CPP_ATTRIBUTE(gnu::warn_unused)
// https://gcc.gnu.org/onlinedocs/gcc/C_002b_002b-Attributes.html#index-warn_005funused
/**
 * Enables the GNU warning for unused values of the annotated type.
 */
#define _WARN_UNUSED_ [[gnu::warn_unused]]
#else
/**
 * Leaves the type unannotated when the GNU unused diagnostic attribute is unavailable.
 */
#define _WARN_UNUSED_
#endif

// Warning suppression helper macros.
#if defined(__clang__)
/**
 * Emits a pragma for Clang from within a macro expansion.
 */
#define GODOT_CLANG_PRAGMA(m_content) _Pragma(#m_content)
/**
 * Saves the current Clang warning state.
 */
#define GODOT_CLANG_WARNING_PUSH GODOT_CLANG_PRAGMA(clang diagnostic push)
/**
 * Disables the specified Clang warning.
 */
#define GODOT_CLANG_WARNING_IGNORE(m_warning) GODOT_CLANG_PRAGMA(clang diagnostic ignored m_warning)
/**
 * Restores the previously saved Clang warning state.
 */
#define GODOT_CLANG_WARNING_POP GODOT_CLANG_PRAGMA(clang diagnostic pop)
/**
 * Saves Clang's warning state and disables the supplied warning.
 */
#define GODOT_CLANG_WARNING_PUSH_AND_IGNORE(m_warning) GODOT_CLANG_WARNING_PUSH GODOT_CLANG_WARNING_IGNORE(m_warning)
#else
/**
 * Expands to nothing when the Clang pragma is unavailable.
 */
#define GODOT_CLANG_PRAGMA(m_content)
/**
 * Expands to nothing when the Clang warning-state save is unavailable.
 */
#define GODOT_CLANG_WARNING_PUSH
/**
 * Expands to nothing when the Clang warning suppression is unavailable.
 */
#define GODOT_CLANG_WARNING_IGNORE(m_warning)
/**
 * Expands to nothing when the Clang warning-state restore is unavailable.
 */
#define GODOT_CLANG_WARNING_POP
/**
 * Expands to nothing when the Clang scoped warning suppression is unavailable.
 */
#define GODOT_CLANG_WARNING_PUSH_AND_IGNORE(m_warning)
#endif

#if defined(__GNUC__) && !defined(__clang__)
/**
 * Emits a pragma for GCC from within a macro expansion.
 */
#define GODOT_GCC_PRAGMA(m_content) _Pragma(#m_content)
/**
 * Saves the current GCC warning state.
 */
#define GODOT_GCC_WARNING_PUSH GODOT_GCC_PRAGMA(GCC diagnostic push)
/**
 * Disables the specified GCC warning.
 */
#define GODOT_GCC_WARNING_IGNORE(m_warning) GODOT_GCC_PRAGMA(GCC diagnostic ignored m_warning)
/**
 * Restores the previously saved GCC warning state.
 */
#define GODOT_GCC_WARNING_POP GODOT_GCC_PRAGMA(GCC diagnostic pop)
/**
 * Saves GCC's warning state and disables the supplied warning.
 */
#define GODOT_GCC_WARNING_PUSH_AND_IGNORE(m_warning) GODOT_GCC_WARNING_PUSH GODOT_GCC_WARNING_IGNORE(m_warning)
#else
/**
 * Expands to nothing when the GCC pragma is unavailable.
 */
#define GODOT_GCC_PRAGMA(m_content)
/**
 * Expands to nothing when the GCC warning-state save is unavailable.
 */
#define GODOT_GCC_WARNING_PUSH
/**
 * Expands to nothing when the GCC warning suppression is unavailable.
 */
#define GODOT_GCC_WARNING_IGNORE(m_warning)
/**
 * Expands to nothing when the GCC warning-state restore is unavailable.
 */
#define GODOT_GCC_WARNING_POP
/**
 * Expands to nothing when the GCC scoped warning suppression is unavailable.
 */
#define GODOT_GCC_WARNING_PUSH_AND_IGNORE(m_warning)
#endif

#if defined(_MSC_VER) && !defined(__clang__)
/**
 * Emits a pragma for MSVC from within a macro expansion.
 */
#define GODOT_MSVC_PRAGMA(m_command) __pragma(m_command)
/**
 * Saves the current MSVC warning state.
 */
#define GODOT_MSVC_WARNING_PUSH GODOT_MSVC_PRAGMA(warning(push))
/**
 * Disables the specified MSVC warning.
 */
#define GODOT_MSVC_WARNING_IGNORE(m_warning) GODOT_MSVC_PRAGMA(warning(disable : m_warning))
/**
 * Restores the previously saved MSVC warning state.
 */
#define GODOT_MSVC_WARNING_POP GODOT_MSVC_PRAGMA(warning(pop))
/**
 * Saves MSVC's warning state and disables the supplied warning.
 */
#define GODOT_MSVC_WARNING_PUSH_AND_IGNORE(m_warning) GODOT_MSVC_WARNING_PUSH GODOT_MSVC_WARNING_IGNORE(m_warning)
#else
/**
 * Expands to nothing when the MSVC pragma is unavailable.
 */
#define GODOT_MSVC_PRAGMA(m_command)
/**
 * Expands to nothing when the MSVC warning-state save is unavailable.
 */
#define GODOT_MSVC_WARNING_PUSH
/**
 * Expands to nothing when the MSVC warning suppression is unavailable.
 */
#define GODOT_MSVC_WARNING_IGNORE(m_warning)
/**
 * Expands to nothing when the MSVC warning-state restore is unavailable.
 */
#define GODOT_MSVC_WARNING_POP
/**
 * Expands to nothing when the MSVC scoped warning suppression is unavailable.
 */
#define GODOT_MSVC_WARNING_PUSH_AND_IGNORE(m_warning)
#endif

// Deprecation warning suppression helper macros.
#if defined(__clang__)
/**
 * Saves Clang's warning state and disables deprecated declaration diagnostics.
 */
#define GODOT_PUSH_IGNORE_DEPRECATION() GODOT_CLANG_WARNING_PUSH_AND_IGNORE("-Wdeprecated-declarations")
/**
 * Restores Clang's previous warning state.
 */
#define GODOT_POP_IGNORE_DEPRECATION() GODOT_CLANG_WARNING_POP
#endif

#if defined(__GNUC__) && !defined(__clang__)
/**
 * Saves GCC's warning state and disables deprecated declaration diagnostics.
 */
#define GODOT_PUSH_IGNORE_DEPRECATION() GODOT_GCC_WARNING_PUSH_AND_IGNORE("-Wdeprecated-declarations")
/**
 * Restores GCC's previous warning state.
 */
#define GODOT_POP_IGNORE_DEPRECATION() GODOT_GCC_WARNING_POP
#endif

#if defined(_MSC_VER) && !defined(__clang__)
/**
 * Saves MSVC's warning state and disables warning 4996.
 */
#define GODOT_PUSH_IGNORE_DEPRECATION() GODOT_MSVC_WARNING_PUSH_AND_IGNORE(4996)
/**
 * Restores MSVC's previous warning state.
 */
#define GODOT_POP_IGNORE_DEPRECATION() GODOT_MSVC_WARNING_POP
#endif

/**
 * Reports an incomplete type when the size expression cannot be formed.
 */
template <typename T, typename = void>
struct is_fully_defined : std::false_type {};

/**
 * Matches a type for which the compiler can form a size expression.
 */
template <typename T>
struct is_fully_defined<T, std::void_t<decltype(sizeof(T))>> : std::true_type {};

/**
 * Exposes the type completeness test as a constant expression.
 */
template <typename T>
constexpr bool is_fully_defined_v = is_fully_defined<T>::value;

#ifndef SCU_BUILD_ENABLED
/// Enforces the requirement that a class is not fully defined.
/// This can be used to reduce include coupling and keep compile times low.
/// The check must be made at the top of the corresponding .cpp file of a header.
#define STATIC_ASSERT_INCOMPLETE_TYPE(m_keyword, m_type) \
	m_keyword m_type; \
	static_assert(!is_fully_defined_v<m_type>, #m_type " was unexpectedly fully defined. Please check the include hierarchy of '" __FILE__ "' and remove includes that resolve the " #m_keyword ".");
#else
/**
 * Omits the incomplete-type assertion in single compilation unit builds, where another source file may have included the definition.
 */
#define STATIC_ASSERT_INCOMPLETE_TYPE(m_keyword, m_type)
#endif

/**
 * Returns the expanded name from the concatenation helper.
 */
#define _GD_VARNAME_CONCAT_B_(m_ignore, m_name) m_name
/**
 * Joins the three supplied tokens into one identifier.
 */
#define _GD_VARNAME_CONCAT_A_(m_a, m_b, m_c) _GD_VARNAME_CONCAT_B_(hello there, m_a##m_b##m_c)
/**
 * Expands the identifier components before passing them to the token join.
 */
#define _GD_VARNAME_CONCAT_(m_a, m_b, m_c) _GD_VARNAME_CONCAT_A_(m_a, m_b, m_c)
/**
 * Appends the current preprocessor counter to the supplied identifier prefix.
 */
#define GD_UNIQUE_NAME(m_name) _GD_VARNAME_CONCAT_(m_name, _, __COUNTER__)

} //namespace godot
