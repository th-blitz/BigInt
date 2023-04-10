

#ifndef BigInt_H
#define BigInt_H

#include "stdint.h"
// #include "ByteStack.h"

typedef enum BigIntType {
    uint128 = 4,
    uint256 = 8,
    uint512 = 16,
    uint1024 = 32,
    uint2048 = 64
} BigIntType;

typedef struct uint128_tt {
    uint32_t array[uint128];
    BigIntType type;
} uint128_t;

typedef struct uint256_tt {
    uint32_t array[uint256];
    BigIntType type;
} uint256_t;

typedef struct uint512_tt {
    uint32_t array[uint512];
    BigIntType type;
} uint512_t;

typedef struct uint1024_tt {
    uint32_t array[uint1024];
    BigIntType type;
} uint1024_t;

typedef struct uint2048_tt {
    uint32_t array[uint2048];
    BigIntType type;
} uint2048_t;

uint128_t BigInt128();
uint256_t BigInt256();

uint128_t BigInt128_from_string(char* string, uint64_t string_len);
uint32_t BigInt128_Addition(void* a, void* b, void* c, BigIntType type);
uint32_t BigInt128_add(uint128_t* a, uint128_t* b, uint128_t* c);
void print_bigint(void* a, BigIntType type);
uint32_t BigInt128_subtract(uint128_t* a, uint128_t* b, uint128_t* c);
int BigInt128_cmp(uint128_t* a, uint128_t* b);
uint32_t BigInt128_multiplication_by_base_2_pow_32(uint128_t* a, uint32_t N, uint128_t* b);
void BigInt128_mulitplication(uint128_t* a, uint128_t* b, uint256_t* c);

#endif