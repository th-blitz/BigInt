

#ifndef BigInt_H
#define BigInt_H

#include "stdint.h"
#include "ByteStack.h"

typedef enum BigIntType {
    uint128 = 4,
    uint256 = 8,
    uint512 = 16,
    uint1024 = 32,
} BigIntType;

typedef struct uint128_tt {
    uint32_t array[uint128];
    BigIntType type;
} uint128_t;

typedef struct uint256_tt {
    uint32_t array[uint256];
    BigIntType type;
} uint256_t;



uint128_t BigInt128();
uint256_t BigInt256();

uint128_t BigInt128_from_bytes( ByteStack* bytes);
uint32_t BigInt128_add(uint128_t* a, uint128_t* b, uint128_t* c);
void print_bigint(void* a, BigIntType type);
uint32_t BigInt128_subtract(uint128_t* a, uint128_t* b, uint128_t* c);
int BigInt128_cmp(uint128_t* a, uint128_t* b);
uint32_t BigInt128_multiplication_by_base_2_pow_32(uint128_t* a, uint32_t N, uint128_t* b);
void BigInt128_mulitplication(uint128_t* a, uint128_t* b, uint256_t* c);

#endif