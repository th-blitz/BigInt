
#include <stdint.h>

#include "BigInt.h"

uint32_t BigInt128_left_shift(uint128_t* a, uint8_t shift, uint128_t* b);
uint32_t BigInt256_left_shift(uint256_t* a, uint8_t shift, uint256_t* b);
uint32_t BigInt512_left_shift(uint512_t* a, uint8_t shift, uint512_t* b);
uint32_t BigInt1024_left_shift(uint1024_t* a, uint8_t shift, uint1024_t* b);
uint32_t BigInt2048_left_shift(uint2048_t* a, uint8_t shift, uint2048_t* b);

uint32_t BigInt128_right_shift(uint128_t* a, uint8_t shift, uint128_t* b);
uint32_t BigInt256_right_shift(uint256_t* a, uint8_t shift, uint256_t* b);
uint32_t BigInt512_right_shift(uint512_t* a, uint8_t shift, uint512_t* b);
uint32_t BigInt1024_right_shift(uint1024_t* a, uint8_t shift, uint1024_t* b);
uint32_t BigInt2048_right_shift(uint2048_t* a, uint8_t shift, uint2048_t* b);