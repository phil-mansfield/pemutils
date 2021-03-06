/* Copyright (c) 2014 Phil Mansfield
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE. */

#include "overflow.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <signal.h>
#include <wchar.h>

/* This file is autogenerated by pemutils/scripts/overflow_gen.py
 * All edits will be deleted. */

bool add_overflow_schar(signed char x, signed char y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > SCHAR_MAX - y;
    } else {
        return x < SCHAR_MIN - y;
    }
}

bool add_overflow_uchar(unsigned char x, unsigned char y) {
    return x > UCHAR_MAX - y;
}

bool add_overflow_shrt(short x, short y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > SHRT_MAX - y;
    } else {
        return x < SHRT_MIN - y;
    }
}

bool add_overflow_ushrt(unsigned short x, unsigned short y) {
    return x > USHRT_MAX - y;
}

bool add_overflow_int(int x, int y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT_MAX - y;
    } else {
        return x < INT_MIN - y;
    }
}

bool add_overflow_uint(unsigned int x, unsigned int y) {
    return x > UINT_MAX - y;
}

bool add_overflow_long(long x, long y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > LONG_MAX - y;
    } else {
        return x < LONG_MIN - y;
    }
}

bool add_overflow_ulong(unsigned long x, unsigned long y) {
    return x > ULONG_MAX - y;
}

bool add_overflow_llong(long long x, long long y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > LLONG_MAX - y;
    } else {
        return x < LLONG_MIN - y;
    }
}

bool add_overflow_ullong(unsigned long long x, unsigned long long y) {
    return x > ULLONG_MAX - y;
}

bool add_overflow_size(size_t x, size_t y) {
    return x > SIZE_MAX - y;
}

bool add_overflow_intmax(intmax_t x, intmax_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INTMAX_MAX - y;
    } else {
        return x < INTMAX_MIN - y;
    }
}

bool add_overflow_uintmax(uintmax_t x, uintmax_t y) {
    return x > UINTMAX_MAX - y;
}

bool add_overflow_intptr(intptr_t x, intptr_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INTPTR_MAX - y;
    } else {
        return x < INTPTR_MIN - y;
    }
}

bool add_overflow_uintptr(uintptr_t x, uintptr_t y) {
    return x > UINTPTR_MAX - y;
}

bool add_overflow_wchar(wchar_t x, wchar_t y) {
#if (WCHAR_MIN != 0)
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > WCHAR_MAX - y;
    } else {
        return x < WCHAR_MIN - y;
    }
#else
    return x > WCHAR_MAX - y;
#endif

}

bool add_overflow_sig_atomic(sig_atomic_t x, sig_atomic_t y) {
#if (SIG_ATOMIC_MIN != 0)
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > SIG_ATOMIC_MAX - y;
    } else {
        return x < SIG_ATOMIC_MIN - y;
    }
#else
    return x > SIG_ATOMIC_MAX - y;
#endif

}

bool add_overflow_wint(wint_t x, wint_t y) {
#if (WINT_MIN != 0)
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > WINT_MAX - y;
    } else {
        return x < WINT_MIN - y;
    }
#else
    return x > WINT_MAX - y;
#endif

}

bool add_overflow_char(char x, char y) {
#if (CHAR_MIN != 0)
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > CHAR_MAX - y;
    } else {
        return x < CHAR_MIN - y;
    }
#else
    return x > CHAR_MAX - y;
#endif

}

bool add_overflow_int8(int8_t x, int8_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT8_MAX - y;
    } else {
        return x < INT8_MIN - y;
    }
}

bool add_overflow_uint8(uint8_t x, uint8_t y) {
    return x > UINT8_MAX - y;
}

bool add_overflow_int_fast8(int_fast8_t x, int_fast8_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT_FAST8_MAX - y;
    } else {
        return x < INT_FAST8_MIN - y;
    }
}

bool add_overflow_uint_fast8(uint_fast8_t x, uint_fast8_t y) {
    return x > UINT_FAST8_MAX - y;
}

bool add_overflow_int_least8(int_least8_t x, int_least8_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT_LEAST8_MAX - y;
    } else {
        return x < INT_LEAST8_MIN - y;
    }
}

bool add_overflow_uint_least8(uint_least8_t x, uint_least8_t y) {
    return x > UINT_LEAST8_MAX - y;
}

bool add_overflow_int16(int16_t x, int16_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT16_MAX - y;
    } else {
        return x < INT16_MIN - y;
    }
}

bool add_overflow_uint16(uint16_t x, uint16_t y) {
    return x > UINT16_MAX - y;
}

bool add_overflow_int_fast16(int_fast16_t x, int_fast16_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT_FAST16_MAX - y;
    } else {
        return x < INT_FAST16_MIN - y;
    }
}

bool add_overflow_uint_fast16(uint_fast16_t x, uint_fast16_t y) {
    return x > UINT_FAST16_MAX - y;
}

bool add_overflow_int_least16(int_least16_t x, int_least16_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT_LEAST16_MAX - y;
    } else {
        return x < INT_LEAST16_MIN - y;
    }
}

bool add_overflow_uint_least16(uint_least16_t x, uint_least16_t y) {
    return x > UINT_LEAST16_MAX - y;
}

bool add_overflow_int32(int32_t x, int32_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT32_MAX - y;
    } else {
        return x < INT32_MIN - y;
    }
}

bool add_overflow_uint32(uint32_t x, uint32_t y) {
    return x > UINT32_MAX - y;
}

bool add_overflow_int_fast32(int_fast32_t x, int_fast32_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT_FAST32_MAX - y;
    } else {
        return x < INT_FAST32_MIN - y;
    }
}

bool add_overflow_uint_fast32(uint_fast32_t x, uint_fast32_t y) {
    return x > UINT_FAST32_MAX - y;
}

bool add_overflow_int_least32(int_least32_t x, int_least32_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT_LEAST32_MAX - y;
    } else {
        return x < INT_LEAST32_MIN - y;
    }
}

bool add_overflow_uint_least32(uint_least32_t x, uint_least32_t y) {
    return x > UINT_LEAST32_MAX - y;
}

bool add_overflow_int64(int64_t x, int64_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT64_MAX - y;
    } else {
        return x < INT64_MIN - y;
    }
}

bool add_overflow_uint64(uint64_t x, uint64_t y) {
    return x > UINT64_MAX - y;
}

bool add_overflow_int_fast64(int_fast64_t x, int_fast64_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT_FAST64_MAX - y;
    } else {
        return x < INT_FAST64_MIN - y;
    }
}

bool add_overflow_uint_fast64(uint_fast64_t x, uint_fast64_t y) {
    return x > UINT_FAST64_MAX - y;
}

bool add_overflow_int_least64(int_least64_t x, int_least64_t y) {
    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > INT_LEAST64_MAX - y;
    } else {
        return x < INT_LEAST64_MIN - y;
    }
}

bool add_overflow_uint_least64(uint_least64_t x, uint_least64_t y) {
    return x > UINT_LEAST64_MAX - y;
}

bool mult_overflow_schar(signed char x, signed char y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return SCHAR_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return SCHAR_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return SCHAR_MIN / y > x;
    } else { // x > 0 && y < 0
        return SCHAR_MIN / x > y;
    }
}

bool mult_overflow_uchar(unsigned char x, unsigned char y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_shrt(short x, short y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return SHRT_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return SHRT_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return SHRT_MIN / y > x;
    } else { // x > 0 && y < 0
        return SHRT_MIN / x > y;
    }
}

bool mult_overflow_ushrt(unsigned short x, unsigned short y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int(int x, int y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT_MIN / x > y;
    }
}

bool mult_overflow_uint(unsigned int x, unsigned int y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_long(long x, long y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return LONG_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return LONG_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return LONG_MIN / y > x;
    } else { // x > 0 && y < 0
        return LONG_MIN / x > y;
    }
}

bool mult_overflow_ulong(unsigned long x, unsigned long y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_llong(long long x, long long y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return LLONG_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return LLONG_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return LLONG_MIN / y > x;
    } else { // x > 0 && y < 0
        return LLONG_MIN / x > y;
    }
}

bool mult_overflow_ullong(unsigned long long x, unsigned long long y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_size(size_t x, size_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_intmax(intmax_t x, intmax_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INTMAX_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INTMAX_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INTMAX_MIN / y > x;
    } else { // x > 0 && y < 0
        return INTMAX_MIN / x > y;
    }
}

bool mult_overflow_uintmax(uintmax_t x, uintmax_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_intptr(intptr_t x, intptr_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INTPTR_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INTPTR_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INTPTR_MIN / y > x;
    } else { // x > 0 && y < 0
        return INTPTR_MIN / x > y;
    }
}

bool mult_overflow_uintptr(uintptr_t x, uintptr_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_wchar(wchar_t x, wchar_t y) {
#if (WCHAR_MIN != 0)
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return WCHAR_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return WCHAR_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return WCHAR_MIN / y > x;
    } else { // x > 0 && y < 0
        return WCHAR_MIN / x > y;
    }
#else
    return x != 0 && (x * y) / x != y;
#endif

}

bool mult_overflow_sig_atomic(sig_atomic_t x, sig_atomic_t y) {
#if (SIG_ATOMIC_MIN != 0)
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return SIG_ATOMIC_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return SIG_ATOMIC_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return SIG_ATOMIC_MIN / y > x;
    } else { // x > 0 && y < 0
        return SIG_ATOMIC_MIN / x > y;
    }
#else
    return x != 0 && (x * y) / x != y;
#endif

}

bool mult_overflow_wint(wint_t x, wint_t y) {
#if (WINT_MIN != 0)
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return WINT_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return WINT_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return WINT_MIN / y > x;
    } else { // x > 0 && y < 0
        return WINT_MIN / x > y;
    }
#else
    return x != 0 && (x * y) / x != y;
#endif

}

bool mult_overflow_char(char x, char y) {
#if (CHAR_MIN != 0)
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return CHAR_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return CHAR_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return CHAR_MIN / y > x;
    } else { // x > 0 && y < 0
        return CHAR_MIN / x > y;
    }
#else
    return x != 0 && (x * y) / x != y;
#endif

}

bool mult_overflow_int8(int8_t x, int8_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT8_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT8_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT8_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT8_MIN / x > y;
    }
}

bool mult_overflow_uint8(uint8_t x, uint8_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int_fast8(int_fast8_t x, int_fast8_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT_FAST8_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT_FAST8_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT_FAST8_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT_FAST8_MIN / x > y;
    }
}

bool mult_overflow_uint_fast8(uint_fast8_t x, uint_fast8_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int_least8(int_least8_t x, int_least8_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT_LEAST8_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT_LEAST8_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT_LEAST8_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT_LEAST8_MIN / x > y;
    }
}

bool mult_overflow_uint_least8(uint_least8_t x, uint_least8_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int16(int16_t x, int16_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT16_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT16_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT16_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT16_MIN / x > y;
    }
}

bool mult_overflow_uint16(uint16_t x, uint16_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int_fast16(int_fast16_t x, int_fast16_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT_FAST16_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT_FAST16_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT_FAST16_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT_FAST16_MIN / x > y;
    }
}

bool mult_overflow_uint_fast16(uint_fast16_t x, uint_fast16_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int_least16(int_least16_t x, int_least16_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT_LEAST16_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT_LEAST16_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT_LEAST16_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT_LEAST16_MIN / x > y;
    }
}

bool mult_overflow_uint_least16(uint_least16_t x, uint_least16_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int32(int32_t x, int32_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT32_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT32_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT32_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT32_MIN / x > y;
    }
}

bool mult_overflow_uint32(uint32_t x, uint32_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int_fast32(int_fast32_t x, int_fast32_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT_FAST32_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT_FAST32_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT_FAST32_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT_FAST32_MIN / x > y;
    }
}

bool mult_overflow_uint_fast32(uint_fast32_t x, uint_fast32_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int_least32(int_least32_t x, int_least32_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT_LEAST32_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT_LEAST32_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT_LEAST32_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT_LEAST32_MIN / x > y;
    }
}

bool mult_overflow_uint_least32(uint_least32_t x, uint_least32_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int64(int64_t x, int64_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT64_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT64_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT64_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT64_MIN / x > y;
    }
}

bool mult_overflow_uint64(uint64_t x, uint64_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int_fast64(int_fast64_t x, int_fast64_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT_FAST64_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT_FAST64_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT_FAST64_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT_FAST64_MIN / x > y;
    }
}

bool mult_overflow_uint_fast64(uint_fast64_t x, uint_fast64_t y) {
    return x != 0 && (x * y) / x != y;
}

bool mult_overflow_int_least64(int_least64_t x, int_least64_t y) {
    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return INT_LEAST64_MAX / x < y;
    } else if (x < 0 && y < 0) {
        return INT_LEAST64_MAX / x > y;
    } else if (x < 0 && y > 0) {
        return INT_LEAST64_MIN / y > x;
    } else { // x > 0 && y < 0
        return INT_LEAST64_MIN / x > y;
    }
}

bool mult_overflow_uint_least64(uint_least64_t x, uint_least64_t y) {
    return x != 0 && (x * y) / x != y;
}