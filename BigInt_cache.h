#ifndef BigInt_Cache_H
#define BigInt_Cache_H

#include <stdint.h>

#include "BigInt.h"

uint128_t BigInt_get_u128_MAX();
uint256_t BigInt_get_u256_MAX();
uint512_t BigInt_get_u512_MAX();
uint1024_t BigInt_get_u1024_MAX();
uint2048_t BigInt_get_u2048_MAX();


uint128_t BigInt_get_u128_RAND();
uint256_t BigInt_get_u256_RAND();
uint512_t BigInt_get_u512_RAND();
uint1024_t BigInt_get_u1024_RAND();
uint2048_t BigInt_get_u2048_RAND();


#endif