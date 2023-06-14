
#include <stdint.h>

#include "BigInt.h"
#include "utils.h"



uint32_t BigInt128_divide_by_n(uint128_t* a, uint32_t divisor, uint32_t remainder, uint128_t* b) {
    uint64_t remainder_carry = remainder;
    for (uint8_t i = uint128; i > 0; i--) {
        remainder_carry <<= 32;
        remainder_carry += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder_carry / divisor);
        remainder_carry %= divisor;
    }
    return (uint32_t)remainder_carry;
}

uint32_t BigInt256_divide_by_n(uint256_t* a, uint32_t divisor, uint32_t remainder, uint256_t* b) {
    uint64_t remainder_carry = remainder;
    for (uint8_t i = uint256; i > 0; i--) {
        remainder_carry <<= 32;
        remainder_carry += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder_carry / divisor);
        remainder_carry %= divisor;
    }
    return (uint32_t)remainder_carry;
}

uint32_t BigInt512_divide_by_n(uint512_t* a, uint32_t divisor, uint32_t remainder, uint512_t* b) {
    uint64_t remainder_carry = remainder; 
    for (uint8_t i = uint512; i > 0; i--) {
        remainder_carry <<= 32;
        remainder_carry += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder_carry / divisor);
        remainder_carry %= divisor;
    }
    return (uint32_t)remainder_carry;
}

uint32_t BigInt1024_divide_by_n(uint1024_t* a, uint32_t divisor, uint32_t remainder, uint1024_t* b) {
    uint64_t remainder_carry = remainder; 
    for (uint8_t i = uint1024; i > 0; i--) {
        remainder_carry <<= 32;
        remainder_carry += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder_carry / divisor);
        remainder_carry %= divisor;
    }
    return (uint32_t)remainder_carry;
}

uint32_t BigInt2048_divide_by_n(uint2048_t* a, uint32_t divisor, uint32_t remainder, uint2048_t* b) {
    uint64_t remainder_carry = remainder; 
    for (uint8_t i = uint2048; i > 0; i--) {
        remainder_carry <<= 32;
        remainder_carry += (uint64_t)(a -> array[i - 1]);
        b -> array[i - 1] = (uint32_t)(remainder / divisor);
        remainder_carry %= divisor;
    }
    return (uint32_t)remainder_carry;
}


uint32_t BigInt_divide_by_n(void* a, uint32_t divisor, uint32_t remainder, void* b, BigIntType type) {
    if (divisor == 0) {divisor = 1;}
    switch(type) {
        case uint128:
            remainder = BigInt128_divide_by_n((uint128_t*)a, divisor, remainder, (uint128_t*)b);
            break;
        case uint256:
            remainder = BigInt256_divide_by_n((uint256_t*)a, divisor, remainder, (uint256_t*)b);
            break;
        case uint512:
            remainder = BigInt512_divide_by_n((uint512_t*)a, divisor, remainder, (uint512_t*)b);
            break;
        case uint1024:
            remainder = BigInt1024_divide_by_n((uint1024_t*)a, divisor, remainder, (uint1024_t*)b);
            break;
        case uint2048:
            remainder = BigInt2048_divide_by_n((uint2048_t*)a, divisor, remainder, (uint2048_t*)b);
            break;
        default:
            break;
    } 
    return remainder;
}

