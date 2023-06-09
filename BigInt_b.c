
#include <stdint.h>

#include "BigInt.h"
#include "utils.h"



uint32_t BigInt128_divide_by_n(uint128_t* a, uint64_t divisor, uint128_t* b) {
    uint64_t remainder = 0;
    uint8_t i;
    for (i = uint128; i > 0; i--) {
        remainder <<= 32;
        remainder += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder / divisor);
        remainder %= divisor;
    }
    return (uint32_t)remainder;
}

uint32_t BigInt256_divide_by_n(uint256_t* a, uint64_t divisor, uint256_t* b) {
    uint64_t remainder = 0;
    uint8_t i;
    for (i = uint256; i > 0; i--) {
        remainder <<= 32;
        remainder += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder / divisor);
        remainder %= divisor;
    }
    return (uint32_t)remainder;
}

uint32_t BigInt512_divide_by_n(uint512_t* a, uint64_t divisor, uint512_t* b) {
    uint64_t remainder = 0;
    uint8_t i;
    for (i = uint512; i > 0; i--) {
        remainder <<= 32;
        remainder += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder / divisor);
        remainder %= divisor;
    }
    return (uint32_t)remainder;
}

uint32_t BigInt1024_divide_by_n(uint1024_t* a, uint64_t divisor, uint1024_t* b) {
    uint64_t remainder = 0;
    uint8_t i;
    for (i = uint1024; i > 0; i--) {
        remainder <<= 32;
        remainder += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder / divisor);
        remainder %= divisor;
    }
    return (uint32_t)remainder;
}

uint32_t BigInt2048_divide_by_n(uint2048_t* a, uint64_t divisor, uint2048_t* b) {
    uint64_t remainder = 0;
    uint8_t i;
    for (i = uint2048; i > 0; i--) {
        remainder <<= 32;
        remainder += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder / divisor);
        remainder %= divisor;
    }
    return (uint32_t)remainder;
}


uint32_t BigInt_divide_by_n(void* a, uint32_t divisor, void* b, BigIntType type) {
    uint32_t remainder = 0;
    switch(type) {
        case uint128:
            remainder = BigInt128_divide_by_n((uint128_t*)a, divisor, (uint128_t*)b);
            break;
        case uint256:
            remainder = BigInt256_divide_by_n((uint256_t*)a, divisor, (uint256_t*)b);
            break;
        case uint512:
            remainder = BigInt512_divide_by_n((uint512_t*)a, divisor, (uint512_t*)b);
            break;
        case uint1024:
            remainder = BigInt1024_divide_by_n((uint1024_t*)a, divisor, (uint1024_t*)b);
            break;
        case uint2048:
            remainder = BigInt2048_divide_by_n((uint2048_t*)a, divisor, (uint2048_t*)b);
            break;
        default:
            printlnc("err: no types identified at BigInt_divide_by_n", red);
    } 
    return remainder;
}


uint32_t BigInt128_left_shift(uint128_t* a, uint32_t shift, uint128_t* b) {

    uint8_t shift_32s = shift / 32;
    uint8_t shifts_in_32s = shift % 32;
    uint8_t i, j, leading_zeros = 0, k = 0;
    uint64_t carry = 0;

    for (i = a -> len + shift_32s, j = a -> len; j > 0; i--, j--) {
        (i - 1 <= uint128) ? (b -> array[i - 1] = a -> array[j - 1]) : 0;
    }

    printlnint(i);

    for (k = i; (k < (a -> len + shift_32s)) && (k < uint128); k++) {
        carry = ((uint64_t)(b -> array[i]) << shifts_in_32s) | carry;
        b -> array[i] = (uint32_t)carry;
        (b -> array[i] == 0) ? (leading_zeros += 1) : (leading_zeros = 0);
        carry >>= 32;
    }

    b -> len = (k - leading_zeros) > 0 ? (k - leading_zeros) : 1;

    while(i > 0) {
        b -> array[i - 1] = 0;
        i--;
    }
    
    return carry;
}