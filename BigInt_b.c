
#include <stdint.h>

#include "BigInt.h"
#include "utils.h"



uint32_t BigInt128_divide_by_n(uint128_t* a, uint64_t divisor, uint128_t* b) {
    uint64_t remainder = 0;
    uint8_t i, leading_zeros = 0, leading_zeros_flag = 0;
    for (i = a -> len; i > 0; i--) {
        remainder <<= 32;
        remainder += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder / divisor);
        (b -> array[i - 1] == 0 && leading_zeros_flag == 0) ? (leading_zeros += 1): (leading_zeros_flag = 1);
        remainder %= divisor;
    }
    b -> len = ((a -> len - leading_zeros) > 0) ? (a -> len - leading_zeros) : (1);
    return (uint32_t)(remainder);
}


uint32_t BigInt_divide_by_n(void* a, uint32_t carry, void* b, BigIntType type) {
    uint32_t remainder = 0;
    switch(type) {
        case uint128:
            break;
        case uint256:
            break;
        case uint512:
            break;
        case uint1024:
            break;
        case uint2048:
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