
#include "BigInt.h"
#include "utils.c"


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