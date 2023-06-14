
#include <stdint.h>
#include <stdio.h>


#include "BigInt.h"




uint32_t BigInt128_left_shift(uint128_t* a, uint8_t shift, uint128_t* b) {

    uint8_t i, j, shift_32s = shift >> 5, shifts_in_32s = shift & 31;
    uint64_t carry = 0;

    for (i = uint128, j = uint128 - shift_32s; j > 0; i--, j--) {
        b -> array[i - 1] = a -> array[j - 1];
    }
    j = i;
    for ( ;i > 0; i--) {
        b -> array[i - 1] = 0;
    }

    if (shifts_in_32s != 0) {
        for (; j < uint128; j++) {
            carry |= (uint64_t)(b -> array[j]) << shifts_in_32s;
            b -> array[j] = (uint32_t)carry;
            carry >>= 32;
        }
    }

    return carry;
}

uint32_t BigInt256_left_shift(uint256_t* a, uint8_t shift, uint256_t* b) {

    uint8_t i, j, shift_32s = shift >> 5, shifts_in_32s = shift & 31;
    uint64_t carry = 0;

    for (i = uint256, j = uint256 - shift_32s; j > 0; i--, j--) {
        b -> array[i - 1] = a -> array[j - 1];
    }
    j = i;
    for ( ;i > 0; i--) {
        b -> array[i - 1] = 0;
    }

    if (shifts_in_32s != 0) {
        for (; j < uint256; j++) {
            carry |= (uint64_t)(b -> array[j]) << shifts_in_32s;
            b -> array[j] = (uint32_t)carry;
            carry >>= 32;
        }
    }

    return carry;
}

uint32_t BigInt512_left_shift(uint512_t* a, uint8_t shift, uint512_t* b) {

    uint8_t i, j, shift_32s = shift >> 5, shifts_in_32s = shift & 31;
    uint64_t carry = 0;

    for (i = uint512, j = uint512 - shift_32s; j > 0; i--, j--) {
        b -> array[i - 1] = a -> array[j - 1];
    }
    j = i;
    for ( ;i > 0; i--) {
        b -> array[i - 1] = 0;
    }

    if (shifts_in_32s != 0) {
        for (; j < uint512; j++) {
            carry |= (uint64_t)(b -> array[j]) << shifts_in_32s;
            b -> array[j] = (uint32_t)carry;
            carry >>= 32;
        }
    }

    return carry;
}

uint32_t BigInt1024_left_shift(uint1024_t* a, uint8_t shift, uint1024_t* b) {

    uint8_t i, j, shift_32s = shift >> 5, shifts_in_32s = shift & 31;
    uint64_t carry = 0;

    for (i = uint1024, j = uint1024 - shift_32s; j > 0; i--, j--) {
        b -> array[i - 1] = a -> array[j - 1];
    }
    j = i;
    for ( ;i > 0; i--) {
        b -> array[i - 1] = 0;
    }

    if (shifts_in_32s != 0) {
        for (; j < uint1024; j++) {
            carry |= (uint64_t)(b -> array[j]) << shifts_in_32s;
            b -> array[j] = (uint32_t)carry;
            carry >>= 32;
        }
    }

    return carry;
}

uint32_t BigInt2048_left_shift(uint2048_t* a, uint8_t shift, uint2048_t* b) {

    uint8_t i, j, shift_32s = shift >> 5, shifts_in_32s = shift & 31;
    uint64_t carry = 0;

    for (i = uint2048, j = uint2048 - shift_32s; j > 0; i--, j--) {
        b -> array[i - 1] = a -> array[j - 1];
    }
    j = i;
    for ( ;i > 0; i--) {
        b -> array[i - 1] = 0;
    }

    if (shifts_in_32s != 0) {
        for (; j < uint2048; j++) {
            carry |= (uint64_t)(b -> array[j]) << shifts_in_32s;
            b -> array[j] = (uint32_t)carry;
            carry >>= 32;
        }
    }

    return carry;
}




uint32_t BigInt128_right_shift(uint128_t* a, uint8_t shift, uint128_t* b) {

    uint8_t i, j, shift_32s = shift >> 5, shifts_in_32s = shift & 31, opp_shift = 31 - shifts_in_32s;
    uint32_t carry = 0, prev_carry = 0;

    for (i = 0, j = shift_32s; j < uint128; i++, j++) {
        b -> array[i] = a -> array[j];
    }
    j = i;
    for ( ; i < uint128 ; i++) {
        b -> array[i] = 0;
    }

    if (shifts_in_32s != 0) {
        for ( ;j > 0 ; j--) {
            carry = b -> array[j - 1];
            b -> array[j - 1] >>= shifts_in_32s;
            b -> array[j - 1] |= prev_carry;
            prev_carry = carry << opp_shift;
        }
    }

    return prev_carry;
}

uint32_t BigInt256_right_shift(uint256_t* a, uint8_t shift, uint256_t* b) {

    uint8_t i, j, shift_32s = shift >> 5, shifts_in_32s = shift & 31, opp_shift = 31 - shifts_in_32s;
    uint32_t carry = 0, prev_carry = 0;

    for (i = 0, j = shift_32s; j < uint256; i++, j++) {
        b -> array[i] = a -> array[j];
    }
    j = i;
    for ( ; i < uint256 ; i++) {
        b -> array[i] = 0;
    }

    if (shifts_in_32s != 0) {
        for ( ;j > 0 ; j--) {
            carry = b -> array[j - 1];
            b -> array[j - 1] >>= shifts_in_32s;
            b -> array[j - 1] |= prev_carry;
            prev_carry = carry << opp_shift;
        }
    }

    return prev_carry;
}

uint32_t BigInt512_right_shift(uint512_t* a, uint8_t shift, uint512_t* b) {

    uint8_t i, j, shift_32s = shift >> 5, shifts_in_32s = shift & 31, opp_shift = 31 - shifts_in_32s;
    uint32_t carry = 0, prev_carry = 0;

    for (i = 0, j = shift_32s; j < uint512; i++, j++) {
        b -> array[i] = a -> array[j];
    }
    j = i;
    for ( ; i < uint512 ; i++) {
        b -> array[i] = 0;
    }

    if (shifts_in_32s != 0) {
        for ( ;j > 0 ; j--) {
            carry = b -> array[j - 1];
            b -> array[j - 1] >>= shifts_in_32s;
            b -> array[j - 1] |= prev_carry;
            prev_carry = carry << opp_shift;
        }
    }

    return prev_carry;
}

uint32_t BigInt1024_right_shift(uint1024_t* a, uint8_t shift, uint1024_t* b) {

    uint8_t i, j, shift_32s = shift >> 5, shifts_in_32s = shift & 31, opp_shift = 31 - shifts_in_32s;
    uint32_t carry = 0, prev_carry = 0;

    for (i = 0, j = shift_32s; j < uint1024; i++, j++) {
        b -> array[i] = a -> array[j];
    }
    j = i;
    for ( ; i < uint1024 ; i++) {
        b -> array[i] = 0;
    }

    if (shifts_in_32s != 0) {
        for ( ;j > 0 ; j--) {
            carry = b -> array[j - 1];
            b -> array[j - 1] >>= shifts_in_32s;
            b -> array[j - 1] |= prev_carry;
            prev_carry = carry << opp_shift;
        }
    }

    return prev_carry;
}

uint32_t BigInt2048_right_shift(uint2048_t* a, uint8_t shift, uint2048_t* b) {

    uint8_t i, j, shift_32s = shift >> 5, shifts_in_32s = shift & 31, opp_shift = 31 - shifts_in_32s;
    uint32_t carry = 0, prev_carry = 0;

    for (i = 0, j = shift_32s; j < uint2048; i++, j++) {
        b -> array[i] = a -> array[j];
    }
    j = i;
    for ( ; i < uint2048 ; i++) {
        b -> array[i] = 0;
    }

    if (shifts_in_32s != 0) {
        for ( ;j > 0 ; j--) {
            carry = b -> array[j - 1];
            b -> array[j - 1] >>= shifts_in_32s;
            b -> array[j - 1] |= prev_carry;
            prev_carry = carry << opp_shift;
        }
    }

    return prev_carry;
}