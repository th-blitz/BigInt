
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

