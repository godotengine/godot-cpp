/**************************************************************************/
/*  hashfuncs.hpp                                                         */
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

#ifdef _MSC_VER
#include <intrin.h> // Needed for `__umulh` below.
#endif

#include <godot_cpp/core/math.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/templates/pair.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/node_path.hpp>
#include <godot_cpp/variant/rect2.hpp>
#include <godot_cpp/variant/rect2i.hpp>
#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector2i.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector3i.hpp>
#include <godot_cpp/variant/vector4.hpp>
#include <godot_cpp/variant/vector4i.hpp>

/**
 * Hashing functions
 */

namespace godot {
/**
 * Computes a 32-bit DJB2 hash of a null-terminated byte string.
 *
 * - `p_cstr` — Readable byte string. The first null terminator ends the input.
 */
_FORCE_INLINE_ uint32_t hash_djb2(const char *p_cstr) {
	const unsigned char *chr = (const unsigned char *)p_cstr;
	uint32_t hash = 5381;
	uint32_t c = *chr++;

	while (c) {
		hash = ((hash << 5) + hash) ^ c; /* hash * 33 ^ c */
		c = *chr++;
	}

	return hash;
}

/**
 * Extends the 32-bit DJB2 hash state with exactly the requested number of bytes, including zero bytes.
 *
 * - `p_buff` — Readable byte buffer to hash.
 * - `p_len` — Number of bytes read from the start of the buffer.
 * - `p_prev` — Initial hash state. Pass a previous result to continue hashing another buffer.
 */
_FORCE_INLINE_ uint32_t hash_djb2_buffer(const uint8_t *p_buff, int p_len, uint32_t p_prev = 5381) {
	uint32_t hash = p_prev;

	for (int i = 0; i < p_len; i++) {
		hash = ((hash << 5) + hash) ^ p_buff[i]; /* hash * 33 + c */
	}

	return hash;
}

/**
 * Multiplies the current DJB2 state by 33 and combines it with one word using XOR.
 *
 * - `p_in` — 32-bit word to add to the hash.
 * - `p_prev` — Initial or previous 32-bit hash state.
 */
_FORCE_INLINE_ uint32_t hash_djb2_one_32(uint32_t p_in, uint32_t p_prev = 5381) {
	return ((p_prev << 5) + p_prev) ^ p_in;
}

/**
 * Thomas Wang's 64-bit to 32-bit Hash function:
 * https://web.archive.org/web/20071223173210/https:/www.concentric.net/~Ttwang/tech/inthash.htm
 *
 * Mixes all 64 input bits into a 32-bit hash.
 *
 * - `p_int` — Unsigned 64-bit value to mix.
 */
_FORCE_INLINE_ uint32_t hash_one_uint64(const uint64_t p_int) {
	uint64_t v = p_int;
	v = (~v) + (v << 18); // v = (v << 18) - v - 1;
	v = v ^ (v >> 31);
	v = v * 21; // v = (v + (v << 2)) + (v << 4);
	v = v ^ (v >> 11);
	v = v + (v << 6);
	v = v ^ (v >> 22);
	return uint32_t(v);
}

/**
 * Mixes the seed and input with the 64-bit MurmurHash3 finalizer.
 *
 * - `p_key` — 64-bit value to hash.
 * - `p_seed` — Value combined with the input before the finalizer.
 */
_FORCE_INLINE_ uint64_t hash64_murmur3_64(uint64_t p_key, uint64_t p_seed) {
	p_key ^= p_seed;
	p_key ^= p_key >> 33;
	p_key *= 0xff51afd7ed558ccd;
	p_key ^= p_key >> 33;
	p_key *= 0xc4ceb9fe1a85ec53;
	p_key ^= p_key >> 33;
	return p_key;
}

/**
 * Default seed for the 32-bit MurmurHash3 helpers.
 */
#define HASH_MURMUR3_SEED 0x7F07C65
// Murmurhash3 32-bit version.
// All MurmurHash versions are public domain software, and the author disclaims all copyright to their code.

/**
 * Adds one 32-bit word to the MurmurHash3 state. Returns the state before finalization.
 *
 * - `p_in` — 32-bit word to mix into the state.
 * - `p_seed` — Initial or previous 32-bit MurmurHash3 state.
 */
_FORCE_INLINE_ uint32_t hash_murmur3_one_32(uint32_t p_in, uint32_t p_seed = HASH_MURMUR3_SEED) {
	p_in *= 0xcc9e2d51;
	p_in = (p_in << 15) | (p_in >> 17);
	p_in *= 0x1b873593;

	p_seed ^= p_in;
	p_seed = (p_seed << 13) | (p_seed >> 19);
	p_seed = p_seed * 5 + 0xe6546b64;

	return p_seed;
}

/**
 * Adds the low and then the high 32 bits of a word to the MurmurHash3 state.
 *
 * - `p_in` — 64-bit word split into two 32-bit words.
 * - `p_seed` — Initial or previous 32-bit MurmurHash3 state.
 */
_FORCE_INLINE_ uint32_t hash_murmur3_one_64(uint64_t p_in, uint32_t p_seed = HASH_MURMUR3_SEED) {
	p_seed = hash_murmur3_one_32(p_in & 0xFFFFFFFF, p_seed);
	return hash_murmur3_one_32(p_in >> 32, p_seed);
}

/**
 * Adds the floating-point bit pattern to a MurmurHash3 state. Both signed zeros hash alike, and all NaNs hash alike.
 *
 * - `p_in` — Floating-point value to mix into the hash.
 * - `p_seed` — Initial or previous 32-bit MurmurHash3 state.
 */
uint32_t hash_murmur3_one_float(float p_in, uint32_t p_seed = HASH_MURMUR3_SEED);
/**
 * Adds the floating-point bit pattern to a MurmurHash3 state. Both signed zeros hash alike, and all NaNs hash alike.
 *
 * - `p_in` — Floating-point value to mix into the hash.
 * - `p_seed` — Initial or previous 32-bit MurmurHash3 state.
 */
uint32_t hash_murmur3_one_double(double p_in, uint32_t p_seed = HASH_MURMUR3_SEED);

/**
 * Adds a real number to the MurmurHash3 state using the build's real-number precision.
 *
 * - `p_in` — Value hashed as single or double precision according to the build.
 * - `p_seed` — Initial or previous 32-bit MurmurHash3 state.
 */
_FORCE_INLINE_ uint32_t hash_murmur3_one_real(real_t p_in, uint32_t p_seed = HASH_MURMUR3_SEED) {
#ifdef REAL_T_IS_DOUBLE
	return hash_murmur3_one_double(p_in, p_seed);
#else
	return hash_murmur3_one_float(p_in, p_seed);
#endif
}

/**
 * Rotates the bits left within a 32-bit word.
 *
 * - `p_x` — Word whose bits are rotated.
 * - `p_r` — Count from 1 through 31.
 */
_FORCE_INLINE_ uint32_t hash_rotl32(uint32_t p_x, int8_t p_r) {
	return (p_x << p_r) | (p_x >> (32 - p_r));
}

/**
 * Finalizes a 32-bit MurmurHash3 state by mixing its bits across the result.
 *
 * - `p_h` — Intermediate 32-bit hash state to finalize.
 */
_FORCE_INLINE_ uint32_t hash_fmix32(uint32_t p_h) {
	p_h ^= p_h >> 16;
	p_h *= 0x85ebca6b;
	p_h ^= p_h >> 13;
	p_h *= 0xc2b2ae35;
	p_h ^= p_h >> 16;

	return p_h;
}

/**
 * Hashes a byte buffer with MurmurHash3, including its byte count in the final mix.
 *
 * - `p_key` — Start of the readable buffer.
 * - `p_length` — Number of bytes to read.
 * - `p_seed` — Initial 32-bit hash state.
 */
uint32_t hash_murmur3_buffer(const void *p_key, int p_length, uint32_t p_seed = HASH_MURMUR3_SEED);

/**
 * Adds a double to a 32-bit DJB2 state after reducing its bit pattern to a 32-bit hash. Signed zeros and NaNs are normalized.
 *
 * - `p_in` — Double to add to the hash.
 * - `p_prev` — Initial or previous 32-bit hash state.
 */
uint32_t hash_djb2_one_float(double p_in, uint32_t p_prev = 5381);
/**
 * Adds the normalized bit pattern of a double to a 64-bit DJB2 state. Signed zeros and NaNs are normalized.
 *
 * - `p_in` — Double to add to the hash.
 * - `p_prev` — Initial or previous 64-bit hash state.
 */
uint64_t hash_djb2_one_float_64(double p_in, uint64_t p_prev = 5381);

/**
 * Multiplies the current DJB2 state by 33 and combines it with a 64-bit word using XOR.
 *
 * - `p_in` — 64-bit word to add to the hash.
 * - `p_prev` — Initial or previous 64-bit hash state.
 */
_FORCE_INLINE_ uint64_t hash_djb2_one_64(uint64_t p_in, uint64_t p_prev = 5381) {
	return ((p_prev << 5) + p_prev) ^ p_in;
}

/**
 * Declares the reference-counted wrapper whose object address can be hashed.
 *
 * - `T` — Type held by the reference wrapper.
 */
template <typename T>
class Ref;

/**
 * Provides the default hash for supported Godot container key types.
 */
struct HashMapHasherDefault {
	// Generic hash function for any type.
	/**
	 * Hashes the pointer address without reading the object it points to.
	 *
	 * - `T` — Type of the pointed-to object.
	 * - `p_pointer` — Address used as the key. A null pointer is also hashed by address.
	 */
	template <typename T>
	static _FORCE_INLINE_ uint32_t hash(const T *p_pointer) { return hash_one_uint64((uint64_t)p_pointer); }

	/**
	 * Hashes the address of the object held by the reference wrapper.
	 *
	 * - `T` — Type held by the reference wrapper.
	 * - `p_ref` — Reference whose pointer address supplies the hash input.
	 */
	template <typename T>
	static _FORCE_INLINE_ uint32_t hash(const Ref<T> &p_ref) { return hash_one_uint64((uint64_t)p_ref.operator->()); }

	/**
	 * Hashes both elements and combines the first hash as the high word and the second as the low word.
	 *
	 * - `F` — Type of the first element.
	 * - `S` — Type of the second element.
	 * - `p_pair` — Pair whose elements are hashed in pair order.
	 */
	template <typename F, typename S>
	static _FORCE_INLINE_ uint32_t hash(const Pair<F, S> &p_pair) {
		uint64_t h1 = hash(p_pair.first);
		uint64_t h2 = hash(p_pair.second);
		return hash_one_uint64((h1 << 32) | h2);
	}

	/**
	 * Uses the Godot string's content hash.
	 *
	 * - `p_string` — String whose content is hashed.
	 */
	static _FORCE_INLINE_ uint32_t hash(const String &p_string) { return p_string.hash(); }
	/**
	 * Hashes bytes through the first null terminator using DJB2.
	 *
	 * - `p_cstr` — Null-terminated byte string.
	 */
	static _FORCE_INLINE_ uint32_t hash(const char *p_cstr) { return hash_djb2(p_cstr); }
	/**
	 * Mixes the wide code unit as a 32-bit value.
	 *
	 * - `p_wchar` — Wide character code unit to hash.
	 */
	static _FORCE_INLINE_ uint32_t hash(const wchar_t p_wchar) { return hash_fmix32(uint32_t(p_wchar)); }
	/**
	 * Mixes the 16-bit code unit as a 32-bit value.
	 *
	 * - `p_uchar` — 16-bit character code unit to hash.
	 */
	static _FORCE_INLINE_ uint32_t hash(const char16_t p_uchar) { return hash_fmix32(uint32_t(p_uchar)); }
	/**
	 * Mixes the 32-bit code unit.
	 *
	 * - `p_uchar` — 32-bit character code unit to hash.
	 */
	static _FORCE_INLINE_ uint32_t hash(const char32_t p_uchar) { return hash_fmix32(uint32_t(p_uchar)); }
	/**
	 * Mixes the resource ID's full 64-bit value into a 32-bit hash.
	 *
	 * - `p_rid` — Resource handle whose numeric ID is hashed.
	 */
	static _FORCE_INLINE_ uint32_t hash(const RID &p_rid) { return hash_one_uint64(p_rid.get_id()); }
	/**
	 * Hashes the byte string with DJB2 up to its null terminator.
	 *
	 * - `p_char_string` — Character buffer whose bytes are hashed.
	 */
	static _FORCE_INLINE_ uint32_t hash(const CharString &p_char_string) { return hash_djb2(p_char_string.get_data()); }
	/**
	 * Uses the interned name's hash.
	 *
	 * - `p_string_name` — Interned name used as the key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const StringName &p_string_name) { return p_string_name.hash(); }
	/**
	 * Uses the engine hash for the node path.
	 *
	 * - `p_path` — Node path used as the key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const NodePath &p_path) { return p_path.hash(); }
	/**
	 * Mixes the full object ID into a 32-bit hash.
	 *
	 * - `p_id` — Object ID used as a key, without looking up the object.
	 */
	static _FORCE_INLINE_ uint32_t hash(const ObjectID &p_id) { return hash_one_uint64(p_id); }
	/**
	 * Uses the callable's hash, including its engine or custom identity.
	 *
	 * - `p_callable` — Callable used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Callable &p_callable) { return p_callable.hash(); }

	/**
	 * Mixes a 64-bit integer into a 32-bit hash.
	 *
	 * - `p_int` — Integer whose 64-bit representation is mixed.
	 */
	static _FORCE_INLINE_ uint32_t hash(const uint64_t p_int) { return hash_one_uint64(p_int); }
	/**
	 * Mixes a 64-bit integer into a 32-bit hash.
	 *
	 * - `p_int` — Integer whose 64-bit representation is mixed.
	 */
	static _FORCE_INLINE_ uint32_t hash(const int64_t p_int) { return hash_one_uint64(uint64_t(p_int)); }
	/**
	 * Hashes a float through MurmurHash3 with signed zeros and NaNs normalized.
	 *
	 * - `p_float` — Single-precision value used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const float p_float) { return hash_murmur3_one_float(p_float); }
	/**
	 * Hashes a double through MurmurHash3 with signed zeros and NaNs normalized.
	 *
	 * - `p_double` — Double-precision value used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const double p_double) { return hash_murmur3_one_double(p_double); }
	/**
	 * Converts the integer to an unsigned 32-bit word and mixes its bits.
	 *
	 * - `p_int` — Integer used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const uint32_t p_int) { return hash_fmix32(p_int); }
	/**
	 * Converts the integer to an unsigned 32-bit word and mixes its bits.
	 *
	 * - `p_int` — Integer used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const int32_t p_int) { return hash_fmix32(uint32_t(p_int)); }
	/**
	 * Converts the integer to an unsigned 32-bit word and mixes its bits.
	 *
	 * - `p_int` — Integer used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const uint16_t p_int) { return hash_fmix32(uint32_t(p_int)); }
	/**
	 * Converts the integer to an unsigned 32-bit word and mixes its bits.
	 *
	 * - `p_int` — Integer used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const int16_t p_int) { return hash_fmix32(uint32_t(p_int)); }
	/**
	 * Converts the integer to an unsigned 32-bit word and mixes its bits.
	 *
	 * - `p_int` — Integer used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const uint8_t p_int) { return hash_fmix32(uint32_t(p_int)); }
	/**
	 * Converts the integer to an unsigned 32-bit word and mixes its bits.
	 *
	 * - `p_int` — Integer used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const int8_t p_int) { return hash_fmix32(uint32_t(p_int)); }
	/**
	 * Hashes the X and Y components in that order as integer numbers, then finalizes the hash.
	 *
	 * - `p_vec` — 2-component vector used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Vector2i &p_vec) {
		uint32_t h = hash_murmur3_one_32(uint32_t(p_vec.x));
		h = hash_murmur3_one_32(uint32_t(p_vec.y), h);
		return hash_fmix32(h);
	}
	/**
	 * Hashes the X, Y, and Z components in that order as integer numbers, then finalizes the hash.
	 *
	 * - `p_vec` — 3-component vector used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Vector3i &p_vec) {
		uint32_t h = hash_murmur3_one_32(uint32_t(p_vec.x));
		h = hash_murmur3_one_32(uint32_t(p_vec.y), h);
		h = hash_murmur3_one_32(uint32_t(p_vec.z), h);
		return hash_fmix32(h);
	}
	/**
	 * Hashes the X, Y, Z, and W components in that order as integer numbers, then finalizes the hash.
	 *
	 * - `p_vec` — 4-component vector used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Vector4i &p_vec) {
		uint32_t h = hash_murmur3_one_32(uint32_t(p_vec.x));
		h = hash_murmur3_one_32(uint32_t(p_vec.y), h);
		h = hash_murmur3_one_32(uint32_t(p_vec.z), h);
		h = hash_murmur3_one_32(uint32_t(p_vec.w), h);
		return hash_fmix32(h);
	}
	/**
	 * Hashes the X and Y components in that order as real numbers, then finalizes the hash.
	 *
	 * - `p_vec` — 2-component vector used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Vector2 &p_vec) {
		uint32_t h = hash_murmur3_one_real(p_vec.x);
		h = hash_murmur3_one_real(p_vec.y, h);
		return hash_fmix32(h);
	}
	/**
	 * Hashes the X, Y, and Z components in that order as real numbers, then finalizes the hash.
	 *
	 * - `p_vec` — 3-component vector used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Vector3 &p_vec) {
		uint32_t h = hash_murmur3_one_real(p_vec.x);
		h = hash_murmur3_one_real(p_vec.y, h);
		h = hash_murmur3_one_real(p_vec.z, h);
		return hash_fmix32(h);
	}
	/**
	 * Hashes the X, Y, Z, and W components in that order as real numbers, then finalizes the hash.
	 *
	 * - `p_vec` — 4-component vector used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Vector4 &p_vec) {
		uint32_t h = hash_murmur3_one_real(p_vec.x);
		h = hash_murmur3_one_real(p_vec.y, h);
		h = hash_murmur3_one_real(p_vec.z, h);
		h = hash_murmur3_one_real(p_vec.w, h);
		return hash_fmix32(h);
	}
	/**
	 * Hashes red, green, blue, and alpha in that order, normalizing signed zeros and NaNs.
	 *
	 * - `p_vec` — Color used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Color &p_vec) {
		uint32_t h = hash_murmur3_one_float(p_vec.r);
		h = hash_murmur3_one_float(p_vec.g, h);
		h = hash_murmur3_one_float(p_vec.b, h);
		h = hash_murmur3_one_float(p_vec.a, h);
		return hash_fmix32(h);
	}
	/**
	 * Hashes the position followed by the size. For each vector, the X component is added before Y.
	 *
	 * - `p_rect` — Rectangle used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Rect2i &p_rect) {
		uint32_t h = hash_murmur3_one_32(uint32_t(p_rect.position.x));
		h = hash_murmur3_one_32(uint32_t(p_rect.position.y), h);
		h = hash_murmur3_one_32(uint32_t(p_rect.size.x), h);
		h = hash_murmur3_one_32(uint32_t(p_rect.size.y), h);
		return hash_fmix32(h);
	}
	/**
	 * Hashes the position followed by the size. For each vector, the X component is added before Y.
	 *
	 * - `p_rect` — Rectangle used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const Rect2 &p_rect) {
		uint32_t h = hash_murmur3_one_real(p_rect.position.x);
		h = hash_murmur3_one_real(p_rect.position.y, h);
		h = hash_murmur3_one_real(p_rect.size.x, h);
		h = hash_murmur3_one_real(p_rect.size.y, h);
		return hash_fmix32(h);
	}
	/**
	 * Hashes the position followed by the size. The X, Y, and Z components of each are added in order.
	 *
	 * - `p_aabb` — Axis-aligned box used as a key.
	 */
	static _FORCE_INLINE_ uint32_t hash(const AABB &p_aabb) {
		uint32_t h = hash_murmur3_one_real(p_aabb.position.x);
		h = hash_murmur3_one_real(p_aabb.position.y, h);
		h = hash_murmur3_one_real(p_aabb.position.z, h);
		h = hash_murmur3_one_real(p_aabb.size.x, h);
		h = hash_murmur3_one_real(p_aabb.size.y, h);
		h = hash_murmur3_one_real(p_aabb.size.z, h);
		return hash_fmix32(h);
	}
};

/**
 * Uses an already computed integer hash as the key's hash.
 */
struct HashHasher {
	/**
	 * Returns the input as the unsigned 32-bit hash.
	 *
	 * - `p_hash` — Precomputed 32-bit hash.
	 */
	static _FORCE_INLINE_ uint32_t hash(const int32_t p_hash) { return p_hash; }
	/**
	 * Returns the input as the unsigned 32-bit hash.
	 *
	 * - `p_hash` — Precomputed 32-bit hash.
	 */
	static _FORCE_INLINE_ uint32_t hash(const uint32_t p_hash) { return p_hash; }
	/**
	 * Returns the input as the unsigned 64-bit hash.
	 *
	 * - `p_hash` — Precomputed 64-bit hash.
	 */
	static _FORCE_INLINE_ uint64_t hash(const int64_t p_hash) { return p_hash; }
	/**
	 * Returns the input as the unsigned 64-bit hash.
	 *
	 * - `p_hash` — Precomputed 64-bit hash.
	 */
	static _FORCE_INLINE_ uint64_t hash(const uint64_t p_hash) { return p_hash; }
};

/**
 * Gets a key's hash through its own C++ member function.
 *
 * - `T` — Key type with a callable hash member.
 */
template <typename T>
struct HashableHasher {
	/**
	 * Calls the supplied key's hash function.
	 *
	 * - `hashable` — Key whose stored or computed hash is requested.
	 */
	static _FORCE_INLINE_ uint32_t hash(const T &hashable) { return hashable.hash(); }
};

/**
 * Provides default key equality through the key type's equality operator.
 *
 * - `T` — Key type whose equality operator determines matches.
 */
template <typename T>
struct HashMapComparatorDefault {
	/**
	 * Uses the key type's equality operator to test for a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const T &p_lhs, const T &p_rhs) {
		return p_lhs == p_rhs;
	}
};

/**
 * Provides equality for single-precision floating-point keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<float> {
	/**
	 * Returns true when both operands are NaN or compare equal.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const float &p_lhs, const float &p_rhs) {
		return (p_lhs == p_rhs) || (Math::is_nan(p_lhs) && Math::is_nan(p_rhs));
	}
};

/**
 * Provides equality for double-precision floating-point keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<double> {
	/**
	 * Returns true when both operands are NaN or compare equal.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const double &p_lhs, const double &p_rhs) {
		return (p_lhs == p_rhs) || (Math::is_nan(p_lhs) && Math::is_nan(p_rhs));
	}
};

/**
 * Provides equality for color keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Color> {
	/**
	 * Returns true when all four RGBA components match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Color &p_lhs, const Color &p_rhs) {
		return ((p_lhs.r == p_rhs.r) || (Math::is_nan(p_lhs.r) && Math::is_nan(p_rhs.r))) && ((p_lhs.g == p_rhs.g) || (Math::is_nan(p_lhs.g) && Math::is_nan(p_rhs.g))) && ((p_lhs.b == p_rhs.b) || (Math::is_nan(p_lhs.b) && Math::is_nan(p_rhs.b))) && ((p_lhs.a == p_rhs.a) || (Math::is_nan(p_lhs.a) && Math::is_nan(p_rhs.a)));
	}
};

/**
 * Provides equality for 2D vector keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Vector2> {
	/**
	 * Returns true when both X and Y match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Vector2 &p_lhs, const Vector2 &p_rhs) {
		return ((p_lhs.x == p_rhs.x) || (Math::is_nan(p_lhs.x) && Math::is_nan(p_rhs.x))) && ((p_lhs.y == p_rhs.y) || (Math::is_nan(p_lhs.y) && Math::is_nan(p_rhs.y)));
	}
};

/**
 * Provides equality for 3D vector keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Vector3> {
	/**
	 * Returns true when all X, Y, and Z components match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Vector3 &p_lhs, const Vector3 &p_rhs) {
		return ((p_lhs.x == p_rhs.x) || (Math::is_nan(p_lhs.x) && Math::is_nan(p_rhs.x))) && ((p_lhs.y == p_rhs.y) || (Math::is_nan(p_lhs.y) && Math::is_nan(p_rhs.y))) && ((p_lhs.z == p_rhs.z) || (Math::is_nan(p_lhs.z) && Math::is_nan(p_rhs.z)));
	}
};

/**
 * Provides equality for 4D vector keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Vector4> {
	/**
	 * Returns true when all X, Y, Z, and W components match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Vector4 &p_lhs, const Vector4 &p_rhs) {
		return ((p_lhs.x == p_rhs.x) || (Math::is_nan(p_lhs.x) && Math::is_nan(p_rhs.x))) && ((p_lhs.y == p_rhs.y) || (Math::is_nan(p_lhs.y) && Math::is_nan(p_rhs.y))) && ((p_lhs.z == p_rhs.z) || (Math::is_nan(p_lhs.z) && Math::is_nan(p_rhs.z))) && ((p_lhs.w == p_rhs.w) || (Math::is_nan(p_lhs.w) && Math::is_nan(p_rhs.w)));
	}
};

/**
 * Provides equality for rectangle keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Rect2> {
	/**
	 * Returns true when the position and size vectors match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Rect2 &p_lhs, const Rect2 &p_rhs) {
		return HashMapComparatorDefault<Vector2>().compare(p_lhs.position, p_rhs.position) && HashMapComparatorDefault<Vector2>().compare(p_lhs.size, p_rhs.size);
	}
};

/**
 * Provides equality for axis-aligned box keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<AABB> {
	/**
	 * Returns true when the position and size vectors match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const AABB &p_lhs, const AABB &p_rhs) {
		return HashMapComparatorDefault<Vector3>().compare(p_lhs.position, p_rhs.position) && HashMapComparatorDefault<Vector3>().compare(p_lhs.size, p_rhs.size);
	}
};

/**
 * Provides equality for plane keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Plane> {
	/**
	 * Returns true when the normal and the plane's scalar offset match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Plane &p_lhs, const Plane &p_rhs) {
		return HashMapComparatorDefault<Vector3>().compare(p_lhs.normal, p_rhs.normal) && ((p_lhs.d == p_rhs.d) || (Math::is_nan(p_lhs.d) && Math::is_nan(p_rhs.d)));
	}
};

/**
 * Provides equality for 2D transform keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Transform2D> {
	/**
	 * Returns true when all three columns match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Transform2D &p_lhs, const Transform2D &p_rhs) {
		for (int i = 0; i < 3; ++i) {
			if (!HashMapComparatorDefault<Vector2>().compare(p_lhs.columns[i], p_rhs.columns[i])) {
				return false;
			}
		}

		return true;
	}
};

/**
 * Provides equality for basis keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Basis> {
	/**
	 * Returns true when all three rows match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Basis &p_lhs, const Basis &p_rhs) {
		for (int i = 0; i < 3; ++i) {
			if (!HashMapComparatorDefault<Vector3>().compare(p_lhs.rows[i], p_rhs.rows[i])) {
				return false;
			}
		}

		return true;
	}
};

/**
 * Provides equality for 3D transform keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Transform3D> {
	/**
	 * Returns true when the basis and origin match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Transform3D &p_lhs, const Transform3D &p_rhs) {
		return HashMapComparatorDefault<Basis>().compare(p_lhs.basis, p_rhs.basis) && HashMapComparatorDefault<Vector3>().compare(p_lhs.origin, p_rhs.origin);
	}
};

/**
 * Provides equality for projection keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Projection> {
	/**
	 * Returns true when all four columns match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Projection &p_lhs, const Projection &p_rhs) {
		for (int i = 0; i < 4; ++i) {
			if (!HashMapComparatorDefault<Vector4>().compare(p_lhs.columns[i], p_rhs.columns[i])) {
				return false;
			}
		}

		return true;
	}
};

/**
 * Provides equality for quaternion keys, treating corresponding NaNs as equal.
 */
template <>
struct HashMapComparatorDefault<Quaternion> {
	/**
	 * Returns true when all four components match. Corresponding NaNs count as a match.
	 *
	 * - `p_lhs` — First key.
	 * - `p_rhs` — Second key.
	 */
	static bool compare(const Quaternion &p_lhs, const Quaternion &p_rhs) {
		return ((p_lhs.x == p_rhs.x) || (Math::is_nan(p_lhs.x) && Math::is_nan(p_rhs.x))) && ((p_lhs.y == p_rhs.y) || (Math::is_nan(p_lhs.y) && Math::is_nan(p_rhs.y))) && ((p_lhs.z == p_rhs.z) || (Math::is_nan(p_lhs.z) && Math::is_nan(p_rhs.z))) && ((p_lhs.w == p_rhs.w) || (Math::is_nan(p_lhs.w) && Math::is_nan(p_rhs.w)));
	}
};

/**
 * Number of supported hash table sizes and reciprocal constants.
 */
constexpr uint32_t HASH_TABLE_SIZE_MAX = 29;

/**
 * Stores the supported prime bucket counts in ascending order.
 */
inline constexpr uint32_t hash_table_size_primes[HASH_TABLE_SIZE_MAX] = {
	5,
	13,
	23,
	47,
	97,
	193,
	389,
	769,
	1543,
	3079,
	6151,
	12289,
	24593,
	49157,
	98317,
	196613,
	393241,
	786433,
	1572869,
	3145739,
	6291469,
	12582917,
	25165843,
	50331653,
	100663319,
	201326611,
	402653189,
	805306457,
	1610612741,
};

// Computed with elem_i = UINT64_C (0 x FFFFFFFF FFFFFFFF ) / d_i + 1, where d_i is the i-th element of the above array.
/**
 * Stores the precomputed reciprocal for each matching prime bucket count.
 */
inline constexpr uint64_t hash_table_size_primes_inv[HASH_TABLE_SIZE_MAX] = {
	3689348814741910324,
	1418980313362273202,
	802032351030850071,
	392483916461905354,
	190172619316593316,
	95578984837873325,
	47420935922132524,
	23987963684927896,
	11955116055547344,
	5991147799191151,
	2998982941588287,
	1501077717772769,
	750081082979285,
	375261795343686,
	187625172388393,
	93822606204624,
	46909513691883,
	23456218233098,
	11728086747027,
	5864041509391,
	2932024948977,
	1466014921160,
	733007198436,
	366503839517,
	183251896093,
	91625960335,
	45812983922,
	22906489714,
	11453246088
};

/**
 * Fastmod computes ( n mod d ) given the precomputed c much faster than n % d.
 * The implementation of fastmod is based on the following paper by Daniel Lemire et al.
 * Faster Remainder by Direct Computation: Applications to Compilers and Software Libraries
 * https://arxiv.org/abs/1902.01961
 *
 * - `p_n` — 32-bit dividend.
 * - `p_c` — Precomputed reciprocal equal to the largest unsigned 64-bit integer divided by the divisor, plus one.
 * - `p_d` — Nonzero 32-bit divisor used to compute the reciprocal.
 */
static _FORCE_INLINE_ uint32_t fastmod(const uint32_t p_n, const uint64_t p_c, const uint32_t p_d) {
#if defined(_MSC_VER)
	// Returns the upper 64 bits of the product of two 64-bit unsigned integers.
	// This intrinsic function is required since MSVC does not support unsigned 128-bit integers.
#if defined(_M_X64) || defined(_M_ARM64)
	return __umulh(p_c * p_n, p_d);
#else
	// Fallback to the slower method for 32-bit platforms.
	return p_n % p_d;
#endif // _M_X64 || _M_ARM64
#else
#ifdef __SIZEOF_INT128__
	// Prevent compiler warning, because we know what we are doing.
	uint64_t lowbits = p_c * p_n;
	__extension__ typedef unsigned __int128 uint128;
	return static_cast<uint64_t>(((uint128)lowbits * p_d) >> 64);
#else
	// Fallback to the slower method if no 128-bit unsigned integer type is available.
	return p_n % p_d;
#endif // __SIZEOF_INT128__
#endif // _MSC_VER
}

} // namespace godot
