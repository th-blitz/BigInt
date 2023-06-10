#ifndef BigInt_B_H
#define BigInt_B_H

#include "BigInt.h"

uint32_t BigInt_divide_by_n(void* a, uint32_t divisor, void* b, BigIntType type);
uint32_t BigInt128_divide_by_n(uint128_t* a, uint64_t divisor, uint64_t remainder, uint128_t* b);
uint32_t BigInt256_divide_by_n(uint256_t* a, uint64_t divisor, uint64_t remainder, uint256_t* b);
uint32_t BigInt512_divide_by_n(uint512_t* a, uint64_t divisor, uint64_t remainder, uint512_t* b);
uint32_t BigInt1024_divide_by_n(uint1024_t* a, uint64_t divisor, uint64_t remainder, uint1024_t* b);
uint32_t BigInt2048_divide_by_n(uint2048_t* a, uint64_t divisor, uint64_t remainder, uint2048_t* b);

#endif